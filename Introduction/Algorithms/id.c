#include<stdio.h>
#include<string.h>

typedef struct
{
    char* name;
    char* id;
}
person;

int main(void)
{
    // declare an array of person named people
    person people[2];

    // add content to the array
    people[0].name = "Jack Ryan";
    people[0].id = "280";
    people[1].name = "Ally James";
    people[1].id = "340";

    //find jack
    for (int i = 0; i < 2; i++)
    {
        if(strcmp(people[i].name, "Ally James") == 0)
        {
            printf("Found %s. Their ID is %s.\n", people[i].name, people[i].id);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}
