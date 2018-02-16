/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 
* Auteur:
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
#include "Produit.h"
using namespace std;






ProduitOrdinaire::ProduitOrdinaire(Fournisseur & fournisseur, const string & nom, int reference, double prix, TypeProduit type, bool estTaxable):Produit(fournisseur,nom,reference,prix,type)
{
	estTaxable_ = estTaxable;
}

bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return false;
}

void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{

	estTaxable_ = estTaxable;

}

ostream & operator<<(ostream & os, const ProduitOrdinaire & produit)
{
	// TODO: insert return statement here

	os << produit;
	os << "Est taxable" << produit.estTaxable_;


	return os;
}

istream & operator>>(istream & is, ProduitOrdinaire & produit)
{
	// TODO: insert return statement here

	is >> produit;
	is >> produit.estTaxable_;


	return is;
}
