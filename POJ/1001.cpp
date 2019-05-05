/*************************************************************************
    > File Name: 1001.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon Apr 29 12:42:54 2019
 ************************************************************************/

//http://poj.org/problem?id=1001
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define MAXSIZE 160 //100000 ^ 25, 25 * 5 = 125(zero) + 1(leader number)

int main(int argc, char * argv[])
{
    char R[10];
    int result[MAXSIZE];
    int times, dot, base = 0;
    int len_R = 0;
    int i, k;
    int len_result = 0, high_val, tail_zero_pos;
    
    while(scanf("%s%d", R, &times) == 2) {
        
        len_R = strlen(R);
        base = 0, dot = -1;
        
        for (i = 0; i < len_R; i++) {
            if (R[i] == '.') {
                dot = len_R - i - 1;
            } else {
                base = base * 10 + (R[i] - '0');
            }
        }
        
        dot *= times;
#ifdef _DEBUG        
        printf("base:%d, dot:%d, times:%d\n", base, dot, times);
#endif
        
        if (base == 0) {
            printf("0\n");
            continue;
        }
        
        memset(result, 0, sizeof(result));
        result[0] = 1;
        len_result = 1;
        
        for (i = 0; i < times; i++) {            
            
            for (k = 0; k < len_result; k++) {
                result[k] = base * result[k];
            }

#ifdef _DEBUG
            for (k = 0; k < len_result; k++) {
                printf("%d\n", result[k]);
            }
#endif
            
            for (k = 0; k < len_result - 1; k++) {     
                if (result[k] >= 10) {
                    result[k + 1] += result[k] / 10;
                    result[k] %= 10;                
                }
            }
            
            high_val = result[len_result - 1];
            if (high_val >= 10) {                
                len_result = len_result - 1;
                while (high_val > 0) {
                    result[len_result ++] = high_val % 10;
                    high_val /= 10;
                }
            }
        }
        
#ifdef _DEBUG
        printf("result:%d:", len_result);
        for (i = 0; i < len_result; i++) {
            printf("%d", result[i]);
        }
        printf("\n");
#endif
        
        if (dot < 0) {
            for (i = len_result - 1; i >= 0; i--) {
                printf("%d", result[i]);
            }
        } else {
            if (dot > len_result) {
                len_result = dot;
            }
            
            tail_zero_pos = 0;
            for (i = 0; i < dot; i++) {
                if (result[i] != 0) {
                    tail_zero_pos = i;
                    break;
                }
            }
            if (i == dot) {
                tail_zero_pos = dot;
            }
            
#ifdef _DEBUG
            printf("tail_zero_pos:%d, dot:%d\n", tail_zero_pos, dot);            
#endif

            for (i = len_result - 1; i >= tail_zero_pos; i--) {
                if (i == dot - 1) {
                    printf(".");
                }
                printf("%d", result[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
