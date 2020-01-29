TARGET=DungeonDozer2

CFLAGS=-Wall -Iinclude -Werror -Wextra -pedantic -ggdb -O0 -std=c++11

SOURCE_DIRECTORY=./src
INCLUDE_DIRECTORY=./include
TEST_DIRECTORY=./test

SOURCES=$(wildcard ${SOURCE_DIRECTORY}/**/*.cpp) \
	$(wildcard ${SOURCE_DIRECTORY}/main.cpp) \
	$(wildcard ${SOURCE_DIRECTORY}/application.cpp) 

HEADERS=$(wildcard ${INCLUDE_DIRECTORY}/*.hpp) \
        $(wildcard ${INCLUDE_DIRECTORY}/interfaces/*.hpp)

LIBS=-pthread

CXX=g++

.phony: all clean test

all: $(TARGET)

$(TARGET): $(SOURCES)
	@$(CXX) $(CFLAGS) $(SOURCES) -o $@ $(LIBS)

$(TEST): $(TEST_SOURCES)
	@$(CXX) $(CFLAGS) -Itest $(TEST_SOURCES) -o $@ $(TEST_LIBS)

clean:
	@rm -rf $(TARGET) $(TEST)

test: $(TEST)
	@./$(TEST)
