#include "EAnimator.h"

namespace EX {
	Animator::Animator()
		:Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation{}
		, mbLoop(false)
		
	{

	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() == true
				&& mbLoop == true)
			{
				mActiveAnimation->Reset();
			}

		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	void Animator::CreateAnimation(const std::wstring& name,
		graphics::Texture* spritesheet, 
		Vector2 leftTop, Vector2 size, 
		Vector2 offset, UINT spriteLegth, 
		float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateAnimation(name, spritesheet
			, leftTop, size, offset, spriteLegth,duration);

		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter =	mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
		return nullptr;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}