
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include "StrList.h" 

/*void printMenu() {
    printf("\nMenu:\n"); 
    printf("1. Insert string\n"); 
    printf("2. Insert string at index\n"); 
    printf("3. Print list\n"); 
    printf("4. Print length of list\n"); 
    printf("5. Print string at index\n"); 
    printf("6. Print total characters in list\n"); 
    printf("7. Count occurrences of a string\n"); 
    printf("8. Remove all occurrences of a string\n"); 
    printf("9. Delete string at index\n"); 
    printf("10. Reverse the list\n"); 
    printf("11. Delete the entire list\n"); 
    printf("12. Sort the list\n"); 
    printf("13. Check if list is lexicographically sorted\n"); 
    printf("0. Exit\n"); 
    printf("Enter your choice: ");
}*/


int main() { 
    StrList* list = NULL;
    int choice = 99;
    char input[100];
    int index;
    
    
    while(choice != 0) {
        
        bool flagForCoice = true;

        //printMenu();
        scanf("%d", &choice); 

        if (choice == 1)
        {
            flagForCoice = false;
            if (list == NULL) {
                list = StrList_alloc();
            }
            //printf("Enter the number of words to insert: ");
            int numWords;
            scanf("%d", &numWords);
            //printf("Enter the words separated by space: ");
            while (numWords-- > 0) {
            scanf("%s", input);
            StrList_insertLast(list, input);
            }
        }
         
        if (choice == 2)
        {
            flagForCoice = false;
            //printf("Enter the index to insert: ");
            scanf("%d", &index);
            //printf("Enter the string to insert: ");
            scanf("%s", input);
            StrList_insertAt(list, input, index);
          }
          
        if (choice == 3)
        {
            flagForCoice = false;
            //printf("List contents:\n");
            StrList_print(list);
        }
    
        if (choice == 4)
        {
            flagForCoice = false;
            printf("%zu\n", StrList_size(list));
        }

        if (choice == 5)
        {
            flagForCoice = false;
            //printf("Enter the index to print: ");
            scanf("%d", &index);
            StrList_printAt(list, index);
        }
            
        if (choice == 6)
        {
            flagForCoice = false;
            printf("%d\n", StrList_printLen(list));
        }
        
        if (choice == 7)
        {
            flagForCoice = false;
            //printf("Enter the string to count: ");
            scanf("%s", input);
            printf("%d\n", StrList_count(list, input));
        }
        
        if (choice == 8)
        {
            flagForCoice = false;
            //printf("Enter the string to remove: ");
            scanf("%s", input);
            StrList_remove(list, input);
        }
        
        if (choice == 9)
        {
            flagForCoice = false;
            //printf("Enter the index to remove: ");
            scanf("%d", &index);
            StrList_removeAt(list, index);
        }
            
        if (choice == 10)
        {
            flagForCoice = false;
            StrList_reverse(list);
            //printf("List reversed.\n");
        }
        
        if (choice == 11)
        {
            flagForCoice = false;
            StrList_free(list);
            list = NULL;
            //printf("List deleted.\n");
        }
        
        if (choice == 12)
        {
            flagForCoice = false;
            StrList_sort(list);
            //printf("List sorted in lexicographical order.\n");
        }
        
        if (choice == 13)
        {
            flagForCoice = false;
            if (StrList_isSorted(list)) {
                printf("true\n");
            } 
            else {
                printf("false\n");
            }
        }

        if(flagForCoice&&choice!=0) {
            printf("can only get integer btween 0 and 13\n");
        }
    }

    if (list != NULL) {
       StrList_free(list);
   }

    //printf("Exiting program.\n");
    return 0;
}

            