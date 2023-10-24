/*
Adina Lev
566021464
Exercise 8 Question 1
This exercise switches an infix string to postfix, and then calculates the postfix value.
This is implemented with stacks -- StackVector and StackList.
*/

#include "Vector.h"
#include "StackVector.h"
#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;

string infixToPostfix(std::string infix) {
    string str;
    char ch, temp, next;
    int count1 = 0, i = 0;
    StackVector<char> stk(infix.length());
    ch = infix[i]; 
    while (i < infix.length()) {
        if (ch == '(') stk.push(ch); // if ch is an left parenthesis then push it on the stack
        if (ch == ')') {
            // pop the contents of the stack up until and not including the 
            //left parenthesis and append each element of the stack to str. 
            next = stk.top(); // to see what the next element in the stack is
            while (next != '(') {
                str += stk.pop(); // append each element of the stack to str
                str += ' ';
                next = stk.top();
            }
            if (next == '(') stk.pop(); // Then pop the left parenthesis from the stack
        }
        if (ch >= 42 && ch <= 47) { // if ch is an operator
            if (!stk.isEmpty()) {
                next = stk.top();
                if (ch == '-' || ch == '+') {
                    while (next == '-' || next == '+' || next == '/' || next == '*') {
                        str += stk.pop(); // pop from the stack all operators with higher precedence and append them to str
                        str += ' ';
                        next = stk.top();
                    }
                }
                if (ch == '/') {
                    while (next == '*' || next == '/') {
                        str += stk.pop();
                        str += ' ';
                        next = stk.top(); 
                    }
                }
                if (ch == '*') {
                    while (next == '*') {
                        str += stk.pop();
                        str += ' ';
                        next = stk.top(); 
                    }
                }
            }
            stk.push(ch); 
        }
        // if ch is a number then append it to str
        if (isdigit(ch) && !isdigit(infix[i-1])) {
            string tempStr = ""; // creating a temporary string
            tempStr += ch;
            int k = 1;
            while (isdigit(infix[i + k])) { 
                // in case there are two digits one right after each other
                tempStr += infix[i + k];
                k++;
            }
            str += tempStr;
            str += ' ';
        }
        i++;
        ch = infix[i]; // read in the next character from input       
    }
    while (!stk.isEmpty()) {
        str += stk.pop();
    }
    return str;
}


int calcPostfix(string postfix) {
    StackVector<int> stk(postfix.length()); // create an empty stack of ints
    int oper1, oper2, answer, digit;
    char ch, next;
    for (int i = 0; i < postfix.size(); i++) {
        ch = postfix[i];
        if(isdigit(ch)) {
            digit = ch - 48;
            int k = 1;
            next = postfix[i + k];
            while (isdigit(next)) {
                digit = digit * 10 + (next - 48);
                k++;
                next = postfix[i + k];
            }
            stk.push(digit); // if the next element is an operand add it to the stack
            i++;
        }
        if (ch == '+') {
            oper1 = stk.pop();
            oper2 = stk.pop();
            stk.push(oper2 + oper1);
        }
        if (ch == '-') {
            oper1 = stk.pop();
            oper2 = stk.pop();
            stk.push(oper2 - oper1);
        }
        if (ch == '*') {
            oper1 = stk.pop();
            oper2 = stk.pop();
            stk.push(oper2 * oper1);

        }
        if (ch == '/') {
            oper1 = stk.pop();
            oper2 = stk.pop();
            stk.push(oper2 / oper1);
        }
    }
    answer = stk.pop();
    return answer;
}

int main()
{
    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "in postfix form: " << postfix << endl;
    cout << "calculated value: " << calcPostfix(postfix) << endl;
    return 0;
}


