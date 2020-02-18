GCC = g++

driver: driver.o database_tools.o
	$(GCC) -o driver driver.o database_tools.o -std=c++11

driver.o: driver.cpp database_tools.o
	$(GCC) -c -o driver.o driver.cpp -std=c++11

database_tools: database_tools.o
	$(GCC) -o database_tools database_tools.o -std=c++11

database_tools.o: database_tools.cpp
	$(GCC) -c -o database_tools.o database_tools.cpp -std=c++11

run: driver
	./driver

clean:
	rm -rf driver.o driver