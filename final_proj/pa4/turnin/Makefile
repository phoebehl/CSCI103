CXX=g++
CXXFLAGS=-Wall -g
SRCS = action.cpp game_board.cpp space.cpp player.cpp pa4.cpp
OBJ = $(SRCS:.cpp=.o)

all: pa4

pa4: $(OBJ)
	$(CXX) $(CXXFLAGS) -o pa4 $(OBJ)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

action.o: action.h

game_board.o: game_board.h

space.o: space.h

player.o: player.h

clean:
	rm -f *.o *~