
CC=clang++

CFLAGS=-c -Wall -Wc++11-extensions -std=c++11
LDFLAGS=

SOURCES=ll_list.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE) 
