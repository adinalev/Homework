// String.cpp
#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;

void MyString::setLength(int n)
{
    len = n;
}

int MyString::getLength()
{
    return len;
}

MyString::MyString() : str(nullptr), len(0) {}

MyString::MyString(const char* s)
{
    if (s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }
    else
        str = nullptr;
}

MyString::MyString(const MyString& ms)
{
    len = strlen(ms.str);
    if (ms.str)
    {
        str = new char[len + 1];
        strcpy_s(str, len + 1, ms.str);
    }
    else
        str = nullptr;
}

MyString::MyString(MyString&& ms)
{  // move constructor
    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr; //very important!!!
    cout << "move ctor" << endl;
}

MyString::~MyString()
{
    if (str) //very important!!!
        delete[] str;
    str = nullptr;
}

void MyString::setString(const char* s)
{
    if (s)
    {
        int len = strlen(s) + 1;
        str = new char[len];
        strcpy_s(str, len, s);
    }
    else str = nullptr;
}

char* MyString::getString() const
{
    return str;
}

MyString& MyString::operator=(const MyString& ms)
{
    len = ms.len;

    if (str)
        delete[] str;

    if (ms.str)
    {
        len = strlen(ms.str);
        str = new char[len + 1];
        strcpy_s(str, len + 1, ms.str);
    }
    else
        str = nullptr;

    return *this;
}

MyString MyString::operator*(const int num) const
{
    char* temp;
    temp = new char[len * num + 1];

    for (int i = 0; i < num; i++)
        strcpy_s(temp + i * len, len + 1, str); //MUST TAKE THIS OUT IN MOODLE

    MyString s(temp);

    return s;
}


MyString MyString::operator+(const MyString& ms) const
{
    int sizeI = len;
    int sizeII = ms.len;
    char* temp = new char[sizeI + sizeII + 1];

    strcpy_s(temp, sizeI + 1, str);
    strcpy_s(temp + sizeI, sizeII + 1, ms.str);

    MyString x(temp);

    return x;
}

bool MyString::operator==(const MyString& ms) const
{
    return !strcmp(str, ms.str);
}

MyString& MyString::operator=(MyString&& ms)
{ // move assignment operator

    if (str)
        delete[] str;

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr;
    cout << "move assign" << endl; // so we can see that we're in the move assignment
    return *this;
}

void MyString::print() const
{
    if (str) cout << str << endl;
}

bool MyString::operator<(const MyString& ms) const
{
    if (len == ms.len) {
        for (int i = 0; i < len; i++) {
            // if str is uppercase and ms.str is lowercase return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] <= 65 || ms.str[i] >= 90)) return false;
            // if str is lowercase and ms.str is uppercase return true
            if ((str[i] <= 65 || str[i] >= 90) && ms.str[i] >= 65 && ms.str[i] <= 90 && str[i]>ms.str[i]) return true;
            // if they're both uppercase and str > ms.str then return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] >= 65 || ms.str[i] <= 90) && str[i] > ms.str[i]) return false;
            //if they're both lowercase and str > ms.str then return false
            if ((str[i] <= 65 || str[i] >= 90) && (ms.str[i] <= 65 || ms.str[i] >= 90) && str[i] > ms.str[i]) return false;
            // if they're not equal, at this point it must be true
            if (str[i] != ms.str[i]) return true;
        }
    }
    if (len > ms.len) {
        for (int i = 0; i < ms.len; i++) {
            // if str is uppercase and ms.str is lowercase return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] <= 65 || ms.str[i] >= 90)) return false;
            // if str is lowercase and ms.str is uppercase return true
            if ((str[i] <= 65 || str[i] >= 90) && ms.str[i] >= 65 && ms.str[i] <= 90 && str[i] > ms.str[i]) return true;
            // if they're both uppercase and str > ms.str then return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] >= 65 || ms.str[i] <= 90) && str[i] > ms.str[i]) return false;
            //if they're both lowercase and str > ms.str then return false
            if ((str[i] <= 65 || str[i] >= 90) && (ms.str[i] <= 65 || ms.str[i] >= 90) && str[i] > ms.str[i]) return false;
            // if they're not equal, at this point it must be true
            if (str[i] != ms.str[i]) return true;
        }
    }
    if (len < ms.len) {
        for (int i = 0; i < len; i++) {
            // if str is uppercase and ms.str is lowercase return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] <= 65 || ms.str[i] >= 90)) return false;
            // if str is lowercase and ms.str is uppercase return true
            if ((str[i] <= 65 || str[i] >= 90) && ms.str[i] >= 65 && ms.str[i] <= 90 && str[i] > ms.str[i]) return true;
            // if they're both uppercase and str > ms.str then return false
            if (str[i] >= 65 && str[i] <= 90 && (ms.str[i] >= 65 || ms.str[i] <= 90) && str[i] > ms.str[i]) return false;
            //if they're both lowercase and str > ms.str then return false
            if ((str[i] <= 65 || str[i] >= 90) && (ms.str[i] <= 65 || ms.str[i] >= 90) && str[i] > ms.str[i]) return false;
            // if they're not equal, at this point it must be true
            if (str[i] != ms.str[i]) return true;
        }
    }
}

bool MyString::operator>(const MyString& ms) const 
{
    if (*this < ms || *this == ms) return false;
    return true;
}

bool MyString::operator<=(const MyString& ms) const
{
    return (*this < ms || *this == ms);
}

bool MyString::operator>=(const MyString& ms) const
{
    return (*this > ms || *this == ms);
}

bool MyString::operator!=(const MyString& ms) const
{
    return !(*this == ms);
}

char& MyString::operator[](int index)
{
    if (index < len && index >= 0)
        return str[index]; 
    else {
        cout << "ERROR" << endl;
        exit(0);
    }
}

MyString MyString::insert(int index, const char* ms) {
    int temp, newLen;
    if (index > len) {
        cout << "ERROR" << endl;
        return MyString();
    }
    newLen = strlen(str) + len + 1;
    char* newStr = new char[newLen];
    for (int i = 0; i < index; i++) {
        newStr[i] = str[i];
    }
    for (int i = 0; i < strlen(ms); i++) {
        newStr[i + index] = ms[i];
    }
    for (int i = index + strlen(ms); i < newLen; i++) {
        newStr[i] = str[i - strlen(ms)];
    }
    MyString final(newStr);
    delete[] newStr;
    return final;
}
