import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import defaultdict

graph = defaultdict(list)

N, M = map(int, input().split())
for _ in range(M):
    # A 가 B를 신뢰한다.
    A, B = map(lambda x: int(x) - 1, input().split())
    # B를 해킹하면 A로 이동할 수 있음
    graph[B].append(A)

n_of_infect = [0] * N
visited = [False] * N

stack = []
for s in range(N):
    stack.append(s)
    visited = set()
    visited.add(s)
    cnt = 1
    while stack:
        current = stack.pop()
        for next in graph[current]:
            if next not in visited:
                cnt += 1
                visited.add(next)
                stack.append(next)
    n_of_infect[s] = cnt

max_infect = max(n_of_infect)
ans = []

for i in range(N):
    if n_of_infect[i] == max_infect:
        ans.append(i+1)
print(*ans)