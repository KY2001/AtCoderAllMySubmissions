S = list(input())
SS = list("CODEFESTIVAL2016")
print(sum([1 for i in range(len(S)) if S[i] != SS[i]]))