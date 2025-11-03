//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;

//---------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner), nursery(nullptr), notifSystem(nullptr), manager(nullptr),
      kobeObs(nullptr), nalediObs(nullptr), carieObs(nullptr)
{
    nursery = new NurseryMediator();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::HireStaffClick(TObject *Sender)
{
	String taskText = StaffEdit->Text;

	if (taskText == "Kobe Bryant - Greenhouse Worker") {
		StaffWorkFlow* kobe = new GreenhouseWorker("Kobe Bryant", nursery);
		StaffList->Items->Add(taskText + " - HIRED!");

		// Send notification
		if (notifSystem != nullptr){
			notifSystem->notify("Kobe Bryant hired as Greenhouse Worker!");
		}
	}
	else if (taskText == "Naledi - Sales Associate") {
		StaffWorkFlow* naledi = new SalesAssociate("Naledi", nursery);
		StaffList->Items->Add(taskText + " - HIRED!");

		if (notifSystem != nullptr) {
			notifSystem->notify("Naledi hired as Sales Associate!");
		}
	}
	else if (taskText == "Trevor - Greenhouse Worker") {
		StaffWorkFlow* trevor = new GreenhouseWorker("Trevor", nursery);
		StaffList->Items->Add(taskText + " - HIRED!");

		if (notifSystem != nullptr) {
			notifSystem->notify("Trevor hired as Greenhouse Worker!");

		}
	}
    else if (taskText == "Carie - Greenhouse Worker") {
		StaffWorkFlow* carie = new GreenhouseWorker("Carie", nursery);
		StaffList->Items->Add(taskText + " - HIRED!");

        if (notifSystem != nullptr) {
			notifSystem->notify("Carie hired as Greenhouse Worker!");
		}
	}
	else if (taskText != ""){
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
void __fastcall TForm2::FactoryListItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
    // Make sure an item is actually selected
    if (FactoryList->Selected == nullptr) return;

    int selectedIndex = FactoryList->Selected->Index;
    String itemText = FactoryList->Items->Strings[selectedIndex];

    // Clear the factory details display
    FactoryDetailsMemo->Lines->Clear();

    // Check which factory was clicked and display its details
	if (itemText.Pos("Flower: Rose - R89.99 - REGISTERED!") > 0) {
		FactoryDetailsMemo->Lines->Add("=== Rose Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Flower");
        FactoryDetailsMemo->Lines->Add("Price: R89.99");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Beautiful flowering plant");
        FactoryDetailsMemo->Lines->Add("• Requires regular watering");
        FactoryDetailsMemo->Lines->Add("• Blooms in various colors");
        FactoryDetailsMemo->Lines->Add("• Symbol of love and passion");
    }
	else if (itemText.Pos("Flower: Tulip - R65.50 - REGISTERED!") > 0) {
		FactoryDetailsMemo->Lines->Add("=== Tulip Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Flower");
        FactoryDetailsMemo->Lines->Add("Price: R65.50");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Spring-blooming perennial");
        FactoryDetailsMemo->Lines->Add("• Symbol of perfect love");
        FactoryDetailsMemo->Lines->Add("• Wide color variety");
        FactoryDetailsMemo->Lines->Add("• Easy to grow and maintain");
    }
	else if (itemText.Pos("Flower: Orchid - R125.00 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Orchid Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Flower");
        FactoryDetailsMemo->Lines->Add("Price: R125.00");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Exotic and elegant appearance");
        FactoryDetailsMemo->Lines->Add("• Requires specific care conditions");
        FactoryDetailsMemo->Lines->Add("• Long-lasting blooms");
        FactoryDetailsMemo->Lines->Add("• High-maintenance but rewarding");
    }
	else if (itemText.Pos("Herb: Basil - R65.00 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Basil Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Herb");
        FactoryDetailsMemo->Lines->Add("Price: R65.00");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
		FactoryDetailsMemo->Lines->Add("• Culinary herb for cooking");
        FactoryDetailsMemo->Lines->Add("• Aromatic leaves with strong flavor");
        FactoryDetailsMemo->Lines->Add("• Used in Italian and Asian cuisine");
        FactoryDetailsMemo->Lines->Add("• Grows quickly in warm conditions");
    }
	else if (itemText.Pos("Herb: Rosemary - R72.50 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Rosemary Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Herb");
        FactoryDetailsMemo->Lines->Add("Price: R72.50");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
		FactoryDetailsMemo->Lines->Add("• Woody, perennial herb");
        FactoryDetailsMemo->Lines->Add("• Needle-like leaves");
        FactoryDetailsMemo->Lines->Add("• Used for seasoning and tea");
        FactoryDetailsMemo->Lines->Add("• Drought-tolerant once established");
    }
	else if (itemText.Pos("Succulent: Aloe Vera - R55.00 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Aloe Vera Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Succulent");
        FactoryDetailsMemo->Lines->Add("Price: R55.00");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Medicinal plant with healing gel");
        FactoryDetailsMemo->Lines->Add("• Requires minimal watering");
        FactoryDetailsMemo->Lines->Add("• Great for sunburns and skin care");
        FactoryDetailsMemo->Lines->Add("• Very low maintenance");
    }
	else if (itemText.Pos("Succulent: Cactus - R45.50 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Cactus Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Succulent");
        FactoryDetailsMemo->Lines->Add("Price: R45.50");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Extreme drought tolerance");
        FactoryDetailsMemo->Lines->Add("• Requires very little water");
        FactoryDetailsMemo->Lines->Add("• Various shapes and sizes");
        FactoryDetailsMemo->Lines->Add("• Perfect for beginners");
    }
	else if (itemText.Pos("Tree: Oak - R450.00 - REGISTERED!") > 0) {
        FactoryDetailsMemo->Lines->Add("=== Oak Tree Factory ===");
        FactoryDetailsMemo->Lines->Add("Type: Tree");
        FactoryDetailsMemo->Lines->Add("Price: R450.00");
        FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Plant Characteristics:");
        FactoryDetailsMemo->Lines->Add("• Large, long-lived tree");
        FactoryDetailsMemo->Lines->Add("• Provides shade and wildlife habitat");
        FactoryDetailsMemo->Lines->Add("• Slow growing but very sturdy");
        FactoryDetailsMemo->Lines->Add("• Can live for hundreds of years");
	}
	else if (itemText.Pos("=== ALL FACTORIES REGISTERED! ===") > 0) {
		FactoryDetailsMemo->Lines->Add("=== ALL PLANT FACTORIES ===");
		FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Total: 8 Factories Registered");
		FactoryDetailsMemo->Lines->Add("• 3 Flower types");
        FactoryDetailsMemo->Lines->Add("• 2 Herb types");
        FactoryDetailsMemo->Lines->Add("• 2 Succulent types");
        FactoryDetailsMemo->Lines->Add("• 1 Tree type");
		FactoryDetailsMemo->Lines->Add("");
        FactoryDetailsMemo->Lines->Add("Ready for plant production!");
    }
    else {
        // If it's not a recognized factory, just show the text
        FactoryDetailsMemo->Lines->Add("Selected: " + itemText);
        FactoryDetailsMemo->Lines->Add("(No factory details available)");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::NotificationsClick(TObject *Sender)
{
    // Setup observer system
    notifSystem = new Subject();
    manager = new ManagerObserver("Sarah");
    kobeObs = new StaffObserver("Kobe", "GreenhouseWorker");
    nalediObs = new StaffObserver("Naledi", "SalesAssociate");
    carieObs = new StaffObserver("Carie", "SalesFloorWorker");

    notifSystem->attach(manager);
    notifSystem->attach(kobeObs);
    notifSystem->attach(nalediObs);
    notifSystem->attach(carieObs);

    // Add to notification list
    NotificationList->Items->Clear();
    NotificationList->Items->Add("=== NOTIFICATION SYSTEM ACTIVE ===");
	NotificationList->Items->Add("Manager: Sarah");
	NotificationList->Items->Add("Staff: Kobe (GreenhouseWorker)");
	NotificationList->Items->Add("Staff: Naledi (SalesAssociate)");
	NotificationList->Items->Add("Staff: Carie (SalesFloorWorker)");
    NotificationList->Items->Add("");
    NotificationList->Items->Add("System ready for notifications!");

    // Send welcome notification
    notifSystem->notify("Nursery is now open for business!");
	NotificationList->Items->Add("Notification: Nursery is now open for business!");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BackClick(TObject *Sender)
{
	Form1->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
