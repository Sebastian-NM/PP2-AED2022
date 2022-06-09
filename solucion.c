// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Struct Declarations
typedef struct cyberAttackType cyberAttackType;
typedef struct cyberAttackTypeList cyberAttackTypeList;
typedef struct cyberAttack cyberAttack;
typedef struct cyberCriminal cyberCriminal;
typedef struct listCriminal listCriminal;
typedef struct country country;
typedef struct treeNode treeNode;
typedef struct vertex vertex;
typedef struct edge edge;
typedef struct AdjList AdjList;
country *chooseNacionality(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl);
country *findCountry(treeNode *root, int key);
cyberAttackType *chooseCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl);
cyberCriminal *chooseCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl);

// Struct's bodies
struct cyberAttackType
{
    char *code;
    char *name;
    char *description;
    char *channels;
    char *counter;
    cyberAttackType *next;
};

struct cyberAttackTypeList
{
    cyberAttackType *first;
};

struct cyberCriminal
{
    char *ID;
    char *organization;
    country *nacionality;
    char *knownAttacks;
    cyberCriminal *next;
    int *counter;
    int *deletable;
};

struct listCriminal
{
    cyberCriminal *head;
};

struct country
{
    int *ID;
    char *name;
    char *population;
    char *continent;
    int *deletable;
};

struct cyberAttack
{
    country *countryOfOrigin;
    country *destinationCountry;
    cyberAttackType *type;
    cyberCriminal *responsible;
    float *duration;
};

struct treeNode
{
    int key;
    struct country *country;
    struct treeNode *right;
    struct treeNode *left;
};

struct vertex
{
    country *country;
    vertex *next;
    edge *ad;
    int visited, finished;
    int amount;
    char *ant;
};

struct edge
{
    vertex *vrt;
    edge *next;
    int seconds; /// peso
    int gb;
    char *attackType;
    char *cyberCriminal;
    char *attacker;
    char *attacked;
};

struct AdjList
{
    vertex *country;
    AdjList *next;
};

vertex *headAdj = NULL;
AdjList *ini = NULL;
AdjList *finale = NULL;

/// | | | | | | | | | | | | | | Utilities | | | | | | | | | | | |

char *mystrcpy(char *dst, const char *src)
{
    char *ptr = dst;
    while ((*dst++ = *src++))
        ;
    return ptr;
}

/// | | | | | | | | | | | | | | Menus | | | | | | | | | | | | | |

void mainMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{

    // HEADER
    system("cls");
    int option;
    printf("[Main Menu]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attacks\n2.Cyber Attack Types\n3.Cyber Criminals\n4.Countries\n5.Stadistics\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        cyberAttackMenu(treeRoot, LtCriminal, catl);
        break;

    case 2:
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl);

    case 3:
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
        break;

    case 4:
        countriesMenu(treeRoot, LtCriminal, catl);
        break;

    case 5:
        statisticsMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        mainMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

void cyberAttackMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{

    // HEADER
    system("cls");
    int option;
    printf("[Cyber Attacks]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attack Simulation\n2.Manual registration\n3.Cyber Attack Routes\n4.Delete a Cyber Attack\n5.Update a Cyber Attack\n6.Show graph of Cyber Attacks\n7.Go back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        printf("Cyber Attack Simulation");
        break;

    case 2:
        createEdge(treeRoot,LtCriminal,catl);
        break;

    case 3:
        printf("Cyber Attack Routes");
        break;

    case 4:
        printf("Delete a Cyber Attack");
        break;

    case 5:
        updateGraph(treeRoot,LtCriminal,catl);
        break;

    case 6:
        showGraph(treeRoot,LtCriminal,catl);
        break;

    case 7:
        mainMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

void cyberAttackTypesMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{

    // HEADER
    system("cls");
    int option;
    printf("[Cyber Attack Types]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Add a new type\n2.Delete a type\n3.Show types\n4.Update a type\n5.Go Back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        system("cls");
        addCyberAttackType(treeRoot, LtCriminal, catl);
        break;

    case 2:
        system("cls");
        deleteCyberAttackType(treeRoot, LtCriminal, catl);
        break;

    case 3:
        system("cls");
        showCyberAttackTypes(treeRoot, LtCriminal, catl);
        break;

    case 4:
        system("cls");
        updatecyberAttackType(treeRoot, LtCriminal, catl);
        break;

    case 5:
        system("cls");
        mainMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

void cyberCriminalsMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{

    // HEADER
    system("cls");
    int option;
    printf("[Cyber Criminals]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.New Cyber Criminal\n2.Delete a Cyber Criminal\n3.Show known Cyber Criminals\n4.Update data\n5.Go Back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        system("cls");
        addCriminal(treeRoot, LtCriminal, catl);
        break;

    case 2:
        system("cls");
        deleteCriminal(treeRoot, LtCriminal, catl);
        break;

    case 3:
        system("cls");
        showCriminal(treeRoot, LtCriminal, catl);
        break;

    case 4:
        system("cls");
        updateCriminal(treeRoot, LtCriminal, catl);
        break;

    case 5:
        system("cls");
        mainMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

void countriesMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    fflush(stdin);

    // HEADER
    system("cls");
    int option;
    printf("[Countries]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.New Country\n2.Delete a country\n3.Show countries\n4.Update data\n5.Go Back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        addCountry(treeRoot, LtCriminal, catl);
        break;

    case 2:
        deleteCountry(treeRoot, LtCriminal, catl);
        break;
        fflush(stdin);

    case 3:
        system("cls");
        if (treeRoot == NULL)
        {
            printf("No Countries found.");
        }
        else
        {
            inOrder(treeRoot);
        }
        char nothing[10];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        countriesMenu(treeRoot, LtCriminal, catl);
        break;

    case 4:
        updateCountry(treeRoot, LtCriminal, catl);
        break;

    case 5:
        mainMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        countriesMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

void statisticsMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    // HEADER
    system("cls");
    int option;
    printf("[Statistics]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Total Cyberattacks sent\n2.Total Cyberattacks received\n3.Cyberattacks sent and received by country\n4.Cyberattacks sent and received by type\n5.Cyberattacks sent and received by responsible\n6.Top 3 countries with the most received attacks\n7.Top 3 cybercriminals with the highest amount of attacks\n8.Go back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        printf("Total Cyberattacks sent");
        break;

    case 2:
        printf("Total Cyberattacks received");
        break;

    case 3:
        printf("Cyberattacks sent and received by country");
        break;

    case 4:
        printf("Cyberattacks sent and received by type");
        break;

    case 5:
        printf("Cyberattacks sent and received by responsible");
        break;
    case 6:
        printf("Top 3 countries with the most received attacks");
        break;
    case 7:
        printf("Top 3 Cyber Criminals with the highest amount of attacks");
        break;
    case 8:
        mainMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        countriesMenu(treeRoot, LtCriminal, catl);
        break;
    }
}

/// | | | | | | | | | | | BS TREE | | | |  | | | | | | | | | | |

struct treeNode *search(struct treeNode *root, int x)
{
    if (root == NULL || root->key == x)
        return root;
    else if (x > root->key)
        return search(root->right, x);
    else
        return search(root->left, x);
}

struct treeNode *findMinimum(struct treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMinimum(root->left);
    return root;
}

struct treeNode *newNode(int x, struct country *country)
{
    struct treeNode *p = malloc(sizeof(struct treeNode));
    p->key = x;
    p->country = country;
    p->left = p->right = NULL;

    return p;
}

struct treeNode *insert(struct treeNode *root, int x, struct country *country)
{
    if (root == NULL)
        return newNode(x, country);
    if (x < root->key)
        root->left = insert(root->left, x, country);
    else
        root->right = insert(root->right, x, country);

    return root;
}

struct node *minValueNode(struct node *node)
{
    struct treeNode *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct treeNode *deleteNode(struct treeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct treeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct treeNode *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inOrder(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        showCountry(root);
        inOrder(root->right);
    }
}

void inOrderOnlyKeys(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrderOnlyKeys(root->left);
        showCountryWithKey(root);
        inOrderOnlyKeys(root->right);
    }
}

///| | | | | | | | | | | GRAPH  | | | |  | | | | | | | | | | |

void insertVertex(country*countryV)
{
    vertex *aux;
    vertex *novus = (vertex *)malloc(sizeof(vertex));
    system("cls");

    novus->country = countryV;

    novus->next = NULL;
    novus->ad = NULL;
    novus->visited = novus->finished = 0;
    novus->amount = -1;
    novus->ant = 0;
    if (headAdj == NULL)
    {
        headAdj = novus;
    }
    else
    {
        aux = headAdj;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = novus;
    }
}

void createEdge(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    int ini;
    int fin;
    const char *src;
    edge *novus = (edge *)malloc(sizeof(edge));
    novus->next = NULL;
    vertex *aux;
    vertex *aux2;
    system("cls");

    printf("\nSelect the attacking country. ");
    ini = chooseNacionality(treeRoot, LtCriminal, catl)->ID;

    printf("\nSelect the Attacked country. ");
    fin = chooseNacionality(treeRoot, LtCriminal, catl)->ID;

    printf("\nDuration of attack in seconds: ");
    scanf("%i", &novus->seconds);
    printf("\nAmount of gygabites affected: ");
    scanf("%i", &novus->gb);
    printf("\n");
    novus->attackType = chooseCyberAttackType(treeRoot, LtCriminal, catl)->name;
    printf("\n");
    novus->cyberCriminal = chooseCyberCriminal(treeRoot, LtCriminal, catl)->organization;
    printf("\n");

    aux = headAdj;
    aux2 = headAdj;

    while (aux2 != NULL)
    {
        if (aux2->country->ID == fin)
        {
            break;
        }
        aux2 = aux2->next;
    }

    while (aux != NULL)
    {
        if (aux->country->ID == ini)
        {
            novus->attacker = aux->country->name;
            novus->attacked = aux2->country->name;
            addEdge(aux, aux2, novus);
            system("cls");
            printf("\nAttack registered successfully\n");
            sleep(1);
            cyberAttackMenu(treeRoot, LtCriminal, catl);
        }
        aux = aux->next;
    }
}

void addEdge(vertex *aux, vertex *aux2, edge *novus)
{
    edge *a;
    if (aux->ad == NULL)
    {
        aux->ad = novus;
        novus->vrt = aux2;
    }
    else
    {
        a = aux->ad;
        while (a->next != NULL){
            a = a->next;
        }
        novus->vrt = aux2;
        a->next = novus;
    }
}

void showGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    vertex*aux = headAdj;
    edge* ed;
    printf("GRAPH\n");
    printf("----------\n");
    while(aux!=NULL){
	    printf("%s--> ",aux->country->name);
        if(aux->ad!=NULL){
            ed=aux->ad;
            while(ed!=NULL){
			    printf("%s",ed->vrt->country->name);
			    printf("[%s,",ed->attackType);
			    printf(" %s,",ed->cyberCriminal);
			    printf(" %i,",ed->gb);
			    printf(" %i]  ",ed->seconds);
                ed=ed->next;
            }
        }
        printf("\n");
        aux=aux->next;
    }
    printf("\n");
    char nothing[100];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    cyberAttackMenu(treeRoot, LtCriminal, catl);

}

void modifyGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl,vertex*pv,edge*ar)
{
    int option;
    int x;
    vertex*y = headAdj;
    system("cls");
    printf("%s --> %s\n", pv->country->name,ar->vrt->country->name);
    printf("---------------\n");
    printf("1. Attack duration: %i seconds\n", ar->seconds);
    printf("2. Gb affected: %i\n",ar->gb);
    printf("3. Attack type: %s\n",ar->attackType);
    printf("4. Criminal: %s\n",ar->cyberCriminal);
    printf("5. Attacked country\n");
    printf("6. Attacking country\n");
    printf("7. Go back\n");

    printf("Number to modify: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        system("cls");
        printf("Enter new duration:\n");
        scanf("%d",&x);
        ar->seconds = x;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        break;

    case 2:
        system("cls");
        printf("Enter Gb:\n");
        scanf("%d",&x);
        ar->seconds = x;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        break;

    case 3:
        system("cls");
        ar->attackType = chooseCyberAttackType(treeRoot, LtCriminal, catl)->name;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        break;

    case 4:
        system("cls");
        ar->cyberCriminal = chooseCyberCriminal(treeRoot, LtCriminal, catl)->organization;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        break;

    case 5:
        system("cls");
        printf("\nSelect the new Attacked country. ");
        x = chooseNacionality(treeRoot, LtCriminal, catl)->ID;
        while(y!=NULL){
            if (y->country->ID == x){
                break;
            }
            y = y->next;
        }
        ar->vrt = y;
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        break;

    /*case 6:
        system("cls");
        vertex*r = pv;
        vertex*t = pv;
        int id;
        vertex*q;
        edge*x = ar;
        edge*y;
        edge*m;
        if (r->ad = ar){
            r->ad = x->next;
            x->next = NULL;
            printf("\nSelect the new Attacking country. ");
            id = chooseNacionality(treeRoot, LtCriminal, catl)->ID;
            while(t!=NULL){
                if(t->country->ID == id){
                    q = t;
                }
                t = t->next;
            }

        }
        else{
            y = r->ad;
            while (y->next!=x){
                y = y->next;
            }
            y->next = x->next;
            x->next = NULL;
            printf("\nSelect the new Attacking country. ");
            id = chooseNacionality(treeRoot, LtCriminal, catl)->ID;
            fflush(stdin);
            while(t!=NULL){
                if(t->country->ID == id){
                    q = t;
                }
                t = t->next;

        }
        if (q->ad == NULL){
                q->ad = x;
            }
        else{
            m = q->ad;
            while(m->next!=NULL){
                m = m->next;
            }
            m->next = x;
        }
        printf("\nData updated\n");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal, catl);
        break;*/


    case 7:
        cyberAttackMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyGraph(treeRoot,LtCriminal,catl,pv,ar);

    }

}

void updateGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    vertex*pv = headAdj;
    vertex*pp = headAdj;
    vertex*xx;
    edge*ar;
    edge*qq;
    int id;
    int id2;

    printf("\nSelect the attacking country. ");
    id = chooseNacionality(treeRoot, LtCriminal, catl)->ID;
    fflush(stdin);
    while(pp!=NULL){
        if (pp->country->ID == id){
            if (pp->ad == NULL){
                printf("\n*This country has not carried out attacks*");
                sleep(2);
                updateGraph(treeRoot,LtCriminal,catl);

            }
            break;
        }
        pp = pp->next;
    }
    system("cls");
    printf("\nSelect the Attacked country. ");
    id2 = chooseNacionality(treeRoot, LtCriminal, catl)->ID;
    pp = headAdj;
    while(pp!=NULL){
        if (pp->country->ID == id){
            qq = pp->ad;
            while(qq!=NULL){
                if(qq->vrt->country->ID == id2){
                    break;
                }
                qq = qq->next;
            }
        }
        pp=pp->next;
    }
    if (qq == NULL){
        printf("\n*The attacker has not hit this country*");
        sleep(2);
        updateGraph(treeRoot,LtCriminal,catl);
    }

    system("cls");

    while (pv!=NULL){
        if (pv->country->ID == id){
            break;
        }
        pv = pv->next;
    }
    ar = pv->ad;
    while(ar!=NULL){
        if (ar->vrt->country->ID == id2){
            modifyGraph(treeRoot,LtCriminal,catl,pv,ar);
        }
        ar = ar->next;
    }
}


///| | | | | | | | | | CYBERATTACK TYPE METHODS | | | | | | | |

cyberAttackTypeList *newListcatl(void)
{
    cyberAttackTypeList *catl;
    catl = (cyberAttackTypeList *)malloc(sizeof(cyberAttackTypeList));
    catl->first = NULL;
    return catl;
}

cyberAttackType *createCyberAttackType()
{
    cyberAttackType *novus;
    char *specifications[100];
    const char *src;
    novus = (cyberAttackType *)malloc(sizeof(cyberAttackType));
    novus->next = NULL;

    printf("Code:\n");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    novus->code = mystrcpy(dst, src);

    printf("Name:\n");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst1 = malloc(sizeof(char) * (strlen(src) + 1));
    novus->name = mystrcpy(dst1, src);

    printf("Description:\n");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst2 = malloc(sizeof(char) * (strlen(src) + 1));
    novus->description = mystrcpy(dst2, src);

    printf("Channels:\n");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
    novus->channels = mystrcpy(dst3, src);

    return novus;
}

void addCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    cyberAttackType *n, *aux;
    cyberAttackType *novus = createCyberAttackType();

    if (catl->first == NULL)
    {
        catl->first = novus;
    }
    else
    {
        n = catl->first;
        while (n != NULL)
        {
            aux = n;
            n = n->next;
        }
        aux->next = novus;
    }
    system("cls");
    printf("Data added.");
    sleep(1);
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
}

void showCyberAttackTypes(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl)
{
    system("cls");
    if (catl->first == NULL)
    {
        printf("\nNo cyberattack types to show.\n");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
    }
    cyberAttackType *aux;
    int n = 1;
    printf("Cyberattack types:\n");
    for (aux = catl->first; aux != NULL; aux = aux->next)
    {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("%i.\n", n);
        printf(" Name: %s\n", aux->name);
        printf(" Code: %s\n", aux->code);
        printf(" Description: %s\n", aux->description);
        printf(" Channels: %s\n", aux->channels);
        n++;
    }
    char nothing[10];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
}

void showCyberAttackTypesWithCodes(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl)
{
    cyberAttackType *aux;
    int n = 1;
    for (aux = catl->first; aux != NULL; aux = aux->next)
    {
        printf("%i.%s:%s\n", n, aux->code, aux->name);
        n++;
    }
}

void modifyType(treeNode *treeRoot, char *code, listCriminal *LtCriminal, const cyberAttackTypeList *catl, cyberAttackType *aux)
{
    system("cls");
    printf("\nCODE: %s\n", aux->code);
    printf("-------------------------\n");
    char *specifications[100];
    const char *src;
    int x;
    int option;

    printf("Number to modify \n1.Code\n2.Name\n3.Description\n4.Channels\n5.Back\n");
    fflush(stdin);
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        system("cls");
        printf("Type new code:\n");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dsta = malloc(sizeof(char) * (strlen(src) + 1));
        aux->code = mystrcpy(dsta, src);
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
        break;

    case 2:
        system("cls");
        printf("Type new name:\n");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dstb = malloc(sizeof(char) * (strlen(src) + 1));
        aux->name = mystrcpy(dstb, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
        break;
    case 3:
        system("cls");
        printf("Type new description:\n");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dstc = malloc(sizeof(char) * (strlen(src) + 1));
        aux->description = mystrcpy(dstc, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
        break;
    case 4:
        system("cls");
        printf("Type new channels:\n");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dstd = malloc(sizeof(char) * (strlen(src) + 1));
        aux->channels = mystrcpy(dstd, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
        break;
    case 5:
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
        break;
    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
    }
}

void updatecyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl)
{
    system("cls");
    cyberAttackType *aux;
    int status = 0;
    char code[100];
    printf("\nCyberattack type code to modify:\n");
    fflush(stdin);
    scanf("%s", code);

    for (aux = catl->first; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->code, code) == 0)
        {
            status++;
            modifyType(treeRoot, code, LtCriminal, catl, aux);
        }
    }

    if (status == 0)
    {
        printf("\nCyberttack type not registered.");
        sleep(3);
        modifyType(treeRoot, code, LtCriminal, catl, aux);
    }
}

void deleteCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    if (catl->first == NULL)
    {
        printf("\nNo cyberattack types registered.\n");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
    }
    cyberAttackType *aux;
    int n = 0;
    char *typeToDelete[100];
    printf("Cyberattack type code to delete: \n");
    fflush(stdin);
    gets(typeToDelete);
    cyberAttackType *aux2 = catl->first;

    for (aux = catl->first; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->code, typeToDelete) == 0)
        {
            if (n > 1)
            {
                aux2 = aux2->next;
            }
            if (aux == aux2)
            {
                catl->first = aux2->next;
                free(aux);
                free(aux2);
                printf("\nCyberattack type erased.\n");
                sleep(1);
                cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
            }
            aux2->next = aux->next;
            free(aux);
            printf("\nCyberattack type erased.\n");
            sleep(1);
            cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
        }
        n++;
    }
    printf("\nCyberattack type not registered.");
    sleep(1);
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl);
}

