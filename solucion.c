//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Struct Declarations
typedef struct cyberAttackType cyberAttackType;
typedef struct cyberAttack cyberAttack;
typedef struct cyberCriminal cyberCriminal;
typedef struct country country;

//Struct's bodies

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


// | | | | | | | | | | | | | | Menus | | | | | | | | | | | | | |  

void mainMenu(){

    //HEADER
    system("cls");
    int option;
    printf("[Main Menu]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attacks\n2.Cyber Criminals\n3.Countries\n4.Stadistics\n");
    scanf("%i", &option);
    //END HEADER

    switch (option)
    {
    case 1:
        cyberAttackMenu();
        break;
    
    case 2:
        cyberCriminalsMenu();
        break;

    case 3:
        countriesMenu();
        break;
    
    case 4:
        printf("Statistics");
        break;
    
    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        mainMenu();
        break;
    }  
}

void cyberAttackMenu(){

    //HEADER
    system("cls");
    int option;
    printf("[Cyber Attacks]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Cyber Attack Simulation\n2.Manual registration\n3.Cyber Attack Routes\n4.Delete a Cyber Attack\n5.Update a Cyber Attack\n6.Show graph of Cyber Attacks\n7.Go back\n");
    scanf("%i", &option);
    //END HEADER

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
        mainMenu();
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberAttackMenu();
        break;
    }  
}

void cyberAttackTypesMenu(){

    //HEADER
    system("cls");
    int option;
    printf("[Cyber Attack Types]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.Add a new type\n2.Delete a type\n3.Show types\n4.Update a type\n5.Go Back\n");
    scanf("%i", &option);
    //END HEADER

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
        mainMenu();
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberAttackTypesMenu();
        break;
    }  
}

void cyberCriminalsMenu(){

    //HEADER
    system("cls");
    int option;
    printf("[Cyber Criminals]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.New Cyber Criminal\n2.Delete a Cyber Criminal\n3.Show known Cyber Criminals\n4.Update data\n5.Go Back\n");
    scanf("%i", &option);
    //END HEADER

    switch (option)
    {
    case 1:
        printf("New Criminal");
        break;
    
    case 2:
        printf("Delete a criminal");
        break;

    case 3:
        printf("Show criminals");
        break;
    
    case 4:
        printf("Update");
        break;
    
    case 5:
        mainMenu();
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        cyberCriminalsMenu();
        break;
    }  
}

void countriesMenu(){

    //HEADER
    system("cls");
    int option;
    printf("[Countries]");
    printf("\nChoose one of the following options:\n------------------------------------\n1.New Country\n2.Delete a country\n3.Show countries\n4.Update data\n5.Go Back\n");
    scanf("%i", &option);
    //END HEADER

    switch (option)
    {
    case 1:
        printf("New Country");
        break;
    
    case 2:
        printf("Delete a country");
        break;

    case 3:
        printf("Show countries");
        break;
    
    case 4:
        printf("Update data");
        break;
    
    case 5:
        mainMenu();
        break;

    default:
        system("cls");
        printf("[Invalid Input]");
        sleep(1);
        countriesMenu();
        break;
    }  
}




// | | | | | | | | | | | | | | Main | | | | | | | | | | | | | |  
void main()
{
    mainMenu();
}