
/** @file Cjt_Usuaris.cc
    @brief Implementació de la classe Cjt_Usuaris
  
*/

#include <iostream>
#include "Cjt_Usuaris.hh"
using namespace std;

//Constructora

Cjt_Usuaris::Cjt_Usuaris() {}

//Modificadora

void Cjt_Usuaris::alta_usuari(string& nom_usuari) {
    Usuari user(nom_usuari);
    cjt_usuaris.insert(make_pair(nom_usuari, user));
}

void Cjt_Usuaris::baixa_usuari(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    cjt_usuaris.erase(it);
}

void Cjt_Usuaris::inscriure_curs_usuari(string& nom_usuari, int c) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.inscribir_curso(c);
}

void Cjt_Usuaris::genera_enviables(string& nom_usuari, list<string>& sessions, Cjt_Sessions& cjt_sessions) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    
    list<string>::iterator it3;
    for (it3 = sessions.begin(); it3 != sessions.end(); ++it3) {
        string p_arrel = cjt_sessions.buscar_arrel((*it3));
        (*it).second.actualitzar_problemes_enviables(p_arrel, (*it3), cjt_sessions);
    }
}

void Cjt_Usuaris::envio_usuari(string& nom_usuari, string& nom_problema, int& result, string& nom_sessio, Cjt_Sessions& cjt_sessions) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.envio(nom_problema, result, nom_sessio, cjt_sessions);
}

void Cjt_Usuaris::treure_curs(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.inscribir_curso(0);
}

//Consultora

int Cjt_Usuaris::consultar_mida() const {
    // Retorna la mida del camp "cjt_usuaris".
    return cjt_usuaris.size();
}

int Cjt_Usuaris::curs_usuari(const string& nom_usuari) {
    int c;
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    c = (*it).second.consultar_curs_usuari();
    return c;
}

int Cjt_Usuaris::consulta_pe(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    return (*it).second.consultar_nombre_problemes_enviables();
}

//Cerca

bool Cjt_Usuaris::cerca_usuari(const string& nom_usuari) const {
    map<string, Usuari>::const_iterator it;
    it = cjt_usuaris.find(nom_usuari);
    if (it != cjt_usuaris.end()) return true;
    return false;
    // nom_usuari no es troba al conjunt d'usuaris
}

//Lectura i Escriptura

void Cjt_Usuaris::llegir() {
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string nom_usuari;
        cin >> nom_usuari;
        Usuari user(nom_usuari);
        cjt_usuaris.insert(make_pair(nom_usuari, user));
    }
}

void Cjt_Usuaris::escriure() const {
    map<string, Usuari>::const_iterator it;
    for (it = cjt_usuaris.begin(); it != cjt_usuaris.end(); ++it) {
        (*it).second.escriure();
    }
}

void Cjt_Usuaris::escriure_usuari(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.escriure();
}


void Cjt_Usuaris::problemes_resolts_usuari(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.consultar_problemes_resolts();
}

void Cjt_Usuaris::problemes_enviables_usuari(string& nom_usuari) {
    map<string, Usuari>::iterator it;
    it = cjt_usuaris.find(nom_usuari);
    (*it).second.consultar_problemes_enviables();
}
