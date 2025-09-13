# shell-with-C

This is a hobby project, where I'm trying to learn the working of a shell with the help of C language.

> **Note**: General concepts about shell are described below. Project Sepcific Details are documented in [src/README.md](src/README.md)

## shell

+ Shell is a Command-Line-Interface (**CLI**) that allow users to Interact with Operating system.
+ It is a Interpreter which read from CLI or files and convert Human readable commands to system calls which OS understands.

## Features of Shell

1. The shell basically parse the User input into Commands and Arguments.
2. Can execute programs by forking a new process.
3. Pipelineing or chaining commands using  ' **|** 'operator, this allow user to use output of one 
  commands as input of the next.(eg. ls /usr| grep lib)
4. Scriptting is the most useful feature of shell. This allow user to automate tasks and excecute from files.(by running **.sh** scripts)

## Shell vs Terminal

+ Shell, as discussed above is a CLI which interpret human readable commands to OS.(eg. Bash, ZSH etc.)
+ Terminal is a graphical user interface which allows user to interact with shell using input devices.

## Shell Working (basic)

+ Shell basically have a prompt which allow user to understand it is ready to take input.
+ There is a parser function which split the user input into commnands and Arguments.
+ There are built-in commands like *cd*, *history*, etc. check if the command is any of these or from the path(environment path).
+  The shell will fork new process(copy and create child process).
+ Execute the command program(or executable) in child process.

