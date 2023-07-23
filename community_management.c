#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DefaultUsername "admin"
#define DefaultPassword "admin"
#define MaxCharSize 40

enum status {
  error,
  warning,
  notice
};

struct community {
  char name[20];
  char dob[20];
  char mar_status[20];
  char father[20];
  char mother[20];
  char gender[5];
  char religion[10];
  char address[20];
  char spouse[20];
};

typedef enum status Status;
typedef struct community Community;

void welcomeScreen();
void insert();
void viewout();
void update();
void printMessage(Status currentStatus, const char* message);
bool isStringValid(const char* address);
void suggestion(const char* name);

int main() {
  welcomeScreen();

  int choice;
  while (1) {
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t            Enter the choice    \n");
    printf("\t\t\t\t\t            *****************\n\n\n");
    printf("\t\t\t\t\t   1-Insert a new record into file  \n\n");
    printf("\t\t\t\t\t   2-Print the records              \n\n");
    printf("\t\t\t\t\t   3-Update the records             \n\n");
    printf("\t\t\t\t\t   4-Exit                           \n\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insert();
        break;
      case 2:
        viewout();
        break;
      case 3:
        update();
        break;
      case 4:
        exit(1);
      default:
        printf("Enter the correct choice\n");
    }
  }
}

void welcomeScreen() {
  printf("\n\n\n\n\n\n");
  printf("\t\t\t\t\t***********************************\n");
  printf("\t\t\t\t\t    1st semester project by      \n\n");
  printf("\t\t\t\t\t                                 \n");
  printf("\t\t\t\t\t     Ram Krishna Sharma          \n");
  printf("\t\t\t\t\t                                 \n");
  printf("\t\t\t\t\t                                 \n");
  printf("\t\t\t\t\t                                 \n");
  printf("\t\t\t\t\t**********************************\n");
  getchar(); // Wait for user input
  system("cls");
}

void insert() {
  system("cls");
  FILE* fp1;
  fp1 = fopen("records.txt", "a+");
  if (fp1 == NULL) {
    printf("File opening error\n");
    return;
  }

  printf("\t\t\t\t\t\t\t      Enter records \n");
  printf("\t\t\t\t\t\t\t       ************* \n\n");

  Community data;

  printf("\t\t\t\t\t\t             Name : ");
  scanf(" %[^\n]%*c", data.name);
  while (!isStringValid(data.name)) {
    printf("Enter a valid name: ");
    scanf(" %[^\n]%*c", data.name);
  }

  printf("\t\t\t\t\t\t     Date of birth: ");
  scanf(" %[^\n]%*c", data.dob);

  printf("\t\t\t\t\t\t     Father's name: ");
  scanf(" %[^\n]%*c", data.father);
  while (!isStringValid(data.father)) {
    printf("Enter a valid father's name: ");
    scanf(" %[^\n]%*c", data.father);
  }

  printf("\t\t\t\t\t\t     Mother's name: ");
  scanf(" %[^\n]%*c", data.mother);
  while (!isStringValid(data.mother)) {
    printf("Enter a valid mother's name: ");
    scanf(" %[^\n]%*c", data.mother);
  }

  printf("\t\t\t\t\t\t    Marital status: ");
  scanf(" %[^\n]%*c", data.mar_status);
  while (!isStringValid(data.mar_status)) {
    printf("Enter a valid marital status: ");
    scanf(" %[^\n]%*c", data.mar_status);
  }

  printf("\t\t\t\t\t\t           Address: ");
  scanf(" %[^\n]%*c", data.address);
  while (!isStringValid(data.address)) {
    printf("Enter a valid address: ");
    scanf(" %[^\n]%*c", data.address);
  }

  printf("\t\t\t\t\t\t          Religion: ");
  scanf(" %[^\n]%*c", data.religion);
  while (!isStringValid(data.religion)) {
    printf("Enter a valid religion: ");
    scanf(" %[^\n]%*c", data.religion);
  }

  printf("\t\t\t\t\t\t           Gender: ");
  scanf(" %[^\n]%*c", data.gender);
  while (!isStringValid(data.gender)) {
    printf("Enter a valid gender: ");
    scanf(" %[^\n]%*c", data.gender);
  }

  fwrite(&data, sizeof(data), 1, fp1);
  fclose(fp1);
  printf("Record inserted successfully.\n");
  printf("Press enter to continue...");
  getchar();
  system("cls");
}

