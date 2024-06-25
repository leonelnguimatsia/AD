/************************************************************************************************
*  Dateiname: QUEUE.h:                                                                          *
*                                                                                               *
*  Definition der Headerdatei zu QUEUE.h mit allen Methodenkoepfen                              *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt eine Definition der Methoden der Klassen QUEUE                                      *
*  Achtung: Signaturen dürfen nicht geaendert werden!                                           *
***********************************************************************************************/
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#pragma once
#include "EVDK.h"

class QUEUE
{
private:

    EVKD *Enter;  //ist ein Zeiger auf das erste Element in der Warteschlange
    EVKD *Last;   //ist ein Zeiger auf das letzte Element in der Warteschlange
    int AnzElem;  //speichert die Anzahl der Elemente in der Warteschlange.

public:
    QUEUE();   //Standard Konstruktor der Klasse QUEUE
    ~QUEUE();  //Destruktor der Klasse QUEUE

    void queueIn(char *InText); // neues element erstellen am Ende der Warteschlange
    char *queueOut(); // letztes element loeschen und gibt den Text dieses Elements zurück

    void einfuege(EVKD *In, int Pos); // fuegt objekt IN vor POS
    EVKD *loesche(int Pos); // loeschen des elements pos  //erste element hat 1, letzte element hat pos=anz  und gibt einen Zeiger auf das gelöschte Objekt zurück
    void SelSort();  //alphabetische sortierung in alphabetischer Reihenfolge

    void zeigDich(); //gibt die Elemente in der Warteschlange aus
};


#endif // QUEUE_H_INCLUDED
