/* Prefix to Infix Conversion
You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.

Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.

Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

Examples:
Input: expression = "+ab"

Output: "(a+b)"

Input: expression = "*+ab-cd"

Output: "((a+b)*(c-d))"
*/
#include <bits\stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefix2Infix(const string &prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isspace(c)) continue; // skip spaces

        if (isOperator(c)) {
            // Pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Form new string
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        } else {
            // Operand → push as string
            st.push(string(1, c));
        }
    }

    // Final expression
    return st.top();
}

int main() {
    string expression;
    cout << "Enter prefix expression: ";
    cin >> expression;

    string infix = prefix2Infix(expression);
    cout << "Infix expression: " << infix << endl;

    return 0;
}