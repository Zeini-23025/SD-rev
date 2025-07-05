
# 🔧 Structures de Données et Algorithmes en C++

Ce projet contient des exemples simples d'implémentation en C++ pour comprendre :

- Les algorithmes de tri
- Les pointeurs
- Les structures de données de base :
  - Pile (stack)
  - File (queue)
  - Liste chaînée (linked list)
  - Arbre binaire (binary tree)

---

## 📌 1. Algorithmes de tri

### 🔷 Tri par sélection (Selection Sort)

- Trouve le plus petit élément et l'échange avec l'élément courant.
- 📈 Complexité : `O(n²)`

### 🔷 Tri par insertion (Insertion Sort)

- Insère chaque élément dans la bonne position dans la partie déjà triée.
- 📈 Complexité : `O(n²)` (meilleur cas : `O(n)`)

### 🔷 Tri à bulles (Bubble Sort)

- Compare les éléments voisins et échange si nécessaire.
- 📈 Complexité : `O(n²)` (meilleur cas : `O(n)` si déjà trié)

---

## 📌 2. Les pointeurs

Un **pointeur** est une variable qui contient l’**adresse mémoire** d’une autre variable.

### Exemple :
```cpp
int x = 5;
int* p = &x;
cout << *p; // affiche 5
```

| Symbole | Signification                |
|---------|------------------------------|
| `*`     | déréférencement (accès valeur) |
| `&`     | adresse de la variable       |

---

## 📌 3. Pile (Stack)

- Structure **LIFO** (Last In First Out)
- Fonctions :
  - `push(val)` : ajoute un élément
  - `pop()` : supprime le dernier élément
  - `afficher()` : affiche le contenu

📈 Complexité :
- Push / Pop : `O(1)`
- Affichage : `O(n)`

---

## 📌 4. File (Queue)

- Structure **FIFO** (First In First Out)
- Fonctions :
  - `ajouter(val)` : ajoute à la fin
  - `supprimer()` : enlève au début
  - `afficher()` : affiche tous les éléments

📈 Complexité :
- Ajouter / Supprimer : `O(1)`
- Affichage : `O(n)`

---

## 📌 5. Liste Chaînée (Linked List)

- Chaque élément (nœud) contient :
  - une valeur
  - un pointeur vers le suivant

Fonctions :
- `ajouter(val)` : ajoute à la fin
- `supprimer(val)` : supprime un nœud
- `afficher()` : affiche tous les nœuds

📈 Complexité :
- Ajouter : `O(n)`
- Supprimer : `O(n)`
- Affichage : `O(n)`

---

## 📌 6. Arbre Binaire

- Chaque nœud a :
  - une valeur
  - un fils gauche
  - un fils droit

Fonctions :
- `ajouter(val)` : insère selon la règle du BST
- `supprimer(val)` : supprime un nœud
- `afficher()` : parcours in-order

📈 Complexité :
- Recherche / Ajout / Suppression : `O(log n)` en moyenne, `O(n)` dans le pire cas

---

## ✅ Objectif

Ce projet est destiné aux débutants pour :
- comprendre les concepts fondamentaux
- apprendre à manipuler la mémoire et les structures
- pratiquer le C++ sans bibliothèque STL

---

## 📁 Fichiers proposés

| Fichier                  | Description                        |
|--------------------------|------------------------------------|
| `tri.cpp`                | Algorithmes de tri                 |
| `pointeur.cpp`           | Exemples simples de pointeurs      |
| `pile.cpp`               | Implémentation manuelle de pile    |
| `file.cpp`               | Implémentation manuelle de file    |
| `linkedlist.cpp`         | Liste chaînée                      |
| `arbre_binaire.cpp`      | Arbre binaire                      |

---

## 📚 À venir (si besoin)

- Menu interactif en console
- Interface graphique (SFML ou SDL)
- Structures dynamiques avec `new` et `delete`

---

## 💬 Auteur

Réalisé à des fins éducatives pour mieux comprendre la logique des structures en C++.
