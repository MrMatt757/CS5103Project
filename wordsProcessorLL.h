#ifndef WORDSPROCESSORLL_H
#define WORDSPROCESSORLL_H

typedef struct LLnode{
    char word[50];
    int count;
    struct LLnode* next;
}LLnode;

LLnode* countWordsWithLinkedList(FILE* txtFile);
void printWordsLinkedList(LLnode* head, char* txtFile);
LLnode* createWord(char word[]);
void destroyWords(LLnode* head);
void printLineCountInFile(FILE* txtFile);
int getCharCountInList(LLnode* head);
void replaceWordsInFile(char* oldWord, char* newWord, FILE* dataFile, FILE* outFile);
int countWordsUnitTest(FILE* dataFile);
int printWordsUnitTest(LLnode* head, FILE* dataFile, char* fileName);
int printLineCountUnitTest(FILE* dataFile);
int getCharCountUnitTest(LLnode* head, FILE* dataFile);
int replaceWordsInFileUnitTest(char* oldWord, char* newWord, FILE* dataFile, FILE* outFile);

#endif


