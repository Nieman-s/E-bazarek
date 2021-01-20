//---------------------------------------------------------------------------

#ifndef ekran_przedmiotuH
#define ekran_przedmiotuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Colors.hpp>
//---------------------------------------------------------------------------
class TForm_ekran_przedmiotu : public TForm
{
__published:	// IDE-managed Components
	TText *text_nazwa;
	TText *text_opis;
	TText *text_kwota;
	TButton *btn_doKoszyka;
	TButton *btn_kupTeraz;
	TButton *btn_licytuj;
	TImageControl *ImageControl1;
	TImage *Image_paski;
	TText *Text_napisa_nazwa;
	TText *Text_napis_kwota;
	TImage *Image_EB;
	TColorBox *ColorBox_biel;
	TImage *Image_przedmiot;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image_paskiDblClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall btn_kupTerazClick(TObject *Sender);
	void __fastcall btn_doKoszykaClick(TObject *Sender);
	void __fastcall btn_licytujClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_ekran_przedmiotu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
//---------------------------------------------------------------------------
#endif
