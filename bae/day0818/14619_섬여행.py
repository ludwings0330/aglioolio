import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import defaultdict

N, M = map(int, input().split())

heights = [0] + list(map(int, input().split()))
graph = defaultdict(list)

for _ in range(M):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)


def solve(current, k):
    if k == 0:
        return heights[current]

    if cache[current][k] != -1:
        return cache[current][k]

    cache[current][k] = float('inf')
    for next in graph[current]:
        cache[current][k] = min(cache[current][k], solve(next, k-1))

    return cache[current][k]


T = int(input())
cache = [[-1] * 501 for _ in range(101)]
while T:
    T -= 1
    A, K = map(int, input().split())
    # A 에서 출발하여 K 에 도착하는 최소 높이의 섬
    ans = solve(A, K)
    print(ans if  ans != float('inf') else -1)