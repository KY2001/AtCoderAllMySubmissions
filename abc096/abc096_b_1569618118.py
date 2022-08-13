A,B,C,K = map(int,open(0).read().split())
print(A+B+C+max(A,B,C)*2**K-max(A,B,C))