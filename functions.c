///\file functions.c
///\brief File where all functions are found.
///
#include "header.h"

double G_BEST_TIME = 999999; /**< Value used to determine which sorting has the best time. */  
char G_BEST_METHOD[100]; /**< String where is saved the name of the best sorting method. */  
clock_t begin_time; /**< Used to determine the time took for each sorting. */  
clock t end_time; /**< Used to determine the time took for each sorting. */  
int G_ACTIVATE_PRINT = 0; /**< Determines if after each sorting the output should be printed to console. */  
int G_BEST_NUMBER = 999; /**< Eaching sorting has a number, it's used for determining the best sort for an binary search. */

/*! \fn void random_numbers_to_array(struct Array *array, int numbers)
    \brief Generates random numbers and put them into the array.
    \param array is the array where the numbers will e generated.
	\param numbers determins how many numbers will be generated.
*/

void random_numbers_to_array(struct Array *array, int numbers){

    int i;
    for(i = 0; i < numbers; i++)
        add_element_begin(array, rand());
    G_BEST_TIME = 999999;
}

/*! \fn void add_element(struct Array *array, int element)
    \brief Add an element to the array end.
    \param array is the array where the number will be placed.
	\param element is the number that will be placed.
*/

void add_element(struct Array *array, int element){

    struct Array *iterator = array;
    struct Array *newElement = malloc(sizeof(struct Array));

    while(iterator->next != NULL){
        iterator = iterator->next;
    }

    iterator->next = newElement;
    newElement->number = element;
    newElement->next = NULL;
    printf("\nSuccessfully added %d to the array.", element);
    return;

}


/*! \fn void add_element_begin(struct Array *array, int element)
    \brief Add an element to the beginning of array.
    \param array is the array where the number will be placed.
	\param element is the number that will be placed.
*/

void add_element_begin(struct Array *array, int element){

    int value;
    struct Array* newElement = malloc(sizeof(struct Array));

    newElement->next = array->next;
    array->next = newElement;
    newElement->number = element;
    printf("\nSuccessfully added %d to the array.", element);
    return;

}

/*! \fn void print_array(struct Array *array)
    \brief Prints the unmodified array.
    \param array is the original array without any sorting.
*/

void print_array(struct Array *array){

    struct Array *iterator = array;

    while(iterator->next != NULL){
        printf("%d ", iterator->next->number);
        iterator = iterator->next;
    }

}

/*! \fn void print_array(struct Array *array)
    \brief Prints the unmodified array.
    \param array which size will be returned.
	\return Size of array
*/

int size_of(struct Array *array){

    struct Array *iterator = array;
    unsigned int counter = 0;

    while(iterator->next != NULL){
        counter++;
        iterator = iterator->next;
    }

    return counter;

}

/*! \fn int * copy_array(struct Array *array, int size)
    \brief Copy the unmodified array into a temporary array in order to make sortings without modified the original array.
    \param array That will be copied.
	\param size Size of unmodified array.
*/

int * copy_array(struct Array *array, int size){

    struct Array *iterator = array;
    int *copy_array = malloc(size * sizeof(int));
    unsigned counter = 0;

    while(iterator->next != NULL){
        copy_array[counter] = iterator->next->number;
        iterator = iterator->next;
        counter++;
    }

    return copy_array;
}

/*! \fn int * bubble_sort(struct Array *array)
    \brief Bubble sorts the given array.
	\param array The array which will be bubble sorted.
*/

int * bubble_sort(struct Array *array){
    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    begin_clock();

    for(i = 0; i < size_array - 1; i++)
        for(j = i + 1; j < size_array; j++){
            if(aux[i] > aux[j]){
                aux_number = aux[i];
                aux[i] = aux[j];
                aux[j] = aux_number;
            }
        }
    end_clock("Bubble sort", 1);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;

}

/*! \fn int * insertion_sort(struct Array *array)
    \brief Insertion sorts the given array.
	\param array The array which will be insertion sorted.
*/

int * insertion_sort(struct Array *array){
    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    begin_clock();

    for(i = 1; i < size_array; i++){
        aux_number = aux[i];
        j = i - 1;
        while(j >= 0 && aux[j] > aux_number){
            aux[j + 1] = aux[j];
            j = j - 1;
        }
        aux[j + 1] = aux_number;
    }

    end_clock("Insertion sort", 2);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;

}

/*! \fn int * selection_sort(struct Array *array)
    \brief Selection sorts the given array.
	\param array The array which will be selection sorted.
*/

int * selection_sort(struct Array *array){
    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    int swap_number;
    begin_clock();
    for (i = 0; i < size_array-1; i++){
        aux_number = i;
        for (j = i+1; j < size_array; j++)
            if (aux[j] < aux[aux_number])
                aux_number = j;

        swap_number = aux[i];
        aux[i] = aux[aux_number];
        aux[aux_number] = swap_number;
    }

    end_clock("Selection sort", 3);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;
}

/*! \fn int * quick_sort(struct Array *array)
    \brief Quick sorts the given array.
	\param array The array which will be quick sorted.
*/

int * quick_sort(struct Array *array){


    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    int swap_number;
    begin_clock();

    quickSort(aux, 0, size_array-1);

    end_clock("Quick sort", 4);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;
}


