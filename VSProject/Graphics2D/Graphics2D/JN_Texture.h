#ifndef JN_TEXTURE_H
#define JN_TEXTURE_H

#include <GL/glew.h>
#include <SDL.h>
#include <string>

namespace TextureConstants
{
	extern const std::string TEXTURE_DIR;
}

class JN_Texture
{
public:
	~JN_Texture();

	void Load(std::string file);	// Loads the texture
	void SetBuffers();	
	GLuint GetTexture();

private:
	SDL_Surface* surface;			// SDL surface - Temp storage for the texture
	GLuint texture;					// Gl version of the texture
};


#endif // !JN_TEXTURE_H
