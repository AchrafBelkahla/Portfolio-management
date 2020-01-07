#include <iostream>
#include <string>
#include"head.h"
#include <fstream>
using namespace std;



Administrateur::Administrateur(string mail,string m,Bourse& bourse_origine):b(&bourse_origine)
{
    login=mail;
    mdp=m;
}

void Administrateur::AjouterClient(Client c)
{
    liste_client.push_back(c);
}
int Administrateur::rechercher_client_humain(string ch)
{
    int a =liste_client.size();
 for(int i=0;i<a;i++)
 {
     if(ch==liste_client[i].getlogin())
        return i;
 }
 return -1;
}
void Administrateur::SupprimerClient(int pos)
{
    liste_client.erase(liste_client.begin()+pos);
}
void Administrateur::AjouterPrixJournalier(PrixJournalier p)
{
    b->TabPJ.push_back(p);
}
int Administrateur::RechercherPrixActionJour(PrixJournalier p)
{
    int a=b->TabPJ.size();
    for(int i=0;i<a;i++)
       {
           if((p.nom==b->TabPJ[i].nom)&&(p.date==b->TabPJ[i].date))
            return  i;}
    return -1;
}
void Administrateur::SupprimerPrixJournalier(PrixJournalier p)
{
    int pos=RechercherPrixActionJour(p);
    b->TabPJ.erase(b->TabPJ.begin()+pos);
}
void Administrateur:: AcheterAction (PrixJournalier p, int quantite , vector<PrixJournalier> PJ, Client& c  )
{
    double prix ;
    prix=b->TabPJ[RechercherPrixActionJour(p)].prix;
    if (prix==-1){cout<< "cette action n'esxite pas "<<endl;}
    if (quantite * prix <= c.getSolde())
      {
       c.AjouterTitre(p.nom,quantite);
        double x = c.getSolde()-(quantite * prix) ;
       c.setSolde(x);
       cout<<"achat avec succés"<<endl;
       }
   else
       {
           cout<<"Votre solde n'est pas suffisant  "<<endl;
       }
}
void Administrateur::VendreAction(PrixJournalier p, int quantite ,vector<PrixJournalier> PJ, Client& c  )

       {

         cout<<"vente temchi"<<endl;
         double prix,x;
            prix=b->TabPJ[RechercherPrixActionJour(p)].prix;
             x=c.getSolde()+ quantite * prix ;

    if (quantite  < c.TabTitre[p.nom].getQuantite())
     {
           int y= c.TabTitre[p.nom].getQuantite()- quantite ;
           c.TabTitre[p.nom].setquantite(y);
            c.setSolde(x);
            cout<<"quantite vendue"<<endl;

     }
    else if (quantite==c.TabTitre[p.nom].getQuantite())
        {
            c.SupprimerAction(p.nom);
            c.setSolde(x);
            cout<<"action vendue"<<endl;

        }
    else

            {
              cout<<"d%csol%c , la quantit%c que vous voulez vendre est sup%crieur %c celle que vous poc%cder dans votre compte\n voulez-vous vendre la totalit%c de la quantit%c que vous avez ? "<< endl;

            }

       }

void Administrateur::TraiterAction(Client &c)
{

       PrixJournalier p(c.tr[c.tr.size()-1].getNomAction(),c.tr[c.tr.size()-1].getdate(),0);
       int q=c.tr[c.tr.size()-1].getQuantite();
    if(c.tr[c.tr.size()-1].gettypeAction()=="Achat")
    {
        AcheterAction(p,q,b->TabPJ,c);
    }
    else if(c.tr[c.tr.size()-1].gettypeAction()=="Vente")
    {
        cout<<"test mriguil"<<endl;
        VendreAction(p,q,b->TabPJ,c);
    }

}
string Administrateur::getlogin()const
{
    return login;
}
string Administrateur::getmdp()const
{
    return mdp;
}
void Administrateur::consulterclients()const
{
    for(int i=0;i<liste_client.size()-1;i++)
        cout<<liste_client[i];
}
