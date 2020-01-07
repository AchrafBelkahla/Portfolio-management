#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;
PrixJournalier::PrixJournalier(){}
PrixJournalier::PrixJournalier(string ch1,string ch2,double p)
{
    nom=ch1;
    date=ch2;
    prix=p;
}
PrixJournalier::~PrixJournalier(){}
string PrixJournalier::getNomAction()const
{
    return nom;
}
string PrixJournalier::getDate()const
{
    return date;
}
double PrixJournalier::getPrix()const
{
    return prix;
}
void PrixJournalier::setNomAction(string ch)
{
    nom=ch;
}
void PrixJournalier::setDate(string d)
{
    date=d;
}
void PrixJournalier::setPrix(double p)
{
    prix=p;
}
ostream& operator<<(ostream& a,PrixJournalier& d)
 {
    a<<d.nom<<endl<<d.prix<<endl<<d.date<<endl;
     return a;
 }

