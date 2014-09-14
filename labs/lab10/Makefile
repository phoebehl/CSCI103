CXX=g++
CXXFLAGS=-Wall -g
SRCS = action.cpp moveAction.cpp moneyAction.cpp player.cpp test_action.cpp
OBJ = $(SRCS:.cpp=.o)

all: test_action

test_action: $(OBJ)
	$(CXX) $(CXXFLAGS) -o test_action $(OBJ)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

action.o: action.h

moveAction.o: moveAction.h

moneyAction.o: moneyAction.h

player.o: player.h

clean:
	rm -f *.o *~