//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "test.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "test2f.h"
#include "enter.h"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

WideString plname="0000000000", plintel="0000000000000000000000000000000000000000";
const char database[]="eb2004.db";
const char score[]="score.dat";
const char ftemp[]="~eb2004.tmp";
int massiv[25];
int test2[5]={0,0,0,0,0};
int mas2[10];
int length;
int cor0=0;
int asknum;

struct base {
char quest[250];
char ans1[250];
char ans2[250];
char ans3[250];
char ans4[250];
int cor;
int vara;
int varb;
int varc;
int vard;
} q;

struct user {
unsigned char name[21];
int times;
int correct;
int wrong;
unsigned char type[21];
unsigned char intel[21];
} player;

inline string rus(char s[])
{
 string t;
 int i=0;
 t=s;
 while (t[i]!=0)
 {
   if(t[i]>='?'&& t[i]<='?' ) t[i]-=64;
   if(t[i]>='?'&& t[i]<='?' ) t[i]-=16;
   i++;
 }
 return t;
}

void plcheck(char cn[])
{
int err=0;
fstream f;
f.open(score);
if (!f)
{
cout << "\nAbnormal program termination";
//exit(1);
}
while (!f.eof())
{
f >> player.name >> player.times >> player.correct >> player.wrong >> player.type >> player.intel;
if (strcmp(cn,player.name)==0)
{
err++;
break;
}
}
f.close();
if (err==0)
{
strcpy(player.name,cn);
player.times=0;
player.correct=0;
player.wrong=0;
strcpy(player.type,"неизвестно");
strcpy(player.intel,"неизвестно");
}
}

void getlenght()
{
int param=0;
char temp[250];
fstream e;
e.open(database);
if (!e)
{
cout << "Abnormal program termination";
exit(1);
}
while (!e.eof())
{
param++;
e.getline(q.quest,250);
e.getline(q.ans1,250);
e.getline(q.ans2,250);
e.getline(q.ans3,250);
e.getline(q.ans4,250);
e.getline(temp,250);
}
e.close();
length=param-26;
}

void getask()
{
int ask,err=0;
char temp[250];
randomize();
while (err==0)
{
ask=random(length)+1+25;
for (int j=0; j<25; j++)
{
if (massiv[j]==ask)
{
err=0;
break;
}
else err=1;
}
}
int k=0;
while (massiv[k]!=0)
k++;
massiv[k]=ask;
fstream f;
f.open(database);
if (!f)
{
cout << "Abnormal program termination";
exit(1);
}
for (int i=1; i <= ask; i++)
{
f.getline(q.quest,250);
f.getline(q.ans1,250);
f.getline(q.ans2,250);
f.getline(q.ans3,250);
f.getline(q.ans4,250);
f.getline(temp,250);
q.cor=temp[0]-48;
}
f.close();
}

void setrank(char cn[])
{
ofstream f;
ifstream r;
if (player.times==1)
{
f.open(score,ios::app);
f << endl << player.name << " " << player.times << " " << player.correct << " " << player.wrong << " " << player.type << " " << player.intel;
f.close();
}
else
{
f.open(ftemp, ios::out);
r.open(score,ios::in);
f << player.name << " " << player.times << " " << player.correct << " " << player.wrong << " " << player.type << " " << player.intel;
while (!r.eof())
{
r >> player.name >> player.times >> player.correct >> player.wrong >> player.type >> player.intel;
if (strcmp(cn,player.name)!=0)
f << endl << player.name << " " << player.times << " " << player.correct << " " << player.wrong << " " << player.type << " " << player.intel;
}
f.close();
r.close();
ofstream h;
h.open(score,ios::trunc);
h.close();
fstream y;
f.open(score, ios::out);
y.open(ftemp,ios::in);
int err=0;
while (!y.eof())
{
y >> player.name >> player.times >> player.correct >> player.wrong >> player.type >> player.intel;
if (err==0)
{
f << player.name << " " << player.times << " " << player.correct << " " << player.wrong << " " << player.type << " " << player.intel;
err++;
}
else
f << endl << player.name << " " << player.times << " " << player.correct << " " << player.wrong << " " << player.type << " " << player.intel;
}
f.close();
r.close();
h.open(ftemp,ios::trunc);
h.close();
}
}

