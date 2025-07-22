#include<stdio.h>
#define MAX 100000
int main(){
    int n;
    scanf("%d", &n);

    if(n == 1){
        printf("0\n");
        return 0;
    }

    int x[n], y[n];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    int minx=x[0], maxx=x[0];
    int miny=y[0], maxy=y[0];
    
    for(int i = 1; i < n; i++){
        if(x[i] < minx) minx = x[i];
        if(x[i] > maxx) maxx = x[i];
        if(y[i] < miny) miny = y[i];
        if(y[i] > maxy) maxy = y[i];
    }
    
    printf("%d\n", (maxx - minx) * (maxy - miny));

    return 0;
}