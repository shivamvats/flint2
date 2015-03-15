#include <stdlib.h>
#include "flint.h"
#include "fmpq_poly.h"
#include "fmpq_poly_mat.h"

void
fmpq_poly_mat_add(fmpq_poly_mat_t C,
                        const fmpq_poly_mat_t A, const fmpq_poly_mat_t B)
{
    slong i, j;

    for (i = 0; i < A->r; i++)
        for (j = 0; j < A->c; j++)
            fmpq_poly_add(fmpq_poly_mat_entry(C, i, j),
                          fmpq_poly_mat_entry(A, i, j),
                          fmpq_poly_mat_entry(B, i, j));
}
