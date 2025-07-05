
#include <iostream>
using namespace std;

const int MAX = 100;

class Pile {
    int tab[MAX];
    int sommet;

public:
    Pile() { sommet = -1; }

    void push(int val) {
        if (sommet >= MAX - 1) cout << "Pile pleine" << endl;
        else tab[++sommet] = val;
    }

    void pop() {
        if (sommet < 0) cout << "Pile vide" << endl;
        else sommet--;
    }

    void afficher() {
        if (sommet < 0) cout << "Pile vide" << endl;
        else {
            for (int i = sommet; i >= 0; i--) cout << tab[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Pile p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.afficher();
    p.pop();
    p.afficher();
    return 0;
}
