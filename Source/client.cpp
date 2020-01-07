#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;
string Client::getNom()const
{
    return Nom;
}
double Client::getSolde()const
{
return Solde;}
void Client::AjouterTitre(string n, int q )
{
    Titre t;
    t.setNomaction(n);

    map<string,Titre>::iterator it;
    it=TabTitre.find(n);
     if (it != TabTitre.end())
           q += TabTitre[n].getQuantite() ;
   t.setquantite(q);
 TabTitre[n]= t;
}
void Client ::SupprimerAction(string nomAct)
{
     std::map<string,Titre> ::iterator it;
    it = TabTitre.find(nomAct);
    TabTitre.erase(it);
}
Client::Client(){}
void Client :: setSolde (double s)
{
    Solde = s;
}
void Client::setNom(string m)
{
    Nom=m;
}
Client::Client(string n,string p,int a,string e,string m,double pr)
{
Nom=n;
Solde=pr;
 prenom=p;
 CIN=a;
 login=e;
 MDP=m;
 tr.resize(1);
}
int Client::getCIN () const
{
    return CIN;
}
string Client::getPrenom() const{
return prenom;
}
string Client::getlogin() const{
return login;}
string Client::getMDP() const{
return MDP;}
void Client::setMDP(string ch)
{
    MDP=ch;
}
void  Client::ChoisirTransaction_manuelle()
{
    Transaction t; string x; int q, ty;
   cout<<"entrez le nom d'action"<<endl;
    cin>>x;
    t.setNomAction(x);
    //cout<<"entrez la date d'action"<<endl;
    //cin>>x;

    cout<<"entrez la quantite"<<endl;
    cin>>q;
    t.setquantite(q);
    cout<<"voulez vous vendre ou achetter cette action ?"<<endl;
    cout<<"1.Acheter"<<endl<<"2.Vendre"<<endl;
    cin>>ty;
    if(ty==1)
        t.setTypeAction("Achat");
    else
        t.setTypeAction("Vente");
    tr.push_back(t);
}
void Client::consulter_transaction()
{
    for(int i=0;i<tr.size();i++)
        cout<<tr[i];
}
void Client::deposerArgent(double argent)
{
  Solde=Solde+argent;
}
void Client::retirerArgent(double argent)
{
    Solde=Solde-argent;
}
void Client::ConsulterCompte()
{
    cout<<"solde ="<< Solde<<endl;
    cout<<" nombre de titre= "<< TabTitre.size()<<endl;
    if(TabTitre.size()!=0)
    cout<<"vos titres sont : "<<endl;
map<string,Titre> :: iterator i = TabTitre.begin();
    while (i != TabTitre.end()){
        cout << i->second<<" ";
        ++i;
    }
    cout << endl;
}
void Client::ConsulterHistorique(Bourse &b)
{ int n=b.TabPJ.size();
     for(int i=0;i<468;i++){
        cout<< b.TabPJ[i]<<endl;}
}

void Client::Choisir_alea(const Bourse& B)
 {
     Transaction t;
     PrixJournalier PJ;
     string ch,nomp;
     double prob;srand(time(NULL));
     int deb1 =0,fin1=468;
      while ( fin1<=4212)
     {
      for (int j =deb1 ; j<fin1; j++)
     { prob=rand()/(double)RAND_MAX;
       PJ= B.TabPJ[j];
       if((prob<0.5)&&(getSolde()>PJ.getPrix()) )
            {
                AjouterTitre(PJ.getNomAction(),1);
               double  x= getSolde() - PJ.getPrix();
                setSolde(x);
                ch="Achat";
                nomp=PJ.getNomAction();
                Transaction t(nomp,ch,1);
                tr.push_back(t);
            }
        else
        {
           std::map<string,Titre> ::iterator it;
          it = TabTitre.find(PJ.getNomAction());
if ((it !=TabTitre.end())&&(prob>=0.5)&&(prob<0.8) &&(TabTitre[PJ.getNomAction()].getQuantite()>0))
        {

    double  x=getSolde()+ PJ.getPrix()*TabTitre[PJ.getNomAction()].getQuantite();
    setSolde(x);
    SupprimerAction(PJ.getNomAction());
    ch="Vente";
                nomp=PJ.getNomAction();
                Transaction t(nomp,ch,1);
                tr.push_back(t);
    }
    else{
        break;}
    }
    }
       deb1+=468;
       fin1+=468;
     }




  std::map<string,Titre> ::iterator it;

      for( it=TabTitre.begin(); it!=TabTitre.end(); ++it)
        {
                int k=3745;
            while(k<=4212)
       {




         if(B.TabPJ[k].getNomAction()== it->first)
        {
          double  x=getSolde()+ B.TabPJ[k].getPrix()*TabTitre[it->first].getQuantite();
          setSolde(x);
          SupprimerAction(it->first);
          }
             k++;
          }

          }



 }
