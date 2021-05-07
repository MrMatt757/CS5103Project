#include <stdio.h>
#include "wordsProcessorLL.h"

int main(int argc, char* argv[]){
    int flag = 0;

    if(argc != 3){
	    printf("Usage: ./execName fileName outFile\n");
	    return -1;
    }

    FILE* dataFile = fopen(argv[1], "r");
    FILE* outFile = fopen(argv[2], "w");


    printf("Running unit tests on total word count.\n");
    flag = countWordsUnitTest(dataFile);
    if(flag)
        printf("Total word count unit test PASSED.\n");
    else
        printf("Total word count unit test FAILED\n");

    flag = 0;
    rewind(dataFile);

    LLnode* head = countWordsWithLinkedList(dataFile);
    rewind(dataFile);

    printf("\nRunning unit tests on line count.\n");
    
    flag = printLineCountUnitTest(dataFile);
    if(flag)
        printf("Total word count unit test PASSED.\n");
    else
        printf("Total word count unit test FAILED\n");

    flag = 0;
    rewind(dataFile);

    printf("\nRunning unit tests on char count.\n");

    flag = getCharCountUnitTest(head, dataFile);
    if(flag)
        printf("Total word count unit test PASSED.\n");
    else
        printf("Total word count unit test FAILED\n");

    flag = 0;
    rewind(dataFile);

    printf("\nRunning unit tests on unique word count.\n");

    flag = printWordsUnitTest(head, dataFile, argv[1]);
    if(flag)
        printf("Total word count unit test PASSED.\n");
    else
        printf("Total word count unit test FAILED\n");

    flag = 0;
    rewind(dataFile);

    printf("\nRunning unit tests on word replace.\n");
    char* oldWord = "the";
    char* newWord = "Da";

    flag = replaceWordsInFileUnitTest(oldWord, newWord, dataFile, outFile);
    if(flag)
        printf("Total word count unit test PASSED.\n");
    else
        printf("Total word count unit test FAILED\n");

    flag = 0;
    rewind(dataFile);

}