t=int(input())
for i in range(t):
    s1=input()
    l1=list(s1)
    len1=len(l1)
    s1=set(l1)
    les1=len(s1)
    if(len1!=les1):
        print("No")
    else:
        l2=[0]*26
        for i in l1:
            c=ord(i)-97
            l2[c]=1
        ind1=l2.index(1)
        count1=[]
        
        count1=l2[ind1:ind1+len1]
        if(count1.count(1)==len1):
            print("Yes")
        else:
            print("No")
