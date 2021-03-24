/*
* Name: Matthew Espinosa
* Assignment: Assignment 1
* Program: Can utilize command line to take a .txt file as the 2nd argument, and can display
* the amount of words that are present in the file, utilizing whitespace as the delimiter. 
*/

#include <stdio.h>
#include "wordsProcessorLL.h"

int main(int argc, char* argv[]){
    
    // check if argument structure is correct
    if(argc != 2){
	printf("Usage: ./execName fileName\n");
	return -1;
    }

    // open a file with argv[1] as the name and check if it is valid
    FILE* txtFile = fopen(argv[1], "r");
    if(txtFile == NULL){
	printf("Invalid file name\n");
	return -1;
    }

    LLnode* head = countWordsWithLinkedList(txtFile);		// returns head of list of words in a .txt file

    rewind(txtFile);

    printLineCountInFile(txtFile);

    printWordsLinkedList(head, argv[1]);			// print words in linked list head of file argv[1]

    int charCount = getCharCountInList(head);
    printf("The total number of chars in the file is %d\n", charCount);

    destroyWords(head);						// free list
}
