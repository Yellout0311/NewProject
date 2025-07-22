#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max_length = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    int sum = a + b + c - max_length;

    while(1){
        if(sum > max_length){
            printf("%d", sum + max_length);
            break;
        }else{
            max_length--;
        }
    }
    return 0;
}