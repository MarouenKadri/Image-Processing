#ifndef SOBELEDGE
#define  SOBELEDGE
#include "image.h"   
#include<vector>

class sobel
{
public:   
	 
	sobel()
	{
		kernelSobelx = { {-1,0,1}  , {-2,0,2} ,{-1,0,1} };
		kernelSobely = { {-1,-2,-1} ,{0,0,0} , {1,2,1}   };

	}
	void applySobel(Image &image); 
	int kernelsize()
	{
		return kernelSobelx.size(); 
	}

private :   
	std::vector<std::vector<int> >kernelSobelx;
	std::vector<std::vector<int> >kernelSobely;

};

#endif // Sobel Filter for edge detection



  











