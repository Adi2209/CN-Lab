/*2. Write a C program to assign values to each members of the following structure. Pass the populated structure to a function Using call-by address and print the value of each member of the structure with in that function.
struct info{
int roll_no;
char name[50];
float CGPA;
}*/

#include <stdio.h>
typedef struct info
{
    int roll_no;
    char name[50];
    float CGPA;
} information;
void display(information *i)
{
    printf("``````Display function called`````\n");
    printf("The name of the student is %s\n", i->name);
    printf("The roll no. of the stident is %d\n", i->roll_no);
    printf("The cgpa of the student is %f\n", i->CGPA);
}
int main()
{
    information i;
    printf("Enter the roll\n");
    scanf("%d", &i.roll_no);
    printf("Enter the cgpa\n");
    scanf("%f", &i.CGPA);
    printf("Enter the name of the student :\n");
    scanf("%s", i.name);
    display(&i);
}