A,B,C,D = map(int,input().split())
if A > D or C > B:
    print(0)
elif C<A<B<D:
    print(B-A)
elif A<C<D<B:
    print(D-C)
elif A < C:
    print(B-C)
else:
    print(D-A)
