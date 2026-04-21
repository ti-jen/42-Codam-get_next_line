*This project has been created as part of the 42 curriculum by tkroon*

# Get Next Line

gets a new line in document every time you call it.

## Description

The goal of this project is to create a function that returns a new line of text every time it is called. If an error occurs or there is nothing left to read, the function returns NULL.

The function works as follows: it first takes the address of a file. It then reads chunks of the file using a defined BUFFER_SIZE. Each chunk is stored in a linked list until a newline character ('\n') is found or the read function returns 0.

Once a newline is found, the function combines the stored chunks until it reaches the end of the list. It then extracts the text up to and including the newline character, returning that as a line. Any remaining text after the newline is stored back in the list for future calls.

If the function is called again, it first checks whether there is already data stored in the list. If so, it continues returning lines from this stored data until no complete lines remain and will repeat the progress.

## Instructions
in this project you can use the Makefile to compile and create 'get_next_line.a'.

### executing program
```
== executes the whole program ==
make all
== removes all object files ==
make clean
== removes all files created by the program ==
make fclean
== removes all files created by the program and re executes the program ==
make re
```

## Resources

https://pythontutor.com/visualize.html#mode=edit

https://stackoverflow.com/questions

https://github.com/paulo-santana/ft_printf_tester#

https://github.com/Tripouille/printfTester#

https://chatgpt.com/

https://www.w3schools.com/

### usage of AI

AI was used to create this README. it was also used to explain valgrind errors and give suggestion in how to shorten the code to pass Norminette