void Client::Choisir_comparaison(const Bourse& B)
 {

     PrixJournalier PJ;

     int deb1 =0,fin1=468;
      while ( fin1<=4212)
     {
      for (int j = deb1 ; j<fin1; j++)
       {PJ= B.TabPJ[j] ;
       if((PJ.getPrix()<B.TabPJ[j-468].getPrix())&&(getSolde()>PJ.getPrix()) )
            {
                AjouterTitre(PJ.getNomAction(),1);
               double  x= getSolde() - PJ.getPrix();                         //achat des actions
                setSolde(x);
            }
        else
        {
           std::map<string,Titre> ::iterator it;
          it = TabTitre.find(PJ.getNomAction());
if ((it !=TabTitre.end())&&(PJ.getPrix()>=B.TabPJ[j-468].getPrix() ) &&(TabTitre[PJ.getNomAction()].getQuantite()>0))
        {

    double  x=getSolde()+ PJ.getPrix()*TabTitre[PJ.getNomAction()].getQuantite();
    setSolde(x);
    SupprimerAction(PJ.getNomAction());                       //vente des actions
    }}
    }

  std::map<string,Titre> ::iterator it;

    deb1+=468;
       fin1+=468;
     }

  std::map<string,Titre> ::iterator it;

      for( it=TabTitre.begin(); it!=TabTitre.end(); ++it)
        {
                int k=3745;
            while(k<=4212)
       {



         if(B.TabPJ[k].getNomAction()== it->first)
        {
          double  x=getSolde()+ B.TabPJ[k].getPrix()*TabTitre[it->first].getQuantite();
          setSolde(x);
          SupprimerAction(it->first);             //vente de tous les titres pour savoir le résultat


          }
             k++;
          }

          }
 }
 void Client::Choisir_VWAP(const Bourse& B)
 {  vector<double> Pri;
     PrixJournalier PJ;
     double vwap,pv;
     int deb=468,sq, fin=936;
     while ( fin<=1872)
     {
      for (int j =deb ; j<fin; j++)
     {
       PJ= B.TabPJ[j] ;
       if((PJ.getPrix()<B.TabPJ[j-468].getPrix())&&(getSolde()>PJ.getPrix()) )
            {  //int a=getSolde()/PJ.getPrix();
               // int q=rand()%(a-1)+1;
                AjouterTitre(PJ.getNomAction(),1);
               double  x= getSolde() - (1*PJ.getPrix());
               Pri.push_back(PJ.getPrix());
                setSolde(x);
            }
    }
    fin+=468;
    deb=468;
     }
//calcul de VWAP
map<string,Titre> :: iterator it = TabTitre.begin();
int p=0;
      for( it=TabTitre.begin(); it!=TabTitre.end(); it++)
        {
          pv+=Pri[p];
            //sq+=TabTitre[it->first].getQuantite();
            sq+=1;
            p++;
          }


vwap=pv/sq;
//traitement apres VWAP
int f=2340, d=1872;
 while ( f<4212)
 {
    for (int j =d ; j<f; j++)
{   PJ= B.TabPJ[j] ;
    if((PJ.getPrix()<vwap)&&(Solde>PJ.getPrix()))
    {
        AjouterTitre(PJ.getNomAction(),1);
               double  x= getSolde() - PJ.getPrix();
                setSolde(x);
    }
}
f+=468;
d+468;
 }
//vente des actions


      for( it=TabTitre.begin(); it!=TabTitre.end(); ++it)
        {
            //cout<<it->second;
                int k=3745;
            while(k<=4212)
       {
         if(B.TabPJ[k].getNomAction()== it->first)
        {
          double  x=getSolde()+ B.TabPJ[k].getPrix()*TabTitre[it->first].getQuantite();
          setSolde(x);
          SupprimerAction(it->first);
          }
             k++;
          }

          }
 }



void Client::affichage_resultat(double s)
{
    cout<<"Solde initial= "<<s<<endl;
    cout<<"Solde final= "<<Solde<<endl;
}
ostream& operator <<(ostream& flux, const Client& a)
{   cout<<"Nom : ";
    flux<<a.getNom()<<endl;
    cout<<"Prenom : ";
    flux<<a.getPrenom()<<endl;
    cout<<"CIN : ";
    flux<<a.getCIN()<<endl;
    cout<<"login : ";
    flux <<a.getlogin()<<endl;
    cout<<"MDP : ";
    flux <<a.getMDP()<<endl;
    cout<<"Solde : ";
    flux<<a.getSolde()<<endl;
    return flux;
}
