# NOTES — CPP Module 00 (last maj : 05 aout 2026)

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

## Concepts acquis cette session

Séparation .hpp / .cpp · opérateur de résolution de portée :: · encapsulation (champ privé + setter) · include guards · composition entre classes · Makefile multi-fichiers.
