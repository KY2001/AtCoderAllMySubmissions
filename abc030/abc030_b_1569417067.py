n, m = map(int, input().split())
s = abs(((((n + (m / 60)) % 12) / 12) - (m / 60))) * 360
print(min(s, 360 - s))