/* { dg-do run } */
/* { dg-skip-if "Variadic funcs have all args on stack. Normal funcs have args in registers." { "aarch64*-*-* avr-*-* " } { "*" } { "" } } */
/* { dg-skip-if "Variadic funcs use Base AAPCS.  Normal funcs use VFP variant." { "arm*-*-*" } { "-mfloat-abi=hard" } { "" } } */

/* PR target/12503 */
/* Origin: <pierre.nguyen-tuong@asim.lip6.fr> */

/* Verify that __builtin_apply behaves correctly on targets
   with pre-pushed arguments (e.g. SPARC).  */



#define INTEGER_ARG  5
/* { dg-do run } */
/* { dg-skip-if "Variadic funcs have all args on stack. Normal funcs have args in registers." { "aarch64*-*-* avr-*-* nds32*-*-*" } { "*" } { "" } } */
/* { dg-skip-if "Variadic funcs use Base AAPCS.  Normal funcs use VFP variant." { arm*-*-* && arm_hf_eabi } { "*" } { "" } } */

/* PR target/12503 */
/* Origin: <pierre.nguyen-tuong@asim.lip6.fr> */

/* Verify that __builtin_apply behaves correctly on targets
   with pre-pushed arguments (e.g. SPARC).  */



#define INTEGER_ARG  5

#if defined(__ARM_PCS) || defined(__epiphany__)
/* For Base AAPCS, NAME is passed in r0.  D is passed in r2 and r3.
   E, F and G are passed on stack.  So the size of the stack argument
   data is 20.  */
#define STACK_ARGUMENTS_SIZE  20
#elif defined __MMIX__ || defined __arc__
/* No parameters on stack for bar.  */
#define STACK_ARGUMENTS_SIZE 0
#else
#define STACK_ARGUMENTS_SIZE  64
#endif

extern void abort(void);

void foo(char *name, double d, double e, double f, int g)
{
  if (g != INTEGER_ARG)
    abort();
}

void bar(char *name, ...)
{
  __builtin_apply(foo, __builtin_apply_args(), STACK_ARGUMENTS_SIZE);
}

int main(void)
{
  bar("eeee", 5.444567, 8.90765, 4.567789, INTEGER_ARG);

  return 0;
}

#if defined(__ARM_PCS) || defined(__epiphany__)
/* For Base AAPCS, NAME is passed in r0.  D is passed in r2 and r3.
   E, F and G are passed on stack.  So the size of the stack argument
   data is 20.  */
#define STACK_ARGUMENTS_SIZE  20
#elif defined __MMIX__ || defined __arc__
/* No parameters on stack for bar.  */
#define STACK_ARGUMENTS_SIZE 0
#else
#define STACK_ARGUMENTS_SIZE  64
#endif

extern void abort(void);

void foo(char *name, double d, double e, double f, int g)
{
  if (g != INTEGER_ARG)
    abort();
}

void bar(char *name, ...)
{
  __builtin_apply(foo, __builtin_apply_args(), STACK_ARGUMENTS_SIZE);
}

int main(void)
{
  bar("eeee", 5.444567, 8.90765, 4.567789, INTEGER_ARG);

  return 0;
}
