all: gdb_test


gdb_test:	gdb_test.c dlist.c
	gcc -g -Wall -Wextra -o gdb_test dlist.c send_msg.c gdb_test.c


.PHONY: clean
clean:
	-rm gdb-test-program

