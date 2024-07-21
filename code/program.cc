#include "Cjt_Cursos.hh"
#include "Cjt_Sessions.hh"
#include "Cjt_Problemes.hh"
#include "Cjt_Usuaris.hh"
#ifndef NO_DIAGRAM
#include <list>
#endif

/** @file program.cc
    @brief Programa principal per l'exercici <em>Evaluator</em>.
*/

int main () {
    
    Cjt_Usuaris cjt_usuaris;
    Cjt_Cursos cjt_cursos;
    Cjt_Sessions cjt_sessions;
    Cjt_Problemes cjt_problemes;
    
    cjt_problemes.llegir();
    cjt_sessions.llegir();
    cjt_cursos.llegir(cjt_sessions);
    cjt_usuaris.llegir();
    
    string comando;
    cin >> comando;
    
    while (comando != "fin") {
        
        if (comando == "nuevo_problema" or comando == "np") {
            string nom_problema;
            cin >> nom_problema;
            cout << '#' << comando << ' ' << nom_problema << endl;;
            if (not cjt_problemes.cerca_problema(nom_problema)) {
                cjt_problemes.afegir_problema(nom_problema);
                cout << cjt_problemes.consultar_mida() << endl;
            }
            else cout << "error: el problema ya existe" << endl;
            
        }
        
        else if (comando == "nueva_sesion" or comando == "ns") {
            string nom_sessio;
            cin >> nom_sessio;
            cout << '#' << comando << ' ' << nom_sessio << endl;
            if (not cjt_sessions.cerca_sessio(nom_sessio)) {
                cjt_sessions.afegir_sessio(nom_sessio);
                cout << cjt_sessions.consultar_mida() << endl;
            }
            else cout << "error: la sesion ya existe" << endl;
            
        }
        
        else if (comando == "nuevo_curso" or comando == "nc") {
            cout << '#' << comando << endl;
            if (cjt_cursos.llegir_nou_curs(cjt_sessions)) {
                cout << cjt_cursos.consultar_mida() << endl;
            }
            else cout << "error: curso mal formado" << endl;
        }
        
        else if (comando == "alta_usuario" or comando == "a") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (not cjt_usuaris.cerca_usuari(nom_usuari)) {
                cjt_usuaris.alta_usuari(nom_usuari);
                cout << cjt_usuaris.consultar_mida() << endl;
            }
            else cout << "error: el usuario ya existe" << endl;
            
        }
        
        else if (comando == "baja_usuario" or comando == "b") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                int c = cjt_usuaris.curs_usuari(nom_usuari);
                if (c != 0) cjt_cursos.decrementa_usuaris_inscrits(c);
                cjt_usuaris.baixa_usuari(nom_usuari);
                cout << cjt_usuaris.consultar_mida() << endl;
            }
            else cout << "error: el usuario no existe" << endl;
            
        }
        
        else if (comando == "inscribir_curso" or comando == "i") {
            string nom_usuari;
            int c;
            cin >> nom_usuari >> c;
            cout << '#' << comando << ' ' << nom_usuari << ' ' << c << endl;
            
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                if (cjt_cursos.cerca_curs(c)) {
                    if (cjt_usuaris.curs_usuari(nom_usuari) == 0) {
                        cjt_usuaris.inscriure_curs_usuari(nom_usuari, c);
                        
                        cjt_cursos.augmenta_usuaris_incrits(c);
                        cout << cjt_cursos.usuaris_inscrits(c) << endl;
                    
                        list<string> sessions = cjt_cursos.list_sessions(c);
                        
                        cjt_usuaris.genera_enviables(nom_usuari, sessions, cjt_sessions);

                        
                        if (cjt_usuaris.consulta_pe(nom_usuari) == 0) {
                            cjt_usuaris.treure_curs(nom_usuari);
                            cjt_cursos.augmenta_usuaris_done(c);
                            cjt_cursos.decrementa_usuaris_inscrits(c);
                        }
                        
                        
                        
                        
                    }
                    else cout << "error: usuario inscrito en otro curso" << endl;
                }
                else cout << "error: el curso no existe" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        
        else if (comando == "curso_usuario" or comando == "cu") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                cout << cjt_usuaris.curs_usuari(nom_usuari) << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        
        else if (comando == "sesion_problema" or comando == "sp") {
            string nom_problema;
            int c;
            cin >> c >> nom_problema;
            cout << '#' << comando << ' ' << c << ' ' << nom_problema << endl;
            if (cjt_cursos.cerca_curs(c)) {
                if (cjt_problemes.cerca_problema(nom_problema)) {
                    if (cjt_cursos.cerca_problema(c, nom_problema)) {
                        cout << cjt_cursos.buscar_sessio(c, nom_problema) << endl;
                    }
                    else cout << "error: el problema no pertenece al curso" << endl;
                }
                else cout << "error: el problema no existe" << endl;
            }
            else cout << "error: el curso no existe" << endl;
        }
        
        else if (comando == "problemas_resueltos" or comando == "pr") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                cjt_usuaris.problemes_resolts_usuari(nom_usuari);
            }
            else cout << "error: el usuario no existe" << endl;
        }
        
        else if (comando == "problemas_enviables" or comando == "pe") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                if (cjt_usuaris.curs_usuari(nom_usuari) != 0) {
                    cjt_usuaris.problemes_enviables_usuari(nom_usuari);
                }
                else cout << "error: usuario no inscrito en ningun curso" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        
        else if (comando == "envio" or comando == "e") {
            string nom_usuari;
            string nom_problema;
            int result;
            cin >> nom_usuari >> nom_problema >> result;
            cout << '#' << comando << ' ' << nom_usuari << ' ' << nom_problema << ' ' << result << endl;
            
            cjt_problemes.actualitzar_stats(nom_problema, result);
            
            int c = cjt_usuaris.curs_usuari(nom_usuari);
            string idS = cjt_cursos.buscar_sessio(c, nom_problema);
            
            cjt_usuaris.envio_usuari(nom_usuari, nom_problema, result, idS, cjt_sessions);
              
            if (cjt_usuaris.consulta_pe(nom_usuari) == 0) {
                cjt_usuaris.treure_curs(nom_usuari);
                cjt_cursos.augmenta_usuaris_done(c);
                cjt_cursos.decrementa_usuaris_inscrits(c);
            }
            
        }
        
        else if (comando == "listar_problemas" or comando == "lp") {
            cout << '#' << comando << endl;
            cjt_problemes.escriure_ordenats();
        } 
        
        else if (comando == "escribir_problema" or comando == "ep") {
            string nom_problema;
            cin >> nom_problema;
            cout << '#' << comando << ' ' << nom_problema << endl;
            if (cjt_problemes.cerca_problema(nom_problema)) {
                cjt_problemes.escriure_problema(nom_problema);
            }
            else cout << "error: el problema no existe" << endl;
        }
        
        else if (comando == "listar_sesiones" or comando == "ls") {
            cout << '#' << comando << endl;
            cjt_sessions.escriure();
        }
        
        else if (comando == "escribir_sesion" or comando == "es") {
            string nom_sessio;
            cin >> nom_sessio;
            cout << '#' << comando << ' ' << nom_sessio << endl;
            if (cjt_sessions.cerca_sessio(nom_sessio)) {
                cjt_sessions.escriure_sessio(nom_sessio);
            }
            else cout << "error: la sesion no existe" << endl;
        }
        
        else if (comando == "listar_cursos" or comando == "lc") {
            cout << '#' << comando << endl;
            cjt_cursos.escriure();
        }
        
        else if (comando == "escribir_curso" or comando == "ec") {
            int c;
            cin >> c;
            cout << '#' << comando << ' ' << c << endl;
            if (cjt_cursos.cerca_curs(c)) {
                cjt_cursos.escriure_curs(c);
            }
            else cout << "error: el curso no existe" << endl;
        }
        
        else if (comando == "listar_usuarios" or comando == "lu") {
            cout << '#' << comando << endl;
            cjt_usuaris.escriure();
        }
        
        else if (comando == "escribir_usuario" or comando == "eu") {
            string nom_usuari;
            cin >> nom_usuari;
            cout << '#' << comando << ' ' << nom_usuari << endl;
            if (cjt_usuaris.cerca_usuari(nom_usuari)) {
                cjt_usuaris.escriure_usuari(nom_usuari);
            }
            else cout << "error: el usuario no existe" << endl;
        }
        
        cin >> comando;
    }
}
