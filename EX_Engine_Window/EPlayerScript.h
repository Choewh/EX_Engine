#pragma once
#include "..\\EX_Engine_SOURCE\\EScript.h"

namespace EX {

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


	};

}