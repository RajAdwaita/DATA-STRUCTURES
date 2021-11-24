t=int(input())
s=input()
s=s.upper();
d={}
l1=[]
l2=[]
l3=[]
count=0
for i in range(0,len(s),2):
    l1.append(s[i])
    l2.append(s[i+1])

for i in range(0,len(l1)):
    if(l1[i]!=l2[i]):
        count+=1
        l3.append(l1[i])
    






