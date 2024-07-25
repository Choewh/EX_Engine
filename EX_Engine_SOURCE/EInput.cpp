#include "EInput.h"
namespace EX 
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Z','X','C',
		' ',
	};

	void Input::Initailize()
	{
		//typedef int DOGUEINT;
		//DOGUEINT a = 0;

		//mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.KeyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed == true;
			}
			else // 키가 안눌렸다
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed == false;
			}
		}
	}

}
