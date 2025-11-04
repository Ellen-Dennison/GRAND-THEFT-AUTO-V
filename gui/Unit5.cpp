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
void __fastcall TForm5::WorkDayClick(TObject *Sender)
{
    // Clear the memo first
    Memo1->Lines->Clear();

    // Add Kobe's Expanded Workday to Memo1
    Memo1->Lines->Add("Kobe's Expanded Workday:");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe clocking in...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("---Morning Shift---");
    Memo1->Lines->Add("Performs ongoing morning tasks to keep landscapes healthy and attractive");
    Memo1->Lines->Add("Kobe is starting morning greenhouse care");
    Memo1->Lines->Add("Morning: Watering 9 plants");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("  ✓ Watered 9 plants");
    Memo1->Lines->Add("Kobe taking lunch break");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("---Afternoon Shift---");
    Memo1->Lines->Add("Performs ongoing afternoon tasks to keep landscapes healthy and attractive");
    Memo1->Lines->Add("Kobe is starting afternoon greenhouse duties");
    Memo1->Lines->Add("Afternoon: Providing sunlight and fertilizer");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Harvest Time!");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Checking for plants ready to harvest...");
    Memo1->Lines->Add("No plants ready for harvest yet.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Sales Floor: Empty");
    Memo1->Lines->Add("Final health check...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Checking for wilting plants...");
    Memo1->Lines->Add("All plants are healthy!");
    Memo1->Lines->Add("Kobe clocking out...");
}
//---------------------------------------------------------------------------
