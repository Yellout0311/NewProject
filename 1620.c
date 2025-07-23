#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    int number;
} Pokemon;

// qsort용 비교 함수
int compare(const void *a, const void *b) {
    Pokemon *pa = (Pokemon *)a;
    Pokemon *pb = (Pokemon *)b;
    return strcmp(pa->name, pb->name);
}

// 이진 탐색 함수
int binary_search(Pokemon arr[], int n, char *target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(target, arr[mid].name);
        
        if (cmp == 0) {
            return arr[mid].number;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 포켓몬 이름을 저장할 배열 (번호로 접근)
    char pokemon_names[100001][21];
    
    // 포켓몬 구조체 배열 (이름으로 검색)
    Pokemon pokemons[100001];
    
    // 포켓몬 정보 입력
    for (int i = 1; i <= n; i++) {
        scanf("%s", pokemon_names[i]);
        strcpy(pokemons[i-1].name, pokemon_names[i]);
        pokemons[i-1].number = i;
    }
    
    // qsort로 이름순 정렬
    qsort(pokemons, n, sizeof(Pokemon), compare);
    
    // 질문 처리
    for (int i = 0; i < m; i++) {
        char query[21];
        scanf("%s", query);
        
        // 숫자인지 확인
        if (query[0] >= '1' && query[0] <= '9') {
            int num = atoi(query);
            printf("%s\n", pokemon_names[num]);
        } else {
            // 이름으로 검색 (이진 탐색)
            int result = binary_search(pokemons, n, query);
            printf("%d\n", result);
        }
    }
    
    return 0;
}