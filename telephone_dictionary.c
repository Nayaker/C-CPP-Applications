#include <stdio.h>
#include <string.h>

int main() {
   FILE* fptr;

   int work;
   printf("Please enter the work you would like to execute : \n");
   printf("1. Read\n2. Add\n3. Specific Contact\n4. Modify\n5. Delete\nPlease enter : "); scanf("%d", &work);

   char name[100], number[11], req_name[100], req_number[11]; 

   switch (work){
   case 2:
      printf("\n ------- You are now adding content ------ \n");

      fptr = fopen("file.txt", "a");
      
      printf("Enter contact name : "); scanf("%s", name);
      printf("Enter contact number : "); scanf("%s", number);
      
      fprintf(fptr, "%s : %s\n", name, number);
      
      printf("We are saving...\n");
      printf("Your contact has been saved!\n");
      
      fclose(fptr);
      break;

   case 3:
      printf("\n ------- You are now finding specific content ------ \n");
      
      fptr = fopen("file.txt", "r");

      printf("Enter contact name to search : "); scanf("%s", req_name);
      
      while (fscanf(fptr, "%s %*s %s", name, number) > 0){
         if(!strcmp(name, req_name)){
            printf("Contact found!\n");
            printf("%s : %s\n", name, number);
         }
      }
      
      fclose(fptr);

      break;

   case 4:
      printf("\n ------- You are now modifying content (Not Working) ------ \n");

      fptr = fopen("file.txt", "w+");

      int position = 0;
      printf("Enter contact name to search : "); scanf("%s", req_name);
      
      while (fscanf(fptr, "%s %*s %s", name, number) > 0){
         if(!strcmp(name, req_name)){
            printf("Contact found!\n");
            printf("%s : %s\n", name, number);
            printf("Enter new number : "); scanf("%s", req_number);
            fprintf(fptr, "%s : %s\n", name, req_number);
            break;
         }
         else fprintf(fptr, "%s : %s\n", name, number);
         position++;
      }

      printf("Position : %d\n", position);

      fclose(fptr);
      
      break;
   
   case 5:
      printf("\n ------- You are now deleting content ------ \n");
      break;
   

   default:
      printf("\n ------- You are now reading all content ------ \n");
      break;
   }

   return 0;
}
