#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void llenar_arreglo(vector<int> &arr, int opcion);
void imprimir_for(const vector<int> &arr);
void imprimir_while(const vector<int> &arr);
int numero_medio(const vector<int> &arr);
void imprimir_pares(const vector<int> &arr);
void imprimir_primos(const vector<int> &arr);
int numero_mayor(const vector<int> &arr);
void ordenar_arreglo(vector<int> &arr);
bool es_primo(int num);

int main() {
    int tamano, opcion;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamano;

    cout << "Seleccione una opción de llenado (1: Automático, 2: Manual): ";
    cin >> opcion;

    vector<int> arreglo(tamano);
    llenar_arreglo(arreglo, opcion);

    imprimir_for(arreglo);
    imprimir_while(arreglo);
    cout << "Número en la posición media: " << numero_medio(arreglo) << endl;
    imprimir_pares(arreglo);
    imprimir_primos(arreglo);
    cout << "Número mayor: " << numero_mayor(arreglo) << endl;
    ordenar_arreglo(arreglo);
    imprimir_for(arreglo);

    return 0;
}

void llenar_arreglo(vector<int> &arr, int opcion) {
    srand(time(0));
    if (opcion == 1) {
        for (int &num : arr) {
            num = rand() % 101 + 100;
        }
    } else if (opcion == 2) {
        for (int &num : arr) {
            do {
                cout << "Ingrese un número entre 0 y 99: ";
                cin >> num;
            } while (num < 0 || num > 99);
        }
    }
}

void imprimir_for(const vector<int> &arr) {
    cout << "Arreglo (for): ";
    for (const int &num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void imprimir_while(const vector<int> &arr) {
    cout << "Arreglo (while): ";
    int i = 0;
    while (i < arr.size()) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
}

int numero_medio(const vector<int> &arr) {
    return arr[arr.size() / 2];
}

void imprimir_pares(const vector<int> &arr) {
    cout << "Números pares: ";
    for (const int &num : arr) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    }
    cout << endl;
}

void imprimir_primos(const vector<int> &arr) {
    cout << "Números primos: ";
    for (const int &num : arr) {
        if (es_primo(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
}

bool es_primo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int numero_mayor(const vector<int> &arr) {
    int mayor = arr[0];
    for (const int &num : arr) {
        if (num > mayor) {
            mayor = num;
        }
    }
    return mayor;
}

void ordenar_arreglo(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}
