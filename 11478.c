#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
    char s[1001];
    char (*substrings)[1001];
    int totalCount = 0;
    int uniqueCount = 0;
    int len;

    scanf("%s",s);
    len = strlen(s);

    totalCount = len * (len + 1) / 2;

    substrings = (char(*)[1001])malloc(totalCount * 1001 * sizeof(char));

    int idx = 0;

    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            strncpy(substrings[idx], s + i, j - i + 1);
            substrings[idx][j - i + 1] = '\0';
            idx++;
        }
    }

    qsort(substrings, totalCount, 1001, compare);

    uniqueCount = 1;
    for(int i = 1; i < totalCount; i++){
        if(strcmp(substrings[i], substrings[i-1]) != 0){
            uniqueCount++;
        }
    }
    printf("%d\n", uniqueCount);

    free(substrings);
    return 0;
}
