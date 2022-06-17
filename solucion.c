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
typedef struct Pila Pila;
typedef struct nodePila nodePila;

// Instances
country *chooseNacionality(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);
country *chooseNacionalityCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);
country *findCountry(treeNode *root, int key);
cyberAttackType *chooseCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);
cyberAttackType *chooseCyberAttackTypeCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);
cyberCriminal *chooseCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);
cyberCriminal *chooseCyberCriminalCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P);

int totalAttacks = 0;

// Struct's bodies
struct cyberAttackType
{
    char *code;
    char *name;
    char *description;
    char *channels;
    int *counter;
    int deletable;
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
    int *counter;
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
    int *ant;
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
    country *country;
    AdjList *next;
};

struct nodePila
{
    char *segurityMessage;
    nodePila *next;
};

struct Pila
{
    nodePila *head;
    int size;
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

void mainMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
        cyberAttackMenu(treeRoot, LtCriminal, catl,P);
        break;

    case 2:
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);

    case 3:
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        countriesMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        statisticsMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void securityMessageMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    // HEADER
    system("cls");
    int option;
    printf("[Security Message]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Show encrypted messages\n2.Show decrypted messages\n3.Delete message\n4.Go back\n5.Generate Message\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        showEncryptedMessages(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        showDecryptedMessages(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        popPila(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        generateSecurityMessage(treeRoot, LtCriminal, catl, P, "Roma", "Masivo", "Angels", 198, 1200);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void cyberAttackMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    // HEADER
    system("cls");
    int option;
    printf("[Cyber Attacks]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attack Simulation\n2.Manual registration\n3.Cyber Attack Routes\n4.Delete a Cyber Attack\n5.Update a Cyber Attack\n6.Show graph of Cyber Attacks\n7.Security Message\n8.Go back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        printf("Cyber Attack Simulation");
        break;

    case 2:
        createEdge(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        system("cls");
        dijkstra(treeRoot, LtCriminal, catl, P);
        char nothingd[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothingd);
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        updateGraph(treeRoot, LtCriminal, catl, P);
        break;

    case 6:
        showGraph(treeRoot, LtCriminal, catl, P);
        break;

    case 7:
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
        break;
    case 8:
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void cyberAttackTypesMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
        addCyberAttackType(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        system("cls");
        deleteCyberAttackType(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        system("cls");
        showCyberAttackTypes(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        system("cls");
        updatecyberAttackType(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        system("cls");
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void cyberCriminalsMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
        addCriminal(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        system("cls");
        deleteCriminal(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        system("cls");
        showCriminal(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        system("cls");
        updateCriminal(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        system("cls");
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void countriesMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
        addCountry(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        deleteCountry(treeRoot, LtCriminal, catl, P);
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
        countriesMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        updateCountry(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        countriesMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void statisticsMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    // HEADER
    system("cls");
    int option;
    printf("[Statistics]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Total Cyberattacks done\n2.Total Cyberattacks realized by country\n3.Total Cyberattacks sent and received by type\n4.Total Cyberattacks done by cyber criminals\n5.Top 3 countries with the most received attacks\n6.Top 3 cybercriminals with the highest amount of attacks\n7.Go back\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        statsTotalCyberAttacksDone(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        statsTotalCyberAttacksSentReceivedByCountry(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        statsTotalCyberAttacksSentReceivedByType(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        statsTotalCyberAttacksSentByCriminal(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        printf("Top 3 countries with the most received attacks");
        break;
    case 6:
        topThreeCriminalsWithMostAttacksSent(treeRoot, LtCriminal, catl, P);
        break;
    case 7:
        mainMenu(treeRoot, LtCriminal, catl, P);
        break;
    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
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

void inOrderAscended(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->right);
        showCountryAscended(root);
        inOrder(root->left);
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

void inOrderForStats(struct treeNode *root)
{
    if (root != NULL)
    {
        inOrderForStats(root->left);
        showCountryForStats(root);
        inOrderForStats(root->right);
    }
}

///| | | | | | | | | | | SECURITY  | | | |  | | | | | | | | | | |
// Security Message
Pila *newPila(void)
{
    Pila *P;
    P = (Pila *)malloc(sizeof(Pila));
    P->head = NULL;
    P->size = 0;
    return P;
}

// Security Message
nodePila *createPilaNode(char *message)
{
    nodePila *new;
    new = (nodePila *)malloc(sizeof(nodePila));
    new->next = NULL;
    const char *src;

    src = message;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    new->segurityMessage = mystrcpy(dst, src);

    return new;
}

// Security Message
void pushPila(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P, char *message)
{
    nodePila *new = createPilaNode(message);

    new->next = P->head;
    P->head = new;
    P->size = P->size++;
    system("cls");
    printf("\nMessage registred\n");
    sleep(1);
}

// Security Message
void popPila(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (P->head == NULL)
    {
        system("cls");
        printf("\nThere are no registered messages.");
        fflush(stdin);
        sleep(1);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        nodePila *delete = P->head;
        int num = 1;

        P->head = P->head->next;
        P->size = P->size--;
        system("cls");
        printf("The deleted message is: \n");
        decryptMessage(delete->segurityMessage, num);
        sleep(3);
        free(delete);
        system("cls");
        printf("\nDeleted message.");
        fflush(stdin);
        sleep(1);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
}

// Security Message
void showEncryptedMessages(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");

    if (P->head == NULL)
    {
        system("cls");
        printf("\nThere are no registered messages.");
        fflush(stdin);
        sleep(1);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        nodePila *i;
        int num = 1;
        printf("RECORDED MESSAGES");
        printf("\n----------\n");

        for (i = P->head; i != NULL; i = i->next)
        {
            printf("%d. %s \n", num, i->segurityMessage);
            num++;
        }

        printf("\n");
        char nothing[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
}

// Security Message
void showDecryptedMessages(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");

    if (P->head == NULL)
    {
        system("cls");
        printf("\nThere are no registered messages.");
        fflush(stdin);
        sleep(1);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        nodePila *i;
        int num = 1;
        printf("RECORDED MESSAGES");
        printf("\n----------\n");

        for (i = P->head; i != NULL; i = i->next)
        {
            decryptMessage(i->segurityMessage, num);
            num++;
        }

        char nothing[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        securityMessageMenu(treeRoot, LtCriminal, catl, P);
    }
}

// Security Message
void encryptMessage(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P, char *texto)
{
    char ch;
    int i;
    int key = 5;

    for (i = 0; texto[i] != '\0'; ++i)
    {
        ch = texto[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            texto[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            texto[i] = ch;
        }
    }

    pushPila(treeRoot, LtCriminal, catl, P, texto);
}

// Security Message
void decryptMessage(char *texto1, int num)
{
    char ch;
    int i;
    int key = 5;

    for (i = 0; texto1[i] != '\0'; ++i)
    {
        ch = texto1[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            texto1[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            texto1[i] = ch;
        }
    }

    printf("%d. %s \n", num, texto1);
}

// Security Message
void generateSecurityMessage(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P, char *destinationCountry, char *typeCyberAttack, char *organizationCyberCriminal, int intAffectedData, int intAttackDuration)
{
    char segurityMessage[150];
    char segurityMessage2[150];
    char segurityMessage3[150];
    char segurityMessage4[150];
    char segurityMessage5[150];

    char attackDuration[100];
    itoa(intAttackDuration, attackDuration, 10);

    char affectedData[100];
    itoa(intAffectedData, affectedData, 10);

    strcat(strcpy(segurityMessage, "The country of "), destinationCountry);
    strcat(segurityMessage, " was attacked by ");

    strcat(strcpy(segurityMessage2, segurityMessage), organizationCyberCriminal);
    strcat(segurityMessage2, " with the ");

    strcat(strcpy(segurityMessage3, segurityMessage2), typeCyberAttack);
    strcat(segurityMessage3, " cyber attack for ");

    strcat(strcpy(segurityMessage4, segurityMessage3), attackDuration);
    strcat(segurityMessage4, " seconds and ");

    strcat(strcpy(segurityMessage5, segurityMessage4), affectedData);
    strcat(segurityMessage5, "Gb were attacked in the process.");

    encryptMessage(treeRoot, LtCriminal, catl, P, segurityMessage5);
}

// | | | | | | | | | || | GRAPH | | | | | | | | | | | | | | |

void insertVertex(country *countryV)
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

void createEdge(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
    ini = chooseNacionalityCounter(treeRoot, LtCriminal, catl, P)->ID;

    printf("\nSelect the Attacked country. ");
    fin = chooseNacionalityCounter(treeRoot, LtCriminal, catl, P)->ID;

    printf("\nDuration of attack in seconds: ");
    scanf("%i", &novus->seconds);
    printf("\nAmount of gygabites affected: ");
    scanf("%i", &novus->gb);
    printf("\n");
    novus->attackType = chooseCyberAttackTypeCounter(treeRoot, LtCriminal, catl, P)->name;

    cyberAttackType *gg = catl->first;
    for (gg = catl->first; gg != NULL; gg = gg->next)
    {
        if (strcmp(novus->attackType, gg->name) == 0)
        {
            gg->deletable = 0;
        }
    }

    printf("\n");
    novus->cyberCriminal = chooseCyberCriminalCounter(treeRoot, LtCriminal, catl, P)->organization;
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
            totalAttacks++;
            system("cls");
            printf("\nAttack registered successfully\n");
            sleep(1);
            cyberAttackMenu(treeRoot, LtCriminal, catl, P);
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
        while (a->next != NULL)
        {
            a = a->next;
        }
        novus->vrt = aux2;
        a->next = novus;
    }
}

void showGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    vertex *aux = headAdj;
    edge *ed;
    printf("GRAPH\n");
    printf("----------\n");
    while (aux != NULL)
    {
        printf("%s--> ", aux->country->name);
        if (aux->ad != NULL)
        {
            ed = aux->ad;
            while (ed != NULL)
            {
                printf("%s", ed->vrt->country->name);
                printf("[%s,", ed->attackType);
                printf(" %s,", ed->cyberCriminal);
                printf(" %igb,", ed->gb);
                printf(" %is]  ", ed->seconds);
                ed = ed->next;
            }
        }
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
    char nothing[100];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    cyberAttackMenu(treeRoot, LtCriminal, catl, P);
}

void modifyGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, vertex *pv, edge *ar, Pila *P)
{
    int option;
    int x;
    vertex *y = headAdj;
    system("cls");
    printf("%s --> %s\n", pv->country->name, ar->vrt->country->name);
    printf("---------------\n");
    printf("1. Attack duration: %i seconds\n", ar->seconds);
    printf("2. Gb affected: %i\n", ar->gb);
    printf("3. Attack type: %s\n", ar->attackType);
    printf("4. Criminal: %s\n", ar->cyberCriminal);
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
        scanf("%d", &x);
        ar->seconds = x;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        break;

    case 2:
        system("cls");
        printf("Enter Gb:\n");
        scanf("%d", &x);
        ar->gb = x;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        break;

    case 3:
        system("cls");
        ar->attackType = chooseCyberAttackType(treeRoot, LtCriminal, catl, P)->name;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        break;

    case 4:
        system("cls");
        ar->cyberCriminal = chooseCyberCriminal(treeRoot, LtCriminal, catl, P)->organization;
        system("cls");
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        break;

    case 5:
        system("cls");
        printf("\nSelect the new Attacked country. ");
        x = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
        while (y != NULL)
        {
            if (y->country->ID == x)
            {
                break;
            }
            y = y->next;
        }
        ar->vrt = y;
        printf("\nData updated\n");
        sleep(1);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        break;

    case 6:
        system("cls");
        vertex *r = pv;
        vertex *t = headAdj;
        int id;
        vertex *q;
        edge *x = ar;
        edge *y;
        edge *m;

        printf("\nSelect the new Attacking country. ");
        id = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;

        if (r->ad == x)
        {
            r->ad = x->next;
            x->next = NULL;
            while (t != NULL)
            {
                if (t->country->ID == id)
                {
                    q = t;
                    break;
                }
                t = t->next;
            }
        }

        else
        {
            y = r->ad;
            while (y->next != x)
            {
                y = y->next;
            }
            y->next = x->next;
            x->next = NULL;
            fflush(stdin);
            while (t != NULL)
            {
                if (t->country->ID == id)
                {
                    q = t;
                    break;
                }
                t = t->next;
            }
        }

        if (q->ad == NULL)
        {
            q->ad = x;
        }
        else
        {
            m = q->ad;
            while (m->next != NULL)
            {
                m = m->next;
            }
            m->next = x;
        }

        printf("\nData updated\n");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 7:
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
    }
}

void updateGraph(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    vertex *pv = headAdj;
    vertex *pp = headAdj;
    vertex *xx;
    edge *ar;
    edge *qq;
    int id;
    int id2;

    printf("\nSelect the attacking country. ");
    id = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
    fflush(stdin);
    while (pp != NULL)
    {
        if (pp->country->ID == id)
        {
            if (pp->ad == NULL)
            {
                printf("\n*This country has not carried out attacks*");
                sleep(2);
                cyberAttackMenu(treeRoot, LtCriminal, catl, P);
            }
            break;
        }
        pp = pp->next;
    }
    system("cls");
    printf("\nSelect the Attacked country. ");
    id2 = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
    pp = headAdj;
    while (pp != NULL)
    {
        if (pp->country->ID == id)
        {
            qq = pp->ad;
            while (qq != NULL)
            {
                if (qq->vrt->country->ID == id2)
                {
                    break;
                }
                qq = qq->next;
            }
        }
        pp = pp->next;
    }
    if (qq == NULL)
    {
        printf("\n*The attacker has not hit this country*");
        sleep(2);
        updateGraph(treeRoot, LtCriminal, catl, P);
    }

    system("cls");

    while (pv != NULL)
    {
        if (pv->country->ID == id)
        {
            break;
        }
        pv = pv->next;
    }
    ar = pv->ad;
    while (ar != NULL)
    {
        if (ar->vrt->country->ID == id2)
        {
            modifyGraph(treeRoot, LtCriminal, catl, pv, ar, P);
        }
        ar = ar->next;
    }
}

void deleteAttackMenu(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    int option;
    printf("[Cyber Attacks]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Delete one attack carried out by a country\n2.Delete every attack carried out by a country\n3.Delete all attacks made against a country\n4.Delete every attack\n5.Go back\n");
    scanf("%i", &option);
    // END HEADER
    vertex *v = headAdj;
    vertex *w = headAdj;
    edge *e;
    edge *f;
    int id;
    int id2;

    switch (option)
    {
    case 1:
        system("cls"); // v es el puntero al país que ataca
        printf("\nSelect the attacking country. ");
        id = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
        while (v != NULL)
        {
            if (v->country->ID == id)
            {
                break;
            }
            v = v->next;
        }
        if (v->ad == NULL)
        {
            printf("\n*This country has not carried out attacks*");
            sleep(2);
            deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        }

        printf("\nSelect the Attacked country. ");
        id2 = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;

        while (w != NULL)
        { // w es el puntero al pais atacado
            if (w->country->ID == id)
            {
                e = w->ad;
                while (e != NULL)
                {
                    if (e->vrt->country->ID == id2)
                    { // e es el puntero a la arista que se debe eliminar
                        break;
                    }
                    e = e->next;
                }
            }
            w = w->next;
        }
        if (e == NULL)
        {
            printf("\n*The attacker has not hit this country*");
            sleep(2);
            deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        }

        if (v->ad == e)
        {
            v->ad = e->next;
            e->next = NULL;
            e->vrt = NULL;
            free(e);
            printf("\nAttack deleted");
            sleep(1);
            deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        }

        f = v->ad;
        while (f->next != e)
        {
            f = f->next;
        }

        f->next = e->next;
        e->next == NULL;
        e->vrt == NULL;
        free(e);
        printf("\nAttack deleted");
        totalAttacks--;
        sleep(1);
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 2:
        system("cls"); // v es el puntero al pais que ataca
        printf("\nSelect the attacking country. ");
        id = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
        while (v != NULL)
        {
            if (v->country->ID == id)
            {
                break;
            }
            v = v->next;
        }
        if (v->ad == NULL)
        {
            printf("\n*This country has not carried out attacks*");
            sleep(2);
            deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        }
        else
        {
            e = v->ad;
            while (e != NULL)
            {
                e->vrt = NULL;
                e = e->next;
                totalAttacks--;
            }
            e = v->ad;
            free(e);
        }

        v->ad = NULL;
        printf("\nAll attacks deleted");
        sleep(1);
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 3:
        system("cls");
        printf("\nSelect the attacked country. ");
        id = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;

        while (v != NULL)
        {
            e = v->ad;
            int n = 1;
            while (e != NULL)
            {
                f = e->next;
                if (e->vrt->country->ID == id && n == 1)
                {
                    while (n == 1)
                    {
                        e->vrt = NULL;
                        v->ad = e->next;
                        e->next = NULL;
                        free(e);
                        e = f;
                        if (f == NULL)
                        {
                            break;
                        }
                        f = f->next;
                        if (e->vrt->country->ID != id)
                        {
                            n++;
                        }
                    }
                }
                n++;
                if (f == NULL)
                {
                    break;
                }
                while (f->vrt->country->ID != id)
                {
                    e = f;
                    f = f->next;
                    if (f == NULL)
                    {
                        break;
                    }
                }
                if (f == NULL)
                {
                    break;
                }
                if (f->vrt->country->ID == id)
                {
                    f->vrt = NULL;
                    e->next = f->next;
                    f->next = NULL;
                    free(f);
                    totalAttacks--;
                    f = e->next;
                    if (f == NULL)
                    {
                        break;
                    }
                }
            }
            v = v->next;
        }

        while (w != NULL)
        {
            if (w->country->ID == id)
            {
                break;
            }
            w = w->next;
        }
        printf("\nAll attacks towards %s have been deleted", w->country->name);
        sleep(2);
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 4:
        while (w != NULL)
        {
            e = w->ad;
            w->ad = NULL;
            free(e);
            w = w->next;
        }
        totalAttacks = 0;
        printf("\nAll attacks have been deleted");
        sleep(2);
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    case 5:
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("Invalid Input.");
        sleep(1);
        deleteAttackMenu(treeRoot, LtCriminal, catl, P);
        break;
    }
}

void insertPile(vertex *aux)
{
    AdjList *novus = (AdjList *)malloc(sizeof(AdjList));
    novus->country = aux->country;
    novus->next = NULL;
    if (ini == NULL)
    {
        ini = novus;
        finale = novus;
    }
    else
    {
        novus->next = ini;
        ini = novus;
    }
}

country *desencolar()
{
    AdjList *aux;
    if (ini == NULL)
    {
        return NULL;
    }
    else
    {
        aux = ini;
        ini = ini->next;
        aux->next = NULL;
        if (ini == NULL)
            finale = NULL;
    }
    country *c = aux->country;
    free(aux);
    return c;
}

void reboot()
{
    if (headAdj != NULL)
    {
        vertex *aux = headAdj;
        while (aux != NULL)
        {
            aux->visited = aux->finished = 0;
            aux = aux->next;
        }
    }
}

void dijkstra(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    vertex *aux = headAdj;
    int dep, b;
    printf("Select the country of departure. ");
    dep = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
    printf("\nSelect the country of arrival. ");
    b = chooseNacionality(treeRoot, LtCriminal, catl, P)->ID;
    while (aux != NULL)
    {
        if (aux->country->ID == dep)
        {
            aux->finished = 1;
            aux->amount = 0;
            break;
        }
        aux = aux->next;
    }
    if (aux->ad == NULL)
    {
        printf("This country has not carried out attacks\n");
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
    }
    while (aux != NULL)
    {
        edge *a = aux->ad;
        while (a != NULL)
        {
            if (a->vrt->amount == -1 || (aux->amount + a->seconds) < a->vrt->amount)
            {
                a->vrt->amount = aux->amount + a->seconds;
                a->vrt->ant = aux->country->ID;
            }
            a = a->next;
        }
        aux = headAdj;
        vertex *min = headAdj;
        while (min->ant == 0 || min->finished == 1)
        {
            min = min->next;
        }
        while (aux != NULL)
        {
            if (aux->amount < min->amount && aux->finished == 0 && aux->ant != 0)
            {
                min = aux;
            }
            aux = aux->next;
        }
        aux = min;
        aux->finished = 1;
        if (aux->country->ID == b)
            break;
    }
    while (aux->ant != 0)
    {
        insertPile(aux);
        int temp = aux->ant;
        aux = headAdj;
        while (aux->country->ID != temp)
        {
            aux = aux->next;
        }
    }
    insertPile(aux);
    printf("\nThe shortest path is:\n");
    while (ini != NULL)
    {
        int c = desencolar()->ID;
        printf("-->%i", c);
        vertex *j = headAdj;
        while (j != NULL)
        {
            if (j->country->ID == c)
            {
                printf("[%s]", j->country->name);
                break;
            }
            j = j->next;
        }
    }
    vertex *j = headAdj;
    while (j != NULL)
    {
        if (j->country->ID == b)
        {
            printf(" {%is}", j->amount);
            break;
        }
        j = j->next;
    }
    printf("\n");
    reboot();
}

// Attack Simulation
void cyberAttackSimulation(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL || LtCriminal->head == NULL || catl->first == NULL)
    {
        system("cls");
        printf("It's necessary that there are cybercriminals, countries and type of cyberattacks registered to do the simulation. ");
        sleep(2);
        system("cls");
        cyberAttackMenu(treeRoot, LtCriminal, catl, P);
    }

    int intOriginCountry;
    char *originCountry;

    int intDestinationCountry;
    char *destinationCountry;

    int typeCyberAttack = 1;
    char *nameTypeCyberAttack;

    int idCyberCriminal = 1;
    char *organizationCyberCriminal;

    int affectedData;
    int attackDuration;
    int randomNumber;
    int validation = 0;

    system("cls");
    int numberCyberAttacks;
    printf("\nNumber of cyberattacks that will be done in the simulation: ");
    fflush(stdin);
    scanf("%d", &numberCyberAttacks);

    for (int i = 0; i < numberCyberAttacks; i++)
    {
        // Random number for country of origin
        const char *srcOriginCountry;
        while (validation == 0)
        {
            randomNumber = rand() % (750 + 1);

            if (search(treeRoot, randomNumber) == NULL)
            {
            }
            else
            {
                validation = 1;
                intOriginCountry = randomNumber;

                srcOriginCountry = search(treeRoot, randomNumber)->country->name;
                char *dst1 = malloc(sizeof(char) * (strlen(srcOriginCountry) + 1));
                originCountry = mystrcpy(dst1, srcOriginCountry);
            }
        }

        // Random number for the destination country
        const char *srcDestinationCountry;
        while (validation == 1)
        {
            randomNumber = rand() % (1500 - 750 + 1) + 750;

            if (search(treeRoot, randomNumber) == NULL)
            {
            }
            else
            {
                validation = 2;
                intDestinationCountry = randomNumber;

                srcDestinationCountry = search(treeRoot, randomNumber)->country->name;
                char *dst2 = malloc(sizeof(char) * (strlen(srcDestinationCountry) + 1));
                destinationCountry = mystrcpy(dst2, srcDestinationCountry);
            }
        }

        validation = 0;

        // Random number for the type of cyber attack
        const char *srcCyberAttack;
        cyberAttackType *auxCyberAttack;
        for (auxCyberAttack = catl->first; auxCyberAttack != NULL; auxCyberAttack = auxCyberAttack->next)
        {
            while (validation == 0)
            {
                randomNumber = rand() % (1000 + 1);
                int intCode = atoi(auxCyberAttack->code);

                if (intCode == randomNumber)
                {
                    typeCyberAttack = randomNumber;

                    srcCyberAttack = auxCyberAttack->name;
                    char *dst3 = malloc(sizeof(char) * (strlen(srcCyberAttack) + 1));
                    nameTypeCyberAttack = mystrcpy(dst3, srcCyberAttack);

                    validation = 1;
                }
            }

            if (typeCyberAttack != 1)
            {
                break;
            }
        }

        validation = 0;

        // Random number for cyber criminal
        const char *srcCyberCriminal;
        cyberCriminal *auxCyberCriminal;
        for (auxCyberCriminal = LtCriminal->head; auxCyberCriminal != NULL; auxCyberCriminal = auxCyberCriminal->next)
        {
            while (validation == 0)
            {
                randomNumber = rand();
                int intIdCyberCriminal = atoi(auxCyberCriminal->ID);

                if (intIdCyberCriminal == randomNumber)
                {
                    idCyberCriminal = randomNumber;

                    srcCyberCriminal = auxCyberCriminal->organization;
                    char *dst4 = malloc(sizeof(char) * (strlen(srcCyberCriminal) + 1));
                    organizationCyberCriminal = mystrcpy(dst4, srcCyberCriminal);

                    validation = 1;
                }
            }

            if (idCyberCriminal != 1)
            {
                break;
            }
        }

        affectedData = rand() % (100 - 10 + 1) + 10;
        attackDuration = rand() % (1500 - 5 + 1) + 5;
        printf("\nAttack end");

        recordCyberAttackSimulation(treeRoot, LtCriminal, catl, P, intOriginCountry, intDestinationCountry, nameTypeCyberAttack, organizationCyberCriminal, affectedData, attackDuration, destinationCountry);
    }

    showGraph(treeRoot, LtCriminal, catl, P);
}

// Attack Simulation
void recordCyberAttackSimulation(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P, int originCountry, int destinationCountry, char *typeCyberAttack, char *organizationCyberCriminal, int affectedData, int attackDuration, char *charDestinationCountry)
{
    system("cls");
    printf("\nInsert");

    int ini;
    int fin;
    const char *src;
    edge *novus = (edge *)malloc(sizeof(edge));
    novus->next = NULL;
    vertex *aux;
    vertex *aux2;

    ini = originCountry;
    fin = destinationCountry;

    novus->attackType = typeCyberAttack;
    novus->cyberCriminal = organizationCyberCriminal;
    novus->seconds = attackDuration;
    novus->gb = affectedData;

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
            printf("\nSimulation registered successfully\n");
            sleep(1);
            generateSecurityMessage(treeRoot, LtCriminal, catl, P, charDestinationCountry, typeCyberAttack, organizationCyberCriminal, affectedData, attackDuration);
        }
        aux = aux->next;
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

    novus->deletable = 1;
    novus->counter = 0;

    return novus;
}

void addCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
}

void showCyberAttackTypes(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (catl->first == NULL)
    {
        printf("\nNo cyberattack types to show.\n");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
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
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
}

void showCyberAttackTypesWithCodes(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl, Pila *P)
{
    cyberAttackType *aux;
    int n = 1;
    for (aux = catl->first; aux != NULL; aux = aux->next)
    {
        printf("%i.%s:%s\n", n, aux->code, aux->name);
        n++;
    }
}

void modifyType(treeNode *treeRoot, char *code, listCriminal *LtCriminal, const cyberAttackTypeList *catl, cyberAttackType *aux, Pila *P)
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
        modifyType(treeRoot, code, LtCriminal, catl, aux, P);
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
        modifyType(treeRoot, code, LtCriminal, catl, aux, P);
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
        modifyType(treeRoot, code, LtCriminal, catl, aux, P);
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
        modifyType(treeRoot, code, LtCriminal, catl, aux, P);
        break;
    case 5:
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
        break;
    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyType(treeRoot, code, LtCriminal, catl, aux, P);
    }
}

void updatecyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, const cyberAttackTypeList *catl, Pila *P)
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
            modifyType(treeRoot, code, LtCriminal, catl, aux, P);
        }
    }

    if (status == 0)
    {
        printf("\nCyberttack type not registered.");
        sleep(3);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
    }
}

void deleteCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (catl->first == NULL)
    {
        printf("\nNo cyberattack types registered.\n");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
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
            if (aux->deletable != 1)
            {
                printf("\n*Cyberattack type cannot be erased*");
                sleep(2);
                cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
            }
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
                cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
            }
            aux2->next = aux->next;
            free(aux);
            printf("\nCyberattack type erased.\n");
            sleep(1);
            cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
        }
        n++;
    }
    printf("\nCyberattack type not registered.");
    sleep(1);
    cyberAttackTypesMenu(treeRoot, LtCriminal, catl, P);
}

cyberAttackType *chooseCyberAttackType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (catl->first == NULL)
    {
        printf("No cyber attacks types found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        char typeID[100];
        cyberAttackType *aux;
        int status = 0;

        printf("Available types:");
        printf("\n");
        showCyberAttackTypesWithCodes(treeRoot, LtCriminal, catl, P);

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
            chooseCyberAttackType(treeRoot, LtCriminal, catl, P);
        }
    }
}

cyberAttackType *chooseCyberAttackTypeCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (catl->first == NULL)
    {
        printf("No cyber attacks types found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        char typeID[100];
        cyberAttackType *aux;
        int status = 0;

        printf("Available types:");
        printf("\n");
        showCyberAttackTypesWithCodes(treeRoot, LtCriminal, catl, P);

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
            chooseCyberAttackType(treeRoot, LtCriminal, catl, P);
            chooseCyberAttackType(treeRoot, LtCriminal, catl, P)->counter++;
        }
    }
}

///| | | | | | | | | | | CYBER CRIMINAL METHODS | | | | | | | | | | |

cyberCriminal *chooseCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (LtCriminal->head == NULL)
    {
        printf("No cybercriminals found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        char criminalID[100];
        cyberCriminal *aux;
        int status = 0;

        printf("Available criminals:");
        showCriminalsWithOrganization(treeRoot, LtCriminal, catl, P);

        printf("\n\nSelected criminal:\n");
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
            chooseCyberCriminal(treeRoot, LtCriminal, catl, P);
        }
    }
}

cyberCriminal *chooseCyberCriminalCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (LtCriminal->head == NULL)
    {
        printf("No cybercriminals found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        char criminalID[100];
        cyberCriminal *aux;
        int status = 0;

        printf("Available criminals:");
        showCriminalsWithOrganization(treeRoot, LtCriminal, catl, P);

        printf("\n\nSelected criminal:\n");
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
            chooseCyberCriminal(treeRoot, LtCriminal, catl, P);
            chooseCyberCriminal(treeRoot, LtCriminal, catl, P)->counter++;
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

cyberCriminal *createCyberCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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

    novus->nacionality = chooseNacionality(treeRoot, LtCriminal, catl, P);

    novus->deletable = 0;

    novus->counter = 0;

    return novus;
}

void addCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("Register countries to add a cyber criminal");
        sleep(3);
        system("cls");
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
    }

    cyberCriminal *n, *aux;
    cyberCriminal *novus = createCyberCriminal(treeRoot, LtCriminal, catl, P);

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
    cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
}

void deleteCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
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
                    cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
                }
                aux2->next = aux->next;
                free(aux);
                printf("\nCyber criminal erased.\n");
                sleep(1);
                cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
            }
            else
            {
                system("cls");
                printf("Error: the country is being used");
                sleep(1);
                cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
            }
        }
        n++;
    }
    system("cls");
    printf("ID  not registered.");
    sleep(1);
    cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
}

void showCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
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
    cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
}

void showCriminalsWithOrganization(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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

void showCriminalsForStats(listCriminal *LtCriminal)
{
    cyberCriminal *i;
    int n = 1;
    for (i = LtCriminal->head; i != NULL; i = i->next)
    {
        printf("\nID:%s", i->ID);
        printf("\nOrganization:%s", i->organization);
        printf("\nNumber of Attacks:%s", i->counter);
        n++;
    }
}

void modifyCyberCriminal(treeNode *treeRoot, char *idCyberCriminal, listCriminal *LtCriminal, const cyberAttackTypeList *catl, cyberCriminal *aux, Pila *P)
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
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
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
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
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
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
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
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
        break;

    case 5:
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
        break;

    default:
        system("cls");
        printf("\n\nInvalid input.\n");
        sleep(2);
        modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
    }
}

void updateCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
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
            modifyCyberCriminal(treeRoot, idCyberCriminal, LtCriminal, catl, aux, P);
        }
    }

    if (status == 0)
    {
        printf("\nID not registered.");
        sleep(3);
        cyberCriminalsMenu(treeRoot, LtCriminal, catl, P);
    }
}

///| | | | | | | | | | | COUNTRY METHODS | | | | | | | | | | |

country *chooseNacionality(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL)
    {
        printf("No Countries found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
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
            chooseNacionality(treeRoot, LtCriminal, catl, P);
        }
        else
        {
            findCountry(treeRoot, countryKey)->deletable = 1;
            return findCountry(treeRoot, countryKey);
        }
    }
}

