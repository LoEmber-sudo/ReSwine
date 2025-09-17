#pragma once
#include "widget.h"  // base class

struct SDXWidget : SWidget // sizeof=x
 {                                     
		 int BakFrame;
	     int BakFont;
	     int BakGlyph;
	     unsigned int Bakolor;
	     bool BakNoresize;
	     bool Bak9Slie;

		 int TooltipTimer;
	     int TooltipEndTimer;
	     int TooltipBakFrame;
	     int InnerBakFrame;
	     int TooltipFrame;
	     int TooltipFont;
	     int TooltipFrameLeft;
	     int TooltipFrameMiddle;
	     int TooltipFrameRight;
	     char TooltipText[2];
	     int ToolTipTextWidth;
	     int ToolTipTextHeight;
	     bool ToolTipFeatureEnabled;
		 };
