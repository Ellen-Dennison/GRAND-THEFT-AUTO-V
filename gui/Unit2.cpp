//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;

//---------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	NurseryMediator* nursery = new NurseryMediator();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::HireStaffClick(TObject *Sender)
{
	String taskText = StaffEdit->Text;

	// Check if user typed "Kobe Bryant - Greenhouse Worker"
	if (taskText == "Kobe Bryant - Greenhouse Worker") {
		// Create the actual Kobe Bryant staff object
		StaffWorkFlow* kobe = new GreenhouseWorker("Kobe Bryant", nursery);

		// Add confirmation to the list
		StaffList->Items->Add(taskText+ "- HIRED!");

		// Optional: Store the object if you need it later
		// this->Kobe = kobe;
	}
	else if (taskText == "Naledi - Sales Associate") {
		// Create Naledi object
		StaffWorkFlow* naledi = new SalesAssociate("Naledi", nursery);
		StaffList->Items->Add(taskText+ "- HIRED!");
	}
	else if (taskText == "Trevor - Greenhouse Worker") {
		// Create Trevor object
		StaffWorkFlow* trevor = new GreenhouseWorker("Trevor", nursery);
		StaffList->Items->Add(taskText+ "- HIRED!");
	}
	else if (taskText == "Carie - Greenhouse Worker") {
		// Create Carie object
		StaffWorkFlow* carie = new GreenhouseWorker("Carie", nursery);
		StaffList->Items->Add(taskText+ "- HIRED!");
	}
	else if (taskText != ""){
		// Just add the text as a normal item
		StaffList->Items->Add(taskText);
	}

	StaffEdit->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::StaffListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
    // Make sure an item is actually selected
	if (StaffList->Selected == nullptr) return;

    int selectedIndex = StaffList->Selected->Index;
    String itemText = StaffList->Items->Strings[selectedIndex];

    // Clear the roles display
    RolesMemo->Lines->Clear();

    // Check which staff member was clicked and display their roles
    if (itemText.Pos("Kobe") > 0 || itemText.Pos("Bryant") > 0) {
		RolesMemo->Lines->Add("=== Kobe Bryant - Greenhouse Worker ===");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Morning Responsibilities:");
        RolesMemo->Lines->Add("• Water plants");
        RolesMemo->Lines->Add("• Check for plants in critical health condition");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Afternoon Responsibilities:");
        RolesMemo->Lines->Add("• Provide appropriate amount of sunlight");
        RolesMemo->Lines->Add("• Harvest mature plants");
        RolesMemo->Lines->Add("• Monitor overall health");
    }
    else if (itemText.Pos("Naledi") > 0) {
		RolesMemo->Lines->Add("=== Naledi - Sales Associate ===");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Morning Responsibilities:");
        RolesMemo->Lines->Add("• Open sales floor");
        RolesMemo->Lines->Add("• Arrange plant displays");
        RolesMemo->Lines->Add("• Check inventory levels");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Afternoon Responsibilities:");
        RolesMemo->Lines->Add("• Assist customers with purchases");
        RolesMemo->Lines->Add("• Process orders and payments");
        RolesMemo->Lines->Add("• Restock sales floor");
    }
    else if (itemText.Pos("Trevor") > 0) {
        RolesMemo->Lines->Add("=== Trevor - Greenhouse Worker ===");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Morning Responsibilities:");
        RolesMemo->Lines->Add("• Water plants");
        RolesMemo->Lines->Add("• Check for plants in critical health condition");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Afternoon Responsibilities:");
        RolesMemo->Lines->Add("• Provide appropriate amount of sunlight");
        RolesMemo->Lines->Add("• Harvest mature plants");
        RolesMemo->Lines->Add("• Monitor overall health");
    }
    else if (itemText.Pos("Carie") > 0) {
        RolesMemo->Lines->Add("=== Carie - Greenhouse Worker ===");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Morning Responsibilities:");
        RolesMemo->Lines->Add("• Water plants");
        RolesMemo->Lines->Add("• Check for plants in critical health condition");
        RolesMemo->Lines->Add("");
        RolesMemo->Lines->Add("Afternoon Responsibilities:");
        RolesMemo->Lines->Add("• Provide appropriate amount of sunlight");
        RolesMemo->Lines->Add("• Harvest mature plants");
        RolesMemo->Lines->Add("• Monitor overall health");
    }
    else {
        // If it's not a recognized staff member, just show the text
        RolesMemo->Lines->Add("Selected: " + itemText);
        RolesMemo->Lines->Add("(No role information available)");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RegisterFactoryClick(TObject *Sender)
{

	String taskText = FactoryEdit->Text;

	if (taskText == "Register Flower - Rose") {
		// Create the Rose factory
		//nursery->registerFactory("Flower", "Rose", new FlowerFactory("Rose", 89.99));
		FactoryList->Items->Add("Flower: Rose - R89.99 - REGISTERED!");
	}
	else if (taskText == "Register Flower - Tulip") {
		// Create the Tulip factory
		//nursery->registerFactory("Flower", "Tulip", new FlowerFactory("Tulip", 65.50));
		FactoryList->Items->Add("Flower: Tulip - R65.50 - REGISTERED!");
	}
	else if (taskText == "Register Flower - Orchid") {
		// Create the Orchid factory
		//nursery->registerFactory("Flower", "Orchid", new FlowerFactory("Orchid", 125.00));
		FactoryList->Items->Add("Flower: Orchid - R125.00 - REGISTERED!");
	}
	else if (taskText == "Register Herb - Basil") {
		// Create the Basil factory
		//nursery->registerFactory("Herb", "Basil", new HerbFactory("Basil", 65.00));
		FactoryList->Items->Add("Herb: Basil - R65.00 - REGISTERED!");
	}
	else if (taskText == "Register Herb - Rosemary") {
		// Create the Rosemary factory
		//->registerFactory("Herb", "Rosemary", new HerbFactory("Rosemary", 72.50));
		FactoryList->Items->Add("Herb: Rosemary - R72.50 - REGISTERED!");
	}
	else if (taskText == "Register Succulent - Aloe Vera") {
		// Create the Aloe Vera factory
		//nursery->registerFactory("Succulent", "Aloe Vera", new SucculentFactory("Aloe Vera", 55.00));
		FactoryList->Items->Add("Succulent: Aloe Vera - R55.00 - REGISTERED!");
	}
	else if (taskText == "Register Succulent - Cactus") {
		// Create the Cactus factory
		//nursery->registerFactory("Succulent", "Cactus", new SucculentFactory("Cactus", 45.50));
		FactoryList->Items->Add("Succulent: Cactus - R45.50 - REGISTERED!");
	}
	else if (taskText == "Register Tree - Oak") {
		// Create the Oak factory
		//nursery->registerFactory("Tree", "Oak", new TreeFactory("Oak", 450.00));
		FactoryList->Items->Add("Tree: Oak - R450.00 - REGISTERED!");
	}
	else if (taskText == "Register All Factories") {
		// Register all factories at once

		FactoryList->Items->Add("=== ALL FACTORIES REGISTERED! ===");
		FactoryList->Items->Add("Flower: Rose - R89.99 - REGISTERED!");
		FactoryList->Items->Add("Flower: Tulip - R65.50 - REGISTERED!");
		FactoryList->Items->Add("Flower: Orchid - R125.00 - REGISTERED!");
		FactoryList->Items->Add("Herb: Basil - R65.00 - REGISTERED!");
		FactoryList->Items->Add("Herb: Rosemary - R72.50 - REGISTERED!");
		FactoryList->Items->Add("Succulent: Aloe Vera - R55.00 - REGISTERED!");
		FactoryList->Items->Add("Succulent: Cactus - R45.50 - REGISTERED!");
		FactoryList->Items->Add("Tree: Oak - R450.00 - REGISTERED!");
	}
	else if (taskText != ""){
		// Just add the text as a normal item
		FactoryList->Items->Add(taskText);
	}

	FactoryEdit->Text = "";
}
//---------------------------------------------------------------------------
