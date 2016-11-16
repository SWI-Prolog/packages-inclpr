/*  Part of INCLP(R)

    Author:        Leslie De Koninck
    E-mail:        Leslie.DeKoninck@cs.kuleuven.be
    WWW:           http://www.swi-prolog.org
    Copyright (c)  2006-2011, K.U. Leuven
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

struct i{double l; double r;};
//
double fmin(double d1, double d2);
double fmax(double d1, double d2);
double trunc(double d1);

static foreign_t pl_ia_sum(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_sum_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
static foreign_t pl_ia_difference(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_difference_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
static foreign_t pl_ia_product(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_product_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
static foreign_t pl_ia_quotient(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_quotient_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
static foreign_t pl_ia_additive_inverse(term_t t1, term_t t2);
static foreign_t pl_ia_additive_inverse_2(term_t t1l, term_t t1r, term_t t2l,
    term_t t2r);
static foreign_t pl_ia_power(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_power_2(term_t t1l, term_t t1r, term_t t2, term_t t3l,
    term_t t3r);
static foreign_t pl_ia_root(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_root_2(term_t t1l, term_t t1r, term_t t2, term_t t3l,
    term_t t3r);
static foreign_t pl_ia_slope_power_2(term_t tuxl, term_t tuxr, term_t tucl,
    term_t tucr, term_t tk, term_t tsl, term_t tsr);

//
static foreign_t pl_ia_intersection(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_intersection_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
static foreign_t pl_ia_union(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_union_2(term_t t1l, term_t t1r, term_t t2l, term_t t2r,
    term_t t3l, term_t t3r);
//
static foreign_t pl_ia_split(term_t t1, term_t t2, term_t t3, term_t t4);
static foreign_t pl_ia_split_excluding_zero(term_t t1, term_t t2, term_t t3);
static foreign_t pl_ia_exclude_zero_bound(term_t t1, term_t t2);
static foreign_t pl_ia_center(term_t t1, term_t t2);
static foreign_t pl_ia_class(term_t t1, term_t t2);
static foreign_t pl_ia_contains(term_t t1, term_t t2);
static foreign_t pl_ia_negative_part(term_t t1, term_t t2);
static foreign_t pl_ia_positive_part(term_t t1, term_t t2);
static foreign_t pl_ia_quadratic_inverse(term_t a, term_t b, term_t c, term_t r);
//

//
static int p_to_c(term_t t, struct i* i);
static int c_to_p(struct i i, term_t t);
static int two_c_to_p(struct i i1, struct i i2, term_t t);
//
static int pos_int_canonical_interval(struct i i1);
//static void print_interval(struct i i);
static struct i ia_sum(struct i i1, struct i i2);
static struct i ia_difference(struct i i1, struct i i2);
static struct i ia_product(struct i i1, struct i i2);
static struct i ia_quotient(struct i i1, struct i i2);
static struct i ia_additive_inverse(struct i i1);
static struct i ia_power(struct i i1, int n);
static int ia_root(struct i i1, int n, struct i* i2, struct i* i3);
static struct i ia_intersection(struct i i1, struct i i2);
static struct i ia_union(struct i i1, struct i i2);
static struct i ia_center(struct i i1);
static int ia_quadratic_inverse(struct i a, struct i b, struct i c, struct i* r1,
    struct i* r2);
static struct i num_to_int(double num);
static struct i ia_discriminant(struct i a, struct i b, struct i c);
static void ia_split(struct i i1, double factor, struct i* i3, struct i* i4);
static void ia_split_excluding_zero(struct i i1, struct i* i2, struct i* i3);

static char ia_class(struct i i);
static int contains(struct i i, double d);
static int valid_interval(struct i i);
static int finite_interval(struct i i);

//
install_t install_inclpr_interval_arithmetic();

