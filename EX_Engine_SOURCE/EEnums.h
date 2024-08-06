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
		Animation,
		Prefab,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};
}