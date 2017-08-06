all : arp_spoof

arp_spoof : main.o str2hex.o common.o
	g++ -o arp_spoof main.o str2hex.o common.o -lpcap

main.o : main.cpp
	g++ -c -o main.o main.cpp

str2hex.o : str2hex.cpp
	g++ -c -o str2hex.o str2hex.cpp

common.o : common.cpp
	g++ -c -o common.o common.cpp

clean :
	rm -f *.o arp_spoof