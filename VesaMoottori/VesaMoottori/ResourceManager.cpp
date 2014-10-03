#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

void ResourceManager::loadImage(std::string filename)
{
	unsigned int hashedImageName = myHasher(filename);
	if (decodedImages.end() != decodedImages.find(hashedImageName))	// tarkastetaan onko kuvaa viel� lis�tty
	{
		DecodedImage image;
		unsigned width, height;
		unsigned error = lodepng::decode(image, width, height, filename);
		if (error)
		{
			//tulosta errorsoopaan "decoder error" error lodepng_error_text(error)
		}
		decodedImages.insert(std::pair<unsigned int, DecodedImage>(hashedImageName, image));	// lis�t��n kuva mappiin
	}
}

DecodedImage* ResourceManager::findImage(std::string filename)
{
	unsigned int hashedImageName = myHasher(filename);

	std::map<unsigned int, DecodedImage>::iterator it = decodedImages.find(hashedImageName);
	if (decodedImages.end() != it)
	{
		return &it->second;
	}
	else
	{
		return NULL;	// varmaan errormessagea
	}
}
char* ResourceManager::findShader(std::string filename)
{
	unsigned int  hashedShaderName = myHasher(filename);
	std::map < unsigned int, char* >::iterator it = shaders.find(hashedShaderName);
	if (shaders.end() != it)
	{
		return it->second;		// !!!!!!!!!
	}
	else
	{
		return NULL;	//varmaan errormessagea
	}
}
// pistet��nk� my�s mappiin?
char* ResourceManager::shaderReader(std::string filename)
{
	unsigned int hashedShaderName = myHasher(filename);		// haetaan hashattu shaderin nimi
	if (decodedImages.end() != decodedImages.find(hashedShaderName))	// tarkastetaan onko shaderi� jo upittu
	{
		std::ifstream readFile(filename, std::ios::in);
		if (readFile.is_open())
		{}
		else
		{
			//errormessage, could not open file
			return NULL;
		}
		readFile.seekg(0, readFile.end);
		int fileLength = (int) readFile.tellg();
		readFile.seekg(0, readFile.beg);
		if (fileLength == 0)
		{
			//errormessage, file empty
		}
		else
		{}
		std::string fileContents((std::istreambuf_iterator<char>(readFile)), std::istreambuf_iterator<char>());
		char *tempChar = new char[fileContents.length() + 1];
		std::strcpy(tempChar, fileContents.c_str());
	
		readFile.close();
		shaders.insert(std::pair<unsigned int, char*>(hashedShaderName, tempChar));
		return tempChar;	// poistetaan k�yt�st� jos tuntuu tyhm�lt� ladata joka kerta tiedostosta kun haeteaan shaderi.
	}
}

void ResourceManager::addImageLocation(std::string filename)
{
	imageLocations.push_back(filename);
}
unsigned int ResourceManager::myHasher(std::string filename)
{
	std::hash<std::string> Hasher;
	unsigned int hash = Hasher(filename);
	return hash;
}

ResourceManager::~ResourceManager()
{
}
