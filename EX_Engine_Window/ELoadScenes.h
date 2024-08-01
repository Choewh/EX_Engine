#pragma once
#include "..\\EX_Engine_SOURCE\ESceneManager.h"
#include "EPlayScene.h"
#include "ETitleScene.h"

namespace EX 
{


	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}