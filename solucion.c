// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Struct Declarations
typedef struct cyberAttackType cyberAttackType;
typedef struct cyberAttack cyberAttack;
typedef struct cyberCriminal cyberCriminal;
typedef struct listCriminal listCriminal;
typedef struct country country;
typedef struct treeNode treeNode;

// Struct's bodies
struct cyberAttackType
{
    char *code;
    char *name;
    char *description;
    char *channels;
};

struct cyberCriminal
{
    char *ID;
    char *organization;
    char *description;
    country *nacionality;
    char *knownAttacks;
    cyberCriminal *next;
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

// | | | | | | | | | | | | | | Utilities | | | | | | | | | | | |

char *mystrcpy(char *dst, const char *src)
{
    char *ptr = dst;
    while ((*dst++ = *src++))
        ;
    return ptr;
}

// | | | | | | | | | | | | | | Menus | | | | | | | | | | | | | |

void mainMenu(treeNode *treeRoot, listCriminal *LtCriminal)
{

    // HEADER
    system("cls");
    int option;
    printf("[Main Menu]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attacks\n2.Cyber Criminals\n3.Countries\n4.Stadistics\n");
    scanf("%i", &option);
    // END HEADER

    switch (option)
    {
    case 1:
        cyberAttackMenu(treeRoot, LtCriminal);
        break;

    case 2:
        cyberCriminalsMenu(treeRoot, LtCriminal);
        break;

    case 3:
        countriesMenu(treeRoot, LtCriminal);
        break;

    case 4:
        statisticsMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        mainMenu(treeRoot, LtCriminal);
        break;
    }
}

void cyberAttackMenu(treeNode *treeRoot, listCriminal *LtCriminal)
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
        printf("Manual Registration");
        break;

    case 3:
        printf("Cyber Attack Routes");
        break;

    case 4:
        printf("Delete a Cyber Attack");
        break;

    case 5:
        printf("Update a Cyber Attack");
        break;

    case 6:
        printf("Show Graph of Cyber Attacks");
        break;

    case 7:
        mainMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberAttackMenu(treeRoot, LtCriminal);
        break;
    }
}

void cyberAttackTypesMenu(treeNode *treeRoot, listCriminal *LtCriminal)
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
        printf("Add a new type");
        break;

    case 2:
        printf("Delete a type");
        break;

    case 3:
        printf("Show types");
        break;

    case 4:
        printf("Update");
        break;

    case 5:
        mainMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberAttackTypesMenu(treeRoot, LtCriminal);
        break;
    }
}

void cyberCriminalsMenu(treeNode *treeRoot, listCriminal *LtCriminal)
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
        addCriminal(treeRoot, LtCriminal);
        break;

    case 2:
        deleteCriminal(treeRoot, LtCriminal);
        break;

    case 3:
        system("cls");
        if (LtCriminal == NULL)
        {
            printf("No Criminals found.");
        }
        else
        {
            showCriminal(LtCriminal);
        }
        char nothing[10];
        printf("\n[Press any key to return]\n");
        fflush(stdin);
        gets(nothing);
        cyberCriminalsMenu(treeRoot, LtCriminal);
        break;

    case 4:
        updateCriminal(treeRoot, LtCriminal);
        break;

    case 5:
        mainMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal);
        break;
    }
}

void countriesMenu(treeNode *treeRoot, listCriminal *LtCriminal)
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
        addCountry(treeRoot, LtCriminal);
        break;

    case 2:
        deleteCountry(treeRoot, LtCriminal);
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
        printf("\n[Press any key to return]\n");
        fflush(stdin);
        gets(nothing);
        countriesMenu(treeRoot, LtCriminal);
        break;

    case 4:
        updateCountry(treeRoot, LtCriminal);
        break;

    case 5:
        mainMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        countriesMenu(treeRoot, LtCriminal);
        break;
    }
}

void statisticsMenu(treeNode *treeRoot, listCriminal *LtCriminal)
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
        mainMenu(treeRoot, LtCriminal);
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        countriesMenu(treeRoot, LtCriminal);
        break;
    }
}

// | | | | | | | | | | | BS TREE | | | |  | | | | | | | | | | |

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
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
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

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct treeNode *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
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

// | | | | | | | | | | | GRAPH  | | | |  | | | | | | | | | | |

//| | | | | | | | | | | CRIMINAL METHODS | | | | | | | | | | |

