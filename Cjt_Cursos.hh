
/** @file Cjt_Cursos.hh
    @brief Especificació de la classe Cjt_Cursos
  
*/

#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

#include "Curs.hh"
#include "Cjt_Sessions.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <list>
#endif

/** @class Cjt_Cursos
    @brief Representa un Conjunt de Cursos
  
*/

class Cjt_Cursos {
    
private:
    vector<Curs> cjt_cursos;
    
public:
    
    //Constructora
    
    
    /** @brief Creadora per defecte.
     \pre <em>Cert<em>.
     \post El resultat és un conjunt de cursos buit.
    
    */
    
    Cjt_Cursos();
    
    //Modificadora
    
    
    /** @brief Operació modificadora.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a modificar.
      \post S'ha augmentat el nombre d'usuaris inscrits al curs c.
      
     */
    
    void augmenta_usuaris_incrits(int c);
    
    
    /** @brief Operació modificadora.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a modificar.
      \post S'ha decrementat el nombre d'usuaris inscrits al curs c.
      
     */
    
    void decrementa_usuaris_inscrits(int c);
    
    
    /** @brief Operació modificadora.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a modificar.
      \post S'ha augmentat el nombre d'usuaris que han realitzat el curs c.
      
     */
    
    void augmenta_usuaris_done(int c);
    
    
    //Consultora
    
    
    /** @brief Consultora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post Es retorna la mida del conjunt de cursos.
     
    */
    
    int consultar_mida() const;
    
    /** @brief Operació de consulta.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a consultar.
      \post Es retorna el nombre de sessions del curs c.
      
     */
    
    int consultar_n_sessions_curs(int c) const;
    
    
    /** @brief Operació de consulta.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a consultar.
      \post Es retorna el nombre d'usuaris inscrits al curs c.
      
     */
    
    int usuaris_inscrits(int c) const;
    
    
    /** @brief Operació de consulta.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs i el nom_problema.
      \post Es retorna l'identificador de la sessió a la qual pertany el nom_problema en el curs c.
      
     */
    
    string buscar_sessio(int c, string& nom_problema);
    
    
    /** @brief Operació de consulta.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a consultar i un int i.
      \post Es retorna el nom de la iessima sessió del curs c.
      
     */
    
    string consultar_idSessio_i(int c, int i);
    
    
    /** @brief Operació de consulta.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a consultar.
      \post Es retorna una llista amb els noms de les sessions del curs c.
      
     */
    
    list<string> list_sessions(int c);
    
    
    //Cerca
    
    
    /** @brief Operació de cerca.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a buscar.
     \post El resultat indica si existeix un curs al paràmetre implícit amb identificador = c.
     
     */
    
    bool cerca_curs(int c) const;
    
    
    /** @brief Operació de cerca.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs = c i el nom del problema nom_problema a buscar en aquest curs.
      \post El resultat indica si el problema pertany al curs c.
      
     */
    
    bool cerca_problema(int c, string& nom_problema);
    
    
    //Lectura i Escriptura
    
    
    /** @brief Operació de lectura.
      \pre Estan preparats al canal estàndard d'entrada el conjunt de sessions.
      \post El paràmetre implícit conté el conjunt de cursos llegits del canal estàndard d'entrada.
     
     */
    
    void llegir(Cjt_Sessions& cjt_sesions);
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparat al canal estàndard d'entrada el conjunt de sessions.
     \post El resultat indica si la seva intersecció de problemes és buida. En cas que ho sigui s'afegeix el curs al conjunt de cursos. Altrament on la intersecció no és buida, no s'afegeix el curs al conjunt.
     
     */
    
    bool llegir_nou_curs(Cjt_Sessions& cjt_sesions);
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'han escrit pel canal estàndard de sortida els cursos del paràmetre implícit ordenats creixentment per identificador i els paràmetres d'aquests.
      
     */

    void escriure();
    
    
    /** @brief Operació d'escriptura.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del curs a escriure.
      \post S'imprimeix pel canal estàndard de sortida les components del curs c.
      
     */
    
    void escriure_curs(int c);
    
};

#endif
