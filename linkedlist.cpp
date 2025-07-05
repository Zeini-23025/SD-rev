
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class Liste {
    Node* head;

public:
    Liste() { head = nullptr; }

    void ajouter(int val) {
        Node* nouveau = new Node{val, nullptr};
        if (!head) head = nouveau;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = nouveau;
        }
    }

    void supprimer(int val) {
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

    void afficher() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Liste l;
    l.ajouter(1);
    l.ajouter(2);
    l.ajouter(3);
    l.afficher();
    l.supprimer(2);
    l.afficher();
    return 0;
}
