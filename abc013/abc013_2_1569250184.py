a, b = map(int, open(0).read().split())
if abs(a-b) >= 5:
    print(10-abs(a-b))
else:
    print(abs(a-b))