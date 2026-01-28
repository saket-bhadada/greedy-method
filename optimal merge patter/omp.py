import numpy as np

A = np.array([3, 8, 12, 20])
B = np.array([4, 6, 15, 18])
C = np.empty(A.size + B.size, dtype=A.dtype)

while(A.size>0 and B.size>0):
    if (A[0]>B[0]):
        C.push(B[0])
        B = B[1:]
    else:
        C.push(A[0])
        A = A[1:]

while(A.size>0):
    C.push(A[0])
    A = A[1:]

while(B.size>0):
    C.push(B[0])
    B = B[1:]

print(C)