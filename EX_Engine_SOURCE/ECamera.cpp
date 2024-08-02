#include "EGameObject.h"
#include "ECamera.h"
#include "ETransform.h"
#include "EApplication.h"

extern EX::Application application;

namespace EX {
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		,mDistance(Vector2::Zero)
		,mResolution(Vector2( 1600.0f , 900.0f ))
		,mLookPosition(Vector2::Zero)
		,mTarget(nullptr)
		,Cameratr(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		Cameratr = GetOwner()->GetComponent<Transform>();
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		//Cameratr->SetPos(Vector2(mResolution));
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else
			mLookPosition = Cameratr->GetPosition();
	
		mDistance = mLookPosition - (mResolution / 2 );
	}
	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{
		int intX = static_cast<int>(mLookPosition.x);
		int intY = static_cast<int>(mLookPosition.y);
		std::wstring x = std::to_wstring(intX);
		std::wstring y = std::to_wstring(intY);
		x += ':';
		x += y;
		const wchar_t* x1 = x.c_str();
		TextOut(hdc, 0, 20, x1 , 10);
	}
}
