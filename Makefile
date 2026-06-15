.PHONY: usage build

BUILDS := $(shell pwd)/build
INCLUDE := $(shell pwd)/include
EXAMPLES := $(shell pwd)/source/examples

# recipes
usage:
	cat Makefile.usage.txt

build:
	gcc -std=c90 -Werror -Wpedantic -Wall -Wextra -I "$(INCLUDE)" -c -x c $(EXAMPLES)/instance.c -o $(BUILDS)/instance.o
	gcc $(BUILDS)/instance.o -o $(BUILDS)/instance -lvulkan
