CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o MaxHeap.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
MaxHeap.o: MaxHeap.cpp MaxHeap.h
	$(CXX) $(CXXFLAGS) MaxHeap.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
