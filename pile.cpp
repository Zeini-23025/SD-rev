#include <iostream>
using namespace std;

const int MAX = 100;

// Structure pour représenter une Pile
struct Pile {
    int tab[MAX];
    int sommet;
};

// Fonction pour initialiser une Pile
void initialiserPile(Pile& p) {
    p.sommet = -1;
}

// Fonction pour empiler un élément
void push(Pile& p, int val) {
    if (p.sommet >= MAX - 1) cout << "Pile pleine" << endl;
    else p.tab[++p.sommet] = val;
}

// Fonction pour dépiler un élément
void pop(Pile& p) {
    if (p.sommet < 0) cout << "Pile vide" << endl;
    else p.sommet--;
}

// Fonction pour afficher les éléments de la Pile
void afficherPile(Pile& p) {
    if (p.sommet < 0) cout << "Pile vide" << endl;
    else {
        for (int i = p.sommet; i >= 0; i--) cout << p.tab[i] << " ";
        cout << endl;
    }
}

int main() {
    Pile p; // Déclaration d'une variable de type Pile
    initialiserPile(p);

    push(p, 10);
    push(p, 20);
    push(p, 30);
    cout << "Pile après ajouts : ";
    afficherPile(p);

    pop(p);
    cout << "Pile après suppression : ";
    afficherPile(p);

    return 0;
}