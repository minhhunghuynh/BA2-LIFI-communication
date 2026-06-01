# Status report

- Groupe : 3
- Date : 21/11/2024

## Ordre du jour

- [Plan d'ensemble](#plan-d'ensemble)
- [Activités](#activités)
- [Risques et problèmes](#risques-et-problèmes)
- [Discussion de contenu](#discussions-de-contenu)

## Plan d'ensemble

![alt text](<../plans ( images)/gant_14_11_24.png>)

## Activités
| Activités terminées la semaine passée | Activités planifiées la semaine prochaine | 
| ------ | ------ |
|Comparateur ( Winnie)|rédaction de l'introduction du rapport (Djibril)|
|code "SEND"  (Nora)|  Correction du code  pour envoie du SEND sans correcteur d'erreur (Nora).| 
|Code "réception du paquet du central node" | code correcteur d'erreur (Abdalla)| 
|l'amplificateur inverseur + caractéristiques des composants du filtre passe-bas (Bily)|Teste du code send sans correcteur d'erreur et avec correcteur d'erreur (Nora,Djibril,Abdalla). |
|Filtre passe-haut (calcul des valeurs des composants) + branchements amplificateurs-filtres (Minhhung)||
|Rédaction abstract du rapport + table des matières du rapport (Winnie)|Rédaction rapport partie circuit (Bily,Winnie et Minhhung) et terminer l'introduction pour le rapport (Djibril) |
| premier sous-circuit avec amplificateur et Filtre passe-bas ( Bily et Minhhung)  et deuxième sous-circuit avec filtre passe-haut et amplificateur inverse (Bily,Winnie et Minhhung)| assemblage des deux sous-circuits et faire le teste (Bily,Winnie et Minhhung) ||



## Risques et problèmes

Sous forme de **tableaux** mais en _Markdown_ pur, **il n'est pas possible d'afficher plusieurs lignes par cellule**.

**Solution 1** : utilisation d'une seule ligne par cellule et de la balise html `<br>` pour passer à la ligne


| Impact \ Probability   | Medium   | High   | Issue  |
| ------                 | ------   | ------ | ------ |
| **Medium**             | **X** |" Code envoi du SEND fonctionne ,mais les autres non"| 
| **High**               | -  pas de possibilité de réellement tester les codes sans circuit fonctionnel car le comparateur ne fonctionne pas quand on l'attache au circuit <br>  |  |


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
prochaine phase de la réalisation du circuit : réalisation du circuit complet<br> 
prochaine réunion :Chaque membre doit continuer à rediger sa partie dans le rapport du projet.

Abdalla devra écrire un code correcteur.
Nora doit vérifier son code envoi du  send et faire un code corcorrecteur avec 

