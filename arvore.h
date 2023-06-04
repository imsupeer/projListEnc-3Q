typedef int Item;

typedef struct arv* Arv;

Arv no(Arv A, Item x, Arv B);
void emOrdem(Arv A);
void preOrdem(Arv A);
void posOrdem(Arv A);
void nivelOrdem(Arv A);
void destroi(Arv *A);
void inserir(Item x, Arv *A);
int busca(Item x, Arv A);
Item removeMax(Arv *A);
void remover(Item x, Arv *A);
