# Status report

- Groupe : 3
- Date : 25/02/2025

## Ordre du jour

- [Plan d'ensemble](#plan-d'ensemble)
- [Activités](#activités)
- [Risques et problèmes](#risques-et-problèmes)
- [Discussion de contenu](#discussions-de-contenu)

## Plan d'ensemble
![alt text](<../plans ( images)/gantt_25_02_25.png>)
![alt text](<../plans ( images)/gantt_25_02_25.2.png>)

## Activités
| Activités terminées la semaine passée | Activités planifiées la semaine prochaine | 
| ------ | ------ |
|Rédaction de l'introduction et de l'abstract + Support 3D (Minhhung)  |Forme du rapport + rédaction SWOT, et fonctionnement de groupe (Minhhung)|
|Finalisation codes (Nora) |Implémentation Hamming(7,4) dans le code réception (Nora)| 
|Rédaction partie code affichage (Djibril)|Suite rédaction partie code affichage (Djibril)| 
|Simulations de l'ensemble du circuit (Bily)| PCB + schémas signaux (Bily)|
|Finalisation codes (Abdalla)|Trouver solution pour le code SEND (Abdalla)|
|Recherches sur transistor (Winnie)|Rédaction rapport partie circuit (Winnie)|


## Risques et problèmes

Sous forme de **tableaux** mais en _Markdown_ pur, **il n'est pas possible d'afficher plusieurs lignes par cellule**.

**Solution 1** : utilisation d'une seule ligne par cellule et de la balise html `<br>` pour passer à la ligne


| Impact \ Probability   | Medium   | High   | Issue  |
| ------                 | ------   | ------ | ------ |
| **Medium**             | **X** |Codes fonctionnent indépendamment du circuit mais pas avec| 
| **High**               | Code SEND fonctionne de façon intermittente <br>  | Pas assez de Central nodes pour tous les groupes |


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
-Utilisation d'un transistor en série avec la LED pour augmenter la portée de la LED = bonne idée.
-Les codes SEND et RECEPTION fonctionnent parfaitement lorsque la communication se fait directement entre les 2 Arduinos.
-Le Central Node ne capte pas systématiquement le SEND alors que le code SEND fonctionne -> problème de HARDWARE ? + pas de possibilité de tester le circuit et le code réception ensemble