#include<stdio.h>
#include<stdlib.h>

void minmax(int *data, int n, int *min, int *max){
    *min = data[0];
    *max = data[0];

    for(int i = 1; i < n; i++){
        if(data[i] > *max)
            *max = data[i];
        else if(data[i] < *min)
            *min = data[i];    
    }
}

int main(){
    int data[10] = {20, 19, 33, 28, 1, 5, 10, 40, 21, 8};

    int min, max;

    minmax(data, 10, &min, &max);

    printf("Min = %d\n", min);
    printf("Max = %d\n", max);

    exit(0);
}