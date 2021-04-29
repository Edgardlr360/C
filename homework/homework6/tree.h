#define MAX 100
typedef struct treenode {
  char* ur; 
  char* pw; 

  struct treenode* leftChild;
  struct treenode* rightChild;
  unsigned int depth;
} node;

char linea[MAX], pw[MAX], ur[MAX];
int saca(); 
void get (char l[MAX],char p[MAX],char u[MAX]); 
node* insert(char* u, char* p, node* pos, int d); 
void alpha(node* position); 
void delete(node* position, char* u, char* p, int* n);
