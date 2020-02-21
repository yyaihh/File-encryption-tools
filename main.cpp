#include<iostream>
#include"rsa.h"
using namespace std;
int main(){
    RSA rsa;
    Key key = rsa.getKey();
    DataType data1;
    cout << "nkey:" << key.m_nkey << endl
        << "ekey:" << key.m_ekey << endl
        << "dkey:" << key.m_dkey << endl;
    return 0;
}
