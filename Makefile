#
#		Makefile
#       IJC-DU1 
#       Author : Pomsar Jakub
#		Organization : VUT FIT
#       Date : March 10, 2022
#

CC = gcc
CFLAGS = -O2 -g -std=c11 -pedantic -Wall -Wextra -lm

make: primes.c
	${CC} ${CFLAGS} primes.c -o primes
	${CC} ${CFLAGS} -DUSE_INLINE primes.c -o primes-i

i: primes.c
	${CC} ${CFLAGS} -DUSE_INLINE primes.c -o primes-i

run: make
	./primes
	./primes-i

32: primes.c
	${CC} -m32 primes.c -o primes
	${CC} -m32 -DUSE_INLINE primes.c -o primes

e:
	${CC} -E -P primes.c

fac: make
	./primes|factor
	./primes|factor

time: make
	time ./primes
	time ./primes