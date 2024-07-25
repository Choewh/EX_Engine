#pragma once
namespace EX{
class Board
{

public:
	Board();
	~Board();
	Board(int w, int h)
	{
		mW = w;
		mH = h;
	}
private:
	int mW;
	int mH;
};
}
