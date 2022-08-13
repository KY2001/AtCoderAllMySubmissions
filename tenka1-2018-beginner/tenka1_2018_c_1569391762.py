from collections import deque
N = int(input())
A = deque(sorted([int(input()) for _ in range(N)]))
B = deque()
B.append(A.pop())
for i in range(N-1):
    if (i//2)%2 == 0:
        if abs(A[0] - B[0]) >= abs(A[0] - B[-1]):
            B.appendleft(A.popleft())
        else:
            B.append(A.popleft())
    else:
        if abs(A[-1] - B[0]) >= abs(A[-1] - B[-1]):
            B.appendleft(A.pop())
        else:
            B.append(A.pop())
C = list(B)
s = 0
for i in range(N-1):
    s += abs(C[i]-C[i+1])
print(s)