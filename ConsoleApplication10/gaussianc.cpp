#include "gaussianConv.h"
#include "image.h"
#include<algorithm>
#include<iostream>
gaussianConv::gaussianConv()
{
	kernel = { { 1,2,1} ,{2,4,2},{1,2,1} };
}

void gaussianConv::applyGaussian(Image & in)
{
	int width = in._width;
	int height = in._height;
	int nbrChannel = in._channels;
	Image out(width, height, nbrChannel);
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int r = 0, g = 0, b = 0;
			for (int ky = 0; ky < 3; ky++)
			{
				for (int kx = 0; kx < 3; kx++)
				{
					int X = x + (kx - 1);
					int Y = y + (ky - 1);
					int nbpixel = (Y*width + X)*nbrChannel;
					r += in.Pixels[nbpixel + 0] * kernel[ky][kx];
					g += in.Pixels[nbpixel + 1] * kernel[ky][kx];
					b += in.Pixels[nbpixel + 2] * kernel[ky][kx];
				}

			}


			int nbrPixel = (y*width + x)*nbrChannel;
			out.Pixels[nbrPixel + 0] = std::min(std::max(r / 16, 0), 255);
			out.Pixels[nbrPixel + 1] = std::min(std::max(g / 16, 0), 255);
			out.Pixels[nbrPixel + 2] = std::min(std::max(b / 16, 0), 255);




		}
		
		

	}
	out.save("gaussianFilter.png");
	std::cout << "Gaussian Filter was applicated with success !" ;
}