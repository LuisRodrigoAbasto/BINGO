//---------------------------------------------------------------------------

#ifndef FormBingoHorizontal123H
#define FormBingoHorizontal123H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TStringGrid *SGB;
	TButton *Button1;
	TEdit *Edit1;
	TButton *Button2;
	TTimer *Timer1;
	TImage *Image2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
	void SGACMatriz(TStringGrid *SG, CMatriz *M);
	void CMatrizASG(CMatriz *M, TStringGrid *SG);
	void cartones();
	void Bolo();
	void Texto();
	void Eliminar();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
