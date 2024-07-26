#include "EInput.h"
namespace EX 
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Z','X','C',
			'W',			   VK_UP,
		'A','S','D',  VK_LEFT,VK_DOWN,VK_RIGHT,
		' ',
	};

	void Input::Initailize()
	{
		creatKeys();
	}
	void Input::creatKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
    /********************************/
	void Input::UpdateKeys()
	{
		for (auto& key : mKeys)
		{
			updateKey(key);
		}
	}
	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.KeyCode))
		{
			updateKeydown(key);
		}
		else
		{
			updateKeyup(key);
		}
	}
	/********************************/
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeydown(Input::Key& key)
	{
		if (mKeys[(UINT)key.KeyCode].bPressed == true)
			mKeys[(UINT)key.KeyCode].state = eKeyState::Pressed;
		else
			mKeys[(UINT)key.KeyCode].state = eKeyState::Down;

		mKeys[(UINT)key.KeyCode].bPressed = true;
	}
	void Input::updateKeyup(Input::Key& key)
	{
			if (mKeys[(UINT)key.KeyCode].bPressed == true)
				mKeys[(UINT)key.KeyCode].state = eKeyState::Up;
			else
				mKeys[(UINT)key.KeyCode].state = eKeyState::None;

			mKeys[(UINT)key.KeyCode].bPressed = false;
	}

}
