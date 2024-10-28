/*2. Definirati strukturu osoba (ime, prezime, godina roðenja) i napisati program koji:
A. dinamièki dodaje novi element na poèetak liste,
B. ispisuje listu,
C. dinamièki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.
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

int main() 
{
	struct osoba head, *q;
	head.Next = NULL;

	unosP(&head);
	ispis(head.Next);
	unosK(&head);
	ispis(head.Next);

	q=trazi(head.Next);
	if (q == NULL)
		printf("\nOsoba ne postoji u listi!\n");
	else
		printf(" %s %s %d\n", q->ime, q->prezime, q->gr);

	brisi(&head);
	ispis(head.Next);

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
	
	P=traziZadnji(P);
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
		printf("\nUnesite prezime osobe koju zelite obrisati:\n\n");
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
	prev=traziPret(P);
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

	printf("\nUnesite prezime osobe koju zelite naci:\n\n");
	scanf(" %s", prez);
	while (P != NULL && strcmp(P->prezime, prez)!=0)
		P = P->Next;
	
	return P;
}