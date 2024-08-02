#include "EPlayerScript.h"
#include "EInput.h"
#include "ETime.h"
#include "ETransform.h"
#include "EPlayer.h"

namespace EX {
	PlayerScript::PlayerScript()
		:Script()
		, tr(nullptr)
		, pos(Vector2::Zero)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		tr = GetOwner()->GetComponent<Transform>();
		pos = tr->GetPosition();
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
		int intX = static_cast<int>(pos.x);
		int intY = static_cast<int>(pos.y);
		std::wstring x = std::to_wstring(intX);
		std::wstring y = std::to_wstring(intY);
		x += ':';
		x += y;
		const wchar_t* x1 = x.c_str();
		TextOut(hdc, 0, 40, x1, 10);
	}

}