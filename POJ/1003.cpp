/*************************************************************************
    > File Name: 1003.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon Apr 29 16:17:29 2019
 ************************************************************************/

#include <stdio.h>

static long long gcd(long long a, long long b)
{
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

static int solution_1(float length)
{
    long long numerator = 1;
    long long denominator = 2;
    int n = 3, count = 1;
    
    while ((float)numerator / denominator < length) {
        int a = denominator, b = numerator;
        
        denominator = a * n;
        numerator = a + b * n;
        
        long long _gcd = gcd(numerator, denominator);
        numerator /= _gcd;
        denominator /= _gcd;
        
#ifdef _DEBUG
        printf("%d %d %f\n", numerator, denominator, (float)numerator / denominator);
#endif            
        
        n ++;
        count ++;
    }
    return count;
}

int solution_2(float length)
{
    float sum = 0.0f;
    int n = 2;
    
    while (sum < length) {
        sum += 1.0 / n;
        n ++;
    }
    
    return n - 2;
}

int main(int argc, char * argv[])
{
    float length;

    while (scanf("%f", &length) == 1 && length > 0) {
        
        int slices = solution_2(length);
        
        printf("%d card(s)\n", slices);
    }
    
    return 0;
}
