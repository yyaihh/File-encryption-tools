#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
typedef long DataType;
struct Key {
    DataType m_ekey;//公钥e
    DataType m_dkey;//私钥d
    DataType m_nkey;//公共模数n
};

class RSA{
    Key m_key;
    DataType getPrime();//产生素数
    bool isPrime(DataType num);
    DataType getNkey(DataType prime1, DataType prime2);//获取公共模数n
    DataType getOrla(DataType prime1, DataType prime2);//欧拉函数, 得到f(n)
    DataType getEkey(DataType orla);//获取公钥
    DataType getDkey(DataType ekey, DataType orla);//获取私钥
    DataType getGcd(DataType num1, DataType num2);//最大公约数
    DataType _encrypt(DataType data, DataType ekey, DataType nkey);//加密,需要加密数据和公钥(e, n)
    DataType _decrypt(DataType data, DataType dkey, DataType nkey);//解密,需要要解密的数据和私钥(d, n)
    void getKeys();
public:
    RSA(){
        getKeys();                                            
    }
    Key getKey();
    void encrypt(const char* filename, const char* outname);
    void decrypt(const char* filename, const char* outname);
};
DataType RSA::getPrime(){
    DataType res;
    srand(time(0));
    do{
        res = rand() % 200 + 2;//
    }while(!isPrime(res));
    return res;
}
bool RSA::isPrime(DataType num){
    if(num <= 0) return false;
    int sr = sqrt(num);
    for(int i = 2; i <= sr; ++i){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
DataType RSA::getNkey(DataType prime1, DataType prime2){
    return prime1 * prime2;
}
DataType RSA::getOrla(DataType prime1, DataType prime2){//prime1和prime2必须互质
    return (prime1 - 1) * (prime2 - 1);
}
DataType RSA::getEkey(DataType orla){
    srand(time(0));
    DataType ekey;
    do{
        ekey = rand() % orla;
    }while(ekey < 2 || getGcd(ekey, orla) != 1);
    return ekey;
}
DataType RSA::getDkey(DataType ekey, DataType orla){
    DataType dkey = orla / ekey;
    for(;(dkey*ekey%orla) != 1; ++dkey);
    return dkey;
}
DataType RSA::getGcd(DataType num1, DataType num2){
    int num;
    while((num = num1 % num2)){
        num1 = num2;
        num2 = num;
    }
    return num2;
}
DataType RSA::_encrypt(DataType data, DataType ekey, DataType nkey){
    DataType Ai = data;
    //data^ekey % nkey
    //只和ekey的位数有关
    DataType res = 1;
    for(; ekey; ekey >>= 1){
       if(ekey & 1){
           res = (res*Ai) % nkey;
       }
       Ai = (Ai*Ai) % nkey;
    }
    return res;
}
DataType RSA::_decrypt(DataType data, DataType dkey, DataType nkey){
    return _encrypt(data, dkey, nkey);
}
void RSA::getKeys(){
    DataType prime1, prime2 = getPrime();
    do{
        prime1 = getPrime();
    } while(prime1 == prime2);
    m_key.m_nkey = getNkey(prime1, prime2);
    DataType orla = getOrla(prime1, prime2);
    m_key.m_ekey = getEkey(orla);
    m_key.m_dkey = getDkey(m_key.m_ekey, orla);
}
Key RSA::getKey(){
    return m_key;
}
void RSA::encrypt(const char* filename, const char* outname){

}
void RSA::decrypt(const char* filename, const char* outname){

}
