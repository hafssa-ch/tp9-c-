
#include <iostream>
#include <string>

class Technicien {
protected:
    double salaireTechnicien;

public:
   
    Technicien(double salaireT) : salaireTechnicien(salaireT) {}

    void afficherSalaire() const {
        std::cout << "  -> Salaire Technicien : " << salaireTechnicien << " EUR" << std::endl;
    }
};

class Comptable {
protected:
    double salaireComptable;

public:
    Comptable(double salaireC) : salaireComptable(salaireC) {}

   
    void afficherSalaire() const {
        std::cout << "  -> Salaire Comptable : " << salaireComptable << " EUR" << std::endl;
    }
};

class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(double salaireT, double salaireC)
        
        : Technicien(salaireT), Comptable(salaireC) {}

    
    void afficherTousSalaires() const {
        std::cout << "--- Affichage Salaires Employe Polyvalent ---" << std::endl;
        
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();

        std::cout << "------------------------------------------" << std::endl;
    }
 
};

int main() {
    
    EmployePolyvalent ep(3000.0, 2500.0);

    std::cout << "Test de la méthode afficherTousSalaires() :" << std::endl;
    ep.afficherTousSalaires();

    std::cout << "\nTest de l'appel direct aux méthodes parentes sur l'objet ep :" << std::endl;
    ep.Technicien::afficherSalaire();
    ep.Comptable::afficherSalaire();

    return 0;
}