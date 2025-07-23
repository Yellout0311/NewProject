import sys
input = sys.stdin.readline #input()보다 빠름

n, m = map(int, input().split())

num_to_name = [''] #1번부터 시작하기 위해 빈 문자열 추가

name_to_num = {} #이름 -> 번호 (딕셔너리)

for i in range(1, n+1):
    name = input().strip()
    num_to_name.append(name)
    name_to_num[name] = i

for _ in range(m):
    query = input().strip()

    if query.isdigit(): #숫자인지 확인
        print(num_to_name[int(query)])
    else:
        print(name_to_num[query])