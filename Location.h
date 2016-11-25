/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Location.h
 * Author: hadrien
 *
 * Created on 25 novembre 2016, 14:39
 */

#ifndef LOCATION_H
#define LOCATION_H
#include "Article.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;


class Location {
public:
    Location();
    Location(string, double);
    virtual ~Location();
    double calculMontant();
    void affiche();
    void setDateDebut(string dateDebut);
    string getDateDebut();
    void setMontantFacture(double montantFacture);
    double getMontantFacture();
    void setListeArticle(list<Article> listeArticle);
    list<Article> getListeArticle();
    void ajoutArticle(const Article &a);
    void afficheListeArticle();
private:
    string dateDebut;
    double montantFacture;
    list<Article> listeArticle;
};

#endif /* LOCATION_H */

