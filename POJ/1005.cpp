/*************************************************************************
    > File Name: 1005.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon May  6 10:30:35 2019
 ************************************************************************/

#include <stdio.h>
#include <math.h>

const float PI = 3.141592653589793f;

int main(int argc, char * argv[])
{
    int N, cnt = 0;
    float x, y, radius, square;
    
    scanf("%d", &N);
    while (N -- > 0) {
        scanf("%f %f", &x, &y);
        radius = sqrt(x * x + y * y);
        square = PI * radius * radius / 2.0f;
        
        printf("Property %d: This property will begin eroding in year %d.\n", 
               ++ cnt, (int)(square / 50.0f) + 1);
    }
    
    printf("END OF OUTPUT.\n");
    
    return 0;
}
