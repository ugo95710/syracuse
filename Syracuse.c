#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initFile(char * fileName){     // Fonction permettant de créer un fichier s'il n'existe pas et de supprimer son contenu s'il existe
    FILE * fp = fopen(fileName, "w");
    fprintf(fp, "n Un");
    fclose(fp);
}

int syracuse(int n){    // Fonction Un+1
    if(n%2==0){
        return (n/2);
    }
    else{
        return ((n*3)+1);
    }
}

int main(int argc, char ** argv) {
    if (argc != 3){ // On vérifie que le nombre de paramètre est bien de 2 + le nom du fichier exécuté
        fprintf(stderr, "ERREUR: Le nombre de paramètre est incorrect !\n");
        exit(-1);
    }
    else {
        initFile(argv[2]);
        FILE *fp = fopen(argv[2], "a");    // On fait directement l'ouverture et la fermeture du fichier dans le main pour gagner en performance et ne pas avoir à ouvrir/fermer le fichier dans une fonction
        int U0 = atoi(argv[1]);
        int Un = U0;
        int n = 1;
        int altimax = U0;
        int dureealtitude = 0;
        int verif = 1;
        fprintf(fp, "\n0 %d",U0); // On écrit le u0 dans le fichier
        while (Un != 1){    // On va jusqu'à la fin de la suite
            Un = syracuse(Un);
            fprintf(fp, "\n%d %d", n, Un);
            n++;
            if (Un > altimax){  // Vérif de l'altitude max
                altimax = Un;
            }
            if ((Un > U0) && verif){       // Update duree de vol en altitude
                dureealtitude++;
            }
            else{   // Permet d'arrêter de compter la durée en altitude à partir du moment où la suite redescend sous U0
                verif = 0;
            }
        }
        fprintf(fp, "\naltimax=%d",altimax);
        fprintf(fp, "\ndureevol=%d",n-1);
        fprintf(fp, "\ndureealtitude=%d",dureealtitude);
        fclose(fp);
    }
    return 0;
}