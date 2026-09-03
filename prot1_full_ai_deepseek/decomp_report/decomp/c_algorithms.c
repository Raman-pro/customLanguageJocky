===== FUNCTION entry @ 0x100000460 size=876 =====
CFG blocks=22 edges=32

undefined8 entry(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  _puts("== fibonacci (iterative) ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== fibonacci (recursive) ==");
  _printf("%d\n");
  _printf("%d\n");
  _fib_rec(10);
  _printf("%d\n");
  _puts("== factorial ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== greatest common divisor ==");
  uVar4 = 0x24;
  uVar1 = 0x30;
  do {
    uVar3 = uVar4;
    uVar4 = 0;
    if (uVar3 != 0) {
      uVar4 = uVar1 / uVar3;
    }
    uVar4 = uVar1 - uVar4 * uVar3;
    uVar1 = uVar3;
  } while (uVar4 != 0);
  _printf("%d\n");
  uVar4 = 5;
  uVar1 = 0x11;
  do {
    uVar3 = uVar4;
    uVar4 = 0;
    if (uVar3 != 0) {
      uVar4 = uVar1 / uVar3;
    }
    uVar4 = uVar1 - uVar4 * uVar3;
    uVar1 = uVar3;
  } while (uVar4 != 0);
  _printf("%d\n");
  _printf("%d\n");
  _puts("== primality ==");
  _puts("true");
  _puts("true");
  _puts("false");
  _puts("true");
  _puts("== primes up to 30 ==");
  uVar4 = 2;
  do {
    if (3 < uVar4) {
      iVar2 = 3;
      do {
        uVar1 = iVar2 - 1;
        uVar3 = 0;
        if (uVar1 != 0) {
          uVar3 = uVar4 / uVar1;
        }
        if (uVar4 == uVar3 * uVar1) goto LAB_100000600;
        uVar1 = iVar2 * iVar2;
        iVar2 = iVar2 + 1;
      } while (uVar1 <= uVar4);
    }
    _printf("%d\n");
LAB_100000600:
    uVar4 = uVar4 + 1;
    if (uVar4 == 0x1f) {
      _puts("== collatz steps ==");
      _printf("%d\n");
      uVar4 = 0x1b;
      do {
        uVar1 = (int)uVar4 >> 1;
        if ((uVar4 & 1) != 0) {
          uVar1 = uVar4 * 3 + 1;
        }
        uVar4 = uVar1;
      } while (uVar1 != 1);
      _printf("%d\n");
      _printf("%d\n");
      _puts("== sum of digits ==");
      _printf("%d\n");
      _printf("%d\n");
      _printf("%d\n");
      _puts("== reverse digits ==");
      _printf("%d\n");
      _printf("%d\n");
      _printf("%d\n");
      _puts("== power ==");
      _printf("%d\n");
      _printf("%d\n");
      _printf("%d\n");
      _puts("== min / max of three ==");
      _printf("%d\n");
      _printf("%d\n");
      _printf("%d\n");
      _puts("== palindrome number ==");
      _puts("true");
      _puts("true");
      _puts("false");
      return 0;
    }
  } while( true );
}


===== FUNCTION _fib_rec @ 0x1000007cc size=76 =====
CFG blocks=5 edges=6

int _fib_rec(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 2) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = _fib_rec(param_1 - 1);
      param_1 = param_1 - 2;
      iVar2 = iVar1 + iVar2;
    } while (1 < param_1);
  }
  return param_1 + iVar2;
}


===== FUNCTION _printf @ 0x100000818 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000824 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000082c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


