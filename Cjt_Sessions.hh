
/** @file Cjt_Sessions.hh
    @brief Especificació de la classe Cjt_Sessions
  
*/

#ifndef CJT_SESSIONS_HH
#define CJT_SESSIONS_HH

#include "Sessio.hh"
#include "Cjt_Problemes.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/** @class Cjt_Sessions
    @brief Representa un Conjunt de Sessions
  
*/

class Cjt_Sessions {
    
private:
    map<string, Sessio> cjt_sessions;
    
    
public:
    
    //Constructora
    
    
    /** @brief Creadora per defecte.
     \pre <em>Cert<em>.
     \post El resultat és un conjunt de sessions buit.
    
    */
    
    Cjt_Sessions();
    
    //Modificadora
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post S'ha afegit la sessio amb identificador = nom, al conjunt de sessions.
     
     */
    
    void afegir_sessio(string& nom);
    
    
    /** @brief Operació Modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del problema, el nom de la sessio a la qual pertany el problema, el conjunt de problemes resolts i el conjunt de problemes enviables.
     \post Els conjunts de problemes enviables i resolts han sigut modificats segons les circumstancies. 
     
     */
    
    void omplir_conjunts(string& nom_problema, string& nom_sessio, Cjt_Problemes& resolts, Cjt_Problemes& enviables);
    
    //Consultora
    
    
    /** @brief Consultora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post Es retorna la mida del conjunt de sessions.
     
    */
    
    int consultar_mida() const;
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió = nom_sessio a consultar.
     \post Es retorna el nombre de prolemes de la sessió nom_sessio.
     
     */
    
    int n_problemes(string& nom_sessio);
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió = nom_sessio a consultar i un int i.
     \post Es retorna el nom del problema en la posició i de la sessió nom_sessio.
     
     */
    
    string problema_i(string& nom_sessio, int i);
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió = nom_sessio a consultar.
     \post Es retorna el nom del problema arrel de la sessio nom_sessio.
     
     */
    
    string buscar_arrel(string& nom_sessio);
    
    
    /** @brief Operació de consulta.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió = nom_sessio i el prolema a buscar en aquesta sessió.
     \post Es retornen els fills del problema en la sessió nom_sessio.
     
     */
    
    pair<string, string> fills(string& nom_sessio, string& nom_problema);
    
    //Cerca
    
    /** @brief Operació de cerca.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió a buscar.
     \post El resultat indica si existeix una sessió al paràmetre implícit amb identificador = nom_sessio.
     
     */
    
    bool cerca_sessio(string& nom_sessio) const;
    
    //Lectura i Escriptura
    
    
    /** @brief Operació de lectura.
      \pre <em>Cert<em>.
      \post El paràmetre implícit conté el conjunt de sessions llegides del canal estàndard d'entrada.
     
     */
    
    void llegir();
    
    
    /** @brief Operació d'escriptura.
     \pre <em>Cert<em>.
     \post S'han escrit pel canal estàndard de sortida les sessions de la plataforma, ordenades creixentment per nom i també per cada sessió el nombre de problemes que la formen i els noms de tals problemes seguint la seva estructura de postordre.
     
     */
    
    void escriure() const;
    
    
    /** @brief Operació d'escriptura.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de la sessió a escriure.
     \post S'imprimeix pel canal estàndard de sortida la sessió nom_sessio, el nombre de problemes que la formen i els noms de tals problemes seguint la seva estructura de postordre.
     
     */
    
    void escriure_sessio(string& nom_sessio);
    
};

#endif
