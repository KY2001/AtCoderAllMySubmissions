N,A,B,C = map(int,input().split())
ABC = [A,B,C]
l = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    if l[i]-10 <= A <= l[i]+10:
        ans += abs(l[i]-A)
        del l[i]
        del ABC[0]
        N -= 1
    elif l[i]-10 <= B <= l[i]+10:
        ans += abs(l[i]-B)
        N -= 1
        del ABC[1]
        del l[i]
    elif l[i]-10 <= C <= l[i]+10:
        ans += abs(l[i]-C)
        del l[i]
        N -= 1
        del ABC[2]
