/*
ATTENTION READER!

This program only accepts command line inputs from 0 to 100. It also doesn't accept custom .dict files. This is sad, but hopefully you can still learn something from my attempt to do this rush project!
*/


////////// MAKEFILE //////////


/*
A makefile is a really good way of managing your program when it's complicated with many files. Instead of having to manually compile every file together manually, you can specify in your file everything you want the 'make' command to do. It's like a little control center for compiling stuff.
*/

NAME = rush-02 // Defines the name of the executable file, the one you use ./ on.
CC = cc // Defines the compiler you want to use (Moulinette uses cc so it's good to use it too).
CFLAGS = -Wall -Wextra -Werror // Defines cc flags (Moulinette uses these).
SRC = execute.c ft_putchar.c ft_strlen.c main.c read_dict.c write_1.c write_2.c // Defines files in the directory you want compiled together.
OBJ = $(SRC:.c=.o) // This will create object files (.o) from all files defined in SRC.

all: $(NAME) // This is the target of the main file. It states that the goal is to produce an executable with the provided name.

$(NAME): $(OBJ) // Defines how the object files are used to create the executable. $(CC) asks for the specified compiler, $(CFLAGS) asks for the specified flags, -o allows for specification of the executable name, $@ is the target (rush-02), and $^ is the object file.
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c // This tells the computer how to make an object file from a C file. It asks for the compiler, the flags, the -c flag (specifies that the result will be an object file, not an executable), and $< is the C file.
	$(CC) $(CFLAGS) -c $<

clean: // Defines what happens if you use the 'make clean' command. It will remove all object files.
	rm -f $(OBJ)

fclean: clean // Defines what happens if you use 'make fclean'. It will do what clean says, followed by removing the executable.
	rm -f $(NAME)

re: fclean all // This target performs a full clean and then recompiles everything by invoking all.

.PHONY: all clean fclean re // This tells make that the targets all, clean, fclean, and re are "phony," meaning they are not actual files but commands to be run.


////////// MAIN.C //////////


/*
The main is quite short as its only purpose is to handle errors and call read_dict, which is the start of the functions chain. In this program, 0 is the error code and 1 is the success code (I actually flipped this by accident, it's usually the opposite). If 0 is returned at any point by any function, this value is passed along the functions chain and is read by the main. If 0 is detected, "Error" is written to standard output (the terminal).
*/

#include <unistd.h> // Header file for write().

int	read_dict(char *input); // Prototyping read_dict as it's called in this function. It won't work otherwise.

int	main(int argc, char **argv) // This main accepts command line arguments. argc means argument counter, and argv means argument vector.
{
	if (argc != 2 || read_dict(argv[1]) == 0) // If there are no arguments other than the file name (argc == 1) or there are more than 2 (argc => 2), it errors. It also errors if read_dict's returned value is 0 (error code). 
		write(1, "Error\n", 6); // Writes "Error" to standard output.
	return (0); // Signals end of whole program.
}


////////// READ_DICT.C //////////


#include <fcntl.h> // Header file for open() and close().
#include <unistd.h> // Header file for write() and read().

int	execute(char *dict, char *input); // Prototyping execute as it's called in this function.

int	read_dict(char *input) // read_dict accepts *input as an argument. This is set to argv[1] in main, meaning it holds the value of the search term written on the command line. Whenever input is used, it is referring to this search term.
{
	int		fd; // fd will hold the returned value of open() (file descriptor).
	char	dict[692]; // Fixed size array for holding the contents of numbers.dict (the provided dictionary). It should be 691 -- this was a mistake -- but it still works just fine.
	ssize_t	bytes_read; // bytes_read will hold the returned value of read() (number of bytes in the numbers.dict fiile).

	fd = open("numbers.dict", O_RDONLY); // open() is called. It opens numbers.dict in read-only mode (to prevent any unwanted changes).
	if (fd == -1) // open() returns -1 if it can't open the file (e.g. the file doesn't exist).
		return (0); // If fd has this value, the error code is returned.
	bytes_read = read(fd, dict, 691); // read() is called. It accepts a file descriptor, the location which will accept the file's data, and the amount of memory to be allocated to the function. 691 is used here as that is the size of the numbers.dict.
	if (bytes_read <= 0) // If the returned value of read() is less than or equal to zero, there was an issue reading the data and the program can't continue.
	{
		close(fd); // The file is closed with close().
		return (0); // The error code is returned to the previous function.
	}
	dict[bytes_read] = '\0'; // The last character (\n, newline) in numbers.dict is replaced with a null terminator to give the dict array an end point for while loops.
	if (execute(dict, input) == 0) // execute is called. It accepts the contents of the dict array and input, the search term as arguments. THis if conditional checks if the returned value is the error code (0).
	{
		close(fd); // If the condition is met, the file is closed.
		return (0); // The error code is returned to the previous function.
	}
	close(fd); // After everything has gone OK, the file is closed.
	return (1); // Returns the success code to the previous function.
}


