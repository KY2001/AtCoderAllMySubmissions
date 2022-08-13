a = int(input())
b = list(map(int, input().split()))
c = sorted(b)
d = c[(a//2)]-c[(a//2)-1]
print(d)