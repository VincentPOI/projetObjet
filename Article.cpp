/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Article.cpp
 * Author: vincent
 * 
 * Created on 18 novembre 2016, 13:00
 */

#include "Article.h"

Article::Article() {
    this->refArticle = "NA";
    this->marqueArticle = "NA";
    this->modeleArticle = "NA";
    this->prixJourArticle = 0;
    this->nbStockarticle = 0;
}

void Article::affiche(ostream& ostr) {
    ostr << "************** Article : " << this->refArticle << " ***************" << endl;
    ostr << "Marque de l'article : " << this->marqueArticle << "\n";
    ostr << "Modele de l'article : " << this->modeleArticle << "\n";
    ostr << "Prix par jour de l'article : " << this->prixJourArticle << "\n";
    ostr << "Nombre d'article en stock : " << this->nbStockarticle << "\n";
}

Article::Article(string refArticle, string marqueArticle, string modeleArticle, double prixJourArticle, int nbStockarticle) {
    this->refArticle = refArticle;
    this->marqueArticle = marqueArticle;
    this->modeleArticle = modeleArticle;
    this->prixJourArticle = prixJourArticle;
    this->nbStockarticle = nbStockarticle;
}

Article::~Article() {
}

bool Article::operator<(const Article& v) {
    return this->refArticle < v.refArticle;
}

void Article::setNbStockarticle(int nbStockarticle) {
    this->nbStockarticle = nbStockarticle;
}

int Article::getNbStockarticle() const {
    return nbStockarticle;
}

void Article::setPrixJourArticle(double prixJourArticle) {
    this->prixJourArticle = prixJourArticle;
}

double Article::getPrixJourArticle() const {
    return prixJourArticle;
}

void Article::setModeleArticle(string modeleArticle) {
    this->modeleArticle = modeleArticle;
}

string Article::getModeleArticle() const {
    return modeleArticle;
}

void Article::setMarqueArticle(string marqueArticle) {
    this->marqueArticle = marqueArticle;
}

string Article::getMarqueArticle() const {
    return marqueArticle;
}

void Article::setRefArticle(string refArticle) {
    this->refArticle = refArticle;
}

string Article::getRefArticle() const {
    return refArticle;
}

