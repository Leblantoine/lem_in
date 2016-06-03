##lem_in

Gestionnaire d'une fourmilière avec pathfinding.

Trouve tous les chemins possibles, utilise en priorté les plus courts.
Ajuste le nombre de chemin utilisé en fonction du nombre de fourmi.

###fonctionnement des maps

- Nombre de fourmis
- Nom des salles et coordonnées
- Tube entre les salles
- Commande pour indiquer la salle de départ et d'arrivée

####Exemple

```12
##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
6-5```
