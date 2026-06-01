# Status report

- Groupe : 3
- Date : 24/10/2024

## Ordre du jour

- [Plan d'ensemble](#plan-d'ensemble)
- [Activités](#activités)
- [Risques et problèmes](#risques-et-problèmes)
- [Discussion de contenu](#discussions-de-contenu)

## Plan d'ensemble

![alt text](<../plans ( images)/gantt_24_10.png>)

## Activités
| Activités terminées la semaine passée | Activités planifiées la semaine prochaine | 
| ------ | ------ |
|Code affichage image (Djibril) |rédaction de l'introduction du rapport (Djibril)|
|Code "SEND" (Nora) |Code "SEND" avec code correcteur d'errreur (Nora)|
|Code "réception du paquet envoyé par le central node" (Abdalla) |code "réception du paquet du central node" avec code correcteur d'erreur (Abdalla)| 
|Schéma du filtre passe-bas (Bily)|Recherches sur l'amplificateur inverseur + caractéristiques des composants du filtre passe-bas (Bily)|
|Schéma du circuit (partie amplificateur) (Minhhung)|filtre passe-haut (calcul des valeurs des composants) + branchements amplificateurs-filtres (Minhhung)|
|recherches sur comparateur (Winnie)|recherches sur comparateur (suite) + rédaction abstract du rapport + table des matières du rapport (Winnie)|

## Risques et problèmes

Sous forme de **tableaux** mais en _Markdown_ pur, **il n'est pas possible d'afficher plusieurs lignes par cellule**.

**Solution 1** : utilisation d'une seule ligne par cellule et de la balise html `<br>` pour passer à la ligne


| Impact \ Probability   | Medium   | High   | Issue  |
| ------                 | ------   | ------ | ------ |
| **Medium**             | **X** | -décalage des "milestones"| 
| **High**               | -  pas de possibilité de réellement tester les codes sans circuit fonctionnel <br> -signal instable + brouillé |  |


**Solution 2** : utilisation d'une rangée intermédiaire vide et de rangées supplémentaires en dessous de la ligne correspondante

| Impact \ Probability 	| Medium 	| High 	| Issue |
| -- 				   	| -- 		| -- 	| -- 	|
|  			    	   	|  		    |  	    |  	    |
| **High** 				| Risque 1 	|   	|   	|
|  				    	| Risque 2 	|   	|   	|
|  					    | 		    |   	| :warning:  Problème à grand impact |
|  				   	    |  		    |  	    |  	    |
| **Medium**			|   **X**	| Risque 1 élevé |   	|
|  						|   		| Risque 2 élevé |   	|

**Solutions alternatives** : faites preuves d'imagination 

**NB** : pour la solution 1, l'impact medium se trouve en rangée 1 tandis que pour la solution 2, c'est l'inverse (cf. graphique du status_report original). A vous de choisir, ce que vous préférez comme solution. 

## Discussions de contenu
prochaine phase de la réalisation du circuit : optimisation -> réalisation de graphes pour trouver les valeurs optimales des composants et/ou test de différentes valeurs des différents composants (résistance, capacité, amplificateur) pour assurer la stabilité du signal <br> 
prochaine réunion : chaque membre du groupe présente et explique aux autres ce sur quoi il a travaillé jusqu'à présent 
