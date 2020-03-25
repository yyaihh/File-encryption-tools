#include<iostream>
#include"rsa.h"
//using namespace std;
//void test() {
//	RSA rsa;
//	/*rsa.encrypt("test.txt", "test_rsa.txt");
//	rsa.decrypt("test_rsa.txt", "test_.txt");*/
//	BigNum bg;
//	cout << bg.GetPrime() << endl;
//}

int main() {
	DataType m(1000);
	DataType res;
	br::mt19937 gen((uint32_t)time(NULL));
	br::uniform_int_distribution<DataType> dist(0, (DataType(1) << 256));
	DataType tmp = dist(gen);
	std::cout << m;
	return 0;
}
