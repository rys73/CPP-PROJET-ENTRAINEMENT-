#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class Produit{
public:
    virtual void afficher() = 0;
    virtual double total() = 0;
    virtual ~Produit() {}
};
class Livre : public Produit{
private:
    string nom[10] = {"C++ avancé", "Design Patterns", "Programmation Moderne en C++", "Algorithmique Pour Tous", "La POO en C++", "Structures de Données", "C++ pour les Nuls", "Apprendre STL", "Programmation Concurrente", "Introduction à l'Algorithmique"};
    string auteur[10] = {"Bjarne Stroustrup", "Erich Gamma", "Scott Mayers", "Donald Knuth", "Bjarne Stroustrup", "Robert Lafore", "Stephen R. Davis", "Nicolai M. Josuttis", "Anthony Williams", "Thomas Cormen"};
    double prixLivre[10] = {49.99, 39.50, 59.90, 74.99, 44.90, 34.50, 29.99, 39.90, 54.99, 64.50};

public:
    void afficher() override{
        cout << "=== Catalogue Livres ===" << endl;
        for (int i = 0; i <= 9; i++){
            cout << i+1 << ". " << nom[i] << " - (Auteur : " << auteur[i] << ") "
                 << "- " << fixed << setprecision(2) << prixLivre[i] << " €" << endl;;
        }
        cout << "Total Prix des Livres : " << fixed << setprecision(2) << total() << "€\n\n";
    }

    double total() override{
        double somme = 0;
        for (double prix : prixLivre)
          somme += prix;
        return somme;
    }
};

class Ordinateur : public Produit{
private:
    string nom[10] = {"MacBook Pro", "XPS 15", "ThinkPad X1 Carbon", "ROG Zephyrus G14", "Surface Laptop 5", "MacBook Air", "Legion 5", "Predator Helios 300", "Razer Blade 15", "HP Spectre x360"};
    string marque[10] = {"Apple", "Dell", "Lenovo", "Asus", "Microsoft", "Apple", "Lenovo", "Acer", "Razer", "HP"};
    double prixOrdinateur[10] = {1799.00, 1499.00, 1699.00, 1899.00, 1399.00, 1299.00, 1499.00, 1799.00, 1999.00, 1599.00};
    
public:
    void afficher() override{
        cout << "=== Catalogue Ordinateurs ===" << endl;
        for (int i = 0; i <= 9; i++){
            cout << i+1 << ". " << nom[i] << " (" << marque[i] << ")"
                 << " - " << fixed << setprecision(2) << prixOrdinateur[i] << " €" << endl;
        }
        cout << "Total Prix des Ordinateurs : " << fixed << setprecision(2) << total() << " €\n\n";
    }

    double total() override{
        double somme = 0;
        for (double prix : prixOrdinateur)
          somme += prix;
        return somme;
    }
};

int main(){
    system("chcp 65001 > nul");

    vector<unique_ptr<Produit>> produits;
    produits.push_back(make_unique<Livre>());
    produits.push_back(make_unique<Ordinateur>());

    double totalGlobal = 0;

    for (auto& p : produits){
        p-> afficher();
        totalGlobal += p->total();
    }

    cout << "===" << endl;
    cout << "TOTAL GLOBAL : " << fixed << setprecision(2) << totalGlobal << " €" << endl;
    cout << "===" << endl;

    return 0;
}