////////// FT_STRLEN.C //////////


/*
This function simply calculates the length of the input string and returns its length. It's used in execute.c.
*/

int	ft_strlen(char *str) // The function accepts a string as an argument.
{
	int	index; // An index variable is declared to index through the input string.

	index = 0; // index is initialised to 0 as 0 is the first character in a string.
	while (str[index] != '\0') // Loop continues until the null terminator is encountered.
		index++; // index is incremented until the loop terminates.
	return (index); // Returns the value of index (AKA the length of the string).
}


////////// EXECUTE.C //////////


/*
This file handles what path is taken depending on the command line input. I've created two functions that are called depending on the length of input.
*/

#include <unistd.h> // Header file for write().

int	ft_strlen(char *str); // ft_strlen is prototyped.
int	write_1(char *dict, char *input, int search_index); // write_1 is prototyped.
int	write_2(char *dict, char *input); // write_2 is prototyped.

int	execute(char *dict, char *input) // The function accepts the contents of the dict array and the command line input string as arguments.
{
	int	len; // len is declared, which will hold the returned value of ft_strlen. It will hold the length of the input string.

	len = ft_strlen(input); // ft_strlen is called, and len is initialised with the returned value of ft_strlen.
	if (len == 0) // If the input string is empty, nothing can be done.
		return (0); // Returns the error code to the previous function.
	else if (len == 1) // If the input string is 1 number long, write_1 is called to handle this case.
		return (write_1(dict, input, 0)); // write_1 is called with 0 as the search_index as there is only one character in the input string. Its result is returned (either the success or error code).
	else if (len == 2) // If the input string is 2 numbers long, write_2 is called to handle this case.
		return (write_2(dict, input)); // write_2's result is returned, which is either the success or error code.
	else if (len == 3 && input[0] == '1' && input[1] == '0'
		&& input[2] == '0') // Handles if the input string is 100.
	{
		write(1, "one hundred\n", 12); // Writes "one hundred" to standard output.
		return (1); // Returns success code to previous function.
	}
	return (0); // If no path was executed successfully, the error code is returned to the previous function.
}


////////// FT_PUTCHAR.C //////////


/*
This function simply writes the char it receives as an argument! Cute. :3 It's used in write_1 and write_2.
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


////////// WRITE_1.C //////////


/*
This function handles command line inputs that contain 1 character. It indexes through the part of the array that handles 0-9. It also handles the second number in a 2 character long string if search_index is set to 1. It's called in write_2 in this case.
*/

#include <unistd.h>

void	ft_putchar(char c); // ft_putchar is prototyped.

int	write_1(char *dict, char *input, int search_index) // The function accepts the contents of the dict array, the command line input string, and an index value for the input string as arguments.
{
	int	index; // An index variable is declared.

	index = 0; // index is initialised to 0 so it can be used to index through the dict array from the start.
	while (index != 79) // IMPORTANT: The loop will terminate at position 79 as this is the newline character at the end of 9: nine in the numbers.dict file. This function only handles numbers 0 to 9.
	{
		if (dict[index] == input[search_index]) // This if conditional looks for a match between the current position in the dict array and the input string.
		{
			index += 3; // If a match is found, index is incremented by 3 as this is the amount of space between the digit and its written form in numbers.dict.
			while (dict[index] != '\n') // While loop is initialised until the newline at the end of the dictionary entry is reached.
			{
				ft_putchar(dict[index]); // ft_putchar is called and handles the writing portion of this function.
				index++; // index is incremented until newline is reached.
			}
			write(1, "\n", 1); // Once the loop terminates, a newline is written to standard output as defined in the PDF.
			return (1); // Success code is returned to the previous function.
		}
		index++; // If no match is found, index is incremented until the limited is reached.
	}
	return (0); // If a match wasn't found, the error code is returned to the previous function.
}


////////// WRITE_2.C //////////


/*
This one looks a little scary, but it's just multiple functions relevant to each other in one file. This file handles command line inputs that are 2 characters long. There are three other functions for handling different versions for this input. handle_one handles numbers that start with 1. handle_tens handles numbers like 20 and 30. handle_other_digits handles everything else.
*/

