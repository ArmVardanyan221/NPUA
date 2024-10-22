#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidScope(const string& input) {
    stack<char> s;

    for (char ch : input) {
        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
        
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
        
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    
    return s.empty();
}

int main() {
    string input;

    cout << "Enter a sequence of symbols ((), {}, []): ";
    getline(cin, input);

    if (isValidScope(input)) {
        cout << "True: The scopes are valid.\n";
    } else {
        cout << "False: The scopes are invalid.\n";
    }

    return 0;
}
