N,*H = map(int,open(0).read().split())
t = 0
h = 0
for i in H:
    if i >= h:
        t += 1
        h = i
    else:
        break
        
print(t)