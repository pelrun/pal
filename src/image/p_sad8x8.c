#include <pal.h>

/*
 * This function returns a scalar sum of the absolute differences between the
 * source block 'x' and an 8×8 sub image 'm'.
 *
 * @param x     Pointer to input image, a 2D array of size 'rows' x 'cols'
 *
 * @param m     Pointer to an 8x8 sub image
 *
 * @param r     Result scalar
 *
 * @param cols  Number of columns in input image
 *
 * @return      None
 */

void p_sad8x8_f32(const float *x, float *m, float *r, int cols)
{
	*r = 0;
	absdiffsum_f32(m[0*8],x[0*cols], *r, 8);
	absdiffsum_f32(m[1*8],x[1*cols], *r, 8);
	absdiffsum_f32(m[2*8],x[2*cols], *r, 8);
	absdiffsum_f32(m[3*8],x[3*cols], *r, 8);
	absdiffsum_f32(m[4*8],x[4*cols], *r, 8);
	absdiffsum_f32(m[5*8],x[5*cols], *r, 8);
	absdiffsum_f32(m[6*8],x[6*cols], *r, 8);
	absdiffsum_f32(m[7*8],x[7*cols], *r, 8);
}

/**
 *
 * Compute sum of element wise absolute difference of two vectors 'a' and 'b'.
 *
 * @param a     Pointer to input vector
 *
 * @param b     Pointer to input vector
 *
 * @param c     Pointer to output sum
 *
 * @param n     Size of 'a' and 'b' vector.
 *
 * @return      None
 *
 */

void absdiffsum_f32(const float *a, const float *b, float *c, int n)
{
    union {
        float f;
        uint32_t u;
    } diff;
    for (int i = 0; i < n; i++) {
        diff.f = a[i] - b[i];
        diff.u &= 0x7FFFFFFF;
        *c += diff.f;
    }
}
