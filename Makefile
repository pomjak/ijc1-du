#
#		Makefile
#       IJC-DU1 
#       Author : Pomsar Jakub
#		Organization : VUT FIT
#       Date : March 10, 2022
#

CC = gcc
CFLAGS = -O2 -g -std=c11 -pedantic -Wall -Wextra 
FILES = primes.c bitset.c error.c eratosthenes.c
SFILES = steg-decode.c ppm.c error.c eratosthenes.c

make: ${FILES}
	${CC} ${CFLAGS} -o primes ${FILES} -lm
	${CC} ${CFLAGS} -DUSE_INLINE -o primes-i ${FILES} -lm
	${CC} ${CFLAGS} -o steg-decode ${SFILES} -lm

steg: make 
	./steg-decode du1-obrazek.ppm 	

i: ${FILES}
	${CC} ${CFLAGS} -DUSE_INLINE -o primes-i ${FILES} -lm

macro: ${FILES}
	${CC} ${CFLAGS} -o primes ${FILES} -lm
	
run: make
	./primes
	./primes-i

32: ${FILES}
	${CC} -m32 -o primes ${FILES} -lm
	${CC} -m32 -DUSE_INLINE -o primes ${FILES} -lm

e: ${FILES}
	${CC} -E -P ${FILES} -lm

fac: make
	./primes|factor
	./primes|factor

time: make
	time ./primes
	time ./primes