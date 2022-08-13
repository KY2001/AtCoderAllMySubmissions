import math
S = sorted(list(input())); N = int(input())
print(S[math.ceil(N/5)-1]+S[N-1-5*(math.ceil(N/5)-1)])
