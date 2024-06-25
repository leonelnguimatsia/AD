/************************************************************************************************
*  Dateiname: main.cpp:                                                                         *
*                                                                                               *
*  Hauptprogramm zum Test der Methoden von Klasse EVKD und QUEUE                                *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt das Hauptprogramm mit den Tests aller programmierten Methoden                       *
*  laut Aufgabenstellung:                                                                       *
*  Das Ziel dieses Praktikums ist die Erstellung eines Programms zur Bearbeitung der Einträge   *
*  in einer verketteten Liste von Strings bei gleichzeitiger Verwaltung einer Warteschlange FIFO*
*  In einem Hauptprogramm soll die Funktionsfähigkeit demonstriert werden                       *
*  .                                                                                            *
*                                                                                               *
***********************************************************************************************/
#include <string>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <string.h>
#include <math.h>
#include "QUEUE.h"
#include "EVDK.h"
using namespace std;

// definiert verschiedene Optionen im Hauptmenü, die der Benutzer auswählen kann
enum choice
{
    Warteschlange_erstellen = 1,
    Verkettete_Liste_anzeigen = 2,
    Neues_Element_in_Warteschlange_einfuegen = 3,
    Element_aus_Warteschlange_entfernen = 4,
    Liste_sortieren = 5,
    ENDE = 12
};

bool menu(); //stellt das Hauptmenü dar. Sie zeigt die verfügbaren Optionen an und ruft je nach Benutzereingabe entsprechende Funktionen auf.
void create_queue(QUEUE &q); //erstellt eine Warteschlange und füllt sie mit vordefinierten Namen
void show_list(QUEUE &q);    //zeigt die Inhalte der Warteschlange an
void new_element_in_queue(QUEUE &q); //fuegt ein neues Element zur Warteschlange hinzu, indem der Benutzer einen Namen eingibt
void sort_list(QUEUE &q);      //sortiert die Warteschlange mit dem Auswahlalgorithmus "Selection Sort
void delete_element(QUEUE &q);  //entfernt das erste Element aus der Warteschlange
string input_validated(const regex, string); //fordert den Benutzer zur Eingabe auf und validiert die Eingabe anhand eines regulären Ausdrucks
choice main_menu_input();   // liest die Benutzereingabe für das Hauptmenü und gibt die entsprechende Auswahl zurück
double console_input_double(string);


int main()
{
    bool repeat = true;
    while (repeat)
        repeat = menu();
}

bool menu()
{
    static QUEUE QUEUE;
    choice user_choice;

    cout << endl
         << "Hauptmenu" << endl
         << Warteschlange_erstellen << ". Warteschlange erstellen" << endl
         << Verkettete_Liste_anzeigen << ". Verkettete Liste anzeigen" << endl
         << Neues_Element_in_Warteschlange_einfuegen << ". Neues Element in warteschlange einfuegen" << endl
         << Element_aus_Warteschlange_entfernen<< ". Element aus der Warteschlange entfernen" << endl
         << Liste_sortieren << ". Liste sortieren" << endl
         << ENDE << ". Programm beenden" << endl
         << endl;

    user_choice = main_menu_input();
    cout << endl;

    switch (user_choice)
    {
    case Warteschlange_erstellen:
        create_queue(QUEUE);
        break;
    case Verkettete_Liste_anzeigen:
        show_list(QUEUE);
        break;
        case Neues_Element_in_Warteschlange_einfuegen:
        new_element_in_queue(QUEUE);
        break;
        case Element_aus_Warteschlange_entfernen:
        delete_element(QUEUE);
        break;
        case Liste_sortieren:
        sort_list(QUEUE);
        break;
    case ENDE:
        return false;
    default:
        cout << "Eingabe ungueltig." << endl;
        break;
    }

    return true;
}

void create_queue(QUEUE &QUEUE)
{
    char *name[] = {(char*) "Schmitz, Josef", (char*) "Mueller, Josi", (char*) "Schmitz, Anna",
                    (char*) "Mueller, Josef", (char*) "Schmitz, Josi", (char*) "Mueller, Anna",
                    (char*) "Meier, Josef", (char*) "Zacher, Josi", (char*) "Anker, Anna"};

    const int len = sizeof(name) / sizeof(char *);
    for (int i = 0; i < len; i++)
        QUEUE.queueIn(name[i]);
};
void show_list(QUEUE &QUEUE)
{
    QUEUE.zeigDich();   //zeigt die Inhalte der Warteschlange auf der Konsole an
};

void new_element_in_queue(QUEUE &QUEUE)
{
    char c_str[100];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Element eingeben ('Name, Vorname') " << std::endl
              << ">> ";

    const unsigned int len = sizeof(c_str) / sizeof(c_str[0]);
    std::cin.getline(c_str, len);

    QUEUE.queueIn(c_str);
};

void delete_element(QUEUE &QUEUE)
{
    char *c = QUEUE.queueOut();

    if (c)
    {
        std::cout << "'" << c << "' wurde entfernt." << std::endl;
        delete[] c;
    }
    else
        std::cout << "Liste ist bereits leer." << std::endl;
};

void sort_list(QUEUE &QUEUE)
{
    QUEUE.SelSort();   //implementiert den Selection-Sort-Algorithmus zum Sortieren der Warteschlange.
};

std::string input_validated(const std::regex RX, std::string msg)
{
    std::string inp;

    while (true)
    {
        std::cout << msg;
        std::cin >> inp;

        if (std::regex_match(inp, RX))
            break;
    }
    return inp;
}

/**
 * Bittet den Anwender so lange zur Eingabe, bis dieser eine gueltige Menueauswahl getroffen hat.
 *
 * @return Gueltige Auswahl
 */
choice main_menu_input()
{
    // 1,2,3,4,5 oder 12
    const std::regex RX = std::regex("([12345]|(12))");

    std::string s = input_validated(RX, ">> ");

    if (s.compare("12") == 0)
        return ENDE;
    else
        return static_cast<choice>(s[0] - '0');
}
