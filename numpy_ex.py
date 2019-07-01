#----------------now we turn to "numpy"------------------
print("----------------矩陣的基本運算----------------------------\n")
import numpy as np
a = np.array([1,2,3,4])     #as you can see 1 of 4 matrix
b = np.arange(4)            #[0,1,2,3]

c = a - b
print(c)                    #[1-0,2-1,3-2,4-3]
c = 0

c = a + b
print(c)
c = 0                       #[0+1,1+2,2+3,3+4]

c = a * b                   #[0*1,1*2,2*3,3*4]
print(c)
c = 0

c = b ** 2                  #[0^2,1^2,2^2,3^2]
print(c)
c = 0
print("")

c = 10*np.sin(a)            #too complicated,no explain XD
print(c)
c = 0

print (b < 3)
print("")
print("---------------2x2矩陣相乘----------------------------------\n")
a = np.array([[2,0],[0,2]])             #now we change into 2 of 2 matrix
b = np.arange(4).reshape((2,2))         #[0,1]
                                        #[2,3]      note:reshape

print(a)                                #[2,0]
                                        #[0,2]
print(b)
print("")

c_dot = np.dot(a,b)
print(c_dot)
c_dot_2 = a.dot(b)
print(c_dot_2)                          #same
print("")

print("----------------------矩陣內的求和以及數值比較-----------------\n")
import numpy as np

a = np.random.random((2,4))             #make random numbers
print(a)

np.sum(a)                               #sum of the number
print(a)
print("")

np.min(a)                               #minimum in the matrix
print(a)
print("")

np.max(a)                               #maximum in the matrix
print(a)
print("")

print("a = ",a)


print("--------------------矩陣內的求和與比較-----------------------\n")
print("sum = ",np.sum(a,axis = 1))      #sum of the column numbers
print("min = ",np.min(a,axis = 0))      #minimum of the row
print("max = ",np.max(a,axis = 1))      #maximum of the column