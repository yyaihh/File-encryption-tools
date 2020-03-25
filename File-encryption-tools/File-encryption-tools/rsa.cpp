//#include<fstream>
//#include"rsa.h"
//using namespace std;
//
//DataType RSA::getNkey(DataType& prime1, DataType& prime2) {
//	return prime1 * prime2;
//}
//DataType RSA::getOrla(DataType& prime1, DataType& prime2) {//prime1和prime2必须互质
//	return (prime1 - 1) * (prime2 - 1);
//}
//DataType RSA::getEkey(DataType& orla) {
//	srand(time(0));
//	DataType ekey;
//	do {
//		ekey = rand() % orla;
//	} while (ekey < 2 || getGcd(ekey, orla) != 1);
//	return ekey;
//}
//DataType RSA::getDkey(DataType& ekey, DataType& orla) {
//	DataType x, y;
//	exGcd(ekey, orla, &x, &y);
//	//变换, 让解密密钥是一个比较小的数
//	return (x % orla + orla) % orla;
//}
//DataType RSA::getGcd(DataType num1, DataType num2) {
//	DataType num;
//	while ((num = num1 % num2)) {
//		num1 = num2;
//		num2 = num;
//	}
//	return num2;
//}
//DataType RSA::exGcd(DataType a, DataType b, DataType* x, DataType* y) {
//	if (b == 0) {
//		*x = 1;
//		*y = 0;
//		return a;
//	}
//	DataType gcd = exGcd(b, a % b, x, y);
//	DataType x1 = *x, y1 = *y;
//	*x = y1;
//	*y = x1 - a / b * y1;
//	return gcd;
//}
//DataType RSA::_encrypt(DataType Ai, DataType& ekey, DataType& nkey) {
//	//data^ekey % nkey
//	//只和ekey的位数有关
//	DataType res = 1;
//	for (; ekey; ekey >>= 1) {
//		if (ekey & 1) {
//			res = (res*Ai) % nkey;
//		}
//		Ai = (Ai*Ai) % nkey;
//	}
//	return res;
//}
//DataType RSA::_decrypt(DataType data, DataType& dkey, DataType& nkey) {
//	return _encrypt(data, dkey, nkey);
//}
//void RSA::getKeys() {
//	DataType prime1, prime2 = bg.GetPrime();
//	do {
//		prime1 = bg.GetPrime();
//	} while (prime1 == prime2);
//	m_key.m_nkey = getNkey(prime1, prime2);
//	DataType orla = getOrla(prime1, prime2);
//	m_key.m_ekey = getEkey(orla);
//	m_key.m_dkey = getDkey(m_key.m_ekey, orla);
//}
//Key RSA::getKey() {
//	return m_key;
//}
//void RSA::encrypt(const char* filename, const char* outname) {
//	ifstream fin(filename, ifstream::binary);
//	ofstream fout(outname, ifstream::binary);
//	if (!fin.is_open()) {
//		perror("input file open failed!");
//		return;
//	}
//	char* buffer = new char[NUMBER];
//	DataType* bufferOut = new DataType[NUMBER];
//	//char* bufferOut = new char[NUMBER];
//	while (!fin.eof()) {
//		fin.read(buffer, NUMBER);
//		int ret = fin.gcount();
//		for (int i = 0; i < ret; ++i) {
//			bufferOut[i] = _encrypt((DataType)buffer[i], m_key.m_ekey, m_key.m_nkey);
//		}
//		fout.write((char*)bufferOut, ret * sizeof(DataType));
//	}
//	delete[] bufferOut;
//	delete[] buffer;
//	fin.close();
//	fout.close();
//}
//void RSA::decrypt(const char* filename, const char* outname) {
//	ifstream fin(filename, ifstream::binary);
//	ofstream fout(outname, ifstream::binary);
//	if (!fin.is_open()) {
//		perror("file open failed");
//	}
//	DataType* buffer = new DataType[NUMBER];
//	//char* buffer = new char[NUMBER];
//	char* bufferOut = new char[NUMBER];
//	while (!fin.eof()) {
//		fin.read((char*)buffer, NUMBER * sizeof(DataType));
//		int ret = fin.gcount() / sizeof(DataType);
//		for (int i = 0; i < ret; ++i) {
//			bufferOut[i] = (char)_decrypt(buffer[i], m_key.m_dkey, m_key.m_nkey);
//		}
//		fout.write((char*)bufferOut, ret);
//	}
//	delete[] bufferOut;
//	delete[] buffer;
//	fin.close();
//	fout.close();
//}