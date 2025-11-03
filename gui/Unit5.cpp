//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit6.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Week6Click(TObject *Sender)
{
	  Form6->Show();
	  this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::BackClick(TObject *Sender)
{
	Form4->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DisplayRolesClick(TObject *Sender)
{
    String text =
		"Adding landscaper role to Kobe\n"
        "[Additional Role: Landscaper]\n"
        "  • Maintain outdoor displays\n"
        "  • Design garden arrangements\n"
        "  • Prune and shape plants\n"
		"  • Keep landscapes attractive\n";

    // Assuming your memo is called Memo1
	Memo2->Lines->Text = text;
}
//---------------------------------------------------------------------------
