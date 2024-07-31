#pragma once
#include "EEntity.h"
#include "EComponent.h"

namespace EX {


	class SpriteRenderer : public Component
	{
	public :
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:

	};

}