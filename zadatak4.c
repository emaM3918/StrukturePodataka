int InsertSorted(Position head, Position nE) {
	Position temp = head;
	while (temp->next != NULL && temp->next->exp < nE->exp) //osiguravamo se da lista nije prazna, odnosno da ne izbaci neki eror (program provjerava uvjete po redu tako da ne mozemo obrnuti ovo)
	{														//u biti pokrivamo slucajeve kad se zbroje i daju 0 i kad se zbroje i daju drugu vrijednost ali onda minjamo vrijednost u listi
		temp = temp->next;
	}
	if (temp->next == NULL || temp->next!=nE->exp)
		InsertAfter(temp, nE);
	else {
		int resultcoeff = nE->coeff + temp->next->coeff;
		if (resultcoeff == 0) { DeleteAfter(temp); free(nE); }
	}
	else
	{ 
		temp->next->coeff = resultceoff; 
		free(nE); 
	}
}

//citanje datoteke u kojoj se nalaze polinomi		23 32 32 43
fgets(buffer, MAXLINE, file); //nac nacin na koji cemo proc kroz string i citat element po element
while (strlen(buffer) > 0) {
	int status=sscanf(buffer, " %d %d %n", &c, &e, &numBytes); //%n je ugraden u sscanf i kaze koliko smo nakon prve iteracije while petlje obradili zakova i pomocu tog podatka mozemo se kretat u bufferu
	//rekli smo sscanfu da pojede sve razmake
	//sscanf vraca broj pa smo ga izjednacili sa integerom, u ovom sucaju mora vratit broj 2
	CreateE(c, e); //kreiraj element
	InsertSorted(head, nE);

	buffer = buffer + numBytes; //ovo radimo da nam petlja ne upadne u beskonacni loop
}

//zbrajanje

/*napravimo if u kojem usporedujemo jesu li koef jednaki
imamo dvi vezane liste i spremamo u rezultantnu (pok i, pok j)
pocetne dvi su sortirane*/


