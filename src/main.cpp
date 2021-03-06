#include "my.h"
#include "location.h"
#include "recognize.h"

int main()
{
	//Mat img = imread("二维码正.jpg");
	//resize(img, img, Size(648, 419));//缩小图像，方便处理
	Mat img;
	VideoCapture cap(0);
	while (1)
	{
		//开始计时
		double time_;
		time_ = static_cast<double>(getTickCount());

		cap >> img;
		if (img.empty())
			break;


		Mat img_out;
		Location location(img);//类实例化
		location.located();//调用函数进行处理
		location.get_dstimg(img_out);

		recognized(img_out);

		//输出时间
		time_ = (static_cast<double>(getTickCount()) - time_) / getTickFrequency();
		double FPS = 1 / time_;
		//cout << "time = " << time_ * 1000 << "ms" << endl;
		cout << "FPS=" << FPS << endl;

		if (!img_out.empty())
			imshow("img_out", img_out);

		imshow("img", img);
		char key = waitKey(10);
		switch(key)
		{
			case 27:return 0; break;
		}
	}

	return 0;
}