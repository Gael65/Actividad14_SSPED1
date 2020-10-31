#include "computadora.h"

Computadora::Computadora() {}

Computadora::Computadora(const string &marca, const string &sistemaOperativo, int memoriaRam, const string &procesador){
    this -> marca = marca;
    this -> sistemaOperativo = sistemaOperativo;
    this -> memoriaRam = memoriaRam;
    this -> procesador = procesador;
}

void Computadora::setMarca(const string &v){
    marca = v;
}

void Computadora::setSO(const string &v){
    sistemaOperativo = v;
}

void Computadora::setMemoriaRam(int v){
    memoriaRam = v;
}

void Computadora::setProcesador(const string &v){
    procesador = v;
}

string Computadora::getMarca(){
    return marca;
}

string Computadora::getSO(){
    return sistemaOperativo;
}

int Computadora::getMemoriaRam(){
    return memoriaRam;
}

string Computadora::getProcesador(){
    return procesador;
}