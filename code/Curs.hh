
/** @file Curs.hh
    @brief Especificació de la classe Curs       
    Tipus de modul: dades.
    Descripcio del tipus: Cada curs té un valor enter entre 1 i N que l'identifica. Un curs està format per un subconjunt de sessions diferents del repositori, amb la restricció que la intersecció entre qualsevol parell de sessions del curs és buida.
  
*/

#ifndef CURS_HH
#define CURS_HH

#include "Sessio.hh"
#include "Cjt_Sessions.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#include <map>
#include <vector>
#endif

/** @class Curs
    @brief Representa un Curs
  
*/

class Curs {
    
private:
    int numeroN;
    int usuaris_done;
    int usuaris_inscrits;
    int nombre_de_sessions;
    
    list <string> cjt_sessions;
    vector<string> vS;
    map<string, int> mapa;
    
public:
    //Constructores
    
    
    /** @brief Creadora per defecte.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del curs = n.
     \post El resultat és un curs biut amb identificador n.
     
    */
    
    Curs(int n);
    
    //Modficadores
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post Actualitza el nombre d'usuaris que han completat el curs.
     
     */
    
    void actualitzar_usuaris_done();
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparat al canal estàndard d'entrada un enter que determina si s'ha inscrit un usuari o si un usuari ha finalitzat el curs.
     \post Actualitza el nombre d'usuaris que estan inscrits al curs.
     
     */
    
    void actualitzar_usuaris_inscrits(int n);
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparats al canal estàndard d'entrada el cjt de sessions, el nom de la sessió i un int i.
     \post El resultat indica si algun problema s'ha repetit en la creació del curs.
     
     */
    
    bool crear_mapa(Cjt_Sessions& cjt_sesion, string& nom_sessio, int i);
    
    //Consultores
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nom del paràmetre implícit.
     
     */
    
    int consultar_numeroN();
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nombre d'usuaris que han completat el curs.
     
     */
    
    int consultar_usuaris_done() const;
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nombre d'usuaris que estan inscrits al curs.
     
     */
    
    int consultar_usuaris_inscrits() const;
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nombre de problemes que componen el curs.
     
     */
    
    int consultar_nombre_de_problemes() const;
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nombre de sessions que componen el curs.
     
     */
    
    int consultar_nombre_sessions() const;
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna la llista de problemes que componen el curs.
     
     */
    
    list<string> consultar_sessions();
    
    
    /** @brief Operació de consulta.
     \pre <em>Cert<em>.
     \post Es retorna el nom de la iessima sessió;
     
     */
    
    string consultar_i_sessio(int i) const;
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del problema nom_problema a consultar a quina sessió pertany.
     \post Es retorna l'identificador de la sessió a la qual pertany el problema nom_problema.
     
     */
    
    string searchS(string& nom_problema);
    
    
    //Cerca
    
    /** @brief Operació de cerca.
      \pre Hi ha preparat al canal estàndard d'entrada un string amb el nom de la sessió a buscar.
      \post El resultat indica si existeix una sessió al paràmetre implícit amb identificador = nom_sessio.
      
     */
    
    bool cerca_sessio(string& nom_sessio);
    
    /** @brief Operació de cerca.
      \pre Hi ha preparat al canal estàndard d'entrada un string amb el nom del problema a buscar.
      \post El resultat indica si existeix un problema al paràmetre implícit amb identificador = nom_problema.
      
     */
    
    bool cerca_problema_curs(string& nom_problema);
    
    //Lectura i escriptura
    
    
    /** @brief Operació de lectura.
     \pre <em>Cert<em>.
     \post El paràmetre implícit passa a tenir les sessions llegides del canal estàndard d'entrada.
     
     */
    
    void llegir();
    
    
    /** @brief Operació de lectura.
     \pre Hi ha preparat al canal estàndard d'entrada el conjunt de sessions.
     \post El resultat indica si el nou curs s'ha format correctament.
     
     */
    
    bool llegir_nou(Cjt_Sessions& cjt_sesions);
    
    /** @brief Operació d'escriptura.
     \pre <em>Cert<em>.
     \post S'han escrit els atributs del paràmetre implícit al canal estàndard de sortida.
     
     */
    
    void escriure();
    
};
#endif
