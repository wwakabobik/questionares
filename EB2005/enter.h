//---------------------------------------------------------------------------

#ifndef enterH
#define enterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TEdit *Edit1;
        TPanel *Panel1;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TStaticText *StaticText8;
        TStaticText *StaticText9;
        TStaticText *StaticText10;
        TPanel *Panel2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall Panel2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
