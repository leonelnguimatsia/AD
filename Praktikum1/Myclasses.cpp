/************************************************************************************************
*  Dateiname: Myclasses.cpp:                                                                    *
*                                                                                               *
*  Implementierung der Klasse POINT, LINE, CIRCLE                                               *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthält die Implemetierung der Methoden der Klassen POINT, LINE, CIRCLE                      *
*                                                                                               *
***********************************************************************************************/
#include "Myclasses.h"
#include <math.h>
#include <iostream>
using namespace std;


// ***********************************************
// Ab hier die Methoden fuer die Klasse POINT
// Haelt die Daten fuer einen Punkt in der Ebene
// Bietet Methoden zur Bestimmung des Abstandes
// zwichen zwei Punkten und um zu ueberpruefen ob
// der Abstand kleiner als ein Epsilon ist, das in
// der Headerdatei definiert wird
// ***********************************************


POINT::POINT() {};  //Implementierung der Standardkonstruktor, Nutzung eventuell nicht erforderlich!

// Konstruktor, erstellt aus zwei uebergebenen double-Werten ein
// Objekte einer Klasse bei der Erzeugung werden direkt initialisiet -- :X(X), Y(Y) ---
// neues POINT Objektes
POINT::POINT(double X, double Y) {

 this->X = abs(X) <= Epsilon ? 0 : X;
 this->Y = abs(Y) <= Epsilon ? 0 : Y;


};

// Copy-Konstruktor
//Die Werte eines bereits existierenden Objekts derselben Klasse werden kopiert.
POINT::POINT(POINT& P)   //Copy-Konstruktor
{
    this->X = P.X;
    this->Y = P.Y;
};

// Ermittelt die Distanz zwischen zwei Punkten
// Die Methode gibt einen Wert vom Typ double zurück und ist als const deklariert,
//was bedeutet, dass sie keine Datenmitglieder des POINT-Objekts ändert.
double POINT::distanceTo(const POINT& P)    // Abstand zweier POINT-Objekte
{
    double x_diff, y_diff;
    x_diff = P.X - this->X;
    y_diff = P.Y - this->Y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
};

// Setter fuer die X-Koordinate
void POINT::setX(double X)
{
    this->X = X;
};

//Setter fuer die Y-Koordinate
void POINT::setY(double Y)
{
    this->Y = Y;
};

//Getter-Methode: gibt den Wert von "X" zurück
double POINT::getX()
{
    return this->X;
};

//Getter-Methode: gibt den Wert von "Y" zurück
double POINT::getY()
{
    return Y;
};

// Der Zuweisungsoperator "=" überlädt die Zuweisung eines POINT-Objekts auf ein anderes.
// Er gibt eine Referenz auf das zugewiesene POINT-Objekt zurück
POINT& POINT :: operator = (const POINT& P)   // Überladener Zuweisungsoperator
{
    this->X = P.X;
    this->Y = P.Y;
    return *this;
};

// Der Additionsoperator "+" überlädt die Addition zweier POINT-Objekte.
//Er gibt eine Referenz auf ein neues POINT-Objekt zurück, das das Ergebnis der Addition repräsentiert
POINT& POINT :: operator + (const POINT& P)   // Überladener Additionsoperator
{
    double Xsum, Ysum;
    POINT* Pnew;
    Xsum = this->X + P.X;
    Ysum = this->Y + P.Y;
    Pnew = new POINT(Xsum, Ysum);
    return *Pnew;
};

//Der Subtraktionsoperator "-" überlädt die Subtraktion zweier POINT-Objekte.
//Er gibt eine Referenz auf ein neues POINT-Objekt zurück, das das Ergebnis der Subtraktion repräsentiert.
POINT& POINT :: operator - (const POINT& P)
{
    double diffX, diffY;
    POINT* Pnew;
    diffX = this->X - P.X;
    diffY = this->Y - P.Y;
    Pnew = new POINT(diffX, diffY);
    return *Pnew;
};// Überladener Subtraktionsoperator

//Der Multiplikationsoperator "*" überlädt die Multiplikation eines POINT-Objekts mit einem Skalarwert.
//Er gibt eine Referenz auf ein neues POINT-Objekt zurück, das das Ergebnis der Multiplikation repräsentiert
POINT& POINT :: operator * (double val)
{
    double x, y;
    POINT* Pnew;
    x = this->X * val;
    y = this->Y * val;
    Pnew = new POINT(x, y);

    return *Pnew;
};  // Überladener Multiplikationsoperator, POINT * Skalar

