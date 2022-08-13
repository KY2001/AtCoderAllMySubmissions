N,T = map(int,input().split())
st = []
for i in range(N):
    s = list(map(int,input().split()))
    if s[1] <= T:
        st.append(s)
st.sort()
if st :
    print(st[0][0])
else:
    print("TLE")