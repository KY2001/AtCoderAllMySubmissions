S = list(input())
T = list(input())
a = [1 for i in range(3) if S[i] == T[i]]
print(sum(a))
