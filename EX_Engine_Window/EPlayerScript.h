#pragma once
#include "..\\EX_Engine_SOURCE\\EScript.h"

namespace EX {

	class Transform;
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

		Transform* tr;
		math::Vector2 pos;
	};

}