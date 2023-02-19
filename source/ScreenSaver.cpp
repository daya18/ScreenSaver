#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void debugMessageCallback ( GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam )
{
	std::string type_string =
		type == GL_DEBUG_TYPE_ERROR ? "Error"
		: type == GL_DEBUG_TYPE_PERFORMANCE ? "Performance"
		: type == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR ? "Undefined Behaviour" : "Unknown type";

	std::cerr << "OpenGL " << type_string << ": " << message << std::endl;
}

void glfwErrorCallback ( int code, const char* description )
{
	std::cout << "GLFW Error " << code << ": " << description << std::endl;
}

int main()
{
	glfwSetErrorCallback ( glfwErrorCallback );
	glfwInit ();
	
	glfwWindowHint ( GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE );
	GLFWwindow* window = glfwCreateWindow ( 1000, 800, "ScreenSaver", nullptr, nullptr );
	
	glfwMakeContextCurrent ( window );
	gladLoadGL ();
	
	glEnable ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback ( debugMessageCallback, nullptr );

	while ( ! glfwWindowShouldClose ( window ) )
	{
		glClearColor ( 0, 0, 0, 1 );
		glClear ( GL_COLOR_BUFFER_BIT );

		glfwSwapBuffers ( window );
		glfwPollEvents ();
	}

	return 0;
}

