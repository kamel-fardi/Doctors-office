#ifndef patient
#define patient
typedef struct
{
    char name[20],secondname[20];
    int apnmt;
}Patient;

void PatientInput(Patient *p);// which allows you to enter a single patient
void DisplayPatient(Patient p);//which allows to display a single patient
void StoragePatient(Patient p,char *Directory);// which allows to save a patient p at the end of a file accessible via a path.
void readLastPatient(Patient *p,char *Directory);//which allows you to return the information of the last patient from a file accessible
                                                 //according to a path.



#endif // patient
