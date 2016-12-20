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
        cout << "Reférence : REF, Marque : MAR, Modèle : MOD, Prix par jours : PR, Retour : R -> ";
        cin >> tri;

        if (tri == "R") {
            return;
        } else if (tri == "MAR") {
            listeArticle.sort(triMarque());
        } else if (tri == "MOD") {
            listeArticle.sort(triModele());
        } else if (tri == "PR") {
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
        string typeArticle;
        FauteuilRoulant fauteuil;
        MatelasAir matelasAir;
        MaterielLit matelatLit;
        while (getline(fichier, ligne)) {
            if (ligne.find("*") != ligne.npos) {
                ligne = ligne.substr(ligne.find(":") + 2);
                ligne = ligne.replace(ligne.end() - 16, ligne.end(), "");

                cout << ligne << endl;
            } else {
                ligne = ligne.substr(ligne.find(":") + 2);
                cout << ligne << endl;
            }
        }
        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Magasin::jeterArticle() {

}

Magasin::~Magasin() {
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
    cout << "Référence du client: " << endl;
    cin >> refClient;
    cout << "Adresse du client: " << endl;
    cin >> adresseClient;
    cout << "Numéro de téléphone du client: " << endl;
    cin >> numeroTelephoneClient;
    cout << "Nouvelle(s) location(s): " << endl;
    cout << "Nombre de locations :" << endl;
    cin >> nbLocationClient;

    for (i = 0; i < nbLocationClient; i++) {
        cout<<"Location "<<i+1<<":"<<endl;
        cout<<"Date de début de la location:"<<endl;
        cin>>dateDebut;
        typeArticle="NA";
        cout << "Article(s) loué(s): " << endl;
        while (typeArticle.compare("R") != 0) {
            typeArticle="NA";
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
        locations.push_front(new Location(dateDebut, "NA", montantFacture, articlesLoues));
    }

    this->listeClients.push_front(new Client(refClient, adresseClient, numeroTelephoneClient, locations));

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


