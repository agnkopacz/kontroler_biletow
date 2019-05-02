/*Napisz funkcjê logiczn¹ "kontroler biletów", która sprawdza wa¿noœæ biletu okresowego.
Jako drugi parametr funkcji zwracana jest liczba dni, która pozosta³a do wykorzystania na bilecie.
Funkcja odnosi siê do daty dzisiejszej. Zak³adamy, ¿e bilet jest 30dniowy i tyle samo dni ma miesi¹c. */

#include <fstream>
#include <iostream>
using namespace std;
struct Data { int miesiac;
              int dzien;
              int rok;
              };
             
bool kontroler(Data termin, int &liczba_dni);
 
int main()
{
    Data koniec_wazn;
    int pozostale=0;
   
    cout << "Podaj date waznosci: " << endl;

    cout << "dzien: ";
    cin >> koniec_wazn.dzien;
    
    cout << "miesiac: ";
    cin >> koniec_wazn.miesiac;
   
    cout << "rok: ";
    cin >> koniec_wazn.rok;
   
    if(kontroler(koniec_wazn, pozostale))
    cout << "Liczba pozostalych dni do konca waznosci biletu: " << pozostale << endl;
   
    else
    cout << "Bilet niewazny" << endl;

       
    system("PAUSE");
    return 0;
}

bool kontroler(Data termin, int &liczba_dni)
{
    int liczba_miesiecy;
    int liczba_lat;
    int liczba;
    Data dzis;
   
    cout << "Podaj date dzisiejsza: " << endl;

    cout << "dzien: ";
    cin >> dzis.dzien;
    
    cout << "miesiac: ";
    cin >> dzis.miesiac;
   
    cout << "rok: ";
    cin >> dzis.rok;
   
    //liczba dni
    if(dzis.dzien>termin.dzien)
    liczba=(30-dzis.dzien)+ termin.dzien; 
    else
    liczba=termin.dzien-dzis.dzien;
   
    //liczba miesiecy
    if(termin.miesiac>=dzis.miesiac)
    liczba_miesiecy=termin.miesiac-dzis.miesiac;
   
    if(termin.miesiac<dzis.miesiac && termin.rok>dzis.rok)
    liczba_miesiecy=(12-dzis.miesiac)+termin.miesiac;
          
    //liczba lat
    if(termin.rok>=dzis.rok && termin.miesiac>=dzis.miesiac)
	liczba_lat=termin.rok-dzis.rok;
       
    liczba_dni=liczba+(liczba_miesiecy*30)+(liczba_lat*365);
   
    if(dzis.rok>termin.rok)
    return false;
       
    if(dzis.rok==termin.rok && dzis.miesiac>termin.miesiac)
    return false;
   
    if(dzis.dzien>termin.dzien && dzis.miesiac==termin.miesiac && dzis.rok==termin.rok)
    return false;

    else
    return true;
}

