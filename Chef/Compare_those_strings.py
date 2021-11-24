t = int(input())
for i in range(t):
    n = int(input())

    a = input()
    b = input()

    c = 0
    for i in range(n):
        sa = 0
        sb = 0
        tt = 0

        for j in range(i, n):

            if(ord(a[j]) < ord(b[j])):
                tt += 1
                # c += i+1
        if(tt == j-1):
            c += 1

    print(c)
