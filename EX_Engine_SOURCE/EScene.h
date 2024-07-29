#pragma once
#include "EEntity.h"
#include "EGameObject.h"
namespace EX {

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameobj);

	private:
		std::vector<GameObject*> mGameObjects;
	};

}