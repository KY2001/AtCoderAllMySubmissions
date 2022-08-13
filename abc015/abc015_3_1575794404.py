N,K = map(int,input().split())
T = [list(map(int,input().split())) for i in range(N)]

def XOR(Q, V):
    if Q == N and V == 0:
        return False
    for i in range(K):
        if XOR(Q+1, V^T[Q][i]):
            return True
    return False

print(XOR(0,0))

