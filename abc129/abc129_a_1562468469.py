P, Q, R =map(int, input().split())
if P+Q <= P+R and P+Q <= Q+R:
    print(P+Q)
elif P+R <= P+Q and P+R <= Q+R:
    print(P+R)
else:
    print(Q+R)