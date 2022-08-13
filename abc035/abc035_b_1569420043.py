S = list(input())
LR = abs(sum([1 for i in S if i == "L"]) - sum([1 for i in S if i == "R"]))
UD = abs(sum([1 for i in S if i == "U"]) - sum([1 for i in S if i == "D"]))
Q = sum([1 for i in S if i == "?"])
if input() == "1":
    print(LR+UD+Q)
else:
    if (LR+UD-Q) < 0:
        if (LR+UD-Q)%2 == 0:
            print(0)
        else:
            print(1)
    else:
        print(LR+UD-Q)