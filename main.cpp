#include<iostream>
#include"rsa.h"
using namespace std;

int main(){
    RSA rsa;
    rsa.getKeys();
    Key key = rsa.getKey();
    DataType data1;
    while(cin>>data1){
        DataType data2 = rsa.encrypt(data1, key.m_ekey, key.m_nkey);
        cout << data2 << endl;
        cout << rsa.decrypt(data2, key.m_dkey, key.m_nkey) << endl;
    }
    return 0;
}
