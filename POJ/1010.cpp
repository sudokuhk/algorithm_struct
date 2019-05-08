/*************************************************************************
    > File Name: 1010.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Tue May  7 14:16:27 2019
 ************************************************************************/

#include <stdio.h>
#include <vector>
#include <algorithm>

typedef std::vector<int> int_array_t;

int_array_t solution;

void dfs(int want, const int_array_t & stamps, int_array_t count)
{
    if (count.size() >= 4) {
        return;
    }
}

int main(int argc, char * argv[])
{
    int_array_t stamps, customers;
    int v;
    
    while (true) {
        if (scanf("%d", &v) && v == 0) {
            break;
        }
        
        // 1. get stamps
        stamps.push_back(v);
        while (scanf("%d", &v) && v) {
            stamps.push_back(v);
        }
        
        // 2. get customers
        while (scanf("%d", &v) && v) {
            customers.push_back(v);
        }
        
        // 3. sort stamps by desc
        sort(stamps.begin(), stamps.end());
        
#if defined(DEBUG)
        for (int i = 0; i < stamps.size(); i++) {
            printf("%d ", stamps[i]);
        }
        printf("\n");
        
        for (int i = 0; i < customers.size(); i++) {
            printf("%d ", customers[i]);
        }
        printf("\n");
#endif
        
    }
    return 0;
}
