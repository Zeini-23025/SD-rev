#include <iostream>
using namespace std;

const int TAILLE_TABLE = 10;
const int MAX_CLE = 50;

struct EntreeHachage {
    char cle[MAX_CLE];
    int valeur;
    bool occupe;
};

struct TableHachage {
    EntreeHachage table[TAILLE_TABLE];
};

// Fonction de hachage simple (somme des ASCII % taille)
int fonctionHachage(const char* cle) {
    int somme = 0;
    int i = 0;
    while (cle[i] != '\0') {
        somme += cle[i];
        i++;
    }
    return somme % TAILLE_TABLE;
}

// Copie manuelle d'une chaîne
void copierChaine(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0' && i < MAX_CLE - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Comparaison manuelle de deux chaînes
bool comparerChaines(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

// Initialise la table (toutes les cases libres)
void initialiserTableHachage(TableHachage& th) {
    for (int i = 0; i < TAILLE_TABLE; ++i) {
        th.table[i].occupe = false;
    }
}

// Insérer une paire clé-valeur
bool inserer(TableHachage& th, const char* cle, int valeur) {
    int index = fonctionHachage(cle);
    int original_index = index;

    while (th.table[index].occupe && !comparerChaines(th.table[index].cle, cle)) {
        index = (index + 1) % TAILLE_TABLE;
        if (index == original_index) {
            cout << "Table pleine, insertion impossible pour : " << cle << endl;
            return false; // Table pleine, insertion échouée
        }
    }

    copierChaine(th.table[index].cle, cle);
    th.table[index].valeur = valeur;
    th.table[index].occupe = true;
    cout << "Inséré (" << cle << ", " << valeur << ") à l'index " << index << endl;
    return true; // Insertion réussie
}

// Rechercher une valeur par clé, retourne true si trouvée
bool rechercher(const TableHachage& th, const char* cle, int& valeur_trouvee) {
    int index = fonctionHachage(cle);
    int original = index;

    while (th.table[index].occupe) {
        if (comparerChaines(th.table[index].cle, cle)) {
            valeur_trouvee = th.table[index].valeur;
            return true;
        }
        index = (index + 1) % TAILLE_TABLE;
        if (index == original) break;
    }
    return false;
}

// Supprimer une entrée par clé (marquer libre)
void supprimer(TableHachage& th, const char* cle) {
    int index = fonctionHachage(cle);
    int original = index;

    while (th.table[index].occupe) {
        if (comparerChaines(th.table[index].cle, cle)) {
            th.table[index].occupe = false;
            cout << "Supprimé : " << cle << " à l'index " << index << endl;
            return;
        }
        index = (index + 1) % TAILLE_TABLE;
        if (index == original) break;
    }
    cout << "Clé non trouvée pour suppression : " << cle << endl;
}

// Afficher la table
void afficher(const TableHachage& th) {
    cout << "\n--- Contenu de la table ---" << endl;
    for (int i = 0; i < TAILLE_TABLE; ++i) {
        cout << "Index " << i << ": ";
        if (th.table[i].occupe) {
            cout << "(" << th.table[i].cle << ", " << th.table[i].valeur << ")";
        } else {
            cout << "(vide)";
        }
        cout << endl;
    }
}

// Exemple d'utilisation
int main() {
    TableHachage maTable;
    initialiserTableHachage(maTable);

    inserer(maTable, "pomme", 10);
    inserer(maTable, "banane", 20);
    inserer(maTable, "cerise", 30);
    inserer(maTable, "date", 40);
    inserer(maTable, "elderberry", 50);

    afficher(maTable);

    int val;
    if (rechercher(maTable, "banane", val)) {
        cout << "\nValeur associée à 'banane' : " << val << endl;
    } else {
        cout << "\n'banane' non trouvée." << endl;
    }

    supprimer(maTable, "cerise");
    afficher(maTable);

    if (rechercher(maTable, "cerise", val)) {
        cout << "Valeur de 'cerise' : " << val << endl;
    } else {
        cout << "'cerise' non trouvée après suppression." << endl;
    }

    return 0;
}
