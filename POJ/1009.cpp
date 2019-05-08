/*************************************************************************
    > File Name: 1009.cpp
    > Author: sudoku.huang
    > Mail: sudoku.huang@gmail.com 
    > Created Time: Mon May  6 15:39:44 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

const int size = 1000;

typedef struct pixel
{
    int pos;
    int code;
} pixel;

int input_pairs[size][2];
pixel output_pixel[size * 8];

int get_value(int pos)
{
    int i = 0, p = 0;

    while (p < pos) {
        p += input_pairs[i ++][1];
    }
    
    return input_pairs[i - 1][0];
}

int get_code(int pos, int width, int total)
{
    int code = get_value(pos);
    int max_abs = 0;

    int row = (pos - 1) / width;
    int col = (pos - 1) % width;
    
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            int neigbour = i * width + j;
            
            if (i < 0 || j < 0 || j >= width || neigbour >= total ||
                neigbour == pos - 1) {
                continue;
            }
            
            int tcode = get_value(neigbour + 1);
            if (max_abs < abs(tcode - code)) {
                max_abs = abs(tcode - code);
            }
        }
    }
    
    return max_abs;
}

int cmp(const void * a, const void * b)
{
    pixel * x = (pixel *)a;
    pixel * y = (pixel *)b;
    
    return x->pos - y->pos;
}

int main(int argc, char * argv[])
{
    int width, value, count;
    
    while (scanf("%d", &width) && width != 0) {
        
        int k = 0, total = 0, pos = 0;
        
        while (scanf("%d%d", &value, &count) && count != 0) {
            input_pairs[k][0] = value;
            input_pairs[k][1] = count;
            
            total += count;
            k ++;
        }
        
        int pair_count = k;
        
        //1. output width
        printf("%d\n", width);
        
        pos = 1;
        k = 0;
        
        for (int p = 0; p <= pair_count; p ++) {
            int row = (pos - 1) / width;
            int col = (pos - 1) % width;
            
            for (int i = row - 1; i <= row + 1; i ++) {
                for (int j = col - 1; j <= col + 1; j ++) {
                    int neigbour = i * width + j;
                    
                    if (i < 0 || j < 0 || j >= width || neigbour >= total) {
                        continue;
                    }
                    
                    output_pixel[k].pos = neigbour + 1;
                    output_pixel[k].code = get_code(neigbour + 1, width, total);
                    k ++;
                }
            }
            
            pos += input_pairs[p][1];
        }
        
        //sort
        qsort(output_pixel, k ,sizeof(pixel), cmp);
        
        pixel * tmp = &output_pixel[0];
        for (int i = 0; i < k; i++) {
            if (tmp->code == output_pixel[i].code) {
                continue;
            }
            
            printf("%d %d\n", tmp->code, output_pixel[i].pos - tmp->pos);
            tmp = &output_pixel[i];
        }
        printf("%d %d\n", tmp->code, total - tmp->pos + 1);
        printf("0 0\n");
    }
    
    printf("0\n");
    
    return 0;
}
