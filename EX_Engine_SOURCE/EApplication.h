#pragma once
#include "CommonInclude.h"
#include "EGameObject.h"

namespace EX
{
	class Application
	{
	public:
		Application();	//생성자
		~Application();	//소멸자

		void Initialize(HWND Hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		GameObject mPlayer;
	};
}

