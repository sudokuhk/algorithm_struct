#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(const char * const s, int * next, int n)
{
    int j = 0, k = -1;

    memset(next, 0x00, sizeof(int) * n);
    next[0] = -1;

    while (j < n - 1) {
        if (k == -1 || s[j] == s[k]) {
            ++j;
            ++k;
            if (s[j] == s[k]) {
                next[j] = next[k];
            } else {
                next[j] = k;
            }
        } else {
            //if not match, do KMP self.
            k = next[k]; 
        }
    }
}

//find s1 in s.
int KMP(const char * const s, const char * const s1)
{
    int i, j, len_s, len_s1;

    if (s == NULL || s1 == NULL) {
        return -1;
    }

    len_s = strlen(s);
    len_s1 = strlen(s1);
    int * next = (int *)malloc(sizeof(int) * len_s1);
    get_next(s1, next, len_s1);
    for (i = 0; i < len_s1; i++) {
        printf("%3d", next[i]);
    }
    printf("\n");

    i = 0, j = 0;
    while (i < len_s && j < len_s1) {
        if (j == -1 || s[i] == s1[j]) {
            i ++;
            j ++;

            printf("i = %3d, j = %3d\n", i, j);
        } else {
            printf("j = %3d, next[j] = %3d\n", j, next[j]);
            j = next[j];
        }
    }
    free(next);

    if (j == len_s1) {
        return i - j;
    } else {
        return -1;
    }
}

int main(int argc, char * argv[])
{
    int pos = KMP(argv[1], argv[2]);
    printf("KMP = %d\n", pos);
    return 0;
}
