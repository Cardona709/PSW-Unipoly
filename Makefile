# - Linux:
# make					# build DragonsBane.exe
# make run			# run DragonsBane.exe
# make clean		# remove ALL binaries and objects

# Compiler to use
CXX = g++

# Flags
SRCS_FLAGS = -g -std=c++11 -Iinclude -Wall

OBJS :=  Player.o Dice.o Property.o Faculty.o Station.o Utility.o Board.o Game.o Cards.o #Server.o 

all:  Unipoly

run: Unipoly
	./$<

Unipoly: src/main.cpp $(OBJS)
	${CXX} ${SRCS_FLAGS} $< $(OBJS) -o $@

%.o: src/logic/%.cpp
	@echo "Creating object $@.."
	${CXX} ${SRCS_FLAGS} -c $^


clean:
	@echo "Cleaning up..."
	rm -f *.o Unipoly


