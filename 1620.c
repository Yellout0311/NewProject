#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    int number;
} Pokemon;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 포켓몬 이름을 저장할 배열 (인덱스로 접근)
    char pokemon_names[100001][21];
    
    // 포켓몬 구조체 배열 (이름으로 검색하기 위해)
    Pokemon pokemons[100001];
    
    // 포켓몬 정보 입력
    for (int i = 1; i <= n; i++) {
        scanf("%s", pokemon_names[i]);
        strcpy(pokemons[i].name, pokemon_names[i]);
        pokemons[i].number = i;
    }
    
    // 이름으로 검색하기 위해 정렬용 배열 생성
    Pokemon sorted_pokemons[100001];
    for (int i = 1; i <= n; i++) {
        strcpy(sorted_pokemons[i].name, pokemons[i].name);
        sorted_pokemons[i].number = pokemons[i].number;
    }
    
    // 이름으로 정렬 (버블 정렬 사용)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (strcmp(sorted_pokemons[j].name, sorted_pokemons[j + 1].name) > 0) {
                Pokemon temp = sorted_pokemons[j];
                sorted_pokemons[j] = sorted_pokemons[j + 1];
                sorted_pokemons[j + 1] = temp;
            }
        }
    }
    
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
            int left = 1, right = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                int cmp = strcmp(query, sorted_pokemons[mid].name);
                
                if (cmp == 0) {
                    printf("%d\n", sorted_pokemons[mid].number);
                    break;
                } else if (cmp < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
    
    return 0;
}