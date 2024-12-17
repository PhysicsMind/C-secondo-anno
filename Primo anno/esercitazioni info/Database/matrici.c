#include<stdio.h>
#include<stdbool.h>
const int m,n,p,q;			//dichiarazione indici matrici
int i,j;					//dichiarazione contatori
bool quadrata=false;
void start(void);										//prototipi
void mat_due(int MAT_2[][q]);
void stampa(int MAT_1[][n]);
void prodotto(int MAT_1[][n], int MAT_2[][q]);
void somma(int MAT_1[][n], int MAT_2[][q]);
void differenza(int MAT_1[][n], int MAT_2[][q]);
int det(int MAT_1[][n], int car);
int main(int argc, char** argv)
{
	start();			//main: chiamata alla prima funzione
}
void start()
{
	char scelta;
	do
	{
		printf("Inserire il numero di righe della prima matrice: ");
		scanf("%d",&m);
		printf("Inserire il numero di colonne della prima matrice: ");
		scanf("%d",&n);
	}
	while(m==0 || n==0);			//input dimensioni matrice e controllo della validità
	if (m==n)
		quadrata=true;				//verifica se la matrice è quadrata
	int MAT_1[m][n],MAT_2[p][q];	//dichiarazione matrici
	for (i=0;i<m;i++)	
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("Inserisci elemento di riga %d e colonna %d: ",i+1,j+1);
			scanf("%d",&MAT_1[i][j]);				//input valori matrice 1
		}
	}
	int car=m/n;			//calcolo della cardinalià per il determinante
	do				//menù
	{														
		printf("\n\t\t\t\t-------------------------------------\n");
		printf("\t\t\t\tStampa matrice (a)\n\t\t\t\tProdotto tra matrici (b)\n\t\t\t\tSomma tra matrici (c)\n\t\t\t\tDifferenza tra matrici(d)\n\t\t\t\tDeterminante delle matrici (e)\n\t\t\t\tPer terminare (*)\n");
		printf("\t\t\t\t-------------------------------------\n");
		scanf(" %c",&scelta);
		switch(scelta)
		{
			case 'a':
				stampa(MAT_1);
				break;
			case 'b':
				mat_due(MAT_2);
				if (m==q)					//verifica se è possibile eseguire il prodotto
					prodotto(MAT_1,MAT_2);	
				else
				printf("\nNon e' possibile eseguire il prodotto \n");
				break;
			case 'c':
				mat_due(MAT_2);
				if(m==p && n==q)			//verifica se è possibile eseguire la somma
					somma(MAT_1,MAT_2);
				else
					printf("\nNon e' possibile eseguire la somma \n");
				break;
			case 'd':
				mat_due(MAT_2);
				if(m==p && n==q)			//verifica se è possibile eseguire la differenza
					differenza(MAT_1,MAT_2);
				else
					printf("\nNon e' possibile eseguire la differenza \n");
				break;
			case 'e':
				if(quadrata)
					printf("\nDeterminante: %d \n",det(MAT_1,car));
				else
					printf("\nNon e' possibile calcolare il determinante\n");
				break;
		}
	}
	while(scelta!='*');			// '*' per terminare
}
void mat_due(int MAT_2[][q])		//funzione per l'input di una seconda matrice
{
	do
	{
		printf("\nInserire il numero di righe della seconda matrice: ");
		scanf("%d",&p);
		printf("Inserire il numero di colonne della seconda matrice: ");
		scanf("%d",&q);
	}
	while(p==0 || q==0);			//input dimensioni matrice e controllo della validità
	if (p==q && q==m)				//verifica se la matrice è quadrata
		quadrata=true;				
	for (i=0;i<p;i++)
	{
		printf("\n");
		for(j=0;j<q;j++)
		{
			printf("Inserisci elemento di riga %d e colonna %d: ",i+1,j+1);
			scanf("%d",&MAT_2[i][j]);				//input valori matrice 2
		}
	}
}
void prodotto(int MAT_1[][n], int MAT_2[][q])
{
	int k,MAT_PRODOTTO[m][q];			//dichiarazione matrice prodotto
	for (i=0;i<m;i++)
	{
		for (j=0;j<q;j++)
		{
			MAT_PRODOTTO[i][j]=0;
			for (k=0;k<n;k++)
				MAT_PRODOTTO[i][j]+=MAT_1[i][k]*MAT_2[k][j];		//calcolo metrice prodotto
			printf("%4d ",MAT_PRODOTTO[i][j]);				//stampa
		}
		printf("\n");
	}
}
void stampa(int MAT_1[][n])
{
	printf("\nMatrice \n");
	for (i=0;i<m;i++)	
	{
		for(j=0;j<n;j++)
		{
			printf("%4d ",MAT_1[i][j]);			//stampa matrice
		}
		printf("\n");	
	}
}
void somma(int MAT_1[][n], int MAT_2[][q])
{
	int MAT_SOMMA[m][p];		//dichiarazione della matrice somma
	stampa(MAT_1);
	stampa(MAT_2);			//prima stampa le due matrici
	printf("\nMatrice somma \n");
	for (i=0;i<m;i++)	
	{
		for(j=0;j<n;j++)
		{
			MAT_SOMMA[i][j]=0;		//azzera la matrice somma
			MAT_SOMMA[i][j]=MAT_1[i][j]+MAT_2[i][j];			//calcolo della matrice somma
			printf("%4d ",MAT_SOMMA[i][j]);				//stampa
		}
		printf("\n");	
	}
}
void differenza(int MAT_1[][n], int MAT_2[][q])
{
	int MAT_DIFF[m][p];			//dichiarazione della matrice differenza
	stampa(MAT_1);
	stampa(MAT_2);				//prima stampa le due matrici
	printf("\nMatrice differenza \n");
	for (i=0;i<m;i++)	
	{
		for(j=0;j<n;j++)
		{
			MAT_DIFF[i][j]=0;				//azzera la matrice differenza
			MAT_DIFF[i][j]=MAT_1[i][j]-MAT_2[i][j];				//calcolo della matrice somma
			printf("%4d ",MAT_DIFF[i][j]);				//stampa
		}
		printf("\n");	
	}
}
int det(int MAT_1[][n], int car)
{
	int sub_m[m][n],determinante=0,k;		//dichiarazione sottomatrice e variabili
	int sub_riga,sub_col;		
	if (car==1)					//verifica il valore della  cardinalità (m/n come calcolato nella funzione start)
		determinante=MAT_1[0][0];			//determinante per la cardinalità uno	
    if (car==2)
        determinante=MAT_1[1][1]*MAT_1[0][0]-MAT_1[0][1]*MAT_1[1][0];		//determinante per la cardinalità due
    else
	{								  //Cardinalità > 2
        for (k=0;k<car;k++)
		{
           	//Sottomatrice di ordine car-1
	        for (i=0;i<car-1;i++)
			{
	            for (j=0;j<car-1;j++)
				{
					if (i<k)					//calcoli per il determinante con la regola di Laplace
	                	sub_riga=i;
	                else
	                	sub_riga=i+1;
	                sub_col=j+1;
	                sub_m[i][j]=MAT_1[sub_riga][sub_col];
	            }
			}
        //Segno sottomatrice + per pari, - per dispari
        if (k%2==0)
            determinante+=MAT_1[k][0]*det(sub_m, car-1);		//utilizzo della ricorsione tra funzioni
        else
            determinante-=MAT_1[k][0]*det(sub_m, car-1);
		}
	}
    return determinante;
}
