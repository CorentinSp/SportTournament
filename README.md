# SportTournament
Projet QT Licence

## Auteurs

- Tanguy BARROSO : 40%
- Corentin SILVA PERREIRA : 60%

## Descriptif

SportTournament permet pour l'instant d'afficher une liste d'équipes, avec les méthodes CRUD, ainsi qu'un détail pour l'équipe.

De plus l'application utilise une base de donnée SQLite.

## Usage

Il suffit de lancer l'application.

## Techniques de programmation utilisées

### QSqlDatabase

SportTournament utilise QSqlDatabase avec une base QSQLite pour la gestion des données.

### QObject avec QProperties

Chaque équipe est un QObject avec plusieurs propriétés. La modification d'une des propriétés entraîne son rafraîchissement dans les listes.

### ListView + Modèle C++

La liste d'équipe s'appuie sur un modèle C++ qui contient une liste. Elle est éditable (on peut ajouter des équipes dans la liste).

La liste est triée par défaut par puissance de réception. Mais le critère de tri peut être modifié dans les options.

### PullDownMenu + QValidator

Un PullDownMenu est présent dans la page de la liste des équipes, il permet d'ajouter un élément. Il affiche un champs qui utilise un QValidator qui permet de s'assuer que le nom choisi pour l'équipe n'est pas vide.

### Clic

Un clic sur une équipe ouvre la page de detail.

## Detail: Modif 

Le nom de l'équipe est éditable. 

### Menu Contextuel

Un clic long affiche un menu contextuel permettant de supprimer une équipe.

### Remorse

L'item précédent utilise une RemorseItem afin de pouvoir annuler la suppression.

## Bugs connus

- Lors de l'ajout d'une équipe, si on essai de supprimer le texte dans le champs, le dernier caractère n'est pas supprimé.

## Précisions

Coco est vraiment le boss, mais Tanguy n'est pas mauvais non plus.