listCriminal *newListCriminal(void)
{
    listCriminal *LtCriminal;
    LtCriminal = (listCriminal *)malloc(sizeof(listCriminal));
    LtCriminal->head = NULL;
    return LtCriminal;
}

void addCriminal(treeNode *treeRoot, listCriminal *LtCriminal)
{
    cyberCriminal *n, *aux;

    if (LtCriminal->head == NULL)
    {
        const char *src;
        LtCriminal->head = (cyberCriminal *)malloc(sizeof(cyberCriminal));
        system("cls");
        printf("[Add Criminal]\n");

        char idCriminal[100];
        printf("Criminal's ID:");
        fflush(stdin);
        gets(idCriminal);
        src = idCriminal;
        char *dst = malloc(sizeof(char) * (strlen(src) + 1));
        LtCriminal->head->ID = idCriminal;

        char descriptionCriminal[100];
        printf("Criminal's description:");
        fflush(stdin);
        gets(descriptionCriminal);
        src = descriptionCriminal;
        char *dst2 = malloc(sizeof(char) * (strlen(src) + 1));
        LtCriminal->head->description = descriptionCriminal;

        char knownAttacksCriminal[100];
        printf("Criminal's known attacks:");
        fflush(stdin);
        gets(knownAttacksCriminal);
        src = knownAttacksCriminal;
        char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
        LtCriminal->head->knownAttacks = knownAttacksCriminal;

        char nacionalityCriminal[100];
        printf("Criminal's nacionality:");
        fflush(stdin);
        gets(nacionalityCriminal);
        src = nacionalityCriminal;
        char *dst4 = malloc(sizeof(char) * (strlen(src) + 1));
        LtCriminal->head->nacionality = nacionalityCriminal;

        char organizationCriminal[100];
        printf("Criminal's organization:");
        fflush(stdin);
        gets(organizationCriminal);
        src = organizationCriminal;
        char *dst5 = malloc(sizeof(char) * (strlen(src) + 1));
        LtCriminal->head->organization = organizationCriminal;
        LtCriminal->head->next = NULL;

        system("cls");
        printf("Criminal added successfully.");
        sleep(1);
        fflush(stdin);
        cyberCriminalsMenu(treeRoot, LtCriminal);
    }

    n = LtCriminal->head;

    while (n != NULL)
    {
        aux = n;
        n = n->next;
    }

    const char *src;
    aux->next = (cyberCriminal *)malloc(sizeof(cyberCriminal));
    aux->next->next = NULL;

    system("cls");
    printf("[Add Criminal]");

    char idCriminal[100];
    printf("Criminal's ID:");
    fflush(stdin);
    gets(idCriminal);
    src = idCriminal;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    aux->next->ID = idCriminal;

    char descriptionCriminal[100];
    printf("Criminal's description:");
    fflush(stdin);
    gets(descriptionCriminal);
    src = descriptionCriminal;
    char *dst2 = malloc(sizeof(char) * (strlen(src) + 1));
    aux->next->description = descriptionCriminal;

    char knownAttacksCriminal[100];
    printf("Criminal's known attacks:");
    fflush(stdin);
    gets(knownAttacksCriminal);
    src = knownAttacksCriminal;
    char *dst3 = malloc(sizeof(char) * (strlen(src) + 1));
    aux->next->knownAttacks = knownAttacksCriminal;

    char nacionalityCriminal[100];
    printf("Criminal's nacionality:");
    fflush(stdin);
    gets(nacionalityCriminal);
    src = nacionalityCriminal;
    char *dst4 = malloc(sizeof(char) * (strlen(src) + 1));
    aux->next->nacionality = nacionalityCriminal;

    char organizationCriminal[100];
    printf("Criminal's organization:");
    fflush(stdin);
    gets(organizationCriminal);
    src = organizationCriminal;
    char *dst5 = malloc(sizeof(char) * (strlen(src) + 1));
    aux->next->organization = organizationCriminal;

    system("cls");
    printf("Criminal added successfully.");
    sleep(1);
    fflush(stdin);
    cyberCriminalsMenu(treeRoot, LtCriminal);
}

int elementExists(listCriminal *LtCriminal, char *idCriminal[100])
{
    cyberCriminal *nAux = LtCriminal->head;

    while (nAux != NULL)
    {
        if (nAux->ID == idCriminal)
        {
            return 1;
        }
        nAux = nAux->next;
    }

    return 0;
}

