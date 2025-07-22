#include<stdio.h>

int main(){
    int N;
    char a[51][51], output[51];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", a[i]);     
    }
    for(int j = 0; j < 51; j++){
        int check = 1;
        for(int k = 1; k < N; k++)
            if(a[k][j] != a[0][j])
                check = 0;
        if(check)
            output[j] = a[0][j];
        else 
            output[j] = '?';
    }

    printf("%s", output);

    return 0;
}