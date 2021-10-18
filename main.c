#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "list.h"
int main()
{
    liste l=create_list();;
    int rdv=0,sansRdv=0;
    Patient kamel,ahmed,hocine;
    char Directory[]="C:project_directory/patients.txt";
    char Directoryb[]="C:project_directory/patientsb.txt";

    PatientInput(&ahmed);
    AddPatient(l,ahmed);
    PatientInput(&hocine);
    AddPatient(l,hocine);
    PatientInput(&kamel);
    AddPatient(l,kamel);
    printf("============Display====================\n");
    ConsultWaitingRoom(l);
    printf("=============Delete==================\n");
    l=DeletePatient(l);
    Appointment(l,&rdv,&sansRdv);
    printf("les rdv :%d\nles sansRDV :%d\n",rdv,sansRdv);
    printf("============Display====================\n");
    ConsultWaitingRoom(l);
    printf("======================================\n");
    PatientsSave(l,Directory);
    StoragePatient(kamel,Directory);

    RetrieveListPatients(l,Directory);
    ConsultWaitingRoom(l);
    PatientsSave_binary(l,Directoryb);
    return 0;
}
