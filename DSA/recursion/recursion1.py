def print_name(i, n):
    if i>n:
        return
    print("hey, my name is mg")

    print_name(i+1,n)


def solve():
    n = int(input())
    print_name(1,n)