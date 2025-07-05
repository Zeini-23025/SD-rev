#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

// Fonction pour ajouter un élément à la liste
void ajouterListe(Node*& head, int val) {
    Node* nouveau = new Node{val, nullptr};
    if (!head) head = nouveau;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = nouveau;
    }
}

// Fonction pour supprimer un élément de la liste
void supprimerListe(Node*& head, int val) {
    if (!head) return;
    if (head->val == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    while (curr->next && curr->next->val != val) curr = curr->next;
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

// Fonction pour afficher les éléments de la liste
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* maListe = nullptr; // La liste est représentée par son pointeur de tête

    ajouterListe(maListe, 1);
    ajouterListe(maListe, 2);
    ajouterListe(maListe, 3);
    cout << "Liste après ajouts : ";
    afficherListe(maListe);

    supprimerListe(maListe, 2);
    cout << "Liste après suppression de 2 : ";
    afficherListe(maListe);

    // Libérer la mémoire (pour un vrai programme, il faudrait une fonction pour parcourir et supprimer tous les nœuds)
    Node* current = maListe;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    maListe = nullptr;

    return 0;
}