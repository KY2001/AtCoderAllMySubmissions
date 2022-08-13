S = list(input())
if len(S)%2 == 0:
    del S[-1]
    del S[-1]
    for i in range(len(S)):
        if S[0:(len(S))//2] == S[(len(S))//2::]:
            print(len(S))
            break
        else:
            del S[-1]
            del S[-1]
else:
    del S[-1]
    for i in range(len(S)):
        if S[0:(len(S))//2] == S[(len(S))//2::]:
            print(len(S))
            break
        else:
            del S[-1]
            del S[-1]