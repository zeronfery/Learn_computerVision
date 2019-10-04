// Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
using namespace std;
//Gray an image()
int GrayScale(cv::Mat pho,cv::String filename) {
	cv::Mat pho1;
	cv::cvtColor(pho, pho1,cv::COLOR_RGB2GRAY);
	cv::imwrite(filename,pho1);
	return 0;
}
int Add_PepperSaltNois(cv::Mat img,cv::String path,int number) {
	int i, j;			//salt rand point
	int m, n;			//pepper rand point
	//cv::cvtColor(img, img, cv::COLOR_RGB2GRAY);
	cv::imwrite(path, img);
}


//Gray some images
int Img_function(string F,int n) { //n means functions' flag:0 Gray some of images;
	cv::Mat empty;
	string img_name,dest_path;
	ifstream fin("D:\\Study\\研究生学期课程\\计算机视觉\\作业\\第三次作业\\img\\img.txt");
	while (getline(fin,img_name))
	{
		dest_path = F + "gray\\" + img_name; //the filepath of saving
		img_name = F + img_name;             //the filepath of reading
		
		empty = cv::imread(img_name, 1);
		if (!empty.empty()) {
			switch (n)
			{
			case 0:
				GrayScale(empty, dest_path);  //Gray the image and save it
				break;
			default:
				cout << "the flag was beyond the ability of this function!" << endl;
				break;
			}
			
		}
	}
	return 0;
}

int main()
{
	
	//cv::Mat img;
	string base_filename = "D:\\Study\\研究生学期课程\\计算机视觉\\作业\\第三次作业\\img\\";
	//if (img.empty())
	//	return -1;
	
	//gray the images
	//GrayScale(img1, "D:\\Study\\研究生学期课程\\计算机视觉\\作业\\第三次作业\\img\\gray\\gray1.jpg");
	Img_function(base_filename,0);


	cv::waitKey(0);
	//cv::destroyWindow("showimg");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
