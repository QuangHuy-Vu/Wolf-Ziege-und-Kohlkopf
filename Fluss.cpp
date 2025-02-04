/*
 *  Das Programm erlaubt es Spielstrategien des bekannten
 *  Wolf-Ziege-Kohlkopf-Problems interaktiv durchzuspielen.
 */

#include <iostream>
using namespace std;

int main() {
  enum subjekte { Bauer, Wolf, Ziege, Kohlkopf };

  enum ufer { ufer_links, ufer_rechts };

  struct info {
    char name[10];
    ufer ort;
  };

  // Hier den eigenen Code ergaenzen
  info lage[4] = {{"Bauer", ufer_links},
                  {"Wolf", ufer_links},
                  {"Ziege", ufer_links},
                  {"Kohlkopf", ufer_links}};

  bool abbruch = false;
  while (!abbruch) {
    cout << "Ufer links: ";
    for (int i = 0; i < 4; i++) {
      if (lage[i].ort == ufer_links) {
        cout << lage[i].name << " ";
      }
    }
    cout << endl
         << "-------------------------------------" << endl
         << "Ufer_rechts: ";
    for (int i = 0; i < 4; i++) {
      if (lage[i].ort == ufer_rechts) {
        cout << lage[i].name << " ";
      }
    }
    char Eingabe = 0;
    cout << endl << "Gib du die Buchstabe ein: ";
    cin >> Eingabe;
    switch (Eingabe) {
      case 'B':
        if (lage[0].ort == ufer_links)
          lage[0].ort = ufer_rechts;
        else
          lage[0].ort = ufer_links;
        break;
      case 'W':
        if (lage[1].ort == lage[0].ort) {
          if (lage[1].ort == ufer_links) {
            lage[1].ort = ufer_rechts;
            lage[0].ort = ufer_rechts;
          } else {
            lage[1].ort = ufer_links;
            lage[0].ort = ufer_links;
          }
        } else {
          cout << "Das Subjekt befindet sich nicht auf gleichem Ufer wie von "
                  "dem Bauer! Versuch du nochmal."
               << endl;
        }
        break;
      case 'Z':
        if (lage[2].ort == lage[0].ort) {
          if (lage[2].ort == ufer_links) {
            lage[2].ort = ufer_rechts;
            lage[0].ort = ufer_rechts;
          } else {
            lage[2].ort = ufer_links;
            lage[0].ort = ufer_links;
          }
        } else {
          cout << "Das Subjekt befindet sich nicht auf gleichem Ufer wie von "
                  "dem Bauer! Versuch du nochmal."
               << endl;
        }
        break;
      case 'K':
        if (lage[3].ort == lage[0].ort) {
          if (lage[3].ort == ufer_links) {
            lage[3].ort = ufer_rechts;
            lage[0].ort = ufer_rechts;
          } else {
            lage[3].ort = ufer_links;
            lage[0].ort = ufer_links;
          }
        } else {
          cout << "Das Subjekt befindet sich nicht auf gleichem Ufer wie von "
                  "dem Bauer! Versuch du nochmal."
               << endl;
        }
        break;
      case 'Q':
        cout << "Das Spiel wird beendet." << endl;
        abbruch = true;
        break;
      default:
        cout << "Ungültige Buchstabe. Bitte versuchen Sie noch einmal." << endl;
        break;
        if (lage[1].ort == lage[2].ort) {
          cout << "Womp womp, der Wolf frisst die Ziege" << endl;
          abbruch = 0;
        } else if (lage[2].ort == lage[3].ort) {
          cout << "Womp womp, die Ziege frisst den Kohlkopf" << endl;
          abbruch = 0;
        }
    }
    if (lage[1].ort == lage[2].ort && lage[1].ort != lage[0].ort) {
      cout << "Womp womp, der Wolf frisst die Ziege" << endl;
      abbruch = 1;
    } else if (lage[2].ort == lage[3].ort && lage[2].ort != lage[0].ort) {
      cout << "Womp womp, die Ziege frisst den Kohlkopf" << endl;
      abbruch = 1;
    }
    if (lage[0].ort == ufer_rechts && lage[1].ort == ufer_rechts &&
        lage[2].ort == ufer_rechts && lage[3].ort == ufer_rechts) {
      cout << "Du hast gewonnen. Du kriegst den Skibidi Rizz" << endl;
      abbruch = 1;
    }
  }
  return 0;
}
