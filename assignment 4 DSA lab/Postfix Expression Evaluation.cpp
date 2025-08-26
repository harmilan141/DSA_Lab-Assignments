#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0'); // convert char to int
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string exp = "231*+9-"; // (2 + (3*1)) - 9
    cout << "Postfix: " << exp << endl;
    cout << "Evaluation: " << evaluatePostfix(exp) << endl;
    return 0;
}
