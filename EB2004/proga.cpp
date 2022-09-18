#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>

const char database[]="eb2004.db";
const char score[]="score.dat";
const char ftemp[]="~eb2004.tmp";
int massiv[25];
int test2[5]={0,0,0,0,0};
int mas2[10];
int length;

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
// ������� ��������� Windows � Dos
{
 string t;
 int i=0;
 t=s;
 while (t[i]!=0)
 {
   if(t[i]>='�'&& t[i]<='�' ) t[i]-=64;
   if(t[i]>='�'&& t[i]<='�' ) t[i]-=16;
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
strcpy(player.type,"����������");
strcpy(player.intel,"����������");
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
}

void main()
{
getlenght();
int set=0;
int cor0=0;
for (int i=0; i < 25; i++)
massiv[i]=0;
string output;
char curname[21];
output=rus("2004 (C) Copyright by Iluhen LamoKilling Corp & The Design Studio Vereshchagin.\n\n\t\t\t������ ����������� ����������\n\t\t\t� �������������� �\n\t\t\tThe Design Studio Vereshchagin\n\t\t\t������������ ����� ���������\n\n\t\t\t\t\"���������-2004\"\n\n\n����� ���������� � ������������� ���� �� ����������������, ���������� \n� ��������������� ������������ \"���������-2004\"!\n\n��� ����������� ������� ���� ���: ");
cout << output;
gets(curname);
plcheck(curname);
cout << "\n\n";
output=rus("������������ ");
cout << output << player.name << endl;
output=rus("������� ");
cout << output << player.times << endl;
output=rus("������� ������ ");
cout << output << player.correct << endl;
output=rus("������� �������� ");
cout << output << player.wrong << endl;
output=rus("��� ���������: ");
cout << output;
output=rus(player.intel);
cout << output << endl;
output=rus("��� ��������: ");
cout << output;
output=rus(player.type);
cout << output << endl;
output=rus("\n\t\t\t���� 1.\n\n���� ���� ������������ ��� ��������� ������ ����������������� ������.��� ����� ���������� ��������� �������� � ��������� ��������� ������� �� ���. �� ������ ������ ������ ���� �� ������� ������ � ������ Enter.\n\n��� ������ ����� �� ���������� ����������� ������� ����� �������");
cout << output;
for (int c=1; c <=25; c++)
{
getask();
getchar();
output=rus("\n\n\t������ ");
cout << output << c << endl;
output=rus(q.quest);
cout << endl << output;
output=rus("\n1. ");
cout << output;
output=rus(q.ans1);
cout << output;
output=rus("\n2. ");
cout << output;
output=rus(q.ans2);
cout << output;
output=rus("\n3. ");
cout << output;
output=rus(q.ans3);
cout << output;
output=rus("\n4. ");
cout << output;
output=rus(q.ans4);
cout << output << endl;
set=getchar();
if (q.cor==set-48)
cor0++;
}
player.times++;
player.correct+=cor0;
player.wrong+=(25-cor0);
if (player.correct/player.times >= 24)
strcpy(player.intel,"�����");
else if (player.correct/player.times >= 19)
strcpy(player.intel,"������������");
else if (player.correct/player.times >= 14)
strcpy(player.intel,"���������");
else
strcpy(player.intel,"��������");
output=rus("\n\t\t\t���� 2.\n\n���� ���� ������������ ��� ����������� ������ ���������. ��������� ������ �� ���� �� ��������\n\n��� ������ ����� �� �������� ������� ����� �������");
cout << output;
getch();
for (int c=1; c <=10; c++)
{
gett2();
getchar();
output=rus("\n\n\t������ ");
cout << output << c << endl;
output=rus(q.quest);
cout << endl << output;
output=rus("\n1. ");
cout << output;
output=rus(q.ans1);
cout << output;
output=rus("\n2. ");
cout << output;
output=rus(q.ans2);
cout << output;
output=rus("\n3. ");
cout << output;
output=rus(q.ans3);
cout << output;
output=rus("\n4. ");
cout << output;
output=rus(q.ans4);
cout << output << endl;
set=getchar();
if (set-48==1)
test2[q.vara]++;
if (set-48==2)
test2[q.varb]++;
if (set-48==3)
test2[q.varc]++;
if (set-48==4)
test2[q.vard]++;
}
int maxt=0;
int maxn=0;
for (int l=1; l<5; l++)
{
if (test2[l]>maxt)
{
maxt=test2[l];
maxn=l;
}
}
if (maxn==1)
strcpy(player.type,"�����");
if (maxn==2)
strcpy(player.type,"����������");
if (maxn==3)
strcpy(player.type,"����������");
if (maxn==4)
strcpy(player.type,"���������");
output=rus("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n��� ���� ������� ��������. ��� ���������� ��������� ������:\n��������� ");
cout << output;
output=rus(player.type);
cout << output << " " << player.name << " ";
output=rus("������� �� ");
cout << output << cor0;
output=rus(" �������� ��������� � �� ");
cout << output << 25-cor0 << " ";
output=rus("�������� ��� ������������ �����.\n������ �� �����, ��� ���������������� ������� ��� ���������� ����������\n��� ");
cout << output;
output=rus(player.intel);
cout << output << ". " << player.name << " " << output << " ";
output=rus(" - ������ ��� ��� ����� - ������ ���.\n��, � ����� ������, ������ ���� ���������� � ������������, ����� �� ��� �� ����.\n�������� ");
cout << output << player.name << " ";
output=rus(player.type);
cout << output;
output=rus(", ��� ������� � ��� ��������� ��������.\n�� ��������, ��� �� ������� ��� ���������� ���� ����� � �����.\n\n\t\t������� �� ������������� ��������� TDSV � ILKC!\n\n\n��� ������ ������� ����� �������.");
cout << output << "\n\n\n\n\n";
setrank(curname);
getch();
}
