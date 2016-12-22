/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Magasin.cpp
 * Author: vincent
 * 
 * Created on 25 novembre 2016, 14:19
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Magasin.h"
#include "FauteuilRoulant.h"
#include "MatelasAir.h"
#include "SouleveMalade.h"
#include "MaterielLit.h"
#include "tri.h"
using namespace std;

Magasin::Magasin() {

}

Magasin::Magasin(list<Article*> listeArticle, list<Client*> listeClients) {
    this->listeArticle = listeArticle;
    this->listeClients = listeClients;
}

void Magasin::ajouterArticle() {
    string typeArticle = "NA";
    string refArticle;
    string marqueArticle;
    string modeleArticle;
    double prixJourArticle;
    int nbStockArticle;
    cout << "Nouvel article: ";
    while (typeArticle.compare("FR") != 0 && typeArticle.compare("MR") != 0 && typeArticle.compare("SM") != 0 && typeArticle.compare("ML") != 0 && typeArticle.compare("R") != 0) {
        cout << "type d'article?(Fauteuil roulant : FR, Matelas air : MR, Souleve Malade : SM, Materiel lit : ML, retour:R)-> ";
        cin >> typeArticle;
    }

    if (typeArticle == "R") {
        return;
    }
    cout << "Reférence?(0000AZ)";
    cin >> refArticle;
    cout << "Marque?";
    cin >> marqueArticle;
    cout << "modeleArticle?";
    cin >> modeleArticle;
    cout << "Prix a la location, journalier?";
    cin >> prixJourArticle;
    cout << "Nombre de cet article en stock?";
    cin >> nbStockArticle;

    if (typeArticle == "FR") {
        double largeur;
        double poids;
        cout << "largeur de l'assise du fauteuil roulant?";
        cin >> largeur;
        cout << "poids du fauteuil roulant?";
        cin >> poids;
        this->listeArticle.push_front(new FauteuilRoulant(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, largeur, poids));
    } else if (typeArticle == "MR") {
        string dimension;
        int pmax;
        double tpsgonfl;
        cout << "dimension du matela?";
        cin >> dimension;
        cout << "poids maximum supporté?";
        cin >> pmax;
        cout << "temps de gonflage?";
        cin >> tpsgonfl;
        this->listeArticle.push_front(new MatelasAir(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, pmax, dimension, tpsgonfl));
    } else if (typeArticle == "SM") {
        int caplevage;
        int degrepivot;
        cout << "capacité de levage?";
        cin >> caplevage;
        cout << "degre pivot fleau?";
        cin >> degrepivot;
        this->listeArticle.push_front(new SouleveMalade(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, caplevage, degrepivot));
    } else if (typeArticle == "ML") {
        double pmax;
        string dimension;
        bool typemat;
        cout << "Lit médicalisé / table d'alité (1/0)?";
        cin >> typemat;
        cout << "poids maximum supporté?";
        cin >> pmax;
        cout << "dimensions?";
        cin >> dimension;
        this->listeArticle.push_front(new MaterielLit(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, pmax, dimension, typemat));
    }
}

void Magasin::afficherArticles(ostream& ostr, bool maj) {
    if (!maj) {
        string tri;
        cout << "Afficher dans quel ordre? :";
        cout << "Reférence : REF, Marque : MAR, Modèle : MOD, Prix par jours : PJ, Retour : R -> ";
        cin >> tri;

        if (tri == "R") {
            return;
        } else if (tri == "MAR") {
            listeArticle.sort(triMarque());
        } else if (tri == "MOD") {
            listeArticle.sort(triModele());
        } else if (tri == "PJ") {
            listeArticle.sort(triPrixJour());
        } else {
            listeArticle.sort();
        }
    }
    for (list<Article*>::iterator it = this->listeArticle.begin(); it != this->listeArticle.end(); it++) {
        (*it)->affiche(ostr);
    }
}

