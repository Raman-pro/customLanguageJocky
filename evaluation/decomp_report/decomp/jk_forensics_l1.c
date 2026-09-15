===== FUNCTION entry @ 0x100000598 size=1444 =====
CFG blocks=49 edges=72

undefined8 entry(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  FILE *pFVar5;
  char *pcVar6;
  long lVar7;
  size_t sVar8;
  char *pcVar9;
  ulong uVar10;
  long lVar11;
  bool bVar12;
  tm *ptVar13;
  time_t local_8398 [64];
  char acStack_8198 [256];
  tm local_8098 [585];
  short local_78;
  char local_76;
  long local_70;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_70 = *(long *)PTR____stack_chk_guard_100004010;
  _puts("=== SYSTEM ===");
  local_8398[0] = _time((time_t *)0x0);
  _localtime_r(local_8398,local_8098);
  pcVar9 = (char *)&_j_buf;
  _strftime((char *)&_j_buf,0x10000,"%Y-%m-%dT%H:%M:%S",local_8098);
  _puts((char *)&_j_buf);
  if ((_main_j_ghb9foiw + _main_j_ghb9foiw * _main_j_ghb9foiw & 0x8000000000000001U) == 1) {
    _puts("false");
  }
  _getcwd((char *)&_j_buf,0x10000);
  _puts((char *)&_j_buf);
  pcVar4 = _getenv("USER");
  pcVar6 = "";
  if (pcVar4 != (char *)0x0) {
    pcVar6 = pcVar4;
  }
  _puts(pcVar6);
  _puts("=== PROCESSES (JSON) ===");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  uVar1 = _proc_listallpids(local_8098,0x8000);
  if ((int)uVar1 < 1) {
    uVar10 = 1;
  }
  else {
    iVar2 = _proc_name(local_8098[0].tm_sec,acStack_8198,0x100);
    if (iVar2 < 1) {
      _snprintf(acStack_8198,0x100,"pid_%d");
    }
    _j_json_escape(local_8398,0x200,acStack_8198);
    uVar3 = _snprintf((char *)((long)&_j_buf + 1),0xffff,"{\"pid\":%d,\"name\":\"%s\"}");
    uVar10 = (ulong)((uVar3 & ((int)uVar3 >> 0x1f ^ 0xffffffffU)) + 1);
    if (uVar1 != 1) {
      lVar11 = (ulong)uVar1 - 1;
      ptVar13 = local_8098;
      do {
        ptVar13 = (tm *)&ptVar13->tm_min;
        if (0xfe70 < uVar10) break;
        iVar2 = _proc_name(*(int *)ptVar13,acStack_8198,0x100);
        if (iVar2 < 1) {
          _snprintf(acStack_8198,0x100,"pid_%d");
        }
        *(undefined1 *)((long)&_j_buf + uVar10) = 0x2c;
        _j_json_escape(local_8398,0x200,acStack_8198);
        uVar1 = _snprintf((char *)((long)&_j_buf + uVar10 + 1),0xffff - uVar10,
                          "{\"pid\":%d,\"name\":\"%s\"}");
        uVar10 = uVar10 + 1 + (ulong)(uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
    }
  }
  *(undefined2 *)((long)&_j_buf + uVar10) = 0x5d;
  _puts((char *)&_j_buf);
  _puts("=== TCP SOCKETS (JSON) ===");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  pFVar5 = _popen("netstat -an -p tcp 2>/dev/null","r");
  if (pFVar5 == (FILE *)0x0) {
    uVar10 = 1;
  }
  else {
    pcVar6 = _fgets((char *)local_8098,0x200,pFVar5);
    if (pcVar6 == (char *)0x0) {
      uVar10 = 1;
    }
    else {
      uVar10 = 1;
      bVar12 = true;
      do {
        iVar2 = _sscanf((char *)local_8098,"%7s %*s %*s %63s %63s %31s");
        if ((iVar2 == 4) && (local_78 == 0x6374 && local_76 == 'p')) {
          if (0xfed4 < uVar10) break;
          if (!bVar12) {
            *(undefined1 *)((long)&_j_buf + uVar10) = 0x2c;
            uVar10 = uVar10 + 1;
          }
          uVar1 = _snprintf((char *)((long)&_j_buf + uVar10),0x10000 - uVar10,
                            "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}");
          bVar12 = false;
          uVar10 = uVar10 + (uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        }
        pcVar6 = _fgets((char *)local_8098,0x200,pFVar5);
      } while (pcVar6 != (char *)0x0);
    }
    _pclose(pFVar5);
  }
  *(undefined2 *)((long)&_j_buf + uVar10) = 0x5d;
  _puts((char *)&_j_buf);
  _puts("=== FS /tmp (JSON) ===");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  lVar11 = _opendir("/tmp");
  if (lVar11 == 0) {
    uVar10 = 1;
  }
  else {
    bVar12 = false;
    uVar10 = 1;
    while (lVar7 = _readdir(lVar11), lVar7 != 0) {
      if (*(char *)(lVar7 + 0x15) != '.') {
        if (0xff38 < uVar10) break;
        if (bVar12) {
          *(undefined1 *)((long)&_j_buf + uVar10) = 0x2c;
          uVar10 = uVar10 + 1;
        }
        _j_json_escape(local_8098,0x400,lVar7 + 0x15);
        uVar1 = _snprintf((char *)((long)&_j_buf + uVar10),0x10000 - uVar10,"\"%s\"");
        uVar10 = uVar10 + (uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        bVar12 = true;
      }
    }
    _closedir(lVar11);
  }
  *(undefined2 *)((long)&_j_buf + uVar10) = 0x5d;
  _puts((char *)&_j_buf);
  iVar2 = _access("/tmp",0);
  pcVar6 = "true";
  if (iVar2 != 0) {
    pcVar6 = "false";
  }
  _puts(pcVar6);
  if (_main_j_o6t0nvls + _main_j_o6t0nvls * _main_j_o6t0nvls < 0) {
    local_8098[0]._0_8_ = _main_j_o6t0nvls * 0x1b + 0x1eb;
    _puts("false");
  }
  pFVar5 = _fopen("/tmp/jocky_test.txt","wb");
  if (pFVar5 != (FILE *)0x0) {
    _fputs("hello from jocky\n",pFVar5);
    _fclose(pFVar5);
  }
  pFVar5 = _fopen("/tmp/jocky_test.txt","rb");
  if (pFVar5 == (FILE *)0x0) {
    pcVar9 = "";
  }
  else {
    sVar8 = _fread(&_j_buf,1,0xffff,pFVar5);
    _fclose(pFVar5);
    *(undefined1 *)((long)&_j_buf + sVar8) = 0;
  }
  _puts(pcVar9);
  _puts("=== REGISTRY (Windows only) ===");
  _j_buf = 0x5d5b;
  DAT_100008012 = 0;
  _puts((char *)&_j_buf);
  _puts("=== MEM DUMP (Windows only, pid=1) ===");
  iVar2 = _puts("done");
  if (*(long *)PTR____stack_chk_guard_100004010 == local_70) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar2);
}


===== FUNCTION _j_json_escape @ 0x100000b3c size=260 =====
CFG blocks=21 edges=30

void _j_json_escape(undefined1 *param_1,ulong param_2,byte *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  
  uVar3 = DAT_100000d48;
  uVar5 = (uint)*param_3;
  if (*param_3 == 0) {
    *param_1 = 0;
    return;
  }
  lVar4 = 0;
  do {
    param_3 = param_3 + 1;
    if (uVar5 < 0xd) {
      if (uVar5 == 9) {
        *(undefined2 *)(param_1 + lVar4) = 0x745c;
        goto LAB_100000b78;
      }
      if (uVar5 == 10) {
        *(undefined2 *)(param_1 + lVar4) = 0x6e5c;
        goto LAB_100000b78;
      }
LAB_100000be0:
      if (uVar5 < 0x20) {
        puVar1 = (undefined4 *)(param_1 + lVar4);
        *puVar1 = (int)uVar3;
        *(char *)(puVar1 + 1) = "0123456789abcdef"[uVar5 >> 4];
        lVar4 = lVar4 + 6;
        *(char *)((long)puVar1 + 5) = "0123456789abcdef"[(ulong)uVar5 & 0xf];
        bVar2 = *param_3;
      }
      else {
        param_1[lVar4] = (char)uVar5;
        lVar4 = lVar4 + 1;
        bVar2 = *param_3;
      }
      uVar5 = (uint)bVar2;
      if (uVar5 == 0) break;
    }
    else {
      if (uVar5 == 0xd) {
        *(undefined2 *)(param_1 + lVar4) = 0x725c;
      }
      else if (uVar5 == 0x5c) {
        *(undefined2 *)(param_1 + lVar4) = 0x5c5c;
      }
      else {
        if (uVar5 != 0x22) goto LAB_100000be0;
        *(undefined2 *)(param_1 + lVar4) = 0x225c;
      }
LAB_100000b78:
      lVar4 = lVar4 + 2;
      uVar5 = (uint)*param_3;
      if (*param_3 == 0) break;
    }
  } while (lVar4 + 8U < param_2);
  param_1[lVar4] = 0;
  return;
}


===== FUNCTION ___stack_chk_fail @ 0x100000c40 size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _access @ 0x100000c4c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _access(char *param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__access_100004018)((int)param_1,param_2);
  return iVar1;
}


===== FUNCTION _closedir @ 0x100000c58 size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000c60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004020)();
  return;
}


===== FUNCTION _fclose @ 0x100000c64 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004028)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100000c70 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004030)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100000c7c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004038)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100000c88 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004040)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100000c94 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004048)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100000ca0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004050)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100000cac size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000cb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004058)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100000cb8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004060)();
  return ptVar1;
}


===== FUNCTION _opendir @ 0x100000cc4 size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004068)();
  return;
}


===== FUNCTION _pclose @ 0x100000cd0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000cd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004070)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100000cdc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ce4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004078)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100000ce8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004080)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100000cf4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000cfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004088)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000d00 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004090)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100000d0c size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_100004098)();
  return;
}


===== FUNCTION _snprintf @ 0x100000d18 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a0)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100000d24 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100000d30 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b0)();
  return sVar1;
}


===== FUNCTION _time @ 0x100000d3c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR__time_1000040b8)();
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


