# 🔧 Structures de Données et Algorithmes en C++

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://github.com/Zeini-23025)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)](https://github.com/Zeini-23025)

Un projet éducatif complet pour apprendre les structures de données fondamentales et les algorithmes en C++. Ce repository contient des implémentations claires et commentées, idéales pour les étudiants et développeurs débutants.

## 📋 Table des matières

- [🎯 Objectifs](#-objectifs)
- [📚 Contenu du projet](#-contenu-du-projet)
- [🚀 Installation et utilisation](#-installation-et-utilisation)
- [📖 Documentation](#-documentation)
- [🔧 Structures implémentées](#-structures-implémentées)
- [📊 Complexités](#-complexités)
- [🤝 Contribution](#-contribution)
- [📄 Licence](#-licence)

## 🎯 Objectifs

Ce projet vise à :
- ✅ Comprendre les concepts fondamentaux des structures de données
- ✅ Maîtriser les algorithmes de tri classiques
- ✅ Apprendre la manipulation des pointeurs en C++
- ✅ Pratiquer l'implémentation manuelle (sans STL)
- ✅ Analyser les complexités temporelles et spatiales

## 📚 Contenu du projet

### 🔷 Algorithmes de tri
- **Tri par sélection** - Sélection du minimum/maximum
- **Tri par insertion** - Insertion dans la partie triée
- **Tri à bulles** - Comparaison d'éléments adjacents
- **Tri par fusion** - Diviser pour régner (Merge Sort)

### 🔷 Structures de données
- **Pile (Stack)** - Structure LIFO
- **File (Queue)** - Structure FIFO
- **Liste chaînée** - Structure dynamique linéaire
- **Arbre binaire** - Structure arborescente
- **Table de hachage** - Structure d'accès direct

## 🚀 Installation et utilisation

### Prérequis
- Compilateur C++ (GCC, Clang, ou MSVC)
- Standard C++11 ou plus récent

### Compilation
```bash
# Cloner le repository
git clone https://github.com/Zeini-23025/structures-donnees-cpp.git
cd structures-donnees-cpp

# Compiler un fichier spécifique
g++ -std=c++11 -o tri tri.cpp
./tri

# Compiler tous les fichiers
make all
```

### Utilisation
```bash
# Exécuter les exemples
./tri           # Algorithmes de tri
./pile          # Démonstration de la pile
./file          # Démonstration de la file
./linkedlist    # Liste chaînée
./arbre_binaire # Arbre binaire
./hachage       # Table de hachage
```

## 📖 Documentation

### Pointeurs en C++
```cpp
int x = 5;
int* p = &x;    // p pointe vers x
cout << *p;     // affiche 5 (déréférencement)
```

| Opérateur | Description |
|-----------|-------------|
| `*` | Déréférencement (accès à la valeur) |
| `&` | Adresse de la variable |

### Exemple d'utilisation - Pile
```cpp
#include "pile.h"

int main() {
    Pile p;
    p.push(10);
    p.push(20);
    p.push(30);
    
    p.afficher();  // Affiche: 30 20 10
    p.pop();       // Supprime 30
    p.afficher();  // Affiche: 20 10
    
    return 0;
}
```

## 🔧 Structures implémentées

### 📁 Organisation des fichiers

| Fichier | Description | Fonctionnalités |
|---------|-------------|-----------------|
| `tri.cpp` | Algorithmes de tri | Selection, Insertion, Bubble, Merge sort |
| `pointeur.cpp` | Exemples de pointeurs | Syntaxe, manipulation mémoire |
| `pile.cpp` | Implémentation de pile | Push, Pop, Afficher |
| `file.cpp` | Implémentation de file | Ajouter, Supprimer, Afficher |
| `linkedlist.cpp` | Liste chaînée | Ajouter, Supprimer, Rechercher |
| `arbre_binaire.cpp` | Arbre binaire de recherche | Insertion, Suppression, Parcours |
| `hachage.cpp` | Table de hachage | Insertion, Recherche, Suppression |

### 🔄 Fonctionnalités principales

#### Pile (Stack) - LIFO
- `push(valeur)` : Ajouter un élément
- `pop()` : Supprimer le dernier élément
- `top()` : Consulter le sommet
- `isEmpty()` : Vérifier si vide

#### File (Queue) - FIFO
- `enqueue(valeur)` : Ajouter à la fin
- `dequeue()` : Supprimer au début
- `front()` : Consulter le premier élément
- `isEmpty()` : Vérifier si vide

#### Liste Chaînée
- `ajouter(valeur)` : Ajouter un nœud
- `supprimer(valeur)` : Supprimer un nœud
- `rechercher(valeur)` : Rechercher un élément
- `afficher()` : Parcourir la liste

#### Arbre Binaire de Recherche
- `inserer(valeur)` : Ajouter selon la règle BST
- `supprimer(valeur)` : Supprimer un nœud
- `rechercher(valeur)` : Rechercher un élément
- `parcours()` : In-order, Pre-order, Post-order

#### Table de Hachage
- `inserer(cle, valeur)` : Ajouter une paire
- `rechercher(cle)` : Trouver une valeur
- `supprimer(cle)` : Supprimer une paire
- `afficher()` : Afficher le contenu

## 📊 Complexités

### Algorithmes de tri
| Algorithme | Meilleur cas | Cas moyen | Pire cas | Espace |
|------------|--------------|-----------|----------|---------|
| Sélection | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion | O(n) | O(n²) | O(n²) | O(1) |
| Bulles | O(n) | O(n²) | O(n²) | O(1) |
| Fusion | O(n log n) | O(n log n) | O(n log n) | O(n) |

### Structures de données
| Structure | Insertion | Recherche | Suppression | Espace |
|-----------|-----------|-----------|-------------|---------|
| Pile | O(1) | O(n) | O(1) | O(n) |
| File | O(1) | O(n) | O(1) | O(n) |
| Liste chaînée | O(n) | O(n) | O(n) | O(n) |
| Arbre binaire | O(log n) | O(log n) | O(log n) | O(n) |
| Table de hachage | O(1)* | O(1)* | O(1)* | O(n) |

*En moyenne, O(n) dans le pire cas

## 🚧 Fonctionnalités à venir

- [ ] Menu interactif en console
- [ ] Interface graphique (SFML/SDL)
- [ ] Algorithmes de tri avancés (QuickSort, MergeSort)
- [ ] Structures avancées (AVL, Red-Black Tree)
- [ ] Tests unitaires automatisés
- [ ] Documentation Doxygen

## 🤝 Contribution

Les contributions sont les bienvenues ! Pour contribuer :

1. 🍴 Fork le projet
2. 🌟 Créer une branche (`git checkout -b feature/nouvelle-fonctionnalite`)
3. 💾 Commit vos changements (`git commit -am 'Ajout d'une nouvelle fonctionnalité'`)
4. 📤 Push vers la branche (`git push origin feature/nouvelle-fonctionnalite`)
5. 🔄 Créer une Pull Request

### Guidelines de contribution
- Respecter le style de code existant
- Ajouter des commentaires explicatifs
- Tester les nouvelles fonctionnalités
- Mettre à jour la documentation

## 📞 Contact

**Auteur** : [Zeini-23025](https://github.com/Zeini-23025)

- 📧 Email : [zeiny.cheikh.dev@gmail.com](zeiny.cheikh.dev@gmail.com)
- 🔗 GitHub : [@Zeini-23025](https://github.com/Zeini-23025)


## 📄 Licence

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

## ⭐ Remerciements

Si ce projet vous a été utile, n'hésitez pas à lui donner une étoile ⭐ !


---

<div align="center">
  <b>Fait avec ❤️ pour l'apprentissage</b>
</div>