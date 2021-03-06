#CFLAGS = -g -Wall -Weffc++ -std=c++0x
CFLAGS = -O3 -Wall -Weffc++ -std=c++0x 

CC = g++
# CC = g++-4.6

INCL = -I../.. -I..

VPATH = .:..:../..

HDR = \
      arg.hh \
      cb.hh \
      format.hh \
      compare.hh \
      types.hh \
      xor_test.hh \
      cputest_funs.hh \
      memory_access.hh \
      switchvsfptr_test.hh \
      jump_test.hh \
      functions.hh \
      infra/measure.hh \
      infra/print_test_header.hh \
      infra/random_permutation.hh \
      infra/argbase.hh \


OBJ = \
      arg.o \
      cb.o \
      format.o \
      compare.o \
      xor_test.o \
      cputest_funs.o \
      memory_access.o \
      switchvsfptr_test.o \
      jump_test.o \
      functions.o \
      types.o \
      ../../infra/system.o \
      ../../infra/print_test_header.o \

ALL = main 


all : $(ALL)

main: main.o $(OBJ)
	$(CC) -o main main.o $(OBJ)

main.o : main.cc $(HDR)
	$(CC) -c $(CFLAGS) $(INCL) main.cc

arg.o : arg.cc arg.hh cb.hh
	$(CC) -c $(CFLAGS) $(INCL) arg.cc

cb.o : cb.cc cb.hh
	$(CC) -c $(CFLAGS) $(INCL) cb.cc

format.o : format.cc format.hh
	$(CC) -c $(CFLAGS) $(INCL) format.cc

compare.o : compare.cc compare.hh
	$(CC) -c $(CFLAGS) $(INCL) compare.cc

xor_test.o : xor_test.cc xor_test.hh
	$(CC) -c $(CFLAGS) $(INCL) xor_test.cc

cputest_funs.o : cputest_funs.cc cputest_funs.hh
	$(CC) -c $(CFLAGS) $(INCL) cputest_funs.cc

memory_access.o : memory_access.cc memory_access.hh
	$(CC) -c $(CFLAGS) $(INCL) memory_access.cc

switchvsfptr_test.o : switchvsfptr_test.cc switchvsfptr_test.hh
	$(CC) -c $(CFLAGS) $(INCL) switchvsfptr_test.cc

jump_test.o : jump_test.cc jump_test.hh
	$(CC) -c $(CFLAGS) $(INCL) jump_test.cc

functions.o : functions.cc functions.hh types.hh
	$(CC) -c $(CFLAGS) $(INCL) functions.cc

types.o : types.cc types.hh
	$(CC) -c $(CFLAGS) $(INCL) types.cc

clean :
	rm -f *.o a.out $(ALL)


