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
    
}

Article::Article(string refArticle, string marqueArticle, string modeleArticle, double prixJourArticle, int nbStockarticle) {

}

Article::~Article() {
}

int Article::affiche() {

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

