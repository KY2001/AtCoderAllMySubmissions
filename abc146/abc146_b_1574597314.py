N = int(input())
S = list(input())
import string
A = list(string.ascii_uppercase + string.ascii_uppercase)
for i in range(len(S)):
    for l in range(1000):
        if S[i] == A[l]:
            S[i] = A[l+N]
            break
print("".join(S))

