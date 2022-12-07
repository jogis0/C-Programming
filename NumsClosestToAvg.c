//Kodo autorius - Jokūbas Viliušis
//Tai programa suskaiciuojanti skaiciu sekos vidurki ir isrenkanti 2 arciausius vidurkio skaicius: didesni ir mazesni

#include <stdio.h>
#include <math.h>
//Masyvo ir ivedamu skaiciu reziai
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
    printf("Ivedus N skaiciu kieki, si programa apskaiciuja N sveiku skaiciu vidurki ir isveda du arciausius vidurkio\n");
    printf("masyvo narius: mazesni ir didesni.\n");
    printf("Skaiciu kiekis N turi priklausyti intervalui [1;%d], sekos skaiciai turi priklausyti intervalui [%d;%d]\n", ARRAY_MAX, NUM_MIN, NUM_MAX);
    while(1){
        printf("Iveskite skaiciu N:\n");
        if(scanf("%d", &numSize) == 1 && getchar() == '\n'){
            if(numSize <= ARRAY_MAX && numSize >= 1){
                break;
            }else{
                printf("Skaiciu kiekis N turi priklausyti intervalui [1;%d].\n", ARRAY_MAX); //Jei skaicius nepriklauso nustatytam intervalui
            }
        }else{
            printf("Neteisinga ivestis, iveskite sveika skaiciu.\n"); //Jei ivestis nera sveikasis skaicius
            while(getchar()!='\n')
                ;
        }
    }
    getInputArray(numArray, numSize, NUM_MIN, NUM_MAX);
    printf("Skaiciu sekos vidurkis: %.2lf\n", arrayAvg(numArray, numSize));
    printf("Vidurkio mazesnysis skaicius: %d\n", avgNumMinor(numArray, numSize));
    printf("Vidurkio didesnysis skaicius: %d\n", avgNumMajor(numArray, numSize));
    return 0;
}
void getInputArray(int num[], int size, int numMin, int numMax){
    int i = 0, temp;
    while(i<size){
        printf("Iveskite %d-aji skaiciu:\n", i + 1);
        if(scanf("%d", &temp) == 1 && getchar() == '\n'){
            if(temp <= numMax && temp >= numMin){
                num[i] = temp;
                ++i;
            }else{
                printf("Skaicius turi priklausyti intervalui [%d;%d].\n", numMin, numMax);
            }
        }else{
            printf("Neteisinga ivestis, iveskite sveika skaiciu.\n");
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
    int closest = smallestNum(num, size); //Pradedama nuo skaiciaus, mazesnio uz vidurki
    double closestDiff = fabs(arrayAvg(num, size) - closest);
    for(int i=0; i<size; ++i){
        double currentDiff = fabs(arrayAvg(num, size) - num[i]);
        if(currentDiff < closestDiff && num[i] < arrayAvg(num, size)){ //Ziurime, ar kiekvieno nario skirtumas yra mazesnis, uz maziausia skirtuma
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
