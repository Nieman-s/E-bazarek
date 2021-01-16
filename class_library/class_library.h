#include <string>
#include <iostream>

//do zrobienia: mozna przeniesc obsloge wystawionych przedmiotow do osoby

class Przedmiot{
private:
	unsigned int ID;
	std::string nazwa;
	unsigned int ilosc;
	unsigned int IDWlasciciela;
	unsigned int cena;
	Przedmiot* next;
	std::string opis;

public:
	bool sprawdz_id_wlasciciela(unsigned int idOsoby);
	void wypisz();
	unsigned int wypisz_id_wlasciciela();
	bool czy_dostepny();
	unsigned int podaj_id();
	void usun_przedmioty(int ilosc);
	
};


class HistoriaLicytacji {
public:
	unsigned int cena;
	HistoriaLicytacji* next;
};


class Osoba {
private:
	std::string mail;
	std::string haslo;
	unsigned int ID;
	static unsigned int licznik;

public:
	Osoba(std::string newMail = "brak_danych", std::string newHaslo = "brak_danych");
	bool sprawdz_dane(std::string compMail, std::string compHaslo);
	void edytuj_dane(std::string newMail, std::string newHaslo);
	unsigned int podaj_id();		//nowododana, nie ma w diagramie klas

};


class Klient : public Osoba {
private:
	std::string imieINazwisko;
	Klient* next;
	Przedmiot* koszyk;

public:
		//obsluga wystawionych przedmiotow
	void dodaj_przedmiot();
	void usun_przedmiot();
	void edytuj_przedmiot();

		//obsluga wystawionych licytacji
	void dodaj_licytacje();
	void usun_licytacje();

		//dodawanie przedmiotu do koszyka
	void dodaj_do_koszyka(unsigned int id_przedmiotu, int ilosc);

		//zakup przedmiotow z koszyka
	Przedmiot* kup();

		//???
	Przedmiot* zwroc_koszyk();
		
		//oproznia koszyk uzytkownika
	void oproznij_koszyk();

	//gettery
	std::string podaj_nazwe_klienta();
	Klient* podaj_wskaznik_next_klienta();

	//settery
	void ustaw_nazwe_klienta(std::string nazwa_do_ustawienia);
	void ustaw_wskaznik_next_klienta(Klient* wskaznik_do_ustawienia);

};


class Licytacja : public Przedmiot {
private:
	unsigned int czasZakonczenia;
	Klient* uczestnicy;
	HistoriaLicytacji* head;

public:
	void wygrana();
	void dodaj_historie(HistoriaLicytacji* toAdd);
	void dodaj_oferte();

};


class Firma : public Osoba {
private:
	std::string nazwa_firmy;
	Firma* next;

public:
		//obsluga wystawionych przedmiotow
	void dodaj_przedmiot();
	void usun_przedmiot();
	void edytuj_przedmiot();

		//obsluga wystawionych licytacji
	void dodaj_licytacje();
	void usun_licytacje();

		//gettery
	std::string podaj_nazwe_firmy();
	Firma* podaj_wskaznik_next_firmy();

		//settery
	void ustaw_nazwe_firmy(std::string nazwa_do_ustawienia);
	void ustaw_wskaznik_next_firmy(Firma* wskaznik_do_ustawienia);

};


class Admin : public Osoba {
public:
	void usun_przedmiot(unsigned int id_przedmiotu);
	void usun_uzytkownika(unsigned int id_uzytkownika);

};


class ListaFirm {
private:
	Firma* head;

public:
	void dodaj(Firma* toAdd);
	bool sprawdz(std::string email_firmy, std::string nazwa_firmy);
	Firma* wyszukaj_firme(unsigned int id_firmy);
	Firma* wyszukaj_firme(std::string nazwa_firmy);
		
};


class ListaKlientow {
private:
	Klient* head;

public:
	void dodaj(Klient* toAdd);
	bool sprawdz(std::string email_klienta, std::string nazwa_klienta);
	Klient* wyszukaj_klienta(unsigned int id_klienta);
	Klient* wyszukaj_klienta(std::string nazwa_klienta);

};