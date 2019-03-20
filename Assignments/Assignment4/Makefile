all: huff

huff: HuffmanCompress.o PriorityQueue.h Node.h BinaryNode.o BitStream.o HuffmanTree.o HuffmanCode.o FrequencyCounter.o EmptyDataCollectionException.o
	g++ -Wall -std=c++98 -o huff HuffmanCompress.o BinaryNode.o BitStream.o HuffmanTree.o HuffmanCode.o FrequencyCounter.o EmptyDataCollectionException.o

HuffmanCompress.o: HuffmanCompress.cpp
	g++ -c HuffmanCompress.cpp

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	g++ -c BinaryNode.cpp

BitStream.o: BitStream.cpp BitStream.h
	g++ -c BitStream.cpp

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	g++ -c HuffmanTree.cpp

HuffmanCode.o: HuffmanCode.cpp HuffmanCode.h
	g++ -c HuffmanCode.cpp

FrequencyCounter.o: FrequencyCounter.cpp FrequencyCounter.h
	g++ -c FrequencyCounter.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f huff *.o