CXX = g++  # Define the C++ compiler
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror  # Compiler flags

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

TARGET = hw5

all: $(TARGET)

$(TARGET): main.o $(SRC_DIR)/Organism.o $(SRC_DIR)/Ant.o $(SRC_DIR)/Queen.o $(SRC_DIR)/Worker.o $(SRC_DIR)/Male.o $(SRC_DIR)/DoodleBug.o $(SRC_DIR)/World.o
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(TARGET) $^  # Link object files into the executable

main.o: main.cpp $(INC_DIR)/World.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c main.cpp -o $(SRC_DIR)/$@  # Compile main.cpp

$(SRC_DIR)/Organism.o: $(SRC_DIR)/Organism.cpp $(INC_DIR)/Organism.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile Organism.cpp

$(SRC_DIR)/Ant.o: $(SRC_DIR)/Ant.cpp $(INC_DIR)/Ant.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile Ant.cpp

$(SRC_DIR)/Queen.o: $(SRC_DIR)/Queen.cpp $(INC_DIR)/Queen.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile Queen.cpp

$(SRC_DIR)/Worker.o: $(SRC_DIR)/Worker.cpp $(INC_DIR)/Worker.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile Worker.cpp

$(SRC_DIR)/Male.o: $(SRC_DIR)/Male.cpp $(INC_DIR)/Male.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile Male.cpp

$(SRC_DIR)/DoodleBug.o: $(SRC_DIR)/DoodleBug.cpp $(INC_DIR)/DoodleBug.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile DoodleBug.cpp

$(SRC_DIR)/World.o: $(SRC_DIR)/World.cpp $(INC_DIR)/World.hpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@  # Compile World.cpp

clean:
	rm -f $(BIN_DIR)/$(TARGET) $(SRC_DIR)/*.o  # Remove the executable and object files
