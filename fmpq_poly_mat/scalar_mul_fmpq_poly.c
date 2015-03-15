#include <stdlib.h>
#include "flint.h"
#include "fmpq.h"
#include "fmpq_poly.h"
#include "fmpq_poly_mat.h"

void
fmpq_poly_mat_scalar_mul_fmpq_poly(fmpq_poly_mat_t B, const fmpq_poly_mat_t A,
                                                        const fmpq_poly_t c)
{
    slong i, j;

    for (i = 0; i < fmpq_poly_mat_nrows(B); i++)
        for (j = 0; j < fmpq_poly_mat_ncols(B); j++)
            fmpq_poly_mul(fmpq_poly_mat_entry(B, i, j),
                          fmpq_poly_mat_entry(A, i, j), c);
}
