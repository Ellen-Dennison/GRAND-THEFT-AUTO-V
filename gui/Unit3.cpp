//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BackClick(TObject *Sender)
{
	Form2->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Week2Click(TObject *Sender)
{
	Form4->Show();
    this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::AddPlantClick(TObject *Sender)
{
    // Clear the ListBox first
    ListBox1->Clear();

    // Add all the plant creation items with bullets
    ListBox1->Items->Add("• Creating Rose Flower");
    ListBox1->Items->Add("  - Rose (Flower) added to greenhouse - R89.99");
    ListBox1->Items->Add("• Creating Rose Flower");
    ListBox1->Items->Add("  - Rose (Flower) added to greenhouse - R89.99");
    ListBox1->Items->Add("• Creating Tulip Flower");
    ListBox1->Items->Add("  - Tulip (Flower) added to greenhouse - R65.5");
    ListBox1->Items->Add("• Creating Orchid Flower");
    ListBox1->Items->Add("  - Orchid (Flower) added to greenhouse - R125");
    ListBox1->Items->Add("• Creating Basil herb");
    ListBox1->Items->Add("  - Basil (Herb) added to greenhouse - R65");
    ListBox1->Items->Add("• Creating Rosemary herb");
    ListBox1->Items->Add("  - Rosemary (Herb) added to greenhouse - R72.5");
    ListBox1->Items->Add("• Creating Aloe Vera Succulent");
    ListBox1->Items->Add("  - Aloe Vera (Succulent) added to greenhouse - R55");
    ListBox1->Items->Add("• Creating Cactus Succulent");
    ListBox1->Items->Add("  - Cactus (Succulent) added to greenhouse - R45.5");
    ListBox1->Items->Add("• Creating Oak Tree");
    ListBox1->Items->Add("  - Oak (Tree) added to greenhouse - R450");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::WorkDayClick(TObject *Sender)
{
    // Clear the ListBox first
    ListBox2->Clear();

    // Add Kobe's work day activities
    ListBox2->Items->Add("Kobe clocking in...");
    ListBox2->Items->Add("");
    ListBox2->Items->Add("---Morning Shift---");
    ListBox2->Items->Add("Kobe is starting morning greenhouse care");
    ListBox2->Items->Add("Morning: Watering 9 plants");
    ListBox2->Items->Add("Daily watering applied (500ml)");
    ListBox2->Items->Add("Health +15");
    ListBox2->Items->Add("Daily watering applied (500ml)");
    ListBox2->Items->Add("Health +15");
    ListBox2->Items->Add("Daily watering applied (500ml)");
    ListBox2->Items->Add("Health +15");
    ListBox2->Items->Add("Daily watering applied (500ml)");
    ListBox2->Items->Add("Health +15");
    ListBox2->Items->Add("Bi-weekly watering applied (350ml)");
    ListBox2->Items->Add("Health +10");
    ListBox2->Items->Add("Bi-weekly watering applied (350ml)");
    ListBox2->Items->Add("Health +10");
    ListBox2->Items->Add("Weekly watering applied (250ml)");
    ListBox2->Items->Add("Health +5");
    ListBox2->Items->Add("Weekly watering applied (250ml)");
    ListBox2->Items->Add("Health +5");
    ListBox2->Items->Add("Weekly watering applied (250ml)");
    ListBox2->Items->Add("Health +5");
	ListBox2->Items->Add(" Watered 9 plants");
    ListBox2->Items->Add("Kobe taking lunch break");
    ListBox2->Items->Add("");
    ListBox2->Items->Add("---Afternoon Shift---");
    ListBox2->Items->Add("Kobe is starting afternoon greenhouse duties");
    ListBox2->Items->Add("Afternoon: Providing sunlight and fertilizer");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Providing full sun exposure - Health +3");
    ListBox2->Items->Add("Fertilizing plant - Health +8");
    ListBox2->Items->Add("Harvest Time!");
    ListBox2->Items->Add("");
    ListBox2->Items->Add("Checking for plants ready to harvest...");
    ListBox2->Items->Add("No plants ready for harvest yet.");
    ListBox2->Items->Add("");
    ListBox2->Items->Add("Sales Floor: Empty");
    ListBox2->Items->Add("Final health check...");
    ListBox2->Items->Add("");
    ListBox2->Items->Add("Checking for wilting plants...");
    ListBox2->Items->Add("All plants are healthy!");
    ListBox2->Items->Add("Kobe clocking out...");
}
//---------------------------------------------------------------------------
