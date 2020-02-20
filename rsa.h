typedef long DataType;
struct Key {
    DataType m_ekey;//公钥e
    DataType m_dkey;//私钥d
    DataType m_nkey;//公共模数n
};

class RSA{
    Key m_key;
public:
    DataType getPrime();//产生素数
    bool isPrime(DataType num);
    DataType getNkey(DataType prime1, DataType prime2);//获取公共模数n
    DataType getOrla(DataType prime1, DataType prime2);//欧拉函数, 得到f(n)
    DataType getEkey(DataType orla);//获取公钥
    DataType getDkey(DataType ekey, DataType orla);//获取私钥
    DataType getGcd(DataType num1, DataType num2);//最大公约数
    DataType encrypt(DataType data, DataType ekey, DataType nkey);//加密,需要加密数据和公钥(e, n)
    DataType decrypt(DataType data, DataType dkey, DataType nkey);//解密,需要要解密的数据和私钥(d, n)
    void getKeys();
    Key getKey();
};

