all: p1

p1: wcat wgrep wzip wunzip
	g++ wcat.cpp -o wcat
	g++ wgrep.cpp -o wgrep
	g++ wzip.cpp -o wzip
	g++ wunzip.cpp -o wunzip

wcat: wcat.cpp
	g++ -c wcat.cpp

wgrep: wgrep.cpp
	g++ -c wgrep.cpp

wzip: wzip
	g++ -c wzip.cpp

wunzip: wunzip.cpp
	g++ -c wunzip.cpp

clean:
	rm -f *.o p1
