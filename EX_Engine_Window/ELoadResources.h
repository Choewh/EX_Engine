#pragma once
#include "..\\EX_Engine_SOURCE\\EResources.h"
#include "..\\EX_Engine_SOURCE\\ETexture.h"

namespace EX
{


	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG",L"D:\\_KDT3D\\Resources\\background.png");
	}
}

//카메라

//크기 조절

//스크립트