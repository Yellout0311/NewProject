#include<stdio.h>

int main(){
    int a,b,c;
    char* output[1000];
    int j = 0;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if((a == 0) && (b == 0) && (c == 0)){
            break;
        } 
        
        // 삼각형 조건 확인 (가장 긴 변 < 나머지 두 변의 합)
        int max_side = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
        int sum_other = a + b + c - max_side;
        
        if(max_side >= sum_other) {
            output[j] = "Invalid";  // 또는 문제에서 요구하는 출력
            j++;
        } else if((a == 0) && (b == 0) && (c == 0)){
            break;
        } else if((a == b) && (b == c)) {
            output[j] = "Equilateral";
            j++;
        } else if((c == b) && (a != b)) {
            output[j] = "Isosceles";
            j++;
        } else if((a == b) && (a != c)) {
            output[j] = "Isosceles";
            j++;
        } else if((a == c) && (a != b)) {
            output[j] = "Isosceles";
            j++;
        }else{
            output[j] = "Scalene";
            j++;
        }
    }
    for(int i = 0; i < j; i++){
        printf("%s\n", output[i]);
    }
    return 0;
}