#include "EApplication.h"
namespace EX {

	Application::Application()
		: mHwnd(nullptr)
			, mHdc(nullptr)
			, mSpeed(0)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND Hwnd)
	{
		mHwnd = Hwnd;
		mHdc = GetDC(Hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mPlayer.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}

}