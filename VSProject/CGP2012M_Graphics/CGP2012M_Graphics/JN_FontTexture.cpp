#include "JN_FontTexture.h"
#include "JN_Logging.h"

#include <SDL_image.h>


JN_FontTexture::JN_FontTexture()
{

}


JN_FontTexture::~JN_FontTexture()
{

}

void JN_FontTexture::Load(std::string file)
{
	surface = IMG_Load(file.c_str());

	if (surface == NULL)
		JN_AppendLog(file + " failed to load");
	else
	{
		JN_AppendLog(file + " loaded OK");
		SetBuffers();
	}
}

void JN_FontTexture::SetBuffers()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (surface->format->BytesPerPixel == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);

	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

	glBindTexture(GL_TEXTURE_2D, 0);

	SDL_FreeSurface(surface);
}