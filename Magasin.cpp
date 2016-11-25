/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Magasin.cpp
 * Author: vincent
 * 
 * Created on 25 novembre 2016, 14:19
 */

#include "Magasin.h"

Magasin::Magasin() {
    this->listeArticle=NULL;
    this->listeClients=NULL;
}

Magasin::Magasin(list<Article> listeArticle, list<Client> listeClients) {
    this->listeArticle=listeArticle;
    this->listeClients=listeClients;
}


Magasin::Magasin(const Magasin& orig) {
}

Magasin::~Magasin() {
}

void Magasin::setListeArticle(list<Article> listeArticle) {
    this->listeArticle = listeArticle;
}

list<Article> Magasin::getListeArticle() const {
    return listeArticle;
}

void Magasin::setListeClients(list<Client> listeClients) {
    this->listeClients = listeClients;
}

list<Client> Magasin::getListeClients() const {
    return listeClients;
}

void Magasin::afficheArticlesDisponibles() {

}

void Magasin::afficheListeLocations(Client client) {

}

void Magasin::calculMontantRecettes(string periode) {

}

void Magasin::enregistrerLocation(Client client) {

}

void Magasin::restitutionArticle(Client client) {

}

void Magasin::setListeArticle(list<Article> listeArticle) {
    this->listeArticle = listeArticle;
}

list<Article> Magasin::getListeArticle() const {
    return listeArticle;
}

void Magasin::setListeClients(list<Client> listeClients) {
    this->listeClients = listeClients;
}

list<Client> Magasin::getListeClients() const {
    return listeClients;
}

