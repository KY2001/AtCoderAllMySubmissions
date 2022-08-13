import string
C =input()

t = list(string.ascii_letters)
for i in range(len(t)):
    if t[i] == C:
        print(t[i+1])


