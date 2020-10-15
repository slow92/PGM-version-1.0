#ifndef PGM_H
#define PGM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struktura{
	char typr[5];
	char nazwa[20];
	int szarosc;
	int wysokosc;
	int szerokosc;
	int **tablica;// wskaŸnik do tablicy
	int mm;
	int nn;
}s;
void wczytaj();
void zapisz();
void odwroc();
void jasnosc();
void piksel();
void histogram();
void progowanie();
void negatyw();
void usun();
#endif
