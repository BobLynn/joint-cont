#----------------now we turn to "numpy"------------------

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

c = 10*np.sin(a)            #too complicated,no explain XD
print(c)
c = 0

print (b < 3)

#---------------------------------------------------------
a = np.array([[2,0],[0,2]])             #now we change into 2 of 2 matrix
b = np.arange(4).reshape((2,2))         #[0,1]
                                        #[2,3]
print(a)
print(b)

