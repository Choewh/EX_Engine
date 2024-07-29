#pragma once
#include "..\\EX_Engine_SOURCE\ESceneManager.h"
#include "EPlayScene.h"

namespace EX 
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}