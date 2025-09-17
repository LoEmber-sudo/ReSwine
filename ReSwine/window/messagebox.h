#include "dialog.h"
#include "textbutton.h"
#include "listbox.h"
struct SMessageBox : SDialog
 { 
	STextButton OKButton;       
	STextButton YesButton;            
	STextButton NoButton;             
	STextButton RetryButton;        
	STextButton IgnoreButton;        
	STextButton CancelButton;     
	SListBox ListBox;                 
	int Type;
};