//---------------------------------------------------------------------------

#ifndef FormBingoABCH
#define FormBingoABCH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TButton *Button1;
	TEdit *Edit1;
	TStringGrid *SGB;
	TButton *Button2;
	TTimer *Timer1;
	TImage *Image2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void SGACLetra(TStringGrid *SG, CLetra *M);
	void CLetraASG(CLetra *M, TStringGrid *SG);
	void cartones();
	void Bolo();
	void Texto();
	void Eliminar();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
