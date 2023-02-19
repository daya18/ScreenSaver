int main()
{
	glfwSetErrorCallback ( glfwErrorCallback );
	glfwInit ();
	
	GLFWwindow* window = glfwCreateWindow ( 1000, 800, "ScreenSaver", nullptr, nullptr );
	
	glfwMakeContextCurrent ( window );
	gladLoadGL ();
	
	while ( ! glfwWindowShouldClose ( window ) )
	{
		glClearColor ( 0, 0, 0, 1 );
		glClear ( GL_COLOR_BUFFER_BIT );

		glfwSwapBuffers ( window );
		glfwPollEvents ();
	}

	return 0;
}

