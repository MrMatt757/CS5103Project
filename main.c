/*
* Name: Matthew Espinosa
* Project: Word Statistics
* Program: Can utilize command line to take a .txt file as the 2nd argument, and can display
* the amount of words that are present in the file, utilizing whitespace as the delimiter. 
*/

#include <stdio.h>
#include "wordsProcessorLL.h"

int main(int argc, char* argv[]){

    char* oldWord = "first";
    char* newWord = "second";
    
    // check if argument structure is correct
    if(argc != 3){
	printf("Usage: ./execName fileName outFile\n");
	return -1;
    }

    // open a file with argv[1] as the name and check if it is valid
    FILE* txtFile = fopen(argv[1], "r");
    FILE* outFile = fopen(argv[2], "w");
    if(txtFile == NULL){
	printf("Invalid file name\n");
	return -1;
    }

    LLnode* head = countWordsWithLinkedList(txtFile);		// returns head of list of words in a .txt file

    printLineCountInFile(txtFile);

    rewind(txtFile);

    printWordsLinkedList(head, argv[1]);			// print words in linked list head of file argv[1]

    int charCount = getCharCountInList(head);
    printf("\nThe total number of chars in the file is %d.\n\n", charCount);

    rewind(txtFile);

    replaceWordsInFile(oldWord, newWord, txtFile, outFile);

    rewind(txtFile);
    
    destroyWords(head);						// free list
    fclose(txtFile);
    fclose(outFile);
}
