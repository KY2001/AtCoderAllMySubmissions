ccc1 = list(input())
ccc2 = list(input())
for i, _ in enumerate(ccc1):
    if _ != ccc2[-i-1]:
        print("NO")
        break
    if i == 2:
        print("YES")
        