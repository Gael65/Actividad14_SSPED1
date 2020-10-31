#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

//Definición
template <class T>
class ArregloDinamico {
private:
    T *arreglo;
    size_t tam;
    size_t contador;
    const static size_t MAX = 5;

    void expandir();
public:
    ArregloDinamico();
    ~ArregloDinamico();

    void insertarFinal(const T& v);
    void insertarInicio(const T& v);
    void insertar(const T& v, size_t p);

    void eliminar_inicio();
    void eliminar_final();
    void eliminar(size_t p);

    T* buscar(const T &v);
    ArregloDinamico<T*> buscar_todos(const T& v);

    size_t size();

    T operator[](size_t p) {
        return arreglo[p];
    }

    friend ArregloDinamico<T>& operator << (ArregloDinamico<T> &a, const T &v) {
        a.insertarFinal(v);

        return a;
    }
};

//Implementación
template <class T>
ArregloDinamico<T>::ArregloDinamico() {
    arreglo = new T[MAX];
    contador = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico() {
    delete[] arreglo;
}

template <class T>
void ArregloDinamico<T>::expandir() {
    T *nuevo = new T[tam + MAX];

    for(size_t i = 0; i < contador; i++) {
        nuevo[i] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

template <class T>
size_t ArregloDinamico<T>::size() {
    return contador;
}

template<class T>
void ArregloDinamico<T>::insertarFinal(const T &v) {
    if(contador == tam) {
        expandir();
    }

    arreglo[contador] = v;
    contador++;
}

template<class T>
void ArregloDinamico<T>::insertarInicio(const T &v) {
    if(contador == tam) {
        expandir();
    }

    for(size_t i = contador; i > 0; i--) {
        arreglo[i] = arreglo[i - 1];
    }  

    arreglo[0] = v;
    contador++; 
}

template<class T>
void ArregloDinamico<T>::insertar(const T& v, size_t p) {
    if(p >= contador) {
        cout << "Posición inválida..." << endl;
        return;
    }

    if(contador == tam) {
        expandir();
    }  

    for(size_t i = contador; i > p; i--) {
        arreglo[i] = arreglo[i - 1];
    }  

    arreglo[p] = v;
    contador++;
}

template<class T>
void ArregloDinamico<T>::eliminar_final() {
    if(contador == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }

    contador--;
}

template<class T>
void ArregloDinamico<T>::eliminar_inicio() {
    if(contador == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }

    for(size_t i = 0; i < contador - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }

    contador --;
}

template<class T>
void ArregloDinamico<T>::eliminar(size_t p) {
    if(contador == 0) {
        cout << "Arreglo vacío" << endl;
        return;
    }

    for(size_t i = p; i < contador - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }

    contador --;
}

template <class T>
T* ArregloDinamico<T>::buscar(const T &v) {
    for(size_t i = 0; i < contador; i++) {
        if(v == arreglo[i])
            return &arreglo[i];
    }
    return nullptr;
}

template <class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& v) {
    ArregloDinamico<T*> ptrs; 

    for(size_t i = 0; i < contador; i++) {
        if(v == arreglo[i])
            ptrs.insertarFinal(&arreglo[i]);
    }

    return ptrs;
}

#endif