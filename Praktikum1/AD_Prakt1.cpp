/************************************************************************************************
*  Dateiname: AD_Prakt1.cpp:                                                                    *
*                                                                                               *
*  Implementierung der Klasse POINT, LINE, CIRCLE                                               *
*  Autor(en):                                                                                   *
*  Aziz Bdira: 11149897                                                                         *
*  Leonel Nguimatsia, Matrikelnummer: 11142206                                                  *
*                                                                                               *
*  Enthaelt das Hauptprogramm mit den Tests aller programmierten Methoden                       *
*  laut Aufgabenstellung:                                                                       *
*  Es werden die Schnittpunkte zweier Kreise berechnet. Zu diesen beiden Kreisen                *
*  werden je drei Punkte eingelesen. Zu diesen Punkten wird ein gemeinsamer Mittelpunkt         *
*  berechnet indem die Mittelsenkrechten der Verbindungslinie zwischen je zwei Punkten          *
*  brechnet werden.                                                                             *
*                                                                                               *
***********************************************************************************************/
#include "Myclasses.h"
#include <iostream>
using namespace std;

//Diese Klasse "WORT" enthält private Variablen und Konstruktoren für die Verwaltung von Wörtern
class WORT {
private:
	WORT* N, * P;   //Wird verwenden,um den wert des Wortes zu speichern.
	long Value;
public:

    //Ermoeglicht das Erstellen eines "WORT" -Objekts mit einem Wert und optional Verweisen auf andere "WORT" -Objekte.
	WORT(long Wert, WORT* N, WORT* P) :Value(Wert), N(N), P(P) {}
	WORT(WORT& W) :WORT(W.Value, W.N, W.P) {}
};

//Diese Funktion überprueft, ob ein übergebener String eine gültige Zahl ist
bool isNumber(const string& str)
{
    //Verwendung der Funktion "find_first_not_of" der Klasse "string", um nach Zeichen zu suchen, die nicht in einer Zahl vorkommen dürfen.
    //wird ueberprüft, ob der String nicht mit einem Punkt beginnt oder endet, um sicherzustellen, dass es sich nicht um eine Dezimalzahl handelt.
	return str.find_first_not_of("-.0123456789") == string::npos &&
		str.front() != '.' && str.back() != '.';
}


//Erstellung zwei Punkte "leonel" und "aziz" mit den Koordinaten.
//Basierend auf den Punkten wird der Radius für die Kreise "leonel_C" und "aziz_C" berechnet
//Dazu zeigt Informationen über die erstellten Kreise und deren Matrikelnummern auf der Konsole an
void abgabeTest () {

	POINT *leonel = new POINT (1, 7);
    POINT *aziz= new POINT (6, 7);
    double r_Leonel =(leonel->distanceTo(*aziz));
    double r_aziz = 3 * r_Leonel / 4;
    CIRCLE leonel_C(leonel, r_Leonel);
    CIRCLE aziz_C(aziz, r_aziz);
    cout << "\n Leonel hat die Matrikelnummer: 11142206. \n Leonel´s Kreis: \n";
    leonel_C.show();
    cout << "\n Aziz hat die Matrikelnummer: 11149897. \n Aziz´s Kreis \n";
    aziz_C.show();
}

