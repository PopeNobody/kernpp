all: libs tests
	
libs: openhack.so datehack.so

tests: mvit accessit stattest

%.o: %.c
	g++ -ggdb3 $< -o $@

mvit accessit stattest: %: %.o
	g++ -ggdb3 $< -o $@

datehack.so openhack.so: O=$(<:.c=.o)
openhack.so datehack.so: %.so: %.c
	gcc -ggdb3 -Wall -fPIC -DPIC -c $< -o $O
	ld -shared -o $@ $O -ldl

