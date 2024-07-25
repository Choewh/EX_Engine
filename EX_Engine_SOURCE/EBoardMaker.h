#pragma once
#include "CommonInclude.h"
#include "EBoard.h"

#define BoradPos 100 , 100
#define BoradPosX 100
#define BoradPosY 100
#define BoradW 150
#define BoradH 450
#define BlockG 15

namespace EX {

	class BoardMaker
	{
	public:		
		BoardMaker();
		~BoardMaker();
		void Init(int W, int H);

	private:
		Board* mBoard;
	};
}
