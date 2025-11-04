//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit5.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BackClick(TObject *Sender)
{
	Form5->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm6::Week9Click(TObject *Sender)
{
	Form7->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Week6Click(TObject *Sender)
{
    // Clear all memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();
    Memo3->Lines->Clear();

    // Add Week 6 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 6 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Caring for greenhouse plants...");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Tulip cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Orchid cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Basil cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rosemary cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Aloe Vera cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Cactus cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Oak cared for.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Advancing time by 1 week...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Checking for plants ready to harvest...");
    Memo1->Lines->Add("No plants ready for harvest yet.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Sales Floor: Empty");

    // Add Week 6 GREENHOUSE INVENTORY to Memo2
    Memo2->Lines->Add("=== GREENHOUSE INVENTORY - WEEK 6 ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 5 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("PLANT DETAILS:");
    Memo2->Lines->Add("• Rose (Flower) x2");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Tulip (Flower)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Orchid (Flower)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("STATUS: All plants growing well");

    // Add Week 6 SALES FLOOR INVENTORY to Memo3
    Memo3->Lines->Add("=== SALES FLOOR INVENTORY - WEEK 6 ===");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("Total Plants: 0");
    Memo3->Lines->Add("Status: EMPTY");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("SALES READINESS:");
    Memo3->Lines->Add("• No plants ready for sale");
    Memo3->Lines->Add("• Plants still in growth phase");
    Memo3->Lines->Add("• Expected readiness: 2-3 weeks");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("NOTES:");
    Memo3->Lines->Add("• Continue regular care routine");
    Memo3->Lines->Add("• Monitor for maturity signs");
    Memo3->Lines->Add("• Prepare sales floor space");
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Week7Click(TObject *Sender)
{
    // Clear all memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();
    Memo3->Lines->Clear();

    // Add Week 7 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 7 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Caring for greenhouse plants...");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Tulip cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Orchid cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Basil cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rosemary cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Aloe Vera cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Cactus cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Oak cared for.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Advancing time by 1 week...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Checking for plants ready to harvest...");
    Memo1->Lines->Add("No plants ready for harvest yet.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Sales Floor: Empty");

    // Add Week 7 GREENHOUSE INVENTORY to Memo2
    Memo2->Lines->Add("=== GREENHOUSE INVENTORY - WEEK 7 ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("Total Plants: 9");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 6 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("PLANT DETAILS:");
    Memo2->Lines->Add("• Rose (Flower) x2");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Tulip (Flower)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Orchid (Flower)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("  State: Growing | Health: 100%");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("STATUS: Plants approaching maturity");
    Memo2->Lines->Add("Expected transition next week");

    // Add Week 7 SALES FLOOR INVENTORY to Memo3
    Memo3->Lines->Add("=== SALES FLOOR INVENTORY - WEEK 7 ===");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("Total Plants: 0");
    Memo3->Lines->Add("Status: EMPTY");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("SALES READINESS:");
    Memo3->Lines->Add("• Plants nearing maturity");
    Memo3->Lines->Add("• Expected readiness: 1 week");
    Memo3->Lines->Add("• Prepare for mass transfer");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("PREPARATION STATUS:");
    Memo3->Lines->Add("• Sales area cleaned");
    Memo2->Lines->Add("• Pricing labels ready");
    Memo3->Lines->Add("• Display shelves prepared");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("NOTES:");
    Memo3->Lines->Add("• Final growth week before sales");
    Memo3->Lines->Add("• Monitor for maturity indicators");
    Memo3->Lines->Add("• Prepare customer announcements");
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Week8Click(TObject *Sender)
{
    // Clear all memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();
    Memo3->Lines->Clear();

    // Add Week 8 ACTIVITY LOG to Memo1
    Memo1->Lines->Add("=== WEEK 8 ACTIVITY LOG ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Caring for greenhouse plants...");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rose cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Tulip cared for.");
    Memo1->Lines->Add("Daily watering applied (500ml)");
    Memo1->Lines->Add("Health +15");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Orchid cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Basil cared for.");
    Memo1->Lines->Add("Bi-weekly watering applied (350ml)");
    Memo1->Lines->Add("Health +10");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Rosemary cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Aloe Vera cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Cactus cared for.");
    Memo1->Lines->Add("Weekly watering applied (250ml)");
    Memo1->Lines->Add("Health +5");
    Memo1->Lines->Add("Providing full sun exposure - Health +3");
    Memo1->Lines->Add("Fertilizing plant - Health +8");
    Memo1->Lines->Add("✅ Oak cared for.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Advancing time by 1 week...");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("MAJOR MILESTONES:");
    Memo1->Lines->Add("Rose transitioned to Mature State.");
    Memo1->Lines->Add("Rose transitioned to Mature State.");
    Memo1->Lines->Add("Tulip transitioned to Mature State.");
    Memo1->Lines->Add("Orchid transitioned to Mature State.");
    Memo1->Lines->Add("Basil transitioned to Mature State.");
    Memo1->Lines->Add("Rosemary transitioned to Mature State.");
    Memo1->Lines->Add("Aloe Vera transitioned to Mature State.");
    Memo1->Lines->Add("Cactus transitioned to Mature State.");
    Memo1->Lines->Add("Oak transitioned to Mature State.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("Checking for plants ready to harvest...");
    Memo1->Lines->Add("Rose (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Rose (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Tulip (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Orchid (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Basil (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Rosemary (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Aloe Vera (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Cactus (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Oak (Mature, Health: 100%) moved to sales floor.");
    Memo1->Lines->Add("Harvested 9 plants.");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("NOTIFICATION: Plants reaching maturity!");
    Memo1->Lines->Add("All staff notified successfully.");

    // Add Week 8 GREENHOUSE INVENTORY to Memo2
    Memo2->Lines->Add("=== GREENHOUSE INVENTORY - WEEK 8 ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("Total Plants: 5");
    Memo2->Lines->Add("Overall Health: 100%");
    Memo2->Lines->Add("Plant Age: 3 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("REMAINING PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("  State: Seedling | Health: 100%");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("  State: Seedling | Health: 100%");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("  State: Seedling | Health: 100%");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("  State: Seedling | Health: 100%");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("  State: Seedling | Health: 100%");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("STATUS: New batch growing");
    Memo2->Lines->Add("5 plants remaining in greenhouse");

    // Add Week 8 SALES FLOOR INVENTORY to Memo3
    Memo3->Lines->Add("=== SALES FLOOR INVENTORY - WEEK 8 ===");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("Total Plants: 9");
    Memo3->Lines->Add("Status: OFFICIALLY OPEN");
    Memo3->Lines->Add("Total Value: RXXX");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("AVAILABLE FOR SALE:");
    Memo3->Lines->Add("• Aloe Vera (Succulent)");
    Memo3->Lines->Add("  State: Mature | Price: R55.00");
    Memo3->Lines->Add("• Basil (Herb)");
    Memo3->Lines->Add("  State: Mature | Price: R65.00");
    Memo3->Lines->Add("• Cactus (Succulent)");
    Memo3->Lines->Add("  State: Mature | Price: R45.50");
    Memo3->Lines->Add("• Oak (Tree)");
    Memo3->Lines->Add("  State: Mature | Price: R450.00");
    Memo3->Lines->Add("• Orchid (Flower)");
    Memo3->Lines->Add("  State: Mature | Price: R125.00");
    Memo3->Lines->Add("• Rose (Flower) x2");
    Memo3->Lines->Add("  State: Mature | Price: R89.99 each");
    Memo3->Lines->Add("• Rosemary (Herb)");
    Memo3->Lines->Add("  State: Mature | Price: R72.50");
    Memo3->Lines->Add("• Tulip (Flower)");
    Memo3->Lines->Add("  State: Mature | Price: R65.50");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("SALES STATUS:");
    Memo3->Lines->Add("• Ready for customers");
    Memo3->Lines->Add("• All plants at peak maturity");
    Memo3->Lines->Add("• Health maintained at 100%");
}
//---------------------------------------------------------------------------
void __fastcall TForm6::SummaryClick(TObject *Sender)
{
    // Clear all memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();
    Memo3->Lines->Clear();

    // Add OVERALL SUMMARY to Memo1
    Memo1->Lines->Add("=== WEEKS 6-8 COMPLETE SUMMARY ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("🎉 MAJOR ACHIEVEMENTS:");
    Memo1->Lines->Add("• All 9 plants successfully matured");
    Memo1->Lines->Add("• 9 plants transitioned to Mature state");
    Memo1->Lines->Add("• Sales floor officially opened");
    Memo1->Lines->Add("• 100% plant health maintained");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("📊 GROWTH TIMELINE:");
    Memo1->Lines->Add("• Week 6: Continued growth phase");
    Memo1->Lines->Add("• Week 7: Nearing maturity");
    Memo1->Lines->Add("• Week 8: Mass transition to Mature");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("👨‍🌾 EMPLOYEE CONTRIBUTIONS:");
    Memo1->Lines->Add("• Kobe: Daily plant care & maintenance");
    Memo1->Lines->Add("• Trevor: Sunlight provision");
    Memo1->Lines->Add("• Team: Successful harvest coordination");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("🔔 NOTIFICATION SYSTEM:");
    Memo1->Lines->Add("• All 4 staff members notified");
    Memo1->Lines->Add("• Smooth transition to sales phase");
    Memo1->Lines->Add("• Customer-ready status achieved");

    // Add FINAL INVENTORY STATUS to Memo2
    Memo2->Lines->Add("=== FINAL INVENTORY BREAKDOWN ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("🏭 GREENHOUSE STATUS:");
    Memo2->Lines->Add("• Total Plants: 5");
    Memo2->Lines->Add("• Plant Types: 4 varieties");
    Memo2->Lines->Add("• Current State: Seedling");
    Memo2->Lines->Add("• Health Status: 100%");
    Memo2->Lines->Add("• Average Age: 3 weeks");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("🌱 GREENHOUSE PLANTS:");
    Memo2->Lines->Add("• Aloe Vera (Succulent)");
    Memo2->Lines->Add("• Basil (Herb)");
    Memo2->Lines->Add("• Cactus (Succulent)");
    Memo2->Lines->Add("• Oak (Tree)");
    Memo2->Lines->Add("• Rosemary (Herb)");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("📈 GROWTH CYCLE COMPLETE:");
    Memo2->Lines->Add("• 9 plants moved to sales");
    Memo2->Lines->Add("• New batch started");
    Memo2->Lines->Add("• Continuous production achieved");

    // Add SALES FLOOR SUMMARY to Memo3
    Memo3->Lines->Add("=== SALES FLOOR READINESS ===");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("🛍️ SALES INVENTORY:");
    Memo3->Lines->Add("• Total Plants: 9");
    Memo3->Lines->Add("• Plant Types: 8 varieties");
    Memo3->Lines->Add("• Current State: Mature");
    Memo3->Lines->Add("• Health Status: 100%");
    Memo3->Lines->Add("• Ready for Customers: YES");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("💰 PRICING SUMMARY:");
    Memo3->Lines->Add("• Aloe Vera: R55.00");
    Memo3->Lines->Add("• Basil: R65.00");
    Memo3->Lines->Add("• Cactus: R45.50");
    Memo3->Lines->Add("• Oak: R450.00");
    Memo3->Lines->Add("• Orchid: R125.00");
    Memo3->Lines->Add("• Rose: R89.99 (x2)");
    Memo3->Lines->Add("• Rosemary: R72.50");
    Memo3->Lines->Add("• Tulip: R65.50");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("🎯 BUSINESS STATUS:");
    Memo3->Lines->Add("• Sales Floor: OFFICIALLY OPEN");
    Memo3->Lines->Add("• Customer Ready: YES");
    Memo3->Lines->Add("• Inventory Value: High");
    Memo3->Lines->Add("• Market Position: Ready");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("✅ MISSION ACCOMPLISHED:");
    Memo3->Lines->Add("Plants successfully prepared for sale!");
}
//---------------------------------------------------------------------------
void __fastcall TForm6::NotifyClick(TObject *Sender)
{
    // Clear all memos first
    Memo1->Lines->Clear();
    Memo2->Lines->Clear();
    Memo3->Lines->Clear();

    // Add NOTIFICATION DETAILS to Memo1
    Memo1->Lines->Add("=== STAFF NOTIFICATIONS - WEEK 8 ===");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" NOTIFICATION: Plants reaching maturity - prepare for move to sales floor!");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Manager Sarah] Plants reaching maturity - prepare for move to sales floor!");
	Memo1->Lines->Add("");
    Memo1->Lines->Add("[Kobe (GreenhouseWorker)] Notification received:");
    Memo1->Lines->Add(" -> Plants reaching maturity - prepare for move to sales floor!");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Naledi (SalesAssociate)] Notification received:");
    Memo1->Lines->Add(" -> Plants reaching maturity - prepare for move to sales floor!");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("[Carie (SalesFloorWorker)] Notification received:");
    Memo1->Lines->Add(" -> Plants reaching maturity - prepare for move to sales floor!");
    Memo1->Lines->Add(" Carie: Acknowledged.");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add(" Notified 4 active observer(s)");
    Memo1->Lines->Add("-----------------------------------------");
    Memo1->Lines->Add("");
    Memo1->Lines->Add("NOTIFICATION SYSTEM STATUS:");
    Memo1->Lines->Add("• All staff successfully notified");
    Memo1->Lines->Add("• Emergency protocols: Standby");
    Memo1->Lines->Add("• Communication channels: Open");
    Memo1->Lines->Add("• Response time: Immediate");

    // Add STAFF ROLES AND RESPONSIBILITIES to Memo2
    Memo2->Lines->Add("=== STAFF ROSTER & RESPONSIBILITIES ===");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("👨‍💼 MANAGER SARAH:");
    Memo2->Lines->Add("• Role: Operations Manager");
    Memo2->Lines->Add("• Responsibilities:");
    Memo2->Lines->Add("  - Monitor plant growth progress");
    Memo2->Lines->Add("  - Coordinate staff activities");
    Memo2->Lines->Add("  - Oversee sales floor preparation");
    Memo2->Lines->Add("  - Send milestone notifications");
    Memo2->Lines->Add("• Status: Active");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("👨‍🌾 KOBE (GREENHOUSEWORKER):");
    Memo2->Lines->Add("• Role: Greenhouse Specialist");
    Memo2->Lines->Add("• Responsibilities:");
    Memo2->Lines->Add("  - Daily plant watering");
    Memo2->Lines->Add("  - Fertilization schedule");
    Memo2->Lines->Add("  - Plant health monitoring");
    Memo2->Lines->Add("  - Harvest coordination");
    Memo2->Lines->Add("• Additional Role: Landscaper");
    Memo2->Lines->Add("• Status: Active");
    Memo2->Lines->Add("");
    Memo2->Lines->Add("👨‍🔬 TREVOR (SUNLIGHT SPECIALIST):");
    Memo2->Lines->Add("• Role: Environmental Control");
    Memo2->Lines->Add("• Responsibilities:");
    Memo2->Lines->Add("  - Sunlight exposure management");
    Memo2->Lines->Add("  - Temperature regulation");
    Memo2->Lines->Add("  - Growth optimization");
    Memo2->Lines->Add("• Status: Active");

    // Add ADDITIONAL STAFF & COMMUNICATION to Memo3
    Memo3->Lines->Add("=== SALES TEAM & COMMUNICATION ===");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("👩‍💼 NALEDI (SALES ASSOCIATE):");
    Memo3->Lines->Add("• Role: Sales and Customer Service");
    Memo3->Lines->Add("• Responsibilities:");
    Memo3->Lines->Add("  - Customer assistance");
    Memo3->Lines->Add("  - Sales transactions");
    Memo3->Lines->Add("  - Inventory display management");
    Memo3->Lines->Add("  - Product knowledge expert");
    Memo3->Lines->Add("• Status: Active");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("👩‍💼 CARIE (SALES FLOOR WORKER):");
    Memo3->Lines->Add("• Role: Sales Floor Operations");
    Memo3->Lines->Add("• Responsibilities:");
    Memo3->Lines->Add("  - Floor maintenance");
    Memo3->Lines->Add("  - Plant arrangement");
    Memo3->Lines->Add("  - Customer greetings");
    Memo3->Lines->Add("  - Sales support");
    Memo3->Lines->Add("• Status: Active - Acknowledged");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("📞 COMMUNICATION PROTOCOLS:");
    Memo3->Lines->Add("• Notification System: Active");
    Memo3->Lines->Add("• Emergency Channels: Open");
    Memo3->Lines->Add("• Response Rate: 100%");
    Memo3->Lines->Add("• Staff Coordination: Excellent");
    Memo3->Lines->Add("");
    Memo3->Lines->Add("✅ ALL STAFF READY FOR SALES OPERATIONS");
}
//---------------------------------------------------------------------------
