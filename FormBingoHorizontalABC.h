//---------------------------------------------------------------------------

#ifndef FormBingoHorizontalABCH
#define FormBingoHorizontalABCH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
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
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
	void SGACLetra(TStringGrid *SG, CLetra *M);
	void CLetraASG(CLetra *M, TStringGrid *SG);
	void Texto();
	void Bolo();
	void Eliminar();
	void cartones();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
