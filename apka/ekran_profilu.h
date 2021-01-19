//---------------------------------------------------------------------------

#ifndef ekran_profiluH
#define ekran_profiluH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image_paski;
	TColorBox *ColorBox1;
	TImage *Image_EB;
	TText *Text_email;
	TEdit *Edit_email;
	TText *Text_haslo;
	TEdit *Edit_haslo;
	TText *Text_login;
	TEdit *Edit_login;
	TImage *Image_oko;
	TColorBox *ColorBox2;
	TImage *Image_firma;
	TImage *Image_klient;
	TImage *Image_admin;
	TButton *Btn_zmien_dane;
	TButton *Btn_usun_konto;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Image_okoClick(TObject *Sender);
	void __fastcall Image_paskiClick(TObject *Sender);
	void __fastcall Btn_usun_kontoClick(TObject *Sender);
	void __fastcall Btn_zmien_daneClick(TObject *Sender);
	void __fastcall Edit_loginChange(TObject *Sender);
	void __fastcall Edit_emailChange(TObject *Sender);
	void __fastcall Edit_hasloChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
