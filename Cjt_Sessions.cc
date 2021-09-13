
/** @file Cjt_Sessions.cc
    @brief Implementació de la classe Cjt_Sessions
  
*/

#include "Cjt_Sessions.hh"
#include <iostream>

//Constructora

Cjt_Sessions::Cjt_Sessions() {
    map<string, Sessio> cjt_sessions;
}

//Modificadora
    
void Cjt_Sessions::afegir_sessio(string& nom_sessio) {
    Sessio a(nom_sessio);
    cjt_sessions.insert(make_pair(nom_sessio, a));
}

void Cjt_Sessions::omplir_conjunts(string& nom_problema, string& nom_sessio, Cjt_Problemes& resolts, Cjt_Problemes& enviables) {
    
    map<string, Sessio>::iterator it;
    it = cjt_sessions.find(nom_sessio);
    (*it).second.actualitza_prbl_env(nom_problema, resolts, enviables);
}


//Consultora


int Cjt_Sessions::consultar_mida() const {
    // Retorna la mida del "cjt_sessions".
    return cjt_sessions.size();
}

int Cjt_Sessions::n_problemes(string& nom_sessio) {
    map<string, Sessio>::iterator it;
    it = cjt_sessions.find(nom_sessio);
    return (*it).second.consultar_n_problemes();
}

string Cjt_Sessions::problema_i(string& nom_sessio, int i) {
    map<string, Sessio>::iterator it;
    it = cjt_sessions.find(nom_sessio);
    return (*it).second.consultar_problema_i(i);
}

string Cjt_Sessions::buscar_arrel(string& nom_sessio) {
    map<string, Sessio>::iterator it;
    it = cjt_sessions.find(nom_sessio);
    return (*it).second.consultar_arrel();
}

pair<string, string> Cjt_Sessions::fills(string& nom_sessio, string& nom_problema) {
    map<string, Sessio>::iterator it;
    pair<string, string> fills;
    it = cjt_sessions.find(nom_sessio);
    fills = (*it).second.fills_sessio(nom_problema);
    return fills;
}

//Cerca 

bool Cjt_Sessions::cerca_sessio(string& nom_sessio) const {
    map<string, Sessio>::const_iterator it;
    it = cjt_sessions.find(nom_sessio);
    if (it != cjt_sessions.end()) return true;
    return false;
    // sessio no es troba en el conjunt de sessions
}

//Lectura i Escriptura

void Cjt_Sessions::llegir() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        Sessio a;
        a.llegir();
        cjt_sessions.insert(make_pair(a.consultar_nom_sessio(), a));
    }
}

void Cjt_Sessions::escriure() const {
    map<string, Sessio>::const_iterator it;
    
    for (it = cjt_sessions.begin(); it != cjt_sessions.end(); ++it) {
        (*it).second.escriure();
    }
}

void Cjt_Sessions::escriure_sessio(string& nom_sessio) {
    map<string, Sessio>::const_iterator it;
    it = cjt_sessions.find(nom_sessio);
    (*it).second.escriure();
}
