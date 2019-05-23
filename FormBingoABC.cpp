//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ClassLetra.h"
#include "ClassBolo.h"
#include "FormPrincipal.h"
#include "FormBingoABC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int a=1,ii=1;
bool sww=false;
int contando=0;
int cc=0;
TStringGrid *VSG[100];
TEdit *E[100];
TForm3 *Form3;
CLetra *A[100], *B;
int y=0;
int x=50;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	 B=new CLetra;
}
//---------------------------------------------------------------------------

void TForm3::SGACLetra(TStringGrid *SG, CLetra *M)
{

M->Filas=SG->RowCount;
	 M->Columnas=SG->ColCount;

	 for(int i=0;i<SG->RowCount;i++)
	 {  for(int j=0;j<SG->ColCount;j++)
			{   M->Casilla[i][j]=StrToFloat(SG->Cells[j][i]); }
	 }

}
void TForm3::CLetraASG(CLetra *M, TStringGrid *SG)
{  SG->RowCount;
	 SG->ColCount;
	 for(int i=0; i<M->Filas;i++)
	 { for(int j=0; j<M->Columnas;j++)
	   {  SG->Cells[j][i]=String(M->Casilla[i][j]);}
	 }

}
//---------------------------------------------------------------------------
void TForm3::cartones(){
bool sw=false;
 if (cc==8) {
	y=0;
x=250;}
else{  if (cc==16) {
		   y=0;
		   x=450;
	   }
	  else{ if (cc==24) {
			 sw=true;
	 		 ShowMessage (" no se puede agregar mas cartones");
			}

	  }
}
if (sw==false) {
Texto();
VSG[cc]=new TStringGrid(this);
A[cc]=new CLetra();
VSG[cc]->Visible=true;
VSG[cc]->RowCount=5;
VSG[cc]->ColCount=5;
VSG[cc]->FixedCols=0;
VSG[cc]->FixedRows=0;
VSG[cc]->Font->Size=10;
VSG[cc]->Width=160;
VSG[cc]->Height=160;
VSG[cc]->DefaultColWidth=30;
VSG[cc]->DefaultRowHeight=30;
VSG[cc]->DrawingStyle=gdsClassic;
VSG[cc]->Top=50+x;
VSG[cc]->Left=5+y;
 y=y+168;
A[cc]->Filas=5;
A[cc]->Columnas=5;
A[cc]->generar();
CLetraASG(A[cc],VSG[cc]);
Form3->InsertControl(VSG[cc]);
cc++;
 }

 }
 //---------------------------------------------------------------------------

void TForm3::Texto(){
E[cc]= new TEdit(this);
E[cc]->Visible=false;
E[cc]->Top=220+x;
E[cc]->Left=5+y;
E[cc]->Height=25;
E[cc]->Width=150;
E[cc]->Text=' ';
Form3->InsertControl(E[cc]);
}
//---------------------------------------------------------------------------
void TForm3::Eliminar(){
  for (int i = 0; i <cc ; i++) {
   delete A[i];
   delete E[i];
   delete VSG[i];
   }
   delete B;
  delete SGB;
   B=new CLetra;

   SGB=new TStringGrid(this);
	sww=false;
	int a=1;
 ii=1;
 contando=0;
 cc=0;
   y=0;
 x=50;

}
//---------------------------------------------------------------------------

void TForm3::Bolo() {
 contando++;
	char num=' ';
 do{
	 num=letraBolo();   }
while (B->repite_bolo_letra(num))  ;
	SGB->ColCount=contando;
	B->Filas=1;
	B->Columnas=75;
  Edit1->Text=num;
  B->guardar_letra(contando,num);
  CLetraASG(B,SGB);
  for (int i = 0; i < cc; i++ ) {
  A[i]->cambiarDato(num);
  CLetraASG(A[i],VSG[i]);
  }
}

//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{  Sleep(900);
cartones();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{    Timer1->Enabled=true;
	 Button2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
 ii++;
if (ii==2 && sww==false) {
 ii=0;
 Bolo();
 for (int i = 0; i < cc; i++&& sww==false) {
	 if (A[i]->bingoCruzado() || A[i]->bingoHorizontal() || A[i]->bingoVertical()&& sww==false) {
			 sww=true;
			 E[i]->Visible=true;
		   E[i]->Text="BINGO";
			 Timer1->Enabled=false;
			 Button2->Visible=true;
	 }
 }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2Click(TObject *Sender)
{
 Close();
Eliminar();
delete Form3;
Form1->Visible=true;
}
//---------------------------------------------------------------------------

