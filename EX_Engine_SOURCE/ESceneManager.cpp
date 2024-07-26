#include "ESceneManager.h"

void EX::SceneManager::Initialize()
{

}

void EX::SceneManager::Update()
{
	mActiveScene->Update();
}

void EX::SceneManager::LateUpdate()
{
}

void EX::SceneManager::Render(HDC hdc)
{
}
