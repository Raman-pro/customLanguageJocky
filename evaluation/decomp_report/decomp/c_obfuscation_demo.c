===== FUNCTION entry @ 0x100000460 size=436 =====
CFG blocks=6 edges=8

undefined8 entry(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  _puts("=== COLLATZ STEPS ===");
  _printf("%d\n");
  uVar4 = 1;
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("=== CLASSIFICATION ===");
  _puts("negative");
  _puts("negative");
  _puts("negative");
  _puts("zero");
  _puts("odd");
  _puts("even");
  _puts("odd");
  _puts("even");
  _puts("odd");
  _puts("even");
  _puts("=== AGGREGATE ===");
  uVar1 = uVar4;
  do {
    while (uVar1 != 1) {
      iVar3 = uVar1 * 3;
      uVar2 = uVar1 & 1;
      uVar1 = (int)uVar1 >> 1;
      if (uVar2 != 0) {
        uVar1 = iVar3 + 1;
      }
    }
    uVar4 = uVar4 + 1;
    uVar1 = uVar4;
  } while (uVar4 != 0xb);
  _printf("%d\n");
  _puts("=== RESULT ===");
  _puts("all builds produce identical output");
  return 0;
}


===== FUNCTION _printf @ 0x100000614 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000061c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000620 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


