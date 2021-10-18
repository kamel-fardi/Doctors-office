# Doctors-office
We propose to model the management of patients in a doctor's office. A patient is characterized by: the last name, first name and an appointment field (for appointment) of integer type indicating whether the patient has an appointment or not: 0 if the patient is without appointment, 1 if the patient is with an appointment. Before being seen by the doctor, the patients entered a waiting room which will be modeled by a linked list of patients. A secretary brings in the patients with an appointment = 1 according to their order of arrival, then she brings in the others patients (those whose appointment = 0) according to their order of arrival as well.
1 Patient management (patient.h / patient.c)
    In a first step, you are asked to enter, display and
    saving a single patient.
      • Define the Patient data structure in patient.h
      • Define the following prototypes in patient.h
      ◦ void enterPatient (Patient * p); // which allows you to enter a single patient
      ◦ void showPatient (Patient p); which allows to display a single patient
      ◦ void savePatient (Patient p, char * path); // which allows to save
    a patient p at the end of a file accessible via a path.
      ◦ void readLastPatient (Patient * p, char * path); // which allows you to return
    the information of the last patient from a file accessible according to a
    path.
      • Implement these functions in patient.c
      • Test these functions in main.c
    NB: In this part, Saving and reading information from a file
    will be done in text mode.
2 Management of the Medical Practice (list.h / list.c)
    In a second step, you are asked to manage the medical practice by
    modeling by a linked list of patients.
    We ask you to:
      • Define the Cell data structure in list.h
      • Define the list type as a pointer to the Cell structure. (in list.h)
      • Add the following prototypes in list.h
      ◦ AddPatient list (head list, Patient P), which allows you to add a new
    patient at the end of the list identified by its head pointer.
      ◦ void Appointment (head list, int * rdv, int * sansRdv), which counts and returns
    the number of patients with an appointment, and the number of patients without an appointment.
      ◦ DeletedPatient list (head list), which allows a patient to be entered
    consultation. This operation is carried out as follows: if there is no
    no patient with an appointment so the first patient on the list is
    deleted. Otherwise we delete the first patient who has an appointment.
      ◦ void ConsultWaitingRoom (head list), which first displays the
    appointment patients, followed by walk-in patients.
      ◦ void savePatients (list head, char * path), which allows you to
    save the patients in a file accessible by a path
      ◦ void retrieveListPatients (list head, char * path), which
    return in a linked list the data of a file accessible according to a
    path.
      • Implement these different functions in list.c
      • Test these functions in main.c
    NB: In this part, Saving and reading information from a file
    will be done in binary mode.
