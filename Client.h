/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.h
 * Author: hadrien
 *
 * Created on 25 novembre 2016, 14:14
 */

#ifndef CLIENT_H
#define CLIENT_H
#include "Location.h"
#include <list>
#include <iostream>
#include <string>
using namespace std;

class Client {
public:
    Client();
    Client(string, string, string, list<Location>);
    void affiche();
    virtual ~Client();
    void setRefClient(string refClient);
    string getRefClient();
    void setAdresseClient(string adresseClient);
    string getAdresseClient();
    void setNumeroTelephoneClient(string numeroTelephoneClient);
    string getNumeroTelephoneClient();
    void setListeLocation(list<Location>);
    list<Location> getListeLocation();
private:
    string refClient;
    string adresseClient;
    string numeroTelephoneClient;
    list<Location> listeLocaiton;
};

#endif /* CLIENT_H */

