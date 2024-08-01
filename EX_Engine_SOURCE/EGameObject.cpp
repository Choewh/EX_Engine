#include "EGameObject.h"
#include "EInput.h"
#include "ETime.h"
#include "ETransform.h"

namespace EX 
{
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		InitializeTransform();
	}
	GameObject::~GameObject() 
	{

	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void GameObject::Update() 
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void GameObject::LateUpdate() 
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC mHdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(mHdc);
		}
	}

	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}

}