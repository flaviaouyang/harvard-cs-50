#include<stdio.h>
#include<string.h>

int main()
{
    //"a" means append
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1; //error handling
    }
 
    char name[1024];
    printf("name: ");
    scanf("%s", name);

    int age;
    printf("age: ");
    scanf("%i", &age);

    char sex[1024];
    printf("sex: ");
    scanf("%s", sex);

    char number[1024];
    printf("phone number: ");
    scanf("%s", number);
    fprintf(file, "%s,%i,%s,%s\n", name, age, sex,number);

    //close the file
    fclose(file);
}