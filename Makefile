# Makefile for Automatic Differentiation library tests
# Mitch Lane
# Senior Project
# CPE 491

CC = g++
CFLAGS = -std=c++0x -O2 -o ad

all:
	$(CC) $(CFLAGS) main.cpp

clean:
	rm ad
