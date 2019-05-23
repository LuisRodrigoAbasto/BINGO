//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
  #include "ClassBingo.h"
#include "ClassLetra.h"

#include "FormCargando.h"
#include "GIFImg.hpp"
#include "FormBingo123.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int a=0;
TForm4 *Form4;
TGIFImage *gif1;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{      gif1=new TGIFImage;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image1Click(TObject *Sender)
{
 gif1->Assign(Image1->Picture);
   gif1->Animate=true;
   Image1->Picture->Assign(gif1);
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
a++  ;
if (a==5) {
Form2->Visible=true;
Form4->Visible=false;
  Timer1->Enabled=false;
  a=0;
}
}
//---------------------------------------------------------------------------
