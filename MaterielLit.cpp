/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaterielLit.cpp
 * Author: vincent
 * 
 * Created on 18 novembre 2016, 13:52
 */

#include "MaterielLit.h"

MaterielLit::MaterielLit() : Article() {
    this->dimensionLit = "NA";
    this->poidsMaxAdmissible = 0;
    this->typeMateriel = "NA";
}

void MaterielLit::affiche(ostream& ostr) {
    Article::affiche(ostr);
    ostr << "Dimension du matériel : " << this->dimensionLit << "\n";
    ostr << "Poids maximum du materiel : " << this->poidsMaxAdmissible << "\n";
    if (this->typeMateriel) {
        ostr << "Type de matériel : Lit médicalisé" << "\n";
    } else {
        ostr << "Type de matériel : Lit d'alité" << "\n";
    }
}

MaterielLit::MaterielLit(string refArticle, string marqueArticle, string modeleArticle, double prixJourArticle, int nbStockarticle, double poidsMaxAdmissible, string dimensionLit, bool typeMateriel) : Article(refArticle, marqueArticle, modeleArticle, prixJourArticle, nbStockarticle) {
    this->dimensionLit = dimensionLit;
    this->poidsMaxAdmissible = poidsMaxAdmissible;
    this->typeMateriel = typeMateriel;
}

MaterielLit::~MaterielLit() {
}

void MaterielLit::setDimensionLit(string dimensionLit) {
    this->dimensionLit = dimensionLit;
}

string MaterielLit::getDimensionLit() const {
    return dimensionLit;
}

void MaterielLit::setPoidsMaxAdmissible(double poidsMaxAdmissible) {
    this->poidsMaxAdmissible = poidsMaxAdmissible;
}

double MaterielLit::getPoidsMaxAdmissible() const {
    return poidsMaxAdmissible;
}

void MaterielLit::setTypeMateriel(bool typeMateriel) {
    this->typeMateriel = typeMateriel;
}

bool MaterielLit::isTypeMateriel() const {
    return typeMateriel;
}

