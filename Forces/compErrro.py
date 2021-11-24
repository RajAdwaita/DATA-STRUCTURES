t=int(input())

a=list(map(int,input().split(' ')))
b=list(map(int,input().split(' ')))
c=list(map(int,input().split(' ')))

# for i in b:
#     if i  in a:
#         a.remove(i)

# print(a[0])

# for i in c:
#     if( i  in b):
#         b.remove(i)
# print(b[0])
    
print(sum(a)-sum(b))
print(sum(b)-sum(c))