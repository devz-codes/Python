import numpy as np
from numpy.linalg import inv
import matplotlib.pyplot as py

x_val=[1,2,3,4,5]
y_val=[-1,0,5,6,7]

mt=np.empty((0,len(x_val)),dtype=float)
mt1=np.empty((0,1),dtype=float)

i=0
while i<len(x_val):
    lst=[pow(x_val[i],x) for x in range(0,len(x_val))]
    mt1=np.append(mt1,np.array([[y_val[i]]]),axis=0)
    mt=np.append(mt,np.array([lst]),axis=0)
    i+=1

inverse=inv(mt)
final=np.dot(inverse,mt1)

def poly_fit(x):
    sum=final[0][0]
    i=0
    while i<len(x_val)-1:
        sum+=pow(x,i+1)*final[i+1][0]
        i+=1
    return sum


n=(max(x_val)-min(x_val))/0.05+1

lst = [min(x_val)+(x*0.05) for x in range(0, int(n))]

py.plot(lst,[poly_fit(x) for x in lst])
py.xlabel("X Values")
py.ylabel("Y Values")
for x in x_val:
    py.scatter(x,y_val[x_val.index(x)])
    py.annotate("({},{})".format(x,y_val[x_val.index(x)]),(x,y_val[x_val.index(x)]))
py.show()

