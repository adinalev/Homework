//#include "Vector.h"
//#include "StackVector.h"
//#include "Stack.h"
//#include <string>
////#include <cstdlib>
////#include <ctype.h>
//#include <iostream>
//using namespace std;
//
//void reverse(string& str)
//{
//    int len = str.length();
//    for (int i = 0; i < len / 2; i++)
//        swap(str[i], str[len - i - 1]);
//}
//
//string infixToPostfix(std::string infix) {
//    string str;
//    char ch, temp;
//   // Stack<char>* stk = new StackVector<char>(infix.length()); // create an empty stack of chars --> stk // stackvector?
//    //stk = new StackVector<int>(); // <char>?
//    StackVector<char> stk(infix.length());
//    int i = 0;
//    while (i < infix.size()) {
//        cin >> ch; // ch = stk.top(); // should this be cin >> ch?
//        if (ch == '(') stk.push(ch); // if ch is an left parenthesis then push it on the stack
//        if (ch == ')') {
//            // pop the contents of the stack up until and not including the 
//            //left parenthesis and append each element of the stack to str. 
//            while (ch != '(') {
//                temp = stk.pop();
//                str += temp; // append each element of the stack to str
//                str += ' ';
//                cin >> ch; // ch = stk.top();  // read in the next character // should this be cin >> ch
//            }
//            stk.pop(); // Then pop the left parenthesis from the stack
//        }
//        if (ch >= 42 && ch <= 47) { // if ch is an operator
//            temp = stk.top();
//            if (ch == '-' || ch == '+') {
//                while (temp == '-' || temp == '+' || temp == '/' || temp == '*') {
//                    // don't know if i'm also supposed to do plus/minus
//                    str += stk.pop(); // pop from the stack all operators with higher precedence and append them to str
//                    str += ' ';
//                    cin >> temp; // temp = stk.top();
//                }
//            }
//            if (ch == '/') {
//                while (temp == '*' || temp == '/') {
//                    str += stk.pop();
//                    str += ' ';
//                    cin >> temp; // temp = stk.top();
//                }
//            }
//            if (ch == '*') {
//                while (temp == '*') {
//                    str += stk.pop();
//                    str += ' ';
//                    cin >> temp; // temp = stk.top();
//                }
//            }
//            // DON'T CONTINUE GOING THROUGH THE STACK IF YOU HIT SOMETHING THAT DOESN'T HAVE HIGHER PRECEDENCE!!
//            stk.push(ch); // do i add <char> // then push ch onto the stack
//        }
//        // if ch is a number then append it to str
//        if (isdigit(ch)) {
//            while (!stk.isEmpty()) {
//                str += stk.pop(); // stk.pop() should be equivalent to ch because ch is the value that's in top
//                str += ' ';
//            }          
//        }
//        ch = stk.top(); // read in the next character from input // should this be cin >> ch?
//        i++;
//    }
//    while (!stk.isEmpty()) {
//        //ch = stk.pop();
//        str += stk.pop();
//    }
//    return str;
//}
//
//int calcPostfix(string postfix) {
//    StackVector<int> stk(postfix.length()); // create an empty stack of ints
//    //Stack<int>* stk = new StackVector<int>();// create an empty stack of ints --> stk // stackvector?
//    int oper1, oper2, answer;
//    char ch;
//    for (int i = 0; i < postfix.size(); i++) {
//        ch = postfix[i];
//        if (ch >= '0' && ch <- '9') {
//            ch -= 48; // convert from ascii to regular value
//            stk.push(ch); // if the next element is an operand add it to the stack
//        }
//        if (ch == '+') {
//            oper1 = stk.pop();
//            oper2 = stk.pop();
//            stk.push(oper1 + oper2);
//        }
//        if (ch == '-') {
//            oper1 = stk.pop();
//            oper2 = stk.pop();
//            stk.push(oper1 - oper2);
//        }
//        if (ch == '*') {
//            oper1 = stk.pop();
//            oper2 = stk.pop();
//            stk.push(oper1 * oper2);
//        }
//        if (ch == '/') {
//            oper1 = stk.pop();
//            oper2 = stk.pop();
//            stk.push(oper1 / oper2);
//        }   
//    }
//    answer = stk.pop();
//    return answer;
//}
//
//int main()
//{
//    string exp;
//    cout << "enter an infix expression as a string" << endl;
//    cin >> exp;
//    string postfix = infixToPostfix(exp);
//    cout << "in postfix form: " << postfix << endl;
//    cout << "calculated value: " << calcPostfix(postfix) << endl;
//    return 0;
//}
//
//
