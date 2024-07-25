#include "EBoardMaker.h"
#include "EBoard.h"

namespace EX 
{
	BoardMaker::BoardMaker()
	{

	}
	BoardMaker::~BoardMaker()
	{

	}

	void BoardMaker::Init(int W, int H)
	{
		mBoard = new Board(W, H);
	}
}