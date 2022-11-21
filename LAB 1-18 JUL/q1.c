/*1. Write a C program to swap the content of 2 variables using pointer.*/
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int num1, num2;

    printf("Enter value of num1: ");
    scanf("%d", &num1);
    printf("Enter value of num2: ");
    scanf("%d", &num2);

    printf("Before Swapping:\n %d %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After  Swapping:\n %d %d\n", num1, num2);

    return 0;
}