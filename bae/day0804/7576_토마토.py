import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

C, R = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(R)]
visited = [[False] * C for _ in range(R)]

move = ((-1, 0), (1, 0), (0, -1), (0, 1))

dq = deque()

ans = -1
cnt_tomato = 0
day = 0
for r in range(R):
    for c in range(C):
        if box[r][c] == 1:
            dq.append((r, c, day))
            visited[r][c] = True
            cnt_tomato += 1

        elif box[r][c] == 0:
            cnt_tomato += 1

while dq:
    r, c, day = dq.popleft()
    cnt_tomato -= 1
    for dr, dc in move:
        nr = r + dr
        nc = c + dc

        if nr < 0 or nr >= R or nc < 0 or nc >= C:
            continue

        if visited[nr][nc] or box[nr][nc] != 0:
            continue

        visited[nr][nc] = True
        dq.append([nr, nc, day + 1])

print(day if cnt_tomato == 0 else -1)