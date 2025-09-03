#include <iostream>

using namespace std;

int main() {
    char ch;
    cout << "enter a character to check if its uppercase or lowercase: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        cout << "the character is uppercase" << endl;
    } else if (ch >= 'a' && ch <= 'z') {
        cout << "the character is lowercase" << endl;
    } else {
        cout << "the character is neither uppercase nor lowercase" << endl;
        if (ch >= '0' && ch <= '9') {
            cout << "the character is a digit" << endl;
        } else {
            cout << "the character is a special character" << endl;
    }
    return 0;
}
}