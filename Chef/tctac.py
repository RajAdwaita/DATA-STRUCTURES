arr=["adwaita","amvrin",'modak']


t=[]

for i in range(len(arr)):
    temp=list(arr[i])
    t+=temp
s=set(t)
print(s)