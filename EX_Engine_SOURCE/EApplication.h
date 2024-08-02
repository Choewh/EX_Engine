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

		void Initialize(HWND Hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();


		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		void adjustWindowRect(HWND Hwnd, UINT width, UINT height);
		void creatBuffer(UINT width, UINT height);
		void InitailizeEtc();
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBuffer; //도화지 , 바탕 ,

		UINT mWidth;
		UINT mHeight;
		//std::vector<Scene*> mScenes;
		std::vector<GameObject*> mGameObjects;
	};
}

