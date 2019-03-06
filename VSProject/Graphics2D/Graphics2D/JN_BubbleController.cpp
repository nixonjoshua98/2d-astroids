#include "JN_BubbleController.h"
#include "JN_Logging.h"
#include "JN_Shader.h"


JN_BubbleController::JN_BubbleController(glm::mat4& _projectionMatrix, glm::mat4& _viewMatrix): projectionMatrix(_projectionMatrix), viewMatrix(_viewMatrix)
{
	JN_AppendLog("BubbleController created");
}



JN_BubbleController::~JN_BubbleController()
{
	JN_AppendLog("BubbleController destroyed");

	DeleteAllBubbles();
}



void JN_BubbleController::Init()
{
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
		b->Render(shaderProgram, glm::value_ptr(viewMatrix), glm::value_ptr(projectionMatrix));
}


void JN_BubbleController::AddBubble(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		bubbles.push_back(new JN_Bubble());
		bubbles.back()->Init();
	}
}


void JN_BubbleController::LoadShaders()
{
	shaderProgram = glCreateProgram();

	JN_Shader frag = JN_Shader(JN_Shader::ShaderType::Fragment, "Shader.frag");
	JN_Shader vert = JN_Shader(JN_Shader::ShaderType::Vertex, "Shader.vert");

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
