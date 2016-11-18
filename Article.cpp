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
    this->prixJourArticle = NULL;
    this->nbStockarticle = 0;
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

int Article::affiche() {
    cout<<"Reference de l'article : "<<this->refArticle<<endl;
    cout<<"Marque de l'article : "<<this->marqueArticle<<endl;
    cout<<"Modele de l'article : "<<this->modeleArticle<<endl;
    cout<<"Prix par jour de l'article : "<<this->prixJourArticle<<endl;
    cout<<"Nombre d'article en stock : "<<this->nbStockarticle<<endl;
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