void deleteCriminal(treeNode *treeRoot, listCriminal *LtCriminal)
{
    const char *src;
    char idCriminal[100];
    printf("Criminal's ID:");
    fflush(stdin);
    gets(idCriminal);

    if (elementExists(LtCriminal, idCriminal))
    {
        cyberCriminal *n, *aux;

        if (LtCriminal->head == NULL)
        {
            system("cls");
            printf("No criminal to delete.");
            sleep(1);
            cyberCriminalsMenu(treeRoot, LtCriminal);
        }

        if (LtCriminal->head->ID == idCriminal)
        {
            LtCriminal->head = LtCriminal->head->next;
            system("cls");
            printf("Criminal deleted successfully.");
            sleep(1);
            system("cls");
            cyberCriminalsMenu(treeRoot, LtCriminal);
        }
        else
        {
            n = LtCriminal->head;
            while (n != NULL)
            {
                if (n->ID == idCriminal)
                {
                    break;
                }
                aux = n;
                n = n->next;
            }

            aux->next = n->next;
            system("cls");
            printf("Criminal deleted successfully.");
            sleep(1);
            system("cls");
            cyberCriminalsMenu(treeRoot, LtCriminal);
        }
    }
    else
    {
        system("cls");
        printf("ID does not exist.");
        sleep(1);
        cyberCriminalsMenu(treeRoot, LtCriminal);
    }
}

void showCriminal(listCriminal *LtCriminal)
{
    cyberCriminal *i;
    for (i = LtCriminal->head; i != NULL; i = i->next)
    {
        printf("\nID:%s", i->ID);
        printf("\nDescription:%s", i->description);
        printf("\nNacionality:%s", i->nacionality);
        printf("\nOrganization:%s", i->organization);
        printf("\nKnown Attacks:%s", i->knownAttacks);
        printf("\n-----------------------------------------");
    }
}

void updateCriminal(treeNode *treeRoot, listCriminal *LtCriminal)
{
}

//| | | | | | | | | | | COUNTRY METHODS | | | | | | | | | | |

void showCountry(treeNode *treeNode)
{
    printf("\nID:%d", treeNode->country->ID);
    printf("\nName:%s", treeNode->country->name);
    printf("\nPopulation:%s", treeNode->country->population);
    printf("\nContinent:%s\n", treeNode->country->continent);
}

void addCountry(treeNode *treeRoot, listCriminal *LtCriminal)
{
    system("cls");
    printf("[Add Country]");
    const char *src;
    country *newCountry;
    newCountry = (country *)malloc(sizeof(country));

    int ID;
    printf("\nCountry's ID:");
    scanf("%d", &ID);
    fflush(stdin);
    newCountry->ID = ID;

    char name[100];
    printf("Country's name:");
    fflush(stdin);
    gets(name);
    src = name;
    char *dst = malloc(sizeof(char) * (strlen(src) + 1));
    newCountry->name = mystrcpy(dst, src);

    char population[100];
    printf("Country's population:");
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

    treeRoot = insert(treeRoot, newCountry->ID, newCountry);

    system("cls");
    printf("Country added successfully.");
    sleep(1);
    countriesMenu(treeRoot, LtCriminal);
}

void deleteCountry(treeNode *treeRoot, listCriminal *LtCriminal)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to delete.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal);
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
            countriesMenu(treeRoot, LtCriminal);
        }
        else
        {
            treeRoot = deleteNode(treeRoot, key);
            system("cls");
            printf("Country deleted successfully.");
            sleep(1);
            system("cls");
            countriesMenu(treeRoot, LtCriminal);
        }
    }
}

void updateCountry(treeNode *treeRoot, listCriminal *LtCriminal)
{
    if (treeRoot == NULL)
    {
        system("cls");
        printf("No countries to update.");
        sleep(1);
        system("cls");
        countriesMenu(treeRoot, LtCriminal);
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
            countriesMenu(treeRoot, LtCriminal);
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
                countriesMenu(treeRoot, LtCriminal);
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
                countriesMenu(treeRoot, LtCriminal);
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
                countriesMenu(treeRoot, LtCriminal);
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
                countriesMenu(treeRoot, LtCriminal);
            default:
                system("cls");
                printf("Invalid Input.");
                sleep(1);
                updateCountry(treeRoot, LtCriminal);
                break;
            }
        }
    }
}

// | | | | | | | | | | | | | | Main | | | | | | | | | | |  | |
void main()
{
    listCriminal *LtCriminal;
    LtCriminal = newListCriminal();

    struct treeNode *root = NULL;
    mainMenu(root, LtCriminal);
}