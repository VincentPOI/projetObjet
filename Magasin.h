/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Magasin.h
 * Author: vincent
 *
 * Created on 25 novembre 2016, 14:19
 */

#ifndef MAGASIN_H
#define MAGASIN_H
#include <list>
#include "Article.h"
#include "Client.h"

class Magasin {
public:
    Magasin();
    Magasin(list<Article>,list<Client>);
    void afficheArticlesDisponibles();
    void afficheListeLocations(Client);
    void restitutionArticle(Client);
    void enregistrerLocation(Client);
    void calculMontantRecettes(string);
    virtual ~Magasin();
    void setListeArticle(list<Article> listeArticle);
    list<Article> getListeArticle() const;
    void setListeClients(list<Client> listeClients);
    list<Client> getListeClients() const;
private:
    list <Client> listeClients;
    list <Article> listeArticle;
};

#endif /* MAGASIN_H */

