// wavread.cpp: 定义控制台应用程序的入口点
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <typeinfo.h>
using namespace std;
struct wav_struct {
	unsigned int channel_num;// 声道数
	unsigned int frequency;// 采样频率
	unsigned int byte_rate;// frequency * channel_num * bit_per_sample /8
	unsigned int bit_per_sample;// 比特位 8位或者16 24等
	unsigned int file_size;	// 文件大小
	unsigned int data_size;	// 实际数据大小
	unsigned char *data;	// 实际存储的数据
};

int main(void)
{
	const string file_name = "D:\\Project\\effect_c\\audioData\\Long Live.wav";		// 需要使用绝对地址
	ifstream fp;																	// 输入时 ifstream
	wav_struct wav;

	fp.open(file_name, ios::in | ios::binary);										// 读取文件 try except
	if (fp.is_open())
		cout << "Open it successful." << endl;
	else
		cout << "Can not open it." << endl;

	fp.seekg(0, ios::end);                  // seek get
	wav.file_size =  fp.tellg();             // 从后往前，输出的是整个文件的大小(字节形式)

	cout << "Wav len:" << wav.file_size << endl;
	fp.seekg(0x18);
	//cout << "cur:"<<fp.tellg() << endl;
	//fp.read((char*)&temp, sizeof(temp));			// 读取之后会自动将指针移动已读字节数
	//cout << "cur:" << fp.tellg() << endl;
	//fp.read((char*)&temp, 4);
	//fp.seekg(0);
	//fp.read(s, 4);
	//cout << "ChunkID-" << s[2] << endl;
	//cout << "Get:" << temp << endl;
	//
	//    fp.read(temp,sizeof(unsigned char));
	//    fp >> noskipws;
	//    while (fp.good()){
	//        fp >> c;
	//        cout << c <<"";
	//    }
	//cout << "see the id" << endl;
	//    cout<< typeid(WAV.frequency).name()<<endl;


	system("pause");
	return 0;
}
