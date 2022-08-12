import random
n=int(input("生成的数组长度:"))
L=[random.randint(1,1000) for i in range(0,n)]
L.sort()
print(str(L).replace(',',' ')[2:-1])