import sys
input = lambda: sys.stdin.readline().rstrip()

equation = input()
stack = ['(']

for e in equation:
    if e == '-':
        stack.append(')')
        stack.append(e)
        stack.append('(')
    else:
        stack.append(e)
stack.append(')')

ans = []
for s in stack:
    if s == '0':
        if ans[-1] == '(' or ans[-1] == '+' or ans == '-':
            continue
    ans.append(s)
print(eval(''.join(ans)))
