#
#		Makefile
#       IJC-DU1 
#       Author : Pomsar Jakub
#		Organization : VUT FIT
#       Date : March 10, 2022
#

CC = gcc
CFLAGS = -O2 -g -std=c11 -pedantic -Wall -Wextra -lm
FILES = primes.c bitset.c error.c eratosthenes.c

make: primes.c error.c bitset.c eratosthenes.c
	${CC} ${CFLAGS} -o primes ${FILES}
	${CC} ${CFLAGS} -DUSE_INLINE -o primes-i ${FILES}

i: primes.c
	${CC} ${CFLAGS} -DUSE_INLINE -o primes-i ${FILES}

macro: primes.c
	${CC} ${CFLAGS} -o primes ${FILES}
	
run: make
	./primes
	./primes-i

32: primes.c
	${CC} -m32 primes.c -o primes
	${CC} -m32 -DUSE_INLINE primes.c -o primes

e: primes.c
	${CC} -E -P primes.c

fac: make
	./primes|factor
	./primes|factor

time: make
	time ./primes
	time ./primes