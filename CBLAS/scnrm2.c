
/*  -- translated by f2c (version 19940927).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

real scnrm2_(integer *n, singlecomplex *x, integer *incx)
{


    /* System generated locals */

    real ret_val, r__1;

    /* Builtin functions */
    double r_imag(singlecomplex *), sqrt(doublereal);

    /* Local variables */
    real temp, norm, scale;
    integer ix;
    real ssq;


/*  SCNRM2 returns the euclidean norm of a vector via the function   
    name, so that   

       SCNRM2 := sqrt( conjg( x' )*x )   

    -- This version written on 25-October-1982.   
       Modified on 14-October-1993 to inline the call to CLASSQ.   
       Sven Hammarling, Nag Ltd.   

   Parameter adjustments   
       Function Body */
#define X(I) x[(I)-1]


    //if (*n < 1 || *incx < 1) {
    if (*n < 1) {
	norm = 0.f;
    } else {
	scale = 0.f;
	ssq = 1.f;
/*        The following loop is equivalent to this call to the LAPACK 
  
          auxiliary routine:   
          CALL CLASSQ( N, X, INCX, SCALE, SSQ ) */
	
	int ixinitial = 1;
	if (*incx < 0) {
	    ixinitial = 1 - (*n-1)* (*incx);
	}

	int i;
	for (i = 1,ix = ixinitial; i <= *n; i++, ix += *incx) {
	    //for (ix = 1; *incx < 0 ? ix >= (*n-1)*(*incx)+1 : ix <= (*n-1)*(*incx)+1; ix += *incx) {
	    if (X(ix).r != 0.f) {
		temp = (r__1 = X(ix).r, dabs(r__1));
		if (scale < temp) {
/* Computing 2nd power */
		    r__1 = scale / temp;
		    ssq = ssq * (r__1 * r__1) + 1.f;
		    scale = temp;
		} else {
/* Computing 2nd power */
		    r__1 = temp / scale;
		    ssq += r__1 * r__1;
		}
	    }
	    if (r_imag(&X(ix)) != 0.f) {
		temp = (r__1 = r_imag(&X(ix)), dabs(r__1));
		if (scale < temp) {
/* Computing 2nd power */
		    r__1 = scale / temp;
		    ssq = ssq * (r__1 * r__1) + 1.f;
		    scale = temp;
		} else {
/* Computing 2nd power */
		    r__1 = temp / scale;
		    ssq += r__1 * r__1;
		}
	    }
/* L10: */
	}
	norm = scale * sqrt(ssq);
    }

    ret_val = norm;
    return ret_val;

/*     End of SCNRM2. */

} /* scnrm2_ */

