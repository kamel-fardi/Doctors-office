#ifndef list
#define list
#include "patient.h"
typedef struct cel
{
    Patient p;
    struct cel* next;
}*liste;

liste create_list();
liste AddPatient(liste Head, Patient p);//allows you to add a new patient at the end of the list identified by its Head pointer

void Appointment(liste Head,int *apnmt,int *noapnmt);//count and return the number of patients with appointment, and without apnmt

void ConsultWaitingRoom(liste Head);//first displays patients with appointments then patients without apnmt

liste DeletePatient(liste Head);//if there is no patient with an appointment then it is the first patient on the list who is deleted
                                // otherwise the first patient who has apnmt is deleted

void PatientsSave(liste Head,char *Directory);//save patients in a file accessible from a Directory

void RetrieveListPatients(liste Head,char *Directory);//return in a chain list the data of a file accessible according to a Directory
void RetrieveListPatients_binary(liste Head,char *Directory);
void PatientsSave_binary(liste Head,char *Directory);







#endif // list
