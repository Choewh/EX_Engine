#pragma once
#include "..\\EX_Engine_SOURCE\\EResources.h"
#include "..\\EX_Engine_SOURCE\\ETexture.h"

namespace EX
{


	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"MAP",L"D:\\_KDT3D\\Resources\\background.png");
		Resources::Load<graphics::Texture>(L"PacMan0",L"D:\\_KDT3D\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"PacMan1",L"D:\\_KDT3D\\Resources\\img\\pacman\\1.png");
		Resources::Load<graphics::Texture>(L"PacMan2",L"D:\\_KDT3D\\Resources\\img\\pacman\\2.png");
		Resources::Load<graphics::Texture>(L"test",   L"D:\\_KDT3D\\Resources\\img\\stardew\\test.bmp");
		Resources::Load<graphics::Texture>(L"Cat1",   L"D:\\_KDT3D\\Resources\\img\\stardew\\cat.bmp");
		Resources::Load<graphics::Texture>(L"Cat2", L"D:\\_KDT3D\\Resources\\img\\stardew\\CatNew.bmp");
	}
}

//카메라

//크기 조절

//스크립트