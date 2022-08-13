A,B,K = map(int,input().split())
a = [A+i for i in range(K)]
b = [B-i for i in range(K)]
ab = a+b
ab = [i for i in ab if A <= i <= B]
ab = sorted(list(set(ab)))
for i in range(len(ab)):
    print(ab[i])
