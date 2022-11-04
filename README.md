# PRG1_Labo_04_B
Ecrire un programme qui affiche pour une année [1800 – 2100] saisie par
l’utilisateur le calendrier complet en tenant compte des années bissextiles.

Janvier 2022
 L  M  M  J  V  S  D
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31

Fevrier 2022
 L  M  M  J  V  S  D   
          1  2  3  4   
 5  6  7  8  9 10 11   
12 13 14 15 16 17 18   
19 20 21 22 23 24 25   
26 27 28   

## But
* Mise en page soignée
* Interface utilisateur
* Boucle
* Sous-programmes et compilation séparée
## Remarques
* Une année est bissextile si elle est divisible par 400, ou par 4 et pas par 100.
* En cas de saisie incorrecte, l’utilisateur est invité à recommencer sa saisie.
* Un menu « voulez-vous recommencer [O/N] » permet de quitter ou recommencer l’opération.
* Tous les « 1 janvier » sont des lundis ... à moins que vous puissiez faire mieux
## Option
La librairie « ctime » http://www.cplusplus.com/reference/ctime peut vous aider
à déterminer le 1er jour d’une année donnée.