#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;
Bourse::Bourse(string Nom)
{
    nom=Nom;
}
Bourse::~Bourse(){}
string Bourse::getNom_bourse()const
{
    return nom;
}
void Bourse::setNom_bourse(string ch)
{
    nom=ch;
}
