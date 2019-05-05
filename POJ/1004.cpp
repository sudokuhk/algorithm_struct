/*************************************************************************
    > File Name: 1004.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon Apr 29 16:49:06 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) 
{
    float input, sum = 0.0f;
    
    for (int i = 0; i < 12; i++) {
        scanf("%f", &input);
        sum += input;
    }
    printf("$%.2f\n", sum / 12);
    
    return 0;
}
