import numpy as np

q = np.array([1, 2, 3, 4, 5, 6, 7]) 
p = np.array([10, 5, 15, 7, 6, 18, 3])
w = np.array([2, 3, 5, 7, 1, 4, 1]) 
pw = np.zeros(7,dtype=float)
capacity = 15
n=7

def profitbyweight(p,w,pw,n):
    for i in range(n):
        pw[i] = p[i]/w[i]


def sort(q,p,w,pw,n):
    for i in range(n):
        for j in range(i+1,n):
            if pw[i]<pw[j]:
                q[i],q[j]=q[j],q[i]
                p[i],p[j]=p[j],p[i] 
                w[i],w[j]=w[j],w[i]
                pw[i],pw[j]=pw[j],pw[i]
    return q,p,w,pw


profitbyweight(p, w, pw, n)
sort(q, p, w, pw, n)

print("Solving knapsack problem using greedy method")
totalprofit =0
currentweight =0
for i in range(n):
    if currentweight >= capacity:
        break
    if currentweight + w[i] <= capacity:
        currentweight += w[i]
        totalprofit += p[i]
    else:
        remain = capacity - currentweight
        totalprofit += p[i]*(remain/w[i])
        currentweight += capacity
        break


print("Total profit in knapsack =", totalprofit)   