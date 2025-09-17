#include "dxwidget.h"  // base class
struct SSliderV : SDXWidget
{
    int SliderFont;
    int ButtonFont;

    int SliderUp;
    int SliderMiddle;
    int SliderDown;
    int SliderBox;
    int ButtonUpFrame;
    int ButtonDownFrame;

    int FirstKlikkTimer;
    int TickTimer;

    int MarginLeft;
    int MarginRight;
    int MarginTop;
    int MarginBottom;

    bool PressedUp;
    bool PressedDown;
    bool ActiveUp;
    bool ActiveDown;
    bool RedBigyoDown;

    int VisibleRows;
    int TopIndex;
    int TopIndexInListBox;
    int NumberOfRows;

    int YSizeOfLittleRedBigyo;
    int YPosOfLittleRedBigyo;
    int XPosRed;
    int XPosLine;
    int DeltaYOfLRB;
    int YDownPosOfLRB;
};