void quickSort(int *arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (int *arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    int aux;

    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    aux = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = aux;
    return (i + 1);
}

/*! \fn int * merge_sort(struct Array *array)
    \brief Merge sorts the given array.
	\param array The array which will be merge sorted.
*/

int * merge_sort(struct Array *array){

    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    int swap_number;
    begin_clock();

    mergeSort(aux, 0, size_array - 1);

    end_clock("Merge sort", 5);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;

}

void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/*! \fn int * heap_sort(struct Array *array)
    \brief Heap sorts the given array.
	\param array The array which will be heap sorted.
*/

int * heap_sort(struct Array *array){

    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    int swap_number;
    begin_clock();

    heapSort(aux, size_array);

    end_clock("Heap sort", 6);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;

}

void heapify(int *arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int aux;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i){
        aux = arr[largest];
        arr[largest] = arr[i];
        arr[i] = aux;

        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    int i;
    int aux;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i= n - 1; i >= 0; i--)
    {
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        heapify(arr, i, 0);
    }
}

/*! \fn int * radix_sort(struct Array *array)
    \brief Radix sorts the given array.
	\param array The array which will be heap radix.
*/

int * radix_sort(struct Array *array){

    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int i;
    int j;
    int aux_number;
    int swap_number;
    begin_clock();

    radixsort(aux, size_array);

    end_clock("Radix sort", 7);

    if(G_ACTIVATE_PRINT == 1){
        printf("\nArray after sorting: ");

        for(i = 0; i < size_array; i++)
            printf("%d ", aux[i]);
    }

    return aux;
}

void radixsort(int *arr, int n){

    int m = getMax(arr, n);
    int exp;

    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void countSort(int *arr, int n, int exp){
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

/*! \fn int getMax(int *arr, int n)
    \brief Used to get the largest number in the array
	\param arr The array from where the largest number will be extracted.
	\param n Size of the array.
*/

int getMax(int *arr, int n){
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

/*! \fn void all_sort(struct Array *array)
    \brief Used for sorting current array with all types of sort.
	\param array The array that will be sorted.
*/

void all_sort(struct Array *array){

    printf("\nSorting array with bubble sort.");
    bubble_sort(array);
    printf("\nSorting array with insertion sort.");
    insertion_sort(array);
    printf("\nSorting array with selection sort.");
    selection_sort(array);
    printf("\nSorting array with quick sort.");
    quick_sort(array);
    printf("\nSorting array with merge sort.");
    merge_sort(array);
    printf("\nSorting array with heap sort.");
    heap_sort(array);
    printf("\nSorting array with radix sort.");
    radix_sort(array);

}

/*! \fn int * sort_with_best(struct Array *array, int size)
    \brief Used for sorting current array with the best sorting method found so far.
	\param array The array that will be sorted.
	\param size Size of the array.
*/

int * sort_with_best(struct Array *array, int size){

    int *aux;

    if(G_BEST_NUMBER == 1){
        aux = bubble_sort(array);
    } else if (G_BEST_NUMBER == 2){
        aux = insertion_sort(array);
    } else if (G_BEST_NUMBER == 3){
        aux = selection_sort(array);
    } else if (G_BEST_NUMBER == 4){
        aux = quick_sort(array);
    } else if (G_BEST_NUMBER == 5){
        aux = merge_sort(array);
    } else if (G_BEST_NUMBER == 6){
        aux = heap_sort(array);
    } else if (G_BEST_NUMBER == 7){
        aux = radix_sort(array);
    }

    return aux;
}

/*! \fn void binary_search(struct Array *array, int number)
    \brief Sorts the given array with the best method than applys binary search on it.
	\param array The array that will be sorted and searched from.
	\param number Number that will be searched.
*/

void binary_search(struct Array *array, int number){

    int size_array = size_of(array);
    int *aux = sort_with_best(array, size_array);
    int aux_number;
    int left;
    int right;
    int middle;

    begin_clock();

    left = 0;
    right = size_array - 1;

    while (left <= right){
        middle = left + (right - left)/2;
        if (aux[middle] == number){
            printf("\nNumber %d found at position %d.", number, middle);
            break;
        }
        if (aux[middle] < number)
            left = middle + 1;
        else
            right = middle - 1;
    }

    if(left > right)
        printf("\nNumber %d was not found in the array.", number);

    end_clock("Binary search", 8);

}

/*! \fn linear_search(struct Array *array, int number)
    \brief Linear search for a number into a given array.
	\param array The array that will be sorted and searched from.
	\param number Number that will be searched.
*/


void linear_search(struct Array *array, int number){

    int size_array = size_of(array);
    int *aux = copy_array(array, size_array);
    int aux_number;

    begin_clock();

    for(aux_number = 0; aux_number < size_array; aux_number++){
        if(aux[aux_number] == number){
            printf("Number %d found at position %d.", number, aux_number + 1);
            end_clock("Linear search", 9);
            return;
        }
    }



    printf("\nNumber %d was not found in the array.", number);
    end_clock("Linear search", 9);
}

/*! \fn begin_clock()
    \brief Starts a clock for counting how many seconds did a function take.
*/

void begin_clock(){

    begin_time = clock();

}

/*! \fn void end_clock(char sorting_method[100], unsigned int sorting_number)
    \brief Ends the started clock.
	\param sorting_method used for knowing which is the name of the best sorting method.
	\param sorting_number each sorting has a specified number, used function sort_with_best
*/

void end_clock(char sorting_method[100], unsigned int sorting_number){

    double aux_time;
    end_time = clock();

    aux_time = (double)(end_time - begin_time) / CLOCKS_PER_SEC;

    if(sorting_number <= 7){
        printf("\nSorting took %.5lf seconds.", aux_time);
    } else {
        printf("\nSearching took %.5lf seconds.", aux_time);
    }

    if(aux_time < G_BEST_TIME && sorting_number <= 7){
        printf("\nCurrent method has the best time for this array.");
        G_BEST_TIME = aux_time;
        G_BEST_NUMBER = sorting_number;
        strcpy(G_BEST_METHOD, sorting_method);
    }


}