cyberAttackType *chooseCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (catl->first == NULL)
    {
        printf("No cyber attacks types found.");
        mainMenu(treeRoot, LtCriminal, catl);
    }
    else
    {
        char typeID[100];
        cyberAttackType *aux;
        int status = 0;

        printf("Available types:");
        printf("\n");
        showCyberAttackTypesWithCodes(treeRoot, LtCriminal, catl);

        printf("\nSelected type:");
        printf("\n");
        fflush(stdin);
        scanf("%s", &typeID);


        for (aux = catl->first; aux != NULL; aux = aux->next)
        {
            if (strcmp(aux->code, typeID) == 0)
            {
                status++;
                aux->counter++;
                return aux;
            }
        }

        if (status == 0)
        {
            printf("\nInvalid input.");
            chooseCyberAttackType(treeRoot, LtCriminal, catl);
        }
    }
}

///| | | | | | | | | | | CYBER CRIMINAL METHODS | | | | | | | | | | |

cyberCriminal *chooseCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (LtCriminal->head == NULL)
    {
        printf("No cybercriminals found.");
        mainMenu(treeRoot, LtCriminal, catl);
    }
    else
    {
        char criminalID[100];
        cyberCriminal *aux;
        int status = 0;

        printf("Available criminals:");
        showCriminalsWithOrganization(treeRoot, LtCriminal, catl);

        printf("\nSelected criminal:");
        fflush(stdin);
        scanf("%s", &criminalID);


        for (aux = LtCriminal->head; aux != NULL; aux = aux->next)
        {
            if (strcmp(aux->ID, criminalID) == 0)
            {
                status++;
                aux->counter++;
                return aux;
            }
        }

        if (status == 0)
        {
            printf("\nInvalid input.");
            chooseCyberCriminal(treeRoot, LtCriminal, catl);
        }
    }

}

