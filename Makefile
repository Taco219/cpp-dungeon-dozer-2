TARGET=DungeonDozer2

SOURCE_DIRECTORY=./src/
ODIR=./obj/
SDIR = ./src/

SOURCES=$(wildcard ${SOURCE_DIRECTORY}/**/*.cpp) \
	$(wildcard ${SOURCE_DIRECTORY}/main.cpp) \
	$(wildcard ${SOURCE_DIRECTORY}/application.cpp) 

_OBJ = $(SOURCES:.cpp=.o)  
OBJ = $(addprefix $(ODIR), $(notdir $(_OBJ)))

CFLAGS=-Wall -Iinclude -Iinclude/interface -Werror -Wextra -pedantic -ggdb -O0 -std=c++11
LIBS=-pthread
CXX=g++

.phony: all clean test

all: $(TARGET)

$(ODIR)%.o: $(SDIR)%.cpp $(DEPS)
	@$(CXX) -c -o $@ $< $(CFLAGS)
$(ODIR)%.o: $(SDIR)**/%.cpp $(DEPS)
	@$(CXX) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	@$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	@rm -rf $(TARGET) $(TEST) $(OBJ)