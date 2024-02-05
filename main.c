#include <stdio.h>
#include <ctype.h>
#include "Functions.h"
int isA(int arr[10][10]);

int isB();

int isC();

int main() {
    char A = 'A';
    char B = 'B';
    char C = 'C';
    char D = 'D';
    char userInput;
    int arr[10][10];

    while (userInput != 'D') {
        scanf("%c", &userInput);
       // printf("First input %c", userInput);
        if (userInput == D) { return 0; }
        if (userInput == A) { if(isA(arr)==0){ return 0; }}
        if (userInput == B) { if(isB(arr)==0){ return 0; }}
        if (userInput == C) {if(isC(arr)==0){ return 0; }}
        //printf("%c", userInput);
    }
}
    int isC(int arr[10][10]) {
        char userInput;
        int i;
        int j;
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; }
        if (userInput == 'A') { if(isA(arr)==0){ return 0; } return 1;}
        if (isdigit(userInput)) {
            i = userInput - '0';
        }
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; }
        if (userInput == 'A') { if(isA(arr)==0){ return 0; } return 1;}
        if (isdigit(userInput)) {
            j = userInput - '0';
        }
        if(pathExist(arr, i ,j)!=0){
            printf("%d", shortestPath(arr, i, j));
        }
        else{
            printf("-1");
        }
        return 1;
    }

    int isB(int arr[10][10]) {
        char userInput;
        int i;
        int j;
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; }
        if (userInput == 'A') { if(isA(arr)==0){ return 0; } return 1;}
        if (isdigit(userInput)) {
            i = userInput - '0';
        }
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; }
        if (userInput == 'A') { if(isA(arr)==0){ return 0; } return 1;}
        if (isdigit(userInput)) {
            j = userInput - '0';
        }
        printf("%d", pathExist(arr, i, j));
        return 1;
    }

    int isA(int arr[10][10]) {
        // printf("inside A");
        char x;
        for (int i = 0; i < 10; i++) {
            printf("i +");
            for (int j = 0; j < 10; j++) {
                scanf("%d", &x);
                printf("Place of [%d],[%d] is , %d", i, j, x);
                if (x == 'D') { return 0; }
                if (x == 'A') { isA(arr); }
                if (isdigit(x)) {
                    int z = x;
                    arr[i][j] = z;
                }
            }
        }
        return 1;
    }
