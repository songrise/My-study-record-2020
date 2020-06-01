#
# Makefile that builds excutable files for format1 task2 
# 

CC = g++
# CFLAGS = -Wall
# LIBS = 

build: TTT.h GameHost.cpp Judge.cpp UI.cpp CompPlayer.cpp Main.cpp 
	$(CC) $(CFLAGS) $(LIBS) -o TTT GameHost.cpp Judge.cpp UI.cpp CompPlayer.cpp Main.cpp

clean: 
	rm -f TTT
