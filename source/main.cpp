//////////////////////////////////////////////////////////////////////////
#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/glfw.h>
#include <vector>
#include "Utilities.h"
#include "Camera.h"

#include "PlaneNode.h"//Use your Mesh instead;





using namespace AIE;

//////////////////////////////////////////////////////////////////////////
void InitOpenGL();

void Run();
void Update(float fDeltaTime);
void Draw();
void MakeStuff();

bool m_bFullscreen = false;
Camera* m_poCamera;
PlaneNode*	m_poWaterPlane;
Quaternion	m_qPlaneRot;
SceneNode* g_Scene;
std::vector<MeshNode*>	NodesToRender;

//////////////////////////////////////////////////////////////////////////
int main()
{

	g_Scene = new SceneNode(vec4(0,0,0,0),nullptr);


	
	Run();




	// shutdown GLFW
	glfwTerminate();

	// return success
	return 0;
}
void MakeStuff()
{
	m_poCamera = new Camera();
	m_poCamera->SetCameraPosition( AIE::vec4(0.f, 7.f, -80.f, 1.f) );
	
	m_poWaterPlane = new PlaneNode(100.f, 100.f, 100, 100, AIE::vec4(0.f, 0.f, 0.f, 1.f));
	m_poWaterPlane->SetTexture( LoadTexture("./images/crate_sideup.png") );
	


	NodesToRender.push_back(m_poWaterPlane);
}

//////////////////////////////////////////////////////////////////////////
void InitOpenGL()
{
	// start GLFW and open a window
	glfwInit();

	// get the desktop mode
	GLFWvidmode oMode;
	glfwGetDesktopMode(&oMode);

	// open a window
	glfwOpenWindow(	1280, 720,	// resolution
					oMode.RedBits,oMode.GreenBits,oMode.BlueBits,0,	// bits per colour channel (RGBA)
					24,			// depth bits
					8,			// stencil bits
					m_bFullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW); // set windowed or fullscreen mode);
	glfwSetWindowTitle("New AIE Framework");

	// start GLEW
	if (glewInit() != GLEW_OK)
	{	// OpenGL didn't start-up! shutdown GLFW and return an error code
		glfwTerminate();
	}



	// set clear colour
	glClearColor(0.25f,0.25f,0.25f,1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// start our timer
	AIE::ResetTimer();
}

void Run()
{
	InitOpenGL();
	MakeStuff();

	do
	{
		float fDeltaTime = AIE::GetDeltaTime();
		if( fDeltaTime > 1/60.f )
			fDeltaTime = 1/60.f;

		glClear(GL_COLOR_BUFFER_BIT);
	
		Update(fDeltaTime);
		
		Draw();

		glfwSwapBuffers();
	} while ( glfwGetKey( GLFW_KEY_ESC ) == GLFW_RELEASE &&
		glfwGetWindowParam( GLFW_OPENED ) != 0 );
	
}
//////////////////////////////////////////////////////////////////////////
void Update(float fDeltaTime)
{
	fDeltaTime = GetDeltaTime();

 

	
}

//////////////////////////////////////////////////////////////////////////
void Draw()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	std::vector<MeshNode*>::iterator iter = NodesToRender.begin();
	while(iter != NodesToRender.end())
	{
		(*iter)->Draw();
	}
}

//////////////////////////////////////////////////////////////////////////
