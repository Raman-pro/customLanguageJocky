===== FUNCTION entry @ 0x1000004f8 size=880 =====
CFG blocks=40 edges=59

undefined8 entry(void)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  
  if (_j_t2hghb9f_j_d8trjgcf + _j_t2hghb9f_j_d8trjgcf * _j_t2hghb9f_j_d8trjgcf < 0) {
    _puts("false");
  }
  if ((_j_t2hghb9f_j_cl9v0u1j + _j_t2hghb9f_j_cl9v0u1j * _j_t2hghb9f_j_cl9v0u1j &
      0x8000000000000001U) == 1) {
    _puts("false");
  }
  if (_j_t2hghb9f_j_2rhh3gut + _j_t2hghb9f_j_2rhh3gut * _j_t2hghb9f_j_2rhh3gut < 0) {
    _puts("false");
  }
  uVar5 = _j_t2hghb9f_j_esi0ml05 * _j_t2hghb9f_j_esi0ml05 & 3;
  uVar3 = -(_j_t2hghb9f_j_esi0ml05 * _j_t2hghb9f_j_esi0ml05);
  if (-1 < (long)uVar3) {
    uVar5 = -(uVar3 & 3);
  }
  if (1 < (long)uVar5) {
    _puts("false");
  }
  if (_j_t2hghb9f_j_gmqpdmt0 + _j_t2hghb9f_j_gmqpdmt0 * _j_t2hghb9f_j_gmqpdmt0 < 0) {
    _puts("false");
  }
  if (_j_t2hghb9f_j_468tmzoa + _j_t2hghb9f_j_468tmzoa * _j_t2hghb9f_j_468tmzoa < 0) {
    _puts("false");
  }
  if (_j_t2hghb9f_j_ifxsxp8l + _j_t2hghb9f_j_ifxsxp8l * _j_t2hghb9f_j_ifxsxp8l < 0) {
    _puts("false");
  }
  _puts("JOCKY forensic language v0.1");
  _printf("%d\n");
  if (_main_j_kiietxma + _main_j_kiietxma * _main_j_kiietxma < 0) {
    _puts("false");
  }
  if ((_j_4f7g6fui_j_ql8pat8l + _j_4f7g6fui_j_ql8pat8l * _j_4f7g6fui_j_ql8pat8l &
      0x8000000000000001U) == 1) {
    _puts("false");
  }
  _puts("true");
  if (_main_j_qb8n9rkr + _main_j_qb8n9rkr * _main_j_qb8n9rkr < 0) {
    _puts("false");
  }
  if (_main_j_c1wchsa4 + _main_j_c1wchsa4 * _main_j_c1wchsa4 < 0) {
    _puts("false");
  }
  if (_main_j_fy0gpnl9 + _main_j_fy0gpnl9 * _main_j_fy0gpnl9 < 0) {
    _puts("false");
  }
  if (_main_j_dj8cfjgn + _main_j_dj8cfjgn * _main_j_dj8cfjgn < 0) {
    _puts("false");
  }
  iVar6 = 0;
  uVar7 = 2;
  do {
    if ((_j_4f7g6fui_j_ql8pat8l + _j_4f7g6fui_j_ql8pat8l * _j_4f7g6fui_j_ql8pat8l &
        0x8000000000000001U) == 1) {
      _puts("false");
    }
    if (3 < uVar7) {
      iVar4 = 3;
      do {
        uVar1 = iVar4 - 1;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = uVar7 / uVar1;
        }
        if (uVar7 == uVar2 * uVar1) goto LAB_1000007f0;
        uVar1 = iVar4 * iVar4;
        iVar4 = iVar4 + 1;
      } while (uVar1 <= uVar7);
    }
    _printf("%d\n");
    iVar6 = iVar6 + 1;
LAB_1000007f0:
    uVar7 = uVar7 + 1;
    if (2 < iVar6) {
      return 0;
    }
  } while( true );
}


===== FUNCTION _printf @ 0x100000868 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000874 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000087c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


