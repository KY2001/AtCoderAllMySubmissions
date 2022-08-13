import string
a = set(string.ascii_lowercase)
S = input()
if sorted(list(set(S))) == list(string.ascii_lowercase):
    print("None")
else:
    for i in set(S):
        if i in a:
            a.remove(i)
    print(sorted(list(a))[0])