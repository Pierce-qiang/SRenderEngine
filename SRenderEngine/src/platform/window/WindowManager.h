#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace sre
{
	class WindowManager
	{
	public:
		~WindowManager();
		static WindowManager* Instance();

		bool Init(const char* title, int width, int height);

		int GetWidth() { return mWidth; }
		int GetHeight() { return mHeight; }
		bool IsHideCursor() { return mHideCursor; }

		bool IsTerminated();
		void Update();
		static void Clear();	// clear depth, color and stencil buffer
		static void Bind();		// bind the default framebuffer

	private:
		WindowManager();
		static WindowManager* sInstance;



		// callback functions, ��Ԫ��Ϊ�����ǽ��ܵ�GLFW���û�ָ����ת��֮����Է���˽�б���
		// static ��Ϊ����ȥthisָ����Ϊ�����ĵ�һ������
		friend void ErrorCallback(int error, const char* description);
		friend void WindowResizeCallback(GLFWwindow* window, int width, int height);
		friend void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		friend void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		friend void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		
		friend void CharCallback(GLFWwindow* window, unsigned int c);


	private:
		const char* mTitle;
		int mWidth, mHeight;
		bool mHideCursor;
		
		GLFWwindow* mWindow;
	};
}