//Zusätziliche Methode bool POINT::operator!=(const POINT& p): Definiert den Überladungsoperator "!=" (Ungleichheitsoperator) für die Klasse "POINT"
//prüft, ob die X-Koordinate des aktuellen Objekts und die X-Koordinate des übergebenen Objekts, sowie die Y-Koordinate des aktuellen Objekts und
//die Y-Koordinate des übergebenen Objekts jeweils einen Unterschied haben, der größer als Epsilon ist.
bool POINT :: operator != (const POINT& p)
{
    return(abs(this->X - p.X) > Epsilon && abs(this->Y - p.Y) > Epsilon);
};

//Methode show(): kann nur in abgeleiteten Klassen überschrieben werden .
//Sie gibt die Koordinaten des Punktes in der Form "(x | y)" aus.
void POINT::show()
{
    cout<< "( " << this->X << " | " << this->Y << " )" ;
};

// Der Destruktor "~POINT()": kann in abgeleiteten Klassen überschrieben werden.
// Der Destruktor wird automatisch aufgerufen, wenn ein POINT-Objekt zerstört wird.
//In diesem Fall wird der Destruktor von LINE und CIRCLE auch den virtuellen Destruktor von POINT aufrufen
POINT::~POINT() {};// Virtueller Destruktor, wird automatisch aufgerufen durch die Destruktoren von LINE und CIRCLE

//Ende POINT



// ****************************************************
// Ab hier die Methoden fuer die Klasse LINE
// Haelt die Daten zu einer Geraden, sowohl zwei Punkte
// als auch die Darstellung in Geradengleichung.
// Bietet Methoden um den Schnittpunkt zweier Geraden
// zu bestimmen und ob die Geraden paralell verlaufen
// ****************************************************


//Konstruktor, erstellt ein LINE-Objekt aus zwei uebergebenen Punkten,
//erstellt die Geradengleichung,um die Koeffizienten der linearen Gleichung (Geradengleichung) zu speichern.
LINE::LINE(POINT* P1, POINT* P2): POINT(P1->getX(), P1->getY()), P2(P2)   //Initialisierungskonstruktor
{

    A = P1->getY() - P2->getY();
    B = P2->getX() - P1->getX();
    C = (P1->getX() * P2->getY()) - (P2->getX() * P1->getY());
    if (abs(A) <= Epsilon)
        A = abs(0);
    if (abs(B) <= Epsilon)
        B = abs(0);
    if (abs(C) <= Epsilon)
        C = abs(0);
};

//Ermittelt den Schnittpunkt zwischen zwei Geraden
POINT* LINE::meets(const LINE* L)    //Schnittpunt für zwei Geraden
{
    double xs = ((L->B) * (this->C) - (L->C) * (this->B)) / ((L->A) * (this->B) - (this->A) * (L->B));  // Bestimmung der X_S-Koordinaten
    double ys = ((L->C) * (this->A) - (L->A) * (this->C)) / ((L->A) * (this->B) - (this->A) * (L->B));  // Bestimmung der Y_S-Koordinaten

    //überprüfen, ob die Werte von X_S und Y_S klein genug sind und setzen sie auf 0, falls ja.
    if (abs(xs) <= Epsilon)
        xs = 0;
    if (abs(ys) <= Epsilon)
        ys = 0;
    POINT* s = new POINT(xs, ys);
    return s;
};

//Ueberprueft ob zwei Geraden parallel sind
// Rueckgabe:   -1 wenn die Geraden paralell sind
//              0 wenn die Geraden nicht paralell sind
bool  LINE::parallelTo(const LINE* L)   //Feststellen, ob zwei Geraden paralel sind
{
    return(abs((A / B) - (L->A / L->B)) <= Epsilon);
};

//show() überschreibt die Methode show() der Klasse "POINT".
//gibt die Koordinaten der Punkte der Linie in der Form (x1 | y1), (x2 | y2) aus
void LINE::show()
{
    POINT P1(P2->getX() - B, A + P2->getY());
    P1.show();
    std::cout << ",";
    this->P2->show();
};

//Ende class LINE



// *********************************************
// Ab hier die Methoden fuer die Klasse CIRCLE
// Haelt die Daten fuer einen Kreis
// Bietet Methoden um die Schnittpunkte zwischen
// zwei Kreisen zu berechnen und ob ein Punkt
// innerhalb des Kreises liegt
// *********************************************

// Konstruktor, erstellt aus einem Punkt und einem Radius ein CIRCLE-Objekt
// initialisiert ein "CIRCLE"-Objekt mit dem gegebenen Punkt als Mittelpunkt und dem gegebenen Radius
CIRCLE::CIRCLE(POINT *M, double R) : POINT(M->getX(), M->getY()), Radius(R) {};

