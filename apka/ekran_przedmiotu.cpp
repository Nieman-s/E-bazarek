//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_przedmiotu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_przedmiotu::TForm_ekran_przedmiotu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::Image1DblClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::FormActivate(TObject *Sender)
{
	/*
	je�li to licytacja, to:
	Text_napis_kwota->Text = "aktualna cena";
	btn_kupTeraz->Visible = false;
	btn_doKoszyka->Visible = false;
	btn_licytuj->Visible = true;
	*/


}
//---------------------------------------------------------------------------

