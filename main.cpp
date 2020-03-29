#include<iostream>
#include <windows.h>
#include"rsa.h"
using namespace std; 
void Test(const string filename, const string EncName, const string DecName) {
	RSA rsa;
	if (rsa.encrypt(filename, EncName)) {
		cout << "加密完成!\n";
		if (rsa.decrypt(EncName, DecName)) {
			cout << "解密完成!";
		}
	}
	cout << "3秒后程序退出!\n";
	Sleep(3000);//在Linux下为sleep(3), 需要添加头文件 unistd.h
}
int main() {
	string filename("明文.txt"), EncName("密文.txt"), DecName("解密后的文件.txt");
	Test(filename, EncName, DecName);
	return 0;
}
