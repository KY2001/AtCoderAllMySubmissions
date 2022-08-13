import string
a = set(string.ascii_lowercase)
S = input()
if sorted(list((S))) == list(string.ascii_lowercase):
    print("None")
else:
    for i in set(S):
        if i in S:
            a.remove(i)
    print(sorted(list(a))[0])