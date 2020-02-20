#include<iostream>
#include"rsa.h"
using namespace std;
int main(){
    RSA rsa;
    rsa.getKeys();
    Key key = rsa.getKey();
    DataType data1;
    cout << "nkey:" << key.m_nkey << endl
        << "ekey:" << key.m_ekey << endl
        << "dkey:" << key.m_dkey << endl;
    while(cin>>data1){
        DataType data2 = rsa.encrypt(data1, key.m_ekey, key.m_nkey);
        cout << "加密后:" << data2 << endl;
        cout << "解密后:" << rsa.decrypt(data2, key.m_dkey, key.m_nkey) << endl << endl;
}
    return 0;
}
