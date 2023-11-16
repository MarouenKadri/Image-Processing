
#include "sobelEdge.h"  
#include<algorithm>
#include<cmath>
#include<iostream>



void sobel::applySobel(Image & inputImage)
{   
	
	int width = inputImage._width;  
	int height = inputImage._height;  
	int channel = inputImage._channels;
	Image out(width, height, channel); 
	for (int y = 1; y < height-1; y++)
	{ 
	  for (int x = 1; x < width-1; x++)
		{  
		  int sumRx(0), sumGx(0), sumBx(0), sumRy(0), sumGy(0), sumBy(0);
		  for (int ky = 0; ky < kernelsize(); ky++)
		  {
			  for (int kx = 0; kx < kernelsize(); kx++)
			  {
				  int X = x + (kx - 1);
				  int Y = y + (ky - 1);
				  int pixel = (Y*inputImage._width + X)*channel;
				  sumRx +=inputImage.Pixels[pixel + 0] * kernelSobelx[ky][kx] ;
				  sumGx += inputImage.Pixels[pixel + 1] * kernelSobelx[ky][kx];
				  sumBx += inputImage.Pixels[pixel + 2] * kernelSobelx[ky][kx];

				  sumRy += inputImage.Pixels[pixel + 0] * kernelSobely[ky][kx] ;
				  sumGy += inputImage.Pixels[pixel + 1] * kernelSobely[ky][kx]; 
				  sumBy += inputImage.Pixels[pixel + 2] * kernelSobely[ky][kx];
				
			  }
		  }

		  int pixelOut = (y * inputImage._width + x)*channel; 
		  out.Pixels[pixelOut + 0] =   std::min(std::max(abs(sumRx)+abs(sumRy), 0) ,255); 
		  out.Pixels[pixelOut + 1] = std::min(std::max(abs(sumRx) + abs(sumRy),0 ),255);
		  out.Pixels[pixelOut + 2] = std::min(std::max(abs(sumRx) + abs(sumRy) ,0),255) ;
		}
	}
	out.save("sobleFilter.png"); 
	std::cout<< "Sobel filter applicated with success!"; 
		 
}