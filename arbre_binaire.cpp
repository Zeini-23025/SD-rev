
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* gauche;
    Node* droit;

    Node(int v) : val(v), gauche(nullptr), droit(nullptr) {}
};

class Arbre {
    Node* racine;

    void inserer(Node*& node, int val) {
        if (!node) node = new Node(val);
        else if (val < node->val) inserer(node->gauche, val);
        else inserer(node->droit, val);
    }

    void afficher(Node* node) {
        if (!node) return;
        afficher(node->gauche);
        cout << node->val << " ";
        afficher(node->droit);
    }

public:
    Arbre() { racine = nullptr; }

    void ajouter(int val) { inserer(racine, val); }

    void afficher() { afficher(racine); cout << endl; }
};

int main() {
    Arbre a;
    a.ajouter(5);
    a.ajouter(3);
    a.ajouter(7);
    a.ajouter(1);
    a.afficher();
    return 0;
}
