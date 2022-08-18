import sys
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
dists = [[0] * (N+1) for _ in range(N+1)]
for fr in range(1, N):
    dist = list(map(int, input().split()))
    i = 0

    for to in range(fr+1, N+1):
        dists[fr][to] = dist[i]
        dists[to][fr] = dist[i]
        i += 1

canRestore = True
for i in range(N):
    for j in range(N):
        if dists[i][j] != dists[j][i]:
            canRestore = False

visited = [[False] * (N+1) for _ in range(N+1)]
if canRestore:
    print(1)
    cnt = 0
    for s in range(1, N+1):
        for e in range(s+1, N+1):
            if visited[s][e]:
                continue
            if dists[s][e] != 0:
                print(s, e, dists[s][e])
                visited[s][e] = visited[e][s] = True
                cnt += 1
    # 간선의 갯수만큼 출력
    for s in range(1, N+1):
        for e in range(s+1, N+1):
            if visited[s][e]:
                continue
            visited[s][e] = visited[e][s] = True
            cnt += 1
            if cnt == M:
                break
        if cnt == M:
            break

else:
    print(0)
