CXX = g++

SOURCES = main.cpp functions/filter_operator.cpp functions/gaussian_smooth.cpp functions/convolution_algorithm.cpp
EXECUTABLE = compiled
TEMP_FILES = bp_filter.txt convolve.txt gaussian_function.txt

all: $(EXECUTABLE) run clean

$(EXECUTABLE): $(SOURCES) 
	@$(CXX) $(SOURCES) -o $(EXECUTABLE)

run: $(EXECUTABLE)
	@echo "Compiling C++ file..."
	@./$(EXECUTABLE)
	@python3 functions/plotting_functions.py

clean:
	@echo "Cleaning temp files..."
	@rm -f $(EXECUTABLE) $(TEMP_FILES)

.PHONY: all run clean