void viewout() {
  system("cls");
  FILE* fp;
  Community data;
  int var = 1;
  fp = fopen("records.txt", "a+");
  if (fp == NULL) {
    printf("File opening error\n");
    return;
  }

  printf("********* Data of community people **************\n");
  while (fread(&data, sizeof(data), 1, fp) == 1) {
    printf("*************** %d************************\n", var);
    printf("\n\n\n\n Name: %s\n", data.name);
    printf(" Date of birth: %s\n", data.dob);
    printf(" Father's name: %s\n", data.father);
    printf(" Mother's name: %s\n", data.mother);
    printf(" Marital status: %s\n", data.mar_status);
    printf(" Address : %s \n", data.address);
    printf(" Religion: %s \n", data.religion);
    printf(" Gender: %s\n", data.gender);
    var++;
    printf("**************************\n");
  }
  fclose(fp);
  printf("Press enter to continue...");
  getchar();
  system("cls");
}

void update() {
  system("cls");
  FILE* fp1;
  fp1 = fopen("records.txt", "r+");
  if (fp1 == NULL) {
    printf("File opening error\n");
    return;
  }

  char name[20];
  printf("Enter the name to be updated: ");
  scanf(" %[^\n]%*c", name);

  Community data;

  while (fread(&data, sizeof(data), 1, fp1) == 1) {
    if (strcmp(data.name, name) == 0) {
      printf("Enter updated records:\n");

      printf(" Name : ");
      scanf(" %[^\n]%*c", data.name);
      while (!isStringValid(data.name)) {
        printf("Enter a valid name: ");
        scanf(" %[^\n]%*c", data.name);
      }

      printf(" Date of birth: ");
      scanf(" %[^\n]%*c", data.dob);

      printf(" Father's name: ");
      scanf(" %[^\n]%*c", data.father);
      while (!isStringValid(data.father)) {
        printf("Enter a valid father's name: ");
        scanf(" %[^\n]%*c", data.father);
      }

      printf(" Mother's name: ");
      scanf(" %[^\n]%*c", data.mother);
      while (!isStringValid(data.mother)) {
        printf("Enter a valid mother's name: ");
        scanf(" %[^\n]%*c", data.mother);
      }

      printf(" Marital status: ");
      scanf(" %[^\n]%*c", data.mar_status);
      while (!isStringValid(data.mar_status)) {
        printf("Enter a valid marital status: ");
        scanf(" %[^\n]%*c", data.mar_status);
      }

      printf(" Address: ");
      scanf(" %[^\n]%*c", data.address);
      while (!isStringValid(data.address)) {
        printf("Enter a valid address: ");
        scanf(" %[^\n]%*c", data.address);
      }

      printf(" Religion: ");
      scanf(" %[^\n]%*c", data.religion);
      while (!isStringValid(data.religion)) {
        printf("Enter a valid religion: ");
        scanf(" %[^\n]%*c", data.religion);
      }

      printf(" Gender: ");
      scanf(" %[^\n]%*c", data.gender);
      while (!isStringValid(data.gender)) {
        printf("Enter a valid gender: ");
        scanf(" %[^\n]%*c", data.gender);
      }

      fseek(fp1, -sizeof(data), SEEK_CUR);
      fwrite(&data, sizeof(data), 1, fp1);
      printf("Record updated successfully.\n");
      fclose(fp1);
      printf("Press enter to continue...");
      getchar();
      system("cls");
      return;
    }
  }

  printf("Update unsuccessful. Enter correct name.\n");
  fclose(fp1);
  printf("Press enter to continue...");
  getchar();
  system("cls");
}

void printMessage(Status currentStatus, const char* message) {
  const char* colorCode = "";
  switch (currentStatus) {
    case error: colorCode = "\033[91m"; break;     // Red color
    case warning: colorCode = "\033[93m"; break;   // Yellow color
    case notice: colorCode = "\033[94m"; break;    // Blue color
  }
  printf("%s%s\033[0m", colorCode, message);   // Reset color to default
}

bool isStringValid(const char* address) {
  for (int i = 0; i < strlen(address); i++) {
    int s = (int)address[i];
    if ((97 <= s && 122 >= s) || (65 <= s && 90 >= s) || s == 44 || s == 32) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

void suggestion(const char* name) {
  FILE* fp;
  fp = fopen("records.txt", "r");
  if (fp == NULL) {
    printf("File opening error\n");
    return;
  }

  Community data;
  while (fread(&data, sizeof(data), 1, fp) == 1) {
    int noc = strlen(name);
    if (strncmp(data.name, name, noc) == 0) {
      printf("%s      ", data.name);
    }
  }

  fclose(fp);
}