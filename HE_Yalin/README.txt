Yalin HE  INF224

Pour ce projet, j'ai fini de créer un projet client/serveur, où le client est une télécommande du serveur, qui est un gestionnaire de médias contenant des images, des vidéos et d'autres fichiers. La télécommande peut demander au serveur des informations sur le contenu, et peut jouer un contenu sur le serveur. Le serveur est codé en C++ et le client est une interface graphique Java Swing. Ils peuvent communiquer à l'aide de sockets.

Pour 'run' the projet, il faut aller dans cpp, faire:  'make run'.
Dans swing, faire : make run

étape 4 :
Q:Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
R:On l'appelle une méthode abstraite ou virtuelle pure, il faut déclarer dans le fichier multimedia.h comme "virtual" et avec l'indication " = 0 ".
virtual void play() const = 0; //etape 4 methode abstraite / virtuelle pure
Q:Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
R:Multimedia est aussi une classe abstraite qui ne peut être instanciée car elle contient la méthode virtuelle pure play().

étape 5 :
Q:Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
la caractéristique est le polymorphisme qui permet de définir plusieurs comportement au même objet.
Q:Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
 En c++ il faut déclarer la fonction display comme virtual dans la classe multimedia. 
Q:Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
Les éléments du tableau sont des pointeurs vers des objets car Multimedia est une classe virtuelle. Il ne peut donc pas être instancié.
Dans java, le polymorphisme fonctionne si on déclarait un tableau d'objets, car java fait abstraction des manipulations que l'on a à faire en c++, il travaille en interne avec des reference.

étape 6:
R:Pour l'accesseur, on peut rajouter "const" à la signature de la méthode, pour empecher l'alteration du contenu pointé par le pointeur retourné.
Ainsi, les modifications apportées au tableau chaptiredure ne résolvent pas le problème de suppression du tableau. Nous devrions donc renvoyer une copie du tableau chaptiredure.
Nous pouvons renvoyer le tableau sous la forme d'une variable const. Pour "setter"//modifier, nous devons faire une copie profonde du tableau.

étape 7:
R:La mémoire n'est pas gérée automatiquement par c++, elle est la mémoire dynamique (ex: le tas, la mémoire allouée par new). 
Donc les classes où on a utilisé ce mot clé doivent être modifiées pour empecher les fuites de mémoire. 
Donc dans la classe Film, on besoin d'un destructeur qui libérera la mémoire allouée avant la destruction de l'objet.
Chaque classe avec pointeur ou tableau doit être modifiée et avoir dans les lignes de destructeur afin de supprimer les objets pointés. 
La copie d'objet doit tenir compte du fait que les objets pointés ne sont pas copiés. Nous devons réimplémenter l'opérateur = pour faire une copie profonde.

étape 8:
Q:On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
R:Il doit s'agir de pointeurs car nous ne voulons pas copier les objets lorsque nous les faisons appartenir à un groupe. 
Cela permet l'utilisation du polymorphisme sur les objets du groupe. 
En Java, la situation est différente car un objet est toujours référencé.

étape 9:
smart printer

étape 10:
La classe Gestion a été implémentée, dont l'objectif est d'avoir un contrôle général sur les cartes Multimédia et Groupe, avec des méthodes permettant d'ajouter un nouveau multimédia (image, vidéo, film) ou groupe, d'imprimer et de lire un objet multimédia spécifique, ou tous les éléments dans un groupe, ainsi que supprimer un objet enregistré.

étape 13:
try/catch

