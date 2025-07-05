
#include <iostream>
using namespace std;

const int MAX = 100;

class File {
    int tab[MAX];
    int debut;
    int fin;

public:
    File() {
        debut = 0;
        fin = -1;
    }

    void ajouter(int val) {
        if (fin >= MAX - 1) cout << "File pleine" << endl;
        else tab[++fin] = val;
    }

    void supprimer() {
        if (debut > fin) cout << "File vide" << endl;
        else debut++;
    }

    void afficher() {
        if (debut > fin) cout << "File vide" << endl;
        else {
            for (int i = debut; i <= fin; i++) cout << tab[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    File f;
    f.ajouter(1);
    f.ajouter(2);
    f.ajouter(3);
    f.afficher();
    f.supprimer();
    f.afficher();
    return 0;
}
