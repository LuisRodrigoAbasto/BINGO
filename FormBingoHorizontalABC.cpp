//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include "ClassLetra.h"
#include "ClassBolo.h"
#include "FormPrincipal.h"
#include "FormBingoHorizontalABC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int a=1,ii=1;
bool sww=false;
int contando=0;
int cc=0;
TStringGrid *VSG[100];
TEdit *E[100];
TForm6 *Form6;
CLetra *A[100], *B;
int y=0;
int x=50;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	 B=new CLetra;
}
//---------------------------------------------------------------------------

void TForm6::SGACLetra(TStringGrid *SG, CLetra *M)
{

M->Filas=SG->RowCount;
	 M->Columnas=SG->ColCount;

	 for(int i=0;i<SG->RowCount;i++)
	 {  for(int j=0;j<SG->ColCount;j++)
			{   M->Casilla[i][j]=StrToFloat(SG->Cells[j][i]); }
	 }

}
void TForm6::CLetraASG(CLetra *M, TStringGrid *SG)
{  SG->RowCount;
	 SG->ColCount;
	 for(int i=0; i<M->Filas;i++)
	 { for(int j=0; j<M->Columnas;j++)
	   {  SG->Cells[j][i]=String(M->Casilla[i][j]);}
	 }

}
//----------------------------------------------------------------------------

void TForm6::cartones(){
bool sw=false;
 if (cc==4) {
	y=0;
  x=200;}
else{  if (cc==8) {
		   y=0;
		   x=350;
	   }
	  else{  if (cc==12) {
		   y=0;
		   x=500;
		  }
	  else{ if (cc==16) {
			 sw=true;
			 ShowMessage (" no se puede agregar mas cartones");
			}

	  }
	  }

}
  if (sw==false) {
VSG[cc]=new TStringGrid(this);
A[cc]=new CLetra();
Texto();
VSG[cc]->Visible=true;
VSG[cc]->RowCount=3;
VSG[cc]->ColCount=9;
VSG[cc]->FixedCols=0;
VSG[cc]->FixedRows=0;
VSG[cc]->Font->Size=10;
VSG[cc]->Width=282;
VSG[cc]->Height=96;
VSG[cc]->DefaultColWidth=30;
VSG[cc]->DefaultRowHeight=30;
VSG[cc]->DrawingStyle=gdsClassic;
VSG[cc]->Top=50+x;
VSG[cc]->Left=10+y;
 y=y+340;
A[cc]->Filas=3;
A[cc]->Columnas=9;
A[cc]->generarH();
A[cc]->generarBlanco();
CLetraASG(A[cc],VSG[cc]);
Form6->InsertControl(VSG[cc]);
cc++;
 }
}

//----------------------------------------------------------------------------
void TForm6::Eliminar(){
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

//---------------------------------------------------------
void TForm6::Texto(){
E[cc]= new TEdit(this);
E[cc]->Visible=false;
E[cc]->Top=150+x;
E[cc]->Left=10+y;
E[cc]->Height=25;
E[cc]->Width=150;
E[cc]->Text=' ';
Form6->InsertControl(E[cc]);
}

//---------------------------------------------------------
void TForm6::Bolo(){
    contando++;
char num=' ';
do{ num=letraBolo() ; }
while(B->repite_bolo_letraH(num));
Edit1->Text=num;
  B->Columnas=90;
  B->Filas=1;
  SGB->ColCount=contando;
  B->guardarLetraH(contando,num),
  CLetraASG(B,SGB);
  for (int i = 0; i < cc; i++) {
  A[i]->cambiarDatoH(num);
  CLetraASG(A[i],VSG[i]);
  }

}
//---------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{   Sleep(900);
cartones();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{ Timer1->Enabled=true;
  Button2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Timer1Timer(TObject *Sender)
{
ii++;
if (ii==2 && sww==false) {
 ii=0;
 Bolo();
 for (int i = 0; i < cc; i++&& sww==false) {
	 if (A[i]->bingoHorizontalH() || A[i]->bingoVerticalH() && sww==false) {
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

void __fastcall TForm6::Image2Click(TObject *Sender)
{   Close();
Eliminar();
delete Form6;
Form1->Visible=true;
}
//---------------------------------------------------------------------------

