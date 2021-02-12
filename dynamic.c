#include <stdio.h>
#define M  50

int min(int nm[]){
    int i;
    int id = 0;
    int min = nm[0];
    for(i = 1; i < 3; i++){
        if(nm[i] < min){
            min = nm[i];
            id = i;
        }
    }
    return id;
}

void findUgly(int uglies[] ,int nm[], int ix[], int counter, int id){
    int i;
    int comp = nm[id];
    int mult;
    uglies[counter] = nm[id];
    for(i = 0; i < 3; i++){
        if(nm[i] == comp){
            if(i == 0) mult = 2;
            else if(i == 1) mult = 3;
            else mult = 5;
            ix[i]++;
            nm[i] = mult * uglies[ix[i]];
        }
    }
}

int main(){
    int ix[3]= {0, 0, 0};
    int uglies[M] = {1};
    int nm[3] = {2, 3, 5};
    int counter = 1;
    int idMin;

    while(counter < M){
        idMin = min(nm);
        printf("%d %d %d\n", nm[0], nm[1], nm[2]);
        findUgly(uglies, nm, ix, counter, idMin);
        
        counter++;
    }
    printf("%d\n%d\n",uglies[M-1], counter);
    return 0;
}