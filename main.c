///\file main.c
///\brief Our main file where the menu is.
///

#include "header.h"

/*! \fn void main
	\brief This is our main file where we will find the menu and the loop that forces you to choose an option.
*/
  

void main(){

    struct Array *array = malloc(sizeof(struct Array));
    array->next = NULL;
    int decision;
    srand(time(NULL));

    while(1){

        printf("\n");
        printf("\n1. Add element to the end in current array.");
        printf("\n2. Add element to the beginning in current array.");;
        printf("\n3. Sort array with bubble sort.");
        printf("\n4. Sort array with insertion sort.");
        printf("\n5. Sort array with selection sort.");
        printf("\n6. Sort array with quick sort.");
        printf("\n7. Sort array with merge sort.");
        printf("\n8. Sort array with heap sort.");
        printf("\n9. Sort array with radix sort.");
        printf("\n10. Sort array with all types of sort.");
        printf("\n11. Print the best time and method for current array.");
        printf("\n12. Activate/Deactivate printing array after sort.");
        printf("\n13. Generate random numbers to array.");
        printf("\n14. Print array to console.");
        printf("\n15. Binary search for a number.");
        printf("\n16. Linear search for a number.");
        printf("\n17. Exit.");

        printf("\n\nPlease choose a number: ");
        scanf("%d", &decision);
        switch(decision){

            case 1: printf("\nWhich number do you want to add to the array: ");
                    scanf("%d", &decision);
                    add_element(array, decision);
                    break;
            case 2: printf("\nWhich number do you want to add to the array: ");
                    scanf("%d", &decision);
                    add_element_begin(array, decision);
                    break;
            case 3: printf("\nSorting array with bubble sort.");
                    bubble_sort(array);
                    break;
            case 4: printf("\nSorting array with insertion sort.");
                    insertion_sort(array);
                    break;
            case 5: printf("\nSorting array with selection sort.");
                    insertion_sort(array);
                    break;
            case 6: printf("\nSorting array with quick sort.");
                    quick_sort(array);
                    break;
            case 7: printf("\nSorting array with merge sort.");
                    merge_sort(array);
                    break;
            case 8: printf("\nSorting array with heap sort.");
                    heap_sort(array);
                    break;
            case 9: printf("\nSorting array with radix sort.");
                    radix_sort(array);
                    break;
            case 10: printf("\nSorting array using all types of sort.");
                    all_sort(array);
                    break;
            case 11: printf("\nBest time %f with %s.", G_BEST_TIME, G_BEST_METHOD);
                    break;
            case 12: if(G_ACTIVATE_PRINT == 0){
                        printf("\nPrinting array after sort activated.");
                        G_ACTIVATE_PRINT = 1;
                     } else {
                        printf("\nPrinting array after sort deactivated.");
                        G_ACTIVATE_PRINT = 0;
                     }
                     break;
            case 13: printf("\nHow many numbers do you want to be added to array: ");
                     scanf("%d", &decision);
                     random_numbers_to_array(array, decision);
                     break;
            case 14: printf("\nOriginal array without any sorting is: ");
                     print_array(array);
                     break;
            case 15: if(G_BEST_NUMBER == 999){
                        printf("\nNo sorting for current array was selected.");
                        break;
                     }
                     printf("Which is the number you want to search: ");
                     scanf("%d", &decision);
                     binary_search(array, decision);
                     break;
            case 16: printf("Which is the number you want to search: ");
                     scanf("%d", &decision);
                     linear_search(array, decision);
                     break;
            case 17: printf("\nExiting.");
                     return;
                     break;
            default: printf("\nInvalid option. Please try again.\n");
                     break;

        }
    }




}
