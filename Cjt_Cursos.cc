
/** @file Cjt_Cursos.cc
    @brief Implementació de la classe Cjt_Cursos
  
*/

#include "Cjt_Cursos.hh"
#include <iostream>

//Constructora
    
Cjt_Cursos::Cjt_Cursos() {}

//Modificadora

void Cjt_Cursos::augmenta_usuaris_incrits(int c) {
    cjt_cursos[c-1].actualitzar_usuaris_inscrits(1);
}

void Cjt_Cursos::decrementa_usuaris_inscrits(int c) {
    cjt_cursos[c-1].actualitzar_usuaris_inscrits(-1);
}

void Cjt_Cursos::augmenta_usuaris_done(int c) {
    cjt_cursos[c-1].actualitzar_usuaris_done();
}

//Consultora

int Cjt_Cursos::consultar_mida() const {
    // Retorna la mida del camp "cjt_cursos".
    return cjt_cursos.size();
}

int Cjt_Cursos::consultar_n_sessions_curs(int c) const {
    return cjt_cursos[c-1].consultar_nombre_sessions();
}

int Cjt_Cursos::usuaris_inscrits(int c) const{
    return cjt_cursos[c-1].consultar_usuaris_inscrits();
}

string Cjt_Cursos::buscar_sessio(int c, string& nom_problema) {
    return cjt_cursos[c-1].searchS(nom_problema);
}

string Cjt_Cursos::consultar_idSessio_i(int c, int i) {
    return cjt_cursos[c-1].consultar_i_sessio(i);
}

list<string> Cjt_Cursos::list_sessions(int c) {
    list<string> aux = cjt_cursos[c-1].consultar_sessions();
    return aux;
}

// Cerca

bool Cjt_Cursos::cerca_curs(int c) const {
    if (c > 0 and c <= cjt_cursos.size()) return true;
    return false;
    // curs no es troba al conjunt de cursos
}

bool Cjt_Cursos::cerca_problema(int c, string& nom_problema) {
    return cjt_cursos[c-1].cerca_problema_curs(nom_problema);
}

//Lectura i Escriptura

void Cjt_Cursos::llegir(Cjt_Sessions& cjt_sesions) {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Curs a(i+1);
        if (a.llegir_nou(cjt_sesions)) cjt_cursos.push_back(a);
    }
}

bool Cjt_Cursos::llegir_nou_curs(Cjt_Sessions& cjt_sesions) {
    int i = cjt_cursos.size();
    Curs a(i+1);
    if (a.llegir_nou(cjt_sesions)) {
        cjt_cursos.push_back(a);
        return true;
    }
    return false;
    // el curs ha sigut mal format
}

void Cjt_Cursos::escriure() {
    for (int i = 0;  i < cjt_cursos.size(); ++i) {
        cjt_cursos[i].escriure();
    }
}

void Cjt_Cursos::escriure_curs(int c) {
    cjt_cursos[c-1].escriure();
}
