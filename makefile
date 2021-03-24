
word-count : main.o wordsProcessorLL.o 
	gcc main.o wordsProcessorLL.o -o word-count

main.o : main.c wordsProcessorLL.h
	gcc -c main.c

wordsProcessorLL.o : wordsProcessorLL.c wordsProcessorLL.h
	gcc -c wordsProcessorLL.c

clean :
	rm *.o word-count 
