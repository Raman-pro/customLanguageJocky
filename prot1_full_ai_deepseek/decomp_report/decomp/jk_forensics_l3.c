===== FUNCTION _j_z_5ppufq @ 0x100000598 size=472 =====
CFG blocks=19 edges=24

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _j_z_5ppufq(uint param_1)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined1 auVar15 [12];
  uint uVar18;
  uint uVar19;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  uint uVar35;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar41 [16];
  
  if ((int)param_1 < 1) {
    return 0;
  }
  if (param_1 < 4) {
    iVar6 = 0;
    uVar3 = 1;
  }
  else {
    if (param_1 < 0x10) {
      uVar4 = 0;
      iVar6 = 0;
      uVar5 = 1;
    }
    else {
      uVar4 = param_1 & 0x7ffffff0;
      iVar8 = (int)_UNK_100001d18;
      iVar9 = (int)((ulong)_UNK_100001d18 >> 0x20);
      iVar6 = (int)_DAT_100001d10;
      iVar7 = (int)((ulong)_DAT_100001d10 >> 0x20);
      uVar5 = uVar4 | 1;
      iVar10 = 0;
      iVar11 = 0;
      iVar12 = 0;
      iVar13 = 0;
      auVar15[8] = 0x55;
      auVar15._0_8_ = 0x5555555555555555;
      auVar15[9] = 0x55;
      auVar15[10] = 0x55;
      auVar15[0xb] = 0x55;
      auVar17[0xc] = 0x55;
      auVar17._0_12_ = auVar15;
      auVar17[0xd] = 0x55;
      auVar17[0xe] = 0x55;
      auVar17[0xf] = 0x55;
      iVar14 = 0;
      iVar20 = 0;
      iVar21 = 0;
      iVar22 = 0;
      iVar23 = 0;
      iVar24 = 0;
      iVar25 = 0;
      iVar26 = 0;
      iVar27 = 0;
      iVar28 = 0;
      iVar29 = 0;
      iVar30 = 0;
      uVar3 = uVar4;
      do {
        auVar31._0_4_ = iVar6 + 4;
        auVar31._4_4_ = iVar7 + 4;
        auVar31._8_4_ = iVar8 + 4;
        auVar31._12_4_ = iVar9 + 4;
        auVar33._0_4_ = iVar6 + 8;
        auVar33._4_4_ = iVar7 + 8;
        auVar33._8_4_ = iVar8 + 8;
        auVar33._12_4_ = iVar9 + 8;
        uVar35 = iVar6 * -0x55555555;
        uVar38 = iVar7 * -0x55555555;
        uVar39 = iVar8 * -0x55555555;
        uVar40 = iVar9 * -0x55555555;
        uVar18 = auVar15._8_4_;
        uVar19 = auVar17._12_4_;
        auVar41._0_5_ =
             CONCAT14(-(0x55555555 < uVar38),(uint)(-(0x55555555 < uVar35) & 1)) & 0x1ffffffff;
        auVar41._5_3_ = 0;
        auVar41[8] = -(uVar18 < uVar39) & 1;
        auVar41._9_3_ = 0;
        auVar41[0xc] = -(uVar19 < uVar40) & 1;
        auVar41._13_3_ = 0;
        auVar36._0_5_ =
             CONCAT14(-(0x55555555 < uVar38 + 4),(uint)(-(0x55555555 < uVar35 + 4) & 1)) &
             0x1ffffffff;
        auVar36._5_3_ = 0;
        auVar36[8] = -(uVar18 < uVar39 + 4) & 1;
        auVar36._9_3_ = 0;
        auVar36[0xc] = -(uVar19 < uVar40 + 4) & 1;
        auVar36._13_3_ = 0;
        auVar32._4_4_ = iVar7;
        auVar32._0_4_ = iVar6;
        auVar32._8_4_ = iVar8;
        auVar32._12_4_ = iVar9;
        auVar41 = NEON_ushl(auVar32,auVar41,4);
        auVar34._5_3_ = 0;
        auVar34._0_5_ =
             CONCAT14(-(0x55555555 < uVar38 + 0xaaaaaaac),
                      (uint)(-(0x55555555 < uVar35 + 0xaaaaaaac) & 1)) & 0x1ffffffff;
        auVar34[8] = -(uVar18 < uVar39 + 0xaaaaaaac) & 1;
        auVar34._9_3_ = 0;
        auVar34[0xc] = -(uVar19 < uVar40 + 0xaaaaaaac) & 1;
        auVar34._13_3_ = 0;
        auVar32 = NEON_ushl(auVar31,auVar34,4);
        auVar2._5_3_ = 0;
        auVar2._0_5_ = CONCAT14(-(0x55555555 < uVar38 + 0x55555558),
                                (uint)(-(0x55555555 < uVar35 + 0x55555558) & 1)) & 0x1ffffffff;
        auVar2[8] = -(uVar18 < uVar39 + 0x55555558) & 1;
        auVar2._9_3_ = 0;
        auVar2[0xc] = -(uVar19 < uVar40 + 0x55555558) & 1;
        auVar2._13_3_ = 0;
        auVar34 = NEON_ushl(auVar33,auVar2,4);
        auVar37._4_4_ = iVar7 + 0xc;
        auVar37._0_4_ = iVar6 + 0xc;
        auVar37._8_4_ = iVar8 + 0xc;
        auVar37._12_4_ = iVar9 + 0xc;
        auVar37 = NEON_ushl(auVar37,auVar36,4);
        iVar10 = auVar41._0_4_ + iVar10;
        iVar11 = auVar41._4_4_ + iVar11;
        iVar12 = auVar41._8_4_ + iVar12;
        iVar13 = auVar41._12_4_ + iVar13;
        iVar14 = auVar32._0_4_ + iVar14;
        iVar20 = auVar32._4_4_ + iVar20;
        iVar21 = auVar32._8_4_ + iVar21;
        iVar22 = auVar32._12_4_ + iVar22;
        iVar23 = auVar34._0_4_ + iVar23;
        iVar24 = auVar34._4_4_ + iVar24;
        iVar25 = auVar34._8_4_ + iVar25;
        iVar26 = auVar34._12_4_ + iVar26;
        iVar27 = auVar37._0_4_ + iVar27;
        iVar28 = auVar37._4_4_ + iVar28;
        iVar29 = auVar37._8_4_ + iVar29;
        iVar30 = auVar37._12_4_ + iVar30;
        iVar6 = iVar6 + 0x10;
        iVar7 = iVar7 + 0x10;
        iVar8 = iVar8 + 0x10;
        iVar9 = iVar9 + 0x10;
        uVar3 = uVar3 - 0x10;
      } while (uVar3 != 0);
      iVar6 = iVar27 + iVar23 + iVar14 + iVar10 + iVar28 + iVar24 + iVar20 + iVar11 +
              iVar29 + iVar25 + iVar21 + iVar12 + iVar30 + iVar26 + iVar22 + iVar13;
      if (param_1 == uVar4) {
        return iVar6;
      }
      if ((param_1 & 0xc) == 0) {
        uVar3 = uVar4 | 1;
        goto LAB_100000734;
      }
    }
    uVar18 = param_1 & 0x7ffffffc;
    uVar3 = uVar18 | 1;
    iVar8 = 0;
    iVar9 = 0;
    iVar10 = 0;
    iVar11 = uVar5 + (int)PTR___mh_execute_header_100001d20;
    iVar12 = uVar5 + (int)((ulong)PTR___mh_execute_header_100001d20 >> 0x20);
    iVar13 = uVar5 + (int)_UNK_100001d28;
    iVar14 = uVar5 + (int)((ulong)_UNK_100001d28 >> 0x20);
    iVar7 = uVar4 - uVar18;
    do {
      auVar16._0_5_ =
           CONCAT14(-(0x55555555U < (uint)(iVar12 * -0x55555555)),
                    (uint)(-(0x55555555U < (uint)(iVar11 * -0x55555555)) & 1)) & 0x1ffffffff;
      auVar16._5_3_ = 0;
      auVar16[8] = -(0x55555555U < (uint)(iVar13 * -0x55555555)) & 1;
      auVar16._9_3_ = 0;
      auVar16[0xc] = -(0x55555555U < (uint)(iVar14 * -0x55555555)) & 1;
      auVar16._13_3_ = 0;
      auVar1._4_4_ = iVar12;
      auVar1._0_4_ = iVar11;
      auVar1._8_4_ = iVar13;
      auVar1._12_4_ = iVar14;
      auVar17 = NEON_ushl(auVar1,auVar16,4);
      iVar6 = auVar17._0_4_ + iVar6;
      iVar8 = auVar17._4_4_ + iVar8;
      iVar9 = auVar17._8_4_ + iVar9;
      iVar10 = auVar17._12_4_ + iVar10;
      iVar11 = iVar11 + 4;
      iVar12 = iVar12 + 4;
      iVar13 = iVar13 + 4;
      iVar14 = iVar14 + 4;
      iVar7 = iVar7 + 4;
    } while (iVar7 != 0);
    iVar6 = iVar6 + iVar8 + iVar9 + iVar10;
    if (param_1 == uVar18) {
      return iVar6;
    }
  }
