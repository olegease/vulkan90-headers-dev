.PHONY: usage build

BUILDS := $(shell pwd)/build
INCLUDE := $(shell pwd)/include
SOURCE := $(shell pwd)/source
EXAMPLES := $(shell pwd)/source/examples

# recipes
usage:
	cat Makefile.usage.txt

build:
	gcc -std=c90 -Werror -Wpedantic -Wall -Wextra -I "$(INCLUDE)" -c -x c $(SOURCE)/vulkan90.c -o $(BUILDS)/vulkan90.o
	gcc -std=c90 -Werror -Wpedantic -Wall -Wextra -I "$(INCLUDE)" -c -x c $(EXAMPLES)/instance.c -o $(BUILDS)/instance.o
	gcc $(BUILDS)/vulkan90.o $(BUILDS)/instance.o -o $(BUILDS)/instance -lvulkan
