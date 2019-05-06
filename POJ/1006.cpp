/*************************************************************************
    > File Name: 1006.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon May  6 11:11:21 2019
 ************************************************************************/

#include <stdio.h>
#include <math.h>

static int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

static int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

static int cal(int a, int b, int c, int mod)
{
    int product = a * b;
    int i = 1;
    
    while (product * i % c != mod) {
        i ++;
    }
    
    return i * a * b;
}

int main(int argc, char * argv[])
{
    const int physical = 23;
    const int emotional = 28;
    const int intellectual = 33;

    const int a = cal(28, 33, 23, 1);    
    const int b = cal(23, 33, 28, 1);
    const int c = cal(23, 28, 33, 1);
    
#if defined(DEBUG)
    printf("%d %d %d\n", a, b, c);
#endif
    
    int p, e, i, d;
    int cnt = 0;
    const int max_cycle = 21252;
    
    while (true) {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p == -1 && e == -1 && i == -1 && d == -1) {
            break;
        }
        
        int n = (a * p + b * e + c * i - d + 21252) % 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", 
               ++ cnt, n > 0 ? n : 21252);
    }
    
    return 0;
}
