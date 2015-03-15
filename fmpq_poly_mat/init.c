#include <stdlib.h>
#include "flint.h"
#include "fmpq_poly.h"
#include "fmpq_poly_mat.h"

void fmpq_poly_mat_init(fmpq_poly_mat_t A, slong rows, slong cols)
{
    if(rows != 0 && cols != 0)
    {
       slong i;

       A->entries = (fmpq_poly_struct *) flint_malloc(rows * cols * sizeof(fmpq_poly_struct));
       A->rows = (fmpq_poly_struct **) flint_malloc(rows * sizeof(fmpq_poly_struct *));

       for (i = 0; i < rows * cols; i++)
           fmpq_poly_init(A->entries + i);

       for (i = 0; i < rows; i++)
           A->rows[i] = A->entries + i * cols;

    }
    else
        A->entries = NULL;

    A->r = rows;
    A->c = cols;
}
