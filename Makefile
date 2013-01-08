APP = A3P11
OBJ = compute.o generic.o main.o pascal.o transform.o

.PHONY: clean program

program: $(OBJ)
	g++ $(OBJ) -o $(APP)

%.o: src/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o
	rm $(APP)

