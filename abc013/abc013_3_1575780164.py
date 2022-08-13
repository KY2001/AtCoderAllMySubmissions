N,H = map(int,input().split())
A,B,C,D,E = map(int,input().split())
ans = 0
for i in range(N):
    if H - E > 0:
        H -= E
    elif H + D - E <= 0 and H + B - E > 0 and 2*C > A:
        H += B
        ans += A
    elif D/C >= B/A:
        H += D
        ans += C
    else:
        H += B
        ans += A
print(ans)