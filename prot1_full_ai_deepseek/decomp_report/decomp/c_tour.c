===== FUNCTION entry @ 0x1000004b0 size=1420 =====
CFG blocks=23 edges=35

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry(void)

{
  bool bVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined1 auVar16 [16];
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  
  _puts("== integers ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== booleans ==");
  _puts("true");
  _puts("false");
  _puts("== strings ==");
  _puts("hello, world");
  _putchar(10);
  _puts("escaped: \\ backslash, \" quote");
  _puts("line1\nline2");
  _puts("== variables ==");
  _printf("%d\n");
  _printf("%d\n");
  _puts("jocky");
  _puts("true");
  _puts("false");
  _puts("== arithmetic ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== comparisons ==");
  _puts("true");
  _puts("true");
  _puts("true");
  _puts("true");
  _puts("false");
  _puts("false");
  _puts("== logic ==");
  _puts("true");
  _puts("false");
  _puts("true");
  _puts("false");
  _puts("true");
  _puts("== string operations ==");
  _printf("%d\n");
  _printf("%d\n");
  _puts("true");
  _puts("false");
  _puts("false");
  _puts("== if / else ==");
  _puts("odd");
  _puts("after if");
  _puts("== while ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== for ==");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== assignment ==");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== shadowing ==");
  _printf("%d\n");
  _printf("%d\n");
  _puts("== functions ==");
  _printf("%d\n");
  _printf("%d\n");
  _puts("hello from a void function");
  _printf("%d\n");
  _fib(10);
  _printf("%d\n");
  _puts("adult");
  _puts("== mutual recursion ==");
  _puts("true");
  iVar11 = 9;
  do {
    if (iVar11 == 1) {
      pcVar7 = "false";
      goto LAB_100000878;
    }
    iVar11 = iVar11 + -2;
  } while (iVar11 != 0);
  pcVar7 = "true";
LAB_100000878:
  _puts(pcVar7);
  iVar11 = 7;
  do {
    if (iVar11 == 1) {
      pcVar7 = "false";
      goto LAB_1000008a8;
    }
    iVar11 = iVar11 + -2;
  } while (iVar11 != 0);
  pcVar7 = "true";
