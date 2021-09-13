
/** @file Cjt_Problemes.cc
    @brief Implementació de la classe Cjt_Problemes
  
*/

#include "Cjt_Problemes.hh"
#include <iostream>
#include <algorithm>
#include <vector>

//Constructora

Cjt_Problemes::Cjt_Problemes() {
    map<string, Problema> cjt_problemes;
}

//Modificadora

void Cjt_Problemes::afegir_problema(string& nom_problema) {
    Problema problem(nom_problema);
    cjt_problemes.insert(make_pair(nom_problema, problem));
}

void Cjt_Problemes::afegir_problema_dic(string& nom_problema, int env) {
    Problema problem(nom_problema, env);
    cjt_problemes.insert(make_pair(nom_problema, problem));
}

void Cjt_Problemes::borrar_problema(string& nom_problema) {
    map<string, Problema>::iterator it;
    it = cjt_problemes.find(nom_problema);
    cjt_problemes.erase(it);
}

void Cjt_Problemes::actualitzar_stats(string& nom_problema, int result) {
    map<string, Problema>::iterator it;
    it = cjt_problemes.find(nom_problema);
    (*it).second.incrementar_total_submisions();
    if (result == 1) {
        (*it).second.incrementar_total_correct_submisions();
    }
    (*it).second.actualizar_ratio();
}

//Consultora

int Cjt_Problemes::consultar_mida() const {
    // Retorna la mida del "cjt_problemes".
    return cjt_problemes.size();
}

int Cjt_Problemes::consultar_env(string& nom_problema) {
    // Retorna la mida del "cjt_problemes".
    map<string, Problema>::iterator it;
    it = cjt_problemes.find(nom_problema);
    return (*it).second.consultar_total_submisions();
}

//Cerca

bool Cjt_Problemes::cerca_problema(const string& nom_problema) {
    map<string, Problema>::iterator it;
    it = cjt_problemes.find(nom_problema);
    if (it != cjt_problemes.end()) return true;
    return false;
    // nom_problema no es troba en el conjunt de problemes
}

//Comparadora

bool Cjt_Problemes::compare_problems (const Problema& a, const Problema& b) {
    
    if (a.consultar_ratio() == b.consultar_ratio()) {
        return a.consultar_nom() < b.consultar_nom();
    }
    return a.consultar_ratio() < b.consultar_ratio();
}

//Lectura i Escriptura
    
void Cjt_Problemes::llegir() {
    int P;
    cin >> P;
    
    for (int i = 0; i < P; ++i) {
        string s;
        cin >> s;
        Problema problem(s);
        cjt_problemes.insert(make_pair(s, problem));
    }
}
    
void Cjt_Problemes::escriure_ordenats() const {
    
    vector<Problema> aux2(cjt_problemes.size());
    map<string, Problema>::const_iterator it1;
    int i = 0;
    
    for (it1 = cjt_problemes.begin(); it1 != cjt_problemes.end(); ++it1) {
        aux2[i] = (it1 -> second);
        ++i;
    }
    
    sort(aux2.begin(), aux2.end(), compare_problems);
    
    for (int i = 0; i < aux2.size(); ++i) {
        cout << aux2[i].consultar_nom() << '(' << aux2[i].consultar_total_submisions() << ',' << aux2[i].consultar_total_correct_submisions() << ',' << aux2[i].consultar_ratio() << ')'<< endl;
    }     
}

void Cjt_Problemes::escriure_problema(const string& nom_problema) {
    map<string, Problema>::iterator it;
    it = cjt_problemes.find(nom_problema);
    (*it).second.escriure();
}

void Cjt_Problemes::escriure() const {
    
    //aquesta funcio es fa servir per escriure els problemes enviables i resolts d'un usuari,
    //ja que la manera en que s'han d'escriure varia de les altres.
    
    map<string, Problema>::const_iterator it;
    
    for (it = cjt_problemes.begin(); it != cjt_problemes.end(); ++it) {
        (*it).second.escriure_pe();
    }
}
