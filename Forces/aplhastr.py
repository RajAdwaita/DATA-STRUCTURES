t=int(input())
pos=-1
for i in range(0,t):
    s=input()
    l=len(s)
    str=s
    # s=list(s)
    if('a' not in s):
        print("NO")

    else:
        l1=[]
        l2=[]
        l11=[]
        l22=[]

        pos=s.index('a')
        strl=s[0:pos]
        strr=s[(pos+1)::]
        strl=strl[::-1]

        # print(strl)
        # print(strr)
        for i  in range(0,len(strl)):
            x=ord(strl[i])-ord('a')
            l1.append(x)
        for i  in range(0,len(strr)):
            x=ord(strr[i])-ord('a')
            l2.append(x)
        l11=list(set(l1.copy()))
        l22=list(set(l2.copy()))
        # print(l11)
        # print(l22)

        # l1.sort()
        # l2.sort()
        # if(len(l1)==0 or len(l2)==0):
        #     print("NO")

        # elif (l1==l11 and l2==l22):
        #     print("YES")
        # else:
        #     print("NO")
        cl=0
        cr=0
        flag=0

        for i in range(1,l):
            if(i in l1):
                if(l1[cl]==i):
                    flag+=1
                    cl+=1
            if(i in l2):
                if(l2[cr]==i):
                    flag+=1
                    cr+=1
        if(flag==l-1):
            print("YES")
        else:
            print("NO")
        # print(flag)
            






        

