#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>//高精度库
#include<boost/random.hpp>//随机数库
#include<boost/multiprecision/miller_rabin.hpp>//素性检测
namespace br = boost::random;
typedef boost::multiprecision::int1024_t DataType;

class BigNum {

public:
	DataType GetPrime();
	bool isPrime(DataType& num);
};
DataType BigNum::GetPrime() {
	DataType res;
	//br::mt19937 gen((uint32_t)time(NULL));
	//br::uniform_int_distribution<DataType> dist(0, (DataType(1) << 256));
	//do {
	//	res = dist(gen);
	//} while (!isPrime(res));
	return res;
}
bool BigNum::isPrime(DataType& num) {
	//br::mt11213b gen((size_t)time(NULL));
	/*if (miller_rabin_test(num, 25, gen)) {
		if (miller_rabin_test((num - 1) / 2, 25, gen)) {
			return true;
		}
	}*/
	return false;
}
	