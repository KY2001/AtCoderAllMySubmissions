import sys
X = int(input())

for i in range(1, 10 ** 3 + 10):
    if 100*i <= X <= 105*i:
        print("1")
        sys.exit()
print("0")