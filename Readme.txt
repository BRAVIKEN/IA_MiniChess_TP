Le fichier mymc.h contient des fonctions de gestion d'un plateau du jeu MiniChess Silverman. Seules les fonctions de déplacement des pions ont été faites. Les déplacements des autres pions restent à faire.
Le fichier s1.cpp initialise le plateau et l'affiche, en noir et blanc et en couleur.

Nous avons créer plusieurs class static qui nous permettent de gérer l'ensemble des pièces.
Chaque pièces a sa class respective contenant une fonction allPossible prenant la position de la pièce en argument et qui retourne l'ensemble des mouvements possible en fonction du déplacement de la pièce depuis cette position.

La classe GameHelper comporte les principales fonctions d'aide au jeu tel que jouer et déjouer mais aussi des fonctions de vérification de mise en échec d'un joueur (checkWhite, checkBlack).
Les fonctions AllPossibleMovesBlack et AllPossibleMovesBlack renvoient la liste de tout les coups possible d'une couleur sans se mettre en échec.

La fonction randomGame de la classe IA permet de jouer une partie de manière aléatoire à partir d'un état.

MCTS (moyenne sur 5 parties): 
    Playout        temps
      1k         0.0558976 s
      10k        0.157949  s
      100k       0.232009  s
      1 000k     0.930106  s