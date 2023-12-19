#include <stdio.h>
#include <string.h>

// Structure pour représenter un candidat
struct Candidat {
    char nom[50];
    int votes;
};

// Fonction pour afficher les candidats
void afficherCandidats(struct Candidat candidats[], int nbCandidats) {
    printf("Candidats disponibles:\n");
    for (int i = 0; i < nbCandidats; i++) {
        printf("%s : %d votes\n", candidats[i].nom, candidats[i].votes);
    }
    printf("\n");
}

int main() {
    // Initialisation des candidats
    struct Candidat candidats[3] = {
        {"Candidat1", 0},
        {"Candidat2", 0},
        {"Candidat3", 0}
    };

    // Nombre total de candidats
    int nbCandidats = sizeof(candidats) / sizeof(candidats[0]);

    // Nombre de personnes qui vont voter
    int nombrePersonnes;
    printf("Combien de personnes vont voter? ");
    scanf("%d", &nombrePersonnes);

    // Boucle de vote
    for (int i = 0; i < nombrePersonnes; i++) {
        printf("\nVeuillez choisir votre candidat:\n");
        afficherCandidats(candidats, nbCandidats);

        char choixCandidat[50];
        printf("Entrez le nom du candidat: ");
        scanf("%s", choixCandidat);

        // Vérification si le candidat existe
        int candidatExiste = 0;
        for (int j = 0; j < nbCandidats; j++) {
            if (strcmp(choixCandidat, candidats[j].nom) == 0) {
                candidats[j].votes++;
                candidatExiste = 1;
                printf("Vote enregistré pour %s!\n", candidats[j].nom);
                break;
            }
        }

        if (!candidatExiste) {
            printf("Candidat invalide. Veuillez choisir un candidat valide.\n");
        }
    }

    // Affichage final des résultats
    printf("\nRésultats finaux:\n");
    afficherCandidats(candidats, nbCandidats);

    return 0;
}
