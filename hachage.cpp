#include <iostream>
#include <vector>
#include <string>

const int TAILLE_TABLE = 10; // Taille fixe de la table de hachage

// Structure pour représenter une entrée dans la table de hachage
struct EntreeHachage {
    std::string cle;
    int valeur;
    bool occupe; // Indique si l'emplacement est occupé
};

// Structure pour la table de hachage
struct TableHachage {
    EntreeHachage table[TAILLE_TABLE];
};

// Fonction de hachage simple (somme des valeurs ASCII des caractères de la clé modulo TAILLE_TABLE)
int fonctionHachage(const std::string& cle) {
    int somme = 0;
    for (char c : cle) {
        somme += c;
    }
    return somme % TAILLE_TABLE;
}

// Initialise la table de hachage
void initialiserTableHachage(TableHachage& th) {
    for (int i = 0; i < TAILLE_TABLE; ++i) {
        th.table[i].occupe = false;
    }
}

// Insère une paire clé-valeur dans la table de hachage
void inserer(TableHachage& th, const std::string& cle, int valeur) {
    int index = fonctionHachage(cle);
    int original_index = index;

    // Gestion des collisions par sondage linéaire
    while (th.table[index].occupe && th.table[index].cle != cle) {
        index = (index + 1) % TAILLE_TABLE;
        if (index == original_index) {
            return false; // Table pleine, insertion échouée
        }
    }

    th.table[index].cle = cle;
    th.table[index].valeur = valeur;
    th.table[index].occupe = true;
    return true; // Insertion réussie
}

// Recherche une valeur par sa clé dans la table de hachage
// Retourne true si trouvé, false sinon. La valeur est stockée dans 'valeur_trouvee'.
bool rechercher(const TableHachage& th, const std::string& cle, int& valeur_trouvee) {
    int index = fonctionHachage(cle);
    int original_index = index;

    while (th.table[index].occupe) {
        if (th.table[index].cle == cle) {
            valeur_trouvee = th.table[index].valeur;
            return true;
        }
        index = (index + 1) % TAILLE_TABLE;
        if (index == original_index) {
            break; // Boucle complète, clé non trouvée
        }
    }
    return false;
}

// Supprime une entrée par sa clé de la table de hachage
void supprimer(TableHachage& th, const std::string& cle) {
    int index = fonctionHachage(cle);
    int original_index = index;

    while (th.table[index].occupe) {
        if (th.table[index].cle == cle) {
            th.table[index].occupe = false; // Marque comme non occupé
            std::cout << "Supprimé : " << cle << " de l'index " << index << std::endl;
            return;
        }
        index = (index + 1) % TAILLE_TABLE;
        if (index == original_index) {
            break; // Boucle complète, clé non trouvée
        }
    }
    std::cout << "Clé non trouvée pour suppression : " << cle << std::endl;
}

// Affiche le contenu de la table de hachage
void afficherTableHachage(const TableHachage& th) {
    std::cout << "\nContenu de la table de hachage :" << std::endl;
    for (int i = 0; i < TAILLE_TABLE; ++i) {
        std::cout << "Index " << i << ": ";
        if (th.table[i].occupe) {
            std::cout << "(" << th.table[i].cle << ", " << th.table[i].valeur << ")";
        } else {
            std::cout << "(vide)";
        }
        std::cout << std::endl;
    }
}

int main() {
    TableHachage maTable;
    initialiserTableHachage(maTable);

    inserer(maTable, "pomme", 10);
    inserer(maTable, "banane", 20);
    inserer(maTable, "cerise", 30);
    inserer(maTable, "date", 40);
    inserer(maTable, "elderberry", 50);

    afficherTableHachage(maTable);

    int valeur;
    if (rechercher(maTable, "banane", valeur)) {
        std::cout << "\nValeur de 'banane' : " << valeur << std::endl;
    } else {
        std::cout << "\n'banane' non trouvée." << std::endl;
    }

    if (rechercher(maTable, "grape", valeur)) {
        std::cout << "Valeur de 'grape' : " << valeur << std::endl;
    } else {
        std::cout << "'grape' non trouvée." << std::endl;
    }

    supprimer(maTable, "cerise");
    afficherTableHachage(maTable);

    if (rechercher(maTable, "cerise", valeur)) {
        std::cout << "Valeur de 'cerise' : " << valeur << std::endl;
    } else {
        std::cout << "'cerise' non trouvée après suppression." << std::endl;
    }

    // Test de collision et de sondage linéaire
    inserer(maTable, "ananas", 60); // Peut entrer en collision avec 'pomme' ou 'banane' selon la fonction de hachage
    inserer(maTable, "apricot", 70);
    afficherTableHachage(maTable);

    return 0;
}