//ein Initialisierungskonstruktor: Es wird verwendet, um ein Objekt vom Typ "CIRCLE" zu erstellen und es mit Werten zu initialisieren.
//Er nimmt drei Punkte als Parameter und initialisiert ein "CIRCLE"-Objekt mit einem Kreis, der durch die drei Punkte definiert wird.
CIRCLE::CIRCLE(POINT *a, POINT *b, POINT *c)
{
    double ab = a->distanceTo(*b); //Berechnung der Abstand zwischen den Punkten a und b und Speicherung in der Variablen ab
    double bc = b->distanceTo(*c); //Berechnung der Abstand zwischen den Punkten b und c und Speicherung in der Variablen bc
    CIRCLE abC(a, 2 * ab / 3);  //Erstellung ein neues "CIRCLE"-Objekt abC und erhält a als Mittelpunkt und 2 * ab / 3 als Radius
    CIRCLE baC(b, 2 * ab / 3);  //Erstellung ein neues "CIRCLE"-Objekt baC und erhält b als Mittelpunkt und 2 * ab / 3 als Radius
    CIRCLE bcC(b, 2 * bc / 3);  //Erstellung ein neues "CIRCLE"-Objekt bcC und erhält b als Mittelpunkt und 2 * bc / 3 als Radius
    CIRCLE cbC(c, 2 * bc / 3);  //Erstellung ein neues "CIRCLE"-Objekt cbC und erhält c als Mittelpunkt und 2 * bc / 3 als Radius

    //Mittelsenkrechte
    POINT* ab1, * ab2, * bc1, * bc2;  //Wird verwendet, um die Schnittpunkte-koordinaten der CIRCE zu speichern.
    int anz;                         //Wird verwendet, um die Anzahl der Schnittpunkte zu speichern.
    abC.meetsOther(&baC, anz, &ab1, &ab2); //Wird verwendet, um die Schnittpunkte zwischen der CIRCLE abC und baC zu berechnen und sie in ab1 und ab2 zu speichern.
    bcC.meetsOther(&cbC, anz, &bc1, &bc2); //Wird verwendet, um die Schnittpunkte zwischen der CIRCLE bcC und cbC zu berechnen und sie in bc1 und bc2 zu speichern.
    LINE ms1(ab1, ab2);      //Erstellung eines "LINE"-Objekt ms1 und die Punkte ab1 und ab2 werden als Endpunkte der Linie übergeben
    LINE ms2(bc1, bc2);     //Erstellung eines "LINE"-Objekt ms2 und die Punkte bc1 und bc2 werden als Endpunkte der Linie übergeben
    POINT M(*(ms1.meets(&ms2)));  //Diese Methode berechnet den Schnittpunkt der beiden Linien und gibt ein neues "POINT"-Objekt zurück
    this->setX(M.getX());  //Hier wird die x-Koordinate des Punktes M als x-Koordinate des aktuellen "CIRCLE"-Objekts gesetzt
    this->setY(M.getY());  //Hier wird die y-Koordinate des Punktes M als y-Koordinate des aktuellen "CIRCLE"-Objekts gesetzt
    Radius = M.distanceTo(*a);  //Hier wird der Radius des aktuellen "CIRCLE"-Objekts auf den Abstand zwischen den Punkten M und a gesetzt.

};
//Getter fuer Mittelpunkt: Erstellung eines neues "POINT"-Objekt und Initialisierung mit den Koordinaten des Mittelpunkts des aktuellen Kreises
POINT* CIRCLE::getMiddle()
{
    POINT* M = new POINT(getX(), getY());
    return M;
};

//Ueberschriebene Methode show der Basisklasse "POINT": Ausgabe des Mittelpunktes und des Radius
void CIRCLE::show() //Überschriebene Methode show, verwendet show von POINT: Ausgabe des Mittelpunktes und des Radius
{
    cout << "\n Mittelpunkt: ( " << getX() << " | " << getY() << " )" << "\n Radius: " << this->Radius << endl;
};

//Ueberprueft ob ein Punkt innerhalb eines Kreises liegt
//Berechnung den Abstand zwischen dem gegebenen Punkt und dem Mittelpunkt des Kreises
bool CIRCLE::isInCircle(const POINT& p)
{
    return (this->getMiddle()->distanceTo(p) <= Epsilon);
};

