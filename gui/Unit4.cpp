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
void __fastcall TForm4::Week2Click(TObject *Sender)
{
    // Clear both memos first
	Memo1->Lines->Clear();
	Memo2->Lines->Clear();

    // Add Week 2 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 2 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe watering all plants...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Watering Plants ------");
    Memo1->Lines->Add("Watering 9 plant(s)...");
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
    Memo1->Lines->Add("Successfully watered 9 plant(s).");
	Memo1->Lines->Add("===========================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Trevor providing sunlight to all plants...");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe fertilizing all plants...");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Week progressing...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Advancing Time ------");
    Memo1->Lines->Add("Advancing 1 week(s) for 9 plant(s)...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("--- Week 1 ---");
    Memo1->Lines->Add("Week 1 complete: 9 plant(s) aged");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Time advancement complete: 1 week(s) passed.");
    Memo1->Lines->Add("============================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" NOTIFICATION: Week 2 care cycle completed");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Manager Sarah] Week 2 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Kobe (GreenhouseWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 2 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Naledi (SalesAssociate)] Notification received:");
    Memo1->Lines->Add(" -> Week 2 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Carie (SalesFloorWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 2 care cycle completed");
    Memo1->Lines->Add(" Carie: Acknowledged.");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" Notified 4 active observer(s)");
    Memo1->Lines->Add("-----------------------------------------");

    // Add Week 2 PLANT INVENTORY to Memo2
    Memo2->Lines->Add("=== WEEK 2 PLANT INVENTORY ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GREENHOUSE PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("• Orchid (Flower)");
    Memo2->Lines->Add("• Rose (Flower) x2");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("• Tulip (Flower)");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("INVENTORY SUMMARY:");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Greenhouse: 9 plants");
    Memo2->Lines->Add("Sales Floor: 0 plants");
    Memo2->Lines->Add("All plants in Seedling state");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 1 week");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("PLANT STATES:");
    Memo2->Lines->Add("• All plants: Seedling");
    Memo2->Lines->Add("• Health: 100%");
    Memo2->Lines->Add("• Age: 1 week");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("CARE STATISTICS:");
    Memo2->Lines->Add("• Watering: Completed");
    Memo2->Lines->Add("• Sunlight: Completed");
    Memo2->Lines->Add("• Fertilizing: Completed");
    Memo2->Lines->Add("• Week 2 cycle: Complete");
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Week3Click(TObject *Sender)
{
    // Clear both memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();

    // Add Week 3 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 3 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe watering all plants...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Watering Plants ------");
    Memo1->Lines->Add("Watering 9 plant(s)...");
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
    Memo1->Lines->Add("Successfully watered 9 plant(s).");
    Memo1->Lines->Add("===========================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Trevor providing sunlight to all plants...");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe fertilizing all plants...");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Week progressing...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Advancing Time ------");
    Memo1->Lines->Add("Advancing 1 week(s) for 9 plant(s)...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("--- Week 1 ---");
    Memo1->Lines->Add("Week 1 complete: 9 plant(s) aged");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Time advancement complete: 1 week(s) passed.");
    Memo1->Lines->Add("============================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" NOTIFICATION: Week 3 care cycle completed");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Manager Sarah] Week 3 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Kobe (GreenhouseWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 3 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Naledi (SalesAssociate)] Notification received:");
    Memo1->Lines->Add(" -> Week 3 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Carie (SalesFloorWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 3 care cycle completed");
    Memo1->Lines->Add(" Carie: Acknowledged.");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" Notified 4 active observer(s)");
    Memo1->Lines->Add("-----------------------------------------");

    // Add Week 3 PLANT INVENTORY to Memo2
    Memo2->Lines->Add("=== WEEK 3 PLANT INVENTORY ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GREENHOUSE PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("• Orchid (Flower)");
    Memo2->Lines->Add("• Rose (Flower) x2");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("• Tulip (Flower)");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("INVENTORY SUMMARY:");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Greenhouse: 9 plants");
    Memo2->Lines->Add("Sales Floor: 0 plants");
    Memo2->Lines->Add("All plants in Seedling state");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 2 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("PLANT STATES:");
    Memo2->Lines->Add("• All plants: Seedling");
    Memo2->Lines->Add("• Health: 100%");
    Memo2->Lines->Add("• Age: 2 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("CARE STATISTICS:");
    Memo2->Lines->Add("• Watering: Completed");
    Memo2->Lines->Add("• Sunlight: Completed");
    Memo2->Lines->Add("• Fertilizing: Completed");
    Memo2->Lines->Add("• Week 3 cycle: Complete");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GROWTH PROGRESS:");
    Memo2->Lines->Add("• Plants still in Seedling stage");
    Memo2->Lines->Add("• Health maintained at 100%");
    Memo2->Lines->Add("• Ready for growth transition soon");
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Week4Click(TObject *Sender)
{
    // Clear both memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();

    // Add Week 4 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 4 ACTIVITY LOG ===");
	Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe watering all plants...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Watering Plants ------");
    Memo1->Lines->Add("Watering 9 plant(s)...");
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
    Memo1->Lines->Add("Successfully watered 9 plant(s).");
    Memo1->Lines->Add("===========================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Trevor providing sunlight to all plants...");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe fertilizing all plants...");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Week progressing...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Advancing Time ------");
    Memo1->Lines->Add("Advancing 1 week(s) for 9 plant(s)...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("--- Week 1 ---");
    Memo1->Lines->Add("Week 1 complete: 9 plant(s) aged");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Time advancement complete: 1 week(s) passed.");
    Memo1->Lines->Add("============================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" NOTIFICATION: Week 4 care cycle completed");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Manager Sarah] Week 4 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Kobe (GreenhouseWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 4 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Naledi (SalesAssociate)] Notification received:");
    Memo1->Lines->Add(" -> Week 4 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Carie (SalesFloorWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 4 care cycle completed");
    Memo1->Lines->Add(" Carie: Acknowledged.");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" Notified 4 active observer(s)");
    Memo1->Lines->Add("-----------------------------------------");

    // Add Week 4 PLANT INVENTORY to Memo2
    Memo2->Lines->Add("=== WEEK 4 PLANT INVENTORY ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GREENHOUSE PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("• Orchid (Flower)");
    Memo2->Lines->Add("• Rose (Flower) x2");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("• Tulip (Flower)");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("INVENTORY SUMMARY:");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Greenhouse: 9 plants");
    Memo2->Lines->Add("Sales Floor: 0 plants");
    Memo2->Lines->Add("All plants in Seedling state");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 3 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("PLANT STATES:");
    Memo2->Lines->Add("• All plants: Seedling");
    Memo2->Lines->Add("• Health: 100%");
    Memo2->Lines->Add("• Age: 3 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("CARE STATISTICS:");
    Memo2->Lines->Add("• Watering: Completed");
    Memo2->Lines->Add("• Sunlight: Completed");
    Memo2->Lines->Add("• Fertilizing: Completed");
    Memo2->Lines->Add("• Week 4 cycle: Complete");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GROWTH PROGRESS:");
    Memo2->Lines->Add("• Plants approaching growth transition");
    Memo2->Lines->Add("• Health maintained at 100%");
    Memo2->Lines->Add("• Expected to transition to Growing state next week");
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Week5thClick(TObject *Sender)
{
    // Clear both memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();

    // Add Week 5 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 5 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe watering all plants...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Watering Plants ------");
    Memo1->Lines->Add("Watering 9 plant(s)...");
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
    Memo1->Lines->Add("Successfully watered 9 plant(s).");
    Memo1->Lines->Add("===========================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Trevor providing sunlight to all plants...");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Kobe fertilizing all plants...");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Week progressing...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("------ Advancing Time ------");
    Memo1->Lines->Add("Advancing 1 week(s) for 9 plant(s)...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("--- Week 1 ---");
    Memo1->Lines->Add("Rose transitioned to Growing State.");
    Memo1->Lines->Add(" Rose transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Rose transitioned to Growing State.");
    Memo1->Lines->Add(" Rose transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Tulip transitioned to Growing State.");
    Memo1->Lines->Add(" Tulip transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Orchid transitioned to Growing State.");
    Memo1->Lines->Add(" Orchid transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Basil transitioned to Growing State.");
    Memo1->Lines->Add(" Basil transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Rosemary transitioned to Growing State.");
    Memo1->Lines->Add(" Rosemary transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Aloe Vera transitioned to Growing State.");
    Memo1->Lines->Add(" Aloe Vera transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Cactus transitioned to Growing State.");
    Memo1->Lines->Add(" Cactus transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Oak transitioned to Growing State.");
    Memo1->Lines->Add(" Oak transitioned: Seedling -> Growing");
    Memo1->Lines->Add("Week 1 complete: 9 plant(s) aged, 9 state transition(s)");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Time advancement complete: 1 week(s) passed.");
    Memo1->Lines->Add("============================");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" NOTIFICATION: Week 5 care cycle completed");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Manager Sarah] Week 5 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Kobe (GreenhouseWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 5 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Naledi (SalesAssociate)] Notification received:");
    Memo1->Lines->Add(" -> Week 5 care cycle completed");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Carie (SalesFloorWorker)] Notification received:");
    Memo1->Lines->Add(" -> Week 5 care cycle completed");
    Memo1->Lines->Add(" Carie: Acknowledged.");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" Notified 4 active observer(s)");
    Memo1->Lines->Add("-----------------------------------------");

    // Add Week 5 PLANT INVENTORY to Memo2
    Memo2->Lines->Add("=== WEEK 5 PLANT INVENTORY ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("NURSERY INVENTORY SUMMARY");
    Memo2->Lines->Add("Greenhouse Plants: 9");
    Memo2->Lines->Add("Sales Floor Plants: 0");
    Memo2->Lines->Add("Registered Factories: 4 types");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("GREENHOUSE PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)   State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Basil (Herb)            State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Cactus (Succulent)      State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Oak (Tree)              State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Orchid (Flower)         State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Rose (Flower) x2        State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Rosemary (Herb)         State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("• Tulip (Flower)          State: Growing   Health: 100%   Age: 4 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("INVENTORY SUMMARY:");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Greenhouse: 9 plants");
    Memo2->Lines->Add("Sales Floor: 0 plants");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 4 weeks");
    Memo2->Lines->Add("");
	Memo2->Lines->Add("GROWTH MILESTONES:");
    Memo2->Lines->Add("• All plants transitioned to Growing state");
    Memo2->Lines->Add("• 9 successful state transitions");
    Memo2->Lines->Add("• Health maintained at 100%");
    Memo2->Lines->Add("• Plants ready for next growth phase");
}
//---------------------------------------------------------------------------
