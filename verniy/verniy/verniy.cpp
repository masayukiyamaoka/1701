// verniy.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<cmath>

//マクロ関数
#define G 9.8
#define SIZE 20
#define _CRT_SECURE_NO_WARNING
#define _USE_MATH_DEFINES

using namespace std;
using namespace cv;

string win_src = "src";


//ベールヌイの定理の応用(水槽)
double verniy(int d, double g)
{
	double v;
	return v = sqrt(2 * d*g);
}


int main()
{
	int i;
	int j;
	int t;

	FILE *fp;
	const char *fname = "C://verniy//verniy.csv";

	const char *s1 = "v[m/s]";
	const char *s2 = "d[m]";

	double v[SIZE];

	string file_src = "C://verniy//verniy.png";

	fopen_s(&fp,fname,"w");
	if (fp == NULL) {
		printf("%sファイルが開けません\n", fname);
		return -1;
	}

	fprintf(fp, "%s,%s\n", s2, s1);
	//計算結果を格納
	for (i = 1; i <= 15; i++)
	{
		v[i] = verniy(i, G);
	}

	//計算結果出力
	for (j = 1; j <= 15; j++)
	{
		printf("流速[%d]=%.2f\n", j, v[j]);
		fprintf(fp, "%d,%.2f\n", j, v[j]);
	}
	fclose(fp);
	printf("%sファイル書き込みが終わりました\n", fname);

	Mat img_src = imread(file_src,1);

	if (!img_src.data)
	{
		cout << "error"<<endl;
		return -1;
	}
	namedWindow(win_src,WINDOW_AUTOSIZE);
	resize(img_src,img_src,Size(),2,2);
	imshow(win_src, img_src);

	waitKey(0);

	cin >> t;
    return 0;
}