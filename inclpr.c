/*  Part of INCLP(R)

    Author:        Leslie De Koninck
    E-mail:        Leslie.DeKoninck@cs.kuleuven.be
    WWW:           http://www.swi-prolog.org
    Copyright (c)  2011, K.U. Leuven
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in
       the documentation and/or other materials provided with the
       distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#include <SWI-Prolog.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include "inclpr_interval_arithmetic.h"



static foreign_t pl_ia_sum(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_sum(i1,i2);
    return c_to_p(i3,t3);
}
static foreign_t pl_ia_sum_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_sum(i1,i2);
    return ( PL_unify_float(t3l,i3.l) &&
	     PL_unify_float(t3r,i3.r) );
}
static foreign_t pl_ia_difference(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_difference(i1,i2);
    return c_to_p(i3,t3);
}
static foreign_t pl_ia_difference_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_difference(i1,i2);
    return (PL_unify_float(t3l,i3.l) &&
	    PL_unify_float(t3r,i3.r));
}
static foreign_t pl_ia_product(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_product(i1,i2);
    return c_to_p(i3,t3);
}
static foreign_t pl_ia_product_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_product(i1,i2);
    return (PL_unify_float(t3l,i3.l) &&
	    PL_unify_float(t3r,i3.r));
}
static foreign_t pl_ia_quotient(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_quotient(i1,i2);
    return c_to_p(i3,t3);
}
static foreign_t pl_ia_quotient_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_quotient(i1,i2);
    return (PL_unify_float(t3l,i3.l) &&
	    PL_unify_float(t3r,i3.r));
}
static foreign_t pl_ia_additive_inverse(term_t t1, term_t t2)
{
    struct i i1;
    struct i i2;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    i2 = ia_additive_inverse(i1);
    return c_to_p(i2,t2);
}
static foreign_t pl_ia_additive_inverse_2(term_t t1l, term_t t1r, term_t t2l,
    term_t t2r)
{
    struct i i1;
    struct i i2;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) )
      return FALSE;
    i2 = ia_additive_inverse(i1);
    return (PL_unify_float(t2l,i2.l) &&
	    PL_unify_float(t2r,i2.r));
}
static foreign_t pl_ia_power(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    if (pos_int_canonical_interval(i2))
    {
	int n = (int)i2.l;
	struct i i3 = ia_power(i1,n);
	return c_to_p(i3,t3);
    }
    else return FALSE;
}
static foreign_t pl_ia_power_2(term_t t1l, term_t t1r, term_t t2, term_t t3l,
    term_t t3r)
{
    struct i i1;
    double exponent;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2,&(exponent)) )
      return FALSE;
    if (exponent >= 0 && trunc(exponent) == exponent)
    {
	int exp = (int)exponent;
	struct i i3 = ia_power(i1,exp);
	return (PL_unify_float(t3l,i3.l) &&
		PL_unify_float(t3r,i3.r));
	return TRUE;
    }
    else return FALSE;
}

static foreign_t pl_ia_root(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    if (pos_int_canonical_interval(i2))
    {
	int n = (int)i2.l;
	struct i i3;
	struct i i4;
	int r = ia_root(i1,n,&i3,&i4);
	if (r == 0) return FALSE;
	else if (r == 1)
	{
	    return c_to_p(i3,t3);
	}
	else
	{
	    struct i i5 = ia_union(i3,i4);
	    return c_to_p(i5,t3);
	}
    }
    return FALSE;
}
static foreign_t pl_ia_root_2(term_t t1l, term_t t1r, term_t t2, term_t t3l,
    term_t t3r)
{
    struct i i1;
    double exponent;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2,&(exponent)) )
      return FALSE;
    if (exponent >= 0 && trunc(exponent) == exponent)
    {
	int exp = (int)exponent;
	struct i i3;
	struct i i4;
	int r = ia_root(i1,exp,&i3,&i4);
	if (r == 0) return FALSE;
	else if (r == 1)
	{
	    return (PL_unify_float(t3l,i3.l) &&
		    PL_unify_float(t3r,i3.r));
	}
	else
	{
	    struct i i5 = ia_union(i3,i4);
	    return (PL_unify_float(t3l,i5.l) &&
		    PL_unify_float(t3r,i5.r));
	}
    }
    else return FALSE;
}
static foreign_t pl_ia_slope_power_2(term_t tuxl, term_t tuxr, term_t tucl,
    term_t tucr, term_t tk, term_t tsl, term_t tsr)
{
    struct i ux;
    struct i uc;
    double fk;
    if ( !PL_get_float(tuxl,&(ux.l)) ||
	 !PL_get_float(tuxr,&(ux.r)) ||
	 !PL_get_float(tucl,&(uc.l)) ||
	 !PL_get_float(tucr,&(uc.r)) ||
	 !PL_get_float(tk,&(fk)) )
      return FALSE;
    if (fk >= 1 && trunc(fk) == fk)
    {
	struct i s;
	int k = (int)fk;
	if (ux.l == uc.l || ux.r == uc.r)
	{
	    int km = k - 1;
	    struct i temp = ia_power(ux,km);
	    fesetround(FE_DOWNWARD);
	    s.l = k * temp.l;
	    fesetround(FE_UPWARD);
	    s.r = k * temp.r;
	    return (PL_unify_float(tsl,s.l) &&
		    PL_unify_float(tsr,s.r));
	}
	else if ((k % 2) == 0)
	{
	    if (k == 2)
	    {
		s = ia_sum(ux,uc);
		return (PL_unify_float(tsl,s.l) &&
			PL_unify_float(tsr,s.r));
	    }
	    else
	    {
		fesetround(FE_DOWNWARD);
		double uckl = pow(uc.l,k);
		double uckr = pow(uc.r,k);
		double url = ux.r - uc.r;
		fesetround(FE_UPWARD);
		double uxkl = pow(ux.l,k);
		double uxkr = pow(ux.r,k);
		double ukl = uxkl - uckl;
		double ukr = uxkr - uckr;
		double ulr = ux.l - uc.l;
		if (uxkl < 0)
		{
		    s.r = ukr / (ux.r - uc.r);
		    fesetround(FE_DOWNWARD);
		    s.l = ukl / (ux.l - uc.l);
		}
		else
		{
		    s.r = ukr / url;
		    fesetround(FE_DOWNWARD);
		    s.l = ukl / ulr;
		}
		return (PL_unify_float(tsl,s.l) &&
			PL_unify_float(tsr,s.r));
	    }
	}
	else
	{
	    char c = ia_class(ux);
	    double uckl;
	    double uckr;
	    double uxkl;
	    double uxkr;
	    double ukl;
	    double ukr;
	    double ulr;
	    double url;
	    struct i temp;
	    int km;
	    switch (c)
	    {
		case 'p':
		    fesetround(FE_DOWNWARD);
		    uckl = pow(uc.l,k);
		    uckr = pow(uc.r,k);
		    url = ux.r - uc.r;
		    fesetround(FE_UPWARD);
		    uxkl = pow(ux.l,k);
		    uxkr = pow(ux.r,k);
		    ukl = uxkl - uckl;
		    ukr = uxkr - uckr;
		    ulr = ux.l - uc.l;
		    s.r = ukr / url;
		    fesetround(FE_DOWNWARD);
		    s.l = ukl / ulr;
		    return (PL_unify_float(tsl,s.l) &&
			    PL_unify_float(tsr,s.r));
		case 'z':
		    km = k - 1;
		    temp = ia_power(ux,km);
		    fesetround(FE_DOWNWARD);
		    s.l = k * temp.l;
		    fesetround(FE_UPWARD);
		    s.r = k * temp.r;
		    return (PL_unify_float(tsl,s.l) &&
			    PL_unify_float(tsr,s.r));
		case 'n':
		    fesetround(FE_UPWARD);
		    uckl = pow(uc.l,k);
		    uckr = pow(uc.r,k);
		    ulr = ux.r - uc.r;
		    fesetround(FE_DOWNWARD);
		    uxkl = pow(ux.l,k);
		    uxkr = pow(ux.r,k);
		    ukl = uxkr - uckr;
		    ukr = uxkl - uckl;
		    s.l = ukl / ulr;
		    fesetround(FE_UPWARD);
		    s.r = ukr / (ux.l - uc.l);
		    return (PL_unify_float(tsl,s.l) &&
			    PL_unify_float(tsr,s.r));
	    }
	}
    }
    return FALSE;
}


static foreign_t pl_ia_quadratic_inverse(term_t a, term_t b, term_t c, term_t r)
{
    struct i ia;
    struct i ib;
    struct i ic;
    if ( !p_to_c(a,&ia) &&
	 !p_to_c(b,&ib) &&
	 !p_to_c(c,&ic) )
      return FALSE;
    struct i ir1;
    struct i ir2;
    int roots = ia_quadratic_inverse(ia,ib,ic,&ir1,&ir2);
    switch (roots)
    {
	case 0:
	    return FALSE;
	case 1:
	    return c_to_p(ir1,r);
	case 2:
	    return two_c_to_p(ir1,ir2,r);
    }
    return FALSE;
}

static int pos_int_canonical_interval(struct i i1)
{
    return (i1.l == i1.r && i1.l >= 0 && trunc(i1.l) == i1.l);
}

static foreign_t pl_ia_intersection(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_intersection(i1,i2);
    if (valid_interval(i3))
    {
	return c_to_p(i3,t3);
    }
    else return FALSE;
}
static foreign_t pl_ia_intersection_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_intersection(i1,i2);
    if (valid_interval(i3))
    { return (PL_unify_float(t3l,i3.l) &&
	      PL_unify_float(t3r,i3.r));
    }
    else return FALSE;
}
static foreign_t pl_ia_union(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !p_to_c(t1,&i1) ||
	 !p_to_c(t2,&i2) )
      return FALSE;
    i3 = ia_union(i1,i2);
    return c_to_p(i3,t3);
}
static foreign_t pl_ia_union_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r)
{
    struct i i1;
    struct i i2;
    struct i i3;
    if ( !PL_get_float(t1l,&(i1.l)) ||
	 !PL_get_float(t1r,&(i1.r)) ||
	 !PL_get_float(t2l,&(i2.l)) ||
	 !PL_get_float(t2r,&(i2.r)) )
      return FALSE;
    i3 = ia_union(i1,i2);
    return (PL_unify_float(t3l,i3.l) &&
	    PL_unify_float(t3r,i3.r));
}

static foreign_t pl_ia_split(term_t t1, term_t t2, term_t t3, term_t t4)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    double factor;
    if ( !PL_get_float(t2,&factor) )
      return FALSE;
    if (finite_interval(i1) && factor > 0 && factor < 1)
    {
	struct i i3;
	struct i i4;
	ia_split(i1,factor,&i3,&i4);
	return (c_to_p(i3,t3) &&
		c_to_p(i4,t4));
    }
    else return FALSE;
}

static foreign_t pl_ia_split_excluding_zero(term_t t1, term_t t2, term_t t3)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    if (contains(i1,0.0))
    {
	struct i i2;
	struct i i3;
	ia_split_excluding_zero(i1,&i2,&i3);
	return (c_to_p(i2,t2) &&
		c_to_p(i3,t3));
    }
    else return FALSE;
}

static foreign_t pl_ia_exclude_zero_bound(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    if (i1.l == 0 && i1.r > 0)
    {
	struct i i2;
	i2.l = 0.0;
	i2.r = i1.r;
	return c_to_p(i2,t2);
    }
    else if (i1.l < 0 && i1.r == 0)
    {
	struct i i2;
	i2.l = i1.l;
	i2.r = -0.0;
	return c_to_p(i2,t2);
    }
    else return FALSE;
}

static foreign_t pl_ia_center(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    if (finite_interval(i1))
    {
	struct i i2 = ia_center(i1);
	return c_to_p(i2,t2);
    }
    else return FALSE;
}
static foreign_t pl_ia_negative_part(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    char c1 = ia_class(i1);
    struct i i2;
    switch (c1)
    {
	case 'n':
	    return c_to_p(i1,t2);
	case 'z':
	    i2.l = i1.l;
	    i2.r = 0.0;
	    return c_to_p(i2,t2);
	case 'p':
	    return FALSE;
    }
    return FALSE; // cannot happen
}
static foreign_t pl_ia_positive_part(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    char c1 = ia_class(i1);
    struct i i2;
    switch (c1)
    {
	case 'n':
	    return FALSE;
	case 'z':
	    i2.l = -0.0;
	    i2.r = i1.r;
	    return c_to_p(i2,t2);
	case 'p':
	    return c_to_p(i1,t2);
    }
    return FALSE; // cannot happen
}

static foreign_t pl_ia_class(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    char c[2];
    c[0] = ia_class(i1);
    c[1] = 0;
    atom_t a = PL_new_atom(c);
    return PL_unify_atom(t2,a);
}
static foreign_t pl_ia_contains(term_t t1, term_t t2)
{
    struct i i1;
    if ( !p_to_c(t1,&i1) )
      return FALSE;
    double d;
    if ( !PL_get_float(t2,&d) )
      return FALSE;
    if (contains(i1,d)) return TRUE;
    else return FALSE;
}

// Data format conversion

static int c_to_p(struct i i, term_t t)
{
    term_t t1 = PL_new_term_ref();
    term_t t2 = PL_new_term_ref();
    term_t t3 = PL_new_term_ref();
    functor_t interval;

    if ( !PL_put_float(t1,i.l) ||
	 !PL_put_float(t2,i.r) )
      return FALSE;
    interval = PL_new_functor(PL_new_atom("i"),2);
    return (PL_cons_functor(t3,interval,t1,t2) &&
	    PL_unify(t,t3));
}
static int two_c_to_p(struct i i1, struct i i2, term_t t)
{
    term_t t1 = PL_new_term_ref();
    term_t t2 = PL_new_term_ref();
    term_t t3 = PL_new_term_ref();
    functor_t intunion;
    if ( !c_to_p(i1,t1) ||
	 !c_to_p(i2,t2) )
      return FALSE;
    intunion = PL_new_functor(PL_new_atom("u"),2);
    return (PL_cons_functor(t3,intunion,t1,t2) &&
	    PL_unify(t,t3));
}

static int p_to_c(term_t t, struct i* i)
{
    term_t t1=PL_new_term_ref();
    term_t t2=PL_new_term_ref();
    if ( !PL_get_arg(1,t,t1) ||
	 !PL_get_arg(2,t,t2) ||
	 !PL_get_float(t1,&(i->l)) ||
	 !PL_get_float(t2,&(i->r)) )
      return FALSE;
    return TRUE;
}


// Operators

static struct i ia_sum(struct i i1, struct i i2)
{
    struct i i;
    fesetround(FE_DOWNWARD);
    i.l = i1.l + i2.l;
    fesetround(FE_UPWARD);
    i.r = i1.r + i2.r;
    return i;
}

static struct i ia_difference(struct i i1, struct i i2)
{
    struct i i;
    fesetround(FE_DOWNWARD);
    i.l = i1.l - i2.r;
    fesetround(FE_UPWARD);
    i.r = i1.r - i2.l;
    return i;
}

static struct i ia_product(struct i i1, struct i i2)
{
    char c1 = ia_class(i1);
    char c2 = ia_class(i2);
    struct i i;
    switch (c1)
    {
	case 'n':
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r*i2.r;
    		    fesetround(FE_UPWARD);
		    i.r = i1.l*i2.l;
    		    break;
		case 'z':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l*i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.l*i2.l;
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l*i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.r*i2.l;
		    break;
	    }
	    break;
	case 'z':
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r*i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.l*i2.l;
		    break;
		case 'z':
		    fesetround(FE_DOWNWARD);
		    i.l = fmin(i1.l*i2.r,i1.r*i2.l);
		    fesetround(FE_UPWARD);
		    i.r = fmax(i1.r*i2.r,i1.l*i2.l);
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l*i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.r*i2.r;
		    break;
	    }
	    break;
	default:
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r*i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.l*i2.r;
		    break;
		case 'z':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r*i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.r*i2.r;
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l*i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.r*i2.r;
		    break;
	    }
	    break;
    }
    return i;
}

static struct i ia_quotient(struct i i1, struct i i2)
{
    char c1 = ia_class(i1);
    char c2 = ia_class(i2);
    struct i i;
    switch (c1)
    {
	case 'n':
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r/i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.l/i2.r;
		    break;
		case 'z':
		    i.l = -1.0/0.0;
		    i.r = 1.0/0.0;
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l/i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.r/i2.r;
		    break;
	    }
	    break;
	case 'z':
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r/i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.l/i2.r;
		    break;
		case 'z':
		    i.l = -1.0/0.0;
		    i.r = 1.0/0.0;
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l/i2.l;
		    fesetround(FE_UPWARD);
		    i.r = i1.r/i2.l;
		    break;
	    }
	    break;
	default:
	    switch (c2)
	    {
		case 'n':
		    fesetround(FE_DOWNWARD);
		    i.l = i1.r/i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.l/i2.l;
		    break;
		case 'z':
		    i.l = -1.0/0.0;
		    i.r = 1.0/0.0;
		    break;
		default:
		    fesetround(FE_DOWNWARD);
		    i.l = i1.l/i2.r;
		    fesetround(FE_UPWARD);
		    i.r = i1.r/i2.l;
		    break;
	    }
	    break;
    }
    return i;
}
// precondition: n >= 0
static struct i ia_power(struct i i1, int n)
{
    struct i i;
    if (n == 0)
    {
	// excluding 0^0 as it is not relevant here
	i.l = 1.0;
	i.r = 1.0;
    }
    else if ((n % 2) == 0)
    {
	switch (ia_class(i1))
	{
	    case 'n':
		fesetround(FE_DOWNWARD);
		i.l = pow(i1.r,n);
		fesetround(FE_UPWARD);
		i.r = pow(i1.l,n);
		break;
	    case 'z':
		i.l = -0.0;
		fesetround(FE_UPWARD);
		i.r  = pow(fmax(-i1.l,i1.r),n);
		break;
	    default:
		fesetround(FE_DOWNWARD);
		i.l = pow(i1.l,n);
		fesetround(FE_UPWARD);
		i.r = pow(i1.r,n);
		break;
	}
    }
    else
    {
	fesetround(FE_DOWNWARD);
	i.l = pow(i1.l,n);
	fesetround(FE_UPWARD);
	i.r = pow(i1.r,n);
    }
    return i;
}
// precondition: n > 0
// returns the number of intervals returned: 0, 1 or 2
static int ia_root(struct i i1, int n, struct i* i2, struct i* i3)
{
    double exponent;
    double root;
    if (n == 0)
    {
	if (contains(i1,1))
	{
	    i2->l = -1.0/0.0;
	    i2->r = 1.0/0.0;
	    return 1;
	}
	else return 0;
    }
    else if (n % 2 == 0)
    {
	switch (ia_class(i1))
	{
	    case 'n':
		return 0;
	    case 'z':
		fesetround(FE_UPWARD);
		exponent = 1.0/n;
		root = pow(i1.r,exponent);
		i2->l = -root;
		i2->r = root;
		return 1;
	    case 'p':
		fesetround(FE_UPWARD);
		exponent = 1.0/n;
		root = pow(i1.r,exponent);
		i2->l = -root;
		i3->r = root;
		fesetround(FE_DOWNWARD);
		exponent = 1.0/n;
		root = pow(i1.l,exponent);
		i2->r = -root;
		i3->l = root;
		return 2;
	}
    }
    else
    {
	switch (ia_class(i1))
	{
	    case 'n':
		fesetround(FE_UPWARD);
		exponent = 1.0/n;
		root = pow(-i1.l,exponent);
		i2->l = -root;
		fesetround(FE_DOWNWARD);
		exponent = 1.0/n;
		root = pow(-i1.r,exponent);
		i2->r = -root;
		return 1;
	    case 'z':
		fesetround(FE_UPWARD);
		exponent = 1.0/n;
		root = pow(-i1.l,exponent);
		i2->l = -root;
		root = pow(i1.r,exponent);
		i2->r = root;
		return 1;
	    case 'p':
		fesetround(FE_DOWNWARD);
		exponent = 1.0/n;
		root = pow(i1.l,exponent);
		i2->l = root;
		fesetround(FE_UPWARD);
		exponent = 1.0/n;
		root = pow(i1.r,exponent);
		i2->r = root;
		return 1;
	}
    }
    return 0;
}

// does not check whether result is a valid interval
static struct i ia_intersection(struct i i1, struct i i2)
{
    struct i i;
    i.l = fmax(i1.l,i2.l);
    i.r = fmin(i1.r,i2.r);
    return i;
}

static struct i ia_union(struct i i1, struct i i2)
{
    struct i i;
    i.l = fmin(i1.l,i2.l);
    i.r = fmax(i1.r,i2.r);
    return i;
}

static struct i ia_additive_inverse(struct i i1)
{
    struct i i;
    i.l = -(i1.r);
    i.r = -(i1.l);
    return i;
}
static int ia_quadratic_inverse(struct i a, struct i b, struct i c,
    struct i* r1, struct i* r2)
{
    struct i d = ia_discriminant(a,b,c);
    struct i sqrt_d_1;
    struct i sqrt_d_2;
    int roots = ia_root(d,2,&sqrt_d_1,&sqrt_d_2);
    struct i minus_b = ia_additive_inverse(b);
    struct i two = num_to_int(2.0);
    struct i two_a = ia_product(two,a);
    struct i temp1;
    struct i temp2;
    switch (roots)
    {
	case 2:
	    temp2 = ia_sum(minus_b,sqrt_d_2);
	    *r2 = ia_quotient(temp2,two_a);
	case 1:
	    temp1 = ia_sum(minus_b,sqrt_d_1);
	    *r1 = ia_quotient(temp1,two_a);
	default:
	    return roots;
    }
}

static struct i ia_discriminant(struct i a, struct i b, struct i c)
{
    struct i b_sqr = ia_power(b,2);
    struct i ac = ia_product(a,c);
    struct i four = num_to_int(4.0);
    struct i four_ac = ia_product(four,ac);
    struct i d = ia_difference(b_sqr,four_ac);
    return d;
}
static struct i num_to_int(double num)
{
    struct i i;
    i.l = num;
    i.r = num;
    return i;
}
// precondition: i1 contains zero
static void ia_split_excluding_zero(struct i i1, struct i* i2, struct i* i3)
{
    i2->l = i1.l;
    i2->r = -0.0;
    i3->l = 0.0;
    i3->r = i1.r;
}
// precondition: i1 is finite
static struct i ia_center(struct i i1)
{
    struct i i;
    fesetround(FE_DOWNWARD);
    i.l = i1.l+(i1.r-i1.l)/2;
    fesetround(FE_UPWARD);
    i.r = i1.l+(i1.r-i1.l)/2;
    return i;
}
// precondition: i1 is finite
// precondition: factor between 0 and 1
static void ia_split(struct i i1, double factor, struct i* i2, struct i* i3)
{
    i2->l = i1.l;
    i3->r = i1.r;
    fesetround(FE_TONEAREST); // to make code reentrant
    double splitpoint = i1.l + factor*(i1.r - i1.l);
    i2->r = splitpoint;
    i3->l = splitpoint;
}
/*
static void print_interval(struct i i)
{
    printf("[%.18e,%.18e]\n",i.l,i.r);
}
*/
static char ia_class(struct i i)
{
    if (copysign(1.0,i.r) == -1.0)
	return 'n';
    else if (copysign(1.0,i.l) == 1.0)
	return 'p';
    else
	return 'z';
}

