#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"



int main(){

char z;

system("cls");
do
{
    system("cls");
	printf("Wybierz dzialanie:\n0. Wyjscie\n1. Wczytaj obraz:\n2. Zapisz jako:\n3. Zamiana gory z dolem:\n4. Zmien jasnosc:\n5. Najmniejsza i najwieksza warotsc piksela:\n6. Histogram:\n7. Progowanie:\n8. Negatyw:\n9. Usun plik\n");
	scanf("%c",&z);
        switch(z)
        {
            case '1':
                wczytaj();
            break;
//
//zapisuje plik
//
            case '2':
                zapisz();
            break;
//odwrocenie
            case '3':
                odwroc();
            break;
//Rozjasnienie, lub przyciemnienie
            case '4':
                jasnosc();
            break;
//najwieksza i najmniejsza wartosc obrazu
            case '5':
                piksel();
            break;
//histogram
            case '6':
                histogram();
            break;
//Progowanie
            case '7':
                progowanie();
            break;
//negatyw
            case '8':
                negatyw();
            break;
//usuwanie pliku
            case '9':
                usun();
            break;
        }
//konic petli i programu
} while (z>0);

return 0;
}
