#pragma once
#include "dxwidget.h"     // base class: SDXWidget
#include "sliderv.h"       // for SSliderV
#include "../core/darray.h"      // for SDArray<T>

struct SListBoxItem {
	char ItemText[261];
	unsigned int ItemData;
	unsigned int Color;
};

struct SListBox : public SDXWidget
{
    int Font;                       
    int VisibleTextLines;           
    int MaxInnerTextLines;          
    int MarginLeft;             
    int MarginRight;         
    int MarginTop;              
    int MarginBottom;            
    int SliderMarginLeft;      
    int SliderMarginRight;     
    int SliderMarginTop;        
    int SliderMarginBottom;    

    int* TextLineFrames;        
    int* TextLineBackFrames;     

    bool scrollbars;              
    bool SelectAble;            
    char padding_1C2[2];         

    SSliderV Slider;              

    bool nobreaklines;          
    char padding_3B9[3];        

    int aligntext;                
    bool alignverticalcenter;       
    char padding_3C1[3];         

    int CurActive;               
    int RowHeight;                 
    int LastClickTime;             
    SDarray m_ListBoxItems;
    SListBoxItem m_ListBoxItem;     


    int m_nCurSel;                  
    int m_nTopIndex;               
};
