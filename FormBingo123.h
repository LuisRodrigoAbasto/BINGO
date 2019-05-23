//---------------------------------------------------------------------------

#ifndef FormBingo123H
#define FormBingo123H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TButton *Button1;
	TStringGrid *SGB;
	TEdit *Edit1;
	TButton *Button2;
	TEdit *Edit2;
	TTimer *Timer1;
	TLabel *Label1;
	TImage *Image2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void SGACMatriz(TStringGrid *SG, CMatriz *M);
	void CMatrizASG(CMatriz *M, TStringGrid *SG);
	void SGACLetra(TStringGrid *SG, CLetra *M);
	void CLetraASG(CLetra *M, TStringGrid *SG);
	void cartones();
	void Bolo();
	void Cambiar();
	void Texto();
	void Eliminar();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
