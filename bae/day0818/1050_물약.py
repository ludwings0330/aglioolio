import sys
from collections import defaultdict
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
materials = defaultdict(int)

for _ in range(N):
    name, amount = input().split()
    # 파는 재료는 중복되지 않는다
    materials[name] = int(amount)

equations = defaultdict(list)

for _ in range(M):
    name, equation = input().split("=")
    required_materials = defaultdict(int)
    for eq in equation.split("+"):
        i = 0

        while '0' <= eq[i] <= '9':
            i += 1

        material_amount = int(eq[:i])
        material_name = eq[i:]
        required_materials[material_name] += material_amount

    equations[name].append(required_materials)


dq = deque(equations.items())
visited = set()
for i in range(50*50):
    if not dq:
        break
    name, required_materials_list = dq.popleft()
    outerCanMake = False
    for required_materials in required_materials_list:
        canMake = True
        price = 0
        for material in required_materials:
            if material not in materials:
                canMake = False
                continue
            else:
                price += required_materials[material] * materials[material]
                if price > 1000000000:
                    price = 1000000001
        if canMake:
            outerCanMake = True
            materials[name] = price if materials[name] == 0 else min(materials[name], price)

    dq.append([name, required_materials_list])

if 'LOVE' not in materials and 'LOVE' not in equations:
    print(-1)
else:
    ans = materials['LOVE']
    print(ans if ans !=0 else -1)
