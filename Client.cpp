/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Client.cpp
 * Author: hadrien
 * 
 * Created on 25 novembre 2016, 14:14
 */

#include "Client.h"

Client::Client() {
    this->refClient = "NA";
    this->adresseClient = "NA";
    this->numeroTelephoneClient = "NA";
}

Client::Client(string refClient, string adresseClient, string numeroTelephoneClient, list<Location*> locations) {
    this->refClient = refClient;
    this->adresseClient = adresseClient;
    this->numeroTelephoneClient = numeroTelephoneClient;
    this->locations=locations;
}

void Client::affiche() {
    cout << "Référence client: " << this->refClient << endl;
    cout << "Adresse du client: " << this->adresseClient << endl;
    cout << "Numéro de téléphone du client: " << this->numeroTelephoneClient << endl;
}

void Client::setRefClient(string refClient){
    this->refClient=refClient;
}

string Client::getRefClient(){
    return this->refClient;
}

void Client::setAdresseClient(string adresseClient){
    this->adresseClient=adresseClient;
}

string Client::getAdresseClient(){
    return adresseClient;
}

void Client::setNumeroTelephoneClient(string numeroTelephoneClient){
    this->numeroTelephoneClient=numeroTelephoneClient;
}

string Client::getNumeroTelephoneClient(){
    return this->numeroTelephoneClient;
}

void Client::setLocations(list<Location*> locations) {
    this->locations = locations;
}

list<Location*> Client::getLocations() const {
    return locations;
}

Client::~Client() {
}

