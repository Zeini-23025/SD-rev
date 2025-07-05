#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* gauche;
    Node* droit;
};

// Fonction pour créer un nouveau nœud
Node* creerNode(int val) {
    Node* nouveau = new Node;
    nouveau->val = val;
    nouveau->gauche = nullptr;
    nouveau->droit = nullptr;
    return nouveau;
}

// Fonction pour insérer une valeur dans l'arbre
void inserer(Node*& node, int val) {
    if (!node) node = creerNode(val);
    else if (val < node->val) inserer(node->gauche, val);
    else inserer(node->droit, val);
}

// Fonction pour afficher l'arbre (parcours infixe)
void afficherArbre(Node* node) {
    if (!node) return;
    afficherArbre(node->gauche);
    cout << node->val << " ";
    afficherArbre(node->droit);
}

int main() {
    Node* racine = nullptr; // L'arbre est représenté par son nœud racine

    inserer(racine, 5);
    inserer(racine, 3);
    inserer(racine, 7);
    inserer(racine, 1);

    cout << "Arbre binaire (infixe) : ";
    afficherArbre(racine);
    cout << endl;

    // Libérer la mémoire (simple pour cet exemple, pour un vrai arbre il faudrait une fonction de suppression récursive)
    // Note: Pour un exemple sans POO, la gestion de la mémoire doit être manuelle.
    // Une fonction de suppression de l'arbre serait nécessaire pour éviter les fuites de mémoire.
    // Pour cet exemple simple, nous ne l'incluons pas pour ne pas complexifier.

    return 0;
}