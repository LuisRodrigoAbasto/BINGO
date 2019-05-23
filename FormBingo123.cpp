//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include "ClassBingo.h"
 #include "ClassBolo.h"
#include "ClassLetra.h"
#include "FormPrincipal.h"
#include "FormBingo123.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int a=1;
bool sww=false;
int ii=1;
int contando=0;
int cc=0;
TStringGrid *VSG[100];
TEdit *E[100];
TForm2 *Form2;
CMatriz *A[100], *B, *C;
CLetra *L[100], *LL;
int y=0;
int x=50;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{    B=new CMatriz;
	 C=new CMatriz ;
	 LL=new CLetra;
}
//---------------------------------------------------------------------------

void TForm2::SGACMatriz(TStringGrid *SG, CMatriz *M)
{

M->Filas=SG->RowCount;
	 M->Columnas=SG->ColCount;

	 for(int i=1;i<SG->RowCount;i++)
	 {  for(int j=0;j<SG->ColCount;j++)
			{   M->Casilla[i][j]=StrToFloat(SG->Cells[j][i]); }
	 }

}
void TForm2::CMatrizASG(CMatriz *M, TStringGrid *SG)
{  SG->RowCount;
	 SG->ColCount;
	 for(int i=1; i<M->Filas;i++)
	 { for(int j=0; j<M->Columnas;j++)
	   {  SG->Cells[j][i]=FloatToStr(M->Casilla[i][j]);}
	 }

}
 //---------------------------------------------------------------------------

void TForm2::SGACLetra(TStringGrid *SG, CLetra *M)
{

M->Filas=SG->RowCount;
	 M->Columnas=SG->ColCount;

	 for(int i=0;i<SG->RowCount;i++)
	 {  for(int j=0;j<SG->ColCount;j++)
			{   M->Casilla[i][j]=StrToFloat(SG->Cells[j][i]); }
	 }

}
void TForm2::CLetraASG(CLetra *M, TStringGrid *SG)
{  SG->RowCount;
	 SG->ColCount;
	 for(int i=0; i<M->Filas;i++)
	 { for(int j=0; j<M->Columnas;j++)
	   {  SG->Cells[j][i]=String(M->Casilla[i][j]);}
	 }
}
//---------------------------------------------------------------------------
void TForm2::cartones(){

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
L[cc]=new CLetra();
A[cc]=new CMatriz();
VSG[cc]->Visible=true;
VSG[cc]->RowCount=6;
VSG[cc]->ColCount=5;
VSG[cc]->FixedCols=0;
VSG[cc]->FixedRows=0;
VSG[cc]->Font->Size=10;
VSG[cc]->Width=160;
VSG[cc]->Height=160;
VSG[cc]->DefaultColWidth=30;
VSG[cc]->DefaultRowHeight=25;
VSG[cc]->DrawingStyle=gdsClassic;
VSG[cc]->Top=50+x;
VSG[cc]->Left=5+y;
 y=y+168;
A[cc]->Filas=6;
A[cc]->Columnas=5;
L[cc]->generarLetra();
A[cc]->generar();
CLetraASG(L[cc],VSG[cc]);
CMatrizASG(A[cc],VSG[cc]);
Form2->InsertControl(VSG[cc]);
cc++;
 }
}
//---------------------------------------------------------------------------

void TForm2::Texto(){
E[cc]= new TEdit(this);
E[cc]->Visible=false;
E[cc]->Top=220+x;
E[cc]->Left=5+y;
E[cc]->Height=25;
E[cc]->Width=150;
E[cc]->Text=' ';
Form2->InsertControl(E[cc]);
}
//---------------------------------------------------------------------------
void TForm2::Eliminar(){
  for (int i = 0; i <cc ; i++) {
   delete A[i];
   delete E[i];
   delete VSG[i];
   delete L[i];
   }
   delete B;
  delete LL;
  delete SGB;
   B=new CMatriz;
   LL=new CLetra;
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

void TForm2::Bolo() {
  contando++;
char letra=' ';
 int num=0;
 do{
	 num=numeroBolo();
 }
while (B->repite_bolo(num))  ;
	SGB->ColCount=contando;
	B->Filas=2;
	B->Columnas=75;
   LL->Filas=1;
   LL->Columnas=75;
  Edit1->Text=num;
  letra=letraBoloBingo(num);
  Edit2->Text=letra;
  LL->guardar_letra(contando,letra);
  B->guardar(contando,num);
  CLetraASG(LL,SGB);
  CMatrizASG(B,SGB);
}

//---------------------------------------------------------------------------
void TForm2::Cambiar(){
for (int i = 0; i < cc; i++ ) {
  A[i]->cambiarDato(StrToInt(Edit1->Text));
  CMatrizASG(A[i],VSG[i]);
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{ Sleep(900);
cartones();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
Timer1->Enabled=true;
Button2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
 ii++;
if (ii==2 && sww==false) {
 ii=0;
 Bolo();
 Cambiar();
 for (int i = 0; i < cc; i++&& sww==false) {
	 if (  A[i]->bingoCruzado() || A[i]->bingoHorizontal() || A[i]->bingoVertical() || A[i]->bingoEsquina() && sww==false) {
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


void __fastcall TForm2::Image2Click(TObject *Sender)
{
Close();
Eliminar();
delete Form2;
Form1->Visible=true;
}
//---------------------------------------------------------------------------

