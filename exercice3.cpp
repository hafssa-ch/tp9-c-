
#include <iostream>
#include <string>

class Vehicule {
protected:
    std::string marque;
    std::string modele;

public:
    Vehicule(const std::string& m, const std::string& mod)
        : marque(m), modele(mod) {}

    virtual ~Vehicule() = default;

    void afficherVehicule() const {
        std::cout << "  [Vehicule] Marque: " << marque << ", Modèle: " << modele << std::endl;
    }
};

class Thermique : virtual public Vehicule {
protected:
    double consommationCarburant; 

public:
   
    Thermique(const std::string& m, const std::string& mod, double conso)
       
        : Vehicule(m, mod), consommationCarburant(conso) {}
    
    void afficherThermique() const {
        std::cout << "  [Thermique] Consommation: " << consommationCarburant << " L/100km" << std::endl;
    }
};

class Electrique : virtual public Vehicule {
protected:
    int autonomieBatterie; // km

public:
    
    Electrique(const std::string& m, const std::string& mod, int autonomie)
        
        : Vehicule(m, mod), autonomieBatterie(autonomie) {}
    
    void afficherElectrique() const {
        std::cout << "  [Electrique] Autonomie Batterie: " << autonomieBatterie << " km" << std::endl;
    }
};

class Hybride : public Thermique, public Electrique {
public:
   
    Hybride(const std::string& marque, const std::string& modele, 
            double conso, int autonomie)
        : Vehicule(marque, modele), 
          Thermique(marque, modele, conso), 
          Electrique(marque, modele, autonomie) 
    {
       
    }

    void afficherCaracteristiques() const {
        std::cout << "========================================" << std::endl;
        std::cout << "   Détails du Véhicule Hybride " << std::endl;
        std::cout << "========================================" << std::endl;
        
        
        Vehicule::afficherVehicule(); 
     
        afficherThermique();
        afficherElectrique();
        
        std::cout << "========================================" << std::endl;
    }
};

int main() {
    
    Hybride voiture("Toyota", "Prius", 4.5, 50);

    voiture.afficherCaracteristiques();

    return 0;
}