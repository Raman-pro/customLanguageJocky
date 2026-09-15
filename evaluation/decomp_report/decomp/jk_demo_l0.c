===== FUNCTION entry @ 0x1000004f8 size=512 =====
CFG blocks=28 edges=41

undefined8 entry(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (_main_j_2rhh3gut * _main_j_2rhh3gut < 0) {
    _printf("%d\n");
  }
  if (_main_j_i31ndk9e * _main_j_i31ndk9e < 0) {
    _printf("%d\n");
  }
  if (_j_t2hghb9f_j_1dwwcl9v * _j_t2hghb9f_j_1dwwcl9v < 0) {
    _printf("%d\n");
  }
  if (_j_t2hghb9f_j_u1jd8trj * _j_t2hghb9f_j_u1jd8trj < 0) {
    _printf("%d\n");
  }
  if (_j_t2hghb9f_j_cfgd3i4e * _j_t2hghb9f_j_cfgd3i4e < 0) {
    _printf("%d\n");
  }
  _puts("JOCKY forensic language v0.1");
  _printf("%d\n");
  if (_j_4f7g6fui_j_l8pat8lv * _j_4f7g6fui_j_l8pat8lv < 0) {
    _printf("%d\n");
  }
  if (_j_4f7g6fui_j_gp4vxxeh * _j_4f7g6fui_j_gp4vxxeh < 0) {
    _printf("%d\n");
  }
  _puts("true");
  iVar4 = 0;
  uVar5 = 2;
  do {
    if (_j_4f7g6fui_j_l8pat8lv * _j_4f7g6fui_j_l8pat8lv < 0) {
      _printf("%d\n");
    }
    if (_j_4f7g6fui_j_gp4vxxeh * _j_4f7g6fui_j_gp4vxxeh < 0) {
      _printf("%d\n");
    }
    if (3 < uVar5) {
      iVar3 = 3;
      do {
        uVar1 = iVar3 - 1;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = uVar5 / uVar1;
        }
        if (uVar5 == uVar2 * uVar1) goto LAB_10000065c;
        uVar1 = iVar3 * iVar3;
        iVar3 = iVar3 + 1;
      } while (uVar1 <= uVar5);
    }
    _printf("%d\n");
    iVar4 = iVar4 + 1;
LAB_10000065c:
    uVar5 = uVar5 + 1;
    if (2 < iVar4) {
      return 0;
    }
  } while( true );
}


===== FUNCTION _printf @ 0x1000006f8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000704 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000070c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


