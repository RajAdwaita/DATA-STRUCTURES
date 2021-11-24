# import numpy as np
# l=list(map(int,input().split(" ")))
# print(np.gcd.reduce(l))
def find_gcd(x, y):
    while(y):
        x, y = y, x % y

    return x



t=int(input())
ans=0
for i in range (0,t):
    n=int(input())
    nums=list(map(int,input().split(" ")))
    a=b=h=s=[0]*n
    ss=0
    for i in nums:
        ss+=i

    if n==1:
        print("1")
        continue



    a[0]=nums[0]
    b[n-1]=nums[n-1]
    for i in range(1,n):
        a[i]=find_gcd(a[i-1],nums[i])
    for i in range(n-2,-1,-1):
        b[i]=find_gcd(b[i+1],nums[i])

    h[0]=b[1]
    h[n-1]=a[n-2]

    for i in range(1,n-1):
        h[i]=find_gcd(a[i-1],b[i+1])


    for i in range(0,n):
        s[i]=int(((ss-nums[i]+h[i])//h[i]))



    ans=s[0]
    for i in s:
        if i<ans:
            ans=i

    print(ans)



#     num1=a[0]
#     num2=a[1]
#     h=find_gcd(num1,num2)
#     for i in range(2,len(a)):
#         h=find_gcd(h,a[i])


#     # print(a)
#     # h=np.gcd.reduce(a)
#     m1=max(a)
#     pos=a.index(m1)
#     a[pos]=h
#     ss=0
#     ss=sum(a)
#     print(ss//h,end="\n")
    # for i in a:
    #     d=i//h;
    #     ss+=d
    # print(ss,end="\n")







