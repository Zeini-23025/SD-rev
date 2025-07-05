
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;

    cout << "Valeur de x : " << x << endl;
    cout << "Adresse de x : " << &x << endl;
    cout << "Pointeur ptr : " << ptr << endl;
    cout << "Valeur pointée par ptr : " << *ptr << endl;

    *ptr = 20;
    cout << "Nouvelle valeur de x via pointeur : " << x << endl;

    return 0;
}
