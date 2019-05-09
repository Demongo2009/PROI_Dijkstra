
CC = g++
CFLAGS = -Wall -g
TARGET = main
SOURCES = Main.cpp
OBJECTS = Main.o


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS)  build/Main.o -o bin/$(TARGET)

test: Tests.o
	$(CC) $(CFLAGS)  test/Tests.o -o test/test

Main.o: include/Graph.h include/MinPriorityQueue.h include/DijkstraManager.h include/Path.h include/Edge.h include/Node.h include/PriorityDummy.h
	$(CC) $(CFLAGS) -c src/Main.cpp -o build/Main.o

Tests.o: include/Graph.h include/MinPriorityQueue.h include/DijkstraManager.h include/Path.h include/Edge.h include/Node.h include/PriorityDummy.h
	$(CC) $(CFLAGS) -c test/Tests.cpp -o test/Tests.o

# DijkstraManager.o: include/DijkstraManager.h include/Graph.h include/Path.h include/MinPriorityQueue.h
# 	$(CC) $(CFLAGS) -c src/DijkstraManager.cpp -o build/DijkstraManager.o
#
# Node.o: include/Node.h include/Edge.h
# 	$(CC) $(CFLAGS) -c src/Node.cpp -o build/Node.o
#
# Edge.o: include/Edge.h include/Node.h
# 	$(CC) $(CFLAGS) -c src/Edge.cpp -o build/Edge.o
#
# Graph.o: include/Graph.h include/Node.h include/Edge.h
# 	$(CC) $(CFLAGS) -c src/Graph.cpp -o build/Graph.o
#
# Path.o: include/Path.h include/Graph.h
# 	$(CC) $(CFLAGS) -c src/Path.cpp -o build/Path.o
#
# PriorityDummy.o: include/PriorityDummy.h
# 	$(CC) $(CFLAGS) -c src/PriorityDummy.cpp -o build/PriorityDummy.o
#
# MinPriorityQueue.o: include/MinPriorityQueue.h include/PriorityDummy.h
# 	$(CC) $(CFLAGS) -c src/MinPriorityQueue.cpp -o build/MinPriorityQueue.o

.PHONY:clean
clean:
	-rm build/*.o
	-rm bin/main
