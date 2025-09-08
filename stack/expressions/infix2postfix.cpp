#include <bits\stdc++.h>
using namespace std;

/*
Problem Statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression.

Examples:

Example 1:
Input: a+b*(c^d-e)^(f+g*h)-i
Output: abcd^e-fgh*+^*+i-
Explanation: Infix to postfix

Example 2:
Input: (p+q)*(m-n)
Output: pq+mn-*
Explanation: Infix to postfix
*/

// intuition: keep adding characters to postfix string and keep track of operators in stack.. game plan is to track the precedence and '()' open close brackets. 
int precedence(char op) {
    if (op == '-' || op == '+') return 1;
    if (op == '*' || op == '^') return 2;
    return 0;
}

string infix2postfix(string &s) {
    string postfix;
    stack<char> st;
    for (char c: s) {
        if (isspace(c)) continue;
        if (isalnum(c)) {
            postfix+= c;
        } 
        else if (c == '(') st.push('(');
        else if (c == ')') {
            while (st.top() != '(' && !st.empty()) {
                postfix += st.top();
                st.pop();
            }
        st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string s;
    cout << "enter expression in strings: ";
    getline(cin, s);
    string ans = infix2postfix(s);
    cout << ans;
    return 0;
}