country *chooseNacionalityCounter(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL)
    {
        printf("No Countries found.");
        mainMenu(treeRoot, LtCriminal, catl, P);
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
            chooseNacionality(treeRoot, LtCriminal, catl, P);
        }
        else
        {
            findCountry(treeRoot, countryKey)->deletable = 1;
            findCountry(treeRoot, countryKey)->counter++;
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

void showCountryAscended(treeNode *treeNode)
{
    printf("\nID:%d", treeNode->country->ID);
    printf("\nNumber of Attacks:%d", treeNode->country->counter);
}

void showCountryWithKey(treeNode *treeNode)
{
    printf("\n%d: %s", treeNode->country->ID, treeNode->country->name);
}

void showCountryForStats(treeNode *treeNode)
{
    printf("%d: %s\n", treeNode->country->ID, treeNode->country->name);

    if (treeNode->country->counter == 0)
    {
        printf("\nNo attacks registered");
    }
    else
    {
        int x = treeNode->country->counter;
        printf("Total Attacks:%d\n", x / 4);
    }
}

void addCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
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

    newCountry->counter = 0;

    treeRoot = insert(treeRoot, newCountry->ID, newCountry);

    system("cls");
    printf("Country added successfully.");
    sleep(1);
    countriesMenu(treeRoot, LtCriminal, catl, P);
}

void deleteCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to delete.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal, catl, P);
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
            countriesMenu(treeRoot, LtCriminal, catl, P);
        }
        else
        {
            if (search(treeRoot, key)->country->deletable == 1)
            {
                system("cls");
                printf("Error: the country is being used");
                sleep(1);
                countriesMenu(treeRoot, LtCriminal, catl, P);
            }

            treeRoot = deleteNode(treeRoot, key);
            system("cls");
            printf("Country deleted successfully.");
            sleep(1);
            system("cls");
            countriesMenu(treeRoot, LtCriminal, catl, P);
        }
    }
}

void updateCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to update.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal, catl, P);
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
            countriesMenu(treeRoot, LtCriminal, catl, P);
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
                countriesMenu(treeRoot, LtCriminal, catl, P);
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
                countriesMenu(treeRoot, LtCriminal, catl, P);
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
                countriesMenu(treeRoot, LtCriminal, catl, P);
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
                countriesMenu(treeRoot, LtCriminal, catl, P);
            default:
                system("cls");
                printf("Invalid Input.");
                sleep(1);
                updateCountry(treeRoot, LtCriminal, catl, P);
                break;
            }
        }
    }
}

///| | | | | | | | | | | STATS METHODS | | | | | | | | | | |

void statsTotalCyberAttacksDone(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    printf("Total of Attacks done: %d", totalAttacks);
    printf("\n");
    char nothing[100];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    statisticsMenu(treeRoot, LtCriminal, catl, P);
}

