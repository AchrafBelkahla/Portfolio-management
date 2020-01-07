#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;
Titre::Titre(){}
Titre::Titre(string s,int q)
{
    NomAction=s;
    quantite=q;
}
string Titre::getNomAction()const
{
    return NomAction;
}
int Titre::getQuantite()const
{
    return quantite;
}
void Titre::setNomaction(string ch)
{
    NomAction=ch;
}
void Titre::setquantite(int q)
{
    quantite=q;
}
ostream& operator<<(ostream& flux, const Titre& t )
{
    flux<<t.getNomAction()<<endl;
    flux<<t.getQuantite()<<endl;
    return flux ;
}
