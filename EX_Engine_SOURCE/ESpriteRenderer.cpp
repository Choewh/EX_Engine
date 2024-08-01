#include "ESpriteRenderer.h"
#include "EGameObject.h"
#include "ETransform.h"
#include "ETexture.h"
#include "EMath.h"

namespace EX {
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
		,mTexture(nullptr)
		,mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();		
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//TransparentBlt(핸들,이미지 출력 위치 x,y , 출력할 크기 가로 세로 ,
			//					핸들 , 출력할 이미지의 x,y, 크기,투명하게 할 색상)
			TransparentBlt(hdc, 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				mTexture->GetHDC(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, 
					mTexture->GetWidth() * mSize.x , mTexture->GetHeight() * mSize.y ));

		}
	}
}