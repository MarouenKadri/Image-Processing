#include "image.h"

#define STB_IMAGE_IMPLEMENTATION  
#include "stb_image.h"       
 
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"  

Image::Image(const int width, const int height, const int nbChannels) :_width(width), _height(height), _channels(nbChannels)
{

	Pixels = new unsigned char[_width*_channels*_height]; 
	//memset(Pixels, 0, _width * _height *_channels);

}
Image::~Image()
{
	delete [] Pixels;
}    

void Image::load(const std::string &path)
{

	unsigned char* newPixels = stbi_load(path.c_str(),&_width,&_height,&_channels,0);
	if (newPixels == nullptr)
	{
		std::string msg = "Failed to load image : " + path + stbi_failure_reason(); 
		throw std::runtime_error(msg.c_str()); 

	}  
	
	Pixels = newPixels;
}  

void Image::save(const std::string &path) const
{
	stbi_write_png(path.c_str(), _width, _height, _channels, Pixels, _width*_channels); 
}
