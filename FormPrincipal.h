//---------------------------------------------------------------------------

#ifndef FormPrincipalH
#define FormPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

//---------------------------------------------------------------------------
#endif
