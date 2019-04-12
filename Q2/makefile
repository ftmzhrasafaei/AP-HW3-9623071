CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o Vector.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
MaxHeap.o: Vector.cpp Vector.h
	$(CXX) $(CXXFLAGS) Vector.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
