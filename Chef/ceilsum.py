import math
t=int(input())
for i in range(t):
    a,b=map(int,input().split(" "))

    if(a==b):
        tot=0

    elif(a<b):
        x=a+1
        tot=math.ceil((b-x)/2)+math.ceil((x-a)/2)

    elif(b<a):
        x=b+1

        tot=math.ceil((b-x)/2)+math.ceil((x-a)/2)

    print(tot)