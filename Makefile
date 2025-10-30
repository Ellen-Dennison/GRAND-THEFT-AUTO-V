# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = nursery

# Source files
SOURCES = main.cpp \
          Plant.cpp \
          Flower.cpp \
          Herb.cpp \
          Succulent.cpp \
          Tree.cpp \
          FlowerFactory.cpp \
          HerbFactory.cpp \
          SucculentFactory.cpp \
          TreeFactory.cpp \
          PlantFactory.cpp \
          SeedlingState.cpp \
          GrowingState.cpp \
          MatureState.cpp \
          FloweringState.cpp \
          WiltingState.cpp \
		  DeadState.cpp \
		  PlantState.cpp \
          WateringStrategy.cpp \
		  DailyWateringStrategy.cpp \
		  WeeklyWateringStrategy.cpp \
		  BiWeeklyWateringStrategy.cpp \
		  PlantDecorator.cpp \
		  GiftWrappingDecorator.cpp \
		  DecorativePotDecorator.cpp 

# Object files (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target - builds the executable
all: $(TARGET)
	@echo "Build complete! Run with 'make run'"

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Executable '$(TARGET)' created successfully!"

# Compile source files to object files
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@echo ""
	./$(TARGET)

# Clean up generated files
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Phony targets (not actual files)
.PHONY: all run clean
