//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "enter.h"
#include "test.h"
#include "test.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
//Form1->Close();
//Form3->Close();
}
//-----------------------------------0----------------------------------------
void __fastcall TForm3::Panel1Click(TObject *Sender)
{
WideString t;
t=Edit1->Text;
plname=t;
int i=1;
unsigned char inside[1024];
while (t[i]!=0)
{
inside[i-1]=t[i];
i++;
}
inside[i]='\0';
plcheck(inside);
StaticText8->Caption = player.times;
StaticText9->Caption = player.correct;
StaticText10->Caption = player.wrong;
Plname0 = t;  //!
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel2Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
