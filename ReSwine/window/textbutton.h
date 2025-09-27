#include "dxwidget.h"  // base class
#include "../common/version.h" // SString
struct STextButton : SDXWidget
{
	int Font;
	int TextFrame;
	int Align;
	SString Text;
};