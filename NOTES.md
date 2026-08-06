# NOTES — CPP Module 00 (last maj : 06 aout 2026)

Point de situation pour reprendre le fil.

## État global

- ex00 — Megaphone : Terminé. Compile clean, exécutable `megaphone`, sortie conforme. Prêt à rendre.
- ex01 — PhoneBook : En cours. Architecture en place, compile — mais le `main` n'utilise pas encore les vraies classes.
- ex02 — Account : Non commencé (optionnel, pas requis pour valider le module).

## ex00 — Megaphone 

Rien à faire. Compile avec -Wall -Wextra -Werror -std=c++98, exécutable bien nommé, les trois cas (une phrase / plusieurs args / sans arg) sont conformes.

## ex01 — PhoneBook 

Déjà corrigé :
- `;` après les définitions de classe (`};`) dans les deux headers.
- `#include <string>` présent dans Contact.hpp.
- Nom du membre cohérent (`firstName`) entre .hpp et .cpp.
- Include guards de PhoneBook.hpp dans le bon ordre (#ifndef -> #define -> #include -> classe -> #endif).
- Makefile à jour (NAME = phonebook, SRCS et HEADERS corrects).

 Piège en cours — « ça compile » est trompeur :
main.cpp contient ENCORE l'ancien brouillon (une classe `contact` minuscule définie à l'intérieur du main, champs publics).
- Le build passe au vert parce que le main utilise sa propre classe locale.
- Contact.hpp/.cpp et PhoneBook.hpp/.cpp sont donc du CODE MORT pour l'instant.
 Priorité n°1 : vider main.cpp de cette classe inline et le brancher sur le vrai Contact (via le setter).

## À reprendre — ordre conseillé

1. Nettoyer main.cpp -> supprimer l'ancienne classe inline, utiliser le vrai Contact.
2. Compléter Contact : les 5 champs (firstName, lastName, nickName, phoneNumber, darkestSecret) + leurs accès, et une méthode display. Le tester seul dans un petit main.
3. Attaquer PhoneBook : PhoneBook.cpp est vide pour l'instant. Logique à écrire — ranger un contact, gérer le 9e qui écrase le plus ancien (buffer circulaire, penser au % 8).
4. Boucle de commandes ADD / SEARCH / EXIT dans le main, avec std::getline (pas cin >>, à cause des espaces dans les champs).
5. Formatage SEARCH : colonnes de 10, alignées à droite, tronquées avec un `.` -> <iomanip> (std::setw, std::right, std::setfill) + logique de troncature perso.
6. Validation : un champ ne peut pas être vide -> à bloquer à la saisie, pas à l'affichage.

## Rappels de règles (sujet)

- Corps de méthode dans un header (hors templates) = 0. -> déclarations dans .hpp, définitions dans .cpp.
- Chaque header inclut ses propres dépendances + include guards (double inclusion = 0).
- Allocation dynamique interdite dans ce PhoneBook -> tableau statique de 8.
- Classes en UpperCamelCase, fichiers nommés d'après la classe.
- Pas d'OCF exigée avant le Module 02.
- STL (vector/map/<algorithm>) interdite jusqu'au Module 08.


# RAPPORT — CPP Module 00 (ex01, suite 2)

== Ce qui a été corrigé (bravo) ==
- main.cpp : appel des méthodes CORRIGÉ. 
 Contact contact1;
 contact1.setFirstName("Nicolas");
 contact1.getFirstName();
 -> La distinction "définir avec ::" vs "appeler avec ." est intégrée. C'était LE point d'hier.
- Setters : toujours corrects. 
- Typo firstName corrigée dans le getter. 

== Ce qui reste : le type de retour des getters ==
Deux problèmes se cumulent.

-- 1) Signature .hpp et .cpp qui ne correspondent PAS --
Tu as changé le retour en char* dans Contact.cpp :
 char *Contact::getFirstName(){ ... }
...mais Contact.hpp déclare TOUJOURS :
 void getFirstName();

Erreur du compilateur : "no declaration matches 'char* Contact::getFirstName()'"
 note : candidate is 'void Contact::getFirstName()'

Le concept : la DÉCLARATION (.hpp) et la DÉFINITION (.cpp) doivent avoir une signature IDENTIQUE — même nom, mêmes paramètres, ET même type de retour. Si tu changes un côté, tu dois changer l'autre. Là tu n'as modifié que le .cpp.

-- 2) char* n'est pas le bon type --
Même en alignant les deux fichiers, char* ne marcherait pas :
 return firstName; // firstName est un std::string
Un std::string ne se convertit PAS automatiquement en char*.
Erreur type : "cannot convert std::string to char*".

char* est un réflexe C. En C++, un getter renvoie le TYPE du champ qu'il rend, donc ici : std::string.
 std::string getFirstName(); // dans le .hpp
 std::string Contact::getFirstName(){ return firstName; } // dans le .cpp

Conséquence dans main.cpp : tant que le .hpp dit void, `std::cout << contact1.getFirstName();` échoue aussi ("operand types are std::ostream and void" : on ne peut pas afficher void). Une fois le retour passé en std::string, cout l'affiche directement.

== À corriger ==
1. Type de retour des 5 getters = std::string, dans le .hpp ET le .cpp (les deux doivent être identiques).
2. Vérifier ensuite que `std::cout << contact1.getFirstName();` compile (ce sera le cas).

== Reste à faire ensuite ==
3. Ajouter display() à Contact.
4. PhoneBook : PhoneBook.cpp encore vide -> stockage + 9e qui écrase le plus ancien (buffer circulaire, % 8).
5. Boucle ADD / SEARCH / EXIT avec std::getline.
6. SEARCH : colonnes de 10, alignées à droite, tronquées avec '.', via <iomanip>.
7. Validation champ vide -> à la saisie.

== Bilan ==
Tu as passé le cap conceptuel du jour (appel de méthode). Le blocage restant est une leçon utile : déclaration et définition doivent toujours correspondre, et un getter renvoie le type de son champ (std::string), pas char*. Deux petites corrections et Contact sera pleinement fonctionnel -> tu pourras attaquer PhoneBook.

## Concepts acquis cette session

Séparation .hpp / .cpp · opérateur de résolution de portée :: · encapsulation (champ privé + setter) · include guards · composition entre classes · Makefile multi-fichiers.
