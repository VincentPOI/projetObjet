/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Article.h
 * Author: vincent
 *
 * Created on 18 novembre 2016, 13:00
 */

#ifndef ARTICLE_H
#define ARTICLE_H
#include<iostream>
#include <string>
using namespace std;

class Article {
public:
    Article();
    Article(string refArticle, string marqueArticle, string modeleArticle, double prixJourArticle, int nbStockarticle);

    virtual void affiche() {
        cout << "************** Article : " << this->refArticle << " ***************" << endl;
        cout << "Marque de l'article : " << this->marqueArticle << endl;
        cout << "Modele de l'article : " << this->modeleArticle << endl;
        cout << "Prix par jour de l'article : " << this->prixJourArticle << endl;
        cout << "Nombre d'article en stock : " << this->nbStockarticle << endl;
    };
    virtual ~Article();
    void setNbStockarticle(int nbStockarticle);
    int getNbStockarticle() const;
    void setPrixJourArticle(double prixJourArticle);
    double getPrixJourArticle() const;
    void setModeleArticle(string modeleArticle);
    string getModeleArticle() const;
    void setMarqueArticle(string marqueArticle);
    string getMarqueArticle() const;
    void setRefArticle(string refArticle);
    string getRefArticle() const;
protected:
    string refArticle;
    string marqueArticle;
    string modeleArticle;
    double prixJourArticle;
    int nbStockarticle;
};

#endif /* ARTICLE_H */

