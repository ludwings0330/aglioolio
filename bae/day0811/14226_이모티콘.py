from collections import deque

S = int(input())
dq = deque()
# 화면에 표시된 이모티콘수, 클립보드에 있는 이모티콘 수, 현재시간
dq.append((1, 0, 0))

visited = [[False] * 2100 for _ in range(2100)]
visited[1][0] = True
while dq:
    s, c, time = dq.popleft()

    if s == S:
        print(time)
        break

    if s+c <= 2000 and not visited[s+c][c]:
        visited[s+c][c] = True
        dq.append((s+c, c, time+1))
    if not visited[s][s]:
        visited[s][s] = True
        dq.append((s, s, time+1))
    if s-1 >= 0 and not visited[s-1][c]:
        visited[s-1][c] = True
        dq.append((s-1, c, time+1))

    # 1. 클립보드에있는 값 복사
    # s+c, c, time+1
    # 2. 클립보드로 복사
    # s, s, time+1
    # 3. 1개 빼기
    # s-1, c, time+1
