#include <iostream>
using namespace std;

const int MAX = 100;

// Structure pour représenter une File
struct File {
    int tab[MAX];
    int debut;
    int fin;
};

// Fonction pour initialiser une File
void initialiserFile(File& f) {
    f.debut = 0;
    f.fin = -1;
}

// Fonction pour ajouter un élément à la File
void ajouterFile(File& f, int val) {
    if (f.fin >= MAX - 1) cout << "File pleine" << endl;
    else f.tab[++f.fin] = val;
}

// Fonction pour supprimer un élément de la File
void supprimerFile(File& f) {
    if (f.debut > f.fin) cout << "File vide" << endl;
    else f.debut++;
}

// Fonction pour afficher les éléments de la File
void afficherFile(File& f) {
    if (f.debut > f.fin) cout << "File vide" << endl;
    else {
        for (int i = f.debut; i <= f.fin; i++) cout << f.tab[i] << " ";
        cout << endl;
    }
}

int main() {
    File f; // Déclaration d'une variable de type File
    initialiserFile(f);

    ajouterFile(f, 1);
    ajouterFile(f, 2);
    ajouterFile(f, 3);
    cout << "File après ajouts : ";
    afficherFile(f);

    supprimerFile(f);
    cout << "File après suppression : ";
    afficherFile(f);

    return 0;
}