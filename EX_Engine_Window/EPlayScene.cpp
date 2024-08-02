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
#include "ECamera.h"
#include "ERenderer.h"

namespace EX {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Scene::Initialize();
		{
			//main camera
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
			Camera* cameracomp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameracomp;

			mPlayer = object::Instantiate<Player>(enums::eLayerType::Player,Vector2(800,450));
			SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
			graphics::Texture* text = (Resources::Find<graphics::Texture>(L"PacMan0"));
			sr->SetTexture(text);
			mPlayer->AddComponent<PlayerScript>();
			cameracomp->SetTarget(mPlayer);
			mPlayer->Initialize();
			camera->Initialize();
		}
		{
			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Background);
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			graphics::Texture* text = (Resources::Find<graphics::Texture>(L"MAP"));
			sr->SetTexture(text);
			bg->Initialize();
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EX::eKeyCode::N))
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
