
/** @file Problema.hh
    @brief Especificació de la classe Problema       
    Tipus de modul: dades.
    Descripcio del tipus: Cada problema té un nom que l'identifica (string). El nombre total d'enviaments realitzats al problema i quants d'ells han estat jutjats com a correctes.
    
  
*/

#ifndef PROBLEMA_HH
#define PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Problema
    @brief Representa un Problema
  
*/

class Problema {
    
private:
    string nom;
    int total_submisions;
    int total_correct_submisions;
    
    double ratio; // = (total_submisions +1)/(total_correct_submisions +1);
    
public:
    //Constructores
    
    
    /** @brief Creadora per defecte.
      \pre <em>Cert<em>.
      \post El resultat es un problema buit.
     
     */
    
    Problema();
    
    
    /** @brief Creadora amb nom.
      \pre <em>Cert<em>.
      \post El resultat es un problema amb identificador = nom_problema.
     
     */
    
    Problema(string& nom_problema);
    
    
    /** @brief Creadora amb nom i enviaments.
      \pre <em>Cert<em>.
      \post El resultat es un problema amb identificador = nom_problema i total_submisions = env.
     
     */
    
    Problema(string& nom_problema, int env);
    
    //Modificadores
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<m>.
      \post Incrementa els enviaments totals del paràmetre implícit.
     
    */
    
    void incrementar_total_submisions();
    
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<m>.
      \post Incrementa els enviaments verds totals enviats del paràmetre implícit.
     
    */
    
    void incrementar_total_correct_submisions();
    
    
    /** @brief Modificadora del paràmetre implícit.
      \pre <em>Cert<m>.
      \post Actualitza el ratio del paràmetre implícit.
     
    */
    
    void actualizar_ratio();
    
    
    //Consultores
    
    
    /** @brief Consultora del nom del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna l'identificador del paràmetre implícit. 
     
     */
    
    string consultar_nom() const;
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre d'enviaments totals al paràmetre implícit. 
     
     */
    
    int consultar_total_submisions() const;
    
    
    /** @brief Consultora del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el nombre d'enviaments totals verds del paràmetre implícit. 
     
     */
    
    int consultar_total_correct_submisions() const;
    
    /** @brief Consultora del ratio del paràmetre implícit.
      \pre <em>Cert<em>.
      \post Es retorna el ratio del paràmetre implícit. 
     
     */

    double consultar_ratio() const;
    
    //Lectura i escriptura
    
    
    /** @brief Operació de lectura.
      \pre <em>Cert<em>.
      \post El paràmetre implícit passa a tenir l'atribut llegit del canal estandard d'entrada.
     
     */
    
    void llegir();
    
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'han escrit els atributs del paràmetre implícit al canal estàndard de sortida. 
     
     */
    
    void escriure() const;
    
    
    /** @brief Operació d'escriptura.
      \pre <em>Cert<em>.
      \post S'han escrit els atributs del paràmetre implícit al canal estàndard de sortida . Aquesta escritura és de caracteristiques diferents. 
     
     */
    
    void escriure_pe() const;
    
};
#endif
