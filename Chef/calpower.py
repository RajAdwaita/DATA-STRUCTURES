t = int(input())
for i in range(0, t):
    ss = 0
    s = input()
    s = list(s)
    s.sort()
    # print(s)

    for i in range(0, len(s)):
        ss += (ord(s[i])-96)*(i+1)

    print(ss)

    # for j in range(0,len(s)):
