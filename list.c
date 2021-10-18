#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "patient.h"
liste create_list()
{
    liste patients_list;
    patients_list=malloc(sizeof(struct cel));
    patients_list->next=NULL;
    return patients_list;
}
liste AddPatient(liste Head, Patient P)
{
    liste List_Element=malloc(sizeof(struct cel));
    List_Element->p=P;
    List_Element->next=NULL;
    if (Head==NULL)
    {
        Head=List_Element;
        DisplayPatient(Head->p);
        printf("\n Added Well\n");
    }
    else
    {
        liste current=NULL;
        current=Head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=List_Element;
        current=current->next;
        printf("Adding :\n");
        DisplayPatient(current->p);
    }

    return Head;
}
void Appointment(liste Head, int *apnmt,int *noapnmt)
{
    *apnmt=0;
    *noapnmt=0;
    liste current=NULL;
    current=Head;
    if (Head==NULL) return;
    if(Head->next==NULL)
    {
        if(Head->p.apnmt==1)(*apnmt)++;
        if(Head->p.apnmt==0)(*noapnmt)++;
    }
    else
    {
        while(current!=NULL)
        {
            if(current->p.apnmt==1)(*apnmt)++;
            if(current->p.apnmt==0)(*noapnmt)++;
            current=current->next;
        }
    }
}
void ConsultWaitingRoom(liste Head)
{
    liste current;
    current=Head;
    if(Head==NULL)
    {
        printf("The room is empty");
    }
    else
    {
        printf("The patients with appointments :\n");
        while(current!=NULL)
        {
            if(current->p.apnmt==1)
            {
                DisplayPatient(current->p);
            }
            current=current->next;
        }
        printf("\n");
        current=Head;
        printf("The patients without appointments :\n");
        while(current!=NULL)
        {
            if(current->p.apnmt==0)
            {
                DisplayPatient(current->p);
            }
            current=current->next;
        }
    }

}
liste DeletePatient(liste Head)
{
    liste current,prev;
    current=create_list();
    prev=create_list();
    prev=Head;
    current=Head->next;
    int r=0,sr=0;
    Appointment(Head,&r,&sr);
    if(current->next==NULL)
    {
        free(current);
        return NULL;
    }
    else
    {
        if(r==0){
            Head=current->next;
            free(current);
            return Head;
        }
            while(current!=NULL)
            {
            if(current->p.apnmt==1)
                {

                if(current->next==NULL){

                        prev->next=NULL;
                        free(current);
                        return (Head);
                        }
                else{
                    prev->next=current->next;
                    free(current);
                    return(Head);
                }
                }
            prev=current;
            current=current->next;

            }
    }
    return 0;
}

void PatientsSave(liste Head,char *directory)
{
    FILE *f=NULL;
    liste current;
    current=create_list();
    current=Head->next;
    f=fopen(directory,"a+");
    if (f==NULL)
    {
        printf("File not found\n");
    }
    else
    {
        if(current->next==NULL){
            fprintf(f,"%s   %s  %d\n",current->p.name,current->p.secondname,current->p.apnmt);
            fclose(f);
            free(Head);
            free(current);
            return;}
        else{
        do
        {
            fprintf(f,"%s   %s  %d\n",current->p.name,current->p.secondname,current->p.apnmt);
            current=current->next;
        }
        while(current!=NULL);
        fclose(f);
    }
    free(Head);
    free(current);
}
}
void RetrieveListPatients(liste Head,char *directory)
{
    FILE *f=NULL;
    Patient p;
    liste List_Element=malloc(sizeof(struct cel));
    List_Element->next=NULL;
    f=fopen(directory,"r+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p.name,p.secondname,&p.apnmt)!=EOF)
        {
            printf("%s %s %d\n",p.name,p.secondname,p.apnmt);
            AddPatient(Head,p);
        }
    }

    else
    {
        printf("File not found");
    }
    fclose(f);
}
void RetrieveListPatients_binary(liste Head,char *directory)
{
    FILE *f=NULL;
    Patient p;
    liste List_Element=malloc(sizeof(struct cel));
    List_Element->next=NULL;
    f=fopen(directory,"rb+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %d\n",p.name,p.secondname,&p.apnmt)!=EOF)
        {
            printf("%s %s %d\n",p.name,p.secondname,p.apnmt);
            AddPatient(Head,p);
        }
    }

    else
    {
        printf("File not found");
    }
    fclose(f);
}

void PatientsSave_binary(liste Head,char *directory)
{
    FILE *f=NULL;
    liste current;
    current=create_list();
    current=Head->next;
    f=fopen(directory,"ab+");
    if (f==NULL)
    {
        printf("File not found\n");
    }
    else
    {
        if(current->next==NULL){
            fprintf(f,"%s   %s  %d\n",current->p.name,current->p.secondname,current->p.apnmt);
            fclose(f);
            free(Head);
            free(current);
            return;}
        else{
        do
        {
            fprintf(f,"%s   %s  %d\n",current->p.name,current->p.secondname,current->p.apnmt);
            current=current->next;
        }
        while(current!=NULL);
        fclose(f);
    }
    free(Head);
    free(current);
}
}
