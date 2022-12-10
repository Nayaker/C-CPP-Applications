// BinaryPhoneDictionary

#include <stdio.h>
#include <string.h>

struct contact_data{
   char name[100];
   char number[11];
} typedef contact;


int main() {
   FILE* fptr;

   int operation;
   printf("Please enter the work you would like to execute : \n");
   printf("1. Read\n2. Add\n3. Specific Contact\n4. Modify\n5. Delete\nPlease enter : "); scanf("%d", &operation);

   char name[100], number[11], req_name[100], req_number[11]; 

   switch (operation){
   case 2:
      printf("\n ------- You are now adding content ------ \n");

      fptr = fopen("phoneDictionaryFile.bin", "ab");
      
      
      printf("Enter contact name : "); scanf("%s", name);
      printf("Enter contact number : "); scanf("%s", number);

      contact person; 
      strcpy(person.name, name); 
      strcpy(person.number, number);
      
      fwrite(&person, sizeof(contact), 1, fptr);
      
      printf("We are saving...\n");
      printf("Your contact has been saved!\n");
      
      fclose(fptr);
      break;

   case 3:
      printf("\n ------- You are now finding specific content ------ \n");
      
      fptr = fopen("phoneDictionaryFile.bin", "rb");

      printf("Enter required person name : "); scanf("%s", req_name);

      // person is already initialized in the 2. Add part
      while (fread(&person, sizeof(contact), 1, fptr) > 0){
         if(!strcmp(person.name, req_name))
            printf("%s : %s\n", person.name, person.number);
      }

      fclose(fptr);

      break;

   case 4:
      printf("\n ------- You are now modifying content ------ \n");

      // We take two files, main file and one more that we will use as a temp container

      fptr = fopen("phoneDictionaryFile.bin", "rb");
      FILE* temp_file = fopen("tempDictionaryFile.bin", "wb");

      printf("Enter required person name : "); scanf("%s", req_name);
      printf("Enter new number : "); scanf("%s", req_number);

      // person is already initialized in the 2. Add part
      while (fread(&person, sizeof(contact), 1, fptr) > 0){
         if(!strcmp(person.name, req_name))
            strcpy(person.number, req_number);

         fwrite(&person, sizeof(contact), 1, temp_file);
      }

      fclose(fptr);
      fclose(temp_file);

      remove("phoneDictionaryFile.bin");
      rename("tempDictionaryFile.bin", "phoneDictionaryFile.bin");
      
      break;
   
   case 5:
      printf("\n ------- You are now deleting content ------ \n");

      // We take two files, main file and one more that we will use as a temp container

      fptr = fopen("phoneDictionaryFile.bin", "rb");
      temp_file = fopen("tempDictionaryFile.bin", "wb");

      printf("Enter person name to delete : "); scanf("%s", req_name);

      // person is already initialized in the 2. Add part
      while (fread(&person, sizeof(contact), 1, fptr) > 0){
         if(!strcmp(person.name, req_name)) continue;

         fwrite(&person, sizeof(contact), 1, temp_file);
      }

      fclose(fptr);
      fclose(temp_file);

      remove("phoneDictionaryFile.bin");
      rename("tempDictionaryFile.bin", "phoneDictionaryFile.bin");

      break;
   

   default:
      printf("\n ------- You are now reading all content ------ \n");
      fptr = fopen("phoneDictionaryFile.bin", "rb");

      // person is already initialized in the 2. Add part

      while (fread(&person, sizeof(contact), 1, fptr) > 0){
         printf("%s : %s\n", person.name, person.number);
      }
      
      break;
   }

   return 0;
}