#include <unistd.h> // Header file for write().

void	ft_putchar(char c); // ft_putchar is prototyped.
int		write_1(char *dict, char *input, int search_index); // write_1 is prototyped.
int		handle_one(char *dict, char *input); // handle_one is prototyped.
int		handle_other_digits(char *dict, char *input); // handle_other_digits is prototyped.
int		handle_tens(char *dict, char *input); // handle_tens is prototyped.

int	write_2(char *dict, char *input) // write_2 accepts the contents of the dict array and the command line input string as arguments.
{
	if (input[0] == '1') // Checks if the first character in the input string is 1.
		return (handle_one(dict, input)); // Calls handle_one.
	else if (input[1] == '0') // Checks if the second character in the input string is 0.
		return (handle_tens(dict, input)); // Calls handle_tens.
	else // If neither of the previous if conditionals are met...
		return (handle_other_digits(dict, input)); // ...handle_other_digits is called.
}

int	handle_one(char *dict, char *input) // handle_one accepts the contents of the dict array and the command line input string as arguments.
{
	int	index; // An index variable is declared.

	index = 80; // IMPORTANT: index is set to 80 here because handle_one only needs entries 10-19 in the dict array.
	while (index != 199) // While loop continues until the newline character at the end of entry 19 in the dict array.
	{
		if (dict[index] == input[0]) // Checks if the first number in the input string has matched with the current position in the dict array.
		{
			index++; // If yes, index is incremented by 1.
			if (dict[index] == input[1]) // The next number in the dict array is compared with the second character in the input string.
			{
				index += 3; // If there's a match, index is incremented by 3, as this is the space between the number and its written form in the dictionary.
				while (dict[index] != '\n') // While loop continues until the newline character at the end of the entry is reached.
				{
					ft_putchar(dict[index]); // ft_putchar handles the writing part of this function.
					index++; // index is incremented by 1 until the while loop terminates.
				}
				write(1, "\n", 1); // When done, a newline is printed as specified in the PDF.
				return (1); // The success code is returned to the previous function.
			}
		}
		index++; // If no match is found, index is incremented by 1.
	}
	return (0); // If no match is found, the error code is returned to the previous function.
}

int	handle_other_digits(char *dict, char *input) // handle_other_digits accepts the contents of the dict array and the command line input string as arguments.
{
	int	index; // An index variable is declared.

	index = 200; // IMPORTANT: index is set to 200 here because handle_other_digits only needs entries 20-90 in the dict array.
	while (index != 285) // While loop continues until the newline character at the end of of entry 90 in the dict array.
	{
		if (dict[index] == input[0]) // Checks if the first number in the input string has matched with the current position in the dict array.
		{
			index += 4; // If yes, index is incremented by 4, as this is the soace between the FIRST number in the entry and its written form. (write_1 handles the second number)
			while (dict[index] != '\n') // While loop continues until the newline character at the end of the entry is reached.
			{
				ft_putchar(dict[index]); // ft_putchar handles the writing part of this function.
				index++; // index is incremented by 1 until the while loop terminates.
			}
			write(1, " ", 1); // When done, a space is printed so that the second written number is not conjoined with the first.
			return (write_1(dict, input, 1)); // write_1 is called with search_index set to 1, so that it finds the second character in the input string, not the first. The returned value of write_1 is returned again.
		}
		index++; // If no match is found, index is incremented by 1.
	}
	return (0); // If no match is found, the error code is returned to the previous function.
}

int	handle_tens(char *dict, char *input) // // handle_tens accepts the contents of the dict array and the command line input string as arguments.
{
	int	index; // An index variable is declared.

	index = 200; // IMPORTANT: index is set to 200 here because handle_tens only needs entries 20-90 in the dict array.
	while (index != 285) // While loop continues until the newline character at the end of of entry 90 in the dict array.
	{
		if (dict[index] == input[0]) // Checks if the first number in the input string has matched with the current position in the dict array.
		{
			index += 4; // If yes, index is incremented by 4, as this is the soace between the FIRST number in the entry and its written form. No handling is required for the second character in this function.
			while (dict[index] != '\n') // While loop continues until the newline character at the end of the entry is reached.
			{
				ft_putchar(dict[index]); // ft_putchar handles the writing part of this function.
				index++; // index is incremented by 1 until the while loop terminates.
			}
			write(1, "\n", 1); // When done, a newline is printed as specified in the PDF.
			return (1); // The success code is returned to the previous function.
		}
		index++; // If no match is found, index is incremented by 1.
	}
	return (0); // If no match is found, the error code is returned to the previous function.
}
