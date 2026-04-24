#ifndef FILE_ATTENTE_H
#define FILE_ATTENTE_H

#include "patient.h"

// Structure d'un nœud pour la file dynamique
typedef struct Noeud {
    Patient patient;
    struct Noeud* suivant;
} Noeud;

// Structure de contrôle de la File
typedef struct {
    Noeud* front; // Tête de file (sortie)
    Noeud* rear;  // Queue de file (entrée)
    int taille;
} FileAttente;

// Prototypes des fonctions d'Anis
void initialiser_file(FileAttente* f);
void enregistrer_arrivee_patient(FileAttente* f, char* nom, char* prenom, int age);
Patient appeler_patient_suivant(FileAttente* f);
void afficher_file(FileAttente f);

#endif
