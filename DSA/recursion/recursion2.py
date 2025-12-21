# print linearly from 1 to N
def recursion(i,n):
    if (i>n):
        return
    print(i)
    recursion(i+1,n)

def solve():
    n = int(input())
    recursion(1,n)