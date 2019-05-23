//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ClassBingo.h"
#include "ClassLetra.h"
#include "FormPrincipal.h"
#include "FormBingoABC.h"
#include "FormBingo123.h"
#include "FormCargando.h"
#include "FormBingoHorizontal123.h"
#include "FormBingoHorizontalABC.h"
#include "GIFImg.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TGIFImage *gif1, *gif2, *gif3, *gif4, *gif5, *gif6;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{     gif1=new TGIFImage;
	gif2=new TGIFImage;
	gif3=new TGIFImage;
	gif4=new TGIFImage;
	gif5=new TGIFImage;
	gif6=new TGIFImage;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{    gif1->Assign(Image1->Picture);
   gif1->Animate=true;
   Image1->Picture->Assign(gif1);

	gif2->Assign(Image2->Picture);
   gif2->Animate=true;
   Image2->Picture->Assign(gif2);

	gif3->Assign(Image3->Picture);
   gif3->Animate=true;
   Image3->Picture->Assign(gif3);

	gif4->Assign(Image4->Picture);
   gif4->Animate=true;
   Image4->Picture->Assign(gif4);

   gif5->Assign(Image5->Picture);
   gif5->Animate=true;
   Image5->Picture->Assign(gif5);

   gif6->Assign(Image7->Picture);
   gif6->Animate=true;
   Image7->Picture->Assign(gif6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{ Form2=new TForm2(this);
  Form4->Visible=true;
  Form1->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image4Click(TObject *Sender)
{ Form3=new TForm3(this);
 Form3->Visible=true;
 Form1->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image7Click(TObject *Sender)
{Form5=new TForm5(this);
 Form5->Visible=true;
 Form1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{  Form6=new TForm6(this);
 Form6->Visible=true;
 Form1->Visible=false;
}
//---------------------------------------------------------------------------

