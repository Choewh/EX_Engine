#include "EApplication.h"
#include "EInput.h"
#include "ETime.h"
namespace EX {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBuffer(nullptr)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND Hwnd, UINT width,UINT height)
	{
		mHwnd = Hwnd;
		mHdc = GetDC(Hwnd);

		RECT rect = {0,0,width,height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, 
			rect.right - rect.left,
			rect.bottom - rect.top , 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 도화지 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		//새로 생성한 BackBuffer를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		Input::Initailize();
		Time::Initailize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::UpdateKeys();
		Time::Update();

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		//
		BitBlt(mHdc, 0, 0, mWidth , mHeight
			,mBackHdc, 0, 0, SRCCOPY);
	}

}