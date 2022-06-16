#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define DELIMITER " \n\t\a"
#define LIFO 1
#define FIFO 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - Data From The Monty File
 * @cmd: Line From File
 * @arg: Argument To Excute
 * @l_number: Line Number
 * @fp: File Descriptor
 * @fn: File Name
 * @type: FIFO LIFO
 * Description: Information About The Commands In The Monty File
 */
typedef struct info_s
{
	char *cmd;
	char **arg;
	char *fn;
	int l_number;
	FILE *fp;
	int type;
} info_t;
extern info_t info;
/**
 * struct error - print error to stderr
 * @out:error code
 * @error_type:function to handle error
 */
typedef struct error
{
	int out;
	void (*error_type)(void);
} error_t;

/********* Error-Handler**********/

void handle_error(int code);
void malloc_fail(void);
void monty_usage(void);
void push_use(void);
void unknown_command(void);
void file_perm(void);
void pint_error(void);
void pop_error(void);
void swap_error(void);
void add_error(void);





void free_info(void);
#endif
