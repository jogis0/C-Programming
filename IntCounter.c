//Code author - Jokūbas Viliušis
//This program calculates the number of positive integer numbers from user input

#include <stdio.h>
#define NUM_MAX 1000000
#define NUM_MIN -1000000

int main(){
    int num, counter = 0;
    printf("This program calculates the number of positive integer numbers from user input.\n");
    printf("To end, enter number 0\n");
    printf("Numbers must be above %d and below %d\n", NUM_MIN, NUM_MAX);

    while(1){
        printf("Enter a number:");
        if(scanf("%d", &num)==1 && getchar() == '\n'){
            if(num==0){
                break;
            }else if(num > NUM_MAX || num < NUM_MIN){
                printf("Numbers must be above %d and below %d\n", NUM_MIN, NUM_MAX);
            }else if(num>0 && num%2==0){
                ++counter;
            }
        }else{
            printf("Wrong input, please enter an integer number\n");
            while(getchar()!='\n')
                ;
        }
    }
    printf("Result: %d\n", counter);
    return 0;
}
