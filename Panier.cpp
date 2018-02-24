/********************************************
* Titre: Travail pratique #3 - Panier.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Panier.h"
#include "ProduitOrdinaire.h"
using namespace std;

Panier::Panier(int idClient) {
	// TODO
	idClient_ = idClient;
	totalAPayer_ = 0;
	
}


Panier::~Panier()
{

	contenuPanier_.clear();
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return (int)contenuPanier_.size();
}


int Panier::obtenirIdClient() const {
	return idClient_;
}

double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}


double Panier::calculerTotalApayer()  const
{
	 // TODO
	double total = 0; 

	total = this->obtenirTotalApayer();



	for (int i = 0; i < this->obtenirContenuPanier().size(); i++)
	{

		if (contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres) 
		{

			
			if (this->obtenirIdClient() == static_cast<ProduitAuxEncheres*>(contenuPanier_[i])->obtenirIdentifiantClient()) {


				total += contenuPanier_[i]->obtenirPrix();


			}

		   
			

		}

		


	}




	return total;
}



void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


void Panier::modifierIdClient(int idClient) {
	idClient_ = idClient;
}




void Panier::ajouter(Produit * prod)
{
	// TODO

	

	if (prod->retournerType() == TypeProduitOrdinaire) {
		
		if (static_cast<ProduitOrdinaire*>(prod)->obtenirEstTaxable() == true) {


			double tax = 0.0;
			tax = prod->obtenirPrix() * TAUX_TAXE;
			totalAPayer_ += tax + prod->obtenirPrix();
			contenuPanier_.push_back(new Produit(*prod));
			
			
		}

		else {

			totalAPayer_ += prod->obtenirPrix();
			contenuPanier_.push_back(new Produit(*prod));
		}


		
		

	}


	else {



		
		contenuPanier_.push_back(new Produit(*prod));

	}
	
}

void Panier::livrer()
{
	totalAPayer_ = 0;
	contenuPanier_.clear();
}

Produit* Panier::trouverProduitPlusCher()
{
	if (contenuPanier_.empty())
		return nullptr;

	Produit* prodPlusChere = contenuPanier_[0];
	for (unsigned int i = 1; i < contenuPanier_.size(); i++)
		if (*contenuPanier_[i] > *prodPlusChere)
			prodPlusChere = contenuPanier_[i];

	return prodPlusChere;
}

ostream & operator<<(ostream & os,  const Panier & panier)
{
	// TODO

	
	
	

	for(int i=0; i < panier.contenuPanier_.size(); i++){

		if (panier.contenuPanier_[i]->retournerType() == TypeProduitAuxEncheres){

			os << "Produit aux enchers " << *(static_cast<ProduitAuxEncheres*>(panier.contenuPanier_[i]));
		

		}
			

		else 
		{
			if ((panier.contenuPanier_[i]->retournerType() == TypeProduitOrdinaire)) {

				

				os << " Produit Ordinaire " << *(static_cast<ProduitOrdinaire*>(panier.contenuPanier_[i]));
			}

			
			
			
		}
	

	}


	os << "---->" << "total a payer  " << panier.obtenirTotalApayer() << endl;
	//os << "total " << panier.calculerTotalApayer(); 
	//os << "total  obtenir " << panier.obtenirTotalApayer(); 


	

	




	return os;

	
}
