def summation(i, sum): 
    if (i<1):
        print(sum)
        return 
    summation(i-1,sum+i)


def solve():
    n = int(input())
    summation(n,0)
