#pragma once
#include "..\\EX_Engine_SOURCE\\EGameObject.h"
namespace EX {
	class Player : public GameObject
	{
	public :
		
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
