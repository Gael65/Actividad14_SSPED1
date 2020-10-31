#include <iostream>

#include "arreglo.h"
#include "computadora.h"

using namespace std;

int main() {

    ArregloDinamico<Computadora> computadoras;

    Computadora pc0("Apple", "macOS", 16, "Core I5");
    Computadora pc1("Toshiba", "Windows", 4, "Core I10");
    Computadora pc2("Apple", "Linux", 8, "Core I7");
    Computadora pc3("Asus", "Windows", 8, "Pentium");
    Computadora pc4("Apple", "macOs", 4, "Celeron");

    computadoras << pc0 << pc1 << pc2 << pc3 << pc4;

    Computadora pc5("Asus", "Windows", 8, "Pentium");
    Computadora pc6("Lenovo", "Windows", 2, "Core I5");

    cout << "Buscar computadora existente" << endl;
    Computadora *ptr = computadoras.buscar(pc5); //Buscar objeto existente
    if(ptr != nullptr)
        cout << *ptr << endl;
    else
        cout << "NO existe en el arreglo" << endl;

    cout << "Buscar computadora no existente" << endl;
    Computadora *ptr2 = computadoras.buscar(pc6); //Buscar objeto NO existente
    if(ptr2 != nullptr)
        cout << *ptr2 << endl;
    else
        cout << "NO existe en el arreglo" << endl << endl;

    
    Computadora pc7("Apple", "Linux", 8, "Core I7");

    cout << "Buscar todas las coincidencias de Apple en el arreglo" << endl;
    ArregloDinamico<Computadora*> ptrs = computadoras.buscar_todos(pc7);
    if(ptrs.size() > 0) {
        for (size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *c = ptrs[i];
            cout << *c;
        }
    }
    else
        cout << "No existen coincidencias..." << endl;

    return 0;
}