a,b,x = map(int,input().split())
xx = a%x
print(int(((b-a)-xx)/x+1))
