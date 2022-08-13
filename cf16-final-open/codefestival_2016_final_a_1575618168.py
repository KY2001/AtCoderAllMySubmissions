import string
H, W = map(int, input().split())
ABC = string.ascii_uppercase

for i in range(H):
    LIST = list(map(str,input().split()))
    for l in range(W):
        if LIST[l] == "snuke":
            print(ABC[l]+str(i+1))