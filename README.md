# double-linked-list
Creating static and shared libraries based on a double linked list with comparators
Build and test static library

$ ar r lib_functions.a functions.o
$ ar tv lib_functions.a
$ gcc main.o lib_functions.a -o program_static
$ ./program_static



Build and test dynamic library

$ gcc -Wall -fPIC -c functions.c
$ gcc functions.o -shared -o lib_functions.so
$ export LD_LIBRARY_PATH=.:"$LD_LIBRARY_PATH"
$ gcc main.o -L. -l_functions.so -o program_dynamic
$ ./program_dynamic


Build and test dynamic library and rpath

$ gcc -Wall -fPIC -c functions.c
$ gcc functions.o -shared -o lib_functions.so
$ export LD_LIBRARY_PATH=.:"$LD_LIBRARY_PATH"
$ gcc main.o -L. -l_functions.so -o program_dynamic
$ ./program_dynamic
