#ifndef JN_FONTTEXTURE_H
#define JN_FONTTEXTURE_H

#include <string>

#include "JN_Texture.h"

class JN_FontTexture : JN_Texture
{
public:
	JN_FontTexture();
	~JN_FontTexture();

	void Load(std::string);

private:
	void SetBuffers();
};

#endif // !JN_FONTTEXTURE_H