# Makefile, dass einzelne Dateien kompiliert und verlinkt (inkl der root-files)
# Wird eine Datei/Klasse ge�ndert m�ssen die anderen Dateien/Klassen nicht neu kompiliert werden

#    Wahl des Compilers
# CXX = clang++
CXX = g++

#    DEBUG MODE
#    -Wall setzt (fast) alle Compilerwarnungen
#    -Werror setzt mehr Warnungen
#    -Wextra setzt noch mehr Warnungen
#    -ggdb erg�nzt debuginfos
CXXFLAGS = -ggdb -Wall -Wextra -std=c++11
# CXXFLAGS = -ggdb -Wall -Wextra -std=c++11 -I`root-config --incdir` ## um ROOT files zu includen
# CXXFLAGS = -ggdb -Wall -Wextra -I`root-config --incdir`


#    RELEASE MODE
#    -O3 Gr��tm�gliche Optimierung; -O1 und -O2 sind kleinere Optimierungen; -Os optimiert Gr��e; -Og mit Debuginfos
# CXXFLAGS = -march=native -O3 -std=c++11 -I`root-config --incdir`

.PHONY: clean

# LDFLAGS = `root-config --libs` -lEG
LDFLAGS =

music: musicmember.o main.o musicmember.h
	$(CXX) -o $@ $(CXXFLAGS) $^ $(LDFLAGS)

musicmember.o: musicmember.cxx musicmember.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cxx musicmember.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o
