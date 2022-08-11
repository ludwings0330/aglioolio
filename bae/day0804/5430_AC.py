from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
while T:
    T -= 1
    query = list(input())
    N = int(input())
    isError = False

    arr = input()[1:-1].split(',')
    if arr[-1] == '':
        arr.pop()
    dq = deque(arr)
    direction = 0 # 0 : forward, 1 : reverse

    for q in query:
        if q == 'R':
            direction = (direction + 1) % 2
        if q == 'D':
            if dq:
                if direction == 0:
                    dq.popleft()
                elif direction == 1:
                    dq.pop()
            else:
                isError = True
                break

    if isError:
        print("error")
    else:
        ans = list(dq) if direction == 0 else list(dq)[::-1]
        print('[', end='')
        print(*ans, sep=',', end=']\n')