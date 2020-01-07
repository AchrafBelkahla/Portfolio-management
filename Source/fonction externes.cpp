#include <iostream>
#include <fstream>
#include"head.h"
using namespace std;

Client saisir_nouveau_compte()
{
string Nom,prenom,login,MDP; int cn;
  cout<<"veuillez introduire votre NOM s'il vous plait:"<<endl;
  cin>>Nom;
cout<<"veuillez introduire votre PRENOM s'il vous plait"<<endl;
  cin>>prenom;
  cout<<"veuillez introduire votre CIN s'il vous plait"<<endl;
  cin>>cn;
  cout<<"veuillez choisir un login s'il vous plait:"<<endl;
 cin>>login;
cout<<"veuillez introduire votre MOT DE PASSE s'il vous plait:"<<endl;
cin>>MDP;
  Client c(Nom,prenom,cn,login,MDP,0);
 return c ;
}

void  identifier(string &login,string &MDP)
{
    cout<<"entrez votre login:"<<endl;
    cin>>login;
    cout<<"entrez votre mot de passe:"<<endl ;
    cin>>MDP;
}
PrixJournalier saisir_prixjournalier()
{string Nom,date; double prix;
    cout<<"veuillez introduire le nom d'action s'il vous plait:"<<endl;
    cin>>Nom;
    cout<<"veuillez introduire la date s'il vous plait"<<endl;
    cin>>date;
    cout<<"veuillez introduire le prix s'il vous plait"<<endl;
    cin>>prix;
    PrixJournalier p(Nom,date,prix);
    return p;
}
void lire_fichier_clients(vector<Client> &T)
{
    string ch,nom;
    double sd;
    int nbt,quant;
    Titre e;
Client p;
    ifstream fi("listeclients.txt");
    while(!fi.eof())
    {

        fi >>ch;
        p.setNom(ch);
        fi >>p.prenom;

        fi >>p.CIN;
        fi >>sd;
        p.setSolde(sd);
        fi >>p.login;
        fi >>p.MDP;
        fi>>nbt;
        if(nbt!=0)
        {
        for(int i=0;i<nbt;i++)
        {
            fi>>nom;
            e.setNomaction(nom);
            fi>>quant;
            e.setquantite(quant);
            p.TabTitre[nom]=e;
        }}
        T.push_back(p);


    }
    fi.close();
}
void ecrire_fichier_clients(vector<Client> T)
{
    ofstream fo("listeclients.txt");
    if (fo.is_open()){
            for(int i=0;i<T.size()-1;i++)
            {
                fo<<T[i].getNom()<<"\t";
                fo<<T[i].getPrenom()<<"\t";
                fo<<T[i].getCIN()<<"\t";
                fo<<T[i].getSolde()<<"\t";
                fo<<T[i].getlogin()<<"\t";
                fo<<T[i].getMDP()<<"\t";
               int s=0;
                map<string,Titre>&m= T[i].TabTitre;
                fo<<s<<"\t";
                if(s!=0)
                {
                    map<string, Titre>::iterator i = m.begin();
                    while (i != m.end())
                        {
                    fo<<i->first<<"\t";
                    fo<<i->second.getQuantite()<<"\t";
                    ++i;
                    }}
    fo<<endl;
            }
        fo.close();
    }
}
void lire_fichier_prixj(vector<PrixJournalier> &T)
{   PrixJournalier p;
string ch1,ch2;
double s;
    ifstream fi("listeaction.txt");
    while(!fi.eof())
    {
        fi>>ch2;
        fi>>ch1;
        fi>>s;
        p.setNomAction(ch1);
        p.setDate(ch2);
        p.setPrix(s);
        T.push_back(p);
    }
    fi.close();
}
void ecrire_fichier_prixj(vector<PrixJournalier> T)
{
    ofstream fo("listeaction.txt");
    if (fo.is_open()){
            for(int i=0;i<T.size()-1;i++)
            {
                fo<<T[i].getDate()<<"\t";
                fo<<T[i].getNomAction()<<"\t";
                fo<<T[i].getPrix()<<"\t";
                fo<<endl;}
                fo.close();
}}
