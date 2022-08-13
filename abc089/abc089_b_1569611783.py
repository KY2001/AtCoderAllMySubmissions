N = int(input())
S = list(map(str,input().split()))
S = set(S)
if len(S) == 3:
    print("Three")
else:
    print("Four")