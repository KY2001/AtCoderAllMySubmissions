S = list(input())
for i in range(len(S)):
    S[i] = int(S[i])
A = 10*S[0] + S[1]
B = 10*S[2] + S[3]
if (A == 0 or A >= 13) and (B == 0 or B >= 13):
    print("NA")
elif A == 0 or A >= 13:
    print("YYMM")
elif B == 0 or B >= 13:
    print("MMYY")
else:
    print("AMBIGUOUS")

