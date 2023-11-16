#ifndef GAUSSIANCONV  
#define GAUSSIANCONV
#include "image.h"
#include<vector>


class gaussianConv
{
public :

	void applyGaussian(Image &in); 
	gaussianConv(); 

public :
	std::vector<std::vector<int>> kernel; 



};
#endif 