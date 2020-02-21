#include<iostream>
#include"bignum.h"
#include<string>
using namespace std;
int main(){
    BigNum s;
    string num1;
    string num2;
    string res;
    while(cin>>num1>>num2){
        cout << num1 << " + " << num2 << " = " << s.add(num1, num2) << endl;
        cout << num1 << " - " << num2 << " = " << s.sub(num1, num2) << endl;
        cout << num1 << " x " << num2 << " = " << s.mul(num1, num2) << endl;
        //pair<string, string> res = s.dev(num1, num2);
        //cout << num1 << " / " << num2 << " = " << res.first << "..." << res.second << endl;
    }
    return 0;
}
