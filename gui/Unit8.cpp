//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit7.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BackClick(TObject *Sender)
{
	Form7->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Week11Click(TObject *Sender)
{
	Form9->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
