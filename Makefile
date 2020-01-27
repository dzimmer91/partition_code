
CC	:= gcc
CXXFLAGS := -g

OBJECTS	:= dep/read.o dep/write.o dep/File.o #main.o
INCLUDES = -I./includes
LIBDIR = lib
LIBS = -lfile_partition
all: dep/read.o dep/write.o dep/File.o lib/libfile_partition.a src/main.exe

dep/%.o: src/%.c
	$(CC) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)

src/%.exe: src/%.c
	$(CC) -o $@ $< $(CXXFLAGS) $(INCLUDES) -L$(LIBDIR) $(LIBS)

lib/libfile_partition.a: $(all)
	ar rcs lib/libfile_partition.a dep/*.o

#main.o: main.cpp
#	$(CC) $(INCLUDES) $(CXXFLAGS) -c main.cpp -o main.o
clean:
	rm -f dep/*.o
	rm -f lib/*.a
	rm -f src/*.o
	rm -f src/*.exe
