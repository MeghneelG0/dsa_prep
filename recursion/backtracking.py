def backtrace(i,n):
    if (i<1):
        return
    backtrace(i-1,n)
    print(i)

def solve():
    n = int(input())
    backtrace(n,n)
    