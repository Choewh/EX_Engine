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
		  W,			 Up,
		A,S,D,N,	Left,Down,Right,
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

		static void UpdateKeys();


		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }		
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static std::vector<Key> mKeys;
		static void creatKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeydown(Input::Key& key);
		static void updateKeyup(Input::Key& key);
	};

}
