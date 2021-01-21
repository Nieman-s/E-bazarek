//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_zapomniane_haslo *Forma_zapomniane_haslo;
TADOConnection * ADOConnection_zaph;

//---------------------------------------------------------------------------
__fastcall TForma_zapomniane_haslo::TForma_zapomniane_haslo(TComponent* Owner, TADOConnection *a_ADOConnection)
	: TForm(Owner)
{
	ADOConnection_zaph = a_ADOConnection;
}
//---------------------------------------------------------------------------
bool TForma_zapomniane_haslo::sprawdzEmail()
{
	TADOQuery* Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection_zaph;

    Query -> SQL -> Clear();
	Query -> SQL -> Add("SELECT email from dbo.uzytkownicy where trim(email) = trim('"+Edit_email->Text+"');");

    Query -> Open();

    AnsiString x = Query -> FieldByName("email")->AsString;

    if (Query -> FieldByName("email")->AsString != "")
    {
        delete Query;
        return true;
    }else
    {
        delete Query;
        return false;
	}
}

//----------------------------------------------------------------------
void __fastcall TForma_zapomniane_haslo::Btn_wyslij_wiadomoscClick(TObject *Sender)
{
	if(CheckBox_email->IsChecked == false)
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak napisanego emaila";
	}
	else if (!sprawdzEmail())
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak konta pod podanym emailem";
	}
	else
	{
		Text_blad1->Visible = false;
		ShowMessage("nie wysy�amy na maila, wi�c... Kod = " + kod);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Btn_zmien_hasloClick(TObject *Sender)
{
	if(CheckBox_kod->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak kodu";
	}
	else if(Edit_kod->Text != kod)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Bledny kod";
	}
	else if(CheckBox_nhaslo->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak napisania nowego hasla";
	}
	else if(CheckBox_pnhaslo->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak ponownego napisania nowego hasla";
	}
	else if(CheckBox_email->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Do zmiany hasla potrzebny jest email";
	}
	else
	{
		Text_blad2->Visible = false;

		TADOQuery* Query = new TADOQuery(NULL);
		Query -> Connection = ADOConnection_zaph;

		Query -> SQL -> Clear();
		Query -> SQL -> Add("UPDATE dbo.uzytkownicy SET haslo = '" +Edit_nhaslo->Text+"' WHERE trim(email) = '"+Edit_email->Text+"'");
		Query -> ExecSQL();

		delete Query;
		ModalResult = 1;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForma_zapomniane_haslo::FormClose(TObject *Sender, TCloseAction &Action)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Btn_powrotClick(TObject *Sender)
{
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void TForma_zapomniane_haslo::wygeneruj_kod()
{
	kod = "";
	short int number = 0; //chwilowe przechowanie danych
	char znak;            //znak na podstawie losowo wybranego numeru
	for (int i = 0; i < 4; i++)
	{
		number = rand()%62;
		if(number <26)
		{
			znak = 'A' + number;
		}
		else if(number >= 26 && number < 52)
		{
			znak = 'a' + number - 26;
		}
		else
		{
			znak = '0' + number - 52;
		}

		this->kod += znak;
	}
}





void __fastcall TForma_zapomniane_haslo::Edit_emailChange(TObject *Sender)
{
	if(Edit_email->Text != "")
	{
		CheckBox_email->IsChecked = true;
	}
	else
	{
		CheckBox_email->IsChecked = false;
	}
    wygeneruj_kod();
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_kodChange(TObject *Sender)
{
	if(Edit_kod->Text != "")
	{
		CheckBox_kod->IsChecked = true;
	}
	else
	{
		CheckBox_kod->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_nhasloChange(TObject *Sender)
{
	if(Edit_nhaslo->Text != "")
	{
		CheckBox_nhaslo->IsChecked = true;

		if (Edit_pnhaslo->Text != Edit_nhaslo->Text)
		{
			CheckBox_pnhaslo->IsChecked = false;
		}
	}
	else
	{
		CheckBox_nhaslo->IsChecked = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_pnhasloChange(TObject *Sender)
{
	if(Edit_pnhaslo->Text != "" && Edit_pnhaslo->Text == Edit_nhaslo->Text)
	{
		CheckBox_pnhaslo->IsChecked = true;
	}
	else
	{
		CheckBox_pnhaslo->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

