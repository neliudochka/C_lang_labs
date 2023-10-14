programName := mathCalculations
location := ./src

$(programName): $(location)/main.c $(location)/functions.c
	gcc -o mathCalculations $(location)//main.c $(location)/functions.c -lm

clean:
	rm $(programName)