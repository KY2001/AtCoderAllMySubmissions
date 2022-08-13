N = int(input())
C = N/1.08
if C%1 == 1:
    print(int(C))
else:
    C -= (C%1)
    D = C+1
    if C*1.08-((C*1.08)%1) != N and D*1.08-((D*1.08)%1) != N:
        print(":(")
    elif C*1.08-((C*1.08)%1) == N:
        print(int(C))
    else:
        print(int(D))
