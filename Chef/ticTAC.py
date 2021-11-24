t=int(input())
for i in range(t):
    final=[]
    count=0

    n,m,k=map(int,input().split())
    l1=list(map(int,input().split()))

    s=set(l1)

    for i in s:
        temp=l1.count(i)

        if(temp>1 and i<=n):
            count+=1
            final.append(i)
    # print(count,end=" ")
    final.insert(0,count)
    for i in final:
        print(i,end=" ")
    print(end="\n")


