#include "dxwidget.h"  // base class
#include "../common/swineversion.h" // SString
struct STextButton : SDXWidget
{
	int Font;
	int TextFrame;
	int Align;
	SString Text;
};