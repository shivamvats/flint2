#include <gmp.h>
#include "flint.h"
#include "fmpq.h"
#include "fmpq_mat.h"
#include "fmpq_poly.h"

typedef struct
{
    fmpq_poly_struct * entries;
    slong r;
    slong c;
    fmpq_poly_struct ** rows;
} fmpq_poly_mat_struct;

typedef fmpq_poly_mat_struct fmpq_poly_mat_t[1];

#define fmpq_poly_mat_entry(mat,i,j) ((mat)->rows[(i)] + (j))


FLINT_DLL void fmpq_poly_mat_init(fmpq_poly_mat_t mat, slong rows, slong cols);

FLINT_DLL void fmpq_poly_mat_init_set(fmpq_poly_mat_t mat, const fmpq_poly_mat_t src);

FLINT_DLL void fmpq_poly_set(fmpq_poly_mat_t mat1, const fmpq_poly_mat_t mat2);

FLINT_DLL void fmpq_poly_mat_clear(fmpq_poly_mat_t mat);

**********


static __inline__ slong
fmpz_poly_mat_nrows(const fmpz_poly_mat_t mat)
{
    return mat->r;
}

static __inline__ slong
fmpz_poly_mat_ncols(const fmpz_poly_mat_t mat)
{
    return mat->c;
}

FLINT_DLL void fmpq_poly_mat_scalar_mul_fmpq_poly(fmpq_poly_mat_t B, const fmpq_poly_mat_t A, const fmpq_poly_t c);

FLINT_DLL void fmpq_poly_mat_scalar_mul_fmpq(fmpq_poly_mat_t B, const fmpq_poly_mat_t A, const fmpq_t c);

