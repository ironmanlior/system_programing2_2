#!make -f

CXX=g++
CXXFLAGS=-std=c++11 -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp
OBJECTS=Graph.o Algorithms.o

all: demo1 test1 demo2 test2 

run1: demo1
	./$^

run2: demo2
	./$^

demo1: Demo1.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo1

test1: TestCounter.o Test1.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test1

demo2: Demo2.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo2

test2: TestCounter.o Test2.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test2

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo2 test2
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo2 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test2 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo2 test2