import threading
import numpy as np

n = 8
fib = np.zeros((n), dtype=int)

def runn(num):
    if(num==0):
        fib[num] = 0
    if(num==1):
        fib[num] = 1
    else:
        fib[num] = fib[num-1]+fib[num-2]


for i in range(n):
    t1=threading.Thread(target=runn, args=(i,))
    #target is the callable object to be invoked by the run() method
    t1.start()
    t1.join()
    print(fib[i])
print(fib)
