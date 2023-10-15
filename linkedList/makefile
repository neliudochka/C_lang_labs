programName := mathCalculations
location := ./src
dep := bookCollection.c

$(programName): $(location)/main.c $(location)/$(dep)
	gcc -o mathCalculations $(location)/main.c $(location)/$(dep) -lm

clean:
	rm $(programName)