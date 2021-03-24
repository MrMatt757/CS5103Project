#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "wordsProcessorLL.h"

/*
* Function: counts the words in a .txt file and adds them to a linked list.
* Parameters: datafile-.txt file with words.
* Returns: pointer to head of list holding word counts.
*/
LLnode* countWordsWithLinkedList(FILE* dataFile){

    int end = 0;			// end logic checks if condition is met
    char word[50];			// holds word from .txt file
    LLnode* cur;			// pointer to use for inserts
    LLnode* prev;			// pointer to use for inserts

    // return empty pointer if file is NULL
    if(dataFile == NULL)
	return cur;

    // Scan file for first word, use it to make the first node of list 
    fscanf(dataFile, "%s", word);
    LLnode* head = createWord(word);
    head->count++;

    // While the file has a string left, add it to the list appropiately
    while(fscanf(dataFile, "%s", word) == 1){
	
	if(ispunct(word[strlen(word)-1]))
	    word[strlen(word)-1] = '\0';	// eliminate punctuation from words

	LLnode* new = createWord(word);		// create new word node

	cur = head;				// set cur to head at beginning of logic

	// logic if word is the earliest word for O(1) insertion 
	if(strcmp(new->word, head->word) < 0){
	    head = new;
	    head->count++;
	    head->next = cur;
	    continue;
	}
	// logic if word is within the list
	while(cur->next != NULL)
	{
	    prev = cur;		// set prev to point to cur node
	    cur = cur->next;	// cur to next cur node(this is > 0 condition step)

	    // if word comes before cur, place before and increment
	    if(strcmp(new->word, cur->word) < 0){
		prev->next = new;
		new->count++;
		new->next = cur;
		end = 1;
		break;
	    }
	    else if(strcmp(new->word, cur->word) == 0){		// if words are equal, increment cur
		cur->count++;
		end = 1;
		break;
	    }
	}

	// execute instructions at end node if condition not met yet
	if(!end){	
	    if(!strcmp(new->word, cur->word) && cur->next == NULL)
		cur->count++;
	    else if(strcmp(new->word, cur->word) > 0){
		cur->next = new;
		new->count++;
	    }
	}
	end = 0;	// reset end break test
    }
    return head;	// return head of list
}

/*
* Function: prints words in a linked list containing words in table.
* Parameters: head-head of linked list. 
* Returns: nothing
*/
void printWordsLinkedList(LLnode* head, char* fileName){

    int total = 0, totalCount = 0;    		// total: number of words, totalCount: all the node's count  

    printf("The file %s has:\n", fileName); 	// print name of file

    // iterate through list printing contents and incrementing counters appropriately
    while(head != NULL){
	if(head->count == 1)
	    printf("%s\t appears %d time\n", head->word, head->count);
	else
	    printf("%s\t appears %d times\n", head->word, head->count);
	total++;
	totalCount += head->count;
	head = head->next;	
    }

    // List total stats
    printf("\nThe total number of words is %d, the number of different words is %d.\n", totalCount, total);
    
}

/*
* Function: creat10.100.240.201es a word node for a list
* Parameters: word-word to place in node
* Returns: new node with word
*/
LLnode* createWord(char word[]){
   
    LLnode* new = (LLnode*)malloc(sizeof(LLnode));
    strcpy(new->word, word);
    new->count = 0;
    new->next = NULL;

    return new;
}

/*
* Function: frees a word linked list
* Parameters: head of list
* Returns : nothing
*/
void destroyWords(LLnode* head){
    LLnode* tmp;

    while(head != NULL){
	tmp = head;
	head = head->next;
	free(tmp); 
    }
}

/*
*Function: Returns the line count in a file
*Parameters: datafile to parse
*Returns: the line count of the file
*/
void printLineCountInFile(FILE* dataFile){
    int lineCount = 0;
    size_t len = 0;
    char line[500];
    
    while(fgets(line, 500, dataFile)) {
	lineCount++;
    }

    printf("The total number of lines is %d\n", lineCount);
}

/*
*Function: Returns the char count in a word linked list
*Parameters: head of words linked list 
*Returns: The number of chars in a file's word linked list
*/
int getCharCountInList(LLnode* head){
    int charCount = 0;
    LLnode* tmp;

    while(head != NULL){
	tmp = head;
	head = head->next;
	charCount += strlen(tmp->word) * tmp->count;
    }

    return charCount;
}
