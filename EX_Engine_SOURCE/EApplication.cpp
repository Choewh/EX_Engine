#include "EApplication.h"
#include "EInput.h"
#include "ETime.h"
#include "ESceneManager.h"
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
		adjustWindowRect(Hwnd, width, height);
		creatBuffer(width, height);
		InitailizeEtc();

		for (size_t i = 0; i < 50; i++)
		{
			GameObject* gameObj = new GameObject();
			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}


	}
	void Application::InitailizeEtc()
	{
		Input::Initailize();
		Time::Initailize();

		SceneManager::Initialize();
	}
	void Application::adjustWindowRect(HWND Hwnd, UINT width, UINT height)
	{
		mHwnd = Hwnd;
		mHdc = GetDC(Hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);
	}
	void Application::creatBuffer(UINT width, UINT height)
	{
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
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

		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();

	}
	void Application::Render()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
		
		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		//
		BitBlt(mHdc, 0, 0, mWidth , mHeight
			,mBackHdc, 0, 0, SRCCOPY);
	}

}