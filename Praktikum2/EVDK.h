/************************************************************************************************
*  Dateiname: EVDK.h:                                                                           *
*                                                                                               *
*  Definition der Headerdatei zu EVDK.h mit allen Methodenkoepfen                               *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt eine Definition der Methoden der Klassen EVDK                                       *
*  Achtung: Signaturen dürfen nicht geaendert werden!                                           *
***********************************************************************************************/
#ifndef EVDK_H_INCLUDED
#define EVDK_H_INCLUDED
#pragma once

class EVKD
{
private:
    char *Daten;  // Zeiger auf einen Char der Klasse EVDK
    int AnzChar;
    EVKD *Next;   //Zeiger auf ein Objekt der Klasse EVKD

public:

    EVKD(char *LPSZDaten, EVKD *Next); // soll objekte erzeugen
    ~EVKD();    //wird verwendet, um Ressourcen freizugeben, die von einem Objekt der Klasse EVKD belegt wurden

    char *getDaten() const; // rueckgabewert char array mit /0 terminiert
    int getAnzChar(); // rueckgabewert anzahl character
    EVKD *getNext(); // rueckgabewert naechstes objekt
    void setNext(EVKD *); // setzt das naechste objekt

    bool operator==(const EVKD &);  //Überladungsoperator (==), der den Gleichheitsvergleich für Objekte der Klasse EVKD implementiert
    bool operator>(const EVKD &);  // Überladungsoperator (>), der den Größenvergleich für Objekte der Klasse EVKD implementiert
};


#endif // EVDK_H_INCLUDED
