#Jesus Minjares
CC = g++
Name = assignment_2
Lib = restaurant
Exe = main
$(Exe):	$(Name).o $(Lib).o
	$(CC) $(Name).o $(Lib).o -o $(Exe)
$(Name).o:	$(Name).cpp
	$(CC) -c $(Name).cpp
$(Lib).o:	$(Lib).cpp
	$(CC) -c $(Lib).cpp
clean:
	rm *.txt *.o $(Exe)
