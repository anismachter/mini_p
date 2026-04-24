#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_attente.h"

// Initialisation de la file au démarrage
void initialiser_file(FileAttente* f) {
    f->front = NULL;
    f->rear = NULL;
    f->taille = 0;
}

// Tâche : Enregistrer l'arrivée et générer le ticket
void enregistrer_arrivee_patient(FileAttente* f, char* nom, char* prenom, int age) {
    // Variable statique pour garder le compteur entre les appels
    static int compteurTickets = 1;

  
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire !\n");
        return;
    }

    // Remplissage des données
    nouveau->patient.id = compteurTickets;
    strcpy(nouveau->patient.nom, nom);
    strcpy(nouveau->patient.prenom, prenom);
    nouveau->patient.age = age;
    nouveau->patient.numTicket = compteurTickets++;
    nouveau->patient.statut = EN_ATTENTE;
    nouveau->suivant = NULL;

    // Enfiler le patient (Insertion en queue)
    if (f->rear == NULL) {
        f->front = nouveau;
        f->rear = nouveau;
    } else {
        f->rear->suivant = nouveau;
        f->rear = nouveau;
    }

    f->taille++;
    printf("\n[Succes] Patient enregistre. Ticket n : %d\n", nouveau->patient.numTicket);
}

// Tâche : Appeler le patient suivant (Défiler)
Patient appeler_patient_suivant(FileAttente* f) {
    if (f->front == NULL) {
        printf("\nLa file est vide !\n");
        Patient p_vide = {0, "", "", 0, 0, EN_ATTENTE};
        return p_vide;
    }

    // Récupération du patient en tête
    Noeud* temp = f->front;
    Patient p = temp->patient;

    f->front = f->front->suivant;
    if (f->front == NULL) {
        f->rear = NULL;
    }

    free(temp); // Libération mémoire 
    f->taille--;

    p.statut = EN_CONSULTATION;
    return p;
}


void afficher_file(FileAttente f) {
    if (f.front == NULL) {
        printf("\nFile d'attente vide.\n");
        return;
    }

    printf("\n--- FILE D'ATTENTE ACTUELLE (%d) ---\n", f.taille);
    Noeud* courant = f.front;
    while (courant != NULL) {
        printf("Ticket #%03d | %s %s (%d ans)\n",
                courant->patient.numTicket,
                courant->patient.nom,
                courant->patient.prenom,
                courant->patient.age);
        courant = courant->suivant;
    }
    printf("------------------------------------\n");
}
