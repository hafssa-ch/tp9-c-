
#include <iostream>
#include <string>
#include <limits> 

class Utilisateur {
protected:
    int identifiant;
    std::string login;

public:
    
    Utilisateur(int id, const std::string& log) : identifiant(id), login(log) {}

    virtual ~Utilisateur() = default;

    void afficherIdentite() const {
        std::cout << "  [Utilisateur] ID: " << identifiant << ", Login: " << login << std::endl;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    std::string droitsAcces;

public:
    
    Administrateur(int id, const std::string& log, const std::string& droits)
        : Utilisateur(id, log), droitsAcces(droits) {}

    void gererSysteme() const {
        std::cout << "  [Administrateur] Gère le système avec droits: " << droitsAcces << std::endl;
    }
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration; 

public:
   
    Moderateur(int id, const std::string& log, int niveau)
        : Utilisateur(id, log), niveauModeration(niveau) {}

    void modererContenu() const {
        std::cout << "  [Moderateur] Modère le contenu au niveau: " << niveauModeration << std::endl;
    }
};

class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    
    SuperUtilisateur(int id, const std::string& log, 
                     const std::string& droits, int niveau)
        
        : Utilisateur(id, log),
       
          Administrateur(id, log, droits),
          Moderateur(id, log, niveau) 
    {
        
    }

    
    void afficherRoles() const {
        std::cout << "\n--- STATUT : SuperUtilisateur ---" << std::endl;
        
        
        Utilisateur::afficherIdentite();
        
        
        gererSysteme();
        modererContenu();
        
        std::cout << "-----------------------------------" << std::endl;
    }
};

void lancerTests() {
    int id, niveau;
    std::string login, droits;

    std::cout << "=== Création d'un SuperUtilisateur ===" << std::endl;

    
    std::cout << "Entrez l'identifiant: ";
    if (!(std::cin >> id)) return; 

    std::cout << "Entrez le login: ";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, login);

    std::cout << "Entrez les droits d'accès (ex: FULL, PARTIAL): ";
    std::getline(std::cin, droits);

    std::cout << "Entrez le niveau de modération (1-10): ";
    if (!(std::cin >> niveau)) return; 

    SuperUtilisateur su(id, login, droits, niveau);

    
    su.afficherRoles();
}

int main() {
    lancerTests();
    return 0;
}