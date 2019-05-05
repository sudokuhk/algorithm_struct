/*************************************************************************
    > File Name: 1002.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon Apr 29 15:51:45 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

typedef std::map<int, int> MAP;
typedef MAP::const_iterator MAP_IT;

int main(int argc, char * argv[]) 
{
    int n;
    char line[100];
    MAP map_count;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", line);
        
        int len_line = strlen(line);
        int phone_num = 0;
        
        for (int j = 0; j < len_line; j++) {
            int digit = 0, pick = 0;
            
            if (line[j] >= '0' && line[j] <= '9') {
                digit = line[j] - '0';
                pick = 1;
            } else if (line[j] >= 'A' && line[j] <= 'P') {
                digit = (line[j] - 'A') / 3 + 2;
                pick = 1;
            } else if (line[j] >= 'R' && line[j] <= 'Y') {
                digit = (line[j] - 'A' - 1) / 3 + 2;
                pick = 1;
            }
            
            if (pick == 1) {
                phone_num = phone_num * 10 + digit;
            }
        }
        
        map_count[phone_num] ++;
    }
    
    if (map_count.size() == n) {
        printf("No duplicates.\n");
    } else {
        for (MAP_IT it = map_count.begin(); it != map_count.end(); ++ it) {
            if (it->second > 1) {
                int phone_num = it->first;
                printf("%03d-%04d %d\n", 
                       phone_num / 10000, phone_num % 10000, it->second);
            }
        }
    }
    
    return 0;
}
