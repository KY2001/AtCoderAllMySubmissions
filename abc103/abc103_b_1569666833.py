from collections import deque
import sys
S = deque(list(input()))
T = list(input())
for i in range(len(S)):
    s = S.pop()
    S.appendleft(s)
    if list(S) == T:
        print("Yes")
        sys.exit()
print("No")