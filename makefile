CC=g++

music.exe: musicmember.o main.o musicmember.h
	$(CC) -std=c++14 -o music.exe musicmember.o main.o


musicmember.o: musicmember.cxx musicmember.h
	$(CC) -std=c++14 -c musicmember.cxx

main.o: musicmember.o musicmember.h
	$(CC) -std=c++14 -c main.cxx

clean:
	rm musicmember.o music.exe main.o
