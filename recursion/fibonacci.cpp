#include <bits\stdc++.h>
using namespace std;


int fibo(int n) {
    if (n == 1 || n ==0 ) {
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

int main() {
    int x;
    cout << "enter n index for fibonacci series: ";
    cin >> x;
    int sum = fibo(x);
    cout << sum;
}