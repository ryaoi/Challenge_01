# Challenge_01
CH_INFO (Un challenge de la part de IUT)

1) Le problème:

Ce problème est inspiré d'une question donnée au Kangourou des mathématiques (http://www.mathkang.org/default.html) à des élèves de collège.
Il s'énonce de la façon suivante:

On souhaite fabriquer une boîte de forme parallélépipédique (un pavé droit) aux dimensions entières (en cm) ayant un volume minimal donné (ex: 1992 cm³) de sorte que la surface de cette  boîte en contact avec l'extérieur soit la plus petite possible (il s'agit de la somme des surfaces des 6 faces de la boîte). Donner les dimensions entières de cette boîte permettant d'obtenir un volume au moins égal au volume donné mais dont la surface des faces est la plus petite possible.

2) Les resultats:

| Le Volume               |    La surface |
|-------------------------|----------------------------------------------------|
| 1                       |     6         |
| 1992                    |     958       |
| 3001                    |     1272      |
| 5001                    |     1782      |
| 7001                    |     2222      |
| 10001                   |     2804      |
| 15001                   |     3696      |
| 20001                   |     4454      |
| 30001                   |     5842      |
| 40001                   |     7048      |
| 50001                   |     8182      |
| 100001                  |     13002     |
| 500001                  |     37942     |
| 1000001                 |     60196     |
| 2000001                 |     95254     |
| 5000001                 |     175444    |
| 10000001                |     278784    |
| 50000001                |     814912    |
| 100000001               |     1293152   |
| 1000000001              |     6001982   |
| 10000000001             | (x:2199, y:2138, z:2127    size:27852522) |
| 100000000001            | (x:4679, y:4629, z:4617    size:129268254) |
| 1000000000001           | (x:10116, y:9944, z:9941  size:600019928) |
| 10000000000001          | (x:21710, y:21476, z:21448   size:2784994576) |
| 100000000000001         | (x:46560, y:46347, z:46341  size:12926639214) |
| 1000000000000001        | (x:100360, y:99876, z:99765    size:60000199800) |
| 10000000000000001       | (x:215856, y:215255, x:215220   size:278495585400)|
| 100000000000000001      | (x:464610, y:464033, x:463834   size:1292661138784)|
| 1000000000000000001     | (x:1001155, y:999444, x:999402 size:6000001999236)|
| 18446744073709551615    | A vous de trouver |

![Alt text](https://github.com/ryaoi/Challenge_01/blob/master/example.png "Optional Title")

A partir de 10000000000000001, mon programme n'est pas comme celle ci donc vous allez pas obtenir une meme valeur et je pense meme que ca va segfault. C'est a cause de ma fonction find_xyz qui commence avec 1 alors changez cette valeur si vous voulez trouver des valeurs pour grand que 10000000000000001.

*La raison pourquoi cela amene a un segfault:
Ma fonction recursive a depasser la taille limite de stack. Il existe deux solutions. Soit cette fonction sera appliqué sur la partie heap au lieu de stack sinon je limite a une certain valeur pour que ma fonction recursive ne va pas partir trop loin.*

Mais bon... a partir de 10000000000000001, je ne peux pas vous dire si le resultat est bon. et aussi n'oubliez pas de utilsier des unsigned int128. Sinon vous allez avoir du mal pour trouver le resultat de la derniere valeur.

3) Les tips:
- Utilisation de baktrack. (sinon... euh votre programme ca va etre lent mais tres lent)
- Comprendre quelle composition de x * y * z comporte la surface la plus petite. (Peut etre un x^3 :+1: )
- Faut pas partir faire une boucle dans une boucle et aussi dans un boucle qui fait sa recherche de 1 a 10Million pour chaque boucle. (Par example si on a une boucle qui fait 6 loop alors pour le cas de boucle dans une boucle et dans une autre boucle, cela fait 6^3 = 216loop)
- Minimaliser votre calcul. C'est a dire, refait pas des calculs que vous avez deja fait, stock la valeur dans une variable.
- Utiliser un structure (cela vous permet a simplifier des taches)
- Si vous utilisez malloc bah c'est important de le free. (fuite de memoire  = pas de job)

**Commentaire:
hmmm mon pc a bien chauffé.....**
