#include "EAnimation.h"
#include "ETime.h"
#include "EAnimator.h"
#include "EGameObject.h"
#include "ETransform.h"
#include "ERenderer.h"
#include "ECamera.h"
namespace EX {
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		,mAnimator(nullptr)
		,mTexture(nullptr)
		,mAnimationSheet{}
		,mIndex(-1)
		,mTime(0.0f)
		,mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		//알파블랜드를 쓸 수 있는 조건 : 해당이미지 알파채널이 존재해야함.
		//AlphaBlend();

		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255 (Opaque) // 알파 채널이 추가된 bmp 만 가능

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHDC();

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) 
		{
			/*AlphaBlend(hdc
				, pos.x, pos.y
				, sprite.size.x, sprite.size.y
				, imgHdc
				, sprite.leftTop.x, sprite.leftTop.y
				, sprite.size.x, sprite.size.y
				, func);*/
			TransparentBlt(hdc, pos.x, pos.y, sprite.size.x , sprite.size.y,
				imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y,
				RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y,
					  10*sprite.size.x, 10*sprite.size.y));
		}
	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spritesheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration)
	{
		mTexture = spritesheet;
		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}