listCriminal *newListCriminal(void)
{
    listCriminal *LtCriminal;
    LtCriminal = (listCriminal *)malloc(sizeof(listCriminal));
    LtCriminal->head = NULL;
    return LtCriminal;
}

cyberCriminal *createCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    cyberCriminal *novus;
    char *specifications[100];
    const char *src;
    novus = (cyberCriminal *)malloc(sizeof(cyberCriminal));
    novus->next = NULL;

    system("cls");
    printf("[Add Criminal]\n");

    printf("ID: ");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    novus->ID = mystrcpy(dst, src);

    printf("Organization: ");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst5 = malloc(sizeof(char) * (strlen(src) + 1));
    novus->organization = mystrcpy(dst5, src);

    printf("Known attacks: ");
    fflush(stdin);
    gets(specifications);
    src = specifications;
    char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
    novus->knownAttacks = mystrcpy(dst3, src);

    novus->nacionality = chooseNacionality(treeRoot, LtCriminal, catl);

    novus->deletable = 0;

    return novus;
}

void addCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("Register countries to add a cyber criminal");
        sleep(3);
        system("cls");
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
    }

    cyberCriminal *n, *aux;
    cyberCriminal *novus = createCyberCriminal(treeRoot, LtCriminal, catl);

    if (LtCriminal->head == NULL)
    {
        LtCriminal->head = novus;
    }
    else
    {
        n = LtCriminal->head;
        while (n != NULL)
        {
            aux = n;
            n = n->next;
        }
        aux->next = novus;
    }

    system("cls");
    printf("Criminal added successfully.");
    sleep(1);
    fflush(stdin);
    cyberCriminalsMenu(treeRoot, LtCriminal, catl);
}

void deleteCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
    }

    cyberCriminal *aux;
    cyberCriminal *aux2 = LtCriminal->head;
    int n = 0;
    const char *src;

    char idCriminal[100];
    printf("Criminal's ID: ");
    fflush(stdin);
    gets(idCriminal);

    for (aux = LtCriminal->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->ID, idCriminal) == 0)
        {
            if (aux->deletable == 0)
            {
                if (n > 1)
                {
                    aux2 = aux2->next;
                }
                if (aux == aux2)
                {
                    LtCriminal->head = aux2->next;
                    free(aux);
                    free(aux2);
                    printf("\nCyber criminal erased.\n");
                    sleep(1);
                    cyberCriminalsMenu(treeRoot, LtCriminal, catl);
                }
                aux2->next = aux->next;
                free(aux);
                printf("\nCyber criminal erased.\n");
                sleep(1);
                cyberCriminalsMenu(treeRoot, LtCriminal, catl);
            }
            else
            {
                system("cls");
                printf("Error: the country is being used");
                sleep(1);
                cyberCriminalsMenu(treeRoot, LtCriminal, catl);
            }
        }
        n++;
    }
    system("cls");
    printf("ID  not registered.");
    sleep(1);
    cyberCriminalsMenu(treeRoot, LtCriminal, catl);
}

void showCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
    }

    cyberCriminal *i;
    int n = 1;
    for (i = LtCriminal->head; i != NULL; i = i->next)
    {
        printf("\nID:%s", i->ID);
        printf("\nOrganization:%s", i->organization);
        printf("\nNacionality:%s", i->nacionality->name);
        printf("\nKnown Attacks:%s", i->knownAttacks);
        n++;
    }

    char nothing[10];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    cyberCriminalsMenu(treeRoot, LtCriminal, catl);
}

void showCriminalsWithOrganization(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    cyberCriminal *i;
    int n = 1;
    for (i = LtCriminal->head; i != NULL; i = i->next)
    {
        printf("\nID:%s", i->ID);
        printf("\nOrganization:%s", i->organization);
        n++;
    }
}

void modifyCyberCriminal(treeNode *treeRoot, char *idCyberCriminal, listCriminal *LtCriminal, const cyberAttackTypeList *catl, cyberCriminal *aux)
{
    system("cls");
    printf("\ID: %s\n", aux->ID);
    printf("-------------------------\n");

    char *specifications[100];
    const char *src;
    int option;

    printf("Number to modify \n1.ID\n2.Nacionality\n3.Organization\n4.Known Attacks\n5.Back\n");
    fflush(stdin);
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        system("cls");
        printf("New ID: ");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dst = malloc(sizeof(char) * (strlen(src) + 1));
        aux->ID = mystrcpy(dst, src);
        system("cls");
        printf("\nID updated\n");
        sleep(1);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
        break;

    case 2:
        system("cls");
        printf("New nacionality: ");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dst4 = malloc(sizeof(char) * (strlen(src) + 1));
        aux->nacionality = mystrcpy(dst4, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
        break;
    case 3:
        system("cls");
        printf("New organization:");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dst5 = malloc(sizeof(char) * (strlen(src) + 1));
        aux->organization = mystrcpy(dst5, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
        break;

    case 4:
        system("cls");
        printf("New known attacks: ");
        fflush(stdin);
        gets(specifications);
        src = specifications;
        char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
        aux->knownAttacks = mystrcpy(dst3, src);
        system("cls");
        printf("\nData updated.\n");
        sleep(1);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
        break;

    case 5:
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
        break;

    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
    }
}

void updateCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
    }

    system("cls");
    cyberCriminal *aux;
    int status = 0;
    char idCyberCriminal[100];

    printf("\nCyber Criminal ID to modify:\n");
    fflush(stdin);
    scanf("%s", idCyberCriminal);

    for (aux = LtCriminal->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->ID, idCyberCriminal) == 0)
        {
            status++;
            modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux);
        }
    }

    if (status == 0)
    {
        printf("\nID not registered.");
        sleep(3);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl);
    }
}

