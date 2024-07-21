
/** @file Problema.cc
    @brief Implementació de la classe Problema
  
*/

#include "Problema.hh"
#include <iostream>

//Constructora

Problema::Problema() {
    total_submisions = 0;
    total_correct_submisions = 0;
    ratio = 1;
}

Problema::Problema(string& nom_problema) {
    nom = nom_problema;
    total_submisions = 0;
    total_correct_submisions = 0;
    ratio = 1;
}

Problema::Problema(string& nom_problema, int env) {
    nom = nom_problema;
    total_submisions = env;
}

//Modificadora

void Problema::incrementar_total_submisions() {
    ++total_submisions;
}

void Problema::incrementar_total_correct_submisions() {
    ++total_correct_submisions;
}

void Problema::actualizar_ratio() {
    ratio = (total_submisions + 1.0)/(total_correct_submisions + 1.0);
}

//Consultora

string Problema::consultar_nom() const {
    // Retorna el valor del camp "nom" del problema corresponent.
    return nom;
}

int Problema::consultar_total_submisions() const {
    // Retorna el valor del camp "total_submisions" del problema corresponent.
    return total_submisions;
}

int Problema::consultar_total_correct_submisions() const {
    // Retorna el valor del camp "total_correct_submisions" del problema corresponent.
    return total_correct_submisions;
}

double Problema::consultar_ratio() const {
    // Retorna el valor del camp "ratio" del problema corresponent.
    return ratio;
}

//Lectura i Escriptura

void Problema::llegir() {
    cin >> nom;
}

void Problema::escriure() const {
    cout << nom << '(' << total_submisions << ',' << total_correct_submisions << ',' << ratio << ')' << endl;
}

void Problema::escriure_pe() const {
    cout << nom << '(' << total_submisions << ')' << endl;
}
