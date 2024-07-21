
/** @file Usuari.hh
    @brief Especificació de la classe Usuari.       
    Tipus de modul: dades.
    Descripcio del tipus: Conte el nom de la persona, nº de problemes que ha intentat 
    resoldre (ha fet un enviament almenys), nº de problemes resolts satisfactoriament,
    nº d'enviaments totals, en quin curs esta inscrit (0 si en cap o N curs), 
    registre de problemes resolts en la plataforma (diversos cursos), 
    registre de problemes que pot accedir a resoldre perque ha resolt els seus prerequisits
  
*/

#ifndef USUARI_HH
#define USUARI_HH

#include "Cjt_Sessions.hh"
#include "Cjt_Problemes.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <set>
#include <string>
#include <list>
#include <iostream>
#endif
using namespace std;

/** @class Usuari
 * @brief Representa un Usuari
 
*/


class Usuari {
    
private:
    string nom;
    int enviaments_verds;
    int enviaments_totals;
    int curs;
    
    set<string> problemes_intentats;
    Cjt_Problemes solved_problems;
    Cjt_Problemes shippable_problems;
    
public:
    //Constructores
    
    /** @brief Creadora per defecte.
      \pre <em>Cert<em>.
      \post El resultat és un usuari buit.
    
    */
    
    Usuari();
    
    
    /** @brief Creadora amb nom.
      \pre <em>Cert<em>.
      \post El resultat és un usuari amb identificador = nom_usuari. 
     
    */
    
    Usuari(string& nom_usuari);
    
    //Modificadores
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post El curs del paràmetre implícit passa a ser el curs amb identificador = curs.
     
    */
    
    void inscribir_curso(int curs);

    
    /** @brief Modificadora del paràmetre implícit.
      \pre Hi ha preparats al canal estàndard d'entrada el nom del problema i el resultat de l'enviament.
      \post S'actualitzen les estadístiques del paràmetre implícit i del problema.
    
    */
    
    void envio(string& problema, int& result, string& nom_sessio, Cjt_Sessions& cjt_sessions);
    
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post S'actualitzen les estadístiques del paràmetre implícit.
    
    */
    
    void actualitzar_enviaments_verds();
    
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post S'actualitzen les estadístiques del paràmetre implícit.
    
    */
    
    void actualitzar_enviaments_totals();

    
    /** @brief Modificadora del paràmetre implícit.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del problema resolt, el nom de la sessió a la qual pertany i el conjunt de sessions.
      \post S'han afegeit els seus 2 fills al paràmetre implícit.
    
    */
    
    void actualitzar_problemes_enviables(string& nom_problema, string& nom_sessio, Cjt_Sessions& cjt_sessions);
    
    
    //Consultores
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna l'identificador del paràmetre implícit.
     
     */
    
    string consultar_nom_usuari() const;
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna l'identificador del curs al qual està inscrit el paràmetre implícit.
     
     */
    
    int consultar_curs_usuari() const;
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre de problemes intentats del paràmetre implícit. 
     
     */
    
    int consultar_problemes_intentats() const;
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre d'enviaments verds del paràmetre implícit. 
     
     */
    
    int consultar_enviaments_verds() const;
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre d'enviaments totals del paràmetre implícit. 
     
     */
    
    int consultar_enviaments_totals() const;
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre de problemes enviables del paràmetre implícit. 
     
     */
    
    int consultar_nombre_problemes_enviables() const;
    
    
    //Cerca
    
    /** @brief Operació de cerca.
      \pre Hi ha preparat al canal estàndard d'entrada el nom del problema a buscar.
      \post El resultat indica si el paràmetre implícit ha resolt el problema.
     
     */
    
    bool cerca_problema_resolt(string& nom_problema);
    
    
    //Lectura i escriptura
    
    
    /** @brief Operació de lectura.
      \pre <em>Cert<em>.
      \post El paràmetre implícit passa a tenir l'atribut llegit del canal estàndard d'entrada.
     
     */
    
    void llegir();
    
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'han escrit els atributs del paràmetre implícit al canal estàndard de sortida.
     
     */
    
    void escriure() const;
    
    
    /** @brief Consultora dels problemes resolts de l'usuari.
      \pre <em>Cert<em>.
      \post Es llisten en ordre creixent per identificador els problemes solucionats amb èxit del paràmetre implícit en la plataforma. 
     
     */
    
    void consultar_problemes_resolts();
    
    
    /** @brief Consultora dels problemes enviables de l'usuari.
      \pre <em>Cert<em>.
      \post Es llisten en ordre creixent per identificador els problemes que el paràmetre implícit no ha resolt en el curs que està inscrit actualment, però els quals ja pot realitzar enviaments perquè ha complert els requisits d'aquest.
     
     */
    
    void consultar_problemes_enviables();
    
};
#endif
