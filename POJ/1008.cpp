/*************************************************************************
 > File Name: 1008.cpp
 > Author: sudoku.huang
 > Mail: sudoku.huang@gmail.com 
 > Created Time: Mon May  6 12:57:40 2019
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>

const char * haab_month[19] = {
    "pop",
    "no",
    "zip",
    "zotz",
    "tzec",
    "xul",
    "yoxkin",
    "mol",
    "chen",
    "yax",
    "zac",
    "ceh",
    "mac",
    "kankin",
    "muan",
    "pax",
    "koyab",
    "cumhu",
    "uayet",
};

const char * another_month[21] = 
{
    "imix",
    "ik",
    "akbal",
    "kan",
    "chicchan",
    "cimi",
    "manik",
    "lamat",
    "muluk",
    "ok",
    "chuen",
    "eb",
    "ben",
    "ix",
    "mem",
    "cib",
    "caban",
    "eznab",
    "canac",
    "ahau",
};

static int hash(const char * s)
{
    int h = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        h += s[i];
    }
    
    return h;
}

int main(int argc, char * arg[])
{
    int i;
    std::map<int, int> month_map;    
    
    for (i = 0; i < 19; i++) {
#if defined(DEBUG)
        printf("haab_month[%d] = %s:%d\n", i, haab_month[i], hash(haab_month[i]));       
#endif
        month_map[hash(haab_month[i])] = i;
    }
    
#if defined(DEBUG)  
    printf("count:%d\n", month_map.size());
#endif
    
    int N;
    scanf("%d", &N);
    printf("%d\n", N);
    
    int haab_days, haab_year;
    char haab_month_input[10];
    
    while (N -- > 0) {
        scanf("%d. %s %d", &haab_days, haab_month_input, &haab_year);
        
#if defined(DEBUG)
        printf("%d, %s:%d, %d\n", haab_days, 
               haab_month_input, month_map[hash(haab_month_input)],
               haab_year);
#endif
        
        int total_days = haab_year * 365 
            + month_map[hash(haab_month_input)] * 20 
            + haab_days;
        
        int tzolkin_year = total_days/ 260;
        //total_days -= tzolkin_year * 260 + 1;
        
        int tzolkin_month = total_days % 13 + 1;
        int tzolkin_day = total_days % 20;
        
        printf("%d %s %d\n", tzolkin_month, 
               another_month[tzolkin_day], tzolkin_year);
    }
    return 0;
}
