import sys
input = lambda: sys.stdin.readline().rstrip()
N, K, R = map(int, input().split())
graph = [[1] * (N*N) for _ in range(N*N)]
cows = []
# graph[r1][c1][r2][c2] = False 길의 유무 확인
# 10^8 -> 메모리
for _ in range(R):
    r1, c1, r2, c2 = map(lambda x: int(x)-1, input().split())
    p1 = r1 * N + c1
    p2 = r2 * N + c2
    graph[p1][p2] = graph[p2][p1] = 0
# R = 3 , C = 3  4 <-> (1, 1) -> 값 2개로 좌표를 표현하는걸 -> 값 1개로 좌표를 표현할 수 있음
for _ in range(K):
    r, c = map(lambda x : int(x) - 1, input().split())
    cows.append(r*N + c)

move = [(1, 0), (-1, 0), (0, 1), (0, -1)]
group = [-1] * (N*N)
no = 1
for p in range(N*N):
    if group[p] != -1:
        continue

    r = p // N
    c = p % N
    group[p] = no
    stack = [[r, c]]
    while stack:
        cr, cc = stack.pop()

        for dr, dc in move:
            nr = cr + dr
            nc = cc + dc

            if 0 <= nr < N and 0 <= nc < N:
                pass
            else:
                continue
            if group[nr*N + nc] != -1:
                continue
            if graph[cr*N + cc][nr*N + nc] == 0:
                continue
            group[nr*N + nc] = no
            stack.append([nr, nc])
    no += 1

cnt = 0
for i in range(K):
    for j in range(i+1, K):
        if group[cows[i]] != group[cows[j]]:
            cnt += 1
print(cnt)
