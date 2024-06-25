/************************************************************************************************
*  Dateiname: QUEUE.cpp:                                                                        *
*                                                                                               *
*  Implementierung der Klasse QUEUE                                                             *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt die Implementierung der Methoden der Klasse QUEUE                                   *
*                                                                                               *
***********************************************************************************************/
#include <iostream>
#include "QUEUE.h"
#include "EVDK.h"

/**
- der Konstruktor der Klasse QUEUE. Er initialisiert die Member-
  Variablen Enter, Last und AnzElem mit nullptr bzw. 0
*/
QUEUE::QUEUE() : Enter(nullptr), Last(nullptr), AnzElem(0)
{

}

/**
    - Diese Funktion fügt ein neues Element am Ende der Warteschlange hinzu. Sie erhöht zuerst AnzElem um 1
    - Falls die Warteschlange leer ist (Enter == nullptr), wird das neue Element direkt als Enter gesetzt.
    - Andernfalls wird das neue Element an das Ende der Liste angehängt
*/
void QUEUE::queueIn(char *inText)
{
    this->AnzElem++;

    // Queue ist leer
    if (!this->Enter)
    {
        this->Enter = new EVKD(inText, nullptr);
        return;
    }

    // gehe zum letzten Element der Liste
    EVKD *last = this->Enter;
    while (last->getNext())
        last = last->getNext();

    last->setNext(new EVKD(inText, nullptr));

}

/**
 - Diese Funktion entfernt das erste Element aus der Warteschlange und gibt einen Zeiger auf seine Daten zurück
 - Falls die Warteschlange leer ist oder AnzElem kleiner oder gleich 0 ist, wird nullptr zurückgegeben
 - Andernfalls wird der Zeiger auf die Daten des ersten Elements gespeichert:
        * das Element wird aus der Liste entfernt
        * 'Enter' wird auf das nächste Element gesetzt
        * 'AnzElem' wird um 1 verringert
*/
char *QUEUE::queueOut()
{
    if(this->AnzElem <= 0){
        return nullptr;
    }
    char *returndata = this->Enter->getDaten();
    EVKD *p = this->Enter->getNext();
    delete this->Enter;
    this->Enter = p;

    this->AnzElem --;
    return returndata;
}

/**
  - Dies ist der Destruktor der Klasse QUEUE
  - Er löscht alle Elemente in der Warteschlange, indem er die Liste von Enter bis zum Ende durchläuft und jedes Element freigibt.
*/
QUEUE::~QUEUE()
{
  EVKD *p, *q;
    p = this->Enter;

    while (p)
    {
        q = p;
        p = p->getNext();
        delete q;
    }
}


/**
    - Diese Funktion fügt ein neues Element an einer bestimmten Position in die Warteschlange ein
    - Wenn die angegebene Position außerhalb des gültigen Bereichs liegt, wird eine std::out_of_range-Ausnahme ausgelöst
    - Andernfalls wird das neue Element an der richtigen Stelle in die sortierte Liste eingefügt.
*/
void QUEUE::einfuege(EVKD *In, int Pos)
{
    if(Pos > this->AnzElem){
        throw std::out_of_range("Out of range!");
    }
      EVKD *element = this->Enter;
    EVKD *lastElement = nullptr;

    for (int i = 0; i < Pos; i++)
    {

        if (*In > *element )
            break;

        lastElement = element;
        element = element->getNext();
    }


    if (lastElement)
    lastElement->setNext(In);
    else // in ist erstes Element
        this->Enter = In;

    In->setNext(element);
    this->AnzElem++;
}

/**
    - Diese Funktion löscht das Element an einer bestimmten Position in der Warteschlange
    - Wenn die angegebene Position ungültig ist (kleiner als 1 oder größer als die Anzahl der Elemente in der Warteschlange), wird nullptr zurückgegeben
    - Andernfalls wird das Element an der angegebenen Position entfernt und ein Zeiger darauf zurückgegeben.
*/
EVKD *QUEUE::loesche(int Pos)
{
    if(Pos < 1)
        {
        return nullptr;
        }
        if (this->AnzElem < Pos)
            {
        return nullptr;
        }
        this->AnzElem--;
        if (Pos == 1)
    {
        EVKD *returnElement = this->Enter;
        this->Enter = this->Enter->getNext();
        return returnElement;
    }

    EVKD *elementBefore = this->Enter;

    for (int i = 0; i < Pos - 2; i++)
        elementBefore = elementBefore->getNext();

    EVKD *returnElement = elementBefore->getNext();

    elementBefore->setNext(returnElement->getNext());

    returnElement->setNext(nullptr);
    return returnElement;
}


/**
    - Diese Funktion sortiert die Warteschlange in aufsteigender Reihenfolge unter Verwendung des Selection Sort Algorithmus
    - Dazu werden alle Elemente nacheinander aus der Warteschlange entfernt und anschließend an der richtigen Position wieder eingefügt
*/
void QUEUE::SelSort()
{
    for (int i = 2; i <= this->AnzElem; i++)
    {
        EVKD *merker = this->loesche(i);
        this->einfuege(merker, i - 1);
    }
}


/**
    - Diese Funktion gibt den Inhalt der Warteschlange aus
    - Sie zeigt die Adressen, Namen und Verknüpfungen (Before, Next) jedes Elements in der Warteschlange an.
*/
void QUEUE::zeigDich()
{
    if (!Enter)
    {
        std::cout << "Warteschlange ist leer." << std::endl;
        return;
    }

    EVKD *before = nullptr;
    EVKD *element = this->Enter;
    char *txt;

    std::cout << "Adresse      Name                 Before     Next" << std::endl
              << "-------      ----                 ------     ----" << std::endl << std::endl;

    std::cout.setf(std::ios::left);
    std::cout.fill(' ');
    std::cout.width(0);

    while (element)
    {
        txt = element->getDaten();
        std::cout.width(10);
        std::cout << element << "   ";

        std::cout.width(20);
        std::cout << txt;
        std::cout << " ";

        std::cout.width(11);
        std::cout << before;

        std::cout.width(0);
        std::cout << element->getNext() << std::endl;

        before = element;
        element = element->getNext();

        delete[] txt;
    }
}
