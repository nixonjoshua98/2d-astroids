
#include "JN_Shader.h"
#include "JN_Logging.h"

#include <fstream>


// Default constructor
Shader::Shader()
{

}


// Constructor overload
Shader::Shader(ShaderType type, std::string path)
{
	this->type = type;
	
	Load(path);
	Compile();
}


// Load the shader file into memory
void Shader::Load(std::string path)
{
	std::ifstream inFile("./Shaders/" + path);

	while (inFile.good())
	{
		std::string line;
		std::getline(inFile, line);
		shaderText.append(line + "\n");
	}

	codePtr = shaderText.c_str();

	JN_AppendLog("Loaded " + path);
}


// Compile the shader program
void Shader::Compile()
{
	switch (type)
	{
	case ShaderType::Vertex:
		shaderID = glCreateShader(GL_VERTEX_SHADER);
		break;

	case ShaderType::Fragment:
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);
		break;

	default:
		break;
	}

	glShaderSource(shaderID, 1, &codePtr, NULL);
	glCompileShader(shaderID);

	GLint success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
		JN_AppendLog("ERROR::SHADER::COMPILATION_FAILED");
}


GLuint Shader::GetShaderID()
{
	return shaderID;
}