#pragma once
#include <vector>
#include "vector2.h"
#include "GL\glew.h"
#include "Texture.h"

class Sprite
	
{
	friend class SpriteBatch;
public:
	Sprite();
	~Sprite() {};

	void setTexture(Texture *tex);
	vector2f getTextureSize();

	void setPosition(vector2f);
	vector2f getPosition();

	void setSourceRPosition(vector2f position);
	vector2f getSourceRPosition();

	void setSourceRSize(vector2f size);
	vector2f getSourceRSize();

	void setOrigin(vector2f origin);
	vector2f getOrigin();
	
	void Sprite::setSize(vector2f size);;
	vector2f getSize();

	void setColorRGB(float red, float blue, float green);

	float getColorR();
	float getColorG();
	float getColorB();

	void createVertexData(); // vanha, kaikki muutetaan.
	void createIndexData(); // luo kulmasonnan

	GLsizei getIndexSize();
	GLsizei getVertexSize();
	GLfloat* getVertexPointer();
	GLuint* getIndexPointer();

private:


	Texture *texture;
	// n�� on jotai kummajasia
	GLfloat *vertexData;
	GLuint *indexData;
	//
	vector2f position;
	vector2f origin;
	vector2f size;
	GLfloat red, blue, green;
	vector2f sourceRectSize;
	vector2f sourceRectPosition;
	GLfloat VERTEX_DATA[28];
	GLuint INDEX_DATA[6];

	bool colorChanged;
	bool positionChanged;
	bool texturePositionChanged;
	void changePositionData();
	void changeColorData();
	void changeTexturePosition();


};

