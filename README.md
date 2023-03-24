# double-linked-list
Creating static and shared libraries based on a double linked list with comparators
Build and test static library

$ ar r lib_functions.a functions.o <br />
$ ar tv lib_functions.a <br />
$ gcc main.o lib_functions.a -o program_static <br />
$ ./program_static <br />



Build and test dynamic library

$ gcc -Wall -fPIC -c functions.c <br />
$ gcc functions.o -shared -o lib_functions.so <br />
$ export LD_LIBRARY_PATH=.:"$LD_LIBRARY_PATH" <br />
$ gcc main.o -L. -l_functions.so -o program_dynamic <br />
$ ./program_dynamic <br />


Build and test dynamic library and rpath

$ gcc -Wall -fPIC -c functions.c <br />
$ gcc functions.o -shared -o lib_functions.so <br />
$ export LD_LIBRARY_PATH=.:"$LD_LIBRARY_PATH" <br />
$ gcc main.o -L. -l_functions.so -o program_dynamic <br />
$ ./program_dynamic <br />
