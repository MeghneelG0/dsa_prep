#include <bits/stdc++.h>
using namespace std;

int powerFunction(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * powerFunction(base, exp - 1);
}

int powerFunctionUsingHalf(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    int half = powerFunction(base, exp/2); 
    if (exp % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}

int main() {
    cout << powerFunction(2,3);
    cout << powerFunctionUsingHalf(2,9999);
    return 0;
}