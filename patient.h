#ifndef PATIENT_H
#define PATIENT_H

typedef enum {
    EN_ATTENTE,
    EN_CONSULTATION,
    OBSERVATION,
    SORTI,
    REFERE
} StatutPatient;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int age;
    int numTicket;      // Sera généré automatiquement par tes fonctions
    StatutPatient statut;
} Patient;

#endif
