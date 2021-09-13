
/** @file Curs.cc
    @brief Implementació de la classe Curs
  
*/

#include "Curs.hh"
#include <iostream>

//Constructora

Curs::Curs(int n) {
    numeroN = n;
    usuaris_done = 0;
    usuaris_inscrits = 0;
    nombre_de_sessions = 0;
}

//Modificadora

void Curs::actualitzar_usuaris_done() {
    ++usuaris_done;
}

void Curs::actualitzar_usuaris_inscrits(int n) {
    usuaris_inscrits += n;
}

bool Curs::crear_mapa(Cjt_Sessions& cjt_sesions, string& nom_sessio, int i) {
    
    // Per cada problema l'inserim al diccionari com a clau i com valor un int i de la posicio
    // del vector Vs (vector de sessions), d'aquesta manera cada problema esta relacionat amb la sessio a la que pertany.
    
    map<string, int>::iterator it;
    int n = cjt_sesions.n_problemes(nom_sessio);
    for (int j = 0; j < n; ++j) {
        string nom_problema = cjt_sesions.problema_i(nom_sessio, j);
        it = mapa.find(nom_problema);
        if (it == mapa.end()) mapa.insert(make_pair(nom_problema, i));
        else return false;
    }
    return true;
}

//Consultora

int Curs::consultar_numeroN() {
    // Retorna el valor del camp "numeroN" del curs corresponent.
    return numeroN;
}

int Curs::consultar_usuaris_done() const {
    // Retorna el valor del camp "usuaris_done" del curs corresponent.
    return usuaris_done;
}

int Curs::consultar_usuaris_inscrits() const {
    // Retorna el valor del camp "usuaris_inscrits" del curs corresponent.
    return usuaris_inscrits;
}

int Curs::consultar_nombre_de_problemes() const {
    // Retorna la mida del diccionari del curs corresponent.
    return mapa.size();
}

int Curs::consultar_nombre_sessions() const {
    // Retorna el valor del camp "nombre_de_sessions" del curs corresponent.
    return nombre_de_sessions;
}

list<string> Curs::consultar_sessions() {
    list<string> aux;
    aux = cjt_sessions;
    return aux;
}

string Curs::consultar_i_sessio(int i) const {
    // Retorna el valor i del camp "vS" del curs corresponent.
    return vS[i];
}

string Curs::searchS(string& nom_problema) {
    map<string, int>::iterator it;
    it = mapa.find(nom_problema);
    return vS[(*it).second];
}

//Cerca

bool Curs::cerca_sessio(string& nom_sessio) {
    list<string>::iterator it;
    for (it = cjt_sessions.begin(); it != cjt_sessions.end(); ++it) {
        if ((*it) == nom_sessio) return true;
    }
    return false;
}

bool Curs::cerca_problema_curs(string& nom_problema) {
    map<string, int>::iterator it;
    it = mapa.find(nom_problema);
    if (it != mapa.end()) return true;
    return false;
    //element no es troba en el map
}

//Lectura i Escriptura

void Curs::llegir() {
    int Sc;
    cin >> Sc;
    nombre_de_sessions = Sc;
    for (int i = 0; i < Sc; ++i) {
        string nom_sessio;
        cin >> nom_sessio;
        vS.push_back(nom_sessio);
        cjt_sessions.push_back(nom_sessio);
    }
}

bool Curs::llegir_nou(Cjt_Sessions& cjt_sesions) {
    int Sc;
    cin >> Sc;
    nombre_de_sessions = Sc;
    for (int i = 0; i < Sc; ++i) {
        string nom_sessio;
        cin >> nom_sessio;
        vS.push_back(nom_sessio);
        cjt_sessions.push_back(nom_sessio);
        if (not crear_mapa(cjt_sesions, nom_sessio, i)) return false;
    }
    return true;
}

void Curs::escriure() {
    cout << numeroN << ' ' << usuaris_done << ' ' << usuaris_inscrits << ' ' << nombre_de_sessions << ' ';
    list<string>::iterator it;
    cout << '(';
    bool primer = true;
    for (it = cjt_sessions.begin(); it != cjt_sessions.end(); ++it) {
        if (primer) {
            cout << (*it);
            primer = false;
        }
        else cout << ' ' << (*it);
        
    }
    cout << ')' << endl;
}
