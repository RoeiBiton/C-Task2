
#include "Functions.h"

void matrixSet(int arr[10][10], int value, int i, int j){
    arr[i][j]=value;
}
int pathExist(int arr[10][10], int start, int dest){
    int isTherePath=0;
    //check for direct path
    if(arr[start][dest]!=0){return 1;}

    //check how many bows we can check
    int bowsCount = 0;
    for(int j= 0; j<10; j++){
        if(arr[start][j]!=0){
            bowsCount=1;
        }
    }
    if(bowsCount == 0){return 0;}
    else {

        int temp[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == start) {
                    temp[i][j] = 0;
                } else {
                    temp[i][j] = arr[i][j];
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            if (arr[start][j] != 0) {
                isTherePath= isTherePath + pathExist(temp, j, dest);
            }
        }
    }
    if(isTherePath!=0){isTherePath=1;}
    return isTherePath;
}

int shortestPathCheck(int arr[10][10], int start, int dest, int stepCount){
    int tempStepCount=0;
    if(arr[start][dest]!=0){
        tempStepCount = stepCount + arr[start][dest];
    }
    int tempArr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == start) {
                tempArr[i][j] = 0;
            } else {
                tempArr[i][j] = arr[i][j];
            }
        }
    }
    for(int j=0; j<10;j++){
        if(arr[start][j]!=0){
            if(pathExist(tempArr, j, dest)!=0){
                int x = shortestPathCheck(tempArr, j, dest, arr[start][j]);
                if(x<tempStepCount){
                    tempStepCount=x;
                }

            }
        }
    }
    return tempStepCount;
}
int shortestPath(int arr[10][10], int start, int dest){
    if(pathExist(arr, start, dest)==0){return -1;}
    else {
        return shortestPathCheck(arr, start, dest, 0);
    }
}
