#include "image.h"   
#include<iostream>
#include<cstring>  
#include<vector>
#include<cmath>
#include<algorithm>      
#include "sobelEdge.h"
#include "gaussianConv.h"
#include "equalization.h"
int main()
{

	sobel filter;

	Image input;
	input.load("Bird.jpg");
	//Image output(input._width, input._height, input._channels);
	//filter.applySobel(input);
	gaussianConv gaussian; 
	gaussian.applyGaussian(input); 
	return 0; 

}