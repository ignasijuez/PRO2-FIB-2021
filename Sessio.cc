
/** @file Sessio.cc
    @brief Implementació de la classe Sessio
  
*/

#include "Sessio.hh"
#include <iostream>

//Constructora

Sessio::Sessio() {
    BinTree<string> exercicis;
    list<string> problems;
}

Sessio::Sessio(string& nom_sessio) {
    nom = nom_sessio;
    llegir_arbre(exercicis, problems, mapa_problemes, vP);
}

//Consultora

string Sessio::consultar_nom_sessio() const {
    // Retorna el valor del camp "nom" de la sessio corresponent.
    return nom;
}

int Sessio::consultar_mida (const BinTree<string>& a) {
    // Retorna la mida del camp "exercicis" de la sessio corresponent.
    int x;
    if (a.empty()) x = 0;
    else x = consultar_mida(a.left()) + consultar_mida(a.right()) + 1;
    return x;
}

string Sessio::consultar_arrel() const {
    // Retorna el valor de l'arrel del camp "exercicis" de la sessio corresponent.
    return exercicis.value();
}

pair<string, string> Sessio::fills_sessio(string& nom_problema) {
    pair<string, string> fills;
    fills.first = fills.first = "0";
    
    // parell <string, string> "buit", el passem per referencia a la funcio i_fills_sessio la qual
    // omplirà aquest valors
    
    i_fills_sessio(exercicis, nom_problema, fills);
    return fills;
}

bool Sessio::i_fills_sessio(const BinTree<string>& a, string& nom_problema, pair<string, string>& par) {
    
    if (a.empty()) return false;
    else if (a.value() == nom_problema) {
        // s'ha trobat en l'arbre el problema resolt
        // ara toca agafar els fills en cas que no siguin buits. Si ho son, agafem un 0.
        if (a.left().empty()) par.first = "0";
        else par.first = a.left().value();
        if (a.right().empty()) par.second = "0";
        else par.second = a.right().value();
        return true;
    }
    else {
        // el valor de l'arbre no era = al problema buscat
        // ara toca mirar el subarbre esquerra i en cas de no trobar-lo en el subarbre esquerra
        // ho buscarem en el subarbre dret.
        return i_fills_sessio(a.left(), nom_problema, par) or i_fills_sessio(a.right(), nom_problema, par);
    }
    
    return false;
}

int Sessio::consultar_n_problemes() {
    // Retorna la mida del camp "problems" de la sessio corresponent.
    return problems.size();
}

string Sessio::consultar_problema_i(int i) {
    // Retorna el valor i del camp "vP" de la sessio corresponent.
    return vP[i];
}

//Cerca

bool Sessio::buscar_mapa(string& nom_problema) {
    map<string, int>::iterator it;
    it = mapa_problemes.find(nom_problema);
    if (it != mapa_problemes.end()) return true;
    return false;
    //element no es troba en el map
}

//Lectura i Escriptura

void Sessio::llegir() {
    cin >> nom;
    llegir_arbre(exercicis, problems, mapa_problemes, vP);
}

void Sessio::escriure() const {
    cout << nom << ' ' << consultar_mida(exercicis) << ' ';
    escriure_arbre(exercicis);
    cout << endl;
}

void Sessio::llegir_arbre(BinTree<string>& a, list<string>& problems, map<string, int>& mapa, vector<string>& vP) {
    
    // Simplement llegeix tots els components del arbre tenint en compte que si 
    // l'identificador és zero es tracta d'un problema "marca" i no és necessari continuar llegint.
    
    string nom_problema;
    cin >> nom_problema;
    if (nom_problema != "0") {
        // Aprofitem per omplir els atributs de la sessio.
        problems.push_back(nom_problema);
        mapa.insert(make_pair(nom_problema, 0));
        vP.push_back(nom_problema);
    }
    
    if (nom_problema != "0") {
        BinTree<string> a1;
        BinTree<string> a2;
        
        llegir_arbre(a1, problems, mapa, vP);
        llegir_arbre(a2,problems, mapa, vP);
        a = BinTree<string> (nom_problema, a1, a2);
    }
}

void Sessio::escriure_arbre(const BinTree<string>& a) {
    if (not a.empty()) {
        cout << '(';
        escriure_arbre(a.left());
        escriure_arbre(a.right());
        cout << a.value();
        cout << ')';
    }
}


void Sessio::actualitza_prbl_env(string& nom_problema, Cjt_Problemes& resolts, Cjt_Problemes& enviables) {
    
    if (not resolts.cerca_problema(nom_problema)) {
        if (nom_problema != "0") enviables.afegir_problema(nom_problema);
    }
    else {
        // element es troba en el map.
        // ara toca buscar els seus dos fills i fer una crida recursiva per cada un d'ells.
        pair<string, string> fills = fills_sessio(nom_problema);
        actualitza_prbl_env(fills.first, resolts, enviables);
        actualitza_prbl_env(fills.second, resolts, enviables);
    }
    
}
