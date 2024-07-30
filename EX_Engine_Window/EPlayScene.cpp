#include "EPlayScene.h"
#include "EGameObject.h"
#include "EPlayer.h"
#include "ETransform.h"
#include "ESpriteRenderer.h"
#include "EInput.h"
#include "ETitleScene.h"
#include "ESceneManager.h"

namespace EX {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//for (int i = 0; i < 10; i++) {
		//	GameObject* obj = new GameObject();
		//	obj->SetPosition(rand() % 1600, rand() % 900);

		//	AddGameObject(obj);
		//}
		Player* bg = new Player();
		Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"D:\\_KDT3D\\Resources\\background.png");

		AddGameObject(bg);
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EX::eKeyCode::Down))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
}
