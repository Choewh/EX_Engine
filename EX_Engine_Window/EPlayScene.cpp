#include "EPlayScene.h"
#include "EGameObject.h"
#include "EPlayer.h"
#include "ETransform.h"
#include "ESpriteRenderer.h"
#include "EInput.h"
#include "ETitleScene.h"
#include "ESceneManager.h"
#include "EObject.h"
#include "ETexture.h"
#include "EResources.h"
#include "EPlayerScript.h"

namespace EX {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//{
			bg = object::Instantiate<Player>(enums::eLayerType::Background, Vector2(0, 0));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			graphics::Texture* text = (Resources::Find<graphics::Texture>(L"BG"));
			sr->SetTexture(text);
			PlayerScript* ps = bg->AddComponent<PlayerScript>();
		//	graphics::Texture* tex = new graphics::Texture();
		//	tex->Load(L"D:\\_KDT3D\\Resources\\background.png");
		//	// sr->ImageLoad(L"D:\\_KDT3D\\Resources\\background.png");
		//}
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
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr
		//	= bg->GetComponent<Transform>();
		//tr->SetPos(Vector2(0, 0));
	}
}