void statsTotalCyberAttacksSentReceivedByCountry(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (treeRoot == NULL)
    {
        printf("No Countries found.");
        sleep(1);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        printf("\nTotal Attacks done and received in every country");
        printf("\n--------------------------------------------------------\n");

        inOrderForStats(treeRoot);
        printf("\n");
        char nothing[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
}

void statsTotalCyberAttacksSentReceivedByType(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (catl->first == NULL)
    {
        printf("\nNo cyberAttack types to show.\n");
        sleep(1);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        printf("\nCyberattacks sent and received by type");
        printf("\n--------------------------------------------------------\n");
        cyberAttackType *aux;

        for (aux = catl->first; aux != NULL; aux = aux->next)
        {
            printf("Name: %s\n", aux->name);
            int n = aux->counter;
            printf("Number of attacks: %d\n", n / 4);
        }

        char nothing[10];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
}

void statsTotalCyberAttacksSentByCriminal(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("\nNo Criminals found.\n");
        sleep(1);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }

    printf("\nCyberattacks done by cyber criminal");
    printf("\n--------------------------------------------------------\n");

    cyberCriminal *i;
    int n = 1;
    for (i = LtCriminal->head; i != NULL; i = i->next)
    {
        printf("\nID:%s", i->ID);
        int x = i->counter;
        printf("\nNumber of attacks:%d", x / 4);
        n++;
    }

    char nothing[10];
    printf("\n<Press any key to return>\n");
    fflush(stdin);
    gets(nothing);
    statisticsMenu(treeRoot, LtCriminal, catl, P);
}

void topThree(treeNode *root, int first, int second, int third)
{
    if (root == NULL)
        return;

    if (root->country->counter > first)
    {
        third = second;
        second = first;
        first = root->country->counter;
    }

    else if (root->country->counter > second && root->country->counter != first)
    {
        third = second;
        second = root->country->counter;
    }

    else if (root->country->counter > third && root->country->counter != first && root->country->counter != second)
    {
        third = root->country->counter;
    }

    topThree(root->left, first, second, third);
    topThree(root->right, first, second, third);
}

void topThreeCountriesWithMostAttacksReceived(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (treeRoot == NULL)
    {
        printf("No Countries found.");
        sleep(1);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {
        topThree(treeRoot, 0, 0, 0);
        printf("\n");
        char nothing[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
}

void findLargestAndSecondLargest(listCriminal *LtCriminal)
{
    int val1 = LtCriminal->head->counter;
    int val2 = LtCriminal->head->counter;
    int max = max(val1, val2);
    int second_max = min(val1, val2);

    LtCriminal = LtCriminal->head->next->next;

    while (LtCriminal != NULL)
    {
        if (LtCriminal->head->counter > max)
        {
            second_max = max;
            max = LtCriminal->head->counter;
        }
        else if (LtCriminal->head->counter > second_max)
        {
            second_max = LtCriminal->head->counter;
        }

        LtCriminal = LtCriminal->head->next;
    }

    printf("");
}

void topThreeCriminalsWithMostAttacksSent(treeNode *treeRoot, listCriminal *LtCriminal, cyberAttackTypeList *catl, Pila *P)
{
    system("cls");
    if (LtCriminal->head == NULL)
    {
        printf("No criminals to show.");
        sleep(1);
        system("cls");
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
    else
    {

        printf("Top 3 cybercriminals with the highest amount of attacks");
        printf("\n--------------------------------------------------------\n");

        //showCriminalsForStats(LtCriminal);

        printf("\n");
        char nothing[100];
        printf("\n<Press any key to return>\n");
        fflush(stdin);
        gets(nothing);
        statisticsMenu(treeRoot, LtCriminal, catl, P);
    }
}

/// | | | | | | | | | | | | | | Main | | | | | | | | | | |  | |
int main()
{
    listCriminal *LtCriminal;
    LtCriminal = newListCriminal();

    cyberAttackTypeList *catl;
    catl = newListcatl();

    Pila *P;
    P = newPila();

    struct treeNode *root = NULL;
    mainMenu(root, LtCriminal, catl, P);
    return -1;
}
