X = list(input())
for i in range(len(X)):
    if not X:
        print("YES")
        break
    elif X[i-1] == "c":
        continue
    else:
        if X[i] == "o" or X[i] == "k" or X[i] == "u":
            if i == len(X)-1:
                print("YES")
                break
        elif X[i] == "c" and X[i+1] == "h":
            if i == len(X)-2:
                print("YES")
                break
        else:
            print("NO")
            break


