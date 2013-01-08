APP = A3P11
OBJ = decasteljau.o horner.o pascal.o toexpform.o tobezierform.o main.o

.PHONY: clean program

program: $(OBJ)
	g++ $(OBJ) -o $(APP)

%.o: src/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o
	rm $(APP)

