#include <vector>
#include <iostream>
typedef std::vector<unsigned char> DecodedImage;
struct ImageInfo
{
	void hitler()
	{
		std::cout << "Iiro niin vihaa maailmaa" << std::endl;
	}
	ImageInfo(DecodedImage DecodedImage, unsigned Width, unsigned Height)
	{
		decodedImage = DecodedImage;
		width = Width;
		height = Height;
	}
	DecodedImage decodedImage;
	unsigned width;
	unsigned height;

};