static int contains(struct i i, double d)
{
    if (d == 0)
    	return (copysign(1.0,i.l) == -1.0) && (copysign(1.0,i.r) == 1.0);
    else
	return (i.l <= d) && (i.r >= d);
}

static int valid_interval(struct i i)
{
    if (i.l == 0 && i.r == 0)
	return (copysign(1.0,i.l) == -1.0) && (copysign(1.0,i.r) == 1.0);
    else
	return (i.l <= i.r);
}
static int finite_interval(struct i i)
{
    return finite(i.l) && finite(i.r);
}

install_t install_inclpr_interval_arithmetic()
{
    PL_register_foreign("ia_sum",3,pl_ia_sum,0);
    PL_register_foreign("ia_sum_2",6,pl_ia_sum_2,0);
    PL_register_foreign("ia_difference",3,pl_ia_difference,0);
    PL_register_foreign("ia_difference_2",6,pl_ia_difference_2,0);
    PL_register_foreign("ia_product",3,pl_ia_product,0);
    PL_register_foreign("ia_product_2",6,pl_ia_product_2,0);
    PL_register_foreign("ia_quotient",3,pl_ia_quotient,0);
    PL_register_foreign("ia_quotient_2",6,pl_ia_quotient_2,0);
    PL_register_foreign("ia_additive_inverse",2,pl_ia_additive_inverse,0);
    PL_register_foreign("ia_additive_inverse_2",4,pl_ia_additive_inverse_2,0);
    PL_register_foreign("ia_power",3,pl_ia_power,0);
    PL_register_foreign("ia_power_2",5,pl_ia_power_2,0);
    PL_register_foreign("ia_root",3,pl_ia_root,0);
    PL_register_foreign("ia_root_2",5,pl_ia_root_2,0);
    PL_register_foreign("ia_slope_power_2",7,pl_ia_slope_power_2,0);
    PL_register_foreign("ia_intersection",3,pl_ia_intersection,0);
    PL_register_foreign("ia_intersection_2",6,pl_ia_intersection_2,0);
    PL_register_foreign("ia_union",3,pl_ia_union,0);
    PL_register_foreign("ia_union_2",6,pl_ia_union_2,0);
    PL_register_foreign("ia_split",4,pl_ia_split,0);
    PL_register_foreign("ia_split_excluding_zero",3,pl_ia_split_excluding_zero,0);
    PL_register_foreign("ia_exclude_zero_bound",2,pl_ia_exclude_zero_bound,0);
    PL_register_foreign("ia_center",2,pl_ia_center,0);
    PL_register_foreign("ia_class",2,pl_ia_class,0);
    PL_register_foreign("ia_contains",2,pl_ia_contains,0);
    PL_register_foreign("ia_negative_part",2,pl_ia_negative_part,0);
    PL_register_foreign("ia_positive_part",2,pl_ia_positive_part,0);
    PL_register_foreign("ia_quadratic_inverse",4,pl_ia_quadratic_inverse,0);
}
