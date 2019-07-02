#------------now we're going to loop space-----------

#------------we start from "while"------------

a_number = 0
while a_number < 10:
    print(a_number)
    a_number = a_number + 1     #output 0~9

# while True:
#     print("I'm a truman!")    #infinity while loop
print("")

condition = 10
while condition:
    print(condition)
    condition -= 1
print("")

a = range(10)
while a:
    print(a[-1])
    a = a[:len(a)-1]
print("")

#----------now turn to "for"!----------
example_list = [1,1,4,5,1,4]
for i in example_list:
    print(i)
print("")

example_list = [1,1,4,5,1,4]
for i in example_list:
    print(i)
    print("inner of for\n")
print("outer of for")
print("")

for i in range(1,10):
    print(i)                    #[1,10), so it will print 1~9
print("")

for i in range(0,13,5):
    print(i)
print("")

#--------type "list,tuple,dict,set" output---------

tup = ('python', 2.7, 64)       #tuple
for i in tup:
    print(i)
print("")

dic = {}                        #dict
dic['lan'] = 'python'
dic['version'] = 3.0
dic['platform'] = 64
for key in dic:
    print(key,dic[key])
print("")

s = set(['python','python2','python3','python'])
for item in s:
    print(item)                 #set
print("")

# define a Fib class
class Fib(object):
    def __init__(self, max):
        self.max = max
        self.n, self.a, self.b = 0, 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.n < self.max:
            r = self.b
            self.a, self.b = self.b, self.a + self.b
            self.n = self.n + 1
            return r
        raise StopIteration()

# using Fib object
for i in Fib(5):
    print(i)
print("")

def fib(max):
    a, b = 0, 1
    while max:
        r = b
        a, b = b, a+b
        max -= 1
        yield r

# using generator
for i in fib(5):
    print(i)
print("")
