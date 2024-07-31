#include "EGameObject.h"
#include "EInput.h"
#include "ETime.h"
#include "ETransform.h"

namespace EX 
{
	GameObject::GameObject()
	{
		InitializeTransform();
	}
	GameObject::~GameObject() 
	{

	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update() 
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate() 
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC mHdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(mHdc);
		}
	}

	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}

}