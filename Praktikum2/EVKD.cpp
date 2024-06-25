/************************************************************************************************
*  Dateiname: EVDK.cpp:                                                                         *
*                                                                                               *
*  Implementierung der Klasse EVDK                                                              *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt die Implementierung der Methoden der Klasse EVDK                                    *
*                                                                                               *
***********************************************************************************************/

#include <string.h>
#include "EVDK.h"


/**
 - Der Konstruktor nimmt zwei Parameter an: einen Zeiger auf eine Zeichenkette (char *LPSZDaten)
   und einen Zeiger auf ein Objekt vom Typ "EVKD" (EVKD *Next).
 - Die Konstruktorinitialisierungsliste : AnzChar(0), Next(Next) initialisiert das Datenmitglied AnzChar mit 0
   und das Datenmitglied Next mit dem �bergebenen Next-Zeiger.
 - this->AnzChar = strlen(LPSZDaten); berechnet die L�nge der �bergebenen Zeichenkette LPSZDaten
   und weist den Wert der L�nge dem Datenmitglied AnzChar zu.
 - this->Daten = new char[this->AnzChar](); weist dem Zeiger Daten ein neues dynamisch allokiertes Zeichenarray der Gr��e AnzChar zu.
 - Die Schleife for kopiert die einzelnen Zeichen aus LPSZDaten in das Daten-Array.

*/
EVKD::EVKD(char *LPSZDaten, EVKD *Next) : AnzChar(0), Next(Next)
{
  this->AnzChar = strlen(LPSZDaten);
  this->Daten = new char[this->AnzChar]();

  for(int i = 0; i < this->AnzChar; i++){
    this->Daten[i] = LPSZDaten[i];
  }
}

/**
  - Diese Methode gibt einen Zeiger auf eine Kopie des Daten-Arrays zur�ck
  - char *dataArray = new char[this->AnzChar+1](); erstellt ein neues Zeichenarray dataArray der Gr��e AnzChar+1
  - Die Schleife for kopiert die Zeichen aus dem Daten-Array in das dataArray-Array.
  - dataArray[this->AnzChar] = '\0'; f�gt ein Nullzeichen am Ende des dataArray-Arrays hinzu
  - Das dataArray wird zur�ckgegeben
*/
char *EVKD::getDaten() const
{
    char *dataArray = new char[this->AnzChar+1]();

    for(int i = 0; i < this->AnzChar; i++){
       *(dataArray + i) = *(this->Daten + i);
    }
    dataArray[this->AnzChar] = '\0';
    return dataArray;
}

//Diese Methode gibt die Anzahl der Zeichen im Daten-Array zur�ck
int EVKD::getAnzChar()
{
 return this->AnzChar;
}

//Diese Methode gibt den Wert des Next-Zeigers zur�ck.
EVKD *EVKD::getNext()
{
 return this->Next;
}

//Diese Methode setzt den Wert des Next-Zeigers auf den �bergebenen Next-Zeiger
void EVKD::setNext(EVKD *Next)
{
    this->Next = Next;
}

//Dieser �berladungsoperator (==) vergleicht zwei EVKD-Objekte auf Gleichheit
bool EVKD::operator==(const EVKD &other)
{
    char *s1, *s2;

    s1 = this->getDaten();
    s2 = other.getDaten();

    bool returnValue = strcmp(s1, s2) == 0;

    delete[] s1;
    delete[] s2;

    return returnValue;

}

//Dieser �berladungsoperator (>) vergleicht zwei EVKD-Objekte auf Gr��er als
bool EVKD::operator>(const EVKD &other)
{
    char *s1, *s2;

    s1 = this->getDaten();
    s2 = other.getDaten();

    bool returnValue = strcmp(s1, s2) > 0;

    delete[] s1; //Objekt s1 wird mithilfe der Methode "Delete" geloescht
    delete[] s2; //Objekt s2 wird mithilfe der Methode "Delete" geloescht
    return returnValue;
}

//Der Destruktor wird aufgerufen
EVKD::~EVKD()
{
 delete[] Daten; //Objekt Daten wird mithilfe der Methode "Delete" geloescht
}
