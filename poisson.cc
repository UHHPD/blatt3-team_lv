#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double mu = 3.11538;  //Mittelwert aus Aufgabe 2, Blatt 2
int N = 234;

double poisson(double mu, int k) {  //Funktion außerhalb des Hauptprogramms

    double e_mu = exp(-mu); //Implementation der Exponentialfunktion
    double mu_k = pow(mu, k); //Implementation für Potenz
    double k_f = tgamma(k+1); //Implementation für Fakultät
    double P = mu_k * e_mu * (1/(k_f)); //Poissonwahrscheinlichkeit
    return P; //Ausgabewert der Funktion

}

int main() {

    using namespace std;
    ifstream fin("datensumme.txt"); //Einlesedatei festlegen
    ofstream fout("hist.txt");  //Ausgabedatei festlegen
    ofstream fout2("histpoi.txt");

    vector<int> zaehler(11);  //Vektor mit 11 Einträgen definieren
    int n_i;  //Variable definieren

    for(int i = 0 ; i < 234 ; ++i) {  //Vorschleife starten, die die nächsten Befehle 234 mal ausführt
        fin >> n_i; //aus Einlesedatei einlesen und den aktuell eingelesenen Wert nach n_i speichern
        zaehler [n_i] += 1; //Vektoreintrag an der Stelle des eingelesenen Eintrags um einen erhöhen
    }

    for(int j=0;j<11;++j) { //Vorschleife starten, die die nächsten Befehle 11 mal ausführt
        cout << zaehler [j] << endl;  //Vektoreintrag an j'ter Stelle ausgeben
        double E = poisson(mu, j)*N;
        fout <<j; //j in Ausgabedatei schreiben
        fout <<" "; //leere Spalte in Ausgabedatei schreiben
        fout <<zaehler [j]<< endl;  //Vektoreintrag an j'ter Stelle in Ausgabedatei schreiben
        fout2 <<j;  //j in 2.Ausgabedatei schreiben
        fout2 <<" ";  //leere Spalte in 2. Ausgabedatei schreiben
        fout2 <<zaehler [j];  //Vektoreintrag an j'ter Stelle in 2. Ausgabedatei schreiben
        fout2 <<" ";  //leere Spalte in 2. Ausgabedatei schreiben
        fout2 <<E<< endl; //Erwartung aus der Poissonverteilung in 2. Ausgabedatei schreiben

    }

    fin.close();
    fout.close();
    fout2.close();

}