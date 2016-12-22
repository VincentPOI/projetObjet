/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Location.cpp
 * Author: hadrien
 * 
 * Created on 25 novembre 2016, 14:39
 */
#include "Location.h"
#include <ctime>
using namespace std;

Location::Location() {
    this->dateDebut = "NA";
    this->montantFacture = 0;
}

Location::Location(string dateDebut, string dateFin, double montantFacture, list<Article*> articlesLoues) {
    this->dateDebut = dateDebut;
    this->dateFin = dateFin;
    this->montantFacture = montantFacture;
    this->articlesLoues = articlesLoues;
}

void Location::setDateDebut(string dateDebut) {
    this->dateDebut = dateDebut;
}

string Location::getDateDebut() {
    return this->dateDebut;
}

void Location::setDateFin(string dateFin) {
    this->dateFin = dateFin;
}

string Location::getDateFin() {
    return this->dateFin;
}

void Location::setMontantFacture(double montantFacture) {
    this->montantFacture = montantFacture;
}

double Location::getMontantFacture() {
    return this->montantFacture;
}

void Location::setArticlesLouees(list<Article*> articlesLouees) {
    this->articlesLoues = articlesLouees;
}

list<Article*> Location::getArticlesLouees() const {
    return articlesLoues;
}

void Location::calculMontant() {

    char toujoursEnCours;
    if (this->dateFin.compare("NA") == 0) {
        cout << "Arrêter la location à ce jour ? (O/N)" << endl;
        cin>>toujoursEnCours;
        if (toujoursEnCours == 'O') {
            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer, 80, "%d", timeinfo);
            string jour(buffer);
            strftime(buffer, 80, "%m", timeinfo);
            string mois(buffer);
            strftime(buffer, 80, "%Y", timeinfo);
            string annee(buffer);

            this->dateFin = jour + "/" + mois + "/" + annee;

            string s = this->dateDebut;
            string delimiter = "/";
            int cpt = 0;
            int diffDate = 0;
            size_t pos = 0;
            string token;
            double montantFacture = 0;
            while ((pos = s.find(delimiter)) != string::npos || cpt != 3) {
                token = s.substr(0, pos);
                if (cpt == 0) { //jour
                    diffDate = strtod(jour.c_str(), NULL) - strtod(token.c_str(), NULL);
                }
                if (cpt == 1) { //mois
                    diffDate = diffDate + 30 * (strtod(mois.c_str(), NULL) - strtod(token.c_str(), NULL));
                }
                if (cpt == 2) {//annee
                    diffDate = diffDate + 365 * (strtod(annee.c_str(), NULL) - strtod(token.c_str(), NULL));
                }
                s.erase(0, pos + delimiter.length());
                cpt++;
            }
            for (list<Article*>::iterator it = this->articlesLoues.begin(); it != this->articlesLoues.end(); it++) {
                montantFacture = montantFacture + diffDate * (*it)->getPrixJourArticle();
            }
            cout << "Montant de la facture pour la location: " << montantFacture << endl;
            this->montantFacture = montantFacture;
        }

    } else {

        string jour, mois, annee;
        int cpt = 0;
        size_t pos = 0;
        string token;
        string delimiter = "/";
        string s = this->dateFin;
        while ((pos = s.find(delimiter)) != string::npos || cpt != 3) {
            token = s.substr(0, pos);
            if (cpt == 0) { //jour
                jour = token;
            }
            if (cpt == 1) { //mois
                mois = token;
            }
            if (cpt == 2) {//annee
                annee = token;
            }
            s.erase(0, pos + delimiter.length());
            cpt++;
        }

        string s2 = this->dateDebut;
        cpt = 0;
        pos = 0;
        int diffDate = 0;

        double montantFacture = 0;
        while ((pos = s2.find(delimiter)) != string::npos || cpt != 3) {
            token = s2.substr(0, pos);
            if (cpt == 0) { //jour
                diffDate = strtod(jour.c_str(), NULL) - strtod(token.c_str(), NULL);
            }
            if (cpt == 1) { //mois
                diffDate = diffDate + 30 * (strtod(mois.c_str(), NULL) - strtod(token.c_str(), NULL));
            }
            if (cpt == 2) {//annee
                diffDate = diffDate + 365 * (strtod(annee.c_str(), NULL) - strtod(token.c_str(), NULL));
            }
            s2.erase(0, pos + delimiter.length());
            cpt++;
        }
        for (list<Article*>::iterator it = this->articlesLoues.begin(); it != this->articlesLoues.end(); it++) {
            montantFacture = montantFacture + diffDate * (*it)->getPrixJourArticle();
        }
        cout << "Montant de la facture pour la location: " << montantFacture << endl;
        this->montantFacture = montantFacture;
    }
}


Location::~Location() {
}

void Location::affiche() {
    cout << "\nDate de début de la location: " << this->dateDebut << endl;
    cout << "Montant de la facture à ce jour: " << this->montantFacture << endl;
    for (list<Article*>::iterator it = this->articlesLoues.begin(); it != this->articlesLoues.end(); it++) {
        (*it)->affiche(cout);
    }
}