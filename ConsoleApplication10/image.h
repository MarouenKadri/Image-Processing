#ifndef IMAGE 
#define IMAGE  

#include<string>

class Image

{  
public :   
	Image() = default; 
	Image(const int p_with, const int p_height, const int p_channels); 
	~Image(); 
	void load(const std::string & path);  
	void save(const std::string & path) const; 

	// Declare the variable   
	int _width = 0;  
	int _height = 0;  
	int _channels = 0;   
	unsigned char *Pixels = nullptr; 

};

#endif