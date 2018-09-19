/* gcc -std=c99 -Wall variable_length.c -o variable_length && ./variable_length */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	uint8_t length;
	uint8_t data[];
} st_pkg;

void test(uint8_t n) {
    size_t allocated_size = sizeof(st_pkg) + n * sizeof(uint8_t);
    printf("n: %i\n", n);
    printf("allocated_size: %zu\n", allocated_size);
    st_pkg* tmp = malloc(allocated_size);
    if (!tmp) {
        perror("malloc");
        exit(EXIT_FAILURE);
    };
    tmp->length = n;
	for (uint8_t i=0; i < tmp->length; i++) {
        tmp->data[i] = i;
    }
    free(tmp);
}

int main() {
	/* int i; */
    test(0);
    test(5);

	/* st_pkg pkg; */
    /* pkg.length = 5; */
    /*  */
	/* emps.No_Of_Employees = 2; //number of elements */
	/* // allocate the number of elements */
	/* emps.Employee_Names = malloc(emps.No_Of_Employees); */
	/* for (i=0; i < pkg.length; i++) */
	/* { */
	/* 	// allocate each element */
	/* 	emps.Employee_Names[i] = malloc(SIZE_OF_ELEM); */
	/* 	// fill the element with some data */
	/* 	sprintf(emps.Employee_Names[i], "emp_n%d", i); */
	/* } */
	/* // show the content */
	/* for (i=0; i<emps.No_Of_Employees; i++) */
	/* { */
	/* 	printf("Employee %d content: %s\n", i, emps.Employee_Names[i]); */
	/* } */
	return 0;
}

