#include "JN_BubbleController.h"
#include "JN_Logging.h"
#include "JN_Shader.h"



JN_BubbleController::JN_BubbleController()
{
	JN_AppendLog("BubbleController created");
}



JN_BubbleController::~JN_BubbleController()
{
	JN_AppendLog("BubbleController destroyed");

	DeleteAllBubbles();
}



void JN_BubbleController::Init(float aspectRatio)
{
	this->aspectRatio = aspectRatio;

	LoadShaders();

}



void JN_BubbleController::Update()
{
	for (auto b : bubbles)
		b->Update();
}



void JN_BubbleController::Render()
{
	glUseProgram(shaderProgram);

	for (auto b : bubbles)
		b->Render(shaderProgram);
}


void JN_BubbleController::AddBubble()
{
	bubbles.push_back(new JN_Bubble());
	bubbles.back()->Init();
}


void JN_BubbleController::LoadShaders()
{
	shaderProgram = glCreateProgram();

	JN_Shader frag = JN_Shader(JN_Shader::ShaderType::Fragment, "Generic/GenericShader.frag");
	JN_Shader vert = JN_Shader(JN_Shader::ShaderType::Vertex, "Generic/GenericShader.vert");

	glAttachShader(shaderProgram, frag.GetShaderID());
	glAttachShader(shaderProgram, vert.GetShaderID());

	glLinkProgram(shaderProgram);
}


void JN_BubbleController::DeleteAllBubbles()
{
	for (auto b : bubbles)
		delete b;
	bubbles.clear();
}
