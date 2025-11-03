//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BackClick(TObject *Sender)
{
	Form8->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Memo1Click(TObject *Sender)
{
    String text =
        "The team hasn't slept since discovering the sabotage...\n"
        "But there's no time to rest, the plants are dying!\n"
        "It's time to put the Memento Protocol to the ultimate test!";

    Memo1->Lines->Text = text;
}
//---------------------------------------------------------------------------
void __fastcall TForm9::InitiateClick(TObject *Sender)
{
    ListBox1->Clear();

    ListBox1->Items->Add("[Manager Sarah] Plant revival tracked:");
    ListBox1->Items->Add("  Successful Revivals: 1");
    ListBox1->Items->Add("  Revival Success Rate: 100.0%");
    ListBox1->Items->Add("");
    ListBox1->Items->Add("[Kobe (GreenhouseWorker)] Notification received:");
    ListBox1->Items->Add("  → INITIATING EMERGENCY REVIVAL PROTOCOL - ALL HANDS ON DECK!");
    ListBox1->Items->Add("");
    ListBox1->Items->Add("[Naledi (SalesAssociate)] Notification received:");
    ListBox1->Items->Add("  → INITIATING EMERGENCY REVIVAL PROTOCOL - ALL HANDS ON DECK!");
    ListBox1->Items->Add("");
    ListBox1->Items->Add("[Carie (SalesFloorWorker)] Notification received:");
    ListBox1->Items->Add("  → INITIATING EMERGENCY REVIVAL PROTOCOL - ALL HANDS ON DECK!");
    ListBox1->Items->Add("  Carie: Acknowledged.");
    ListBox1->Items->Add("-----------------------------------------");
    ListBox1->Items->Add("Notified 4 active observer(s)");
}
//---------------------------------------------------------------------------
