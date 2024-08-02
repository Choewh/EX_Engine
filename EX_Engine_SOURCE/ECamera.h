#pragma once
#include "EComponent.h"

namespace EX {

	using namespace math;
	class Transform;
	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		GameObject* SetTarget(GameObject* target) { return mTarget = target; }

	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mLookPosition;
		Vector2 mResolution;
		Transform* Cameratr;
	};

}


class Camera
{
};
