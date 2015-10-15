#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int evaluate(string infix, const bool values[], string& postfix, bool& result)
{
    if (infix == "") return 1;
    postfix = "";
    stack<char> ysf;
    char prev = ' ';
    for (int i = 0; i < infix.length(); i++)
        switch (infix[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (prev>='0' && prev<='9' || prev == ')') return 1;
                prev = infix[i];
                postfix += infix[i];
                while (!ysf.empty() && ysf.top() == '!') {
                    postfix += ysf.top();
                    ysf.pop();
                }
                break;
            case '(':
            case '!':
                if (prev>='0' && prev<='9' || prev == ')') return 1;
                prev = infix[i];
                ysf.push(infix[i]);
                break;
            case ')':
                if ((prev<'0' || prev>'9') && prev != ')') return 1;
                prev = infix[i];
                while (!ysf.empty() && ysf.top() != '(') {
                    postfix += ysf.top();
                    ysf.pop();
                }
                if (ysf.empty()) return 1;
                ysf.pop();
                break;
            case '&':
            case '|':
                if ((prev<'0' || prev>'9') && prev != ')') return 1;
                prev = infix[i];
                while (!ysf.empty() && ysf.top() != '(' && infix[i] >= ysf.top()) {
                    postfix += ysf.top();
                    ysf.pop();
                }
                ysf.push(infix[i]);
                break;
            case ' ':
                break;
            default:
                return 1;
        }
    if (prev=='!' || prev=='&' || prev == '|') return 1;
    while (!ysf.empty()) {
        if (ysf.top() == '(') return 1;
        postfix += ysf.top();
        ysf.pop();
    }
    
    stack<bool> operand;
    bool operand1, operand2;
    for (int i = 0; i < postfix.length(); i++)
        if (postfix[i]<='9' && postfix[i]>='0')
            operand.push(values[postfix[i]-'0']);
        else
        {
            if (postfix[i] != '!') {
                operand2 = operand.top();
                operand.pop();
                operand1 = operand.top();
                operand.pop();
                if (postfix[i] == '&')
                    operand1 = operand1 && operand2;
                else
                    operand1 = operand1 || operand2;
                operand.push(operand1);
            }
            else
                operand.top() = !operand.top();
        }
    result = operand.top();
    return 0;
}


int main()
{
    bool ba[10] = {
        //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    /*string pf;
    bool answer;
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
           &&  pf == "43!03&&|"  &&  !answer);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    ba[2] = false;
    ba[9] = true;
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    cout << "Passed all tests" << endl;*/
    string infix, postfix;
    bool result;
    getline(cin, infix);
    cout << evaluate(infix, ba, postfix, result) << endl;
    cout << postfix << endl;
    cout << result << endl;
}
