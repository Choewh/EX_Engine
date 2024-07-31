#pragma once

namespace EX::enums {

	enum class eLayerType
	{
		None,
		Background,
		Player,
		Max = 16
	 };

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}