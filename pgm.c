#include "pgm.h"

void wczytaj(){
	char typ[]="P2";
	FILE* fp;
	int n,m;
	int a,b;
	int x;
	char nw[20];

puts("Wybierz plik .pgm:\n");
   scanf("%s",nw);
	if ((fp=fopen(nw, "r"))==NULL) {
     	printf ("Nie mogê otworzyæ pliku do odczytu!\n");
     	exit(1);
     	}
	fscanf(fp,"%s",s.typr);
	if(typ[0]!=s.typr[0]||typ[1]!=s.typr[1])
		{
			printf("Nieznany format zapisu pliku graficznego");
			exit(1);
				}
	fscanf(fp,"%s",s.nazwa);
	fscanf(fp,"%d %d",&n,&m);
	fscanf(fp,"%d",&s.szarosc);
	// rozmiar tablicy;
	if(s.tablica!=NULL)
    {
        for(a=0; a<s.nn; a++)
            free(s.tablica[a]); //uwolnienie pamieci
        free(s.tablica); //uwolnienie pamieci
        s.tablica = NULL;
    }

	s.tablica=(int**)malloc(n*sizeof(int*)); // alokacja pamiêci dla tablicy , wskaŸnik  zawiera adres pierwszego elementu
	 for(x = 0; x < n; ++x)
	     s.tablica[x] = (int*)malloc(m * sizeof(int));
	for(a=0;a<n;a++){
		for(b=0;b<m;b++){
			fscanf(fp,"%d",&s.tablica[a][b]);
		}
	}
	printf("\n");
	fclose(fp);
	s.mm=m-1;
	s.nn=n-1;
	s.szerokosc=m;
	s.wysokosc=n;
}
//
//
void zapisz(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b;
	char nw[20];

	puts("Zapisz jako:\n");
   scanf("%s",nw);
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ do zapisu!\n");
     	exit(1);
     	}
	fprintf(fp,"%s\n",s.typr);
	fprintf(fp,"%s\n",s.nazwa);
	fprintf(fp,"%d %d\n",s.wysokosc,s.szerokosc);
	fprintf(fp,"%d\n",s.szarosc);
	for(a=0;a<s.wysokosc;a++){
		for(b=0;b<s.szerokosc;b++){
			fprintf(fp,"%d ",s.tablica[a][b]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
//
//
void odwroc(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b;
	char nw[20];

	puts("Zapisz jako:\n");
	scanf("%s",nw);
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ pliku do zapisu!\n");
     	exit(1);
     	}
	fprintf(fp,"%s\n",s.typr);
	fprintf(fp,"%s\n",s.nazwa);
	fprintf(fp,"%d %d\n",s.wysokosc,s.szerokosc);
	fprintf(fp,"%d\n",s.szarosc);
	for(a=s.nn;a>=0;a--){
		for(b=s.mm;b>=0;b--){
			fprintf(fp,"%d ",s.tablica[a][b]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
//
//
void jasnosc(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b,c;
	char nw[20];

	puts("Zapisz jako:\n");
	scanf("%s",nw);
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ pliku do zapisu!\n");
     	exit(1);
     	}
     	printf("Podaj o jaka liczbe chcesz zmienic jasnosc obrazu \n");
     	scanf("%d",&c);
    for(a=0;a<s.wysokosc;a++){
		for(b=0;b<s.szerokosc;b++){
			s.tablica[a][b]=s.tablica[a][b]+c;
		}
    }
    fprintf(fp,"%s\n",s.typr);
	fprintf(fp,"%s\n",s.nazwa);
	fprintf(fp,"%d %d\n",s.wysokosc,s.szerokosc);
	fprintf(fp,"%d\n",s.szarosc);
    for(a=0;a<s.wysokosc;a++){
		for(b=0;b<s.szerokosc;b++){
			fprintf(fp,"%d ",s.tablica[a][b]);
		}
		fprintf(fp,"\n");
    }
    fclose(fp);
}
//
//
void piksel(){

    if(s.tablica==NULL) return;
	int a,b,t,v;

	v=s.tablica[0][0];
for(a=0;a<s.wysokosc;a++){
	for(b=0;b<s.szerokosc;b++){
		if(v<s.tablica[a][b])
		v=s.tablica[a][b];
	}
}
t=s.tablica[0][0];
for(a=0;a<s.wysokosc;a++){
	for(b=0;b<s.szerokosc;b++){
		if(t>s.tablica[a][b])
		t=s.tablica[a][b];
	}
}
printf("Najwieksza wartosc to %d, a najmniejsza %d\n",v,t);
}
//
//
void histogram(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b,t,v;
	char hi[20];

	puts("Zapisz jako: (.csv,lub .ods)\n");
	scanf("%s",hi);
	if ((fp=fopen(hi, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ pliku do zapisu!\n");
     	exit(1);
     	}
    for(t=0;t<=s.szarosc;t++){
		v=0;
		for(a=0;a<s.wysokosc;a++){
			for(b=0;b<s.szerokosc;b++){
				if(t==s.tablica[a][b])
				v++;
			}
		}
		if(v!=0)
		fprintf(fp,"%d %d\n",t,v);
    }
	fclose(fp);
}
//
//
void progowanie(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b,t,v;
	char nw[20];
	int mnw=0,mn=0,prog;

	puts("Zapisz jako:\n");
	scanf("%s",nw);
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyæ pliku do zapisu!\n");
     	exit(1);
     	}
    for(t=0;t<=s.szarosc;t++){
		v=0;
		for(a=0;a<s.wysokosc;a++){
			for(b=0;b<s.szerokosc;b++){
				if(t==s.tablica[a][b])
				v++;
			}
		}
		if(v!=0){
		mnw=mnw+t*v;
		mn=mn+v;
		}
    }
    prog=mnw/mn-60;

    fprintf(fp,"%s\n",s.typr);
	fprintf(fp,"%s\n",s.nazwa);
	fprintf(fp,"%d %d\n",s.wysokosc,s.szerokosc);
	fprintf(fp,"%d\n",s.szarosc);

    for(a=0;a<s.wysokosc;a++){
		for(b=0;b<s.szerokosc;b++){
			if(s.tablica[a][b]<prog){
				s.tablica[a][b]=0;
				fprintf(fp,"%d ",s.tablica[a][b]);
			}
			else {
				s.tablica[a][b]=255;
				fprintf(fp,"%d ",s.tablica[a][b]);
			}
		}
		fprintf(fp,"\n");
    }
    printf("%d\n",prog);
    fclose(fp);
}
//
//
void negatyw(){

    if(s.tablica==NULL) return;
	FILE* fp;
	int a,b;
	char nw[20];

	puts("Zapisz jako:\n");
	scanf("%s",nw);
	if ((fp=fopen(nw, "w"))==NULL) {
     	printf ("Nie mogê otworzyc pliku do zapisu!\n");
     	exit(1);
     	}
	fprintf(fp,"%s\n",s.typr);
	fprintf(fp,"%s\n",s.nazwa);
	fprintf(fp,"%d %d\n",s.wysokosc,s.szerokosc);
	fprintf(fp,"%d\n",s.szarosc);

    for(a=0;a<s.wysokosc;a++){
		for(b=0;b<s.szerokosc;b++){
				s.tablica[a][b]=255-s.tablica[a][b];
				fprintf(fp,"%d ",s.tablica[a][b]);
		}
		fprintf(fp,"\n");
    }
	fclose(fp);
}
//
//
void usun(){
	char nw[20];
	printf("Usun:\n");
	scanf("%s",nw);
	remove(nw);
}
