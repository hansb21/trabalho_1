APP_NAME=xml-verifier

CC = g++
CFLAGS = -Wall -std=c++11

TEST_CFLAGS = -fsanitize=leak
DEBUG_CFLAGS = $(TEST_CFLAGS) -Werror -D DEBUG -O0
BUILD_CFLAGS = -D NDEBUG -O2

TARGETS = src/main.cpp src/xml.cpp src/counter.cpp
DEPS = $(TARGETS)  src/linked_queue.h src/linked_queue.cpp src/counter.h

default: $(DEPS)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $(APP_NAME).out $(TARGETS)

test:
	make default
	./$(APP_NAME).out

debug: $(DEPS)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -o $(APP_NAME).out -g $(TARGETS)

gdb:
	make debug
	gdb $(APP_NAME).out

build: $(DEPS)
	$(CC) $(CFLAGS) $(BUILD_CFLAGS) -o $(APP_NAME).out $(TARGETS)

clean:
	rm *.out
