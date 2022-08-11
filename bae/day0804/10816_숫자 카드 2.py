from collections import defaultdict

store = defaultdict(int)

N = int(input())
cards = list(map(int, input().split()))
for card in cards:
    store[card] += 1

M = int(input())
numbers = list(map(int, input().split()))
for number in numbers:
    print(store[number], end=' ')