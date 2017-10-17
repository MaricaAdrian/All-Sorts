///\file header.h
///\brief Header file where all head declarations are.
///
#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

 /** A Struct type. 
     *  Where we can store our array.
     */
struct Array{

    int number; /**< Number from array. */  
    struct Array *next; /**< Memory address of the next number. */  

}Array; /**< Our main array. */  

extern double G_BEST_TIME; /**< Value used to determine which sorting has the best time. */  
extern char G_BEST_METHOD[100]; /**< String where is saved the name of the best sorting method. */  
clock_t begin_time; /**< Used to determine the time took for each sorting. */  
clock_t end_time; /**< Used to determine the time took for each sorting. */  
extern int G_ACTIVATE_PRINT; /**< Determines if after each sorting the output should be printed to console. */  
extern int G_BEST_NUMBER; /**< Eaching sorting has a number, it's used for determining the best sort for an binary search. */

void random_numbers_to_array(struct Array *array, int numbers); /**< Used to generate numbers and push them into the list. */
void add_element(struct Array *array, int element);  /**< Add given element to the end of array. */
void add_element_begin(struct Array *array, int element); /**< Add given element to the beginning of array. */
void print_array(struct Array *array); /**< Prints the unmodified array. */
void quickSort(int *arr, int low, int high); /**< Used for quick sorting. Ends when low is greather than high.*/
int * copy_array(struct Array *array, int size); /**< Copy the array into a pointer so we can do operations without altering the original one.*/
int * bubble_sort(struct Array *array); /**< Bubble sorts the given array.*/
int * insertion_sort(struct Array *array); /**< Insertion sorts the given array.*/
int * selection_sort(struct Array *array); /**< Selection sorts the given array.*/
int * quick_sort(struct Array *array); /**< Quick sorts the given array.*/
int * merge_sort(struct Array *array); /**< Merge sorts the given array.*/
int * heap_sort(struct Array *array); /**< Heap sorts the given array.*/
int * radix_sort(struct Array *array); /**< Radix sorts the given array.*/
int * sort_with_best(struct Array *array, int size); /**< Sorts the given array with the best method found so far and it returns the sorted array.*/
int partition (int *arr, int low, int high); /**< Partition used for quick sort. It's swaping the pivot with the lowest.*/
int getMax(int *arr, int n); /**< Get's the maximum element from an array. Used for radix sort.*/
int size_of(struct Array *array); /**< Returns the size of the given array.*/
void mergeSort(int *arr, int l, int r); /**< Calls the functions for merge sorting.*/
void merge(int *arr, int l, int m, int r); /**< Merge two arrays. From 0 to m - 1 and from r -m to r. Used for merge sorting.*/
void heapify(int *arr, int n, int i); /**< Heapify the given array.*/
void heapSort(int *arr, int n); /**< Calls heapify function for heap sort.*/
void radixsort(int *arr, int n); /**< Calls the countSort and getMax functions for radix sort.*/
void countSort(int *arr, int n, int exp); /**< Used for counting the output array for radix sort.*/
void all_sort(struct Array *array); /**< Sorts given array with all sorting methods.*/
void binary_search(struct Array *array, int number); /**< Binary search the given number into the given array.*/
void linear_search(struct Array *array, int number); /**< Linear search the given number into the given array.*/
void begin_clock(); /**< Starts time counting for determining how long does an opreations take. */
void end_clock(char sorting_method[100], unsigned int sorting_number); /**< Ends time counting, and prints the result. */
#endif