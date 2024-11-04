/*2. Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
A. dinamièki dodaje novi element na poèetak liste,
B. ispisuje listu,
C. dinamièki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.
*/
/*3. Prethodnom zadatku dodati funkcije:
A. dinamièki dodaje novi element iza odreðenog elementa,
B. dinamièki dodaje novi element ispred odreðenog elementa,
C. sortira listu po prezimenima osoba,
D. upisuje listu u datoteku,
E. èita listu iz datoteke.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct osoba;

typedef struct osoba* position;

struct osoba {
	char ime[10];
	char prezime[10];
	int gr;
	position Next;
};

void unosP(position);
void ispis(position);
position traziZadnji(position);
void unosK(position);
position traziPret(position);
position trazi(position);
void brisi(position);
void unosIza(position);
void sort(position);
void datUcitaj(position);
void datUpis(position);


int main()
{
	struct osoba head, * q;
	head.Next = NULL;
	char n = 1;
	char prez[10];

	while (n != '0')
	{
		printf("Unesite broj funkcije koju zelite obaviti:\n");
		printf("\tA-unos elementa na pocetak liste\n\tB-ispis liste\n\tC-unos elementa na kraj liste\n\tD-pretraga po prezimenu\n\tE-brisanje elementa iz liste\n");
		printf("\tF-ubacivanje novog elementa iza postojeceg elementa\n\tG-Ubacivanje novog elementa ispred postojeceg\n\tH-sortiranje po prezimenu\n\tI-upisivanje liste u datoteku\n\tJ-citanje liste iz datoteke\n\t0-izlaz\n");
		scanf(" %c", &n);

		switch (n)
		{
		case 'a':
		case 'A':
			unosP(&head);
			break;

		case 'b':
		case 'B':
			ispis(head.Next);
			break;

		case 'c':
		case 'C':
			unosK(&head);
			break;

		case 'd':
		case 'D':
			q = trazi(head.Next);
			if (q == NULL)
				printf("\nOsoba ne postoji u listi!\n");
			else
				printf(" %s %s %d\n", q->ime, q->prezime, q->gr);
			break;

		case 'e':
		case 'E':
			brisi(&head);
			break;

		case 'f':
		case 'F':
			q = trazi(head.Next);
			if (q == NULL)
				printf("\nOsoba ne postoji u listi!\n");
			else
			{
				unosP(q);
				ispis(head.Next);
			}
			break;

		case 'g':
		case 'G':
			q = traziPret(&head);
			if (q == NULL)
				printf("\nOsoba ne postoji u listi!\n");
			else
			{
				unosP(q);
				ispis(head.Next);
			}
			break;

		case 'h':
		case 'H':
			sort(&head);
			ispis(head.Next);
			break;

		case 'i':
		case 'I':
			datUpis(head.Next);
			break;

		case 'j':
		case 'J':
			datUcitaj(&head);
			break;

		case '0':
			printf("Kraj!\n");
			break;

		default:
			printf("\nKrivi unos!\n");
		}

	}

	return 0;
}

void unosP(position P) {
	position temp;

	temp = (position)malloc(sizeof(struct osoba));
	printf("Unesite podatke o osobi:\n");
	scanf(" %s %s %d", temp->ime, temp->prezime, &temp->gr);
	temp->Next = P->Next;
	P->Next = temp;
}

void ispis(position P)
{
	if (P == NULL)
		printf("\nLista je prazna.\n");
	else
	{
		printf("\nU listi se nalaze:\n");
		while (P != NULL) {
			printf("\n\t %s %s %d\n", P->ime, P->prezime, P->gr);
			P = P->Next;
		}
	}

}

position traziZadnji(position P)
{
	while (P->Next != NULL)
		P = P->Next;

	return P;
}


void unosK(position P)
{
	position temp;
	temp = (position)malloc(sizeof(struct osoba));
	printf("\nUnesite podatke o osobi:\n");
	scanf(" %s %s %d", temp->ime, temp->prezime, &temp->gr);

	P = traziZadnji(P);
	temp->Next = P->Next;
	P->Next = temp;

}

position traziPret(position P)
{
	char prez[10];

	if (P->Next == NULL)
		P = NULL;

	else
	{
		printf("\nUnesite prezime osobe koju zelite obrisati ili ispred koje zelite dodati novi element:\n\n");
		scanf(" %s", prez);

		while (strcmp(P->Next->prezime, prez) != 0 && P->Next->Next != NULL)
			P = P->Next;

		if (strcmp(P->Next->prezime, prez) != 0)
			P = NULL;
	}
	return P;
}

void brisi(position P)
{
	position prev;
	prev = traziPret(P);
	if (prev != NULL)
	{
		P = prev->Next;
		prev->Next = P->Next;
		printf("\nOsoba %s %s %d sada je obrisana\n", P->ime, P->prezime, P->gr);
		free(P);
	}
	else
		printf("\nOsoba ne postoji u listi!\n");

}

position trazi(position P)
{
	char prez[10];

	printf("\nUnesite prezime osobe koju zelite naci, ili iza koje zelite ubaciti novi element:\n\n");
	scanf(" %s", prez);
	while (P != NULL && strcmp(P->prezime, prez) != 0)
		P = P->Next;

	return P;
}

void sort(position P)
{
	position i, j, prev_j, temp, end;
	end = NULL;
	i = P;

	while (i->Next != end)
	{
		prev_j = i;
		j = i->Next;
		while (j->Next != end)
		{
			if (strcmp(j->prezime, j->Next->prezime) > 0) //ako su prezimena razlicita
			{
				temp = j->Next;
				prev_j->Next = temp;		
				j->Next = temp->Next;					 //onda radimo zamjenu
				temp->Next = j;
				j = temp;
			}
			prev_j = j;
			j = j->Next;
		}
		end = j;
	}
}

void datUpis(position P)
{
	FILE* dat;
	char imeDat[10];

	printf("\nUnesi ime datoteke u koju zelis spremiti listu:");
	scanf(" %s", imeDat);

	dat = fopen(imeDat, "w");

	if (NULL == dat)
		printf("\n Greska u otvaranju datoteke");
	else
	{
		while (P != NULL)
		{
			fprintf(dat, "\n %s %s %d", P->ime, P->prezime, P->gr);
			P = P->Next;
		}
		fclose(dat);
	}
}

void datUcitaj(position P)
{
	FILE* dat;
	char imeDat[10];
	position temp;

	printf("\nUnesi ime datoteke iz koje zelis procitati listu:");
	scanf(" %s", imeDat);

	dat = fopen(imeDat, "r");

	if (dat == NULL)
		printf("\n Ne postoji datoteke s tim imenom");
	else
	{
		while (feof(dat) == 0)
		{
			temp = (position)malloc(sizeof(struct osoba));

			fscanf(dat, " %s %s %d", temp->ime, temp->prezime, &temp->gr);
			printf(" %s %s %d\n", temp->ime, temp->prezime, temp->gr);

			temp->Next = P->Next;
			P->Next = temp;
			P = temp;
		}

		fclose(dat);
	}
}