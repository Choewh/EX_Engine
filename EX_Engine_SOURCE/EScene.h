#pragma once
#include "EEntity.h"
#include "EGameObject.h"
namespace EX {

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> mGameObjects;
	};

}