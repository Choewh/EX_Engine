#include "EGameObject.h"
#include "EInput.h"
#include "ETime.h"
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
		const float speed = 100.0f;
		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate() 
	{
	
	}

	void GameObject::Render(HDC mHdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));        //핸들선언과 동시에 초기화
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush);    //이전핸들 저장
		Ellipse(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);           //브러쉬 사용
		(HBRUSH)SelectObject(mHdc, oldbrush);                       //이전브러쉬 되돌려놓기
		DeleteObject(bluebrush);                                    //사용했던 브러쉬 삭제
	}


}