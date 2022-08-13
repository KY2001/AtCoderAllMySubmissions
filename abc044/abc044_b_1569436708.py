import sys
w = list(input())
ww = set(w)
for i in ww:
    s = 0
    for l in w:
        if i == l:
            s += 1
    if s%2 == 0:
        continue
    else:
        print('No')
        sys.exit()
print('Yes')