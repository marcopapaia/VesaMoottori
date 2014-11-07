#pragma once
#include <GL\glew.h>
#include <map>
#include <string>
#include "Image.h"
#include "Texture.h"

class ResourceManager
{
public:
	ResourceManager() {};
	~ResourceManager() {};

	bool LoadPicture(std::string fileName); // Lis�t��n kuva mappiin.
	Image* FindImage(std::string pictureName); // Haeteaan kuva mapista.

	//Texture* CreateTexture(std::string pictureName, std::string textureName);
	Texture* CreateTexture(std::string pictureName, std::string textureName, vector2f position, float scale);
	//Texture* FindTexture(std::string textureName);

	char* LoadShader(std::string fileName, std::string shaderName);
	char* FindShader(std::string shaderName);

	//void AddImageLocation(std::string filename);	//kuvan sijainti vektoriin, jos vaikka k�ynnist�ess� la
	//char* LoadShader(std::string filename);		//palauttaa t�ll� hetkell� shaderin & uppii shadermappiin
	//char* FindShader(std::string filename);		//palauttaa shaderin shadermapista
	//GLuint GetTexture() { return texture; }
	//void CreateTexture(Image *image);

private:
	unsigned int MyHasher(std::string fileName); // Muuttaa stringin uchariksi.
	std::map<unsigned int, Image> decodedImages; // Sis�lt�� ladatut kuvat.
	std::map<std::string, Texture*> textures;
	std::map<std::string, char*> shaders;
	char* ShaderReader(std::string fileName);

	//GLuint texture;
	//std::map<unsigned int, char*> shaders;			//shadermap
	//std::vector<std::string> imageLocations;			//ei ehk� v�ltt�m�t�n. Helppo muokattavuus jos vaikka tekstifileess�, josta voidaan sitten hakea kaikki tarvittavat kuvat.
};