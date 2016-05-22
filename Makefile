# Makefile for Automatic Differentiation library tests
# Mitch Lane
# Senior Project
# CPE 491

CC = g++
CFLAGS = -I /usr/include/eigen3 -std=c++0x -O2 -o ad

all:
	$(CC) $(CFLAGS) main2.cpp

clean:
	rm ad
