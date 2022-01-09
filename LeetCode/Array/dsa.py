nums = [1, 2, 3, 4, 3, 2, 4, 5, 6, 4, 3, 2]
d = {}
for i in nums:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
print(d)
