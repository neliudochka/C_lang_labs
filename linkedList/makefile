programName := harryPotterBookCollection
location := ./src
dep := bookCollection.c

$(programName): $(location)/main.c $(location)/$(dep)
	gcc -o $(programName) $(location)/main.c $(location)/$(dep)

clean:
	rm $(programName)