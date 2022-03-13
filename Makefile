#
#       IJC-1 
#       Author : Pomsar Jakub
#       Date : March 10, 2022
#${CC} ${CFLAGS} -DUSE_INLINE primes.c -o primes
#

CC = gcc
CFLAGS = -O0 -g -std=c11 -pedantic -Wall -Wextra -lm

make: primes.c
	${CC} ${CFLAGS} primes.c -o primes

run: make
	./primes
	./primes-i

32: primes.c
	${CC} -m32 primes.c -o primes
	${CC} -m32 -DUSE_INLINE primes.c -o primes

e:
	${CC} -E primes.c

clean:
	rm -rf primes primes-i .dSYM
