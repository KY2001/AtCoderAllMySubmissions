ABC = list(map(list,input().split()))
for i in range(2):
    if ABC[i][-1] != ABC[i+1][0]:
        print("NO")
        break
    if i == 1:
        print("YES")



