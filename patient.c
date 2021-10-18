#include <stdio.h>
#include <string.h>
#include "patient.h"
void PatientInput(Patient *p)
{
    printf("Input your first name\n");
    fflush(stdin);
    gets(p->name);

    printf("Input your second name\n");
    gets(p->secondname);

    printf("do you have an apnmt 1:yes 0:no\n");
    scanf("%d",&p->apnmt);

}
void DisplayPatient(Patient p)
{
    if(p.apnmt==1)
        {
            printf("Patient first name: %s\n",p.name);
            printf("Patient Seconde name: %s\n",p.secondname);
            printf("there is an apnmt\n");
        }
    else
        {
            printf("Patient first name: %s\n",p.name);
            printf("Patient Seconde name: %s\n",p.secondname);
            printf("there is no apnmt\n");
        }

}
void StoragePatient(Patient p,char *Directory)
{
FILE *f=NULL;
f=fopen(Directory,"a+");
if (f!=NULL)
{
    fprintf(f,"%s   %s  %d",p.name,p.secondname,p.apnmt);
    fclose(f);
}
else printf("File not found");
}

void readLastPatient(Patient *p,char *Directory)
{
    FILE *f=NULL;

    Patient Temp[20];

    int Counter =0;

    f=fopen(Directory,"r+");

    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p->name,p->secondname,&p->apnmt)!=EOF)
        strcpy(Temp[Counter].name,p->name);
        strcpy(Temp[Counter].secondname,p->secondname);
        p->apnmt=Temp[Counter].apnmt;
    }

    else
    {
        printf("File not found");
    }
}
