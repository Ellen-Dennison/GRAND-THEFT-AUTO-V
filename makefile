# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = nursery
TEST = test_runner

# Source folder
SRC_DIR = src

#Test folder
TST_DIR = tests

# Source files (with src/ prefix)
SOURCES = $(addprefix $(SRC_DIR)/, \
          main.cpp \
          Plant.cpp \
          Flower.cpp \
          Herb.cpp \
          Succulent.cpp \
          Tree.cpp \
          PlantFactory.cpp \
          FlowerFactory.cpp \
          HerbFactory.cpp \
          SucculentFactory.cpp \
          TreeFactory.cpp \
          PlantState.cpp \
          SeedlingState.cpp \
          GrowingState.cpp \
          MatureState.cpp \
          FloweringState.cpp \
          WiltingState.cpp \
          DeadState.cpp \
          WateringStrategy.cpp \
          DailyWateringStrategy.cpp \
          WeeklyWateringStrategy.cpp \
          BiWeeklyWateringStrategy.cpp \
          PlantDecorator.cpp \
          GiftWrappingDecorator.cpp \
          DecorativePotDecorator.cpp \
          PlantMemento.cpp \
          PlantCaretaker.cpp \
          Subject.cpp \
          ManagerObserver.cpp \
          StaffObserver.cpp \
          StaffWorkFlow.cpp \
          StaffWorkFlowDecorator.cpp \
          GreenhouseWorker.cpp \
          SalesAssociate.cpp \
          SalesRole.cpp \
          ManagerRole.cpp \
          LandscaperRole.cpp \
          DeliveryRole.cpp \
          PlantOrder.cpp \
          Customer.cpp \
          NurseryMediator.cpp \
          Command.cpp \
          AdvanceTimeCommand.cpp \
          WaterPlantsCommand.cpp \
          RevivePlantCommand.cpp)

TEST_SOURCES = $(wildcard $(TST_DIR)/*.cpp)
TESTABLE_SOURCES = $(filter-out $(SRC_DIR)/main.cpp, $(SOURCES))

# Object files (strip src/ and replace .cpp with .o) and # Object files for test build
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SOURCES))
TST_OBJECTS = $(patsubst $(TST_DIR)/%.cpp, %.o, $(TEST_SOURCES))
TESTABLE_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(TESTABLE_SOURCES))

# Default target
all: $(TARGET)
	@echo "Build complete! Run with 'make run'"


# Build test executable
$(TEST): $(TESTABLE_OBJECTS) $(TST_OBJECTS)
	@echo "Linking test executable..."
	$(CXX) $(CXXFLAGS) -o $(TEST) $^

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Executable '$(TARGET)' created successfully!"


# Pattern rule for compiling test files
%.o: $(TST_DIR)/%.cpp
	@echo "Compiling test $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile source files to object files
%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@echo ""
	./$(TARGET)

# Run tests
test: $(TEST)
	@echo "Running unit tests..."
	./$(TEST)


# Clean up generated files
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(TARGET) $(TST_OBJECTS) $(TEST) 
	@echo "Clean complete!"

# Phony targets (not actual files)
.PHONY: all run clean

