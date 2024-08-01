#include "EPlayerScript.h"
#include "EInput.h"
#include "ETime.h"
#include "ETransform.h"
#include "EPlayer.h"

namespace EX {
	PlayerScript::PlayerScript()
		:Script()
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			//현재 컴포넌트를 가지고있는 게임 오브젝트 - > Getcomp -> tr 반환
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			//현재 컴포넌트를 가지고있는 게임 오브젝트 - > Getcomp -> tr 반환
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}

}