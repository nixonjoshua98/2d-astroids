

#include "JN_Texture.h"
#include "JN_Logging.h"

#include <SDL_image.h>
#include <iostream>

extern const std::string TextureConstants::TEXTURE_DIR = "./Resources/Textures/";


JN_Texture::~JN_Texture()
{
	SDL_FreeSurface(surface);

	surface = NULL;
}



void JN_Texture::Load(std::string file)
{
	std::string path = TextureConstants::TEXTURE_DIR + file;

	surface = IMG_Load(path.c_str());

	if (surface == NULL)
		JN_AppendLog(file + " failed to load");
	else
	{
		JN_AppendLog(file + " loaded OK");
		SetBuffers();
	}
}



void JN_Texture::SetBuffers()
{
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texture parameters on currently bound texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint JN_Texture::GetTexture()
{
	return texture;
}