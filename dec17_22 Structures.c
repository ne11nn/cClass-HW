#include <stdio.h>

typedef struct
{
    char *name;
    int age;
    char *toy;
    char *catOrDog;
} PetStruct;

typedef struct
{
    char *name;
    int age;
    int phoneNumber;
    char *address;
    PetStruct *pet;
} PersonStruct;

void printInfo(PersonStruct *personStu)
{
    printf("Hi my name is %s. I am %d years old and I have a %s. He is called %s and likes to play with a %s. Currently he is %d years old.", personStu->name, personStu->age, 
    personStu->pet->catOrDog, personStu->pet->name, personStu->pet->toy, personStu->pet->age);
}

int main()
{
    PetStruct petStu = {"Cleo", 2, "Yarn Ball", "Cat"};
    PersonStruct personStu = {"Peter", 18, 33420620, "7 EMPERSS RD 01-02", &petStu};
    printInfo(&personStu);
    return 0;
}