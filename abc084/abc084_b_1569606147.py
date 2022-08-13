import sys
A,B = map(int,input().split())
S = list(input())
if S[A] != "-":
    print("No")
    sys.exit()
j = [str(i) for i in range(10)]
if len(S) != len([i for i in S if i in j and i != A])+1:
    print("No")
    sys.exit()
print("Yes")

