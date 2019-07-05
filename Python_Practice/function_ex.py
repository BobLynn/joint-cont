#----------------The function area!------------------
import numpy as np
import theano.tensor as T
import theano

#----------------激勵函數-----------------
x = T.dmatrix('x')
s = 1/(1+T.exp(-x))
logistic = theano.function([x],s)
print(logistic([[0,1],[-2,-3]]))
print("")

#----------多輸入/輸出的function-----------
a,b = T.dmatrices('a','b')

diff = a - b                        #差
abs_diff = abs(diff)                #絕對值
diff_squared = diff ** 2            #平方差
f = theano.function([a,b],[diff,abs_diff,diff_squared])

x1,x2,x3= f(
    np.ones((2,2)),                 # a
    np.arange(4).reshape((2,2))     # b
)
print(x1, x2, x3)
print("")

#-------------function的名字--------------
x,y,w = T.dscalars('x','y','w')
z = (x+y)*w


f = theano.function([x,
                     theano.In(y, value=1),
                     theano.In(w,value=2)],
                    z)      #name for a function

print(f(23))                #使用預設
print(f(23,1,4))            #不使用預設

f = theano.function([x,
                     theano.In(y, value=1),
                     theano.In(w,value=2,name='weights')],
                    z)
                    
print (f(23,1,weights=4))   #調用方式
