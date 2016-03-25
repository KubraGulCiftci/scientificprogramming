//Kübra Gül Çiftçi
//210206006
//Root Finding Homework 3.

#include <stdio.h>

//Function is x^4 + 7/2*x^3 - 3*x^2 - 7/2*x +2
double function(double x)
{
	return (x*x*x*x + (7.0/2.0)*x*x*x - (3.0)*x*x - (7.0/2.0)*x + 2.0);
}

//A function for findinf interval by using interval's end point and start point with increasing xleft and xright.
int finding_interval(double (*equation)(double), double x_start, double x_end, double *x_left, double *x_right, double step_size)
{
    //Iteration number is to know how many iteration and roots exist.
	int iteration_number = 0 ;
	*x_left = x_start ;
	*x_right = *x_left + step_size ;

	while(*x_right <= x_end)
	{
		if(equation(*x_left) * equation(*x_right) < 0.0){
			iteration_number++ ;
			printf("Interval %d = [%.2lf, %.2lf]\n",iteration_number, *x_left, *x_right);
			if(*x_right != x_end){
				*x_left = *x_right ;
				*x_right += step_size ;
			}

		}
		else{
			*x_left = *x_right ;
			*x_right += step_size ;

		}
	}
}

int main()
{

	double x1,x2 ;

	finding_interval(function, -6.0, 6.0, &x1, &x2, 0.03);
	return 0;
}