// Berechnet die Schnittpunkte zweier Kreise
// Diese Berechnung wird gemaess der Aufgabenstellung
//  durchgefuehrt.
// Rueckgabe der Anzahl an Schnittpunkte in "Anzahl"
// Rueckgabe der Schnittpunkte in S1 und S2
// Rueckgabe:  * Wenn die Mittelpunkte identisch sind und die Radien gleich sind, werden die Kreise als identisch betrachtet
//               dann wird die Anzahl der Schnittpunkte als unendlich .
//
//             * Wenn die Mittelpunkte identisch sind, aber die Radien unterschiedlich sind
//               dann gibt es keine Schnittpunkte.
//
//             * In allen anderen Fällen werden die Schnittpunkte berechnet und die Anzahl entsprechend festgelegt.
void CIRCLE::meetsOther(CIRCLE* C, int& Anzahl, POINT** S1, POINT** S2) //C wird übergeben, Anzahl, S1 und S2 kommen zurück
{
    double Ax = this->getMiddle()->getX();  //wird verwendet,um die x- und y-Koordinaten des Mittelpunkts des aktuellen Kreises (this) zu speichern.
    double Ay = this->getMiddle()->getY();  //wird verwendet,um die x- und y-Koordinaten des Mittelpunkts des aktuellen Kreises (this) zu speichern.
    double Bx = C->getMiddle()->getX();     //Es wird verwendet,um die x- und y-Koordinaten des Mittelpunkts des anderen Kreises (C) zu speichern.
    double By = C->getMiddle()->getY();     //Es wird verwendet,um die x- und y-Koordinaten des Mittelpunkts des anderen Kreises (C) zu speichern.
    double a = this->Radius;                //Es wird verwendet,um der Radius des aktuellen Kreises (this) zu speichern.
    double b = C->Radius;                   //Es wird verwendet,um der Radius des anderen Kreises (C) zu speichern.

    //Es wird verwendet,um der Abstand zwischen den Mittelpunkten der beiden Kreise zu speichern.
    //Dies wird berechnet, indem die Methode distanceTo auf dem Mittelpunkt des aktuellen Kreises (this->getMiddle()) aufgerufen wird
    //und die Koordinaten des Mittelpunkts des anderen Kreises übergeben werden (POINT(C->getMiddle()->getX(), C->getMiddle()->getY())).
    double c = this->getMiddle()->distanceTo(POINT(C->getMiddle()->getX(), C->getMiddle()->getY())); //Abstand der Mittelpunkte zueinander
    double x, y;   //wird verwendet,um die Koordinaten der Schnittpunkte zu berechnen und zu speichern.

    //Ueberprüft, ob die Kreise identisch sind, d.h. ob der Abstand der Mittelpunkte sehr
    //klein (kleiner als Epsilon) ist und die Radien gleich sind
    if (c <= Epsilon && a == b)
    {
        //cout << "Die Kreise sind identisch!" << endl;
        Anzahl = INFINITY;
        *S1 = NULL;
        *S2 = NULL;
    }
    else

        //Ueberprüft, ob die Kreiszentren identisch sind, aber die Radien unterschiedlich sind
        if (c == Epsilon && a != b)
        {
            //cout << "Die Kreiszentren sind identisch mit verschieden Radien!" << endl;
            Anzahl = 0;
            *S1 = NULL;
            *S2 = NULL;
        }

    //Wenn die obigen Bedingungen nicht erfüllt sind, werden die Koordinaten der Schnittpunkte berechnet
        else
        {
            x = (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * c);

            // Ueberprüft, ob der Ausdruck pow(a, 2) - pow(x, 2) größer oder gleich 0 ist. Wenn ja, gibt es Schnittpunkte
            if (pow(a, 2) - pow(x, 2) >= 0)
            {
                if (pow(a, 2) - pow(x, 2) <= Epsilon)
                {
                    y = 0;
                    Anzahl = 1;
                    *S1 = new POINT(Ax + (x * (Bx - Ax) / c), Ay + (x * (By - Ay) / c));
                    *S2 = NULL;
                }
                else
                {
                    y = sqrt(pow(a, 2) - pow(x, 2));
                    Anzahl = 2;
                    *S1 = new POINT(Ax + (x * (Bx - Ax) / c) - (y * ((By - Ay) / c)), Ay + (x * (By - Ay) / c) + (y * (Bx - Ax) / c));
                    *S2 = new POINT(Ax + (x * (Bx - Ax) / c) + (y * ((By - Ay) / c)), Ay + (x * (By - Ay) / c) - (y * (Bx - Ax) / c));

                }
            }
            else
            {
                Anzahl = 0;
                *S1 = NULL;
                *S2 = NULL;
            }
        }
};

//Ende CIRCLE






