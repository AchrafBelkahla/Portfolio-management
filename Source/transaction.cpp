#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;
Transaction::Transaction(){};
Transaction::Transaction(string n, string t, int q)
{
    NomAction=n;
    quantite=q;
    typeAction=t;
}
int Transaction::getQuantite() const{
return quantite;}
string Transaction::getNomAction() const
{
return NomAction;}
string Transaction::getdate() const
{
return date;}
string Transaction::gettypeAction()const{
return typeAction;}
void Transaction::setNomAction(string nom)
{
    NomAction=nom;
}
void Transaction::setDateAction(string d)
{
    date=d;
}
void Transaction::setquantite(int q)
{
    quantite=q;
}
void Transaction::setTypeAction(string t)
{
    typeAction=t;
}
ostream& operator<< (ostream& flux, Transaction& t)
{
    flux<<t.getNomAction()<<endl;
    flux<<t.getQuantite()<<endl;
    flux<<t.gettypeAction()<<endl;
    return flux;
}
