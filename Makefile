APP = A3P11
OBJ = compute.o generic.o program.o pascal.o transform.o

.PHONY: clean program tex

program: $(OBJ)
	g++ $(OBJ) -o $(APP)

tex:
	cd doc && pdflatex sprawozdanie.tex

%.o: prog/%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o
	rm -f $(APP)


