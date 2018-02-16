/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"

Fournisseur::Fournisseur(const string & nom, const string & prenom, int identifiant, const string & codePostal):Usager(nom,prenom,identifiant,codePostal)

	
{
	
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {

		satisfaction_.niveaux_[i] = 0;
	}

}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}

Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{

	satisfaction_ = satisfaction;
	
}

void Fournisseur::noter(int appreciation)
{

	satisfaction_.niveaux_[appreciation]++;

}

void Fournisseur::ajouterProduit(Produit * produit)
{
	this->contenuCatalogue_.push_back(new Produit(*produit));
}

void Fournisseur::enleverProduit(Produit * produit)
{

	
	

	for (int i = 0; i < this->contenuCatalogue_.size(); i++) {

		if (this->contenuCatalogue_[i]->obtenirNom() == produit->obtenirNom()) {

			
			contenuCatalogue_.erase(contenuCatalogue_.begin() + i);		
			

		}
	}

	

}

Fournisseur & Fournisseur::operator=(const Fournisseur & fournisseur)
{
	// TODO: insert return statement here
	

	this->obtenirNom() = fournisseur.obtenirNom();
	this->obtenirPrenom() = fournisseur.obtenirPrenom();
	this->obtenirCodePostal() = fournisseur.obtenirCodePostal();
	this->obtenirSatisfaction() = fournisseur.obtenirSatisfaction();

	// copy the pointer 




	




	
}

ostream & operator<<(ostream & os, Fournisseur & fournisseur)
{
	// TODO: insert return statement here

	static_cast<Usager>(fournisseur);

	os << fournisseur;
	for (int i = 0; i < fournisseur.contenuCatalogue_.size(); i++) {
		os << "----> ";
		os << *(fournisseur.contenuCatalogue_[i]) << endl;


	}


	os << "Satisfication " << endl;
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++) {

		os << fournisseur.satisfaction_.niveaux_[i];
	}
	
	

	return os;



}