LAB_1000008a8:
  _puts(pcVar7);
  _puts("== composition ==");
  _printf("%d\n");
  uVar6 = _fib(5);
  if ((int)uVar6 < 2) goto LAB_100000a0c;
  uVar10 = uVar6;
  if (4 < uVar6) {
    uVar2 = uVar6 - 1;
    if (uVar6 < 0x11) {
      uVar8 = 0;
      iVar11 = 1;
    }
    else {
      iVar22 = uVar6 + _DAT_100000ab0;
      iVar17 = uVar6 + _UNK_100000ab4;
      iVar19 = uVar6 + _UNK_100000ab8;
      iVar21 = uVar6 + _UNK_100000abc;
      iVar11 = 1;
      iVar12 = 1;
      iVar14 = 1;
      iVar18 = 1;
      uVar8 = uVar2 & 0xfffffff0;
      uVar10 = uVar6 - uVar8;
      iVar23 = 1;
      iVar24 = 1;
      iVar25 = 1;
      iVar26 = 1;
      iVar27 = 1;
      iVar28 = 1;
      iVar29 = 1;
      iVar30 = 1;
      iVar31 = 1;
      iVar13 = 1;
      iVar15 = 1;
      iVar20 = 1;
      uVar9 = uVar8;
      do {
        iVar11 = iVar11 * iVar22;
        iVar12 = iVar12 * iVar17;
        iVar14 = iVar14 * iVar19;
        iVar18 = iVar18 * iVar21;
        iVar23 = iVar23 * (iVar22 + -4);
        iVar24 = iVar24 * (iVar17 + -4);
        iVar25 = iVar25 * (iVar19 + -4);
        iVar26 = iVar26 * (iVar21 + -4);
        iVar27 = iVar27 * (iVar22 + -8);
        iVar28 = iVar28 * (iVar17 + -8);
        iVar29 = iVar29 * (iVar19 + -8);
        iVar30 = iVar30 * (iVar21 + -8);
        iVar31 = iVar31 * (iVar22 + -0xc);
        iVar13 = iVar13 * (iVar17 + -0xc);
        iVar15 = iVar15 * (iVar19 + -0xc);
        iVar20 = iVar20 * (iVar21 + -0xc);
        iVar22 = iVar22 + -0x10;
        iVar17 = iVar17 + -0x10;
        iVar19 = iVar19 + -0x10;
        iVar21 = iVar21 + -0x10;
        uVar9 = uVar9 - 0x10;
      } while (uVar9 != 0);
      iVar31 = iVar31 * iVar27 * iVar23 * iVar11;
      iVar13 = iVar13 * iVar28 * iVar24 * iVar12;
      iVar15 = iVar15 * iVar29 * iVar25 * iVar14;
      iVar20 = iVar20 * iVar30 * iVar26 * iVar18;
      auVar16._4_4_ = iVar13;
      auVar16._0_4_ = iVar31;
      auVar16._8_4_ = iVar15;
      auVar16._12_4_ = iVar20;
      auVar5._4_4_ = iVar13;
      auVar5._0_4_ = iVar31;
      auVar5._8_4_ = iVar15;
      auVar5._12_4_ = iVar20;
      auVar16 = NEON_ext(auVar16,auVar5,8,1);
      iVar11 = iVar31 * auVar16._0_4_ * iVar13 * auVar16._4_4_;
      if (uVar2 == uVar8) goto LAB_100000a0c;
      if ((uVar2 & 0xc) == 0) goto LAB_1000009fc;
    }
    uVar9 = uVar2 & 0xfffffffc;
    iVar12 = 1;
    iVar13 = 1;
    iVar14 = 1;
    iVar15 = uVar10 + _DAT_100000ab0;
    iVar18 = uVar10 + _UNK_100000ab4;
    iVar20 = uVar10 + _UNK_100000ab8;
    iVar22 = uVar10 + _UNK_100000abc;
    iVar31 = uVar8 - uVar9;
    do {
      iVar11 = iVar11 * iVar15;
      iVar12 = iVar12 * iVar18;
      iVar13 = iVar13 * iVar20;
      iVar14 = iVar14 * iVar22;
      iVar15 = iVar15 + -4;
      iVar18 = iVar18 + -4;
      iVar20 = iVar20 + -4;
      iVar22 = iVar22 + -4;
      iVar31 = iVar31 + 4;
    } while (iVar31 != 0);
    auVar3._4_4_ = iVar12;
    auVar3._0_4_ = iVar11;
    auVar3._8_4_ = iVar13;
    auVar3._12_4_ = iVar14;
    auVar4._4_4_ = iVar12;
    auVar4._0_4_ = iVar11;
    auVar4._8_4_ = iVar13;
    auVar4._12_4_ = iVar14;
    NEON_ext(auVar3,auVar4,8,1);
    uVar10 = uVar6 - uVar9;
    if (uVar2 == uVar9) goto LAB_100000a0c;
  }
LAB_1000009fc:
  do {
    bVar1 = 2 < uVar10;
    uVar10 = uVar10 - 1;
  } while (bVar1);
LAB_100000a0c:
  _printf("%d\n");
  return 0;
}


===== FUNCTION _fib @ 0x100000a3c size=76 =====
CFG blocks=5 edges=6

int _fib(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 2) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = _fib(param_1 - 1);
      param_1 = param_1 - 2;
      iVar2 = iVar1 + iVar2;
    } while (1 < param_1);
  }
  return param_1 + iVar2;
}


===== FUNCTION _printf @ 0x100000a88 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _putchar @ 0x100000a94 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _putchar(int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__putchar_100004008)(param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000aa0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004010)((int)param_1);
  return iVar1;
}


