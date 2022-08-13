A,B = map(int,input().split())
if A == B:
  print(2*A)
else:
  print(max(2*A-1,2*B-1))