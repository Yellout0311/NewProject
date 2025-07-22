#include<stdio.h>

int main(){
    int tmp;

    int a[6];
    for(int i = 0; i<5 ; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(a[i] < a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    printf("%d\n",(a[1]+a[2]+a[3]+a[4]+a[5])/5);
    printf("%d\n", a[3]);
    

    return 0;
} 