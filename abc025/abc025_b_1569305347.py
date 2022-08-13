N,A,B = map(int,input().split())
distance = 0
for i in range(N):
    s,d = map(str,input().split())
    d = int(d)
    if s == "West":
        if d < A:
            distance -= A
        elif d > B:
            distance -= B
        else:
            distance -= d
    else:
        if d < A:
            distance += A
        elif d > B:
            distance += B
        else:
            distance += d
if distance < 0:
    print("West",-distance)
elif distance > 0:
    print("East",distance)
else:
    print(0)