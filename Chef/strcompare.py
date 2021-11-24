t = int(input())
for i in range(t):
    n = int(input())

    a = input()
    b = input()

    c = 0
    for i in range(n):
        if(ord(a[i]) < ord(b[i])):
            c += i+1

    print(c)
