#include <stdio.h>
#include <stdbool.h>
#define M 1600

bool isUgly(int N){
    while(N % 2 == 0){
        N /= 2;
    }
    while(N % 3 == 0){
        N /= 3;
    }
    while(N % 5 == 0){
        N /= 5;
    }
    if(N == 1){
        return true;
    }else{
        return false;
    }
}

int main(){
    int counter = 1;
    int uglies[M] = {1};
    int N = 2;
    while(counter < M){
        if(isUgly(N) == true){
            uglies[counter] = N;
            counter++;
        }
        N++;
    } 
    printf("%d\n%d\n",uglies[M-1], N);
    return 0;
}