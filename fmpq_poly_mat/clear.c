#include "stdlib.h"
#include "flint.h"
#include "fmpq_poly.h"
#include "fmpq_poly_mat.h"

void fmpq_poly_mat_clear(fmpq_poly_mat_t A)
{
    if((A->entries) != 0)
    {
        slong i;

        for(i = 0; i < A->r * A->c; i++)
            fmpq_poly_clear(A->entries + i);

        flint_free(A->entries);
        flint_free(A->rows);
    }
}

