//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_panelu_admina.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_panelu_admina *Form_ekran_panelu_admina;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_panelu_admina::TForm_ekran_panelu_admina(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_panelu_admina::Btn_anulujClick(TObject *Sender)
{
	Edit_usun_przedmiot->Text = "";
	Edit_usun_uzytkownika->Text = "";
    Memo_komentarz->Text = "";
}
//---------------------------------------------------------------------------
