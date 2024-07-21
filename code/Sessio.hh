
/** @file Sessio.hh
    @brief Especificació de la classe Sessio.        
    Tipus de modul: dades.
    Descripcio del tipus: Conte un nom que la identifica (string) i està formada per un sub-conjunt de problemes diferents de la col·lecció estructurats segons unes relacions de prerequisit. A cada sessió hi ha un problema bàsic inicial que s'ha de resoldre abans que la resta de problemes de la mateixa sessió. Els problemes d'una sessió poden ser prerequisit directe de 0, 1 o 2 problemes de la mateixa sessió, i cada problema, excepte el bàsic inicial, té un únic problema que és prerequisit directe d'ell.
  
*/

#ifndef SESSIO_HH
#define SESSIO_HH

#include "Cjt_Problemes.hh"

#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include <list>
#include <map>
#include <vector>
#endif

/** @class Sessio
    @brief Representa una Sessio
  
*/

class Sessio {
    
private:
    string nom;
    BinTree<string> exercicis;
    list<string> problems;
    vector<string> vP;
    map<string, int> mapa_problemes;
    
    
    /** @brief Operació de lectura de l'arbre de problemes
        \pre <em>Esta prepatat pel canal estàndard d'entrada una seqüència de strings que representen l'arbre d'exercicis de la sessio</em>
        \post La sessió ara conté l'arbre d'exercicis.
    */
    
    static void llegir_arbre(BinTree<string>& a, list<string>& aux, map<string, int>& mapa, vector<string>& vP);
    
    
    /** @brief Operació d'escriptura d'un arbre
        \pre <em>Cert</em>
        \post S'ha escrit pel canal standard de sortida els exercicis de la sessió en postordre. 
    */
    
    static void escriure_arbre(const BinTree<string>& a);
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nombre de problemes que componen el paràmetre implícit.
    
    */
    
    static int consultar_mida (const BinTree<string>&);
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el resultat, parells de fills, per paràmetre de la funció.
    
    */
    
    static bool i_fills_sessio(const BinTree<string>& a, string& nom_problema, pair<string, string>& b);
    
    
public:
    
    //Constructores
    
    
    /** @brief Creadora per defecte.
     \pre <em>Cert<em>
     \post El resultat és una sessió buida.
    
    */
    
    Sessio();
    
    
    /** @brief Creadora d'una sessió amb nom.
     \pre <em>Cert<em>
     \post El resultat és una sessió amb identificador = nom_sessio. 
     
     */
    
    Sessio(string& nom_sessio);
    
    //Modificadores
    
    /** @brief Operació Modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada 
     \post S'ha escrit al canal estàndard de sortida el nom de la sessió, la seva mida i els problemes de la sessió en postordre.
    
    */
    
    void actualitza_prbl_env(string& nom_problema, Cjt_Problemes& resolts, Cjt_Problemes& enviables);
    
    //Consultores
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nom del paràmetre implícit.
    
    */
    
    string consultar_nom_sessio() const;
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nom de la arrel de la sessió del paràmetre implícit.
    
    */
    
    string consultar_arrel() const;
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a buscar.
     \post Es retorna un parell format pels dos fills del problema buscat.
    
    */
    
    pair<string, string> fills_sessio(string& nom_problema);
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>
     \post El resultat es el nombre de problemes del paràmetre implícit.
    
    */
    
    int consultar_n_problemes();
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada un int i.
     \post El resultat es el problema de la posicio i del vector de problemes del paràmetre implícit.
    
    */
    
    string consultar_problema_i(int i);
    
    
    //Cerca
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a buscar.
     \post El resultat indica si existeix el problema al paràmetre implícit.
    
    */
    
    bool buscar_mapa(string& nom_problema);
    
    //Lectura i escriptura
    
    
    /** @brief Operació de lectura.
     \pre <em>Cert<em>.
     \post El paràmetre implícit conté els problemes llegits del canal estàndard d'entrada seguint un recorregut en preordre de la seva estructura de prerequisits.
    
    */
    
    void llegir();
    
    
    /** @brief Operació d'escriptura.
     \pre <em>Cert<em>
     \post S'ha escrit al canal estàndard de sortida el nom de la sessió, la seva mida i els problemes de la sessió en postordre.
    
    */
    
    void escriure() const;
    
};
#endif
