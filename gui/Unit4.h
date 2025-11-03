//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Week5Click(TObject *Sender)
{
	Form5->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BackClick(TObject *Sender)
{
	Form3->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
