import sysinput = sys.stdin.readline

s = input()
t = input()

dp = [[0 for _ in range(len(s) + 10)] for _ in range(len(s) + 10)]

for i in range(1, len(s)):
    for l in range(1, len(t)):
        if s[i - 1] == t[l - 1]:
            dp[i][l] = max(max(dp[i - 1][l - 1] + 1, dp[i][l - 1]), dp[i - 1][l])
        else:
            dp[i][l] = max(dp[i][l - 1], dp[i - 1][l])
length = dp[len(s) - 1][len(t) - 1]
if length == 0:
    print("")
else:
    ans = ' '
    i = len(s) - 1
    l = len(t) - 1
    while i > 0 and l > 0:
        if dp[i][l] == dp[i - 1][l - 1] + 1:
            ans = s[i - 1] + ans
            i -= 1
            l -= 1
        elif dp[i-1][l] == dp[i][l]:
            i -= 1
        elif dp[i][l-1] == dp[i][l]:
            l -= 1
    print(ans)
