//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForma_zapomniane_haslo *Forma_zapomniane_haslo;
//---------------------------------------------------------------------------
__fastcall TForma_zapomniane_haslo::TForma_zapomniane_haslo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForma_zapomniane_haslo::Button1Click(TObject *Sender)
{
	if(haslo_jasiu1->Text == "")
	{
		Text3->Visible = true;
		Text3->Text = "Brak napisanego emaila";
	}
	else if(haslo_jasiu2->Text == "")
	{
		Text3->Visible = true;
		Text3->Text = "Brak napisanego starego hasla";
	}
	//elsse if (has�o nie pasuje do emaila)
	else
	{
		Text3->Visible = false;

	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Button2Click(TObject *Sender)
{
	if(haslo_jasiu3->Text == "")
	{
		Text6->Visible = true;
		Text6->Text = "Brak kodu";
	}
	else if(haslo_jasiu4->Text == "")
	{
		Text6->Visible = true;
		Text6->Text = "Brak napisania nowego hasla";
	}
	else if(haslo_jasiu5->Text == "")
	{
		Text6->Visible = true;
		Text6->Text = "Brak ponownego napisania nowego hasla";
	}
	//else if (nie by�o wygenerowanego takiego kodu)
	else
	{
		Text6->Visible = false;
		//zmiana has�a do danego emaila
	}
}
//---------------------------------------------------------------------------



void __fastcall TForma_zapomniane_haslo::FormClose(TObject *Sender, TCloseAction &Action)
{
//   Forma_ekran_startowy->Visible = true;

    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Button3Click(TObject *Sender)
{
 ModalResult = 1;
}
//---------------------------------------------------------------------------

