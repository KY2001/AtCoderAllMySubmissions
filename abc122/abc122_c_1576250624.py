N, Q = map(int, input().split())
S = list(input())
T = [0]
s = 0
for i in range(N-1):
    if S[i] == 'A' and S[i+1] == 'C':
        s += 1
        T.append(s)
    else:
        T.append(s)
for i in range(Q):
    l, r = map(int, input().split())
    print(abs(T[l-1]-T[r-1]))
