
/** @file Cjt_Usuaris.hh
    @brief Especificació de la classe Cjt_Usuaris
  
*/

#ifndef CJT_USUARIS_HH
#define CJT_USUARIS_HH

#include "Usuari.hh"
#include "Cjt_Sessions.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/** @class Cjt_Usuaris
    @brief Representa un Conjunt d'Usuaris
  
*/

class Cjt_Usuaris {
    
private:
    map<string, Usuari> cjt_usuaris;
    
    
public:
    
    //Constructora
    
    
    /** @brief Creadora per defecte.
        \pre <em>Cert<em>.
        \post El resultat és un conjunt d'usuaris buit.
    
    */
    
    Cjt_Usuaris();
    
    //Modificadora
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre  Hi ha preparat al canal estàndard d'entrada el nom del usuari a afegir al conjunt.
     \post S'ha afegit l'usuari amb identificador = nom_usuari, al conjunt d'usuaris.
     
     */
    
    void alta_usuari(string& nom_usuari);
    
    
    /** @brief Modificadora del paràmetre implícit.
     \pre  Hi ha preparat al canal estàndard d'entrada el nom del usuari a suprimir del conjunt.
     \post S'ha borrat l'usuari amb identificador = nom_usuari, del conjunt d'usuaris.
     
     */
    
    void baixa_usuari(string& nom);
    
    
    /** @brief Operació modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a inscriure al curs int c.
     \post L'usuari amb identificador = nom_usuari ha sigut inscrit el curs int c.
     
     */
    
    void inscriure_curs_usuari(string& nom_usuari, int c);
    
    
    /** @brief Operació modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a modificar, una llista amb els problemes a incorporar a problemes enviables del usuari, una llista de sessions i el cjt de sessions.
     \post Els conjunts de problemes resolts i enviables de l'usuari han sigut modificats.
     
     */
    
    void genera_enviables(string& nom_usuari, list<string>& sessions, Cjt_Sessions& cjt_sessions);
    
    
    /** @brief Operació modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a modificar, el nom del problema que ha realitzat un enviament i el resultat d'aquest enviament.
     \post Els conjunts de problemes resolts i enviables de l'usuari han sigut modificats.
     
     */
    
    void envio_usuari(string& nom_usuari, string& nom_problema, int& result, string& nom_sessio, Cjt_Sessions& cjt_sessions);
    
    
    /** @brief Operació modificadora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a modificar.
     \post L'usuari no està inscrit en cap curs.
     
     */
    
    void treure_curs(string& nom_usuari);
    
    
    //Consultora
    
    
    /** @brief Consultora del paràmetre implícit.
     \pre <em>Cert<em>.
     \post Es retorna la mida del conjunt d'usuaris.
     
    */
    
    int consultar_mida() const;
    
    /** @brief Operació consultora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a consultar.
     \post Es retorna el identificador del curs al que l'usuari esta inscrit.
     
     */
    
    int curs_usuari(const string& nom_usuari);
    
    
    /** @brief Operació consultora.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a consultar.
     \post Es retorna el nombre de problemes enviables de l'usuari.
     
     */
    
    int consulta_pe(string& nom_usuari);
    
    //Cerca
    
    
    /** @brief Operació de cerca.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a buscar.
     \post El resultat indica si existeix un usuari al paràmetre implícit amb identificador = nom_usuari.
     
     */
    
    bool cerca_usuari(const string& nom_usuari) const;
    
    
    //Lectura i Escriptura
    
    
    /** @brief Operació de lectura.
     \pre <em>Cert<em>.
     \post El paràmetre implícit conté el conjunt d'usuaris llegits del canal estàndard d'entrada.
     
     */
    
    void llegir();
    
    /** @brief Operació d'escriptura.
     \pre <em>Cert<em>.
     \post S'han escrit pel canal estàndard de sortida els usuaris del paràmetre implícit en ordre ascendent per identificador.
     
     */
    
    void escriure() const;
    
    /** @brief Operació d'escriptura.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a escriure.
     \post S'imprimeix pel canal estàndard de sortida l'usuari amb els seus paràmetres.
     
     */
    
    void escriure_usuari(string& nom_usuari);
    
    
    /** @brief Operació d'escriptura.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a escriure els seus problemes resolts.
     \post S'imprimeix pel canal estàndard de sortida els problemes resolts per l'usuari nom_usuari.
     
     */
    
    void problemes_resolts_usuari(string& nom_usuari);
    
    
    /** @brief Operació d'escriptura.
     \pre Hi ha preparat al canal estàndard d'entrada el nom de l'usuari a escriure els seus problemes enviables.
     \post S'imprimeix pel canal estàndard de sortida els problemes enviables de l'usuari nom_usuari.
     
     */
    
    void problemes_enviables_usuari(string& nom_usuari);
    
};

#endif
