//Code author - Jokūbas Viliušis
//This program calculates the average of user-entered numbers and finds 2 closest numbers to the average: one lower than the average and one higher

#include <stdio.h>
#include <math.h>

#define ARRAY_MAX 1000
#define NUM_MAX 1000000
#define NUM_MIN (-1000000)

void getInputArray(int num[], int size, int numMin, int numMax);
double arrayAvg(int num[], int size);
int smallestNum(int num[], int size);
int biggestNum(int num[], int size);
int avgNumMinor(int num[], int size);
int avgNumMajor(int num[], int size);

int main(){
    int numArray[ARRAY_MAX];
    int numSize;
    printf("This program gets the amount of numbers to be entered (number N) and then gets N amount of numbers.\n");
    printf("It calculates the average of the numbers and finds 2 closest numbers to the average: one lower and one higher than the average.\n");
    printf("Number N has to be between 1 and %d, entered numbers have to be between %d and %d.\n", ARRAY_MAX, NUM_MIN, NUM_MAX);
    while(1){
        printf("Enter number N:\n");
        if(scanf("%d", &numSize) == 1 && getchar() == '\n'){
            if(numSize <= ARRAY_MAX && numSize >= 1){
                break;
            }else{
                printf("Number N has to be between 1 and %d.\n", ARRAY_MAX);
            }
        }else{
            printf("Incorrect input, input has to be a whole number.\n");
            while(getchar()!='\n')
                ;
        }
    }
    getInputArray(numArray, numSize, NUM_MIN, NUM_MAX);
    printf("Average: %.2lf\n", arrayAvg(numArray, numSize));
    printf("Closest number lower than the average: %d\n", avgNumMinor(numArray, numSize));
    printf("Closest number higher than the average: %d\n", avgNumMajor(numArray, numSize));
    return 0;
}
void getInputArray(int num[], int size, int numMin, int numMax){
    int i = 0, temp;
    while(i<size){
        printf("Enter the %d number:\n", i + 1);
        if(scanf("%d", &temp) == 1 && getchar() == '\n'){
            if(temp <= numMax && temp >= numMin){
                num[i] = temp;
                ++i;
            }else{
                printf("Entered numbers have to be between %d and %d.\n", numMin, numMax);
            }
        }else{
            printf("Incorrect input, input has to be a whole number.\n");
            while(getchar()!='\n')
                ;
        }
    }
}
double arrayAvg(int num[], int size){
    int sum = 0;
    for(int i=0; i<size; ++i){
        sum += num[i];
    }
    return (double)sum / (double)size;
}
int smallestNum(int num[], int size){
    int result = num[0];
    for(int i=1; i<size; ++i){
        if(num[i] < result){
            result = num[i];
        }
    }
    return result;
}
int biggestNum(int num[], int size){
    int result = num[0];
    for(int i=1; i<size; ++i){
        if(num[i] > result){
            result = num[i];
        }
    }
    return result;
}
int avgNumMinor(int num[], int size){
    int closest = smallestNum(num, size);
    double closestDiff = fabs(arrayAvg(num, size) - closest);
    for(int i=0; i<size; ++i){
        double currentDiff = fabs(arrayAvg(num, size) - num[i]);
        if(currentDiff < closestDiff && num[i] < arrayAvg(num, size)){
            closest = num[i];
            closestDiff = currentDiff;
        }
    }
    return closest;
}
int avgNumMajor(int num[], int size){
    int closest = biggestNum(num, size);
    double closestDiff = fabs(arrayAvg(num, size) - closest);
    for(int i=0; i<size; ++i){
        double currentDiff = fabs(arrayAvg(num, size) - num[i]);
        if(currentDiff < closestDiff && num[i] > arrayAvg(num, size)){
            closest = num[i];
            closestDiff = currentDiff;
        }
    }
    return closest;
}
