# 🌳 Parcours d'Arbres Binaires - Guide Complet

## 📋 Table des matières
- [🎯 Introduction](#-introduction)
- [🔍 Types de parcours](#-types-de-parcours)
- [🌲 Construction d'arbre avec exemple](#-construction-darbre-avec-exemple)
- [📝 Exemple pratique](#-exemple-pratique)
- [💻 Implémentation en C++](#-implémentation-en-c)

---

## 🎯 Introduction

Les **parcours d'arbres binaires** sont des méthodes pour visiter tous les nœuds d'un arbre dans un ordre spécifique. Il existe trois types principaux :

1. **Préfixe (Pre-order)** : Racine → Gauche → Droite
2. **Infixe (In-order)** : Gauche → Racine → Droite  
3. **Postfixe (Post-order)** : Gauche → Droite → Racine

---

## 🔍 Types de parcours

### 🔸 Parcours Préfixe (Pre-order)
**Ordre :** `Racine → Sous-arbre gauche → Sous-arbre droit`

**Utilité :**
- Créer une copie de l'arbre
- Sérialiser l'arbre
- Expressions préfixées (notation polonaise)

### 🔸 Parcours Infixe (In-order)
**Ordre :** `Sous-arbre gauche → Racine → Sous-arbre droit`

**Utilité :**
- **Arbre binaire de recherche (BST)** : donne les valeurs **triées**
- Évaluation d'expressions mathématiques
- Le plus utilisé pour afficher les valeurs en ordre croissant

### 🔸 Parcours Postfixe (Post-order)
**Ordre :** `Sous-arbre gauche → Sous-arbre droit → Racine`

**Utilité :**
- Supprimer l'arbre (libérer la mémoire)
- Calculer la taille de l'arbre
- Expressions postfixées (notation polonaise inverse)

---

## 🌲 Construction d'arbre avec exemple

### 📊 Données : `20, 30, 10, 5, 6, 1, 4`

Construisons un **Arbre Binaire de Recherche (BST)** en insérant les valeurs dans l'ordre :

#### Étape 1 : Insertion de 20 (racine)
```
    20
```

#### Étape 2 : Insertion de 30 (30 > 20 → droite)
```
    20
      \
      30
```

#### Étape 3 : Insertion de 10 (10 < 20 → gauche)
```
    20
   /  \
  10   30
```

#### Étape 4 : Insertion de 5 (5 < 20, 5 < 10 → gauche de 10)
```
    20
   /  \
  10   30
 /
5
```

#### Étape 5 : Insertion de 6 (6 < 20, 6 < 10, 6 > 5 → droite de 5)
```
    20
   /  \
  10   30
 /
5
 \
  6
```

#### Étape 6 : Insertion de 1 (1 < 20, 1 < 10, 1 < 5 → gauche de 5)
```
    20
   /  \
  10   30
 /
5
/\
1  6
```

#### Étape 7 : Insertion de 4 (4 < 20, 4 < 10, 4 < 5, 4 > 1 → droite de 1)
```
    20
   /  \
  10   30
 /
5
/\
1  6
 \
  4
```

### 🎯 Arbre final
```
        20
       /  \
      10   30
     /
    5
   / \
  1   6
   \
    4
```

---

## 📝 Exemple pratique

### 🔸 Parcours Préfixe (Pre-order)
**Ordre :** Racine → Gauche → Droite

**Résultat :** `20, 10, 5, 1, 4, 6, 30`

**Explication :**
1. Visite **20** (racine)
2. Va à gauche : visite **10**
3. Va à gauche de 10 : visite **5**
4. Va à gauche de 5 : visite **1**
5. Va à droite de 1 : visite **4**
6. Retour à 5, va à droite : visite **6**
7. Retour à 20, va à droite : visite **30**

### 🔸 Parcours Infixe (In-order)
**Ordre :** Gauche → Racine → Droite

**Résultat :** `1, 4, 5, 6, 10, 20, 30`

**Explication :**
1. Va tout à gauche : visite **1**
2. Remonte au parent de 1, va à droite : visite **4**
3. Remonte au parent de 1 et 4 : visite **5**
4. Va à droite de 5 : visite **6**
5. Remonte au parent de 5 : visite **10**
6. Remonte à la racine : visite **20**
7. Va à droite de 20 : visite **30**

> **⚠️ Note importante :** Pour un BST, le parcours infixe donne **toujours** les valeurs **triées** !

### 🔸 Parcours Postfixe (Post-order)
**Ordre :** Gauche → Droite → Racine

**Résultat :** `4, 1, 6, 5, 10, 30, 20`

**Explication :**
1. Va tout à gauche, puis droite : visite **4**
2. Remonte au parent de 4 : visite **1**
3. Remonte, va à droite : visite **6**
4. Remonte au parent de 1 et 6 : visite **5**
5. Remonte au parent de 5 : visite **10**
6. Remonte, va à droite : visite **30**
7. Finalement, visite la racine : visite **20**

---

## 💻 Implémentation en C++

```cpp
#include <iostream>
using namespace std;

struct Noeud {
    int data;
    Noeud* gauche;
    Noeud* droite;
    
    Noeud(int val) : data(val), gauche(nullptr), droite(nullptr) {}
};

class ArbreBinaire {
public:
    Noeud* racine;
    
    ArbreBinaire() : racine(nullptr) {}
    
    // Insertion dans un BST
    Noeud* inserer(Noeud* noeud, int val) {
        if (noeud == nullptr) {
            return new Noeud(val);
        }
        
        if (val < noeud->data) {
            noeud->gauche = inserer(noeud->gauche, val);
        } else {
            noeud->droite = inserer(noeud->droite, val);
        }
        
        return noeud;
    }
    
    // Parcours Préfixe (Pre-order)
    void prefixe(Noeud* noeud) {
        if (noeud != nullptr) {
            cout << noeud->data << " ";  // Visite la racine
            prefixe(noeud->gauche);      // Parcours gauche
            prefixe(noeud->droite);      // Parcours droite
        }
    }
    
    // Parcours Infixe (In-order)
    void infixe(Noeud* noeud) {
        if (noeud != nullptr) {
            infixe(noeud->gauche);       // Parcours gauche
            cout << noeud->data << " ";  // Visite la racine
            infixe(noeud->droite);       // Parcours droite
        }
    }
    
    // Parcours Postfixe (Post-order)
    void postfixe(Noeud* noeud) {
        if (noeud != nullptr) {
            postfixe(noeud->gauche);     // Parcours gauche
            postfixe(noeud->droite);     // Parcours droite
            cout << noeud->data << " ";  // Visite la racine
        }
    }
};

int main() {
    ArbreBinaire arbre;
    
    // Insertion des valeurs : 20, 30, 10, 5, 6, 1, 4
    arbre.racine = arbre.inserer(arbre.racine, 20);
    arbre.racine = arbre.inserer(arbre.racine, 30);
    arbre.racine = arbre.inserer(arbre.racine, 10);
    arbre.racine = arbre.inserer(arbre.racine, 5);
    arbre.racine = arbre.inserer(arbre.racine, 6);
    arbre.racine = arbre.inserer(arbre.racine, 1);
    arbre.racine = arbre.inserer(arbre.racine, 4);
    
    cout << "Arbre construit avec : 20, 30, 10, 5, 6, 1, 4\n\n";
    
    cout << "Parcours Préfixe (Pre-order) : ";
    arbre.prefixe(arbre.racine);
    cout << "\n";
    
    cout << "Parcours Infixe (In-order) : ";
    arbre.infixe(arbre.racine);
    cout << "\n";
    
    cout << "Parcours Postfixe (Post-order) : ";
    arbre.postfixe(arbre.racine);
    cout << "\n";
    
    return 0;
}
```

### 📊 Résultat de l'exécution :
```
Arbre construit avec : 20, 30, 10, 5, 6, 1, 4

Parcours Préfixe (Pre-order) : 20 10 5 1 4 6 30 
Parcours Infixe (In-order) : 1 4 5 6 10 20 30 
Parcours Postfixe (Post-order) : 4 1 6 5 10 30 20 
```

---

## 🎯 Résumé

| Type de parcours | Ordre | Utilité principale | Résultat pour notre exemple |
|------------------|-------|-------------------|------------------------------|
| **Préfixe** | Racine → Gauche → Droite | Copier/Sérialiser | `20, 10, 5, 1, 4, 6, 30` |
| **Infixe** | Gauche → Racine → Droite | **Tri (BST)** | `1, 4, 5, 6, 10, 20, 30` |
| **Postfixe** | Gauche → Droite → Racine | Supprimer/Calculer | `4, 1, 6, 5, 10, 30, 20` |

> **💡 Astuce :** Pour un BST, utilisez toujours le parcours **infixe** pour obtenir les valeurs triées !

---

<div align="center">
  <b>🌳 Maîtrisez les arbres binaires pour devenir un meilleur programmeur ! 🚀</b>
</div>
