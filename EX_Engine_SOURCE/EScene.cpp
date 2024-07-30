#include "EScene.h"

namespace EX {
	Scene::Scene()
		: mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		for (GameObject* mGameObject : mGameObjects)
		{
			mGameObject->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* mGameObject : mGameObjects)
		{
			mGameObject->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameobj)
	{
		mGameObjects.push_back(gameobj);
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}
}