#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#define MAX 10

pthread_t th[NTHREADS];
int rc;


void init_tab(int n, int* a) {
	int i;
	fprintf(stderr, "tableau:\n");
	for(i=0; i< n; i++) {
		int r = rand() % MAX;
		a[i]= r;
		fprintf(stderr, "%d ", r);
	}
	fprintf(stderr, "\n");
}

/* fonction qui prend un tableau, une valeur à chercher
et les limites de la zone dans le tableau où chercher la
valeur */
int cherche(int* a, int val, int debut, int fin) {
	if(debut > fin || fin < debut) {
		fprintf(stderr, "erreur des limites de recherche");
		return 0;
	}
	
	int i;
	for(i=debut; i< fin; i++) {
		int tmp=a[i];
		if (val==tmp) {
			return 1;
		}
	}
	return 0; //on a pas trouvé val

}


void *premiere(void * arg) {

int *tab = (int *) arg;

int trouve;
	

	start = clock();
	trouve=cherche(a, val, 0, n/2);
	end= clock();

	
   pthread_exit (0);
  }

void *deuxieme(void * arg) {

		int *tab = (int *) arg;

int trouve;
	

	start = clock();
	trouve=cherche(a, val, n/2, n);
	end= clock();

    printf ("produit : %d \n",prod);
	
   pthread_exit (0);
  }




int main ( int argc, char *argv[] ) {
	int n=0;
	int val;
	
	clock_t start, end;
	
	if ( argc != 3 ) {
		printf( "usage: %s taille_tableau valeur_a_chercher \n", argv[0] );
	} else {
		n=atoi(argv[1]);
		val=atoi(argv[2]);
	}
	srand(time(NULL));
	
	int a[n];
	init_tab(n, a);


	  rc=pthread_create(&th[0], NULL, premiere, tab);
	  rc=pthread_create(&th[1], NULL, deuxieme, tab);

	  rc=pthread_create(&th[2], NULL, my_prod, tab);

	  rc=pthread_join(th[2],NULL);
	
	if (trouve) fprintf(stdout, "%d est dans le tableau\n", val);
	
	fprintf(stdout, "\nrecherche finalisée en %f millisecondes\n", (end-start)*1000/(double)(CLOCKS_PER_SEC));
	
	return 0;
}
