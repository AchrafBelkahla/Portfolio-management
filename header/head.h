#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include<string>
#include<vector>
#include<map>
#include <fstream>
#include<cstdlib>
#include"time.h"


using namespace std ;
class PrixJournalier{
    public :
    string nom;
    string date;
    double prix;
public:
    PrixJournalier();
    PrixJournalier(string ,string , double);
    ~PrixJournalier();
    string getNomAction() const ;
    string getDate() const ;
    double getPrix() const;
    void setPrix(double);
    void setNomAction(string);
    void setDate(string);
     friend ostream& operator<<( ostream&, PrixJournalier&);


  };
  
  
class Transaction
{
private:
    string NomAction ;
    int quantite ;
    string date;
    string typeAction;
public:

    Transaction();
    Transaction(string ,string, int);
    string getNomAction() const ;
    string getdate() const ;
    int getQuantite () const ;
    string gettypeAction () const ;
    void setNomAction(string);
    void setDateAction(string);
    void setTypeAction(string);
    void setquantite(int);
    friend ostream& operator <<(ostream&, Transaction& );
};

class Bourse{
    public:
    string nom ;
    vector <PrixJournalier> TabPJ;
    string getNom_bourse() const ;
    void setNom_bourse(string);
    Bourse(string);
    ~Bourse();
};

class Titre
{
private:
    string NomAction ;
    int quantite ;
public:
    Titre();
    Titre(string,int);
    string getNomAction () const ;
     int getQuantite () const ;
    void setNomaction(string);
    void setquantite(int);
    friend ostream& operator<<(ostream&,  const Titre&);
};


class Client {
protected:
    string Nom;
    string prenom ;
    int CIN ;
    string login ;
    string MDP ;
    double Solde;
public:
    Client(string,string ,int, string , string , double);
    map <string,Titre> TabTitre;
    vector< Transaction> tr;
    bool rechercheTitre(string);
    void AjouterTitre( string,int);
    void SupprimerAction(string);
    string getNom() const ;
    double getSolde () const ;
    void setSolde(double);
    void setNom(string);
    void setMDP(string);
    Client();
    void ChoisirTransaction_manuelle();
    void Choisir_alea(const Bourse&);
    void Choisir_VWAP(const Bourse&);
    void Choisir_comparaison(const Bourse&);
    string getPrenom () const;
    string getMDP () const;
    string getlogin() const;
    int getCIN() const;
    void ModifierMDP (string);
    void ConsulterHistorique(Bourse &) ;
    void ConsulterCompte ();
    void deposerArgent(double);
    void retirerArgent(double);
    void consulter_transaction();
    void affichage_resultat(double);
    friend ostream& operator <<(ostream&, const Client&);
    friend void lire_fichier_clients(vector<Client> &T);
    friend void ecrire_fichier_clients(vector<Client> T);
};



class Administrateur
{
    protected:
        string login ;
        string mdp ;
        void AcheterAction(PrixJournalier,int,vector<PrixJournalier>,Client&);
        void VendreAction(PrixJournalier, int, vector<PrixJournalier>, Client& ) ;
    public:
        vector<Client> liste_client;
        Bourse * b;
        string getlogin() const;
        string getmdp() const;
        void AjouterClient (Client) ;
        void consulterclients()const;
        void consulterprixjournalier()const;
        void SupprimerClient (int) ;
        void TraiterAction(Client&) ;
        int rechercher_client_humain(string);
        Administrateur(string,string,Bourse&);
        int RechercherPrixActionJour(PrixJournalier);
        void AjouterPrixJournalier(PrixJournalier) ;
        void SupprimerPrixJournalier(PrixJournalier) ;
};



Client saisir_nouveau_compte();
void  identifier(string &login,string &MDP);
PrixJournalier saisir_prixjournalier();
void lire_fichier_clients(vector<Client> &T);
void ecrire_fichier_clients(vector<Client> T);
void lire_fichier_prixj(vector<PrixJournalier> &T);
void ecrire_fichier_prixj(vector<PrixJournalier> T);
#endif // CLASSES_H_INCLUDED
