a = [1,1,4,5,1,4]

a.append(0)             #append a number 0
print(a)                #a = [1,1,4,5,1,4,0]

a = [1,1,4,5,1,4]
a.insert(1,0)           #append a number 0 after 1
print(a)                #a = [1,0,1,4,5,1,4]

a = [1,1,4,5,1,4]
a.remove(1)             #remove 1
print(a)
print("")
a = [1,1,4,5,1,4]
print(a[1])             #1
print(a[-1])            #4
print(a[0:3])           #[1,1,4]
print(a[5:])            #[4]
print(a[-3:])           #[5,1,4]
print("")
print(a.index(4))       #2
print(a.count(1))       #3
print("")
a.sort()                #sort from small to large
print(a)
a.sort(reverse=True)    #sort from large to small