#include "EGameObject.h"

namespace EX 
{
	GameObject::GameObject()
		:mX(0)
		,mY(0)
	{
		
	}
	GameObject::~GameObject() 
	{

	}

	void GameObject::Update() 
	{
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))
		{
			mX += 0.01f;
		}
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			mX -= 0.01f;
		}
		if ((GetAsyncKeyState(VK_UP) & 0x8000))
		{
			mY -= 0.01f;
		}
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate() 
	{
	
	}

	void GameObject::Render(HDC mHdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));        //핸들선언과 동시에 초기화
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush);    //이전핸들 저장
		Ellipse(mHdc, 400 + mX, 400 + mY, 500 + mX, 500 + mY);           //브러쉬 사용
		(HBRUSH)SelectObject(mHdc, oldbrush);                       //이전브러쉬 되돌려놓기
		DeleteObject(bluebrush);                                    //사용했던 브러쉬 삭제
	}


}