void Magasin::majStock() {
    ofstream fichier("Stock.txt", ios::out | ios::trunc);

    if (fichier) {
        this->afficherArticles(fichier, true);
        fichier.close();

    } else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Magasin::loadStock() {
    ifstream fichier("Stock.txt", ios::in);
    if (fichier) {
        string ligne;
        FauteuilRoulant * f;
        MatelasAir * mr;
        SouleveMalade * sm;
        MaterielLit * ml;
        int typeArticle = 0;
        int cpt = 15;
        Article* a;

        while (getline(fichier, ligne)) {
            if (ligne.find("*") != ligne.npos) {
                cpt = 0;
                ligne = ligne.substr(ligne.find(":") + 2);
                ligne = ligne.replace(ligne.end() - 16, ligne.end(), "");
                if (ligne.find("FR") != ligne.npos) {
                    a = new FauteuilRoulant();
                    typeArticle = 0;
                } else if (ligne.find("MR") != ligne.npos) {
                    a = new MatelasAir();
                    typeArticle = 1;
                } else if (ligne.find("SM") != ligne.npos) {
                    a = new SouleveMalade;
                    typeArticle = 2;
                } else if (ligne.find("ML") != ligne.npos) {
                    a = new MaterielLit;
                    typeArticle = 3;
                }
                a->setRefArticle(ligne);
            } else {
                ligne = ligne.substr(ligne.find(":") + 2);
                switch (typeArticle) {
                    case 0:
                        f = dynamic_cast<FauteuilRoulant*> (a);
                        switch (cpt) {

                            case 1:
                                a->setMarqueArticle(ligne);
                                break;

                            case 2:
                                a->setModeleArticle(ligne);
                                break;

                            case 3:a->setPrixJourArticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 4:
                                a->setNbStockarticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 5:
                                f->setLargeurAssise(strtod(ligne.c_str(), NULL));
                                break;

                            case 6:
                                f->setPoidsFauteuil(strtod(ligne.c_str(), NULL));
                                break;
                        }
                        if (cpt == 6)
                            this->listeArticle.push_front(f);
                        break;

                    case 1:
                        mr = dynamic_cast<MatelasAir*> (a);
                        switch (cpt) {
                            case 1: a->setMarqueArticle(ligne);
                                break;

                            case 2:
                                a->setModeleArticle(ligne);
                                break;

                            case 3:a->setPrixJourArticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 4:
                                a->setNbStockarticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 5:mr->setPoidsMaximumSupporte(strtod(ligne.c_str(), NULL));
                                break;

                            case 6:
                                mr->setDimensionMatelas(ligne);
                                break;

                            case 7:
                                mr->setTempsGonflage(strtod(ligne.c_str(), NULL));
                                break;
                        }
                        if (cpt == 7)
                            this->listeArticle.push_front(mr);
                        break;

                    case 2:
                        sm = dynamic_cast<SouleveMalade*> (a);
                        switch (cpt) {
                            case 1: a->setMarqueArticle(ligne);
                                break;

                            case 2:
                                a->setModeleArticle(ligne);
                                break;

                            case 3:a->setPrixJourArticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 4:
                                a->setNbStockarticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 5:
                                sm->setCapaciteLevage(strtod(ligne.c_str(), NULL));
                                break;

                            case 6:
                                sm->setDegrePivotFleau(strtod(ligne.c_str(), NULL));
                                break;
                        }
                        if (cpt == 6)
                            this->listeArticle.push_front(sm);
                        break;

                    case 3:
                        ml = dynamic_cast<MaterielLit*> (a);
                        switch (cpt) {
                            case 1: a->setMarqueArticle(ligne);
                                break;

                            case 2:
                                a->setModeleArticle(ligne);
                                break;

                            case 3:a->setPrixJourArticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 4:
                                a->setNbStockarticle(strtod(ligne.c_str(), NULL));
                                break;

                            case 5:
                                ml->setDimensionLit(ligne);
                                break;

                            case 6:
                                ml->setPoidsMaxAdmissible(strtod(ligne.c_str(), NULL));
                                break;

                            case 7:
                                if (ligne.find("cal") != ligne.npos)
                                    ml->setTypeMateriel(true);
                                else
                                    ml->setTypeMateriel(false);
                                break;
                        }
                        if (cpt == 7)
                            this->listeArticle.push_front(ml);
                        break;
                }
            }
            cpt++;
        }
        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Magasin::enregistrerClient() {
    string refClient;
    string adresseClient;
    string numeroTelephoneClient;
    int nbArticles;
    int i;
    string dateDebut;
    double montantFacture = 0;
    string refArticle;
    list <Article*> articlesLoues;
    list <Location*> locations;

    cout << "Enregistrer un nouveau client : \n";
    cout << "Référence du client: ";
    cin >> refClient;
    cin.ignore();

    cout << "Adresse du client: ";
    getline(cin, adresseClient);

    cout << "Numéro de téléphone du client: ";
    cin >> numeroTelephoneClient;

    cout << "Nouvelle(s) location(s): \n";
    cout << "Date de début de la location: ";
    cin >> dateDebut;

    cout << "Nombre d'articles : ";
    cin >> nbArticles;

    for (i = 0; i < nbArticles; i++) {
        cout << "Aricle " << i + 1 << ":" << endl;
        cout << "référence de l'articles : ";
        cin >> refArticle;
        for (list<Article*>::iterator it = this->listeArticle.begin(); it != this->listeArticle.end(); it++) {
            if ((*it)->getRefArticle() == refArticle) {
                (*it)->setNbStockarticle((*it)->getNbStockarticle() - 1);
                articlesLoues.push_front((*it));
            }
        }
    }
    locations.push_front(new Location(dateDebut, "NA", montantFacture, articlesLoues));
    this->listeClients.push_front(new Client(refClient, adresseClient, numeroTelephoneClient, locations));
}

void Magasin::enregistrerLocation() {
    string refClient;
    int nbArticles;
    int i;
    string dateDebut;
    double montantFacture = 0;
    string refArticle;
    list <Article*> articlesLoues;
    list <Location*> locations;
    cout << "référence du client? ";
    cin >> refClient;


    for (list<Client*>::iterator it = this->listeClients.begin(); it != this->listeClients.end(); it++) {
        if ((*it)->getRefClient() == refClient) {
            cout << "Nouvelle(s) location(s): \n";
            cout << "Date de début de la location: ";
            cin >> dateDebut;

            cout << "Nombre d'articles : ";
            cin >> nbArticles;

            for (i = 0; i < nbArticles; i++) {
                cout << "Aricle " << i + 1 << ":" << endl;
                cout << "référence de l'articles : ";
                cin >> refArticle;
                for (list<Article*>::iterator ite = this->listeArticle.begin(); ite != this->listeArticle.end(); ite++) {
                    if ((*ite)->getRefArticle() == refArticle) {
                        (*ite)->setNbStockarticle((*ite)->getNbStockarticle() - 1);
                        articlesLoues.push_front((*ite));
                    }
                }
            }
            locations = (*it)->getLocations();
            locations.push_front(new Location(dateDebut, "NA", montantFacture, articlesLoues));
            (*it)->setLocations(locations);
        }
    }
}

void Magasin::afficherClient() {
    string refClient;
    cout << "ref client? ";
    cin >> refClient;
    for (list<Client*>::iterator it = this->listeClients.begin(); it != this->listeClients.end(); it++) {
        if ((*it)->getRefClient() == refClient) {
            (*it)->affiche();
        }
    }
}

void Magasin::rendreLocation() {
    string refClient;
    string dateLoc;
    string dateFin;
    Location* locaremove;
    cout << "référence du client? ";
    cin >> refClient;
    cout << "date de la location (jj/mm/aaaa)?";
    cin >> dateLoc;
    cout << "date de fin de la location (jj/mm/aaaa)?";
    cin >> dateFin;
    for (list<Client*>::iterator it = this->listeClients.begin(); it != this->listeClients.end(); it++) {
        Client* client = (*it);
        list <Location*> locations = client->getLocations();
        if (client->getRefClient() == refClient) {
            for (list<Location*>::iterator ite = locations.begin(); ite != locations.end(); ite++) {
                Location* location = (*ite);
                if (location->getDateDebut() == dateLoc) {
                    location->setDateFin(dateFin);
                    location->calculMontant();
                    list<Article*> article = location->getArticlesLouees();
                    for (list<Article*>::iterator itera = article.begin(); itera != article.end(); itera++) {
                        Article* article = (*itera);
                        article->setNbStockarticle(article->getNbStockarticle() + 1);
                    }
                    this->archiverLocation(location);
                    locaremove = location;
                } else {
                }

            }
            locations.remove(locaremove);
            (*it)->setLocations(locations);
        } else {
        }
    }
}

void Magasin::archiverLocation(Location * location) {
    string date = location->getDateDebut();
    string mois;
    string annee;
    mois = date.substr(date.find("/") + 1, +2);
    annee = date.substr(6);
    string nomfichier = annee + mois + ".loc";

    ofstream fichier(nomfichier.c_str(), ios::out | ios::app);

    if (fichier) {
        fichier << "location du " << location->getDateDebut() << " au " << location->getDateFin() << "\n";
        fichier << "montant : " << location->getMontantFacture() << "\n";
        fichier.close();
    } else
        cerr << "Erreur à l'ouverture !" << endl;
}

void Magasin::afficherRevenuPeriode() {
    string debut;
    string fin;
    string ligne;
    double total;
    string mois;
    string annee;
    int m;
    int a;
    cout << "début période? (aaaamm) ";
    cin >> debut;
    cout << "fin période? (aaaamm) ";
    cin >> fin;
    mois = debut.substr(4);
    m = strtod(mois.c_str(), NULL);
    annee = debut.substr(0, +4);
    a = strtod(annee.c_str(), NULL);


    while (debut != fin) {

        ifstream fichier((debut + ".loc").c_str(), ios::in);
        if (fichier) {
            while (getline(fichier, ligne)) {
                if (ligne.find("montant") != ligne.npos) {
                    ligne = ligne.substr(ligne.find(":") + 2);
                    total = total + strtod(ligne.c_str(), NULL);
                } else {
                }
            }
            fichier.close();
        }
        if (m > 0 && m < 10) {
            mois = "0" + to_string(m);
        } else {
            mois = to_string(m);
        }
        annee = to_string(a);
        debut.replace(0, debut.size(), annee + mois);
        if (m == 12) {
            a++;
            m = 0;
        }
        m++;
    }
    cout << "montant gagner sur cette période : " << total << "\n";
}

void Magasin::jeterArticle() {

}

Magasin::~Magasin() {
}

void Magasin::afficheListeLocations(Client client) {

}

void Magasin::calculMontantRecettes(string periode) {

}

void Magasin::restitutionArticle(Client client) {

}

void Magasin::setListeArticle(list<Article*> listeArticle) {

    this->listeArticle = listeArticle;
}

list<Article*> Magasin::getListeArticle() const {

    return listeArticle;
}

void Magasin::setListeClients(list<Client*> listeClients) {

    this->listeClients = listeClients;
}

list<Client*> Magasin::getListeClients() const {

    return listeClients;
}

void Magasin::afficheArticlesDisponibles() {

}


