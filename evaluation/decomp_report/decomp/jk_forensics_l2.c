===== FUNCTION entry @ 0x100000598 size=4544 =====
CFG blocks=1 edges=0

void entry(void)

{
  (*(code *)PTR____chkstk_darwin_100004000)();
                    /* WARNING: Could not recover jumptable at 0x000100000688. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100001b1a * 4 + 0x100000620))();
  return;
}


===== FUNCTION _j_json_escape @ 0x100001758 size=684 =====
CFG blocks=21 edges=30

void _j_json_escape(undefined1 *param_1,ulong param_2,byte *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  uVar3 = DAT_100001c98;
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
        goto LAB_1000017b4;
      }
      if (uVar4 == 10) {
        *(undefined2 *)(param_1 + lVar5) = 0x6e5c;
        goto LAB_1000017b4;
      }
LAB_10000181c:
      if (uVar4 < 0x20) {
        puVar1 = (undefined4 *)(param_1 + lVar5);
        *puVar1 = (int)uVar3;
        _j_dc_0_j_rb = _j_enc_0 ^ 0x12;
        DAT_100018084 = DAT_100001b60 ^ 0x12;
        DAT_100018085 = DAT_100001b61 ^ 0x12;
        DAT_100018086 = DAT_100001b62 ^ 0x12;
        DAT_100018087 = DAT_100001b63 ^ 0x12;
        DAT_100018088 = DAT_100001b64 ^ 0x12;
        DAT_100018089 = DAT_100001b65 ^ 0x12;
        DAT_10001808a = DAT_100001b66 ^ 0x12;
        DAT_10001808b = DAT_100001b67 ^ 0x12;
        DAT_10001808c = DAT_100001b68 ^ 0x12;
        DAT_10001808d = DAT_100001b69 ^ 0x12;
        DAT_10001808e = DAT_100001b6a ^ 0x12;
        DAT_10001808f = DAT_100001b6b ^ 0x12;
        DAT_100018090 = DAT_100001b6c ^ 0x12;
        DAT_100018091 = DAT_100001b6d ^ 0x12;
        DAT_100018092 = DAT_100001b6e ^ 0x12;
        DAT_100018093 = 0;
        *(byte *)(puVar1 + 1) = (&_j_dc_0_j_rb)[uVar4 >> 4];
        _j_dc_1_j_rb = _j_enc_1 ^ 0x89;
        DAT_100018095 = DAT_100001b70 ^ 0x89;
        DAT_100018096 = DAT_100001b71 ^ 0x89;
        DAT_100018097 = DAT_100001b72 ^ 0x89;
        DAT_100018098 = DAT_100001b73 ^ 0x89;
        DAT_100018099 = DAT_100001b74 ^ 0x89;
        DAT_10001809a = DAT_100001b75 ^ 0x89;
        DAT_10001809b = DAT_100001b76 ^ 0x89;
        DAT_10001809c = DAT_100001b77 ^ 0x89;
        DAT_10001809d = DAT_100001b78 ^ 0x89;
        DAT_10001809e = DAT_100001b79 ^ 0x89;
        DAT_10001809f = DAT_100001b7a ^ 0x89;
        DAT_1000180a0 = DAT_100001b7b ^ 0x89;
        DAT_1000180a1 = DAT_100001b7c ^ 0x89;
        DAT_1000180a2 = DAT_100001b7d ^ 0x89;
        DAT_1000180a3 = DAT_100001b7e ^ 0x89;
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
        if (uVar4 != 0x22) goto LAB_10000181c;
        *(undefined2 *)(param_1 + lVar5) = 0x225c;
      }
LAB_1000017b4:
      lVar5 = lVar5 + 2;
      uVar4 = (uint)*param_3;
      if (*param_3 == 0) break;
    }
  } while (lVar5 + 8U < param_2);
  param_1[lVar5] = 0;
  return;
}


===== FUNCTION ___stack_chk_fail @ 0x100001a04 size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _access @ 0x100001a10 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _access(char *param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__access_100004018)((int)param_1,param_2);
  return iVar1;
}


===== FUNCTION _closedir @ 0x100001a1c size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001a24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004020)();
  return;
}


===== FUNCTION _fclose @ 0x100001a28 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004028)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100001a34 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004030)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100001a40 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004038)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100001a4c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004040)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100001a58 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004048)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100001a64 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004050)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100001a70 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004058)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100001a7c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004060)();
  return ptVar1;
}


===== FUNCTION _opendir @ 0x100001a88 size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004068)();
  return;
}


===== FUNCTION _pclose @ 0x100001a94 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001a9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004070)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100001aa0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004078)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100001aac size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ab4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004080)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100001ab8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004088)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100001ac4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004090)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100001ad0 size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100001ad8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_100004098)();
  return;
}


===== FUNCTION _snprintf @ 0x100001adc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001ae4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a0)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100001ae8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001af0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100001af4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b0)();
  return sVar1;
}


===== FUNCTION _strncmp @ 0x100001b00 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strncmp(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strncmp_1000040b8)((int)param_1);
  return iVar1;
}


===== FUNCTION _time @ 0x100001b0c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001b14. Too many branches */
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


