/*************************************************************************
    > File Name: 1007.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon May  6 12:11:31 2019
 ************************************************************************/

#include <stdio.h>

typedef struct DNA
{
    char content[50];
    int reverse_count;
} DNA;

int calc_reverse_count(const DNA * dna, int length)
{
    int count = 0;
    int i, j;
    
    for (i = length - 1; i >= 0; i--) {
        for (j = i + 1; j < length; j++) {
            if (dna->content[i] > dna->content[j]) {
                count ++;
            }
        }
    }
    return count;
}

void sort_dna(DNA ** dna, int number)
{
    int i, j;
    DNA * tmp;
    
    for (i = 0; i < number; i ++) {
        for (j = i + 1; j < number; j++) {
            if (dna[i]->reverse_count > dna[j]->reverse_count) {
                tmp = dna[i];
                dna[i] = dna[j];
                dna[j] = tmp;
            }
        }
    }
}

int main(int argc, char * argv[])
{
    int length, number, i;
    scanf("%d %d", &length, &number);
    
    DNA * dna = new DNA[number];
    DNA ** sorted_array = new DNA *[number];
    
    for (i = 0; i < number; i++) {
        scanf("%s", dna[i].content);
        dna[i].reverse_count = calc_reverse_count(&dna[i], length);
        sorted_array[i] = &dna[i];
    }
    
    sort_dna(sorted_array, number);
    
    for (i = 0; i < number; i++) {
#if defined(DEBUG)
        printf("%s:%d\n", sorted_array[i]->content, sorted_array[i]->reverse_count);
#else
        printf("%s\n", sorted_array[i]->content);
#endif
    }
    
    delete [] dna;
    delete [] sorted_array;
    
    return 0;
}
