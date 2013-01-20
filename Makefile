APP = A3P11
OBJ = compute.o generic.o main.o pascal.o transform.o

.PHONY: clean program tex

program: $(OBJ)
	g++ $(OBJ) -o $(APP)

tex:
	cd tex && pdflatex p3-11.tex

%.o: src/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o
	rm -f $(APP)


