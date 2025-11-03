//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include "PlantMemento.h"
#include "PlantCaretaker.h"
#include "Subject.h"
#include "ManagerObserver.h"
#include "StaffObserver.h"
#include "Command.h"
#include "AdvanceTimeCommand.h"
#include "WaterPlantsCommand.h"
#include "RevivePlantCommand.h"
#include "NurseryMediator.h"
#include "StaffWorkFlow.h"
#include "StaffWorkFlowDecorator.h"
#include "LandscaperRole.h"
#include "DeliveryRole.h"
#include "SalesRole.h"
#include "ManagerRole.h"
#include "GreenhouseWorker.h"
#include "SalesAssociate.h"
#include "PlantOrder.h"
#include "PlantItem.h"
#include "PlantBundle.h"
#include "OrderBuilder.h"
#include "Customer.h"
#include "SalesFloorWorker.h"
#include "WiltingState.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Week0title;
	TLabel *Label1;
	TButton *Button1;
	TListBox *ListBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TListBox *ListBox2;
	TButton *RegisterFactory;
	TButton *Button2;
	TButton *Button3;
private:
	NurseryMediator* nursery;
    Subject* notifSystem;
    StaffWorkFlow* Kobe;
    StaffWorkFlow* Naledi;
    StaffWorkFlow* Trevor;
	StaffWorkFlow* Carie;	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