///| | | | | | | | | | | COUNTRY METHODS | | | | | | | | | | |

country *chooseNacionality(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (treeRoot == NULL)
    {
        printf("No Countries found.");
        mainMenu(treeRoot, LtCriminal, catl);
    }
    else
    {
        printf("Available countries:\n");
        inOrderOnlyKeys(treeRoot);
        printf("\n\nSelected country:");
        int countryKey;
        fflush(stdin);
        scanf("%d", &countryKey);

        if (checkCountry(treeRoot, countryKey) == -1)
        {
            printf("Invalid Input.");
            sleep(1);
            chooseNacionality(treeRoot, LtCriminal, catl);
        }
        else
        {
            findCountry(treeRoot, countryKey)->deletable = 1;
            return findCountry(treeRoot, countryKey);
        }
    }
}

country *findCountry(treeNode *root, int key)
{
    if (key < root->key)
    {
        return findCountry(root->left, key);
    }
    else if (key > root->key)
    {
        return findCountry(root->right, key);
    }
    else
    {
        return root->country;
    }
}

int checkCountry(treeNode *root, int key)
{
    if (key < root->key)
    {
        return checkCountry(root->left, key);
    }
    else if (key > root->key)
    {
        return checkCountry(root->right, key);
    }
    else
    {
        return root->country->ID;
    }
    return -1;
}

void showCountry(treeNode *treeNode)
{
    printf("\nID:%d", treeNode->country->ID);
    printf("\nName:%s", treeNode->country->name);
    printf("\nPopulation:%s", treeNode->country->population);
    printf("\nContinent:%s\n", treeNode->country->continent);
}

void showCountryWithKey(treeNode *treeNode)
{
    printf("\n%d: %s", treeNode->country->ID, treeNode->country->name);
}

void addCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    system("cls");
    printf("[Add Country]");
    const char *src;
    country *newCountry;
    newCountry = (country *)malloc(sizeof(country));
    insertVertex(newCountry);

    int ID;
    printf("\nID:");
    scanf("%d", &ID);
    fflush(stdin);
    newCountry->ID = ID;

    char name[100];
    printf("Name:");
    fflush(stdin);
    gets(name);
    src = name;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    newCountry->name = mystrcpy(dst, src);

    char population[100];
    printf("Population:");
    fflush(stdin);
    gets(population);
    src = population;
    char *dst2 = malloc(sizeof(char) * (strlen(src) + 1));
    newCountry->population = mystrcpy(dst2, src);

    char continent[100];
    printf("Continent of origin:");
    fflush(stdin);
    gets(continent);
    src = continent;
    char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
    newCountry->continent = mystrcpy(dst3, src);

    newCountry->deletable = 0;

    treeRoot = insert(treeRoot, newCountry->ID, newCountry);

    system("cls");
    printf("Country added successfully.");
    sleep(1);
    countriesMenu(treeRoot, LtCriminal, catl);
}

void deleteCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to delete.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal, catl);
    }
    else
    {
        system("cls");
        printf("[Delete Country]\n");

        int key;
        printf("Country's key:");
        scanf("%d", &key);

        if (search(treeRoot, key) == NULL)
        {
            system("cls");
            printf("The country code wasn't found in the records.");
            sleep(2);
            countriesMenu(treeRoot, LtCriminal, catl);
        }
        else
        {
            if (search(treeRoot, key)->country->deletable == 1)
            {
                system("cls");
                printf("Error: the country is being used");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl);
            }

            treeRoot = deleteNode(treeRoot, key);
            system("cls");
            printf("Country deleted successfully.");
            sleep(1);
            system("cls");
            countriesMenu(treeRoot, LtCriminal, catl);
        }
    }
}

void updateCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to update.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal, catl);
    }
    else
    {
        system("cls");
        printf("[Update Country]\n");
        const char *src;
        char *src2;
        char *auxChanges[100];
        char *show;
        int key;
        printf("Country's key:");
        scanf("%d", &key);

        if (search(treeRoot, key) == NULL)
        {
            system("cls");
            printf("The country code wasn't found in the records.");
            sleep(2);
            countriesMenu(treeRoot, LtCriminal, catl);
        }
        else
        {
            country *s;
            s = search(treeRoot, key)->country;
            system("cls");
            printf("Country:%s\n", s->name);
            printf("-------------------\n");
            int decision;
            printf("Property to change:\n1.ID\n2.Name\n3.Population\n4.Continent\n");
            scanf("%d", &decision);
            country *auxCountry;
            auxCountry = search(treeRoot, key)->country;

            switch (decision)
            {
            case 1:
                system("cls");
                int IDdecision;
                printf("New ID:");
                scanf("%d", &IDdecision);
                auxCountry->ID = IDdecision;
                system("cls");
                printf("Changes saved successfully.");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl);
            case 2:
                system("cls");
                printf("New name:");
                fflush(stdin);
                gets(auxChanges);
                src = auxChanges;
                char *dstc = malloc(sizeof(char) * (strlen(src) + 1));
                auxCountry->name = mystrcpy(dstc, src);
                system("cls");
                printf("Changes saved successfully.");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl);
            case 3:
                system("cls");
                printf("New population:");
                fflush(stdin);
                gets(auxChanges);
                src = auxChanges;
                char *dst2 = malloc(sizeof(char) * (strlen(src) + 1));
                auxCountry->population = mystrcpy(dst2, src);
                system("cls");
                printf("Changes saved successfully.");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl);
            case 4:
                system("cls");
                printf("New continent:");
                fflush(stdin);
                gets(auxChanges);
                src = auxChanges;
                char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
                auxCountry->population = mystrcpy(dst3, src);
                system("cls");
                printf("Changes saved successfully.");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl);
            default:
                system("cls");
                printf("Invalid Input.");
                sleep(1);
                updateCountry(treeRoot, LtCriminal, catl);
                break;
            }
        }
    }
}

/// | | | | | | | | | | | | | | Main | | | | | | | | | | |  | |
int main()
{
    listCriminal *LtCriminal;
    LtCriminal = newListCriminal();

    cyberAttackTypeList *catl;
    catl = newListcatl();

    struct treeNode *root = NULL;
    mainMenu(root, LtCriminal, catl);
    return -1;
}
