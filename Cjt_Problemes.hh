
/** @file Cjt_Problemes.hh
    @brief Especificació de la classe Cjt_Problemes
  
*/

#ifndef CJT_PROBLEMES_HH
#define CJT_PROBLEMES_HH

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Problemes
    @brief Representa un Conjunt de Problemes
  
*/

class Cjt_Problemes {
    
private:
    map<string, Problema> cjt_problemes;
    
    /** @brief Operació de comparació.
      \pre <em>Cert<em>.
      \post El resultat indica si el paràmetre a te el ratio més gran que el paràmetre b. En cas d'empat, indica qui te el nom més petit alfabèticament.
      
     */
    
    static bool compare_problems (const Problema& a, const Problema& b);
    
    
public:
    
    //Constructora
    
    
    /** @brief Creadora per defecte.
     \pre <em>Cert<em>.
     \post El resultat és un conjunt de problemes buit.
    
    */
    
    Cjt_Problemes();
    
    
    //Modificadora
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparat al canal d'entrada estàndard l'identificador del problema a afegir.
     \post S'ha afegit el problema amb identificador = nom_problema, al conjunt de problemes.
     
    */
    
    void afegir_problema(string& nom_problema);
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparat al canal d'entrada estàndard l'identificador del problema a afegir al diccionari i un int amb el nombre d'enviaments.
     \post S'ha afegit el problema amb identificador = nom_problema, al conjunt de problemes.
     
    */
    
    void afegir_problema_dic(string& nom_problema, int env);
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre Hi ha preparat al canal d'entrada estàndard l'identificador del problema a esborrar.
     \post S'ha esborrat el problema amb identificador = nom_problema, al conjunt de problemes.
     
    */
    
    void borrar_problema(string& nom_problema);
    
    
    /** @brief Operació modificadora.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del problema i el resultat del enviament al problema.
      \post S'han actualitzat les estadistiques del problema nom_problema.
     */
    
    void actualitzar_stats(string& nom_problema, int result);
    
    
    //Consultora
    
    
    /** @brief Consultora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post Es retorna la mida del conjunt de problemes.
     
    */
    
    int consultar_mida() const;
    
    
    /** @brief Consultora del paràmetre implícit.
     \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a consultar.
     \post Es retorna els enviaments al problema nom_problema del conjunt de problemes.
     
    */
    
    int consultar_env(string& nom_problema);
    
    
    //Cerca
    
    
    /** @brief Operació de cerca.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a buscar.
      \post El resultat indica si existeix un problema al paràmetre implícit amb identificador = nom_problema.
      
     */
    
    bool cerca_problema(const string& nom_problema);
    
    
    //Lectura i Escriptura
    
    
    /** @brief Operacio de lectura.
      \pre <em>Cert<em>.
      \post El paràmetre implícit conté el conjunt de problemes llegits del canal estàndard d'entrada.
     
     */
    
    void llegir();
    
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'han escrit pel canal estàndard de sortida els problemes del paràmetre implícit en ordre ascendent pel ratio, en cas d'empat ordenats ascendent pel nom.
      
     */
    
    void escriure_ordenats() const;
    
    
    /** @brief Operació d'escriptura.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a escriure.
      \post S'ha escrit pel canal estàndard de sortida el problema nom_problema.
     */
    
    void escriure_problema(const string& nom_problema);
    
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'ha escrit pel canal estàndard els problemes del conjunt ordenats alfabèticament i amb els seus enviaments.
     */
    
    void escriure() const;
    
};

#endif
