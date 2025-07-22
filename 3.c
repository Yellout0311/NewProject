#include<stdio.h>

int main(){
    int a,b,c;

    scanf("%d\n%d\n%d",&a,&b,&c);

    if(a+b+c == 180){
        if(a==b==c) printf("Equilateral\n");
        else if((a == b) && (a != c)) printf("Isosceles\n");
        else if((c == b) && (a != b)) printf("Isosceles\n");
        else if((a == c) && (a != b)) printf("Isosceles\n");
        else printf("Scalene\n");

    }else{
        printf("Error\n");
    }

    return 0;
}