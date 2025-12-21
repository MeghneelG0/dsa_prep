def solve():
    n = int(input())
    for i in range(0, n):
        # space 
        for j in range(0, n-i-1):
            print(" ", end="")
        for j in range(0, 2*i+1):
            print("* ", end="")
        for j in range (0,n-i-1):
            print(" ", end="")
        print()
    