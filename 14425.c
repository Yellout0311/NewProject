#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_SIZE 100003

typedef struct Node{
    char str[501];
    struct Node* next;
}Node;

Node* hash_table[HASH_SIZE]; //해시테이블에는 node주소만 들어가는 거임

unsigned int hash(char* str){
    unsigned int hash = 0;
    while(*str){
        hash = hash * 31 + *str++; //여기서는 해당 문자의 아스키값으로 계산을 하고, 포인터를 다음 문자로 넘김
        //31은 소수이면서 컴퓨터가 빠르게 계산할 수 있는 수임
        //소수를 사용하면 해시 충돌이 적어짐.!
    }
    return hash % HASH_SIZE;
}

void insert(char* str){
    unsigned int idx = hash(str);
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->str, str);
    new_node->next = hash_table[idx]; //기존 첫 번째 노드를 가리킴
    hash_table[idx] = new_node; //해시테이블이 새 노드를 가리키도록 변경 
}
/* 메모리에서 실제로 일어나는 일 
처음 상태:
hash_table[5] = NULL

"apple" 추가:
heap: [Node1: "apple", next→NULL] ← hash_table[5]

"dog" 추가 (같은 해시값 5):
heap: [Node1: "apple", next→NULL]
      [Node2: "dog", next→Node1] ← hash_table[5]

"cat" 추가 (같은 해시값 5):
heap: [Node1: "apple", next→NULL]
      [Node2: "dog", next→Node1]  
      [Node3: "cat", next→Node2] ← hash_table[5]
*/
int search(char* str){
    unsigned int idx = hash(str);
    Node* curr = hash_table[idx];
    while(curr){
        if(strcmp(curr->str, str) == 0) return 1;
        curr = curr->next;
    }
    return 0;
}

int main(){
    int n, m, cnt =0;
    char str[501];
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i< n; i++){
        scanf("%s", str);
        insert(str);
    }
    for(int i = 0; i < m; i++){
        scanf("%s", str);
        if(search(str)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}