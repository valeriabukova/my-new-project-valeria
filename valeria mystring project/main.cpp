//
//  main.cpp
//  valeria mystring project
//
//  Created by Valeria  Bukova on 02.10.2024.
//

#include <iostream>
using namespace std;

class MyString {
private:
    char* str;
    int length;
    static int objectCount;

public:
   
    MyString() {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

  
    MyString(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

   
    MyString(const char* inputStr) {
        length = 0;
        while (inputStr[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = inputStr[i];
        }
        str[length] = '\0';
        objectCount++;
    }

  
    ~MyString() {
        delete[] str;
        objectCount--;
    }

   
    void input() {
        cout << "Введите строку: ";
        cin >> str;
        length = 0;
        while (str[length] != '\0') {
            length++;
        }
    }

  
    void output() const {
        cout << "Строка: " << str << endl;
    }

    
    void MyStrcpy(MyString &obj) {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = obj.str[i];
        }
        str[length] = '\0';
    }

    
    bool MyStrStr(const char* substr) {
        for (int i = 0; i < length; i++) {
            int j = 0;
            while (str[i + j] == substr[j] && substr[j] != '\0') {
                j++;
            }
            if (substr[j] == '\0') {
                return true;
            }
        }
        return false;
    }

    
    int MyChr(char c) {
        for (int i = 0; i < length; i++) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    
    int MyStrLen() const {
        return length;
    }


    void MyStrCat(MyString &b) {
        char* newStr = new char[length + b.length + 1];
        for (int i = 0; i < length; i++) {
            newStr[i] = str[i];
        }
        for (int i = 0; i < b.length; i++) {
            newStr[length + i] = b.str[i];
        }
        newStr[length + b.length] = '\0';
        delete[] str;
        str = newStr;
        length += b.length;
    }


    void MyDelChr(char c) {
        int newLength = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] != c) {
                str[newLength++] = str[i];
            }
        }
        str[newLength] = '\0';
        length = newLength;
    }


    int MyStrCmp(MyString &b) {
        int i = 0;
        while (str[i] != '\0' && b.str[i] != '\0') {
            if (str[i] < b.str[i]) {
                return -1;
            } else if (str[i] > b.str[i]) {
                return 1;
            }
            i++;
        }
        if (str[i] == '\0' && b.str[i] == '\0') {
            return 0;
        }
        return (str[i] == '\0') ? -1 : 1;
    }

    MyString operator+(MyString &b) {
        MyString temp(length + b.length);
        temp.MyStrCat(*this);
        temp.MyStrCat(b);
        return temp;
    }

    
    bool operator==(MyString &b) {
        return MyStrCmp(b) == 0;
    }

    
    MyString& operator++() {
        char* newStr = new char[length + 2];
        for (int i = 0; i < length; i++) {
            newStr[i] = str[i];
        }
        newStr[length] = ' ';
        newStr[length + 1] = '\0';
        delete[] str;
        str = newStr;
        length++;
        return *this;
    }

   
    static int getObjectCount() {
        return objectCount;
    }
};


int MyString::objectCount = 0;

int main() {
    MyString str1("Hello");
    MyString str2(" World");

    str1.output();
    str2.output();

    
    MyString str3 = str1 + str2;
    str3.output();

    
    if (str1 == str2) {
        cout << "Строки равны!" << endl;
    } else {
        cout << "Строки не равны!" << endl;
    }

    
    ++str1;
    str1.output();

    
    cout << "Количество объектов: " << MyString::getObjectCount() << endl;

    return 0;
}
