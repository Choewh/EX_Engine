#pragma once
#include "CommonInclude.h"

namespace EX {
	
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }
	private:
		static LARGE_INTEGER CpuFrequency; // 내 컴퓨터의 cpu 초당 진동수
		static LARGE_INTEGER PrevFrequency; // 내 컴퓨터의 이전 진동수
		static LARGE_INTEGER CurrentFrequency; // 내 컴퓨터의 이전 진동수
		static float DeltaTimeValue;



	};

}

