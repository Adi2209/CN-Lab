/*4. Write a C Program to enter a number and store the 
number across the following structure and print the content of 
each member of the structure.
Then aggregate each member of the structure to 
form the original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};*/

#include<stdio.h>
#include<string.h>
typedef struct pkt{
char ch1;
char ch2[2];
char ch3;
}p;
void aggregate(p k){
    int number,x,y=1;
    printf("Enter a number\n");
    scanf("%d",&number);
    while(number!=0 && y<=4){
        x=number%10;
        if(y==1){
            k.ch1=x;
        }
        if(y==2){
            k.ch2[0]=x;
        }
        if(y==3){
            k.ch2[1]=x;
        }
        if(y==4){
            k.ch3=x;
        }
        y++;
        number=number/10;
    }
    printf("The aggregate characters are %d\n%d\n%d\n%d\n",k.ch3,k.ch2[1],k.ch2[0],k.ch1);
}
int main(){
    p m;
    aggregate(m);
}
