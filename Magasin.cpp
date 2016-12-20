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

                            case 5:
                                mr->setDimensionMatelas(ligne);
                                break;

                            case 6:
                                mr->setPoidsMaximumSupporte(strtod(ligne.c_str(), NULL));
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
    int nbLocationClient;
    int i;
    string dateDebut;
    bool enCours = true;
    double montantFacture = 0;
    string typeArticle;
    string refArticle;
    string marqueArticle;
    string modeleArticle;
    double prixJourArticle;
    int nbStockArticle;
    list <Article*> articlesLoues;
    list <Location*> locations;

    cout << "Enregistrer un nouveau client :" << endl;
    cout << "Référence du client: ";
    cin >> refClient;
    cout << "Adresse du client: ";
    cin >> adresseClient;
    cout << "Numéro de téléphone du client: ";
    cin >> numeroTelephoneClient;
    cout << "Nouvelle(s) location(s): " << endl;
    cout << "Nombre de locations : ";
    cin >> nbLocationClient;

    for (i = 0; i < nbLocationClient; i++) {
        cout << "Location " << i + 1 << ":" << endl;
        cout << "Date de début de la location:" << endl;
        cin>>dateDebut;
        typeArticle = "NA";
        cout << "Article(s) loué(s): " << endl;
        while (typeArticle.compare("R") != 0) {
            typeArticle = "NA";
            while (typeArticle.compare("FR") != 0 && typeArticle.compare("MR") != 0 && typeArticle.compare("SM") != 0 && typeArticle.compare("ML") != 0 && typeArticle.compare("R") != 0) {
                cout << "type d'article?(Fauteuil roulant : FR, Matelas air : MR, Souleve Malade : SM, Materiel lit : ML, retour:R)-> ";
                cin >> typeArticle;
            }

            if (typeArticle == "R") {
                break;
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
                articlesLoues.push_front(new FauteuilRoulant(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, largeur, poids));
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
                articlesLoues.push_front(new MatelasAir(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, pmax, dimension, tpsgonfl));
            } else if (typeArticle == "SM") {
                int caplevage;
                int degrepivot;
                cout << "capacité de levage?";
                cin >> caplevage;
                cout << "degre pivot fleau?";
                cin >> degrepivot;
                articlesLoues.push_front(new SouleveMalade(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, caplevage, degrepivot));
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
                articlesLoues.push_front(new MaterielLit(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockArticle, pmax, dimension, typemat));
            }
        }
        locations.push_front(new Location(dateDebut, enCours, montantFacture, articlesLoues));
    }
    this->listeClients.push_front(new Client(refClient, adresseClient, numeroTelephoneClient, locations));

}

void Magasin::afficherClient(string refClient) {

    for (list<Client*>::iterator it = this->listeClients.begin(); it != this->listeClients.end(); it++) {
        if ((*it)->getRefClient() == refClient) {
            cout << "client n°" << (*it)->getRefClient() << " : \n";
            (*it)->affiche();
        }
    }
}

void Magasin::rendreArticle() {
    string refClient;
    string dateLoc;
    cout << "référence du client? ";
    cin >> refClient;
    cout << "date de la location (jj/mm/aaaa)?";
    cin >> dateLoc;
    for (list<Client*>::iterator it = this->listeClients.begin(); it != this->listeClients.end(); it++) {
        if ((*it)->getRefClient() == refClient) {
            for (list<Location*>::iterator ite = (*it)->getLocations().begin(); ite != (*it)->getLocations().end(); it++) {
                if ((*ite)->getDateDebut() == dateLoc) {
                    (*it)->getLocations().remove((*ite));
                }
            }
        }
    }
}

void Magasin::jeterArticle() {

}

Magasin::~Magasin() {
}

void Magasin::afficheListeLocations(Client client) {

}

void Magasin::calculMontantRecettes(string periode) {

}

void Magasin::enregistrerLocation(Client client) {

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


