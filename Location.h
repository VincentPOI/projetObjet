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
#include <string>
#include <list>
#include <iostream>
#include "Article.h"
using namespace std;


class Location {
public:
    Location();
    Location(string, double, bool, list<Article*>);
    virtual ~Location();
    double calculMontant();
    void affiche();
    void setDateDebut(string dateDebut);
    string getDateDebut();
    void setEnCours(bool enCours);
    bool getEnCours();
    void setMontantFacture(double montantFacture);
    double getMontantFacture();
    void setArticlesLouees(list<Article*> articlesLouees);
    list<Article*> getArticlesLouees() const;
private:
    string dateDebut;
    bool enCours;
    double montantFacture;
    list <Article*> articlesLoues;
};

#endif /* LOCATION_H */

