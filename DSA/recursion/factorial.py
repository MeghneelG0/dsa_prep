def factorial(n):
    if (n==0):
        return 1
    return n * factorial(n-1)



def solve():
    n = int(input())
    print(factorial(n))
