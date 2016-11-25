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
private:
    string dateDebut;
    double montantFacture;
};

#endif /* LOCATION_H */

