def fnrecursion(n):
    if (n==0):
        return 0
    return n + fnrecursion(n-1)



def solve():
    n= int(input())
    print(fnrecursion(n))