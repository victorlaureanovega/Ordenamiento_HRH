#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

void hrh(vector<int>& arreglo){
    int a = 0;
    int b = arreglo.size() - 1;
    while (a <= b){
        int minimo = a;
        int maximo = a;
        for (int i = a; i <= b; i++) {
            if (arreglo[i] < arreglo[minimo]){
                minimo = i;
            }
            if (arreglo[i] > arreglo[maximo]){
                maximo = i;
            }
        }
        swap(arreglo[a], arreglo[minimo]);
        if (maximo == a){
            maximo = minimo;
        }
        swap(arreglo[b], arreglo[maximo]);
        a++;
        b--;
    }
}

void seleccion(vector<int>& arreglo){
    int n = arreglo.size();
    for (int i = 0; i < n-1; i++){
        int minimo = i;
        for (int j = i+1; j < n; j++){
            if (arreglo[j] < arreglo[minimo]){
                minimo = j;
            }
        }
        swap(arreglo[i], arreglo[minimo]);
    }
}

void rapido(vector<int>& vector, int izquierda, int derecha){
    if (izquierda < derecha){
        int pivote = vector[derecha];
        int i = izquierda-1;
        for (int j = izquierda; j < derecha; j++){
            if (vector[j] < pivote){
                i++;
                swap(vector[i], vector[j]);
            }
        }
        swap(vector[i+1], vector[derecha]);
        int pi = i+1;
        rapido(vector, izquierda, pi-1);
        rapido(vector, pi+1, derecha);
    }
}

void probarArreglo(int tamaño){
    vector<int> arreglo;
    for (int i = 0; i < tamaño; ++i){
        arreglo.push_back(rand() % 1000);
    }
    
    // MEDICIONES DE TIEMPO
    cout << "Ordenamiento HRH\n";
    auto inicio = chrono::high_resolution_clock::now();
    hrh(arreglo);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = fin - inicio;
    cout << "Tiempo de ordenamiento: " << tiempo.count() << "segundos" << endl << endl;

    cout << "Ordenamiento por selección\n";
    inicio = chrono::high_resolution_clock::now();
    seleccion(arreglo);
    fin = chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    cout << "Tiempo de ordenamiento: " << tiempo.count() << "segundos" << endl << endl;

    cout << "Ordenamiento rápido\n";
    inicio = chrono::high_resolution_clock::now();
    rapido(arreglo, 0, arreglo.size()-1);
    fin = chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    cout << "Tiempo de ordenamiento: " << tiempo.count() << "segundos" << endl << endl;
}

int main(){
    cout << "ARREGLO DE 10 ELEMENTOS\n";
    probarArreglo(10);

    cout << "\nARREGLO DE 71 ELEMENTOS\n";
    probarArreglo(71);

    cout << "\nARREGLO DE 1000 ELEMENTOS\n";
    probarArreglo(1000);

    cout << "\nARREGLO DE 2023 ELEMENTOS\n";
    probarArreglo(2023);

    cout << "\nARREGLO DE 10000 ELEMENTOS\n";
    probarArreglo(10000);

    cout << "\nARREGLO DE 15093 ELEMENTOS\n";
    probarArreglo(15093);
}