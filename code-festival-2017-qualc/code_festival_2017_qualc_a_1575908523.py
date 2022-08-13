S = list(input())
for i in range(len(S)-1):    
    if S[i] == "A" and S[i+1] == "C":
        print("Yes")
        import sys
        sys.exit()
print("No")