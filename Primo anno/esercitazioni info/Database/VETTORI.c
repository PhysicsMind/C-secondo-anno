//FUNZIONE RIEMPIMENTO VETTORE
void riempivettore (int l, int vettore[l]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite standard imput
	printf("Inserire valore %i del vettore: ", i); 		
	scanf("%i", &vettore[i]);
	}
}
//nel main:
int V[N];
riempivettore(N, V);   //riempimento del vettore  V[N]

//FUNZIONE RIEMPIMENTO MATRICE
void riempimatrice (int l, int k, double mat[l][k]){                 //funzione per assegnare i valori nella matrice
	for(int i=0; i<l; i++){ 
	    for(int j=0; j<k; j++){                             //ciclo di assegnamento delle variabili tramite standard imput
	    printf("Inserire valore riga %i, colonna %i: ", i+1,j+1); 		
	    scanf("%le", &mat[i][j]);
	    } 
	}
}
//nel main:
double mat[M][N];
riempimatrice(M,N, mat);


//FUNZIONE RIEMPIMENTO VETTORE DALLA LINEA DI COMANDO            
void riempivettore (int l, int vettore[l], char *argv[]){                 //funzione per assegnare i valori nel vettore
	for(int i=0; i<l; i++){                             //ciclo di assegnamento delle variabili tramite linea di comando
	vettore[i]=atoi(argv[i+1]);
	}
}
//nel main:
  int V[argc-1]; 
  riempivettore(argc-1, V, argv);   //riempimento del vettore  V[argc-1]
 
//FUNZIONE STAMPA VETTORE
void stampavettore(int l, int vettore[l]){    //funzione per stampare i valori di un vettore 
	for(int i=0; i<l; i++){               //ciclo di stampa di ogni elemento
	printf("%i ", vettore[i]);
	}
	printf("\n");
}
//nel main:
int V[N];
stampavettore(N , V); //stampa il vettore  V[N]

//FUNZIONE STAMPA MATRICE
void stampamatrice(int l, int k, double mat[l][k]){
	printf("\nMatrice \n");
	for (int i=0;i<l;i++)	
	{
		for(int j=0;j<k;j++)
		{
			printf("%4f ",mat[i][j]);			//stampa matrice
		}
		printf("\n");	
	}
}
//nel main:
double mat[M][N];
stampamatrice(M,N, mat);


//POSIZIONE VALORE MINIMO DEL VETTORE
int trovaposmin (int l, int v[]) {   //trova e stampa la posizione dell'elemento più  piccolo nel vettore v
  int vmin, posmin;

  vmin = v[0]; posmin = 0;        //azzeramento variabili
  for (int i=0; i <= l; i++) {
    if ( v[i] < vmin ) {  //se la posizione successiva è minore allora è il nuovo minimo
      vmin = v[i];
      posmin = i;
    }
  }
  return posmin;  
}
//nel main:
 int min; //variabile per posizione del valore minimo del vettore
 min=trovaposmin(N ,V);
 
 //SCAMBIA ELEMENTI DI UN VETTORE
 void scambia (int v[], int x, int y) {   //scambia nel vettore v[x] con v[y]
  int tmp = v[x];
  v[x] = v[y];
  v[y] = tmp;
  return;
}
 //nel main:
    scambia(V, el1 , el2);
    
//ORDINA VETTORE
void ordinavettore(int l, int vettore[l]){   //funzione di ordinamento degli elementi di un vettore
    int min, temp;

	for(int i=0; i<l; i++){   		// array di ordinamento con due cicli for annidati, nel secondo for ogni volta che viene trovato un valore minore rispetto a quello fissato nel primo ciclo for vengono scambiati,
	min=vettore[i];				// tramite una variabile ausiliaria
	temp=vettore[i];
		for(int cont=i;cont<l;cont++){
			if(vettore[cont]<vettore[i]){
			min=vettore[cont];
			temp=vettore[i];
			vettore[i]=min;
			vettore[cont]=temp;
			}
		}	
	}
}
//nel main:
  int v[N];
  ordinavettore(N, V);
  
//FONDIVETTORI
void fondivettori (int vettoreA[], int vettoreB[],int l1, int l2, int vettoreC[l1+l2]){ //funzione di fusione di due vettori
   int k=0;

	for(int i=0; i<l1; i++){     // il primo ciclo for riempe il vettore C con i valori del vettore A
	vettoreC[i]=vettoreA[i];
	}

	for(int j=l1; j<l1+l2; j++){  //il secondo ciclo copia i valori del vettore B in C
	vettoreC[j]=vettoreB[k];
	k++;
	}
}
//nel main:
  int vettoreA[N];    //dichiarazione vettori
  int vettoreB[M];
  int vettoreC[N+M];
  fondivettori(vettoreA,vettoreB,N,M, vettoreC);   //fusione A+B nel vettore C con lunghezza N+M
  
//FUNZIONE SHITF LEFT       es: 4 3 2 1 -> 1 2 3 4
void shl(int vet[],int n)
{
	int i;
	for (i=1;i<n;i++)
		vet[i-1]=vet[i];
	vet[n-1]=0;
}
//nel main 
   shl(vet,N);
   
//FUNZIONE SHITF RIGHT      es: 1 2 3 4 -> 4 3 2 1
void shr(int vet[],int n)
{
	int i;
	for (i=0;i<n;i++)
		vet[i+1]=vet[i];
	vet[0]=0;
}
//nel main 
   shr(vet,N);
   

