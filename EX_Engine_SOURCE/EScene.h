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

		virtual void OnEnter(); //씬 입장
		virtual void OnExit();  //씬 퇴장

		void AddGameObject(GameObject* gameobj);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}