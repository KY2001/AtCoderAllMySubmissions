abc = list(map(int,open(0).read().split()))
abc2 = abc.sorted(reverse = True)
for _ in range(3):
    for i, score in enumerate(abc2):
        if abc[_] == score:
            print(i + 1)

