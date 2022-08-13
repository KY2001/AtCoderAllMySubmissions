S = list(input())
T = list(input())
s = 0
ss = set("atcoder")
for i in range(len(S)):
    if S[i] != "@" and T[i] != "@" and S[i] != T[i]:
        print("You will lose")
        break
    else:
        if S[i] == "@" and T[i] != "@":
            if T[i] not in ss:
                print("You will lose")
                break
            else:
                if i == len(S) - 1:
                    print("You can win")
        elif T[i] == "@" and S[i] != "@":
            if S[i] not in ss:
                print("You will lose")
                break
            else:
                if i == len(S) - 1:
                    print("You can win")
        else:
            if i == len(S) - 1:
                print("You can win")
