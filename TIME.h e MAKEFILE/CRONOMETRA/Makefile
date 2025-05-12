# Makefile per usare i file cronmetra e cronometrare_il_codice e head.h

# PER PRIMA COSA, NEL TERMINALE SCRIVI: make
# PER ESEGUIRE IL FILE: ./cronometra_executable 
# PER PULIRE: make clean

# Define the C compiler to use
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall

# Define any directories containing header files
INCLUDES = -I.

# Define library paths in addition to /usr/lib
# LFLAGS = -L/path/to/libraries

# Define any libraries to link into executable
# LIBS = -lmylibrary

# Define the C source files
SRCS = cronometra.c cronometrare_il_codice.c

# Define the C object files   
OBJS = $(SRCS:.c=.o)

# Define the executable file   
MAIN = cronometra_executable

.PHONY: depend clean

all:    $(MAIN)
	@echo  Cronometra has been compiled
    
$(MAIN): $(OBJS)   
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)  
    
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
    
clean:
	$(RM) *.o *~ $(MAIN)
    
depend: $(SRCS)
	# If makedepend is not available, consider using gcc -MM
	makedepend $(INCLUDES) $^
