#pragma once
#include "EEntity.h"
#include "CommonInclude.h"
#include "EGameObject.h"

namespace EX {
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameobj);

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}
