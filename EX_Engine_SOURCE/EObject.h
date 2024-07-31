#pragma once
#include "EComponent.h"
#include "EGameObject.h"
#include "ETransform.h"
#include "ELayer.h"
#include "ESceneManager.h"
#include "EScene.h"

namespace EX::object
{
	template<typename T>
	static T* Instantiate(EX::enums::eLayerType type)
	{
		T* gameobject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameobject);

		return gameobject;
	}

	template<typename T>
	static T* Instantiate(EX::enums::eLayerType type, math::Vector2 pos)
	{
		T* gameobject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameobject);
		Transform* tr = gameobject->GetComponent<Transform>();
		tr->SetPos(pos);

		return gameobject;
	}
}