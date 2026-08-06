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

# RAPPORT — CPP Module 00 (suite)

== Ce qui a avancé depuis hier ==
- Contact étendu aux 5 champs : firstName, lastName, nickName, phoneNumber, darkestSecret. 
- Les 5 setters sont écrits et CORRECTS (setFirstName, setLastName, etc.). 
- Les 5 getters sont écrits (mais buggés, voir plus bas).
- NOTES.md ajouté au repo. 
- Makefile toujours bon (NAME = phonebook, SRCS, HEADERS). 

== État : ex01 NE COMPILE PAS ==
Deux points conceptuels bloquent. Rien de grave, mais à comprendre.

-- 1) Les getters renvoient void au lieu de std::string --
Dans Contact.hpp (lignes 17-21) et Contact.cpp, tes getters sont déclarés :
 void getFirstName(); // <- void
...mais leur corps fait `return firstName;`.
Erreur du compilateur : "return-statement with a value, in function returning 'void'".

Le concept : un GETTER a pour rôle de RENDRE la valeur du champ. Son type de retour doit donc être le TYPE de ce qu'il rend, soit std::string — pas void.
void = "ne renvoie rien", ce qui contredit un getter.
À corriger : le type de retour des 5 getters (dans le .hpp ET le .cpp).

Bonus : dans getFirstName, tu as écrit `return firstname;` (minuscule) au lieu de `firstName`. Simple typo -> identifiant inconnu.

-- 2) main.cpp : tu confonds "définir" et "appeler" une méthode --
Ton main fait :
 contact contact1; // (a)
 Contact::setFirstName("Nicolas"); // (b)
 std::cout << Contact::getFirstName(); // (b)

(a) `contact` (minuscule) n'existe pas : ta classe s'appelle Contact (majuscule).

(b) LE point important. Tu appelles les méthodes avec `Contact::`, comme quand tu les DÉFINIS dans le .cpp. Mais :
- `Contact::setFirstName` (avec ::) sert à DÉFINIR la méthode -> "cette méthode appartient à Contact". C'est ce que tu fais, à juste titre, dans Contact.cpp.
- Pour APPELER une méthode, il faut un OBJET et l'opérateur point :
 contact1.setFirstName("Nicolas");
 contact1.getFirstName();
 La méthode agit SUR un objet précis. Sans objet, la question "le firstName de QUEL contact ?" n'a pas de réponse -> d'où l'erreur "cannot call member function without object".

Résumé mental :
 Class::methode(...) => pour DÉFINIR (dans le .cpp)
 objet.methode(...) => pour APPELER (dans le main / ailleurs)

== Reste à faire (rappel, ordre conseillé) ==
1. Corriger le type de retour des getters (std::string) + la typo firstName.
2. Corriger le main : `Contact contact1;` puis `contact1.setFirstName(...)` / `contact1.getFirstName()`.
3. Ajouter une méthode display() à Contact (affichage d'un contact).
4. PhoneBook : PhoneBook.cpp est encore vide -> logique de stockage, gérer le 9e qui écrase le plus ancien (buffer circulaire, % 8).
5. Boucle ADD / SEARCH / EXIT dans le main, avec std::getline.
6. SEARCH : colonnes de 10, alignées à droite, tronquées avec '.', via <iomanip> (setw, right, setfill).
7. Validation : champ vide interdit -> bloquer à la SAISIE.

== Bilan ==
Bonne progression sur Contact (structure + setters nickel). Les deux blocages sont des confusions classiques et FORMATRICES : le type de retour d'un getter, et la différence entre DÉFINIR (::) et APPELER (.) une méthode. Une fois ces deux points intégrés, tu auras un Contact fonctionnel et tu pourras enchaîner sur PhoneBook.

## Concepts acquis cette session

Séparation .hpp / .cpp · opérateur de résolution de portée :: · encapsulation (champ privé + setter) · include guards · composition entre classes · Makefile multi-fichiers.
