//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Back;
	TButton *Week9;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Week6;
	TButton *Week7;
	TButton *Week8;
	TButton *Summary;
	TButton *Button5;
	TButton *Notify;
	TLabel *ActivityLog;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TLabel *InventoryStatus;
	void __fastcall BackClick(TObject *Sender);
	void __fastcall Week9Click(TObject *Sender);
	void __fastcall Week6Click(TObject *Sender);
	void __fastcall Week7Click(TObject *Sender);
	void __fastcall Week8Click(TObject *Sender);
	void __fastcall SummaryClick(TObject *Sender);
	void __fastcall NotifyClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
