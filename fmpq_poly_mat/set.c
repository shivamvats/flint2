#include <stdlib.h>
#include "flint.h"
#include "fmpz_poly.h"
#include "fmpz_poly_mat.h"

void fmpq_poly_mat_set(fmpq_poly_mat_t B, const fmpq_poly_mat_t A)
{
    if(A != B)
    {
        slong i, j;

        for (i = 0; i < A->r; i++)
            for(j = 0; j < A->c; j++)
                fmpq_poly_set(fmpq_poly_mat_entry(B, i, j),
                              fmpq_poly_mat_entry(A, i, j));
    }
}