gett2()
{
int ask,err=0;
char temp[250];
randomize();
while (err==0)
{
ask=random(25)+1;
for (int j=0; j<10; j++)
{
if (mas2[j]==ask)
{
err=0;
break;
}
else err=1;
}
}
int k=0;
while (massiv[k]!=0)
k++;
massiv[k]=ask;
fstream f;
f.open(database);
if (!f)
{
cout << "Abnormal program termination";
exit(1);
}
for (int i=1; i <= ask; i++)
{
f.getline(q.quest,250);
f.getline(q.ans1,250);
f.getline(q.ans2,250);
f.getline(q.ans3,250);
f.getline(q.ans4,250);
f.getline(temp,250);
q.vara=temp[0]-48;
q.varb=temp[2]-48;
q.varc=temp[4]-48;
q.vard=temp[6]-48;
}
f.close();
return 0;
}

void whoiam(void)
{
player.times=1;
player.correct=cor0;
player.wrong+=(25-cor0);
if (player.correct/player.times >= 24)
{
strcpy(player.intel,"Гений");
plintel="Гений";
}
else if (player.correct/player.times >= 19)
{
strcpy(player.intel,"Образованный");
plintel="Образованный";
}
else if (player.correct/player.times >= 14)
{
strcpy(player.intel,"Раздолбай");
plintel="Раздолбай";
}
else
{
strcpy(player.intel,"Придурок");
plintel="Придурок";
}
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Panel7Click(TObject *Sender)
{
//test2[q.vara]++;
if (asknum<25)
{
if (q.cor==1)
cor0++;
asknum++;
getask();
Panel11->Caption = q.quest;
Panel7->Caption = q.ans1;
Panel8->Caption = q.ans2;
Panel9->Caption = q.ans3;
Panel10->Caption = q.ans4;
Panel2->Caption=asknum;
}
else
{
whoiam();
Form2->StaticText4->Caption=Plname0;
Form2->StaticText6->Caption=cor0;
Form2->StaticText8->Caption=25-cor0;
Form2->StaticText12->Caption=plintel;
Visible=False;
Form2->ShowModal();
exit(0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel8Click(TObject *Sender)
{
//test2[q.varb]++;
if (asknum<25)
{
if (q.cor==2)
cor0++;
asknum++;
getask();
Panel11->Caption = q.quest;
Panel7->Caption = q.ans1;
Panel8->Caption = q.ans2;
Panel9->Caption = q.ans3;
Panel10->Caption = q.ans4;
Panel2->Caption=asknum;
}
else {
whoiam();
Form2->StaticText4->Caption=Plname0;
Form2->StaticText6->Caption=cor0;
Form2->StaticText8->Caption=25-cor0;
Form2->StaticText12->Caption=plintel;
Visible=False;
Form2->ShowModal();
exit(0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel9Click(TObject *Sender)
{
//test2[q.varc]++;
if (asknum<25)
{
if (q.cor==3)
cor0++;
asknum++;
getask();
Panel11->Caption = q.quest;
Panel7->Caption = q.ans1;
Panel8->Caption = q.ans2;
Panel9->Caption = q.ans3;
Panel10->Caption = q.ans4;
Panel2->Caption=asknum;
}
else {
whoiam();
Form2->StaticText4->Caption=Plname0;
Form2->StaticText6->Caption=cor0;
Form2->StaticText8->Caption=25-cor0;
Form2->StaticText12->Caption=plintel;
Visible=False;
Form2->ShowModal();
exit(0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel10Click(TObject *Sender)
{
//test2[q.vard]++;
if (asknum<25)
{
if (q.cor==4)
cor0++;
asknum++;
getask();
Panel11->Caption = q.quest;
Panel7->Caption = q.ans1;
Panel8->Caption = q.ans2;
Panel9->Caption = q.ans3;
Panel10->Caption = q.ans4;
Panel2->Caption=asknum;
}
else {
whoiam();
Form2->StaticText4->Caption=Plname0;
Form2->StaticText6->Caption=cor0;
Form2->StaticText8->Caption=25-cor0;
Form2->StaticText12->Caption=plintel;
Visible=False;
Form2->ShowModal();
exit(0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
getlenght();
asknum++;
player.times = 1;
getask();
Panel11->Caption = q.quest;
Panel7->Caption = q.ans1;
Panel8->Caption = q.ans2;
Panel9->Caption = q.ans3;
Panel10->Caption = q.ans4;
Panel2->Caption=asknum;
int set=0;
int cor0=0;
for (int i=0; i < 25; i++)
massiv[i]=0;
}
//-----------------0----------------------------------------------------------
