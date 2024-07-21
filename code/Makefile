OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: program.o Cjt_Cursos.o Cjt_Sessions.o Cjt_Problemes.o Cjt_Usuaris.o Curs.o Sessio.o Problema.o Usuari.o
	g++ -o program.exe program.o Cjt_Cursos.o Cjt_Sessions.o Cjt_Problemes.o Cjt_Usuaris.o Curs.o Sessio.o Problema.o Usuari.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_Cursos.o: Cjt_Cursos.cc Cjt_Cursos.hh
	g++ $(OPCIONS) -c Cjt_Cursos.cc
	
Cjt_Sessions.o: Cjt_Sessions.cc Cjt_Sessions.hh
	g++ $(OPCIONS) -c Cjt_Sessions.cc

Cjt_Problemes.o: Cjt_Problemes.cc Cjt_Problemes.hh
	g++ $(OPCIONS) -c Cjt_Problemes.cc

Cjt_Usuaris.o: Cjt_Usuaris.cc Cjt_Usuaris.hh
	g++ $(OPCIONS) -c Cjt_Usuaris.cc
	
Curs.o: Curs.cc Curs.hh
	g++ $(OPCIONS) -c Curs.cc
	
Sessio.o: Sessio.cc Sessio.hh
	g++ $(OPCIONS) -c Sessio.cc
	
Problema.o: Problema.cc Problema.hh
	g++ $(OPCIONS) -c Problema.cc
	
Usuari.o: Usuari.cc Usuari.hh
	g++ $(OPCIONS) -c Usuari.cc
	
practica.tar: Makefile DoxyfileOP program.cc Cjt_Cursos.cc Cjt_Cursos.hh Cjt_Sessions.cc Cjt_Sessions.hh Cjt_Problemes.cc Cjt_Problemes.hh Cjt_Usuaris.cc Cjt_Usuaris.hh Curs.cc Curs.hh Sessio.cc Sessio.hh Problema.cc Problema.hh Usuari.cc Usuari.hh BinTree.hh
	tar -cvf practica.tar Makefile DoxyfileOP program.cc Cjt_Cursos.cc Cjt_Cursos.hh Cjt_Sessions.cc Cjt_Sessions.hh Cjt_Problemes.cc Cjt_Problemes.hh Cjt_Usuaris.cc Cjt_Usuaris.hh Curs.cc Curs.hh Sessio.cc Sessio.hh Problema.cc Problema.hh Usuari.cc Usuari.hh BinTree.hh

clean:
	rm *.o
	rm *.exe
	rm *.gch
