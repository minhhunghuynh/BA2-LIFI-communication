# Transmission d'images par lien optique (LiFi)

| | |
|---|---|
| **Cours** | TRAN-H201 — Projet multidisciplinaire II |
| **École** | École Polytechnique de Bruxelles (ULB) |
| **Auteur** | HUYNH Minhhung |
| **Groupe** | EIT 3 |
| **Superviseur** | OSEE Michel |
| **Lecteur** | CHASSAGNE Aurelien |

---

## Description du projet

Ce projet consiste à concevoir et implémenter un système de communication optique permettant la transmission d'images via une modulation **On-Off Keying (OOK)**. Le dispositif repose sur deux nœuds Arduino formant un réseau point-à-point :

- **User Node** : initie la transaction en envoyant une commande au Central Node, puis reçoit l'image transmise par signal lumineux et l'affiche sur un écran hôte.
- **Central Node** : répond à la commande en transmettant l'image sous forme de signal lumineux modulé.

La communication est fonctionnelle sur une distance de **180 cm**, à un débit allant de **5 kbit/s à 35 kbit/s**. Une version avec **code correcteur d'erreur Hamming(7,4)** a été implémentée pour améliorer la fiabilité de la transmission.

---

## Architecture du système

### Émission

L'émetteur utilise une **LED** pilotée par un transistor amplificateur **BC337** (NPN en silicium), alimenté en externe via un port USB 5V. Ce transistor fonctionne comme un interrupteur commandé en courant, permettant d'activer la LED avec un courant de commande réduit, assurant ainsi une portée plus longue.

### Réception

Le circuit de réception convertit le signal lumineux en signal numérique interprétable par l'Arduino du User Node. Il comprend plusieurs étages :

1. **Photodiode et amplificateur transimpédance** : convertit le courant photogénéré en tension.
2. **Filtre passe-haut RC** : élimine les composantes basses fréquences (lumière ambiante).
3. **Amplificateur inverseur** : amplifie le signal filtré.
4. **Comparateur à hystérésis** : produit un signal numérique propre (0/1) à partir du signal analogique amplifié.

Un **PCB** (circuit imprimé) a été conçu pour le circuit de réception, accompagné d'un **support 3D** imprimé pour le User Node.

---

## Software

Le code Arduino implémente les fonctionnalités suivantes :

- **Fonctions élémentaires** : émission et réception de bits via OOK.
- **Protocole de communication** : trame de synchronisation entre le User Node et le Central Node.
- **Code correcteur d'erreur** : implémentation du code de Hamming(7,4) pour détecter et corriger les erreurs de transmission.
- **Envoi de la commande** : le User Node envoie une commande au Central Node pour déclencher la transmission.
- **Réception de l'image** : réception et reconstruction des octets de l'image.
- **Décodage et affichage** : décodage des données reçues et affichage de l'image sur l'hôte.

---

## Structure du dépôt

```
ba2-eit-lifi-main 2/
├── Arduino/                  # Code source Arduino (User Node & Central Node)
├── Documentation/            # Schémas, PCB et fichiers techniques
├── Gestion/                  # Fichiers de gestion de projet (SWOT, réunions)
├── README.md                 # Ce fichier
└── Rapport_projet_BA2_groupe_EIT3.pdf  # Rapport complet du projet
```

---

## Résultats

- Transmission d'images fonctionnelle sur **60 cm**.
- Débit de communication : **5 à 35 kbit/s**.
- Code correcteur d'erreur Hamming(7,4) implémenté avec succès.
- Conception d'un PCB et d'un support 3D pour le prototype final.

---

## Technologies utilisées

- **Matériel** : Arduino Uno, LED, photodiode, transistor BC337, amplificateur opérationnel, composants passifs (R, C)
- **Logiciels** : Arduino IDE, KiCad (PCB), logiciel de modélisation 3D
- **Protocole** : On-Off Keying (OOK), code Hamming(7,4)

---

*Projet réalisé dans le cadre du cours TRAN-H201 — École Polytechnique de Bruxelles, ULB.*
