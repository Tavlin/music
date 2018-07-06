CC=g++

music.exe: musicmember.o
	$(CC) -std=c++14 -o music.exe musicmember.o

musicmember.o: musicmember.cxx
	$(CC) -std=c++14 -c musicmember.cxx

clean:
	rm musicmember.o music.exe
