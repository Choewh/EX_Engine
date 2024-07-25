#pragma once
#include "CommonInclude.h"
namespace EX {

	enum class eKeyState : unsigned char
	{
		None,
		Down,
		Pressed,
		Up,
	};

	enum class eKeyCode : unsigned char
	{
		Z,X,C,
		Space,
		End, //끝
	};
	class Input
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};
		
		static void Initailize();

		static void Update();


		static bool GetKeyDown(eKeyCode code);
		static bool GetKeyUp(eKeyCode code);
		static bool GetKey(eKeyCode code);

	private:
		//eKeyState mState = eKeyState::Up;
		static std::vector<Key> mKeys;
	};

}
