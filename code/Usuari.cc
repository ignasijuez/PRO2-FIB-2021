
/** @file Usuari.cc
    @brief Implementació de la classe Usuari
  
*/

#include "Usuari.hh"
#include <iostream>

//Constructora

Usuari::Usuari() {
    enviaments_verds = 0;
    enviaments_totals = 0;
    curs = 0;
}

Usuari::Usuari(string& nom_usuari) {
    nom = nom_usuari;
    enviaments_verds = 0;
    enviaments_totals = 0;
    curs = 0;
}

//Modificadora

void Usuari::inscribir_curso (int c) {
    curs = c;
}

void Usuari::envio(string& nom_problema, int& result, string& nom_sessio, Cjt_Sessions& cjt_sessions) {
    actualitzar_enviaments_totals();
    problemes_intentats.insert(nom_problema);
    shippable_problems.actualitzar_stats(nom_problema, result);
    
    if (result == 1) {
        actualitzar_enviaments_verds();
        int env = shippable_problems.consultar_env(nom_problema);
        
        //agafem els enviaments del problema per poguer passarlo als problemes resolts amb els seus enviaments
        
        solved_problems.afegir_problema_dic(nom_problema, env);
        shippable_problems.borrar_problema(nom_problema);
        
        cjt_sessions.omplir_conjunts(nom_problema, nom_sessio, solved_problems, shippable_problems);
    }
    
}

void Usuari::actualitzar_enviaments_verds() {
    ++enviaments_verds;
}

void Usuari::actualitzar_enviaments_totals() {
    ++enviaments_totals;
}

void Usuari::actualitzar_problemes_enviables(string& nom_problema, string& nom_sessio, Cjt_Sessions& cjt_sessions) {
    
    cjt_sessions.omplir_conjunts(nom_problema, nom_sessio, solved_problems, shippable_problems);
}

//Consultora

string Usuari::consultar_nom_usuari() const {
    // Retorna el valor del camp "nom" de l'usuari corresponent.
    return nom;
}

int Usuari::consultar_curs_usuari() const {
    // Retorna el valor del camp "curs" de l'usuari corresponent.
    return curs;
}

int Usuari::consultar_problemes_intentats() const {
    // Retorna la mida del camp "problemes_intentats" de l'usuari corresponent.
    return problemes_intentats.size();
}

int Usuari::consultar_enviaments_verds() const {
    // Retorna el valor del camp "enviaments_verds" de l'usuari corresponent.
    return enviaments_verds;
}

int Usuari::consultar_enviaments_totals() const {
    // Retorna el valor del camp "enviaments_totals" de l'usuari corresponent.
    return enviaments_totals;
}

int Usuari::consultar_nombre_problemes_enviables() const {
    // Retorna la mida del camp "problemes_enviables" de l'usuari corresponent.
    return shippable_problems.consultar_mida();
}

//Cerca

bool Usuari::cerca_problema_resolt(string& nom_problema) {
    
    if (solved_problems.cerca_problema(nom_problema)) return true;
    else return false;
    // element no es troba en el map.
}

//Lectura i Escriptura

void Usuari::llegir() {
    cin >> nom;
}

void Usuari::escriure() const {
    cout << nom << '(' << enviaments_totals << ',' << enviaments_verds << ',' << consultar_problemes_intentats() << ',' << curs << ')' << endl;
}

void Usuari::consultar_problemes_resolts() {
    solved_problems.escriure();
}

void Usuari::consultar_problemes_enviables() {
    shippable_problems.escriure();
}
