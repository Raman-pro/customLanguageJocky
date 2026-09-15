===== FUNCTION entry @ 0x100000460 size=180 =====
CFG blocks=10 edges=14

undefined8 entry(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  _puts("JOCKY forensic language v0.1");
  _printf("%d\n");
  _puts("true");
  iVar4 = 0;
  uVar5 = 2;
  do {
    if (3 < uVar5) {
      iVar3 = 3;
      do {
        uVar1 = iVar3 - 1;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = uVar5 / uVar1;
        }
        if (uVar5 == uVar2 * uVar1) goto LAB_1000004c0;
        uVar1 = iVar3 * iVar3;
        iVar3 = iVar3 + 1;
      } while (uVar1 <= uVar5);
    }
    _printf("%d\n");
    iVar4 = iVar4 + 1;
LAB_1000004c0:
    uVar5 = uVar5 + 1;
    if (2 < iVar4) {
      return 0;
    }
  } while( true );
}


===== FUNCTION _printf @ 0x100000514 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000051c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000520 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


