#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


double mu=3.11538;  //Mittelwert

double prob(vector<int> daten, double mu) { //Funktion außerhalb des Hauptprogramms starten

    double L=1; //Variable definieren

    double e_mu = exp(-mu); //Implementation der Exponentialfunktion

    for(int k : daten) {  //Vorschleife starten, die die nächsten Befehle mit allen Einträgen aus dem Vektor daten je einmal ausführt

        double mu_k = pow(mu, k); //Implementation für Potenz
        double k_f = tgamma(k+1); //Implementation für Fakultät

        L *=  mu_k * e_mu * (1/(k_f));  //Likelihood (Wahrscheinlichkeit, die Daten mit einem bestimmten mu zu erhalten)

    } //Vorschleife beenden

    return L; //Variable zurücksetzen

} //Funktion außerhalb des Hauptprogramms beenden



int main() {  //Hauptprogramm starten

    
    ifstream fin("datensumme.txt"); //Einlesedatei festlegen
    ofstream fout("likelihood.txt");  //Ausgabedatei festlegen

        vector<int> daten(0); //Vektor mit 0 Einträgen defineiren
        int n_i;  //Variable definieren

        for(int i = 0 ; i < 234 ; ++i) {  //Vorschleife starten, die folgenden Befehle 234 mal ausführt

            fin >> n_i; //aus Einlesedatei einlesen und den aktuell eingelesenen Wert nach n_i speichern
            daten.push_back(n_i); //den aktuell in n_i gespeicherten Wert dem Vektor hinzufügen

        } //vorschleife beenden

        cout << prob(daten , mu) << endl; //Likelihood für mu im Terminal ausgeben


        mu=0; //Variable zurücksetzen
        
        do{ //nachfolgende Befehle ausführen, so lange Bedingung erfüllt ist
        
            fout << mu << " " << prob(daten,mu) << endl;  //Wertepaare mu und L(mu) in Ausgabedatei schreiben
            mu+=0.1;  //Schrittweite von mu festlegen

        } while(mu<6);  //Bedingung festlegen, die zum ausführen der obigen Befehle erfüllt sein muss
    
    fin.close();  //Einlesedatei schließen
    fout.close(); //Ausgabedatei schließen

} //Hauptprogramm beenden

