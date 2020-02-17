GCC = g++

driver: driver.o
	$(GCC) -o driver driver.o -std=c++11

driver.o: driver.cpp
	$(GCC) -c -o driver.o driver.cpp -std=c++11

run: driver
	./driver

clean:
	rm -rf driver.o driver