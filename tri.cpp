
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void afficher(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;

    cout << "Avant tri : ";
    afficher(arr, n);

    selectionSort(arr, n);
    cout << "Tri par sélection : ";
    afficher(arr, n);

    int arr2[] = {5, 2, 9, 1, 3};
    insertionSort(arr2, n);
    cout << "Tri par insertion : ";
    afficher(arr2, n);

    int arr3[] = {5, 2, 9, 1, 3};
    bubbleSort(arr3, n);
    cout << "Tri à bulles : ";
    afficher(arr3, n);

    return 0;
}
