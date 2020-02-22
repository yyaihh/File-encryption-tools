#include<string>
using std::string;
using std::pair;
class BigNum{
    string m_num;
    string add(string num1, string num2);
    string sub(string num1, string num2);
    string mul(string& num1, string& num2);
    pair<string, string> dev(string num1, string num2);
    bool IsLess(const string& num1, const string& num2);
public:
    BigNum(const string num):
        m_num(num) 
    {}
    BigNum(const BigNum& b):
        m_num(b.m_num)
    {}
    BigNum& operator=(const BigNum& b){
        m_num = b.m_num;
        return *this;
    }
    string operator+(BigNum& n);
    string operator-(BigNum& n);
    string operator*(BigNum& n);
    string operator/(BigNum& n);
    string operator%(BigNum& n);
};
