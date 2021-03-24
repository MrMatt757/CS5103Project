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

#endif