int main() {

    //Deklaration verschiedene Variablen und Objektes, darunter zwei "WORT"-Objekt ""W1 und "W2"
	WORT* w1, *w2;
	w1 = new WORT(10,NULL,NULL);
	w2 = new WORT (*w1);

	//return 1;
    //Erstellung eines Arrays von Zeigern auf Zeichen("arr") und ein Array von Ganzzahlen("arr1").

	char* arr[15];
	int arr1 [15];
	arr1[9] = 5;
	int bs[] = {1,5,5}; new int[5];


    //Erstellung der Variable "ok" und auf den Wert "True" setzen
	bool ok = true;
	string str1, str2, str3;   //String "str1" und "str2" wurde erstellt.
	int anz;
	POINT* s1, * s2;   //Zeiger "s1" und "s2" wurde erstellt.

	abgabeTest();  //Aufruf der Funktion "abgabetest()",um die vordefinierte Kreise anzuzeigen.


	//Hiert wird eine Schleife gestartet, in der der Benutzer eine Auswahl treffen kann.
    //Die Auswahl wird eingelesen und ueberprüft, ob es sich um eine gueltige Zahl handelt.
    //Abhängig von der Auswahl des Benutzers werden verschiedene Aktionen ausgeführt
	do {
		cout << " Bitte eine Auswahl treffen: \n 1: Erstellen zweier Kreise \n 2: Erstellen von  2 Kreisen jeweils mit 3 Punkten \n 9: Programm beenden " << endl;
		cin >> str1;
		if (isNumber(str1)) {
			switch (stoi(str1)) {

            //Bei Auswahl 1 werden die Koordinaten für zwei Kreise eingelesen,
            //basierend auf den eingegebenen Werten werden die Kreise erstellt und ihre Informationen angezeigt
			case 1:
			{
				cout << "\n Bitte geben Sie zwei X und Y Koordinaten fuer Mittelpunkt und Radius des ersten Kreises:" << endl;
				cin >> str1 >> str2 >> str3;
				if (isNumber(str1) && isNumber(str2) && isNumber(str3)) {
					POINT p1(stod(str1), stod(str2));
					CIRCLE c1(&p1, stod(str3));
					cout << "\n Bitte geben Sie zwei X und Y Koordinaten fuer Mittelpunkt und Radius des zweiten Kreises: \n " << endl;
					cin >> str1 >> str2 >> str3;
					if (isNumber(str1) && isNumber(str2) && isNumber(str3)) {
						POINT p2(stod(str1), stod(str2));
						CIRCLE c2(&p2, stod(str3));

						cout << "Kreise 1:";
						c1.show();
						cout << "\n Kreise 2:";
						c2.show();
						c1.meetsOther(&c2, anz, &s1, &s2);
						cout << "\n Die Kreise schneiden sich in  " << anz << " Punkt(en) \n" << endl;
						if (anz == 1) {
							cout << "Schnittpunkt: ";
							s1->show();
							cout << endl;
						}
						if (anz == 2) {
							cout << "Schnittpunkt 1: ";
							s1->show();
							cout << "\nSchnittpunkt 2: ";
							s2->show();
							cout << endl;
						}
					}
					else {
						ok = false;
						cout << "\n Falsche Eingabe!! \n" << endl;
						break;
					}
				}
				else {
					ok = false;
					cout << "\n Falsche Eingabe!! \n" << endl;
					break;
				}
				break;

				delete s1;
				delete s2;
			}

			//Bei Auswahl 2 wird der Benutzer aufgefordert, Koordinaten für drei Punkte einzugeben, um jeweils zwei Kreise zu erstellen.
            //Die Kreise werden erstellt und ihre Informationen angezeigt, und es wird ueberprüft, ob sie sich schneiden.
			case 2:
			{
				do {
					ok = true;
					cout << "\n Kreis mit 3 Punkten: \n Erster Kreis: \n Bitte geben Sie X und Y Koordinaten des ersten Punkts: " << endl;
					cin >> str1 >> str2;
					if (isNumber(str1) && isNumber(str2)){
						POINT* p1 = new POINT(stod(str1), stod(str2));
						p1->show();

						cout << "\n Bitte geben Sie X und Y Koordinaten des zweiten Punkts: " << endl;
						cin >> str1 >> str2;
						if (isNumber(str1) && isNumber(str2)) {
							POINT* p2 = new POINT(stod(str1), stod(str2));
							p2->show();

							cout << "\n Bitte geben Sie X und Y Koordinaten des dritten Punkts: " << endl;
							cin >> str1 >> str2;
							if (isNumber(str1) && isNumber(str2)) {
								POINT* p3 = new POINT(stod(str1), stod(str2));;
								p3->show();


								if (p1 != p2 && p1 != p3 && p2 != p3 ) {
									LINE* l1 = new LINE(p1, p2);
									LINE* l2 = new LINE(p2, p3);
									if (l1->parallelTo(l2) == false) {
										CIRCLE c1(p1, p2, p3);
										cout << "\n Erster Kreis: ";
										c1.show();
										do {
											ok = true;
											cout << "\n Zweiter Kreis \n Bitte geben Sie X und Y Koordinaten des ersten Punkts: " << endl;
											cin >> str1 >> str2;
											if (isNumber(str1) && isNumber(str2)) {
												POINT* p4 = new POINT(stod(str1), stod(str2));
												p4->show();

												cout << "\n Bitte geben Sie X und Y Koordinaten des zweiten Punkts: " << endl;
												cin >> str1 >> str2;
												if (isNumber(str1) && isNumber(str2)) {
													POINT* p5 = new POINT(stod(str1), stod(str2));
													p5->show();

													cout << "\n Bitte geben Sie X und Y Koordinaten des dritten Punkts: " << endl;
													cin >> str1 >> str2;
													if (isNumber(str1) && isNumber(str2)) {
														POINT* p6 = new POINT(stod(str1), stod(str2));
														p6->show();

														if (p4 != p5 && p4 != p6 && p5 != p6) {
															LINE* l1 = new LINE(p1, p2);
															LINE* l2 = new LINE(p2, p3);
															if (l1->parallelTo(l2) == false) {
																CIRCLE c2(p4, p5, p6);
																cout << "Kreise 1:";
																c1.show();
																cout << "Kreise 2:";
																c2.show();
																c1.meetsOther(&c2, anz, &s1, &s2);
																if (s1 != NULL || s2 != NULL) {
																	cout << "\n Die Kreise schneiden sich in " << anz << " Punkt(en) \n" << endl;
																	if (anz == 1) {
																		cout << "Schnittpunkt: ";
																		s1->show();
																	}
																	if (anz == 2) {
																		cout << "Schnittpunkt 1: ";
																		s1->show();
																		cout << "\nSchnittpunkt 2: ";
																		s2->show();
																	}
																}
																else {
																	if (c1.getMiddle() == c2.getMiddle()) {
																		cout << "\n Die Kreismittelpunkte sind gleich";
																		if (p1 == c2.getMiddle())
																			cout << " und die Radien sind gleich; identische Kreise! \n";
																		else
																			cout << "und Radien sind unterschiedlich; Keine Schnittpunkte!";
																	}
																	else
																		cout << "\n Kreise liegen zu weit auseinander und koennnen sich nicht schneiden! \n";
																}
															}
															else {
																cout << "\n Falsche Eingabe!! \n Punkte liegen in einer Gerade" << endl;
																ok = false;
															}
														}
														else {
															cout << "\n Falsche Eingabe!! \n eine oder mehrere Punkte sind identisch!!" << endl;
															ok = false;
														}
													}
													else {
														ok = false;
														cout << "\n Falsche Eingabe!! \n";
													}
												}
												else {
													ok = false;
													cout << "\n Falsche Eingabe!! \n";
												}
											}
											else {
												ok = false;
												cout << "\n Falsche Eingabe!! \n";
											}
										} while (!ok);
									}
									else {
										cout << "\n Falsche Eingabe!! \n Punkte liegen in einer Gerade" << endl;
										ok = false;
									}

								}
								else {
									cout << "\n Falsche Eingabe!! \n Punkte liegen in einer Gerade" << endl;
									ok = false;
								}
							}
							else {
								ok = false;
								cout << "\n Falsche Eingabe!! \n";
							}
						}
						else {
							ok = false;
							cout << "\n Falsche Eingabe!! \n";
						}

					}
					else {
						ok = false;
						cout << "\n Falsche Eingabe!! \n" ;
					}

				} while (!ok);
				ok = false;
				break;

				delete s1;
				delete s2;
			}

			case 9:
				return 0;

			default:
				ok = false;
			}
		}else
		ok = false;

	} while (cin.fail() || !ok);  //Bei ungueltiger Eingabe oder einem Fehler wird eine entsprechende Meldung ausgegeben, und der Benutzer wird erneut zur Eingabe aufgefordert

    delete w1;
    delete w2;

};
