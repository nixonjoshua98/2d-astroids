#ifndef JN_SHADER_H
#define JN_SHADER_H

#include <GL/glew.h>
#include <string>
#include <fstream>

class Shader
{
public:
	enum class ShaderType { Fragment, Vertex };

	Shader();									// Default constructor
	Shader(ShaderType type, std::string path);	// Load the shader code from a text file
	~Shader();									// Deconstructor

	/* - - - - GETS - - - -*/
	GLuint GetShaderID();

	const GLchar* codePtr;
	std::string shaderText;

private:
	GLuint shaderID;
	ShaderType type;

	void Load(std::string path);
	void Compile();
};

#endif // !JN_SHADER_H