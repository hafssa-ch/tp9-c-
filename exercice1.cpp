
#ifndef ENSEIGNANTCHERCHEUR_HPP
#define ENSEIGNANTCHERCHEUR_HPP

#include <iostream>
#include <string>


class Personne {
protected:
    std::string nom;
    std::string prenom;

public:
   
    Personne(const std::string& n, const std::string& p)
        : nom(n), prenom(p) {}

   
    void afficher() const {
        std::cout << "  -> Personne : " << prenom << " " << nom << std::endl;
    }
};


class Chercheur {
protected:
    std::string domaineRecherche;

public:
   
    Chercheur(const std::string& domaine)
        : domaineRecherche(domaine) {}

    
    void afficher() const {
        std::cout << "  -> Chercheur : Domaine = " << domaineRecherche << std::endl;
    }
};


class EnseignantChercheur : public Personne, public Chercheur {
private:
    
public:
    EnseignantChercheur(const std::string& nom, const std::string& prenom, const std::string& domaine)
        : Personne(nom, prenom), Chercheur(domaine) {}

    void afficher() const {
        std::cout << "--- Affichage Enseignant Chercheur ---" << std::endl;
        Personne::afficher();
        Chercheur::afficher();
        std::cout << "--------------------------------------" << std::endl;
    }
};

#endif 


int main() {
    
    EnseignantChercheur ec("Dupont", "Marie", "Intelligence Artificielle");

   
    std::cout << "Test de la méthode afficher() de EnseignantChercheur :" << std::endl;
    ec.afficher();

    std::cout << "\nTest de l'appel direct aux méthodes parentes :" << std::endl;
    ec.Personne::afficher();
    ec.Chercheur::afficher();
    
    return 0;
}