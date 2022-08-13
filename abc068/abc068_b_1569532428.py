a = set()
for i in range(7):
    a.add(2**(i+1))
for i in range(int(input()),0,-1):
    if i in a:
        print(i)
        break