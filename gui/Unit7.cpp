//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit6.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	Form6->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Week10Click(TObject *Sender)
{
	Form8->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
