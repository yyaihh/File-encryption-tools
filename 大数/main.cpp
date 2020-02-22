#include<iostream>
#include"bignum.h"
#include<string>
using namespace std;
int main(){
    string num1;
    string num2;
    while(cin>>num1>>num2){
        BigNum s1(num1);
        BigNum s2(num2);
        cout << num1 << " + " << num2 << " = " << s1 + s2 << endl;
        cout << num1 << " - " << num2 << " = " << s1 - s2 << endl;
        cout << num1 << " x " << num2 << " = " << s1 * s2 << endl;
        cout << num1 << " / " << num2 << " = " << s1 / s2 << endl;
        cout << num1 << " % " << num2 << " = " << s1 % s2 << endl;
    }
    return 0;
}
