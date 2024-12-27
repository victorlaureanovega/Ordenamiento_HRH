#include <iostream>
#include <vector>
using namespace std;

void imprimir(vector<int>& arreglo){
    for (int elemento : arreglo){
        cout << elemento << " ";
    }
}

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
    imprimir(arreglo);
}

int main(){
    vector<int> arreglo = {40, 1, 6, 7, 9, 10, 12, 90, 78};
    imprimir(arreglo);
    cout << endl;
    hrh(arreglo);
    return 0;
}