LAB_100000734:
  iVar7 = (param_1 - uVar3) + 1;
  do {
    iVar6 = (uVar3 << (0x55555555 < uVar3 * -0x55555555)) + iVar6;
    uVar3 = uVar3 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return iVar6;
}


===== FUNCTION _j_z_hy797h @ 0x100000770 size=56 =====
CFG blocks=3 edges=4

ulong _j_z_hy797h(ulong param_1,int param_2,int param_3)

{
  if (0 < param_2) {
    do {
      param_1 = (ulong)(uint)((param_3 + (int)param_1 * 0x1f) % 0x2717);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return param_1;
}


===== FUNCTION entry @ 0x1000007a8 size=4512 =====
CFG blocks=1 edges=0

void entry(void)

{
  (*(code *)PTR____chkstk_darwin_100004000)();
                    /* WARNING: Could not recover jumptable at 0x000100000894. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100001d32 * 4 + 0x10000082c))();
  return;
}


===== FUNCTION _j_json_escape @ 0x100001948 size=684 =====
CFG blocks=21 edges=30

void _j_json_escape(undefined1 *param_1,ulong param_2,byte *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  uVar3 = DAT_100001eb0;
  uVar4 = (uint)*param_3;
  if (*param_3 == 0) {
    *param_1 = 0;
    return;
  }
  lVar5 = 0;
  do {
    param_3 = param_3 + 1;
    if (uVar4 < 0xd) {
      if (uVar4 == 9) {
        *(undefined2 *)(param_1 + lVar5) = 0x745c;
        goto LAB_1000019a4;
      }
      if (uVar4 == 10) {
        *(undefined2 *)(param_1 + lVar5) = 0x6e5c;
        goto LAB_1000019a4;
      }
LAB_100001a0c:
      if (uVar4 < 0x20) {
        puVar1 = (undefined4 *)(param_1 + lVar5);
        *puVar1 = (int)uVar3;
        _j_dc_0_j_rb = _j_enc_0 ^ 0x23;
        DAT_100018084 = DAT_100001d78 ^ 0x23;
        DAT_100018085 = DAT_100001d79 ^ 0x23;
        DAT_100018086 = DAT_100001d7a ^ 0x23;
        DAT_100018087 = DAT_100001d7b ^ 0x23;
        DAT_100018088 = DAT_100001d7c ^ 0x23;
        DAT_100018089 = DAT_100001d7d ^ 0x23;
        DAT_10001808a = DAT_100001d7e ^ 0x23;
        DAT_10001808b = DAT_100001d7f ^ 0x23;
        DAT_10001808c = DAT_100001d80 ^ 0x23;
        DAT_10001808d = DAT_100001d81 ^ 0x23;
        DAT_10001808e = DAT_100001d82 ^ 0x23;
        DAT_10001808f = DAT_100001d83 ^ 0x23;
        DAT_100018090 = DAT_100001d84 ^ 0x23;
        DAT_100018091 = DAT_100001d85 ^ 0x23;
        DAT_100018092 = DAT_100001d86 ^ 0x23;
        DAT_100018093 = 0;
        *(byte *)(puVar1 + 1) = (&_j_dc_0_j_rb)[uVar4 >> 4];
        _j_dc_1_j_rb = _j_enc_1 ^ 0x12;
        DAT_100018095 = DAT_100001d88 ^ 0x12;
        DAT_100018096 = DAT_100001d89 ^ 0x12;
        DAT_100018097 = DAT_100001d8a ^ 0x12;
        DAT_100018098 = DAT_100001d8b ^ 0x12;
        DAT_100018099 = DAT_100001d8c ^ 0x12;
        DAT_10001809a = DAT_100001d8d ^ 0x12;
        DAT_10001809b = DAT_100001d8e ^ 0x12;
        DAT_10001809c = DAT_100001d8f ^ 0x12;
        DAT_10001809d = DAT_100001d90 ^ 0x12;
        DAT_10001809e = DAT_100001d91 ^ 0x12;
        DAT_10001809f = DAT_100001d92 ^ 0x12;
        DAT_1000180a0 = DAT_100001d93 ^ 0x12;
        DAT_1000180a1 = DAT_100001d94 ^ 0x12;
        DAT_1000180a2 = DAT_100001d95 ^ 0x12;
        DAT_1000180a3 = DAT_100001d96 ^ 0x12;
        DAT_1000180a4 = 0;
        lVar5 = lVar5 + 6;
        *(byte *)((long)puVar1 + 5) = (&_j_dc_1_j_rb)[(ulong)uVar4 & 0xf];
        bVar2 = *param_3;
      }
      else {
        param_1[lVar5] = (char)uVar4;
        lVar5 = lVar5 + 1;
        bVar2 = *param_3;
      }
      uVar4 = (uint)bVar2;
      if (uVar4 == 0) break;
    }
    else {
      if (uVar4 == 0xd) {
        *(undefined2 *)(param_1 + lVar5) = 0x725c;
      }
      else if (uVar4 == 0x5c) {
        *(undefined2 *)(param_1 + lVar5) = 0x5c5c;
      }
      else {
        if (uVar4 != 0x22) goto LAB_100001a0c;
        *(undefined2 *)(param_1 + lVar5) = 0x225c;
      }
LAB_1000019a4:
      lVar5 = lVar5 + 2;
      uVar4 = (uint)*param_3;
      if (*param_3 == 0) break;
    }
  } while (lVar5 + 8U < param_2);
  param_1[lVar5] = 0;
  return;
}


===== FUNCTION ___stack_chk_fail @ 0x100001bf4 size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001bfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _access @ 0x100001c00 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _access(char *param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__access_100004018)((int)param_1,param_2);
  return iVar1;
}


===== FUNCTION _closedir @ 0x100001c0c size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004020)();
  return;
}


===== FUNCTION _fclose @ 0x100001c18 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004028)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100001c24 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004030)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100001c30 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004038)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100001c3c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004040)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100001c48 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004048)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100001c54 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004050)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100001c60 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004058)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100001c6c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004060)();
  return ptVar1;
}


===== FUNCTION _opendir @ 0x100001c78 size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001c80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004068)();
  return;
}


===== FUNCTION _pclose @ 0x100001c84 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004070)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100001c90 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004078)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100001c9c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004080)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100001ca8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001cb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004088)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100001cb4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001cbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004090)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100001cc0 size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001cc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_100004098)();
  return;
}


===== FUNCTION _snprintf @ 0x100001ccc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001cd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a0)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100001cd8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100001ce4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b0)();
  return sVar1;
}


===== FUNCTION _strncmp @ 0x100001cf0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strncmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001cf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strncmp_1000040b8)((int)param_1);
  return iVar1;
}


===== FUNCTION _time @ 0x100001cfc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001d04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR__time_1000040c0)();
  return tVar1;
}


===== FUNCTION ___chkstk_darwin @ 0x100020000 size=1 =====
CFG blocks=1 edges=0

/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


