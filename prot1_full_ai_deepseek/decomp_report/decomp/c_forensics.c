===== FUNCTION entry @ 0x1000004f8 size=1356 =====
CFG blocks=59 edges=88

undefined8 entry(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  FILE *pFVar5;
  long lVar6;
  size_t sVar7;
  char cVar8;
  long lVar9;
  char *pcVar10;
  long lVar11;
  char *pcVar12;
  long lVar13;
  ulong uVar14;
  bool bVar15;
  undefined8 local_8398;
  char local_8198;
  char acStack_8197 [255];
  tm local_8098 [585];
  short local_78;
  char local_76;
  long local_70;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_70 = *(long *)PTR____stack_chk_guard_100004010;
  _puts("=== SYSTEM ===");
  local_8398 = _time((time_t *)0x0);
  _localtime_r(&local_8398,local_8098);
  pcVar12 = &_g_buf;
  _strftime(&_g_buf,0x10000,"%Y-%m-%dT%H:%M:%S",local_8098);
  _puts(&_g_buf);
  pcVar4 = _getcwd(&_g_buf,0x10000);
  pcVar10 = "";
  if (pcVar4 != (char *)0x0) {
    pcVar10 = pcVar12;
  }
  _puts(pcVar10);
  pcVar4 = _getenv("USER");
  pcVar10 = "";
  if (pcVar4 != (char *)0x0) {
    pcVar10 = pcVar4;
  }
  _puts(pcVar10);
  _puts("=== PROCESSES (JSON) ===");
  _g_buf = 0x5b;
  uVar1 = _proc_listallpids(local_8098,0x8000);
  if ((int)uVar1 < 1) {
    lVar13 = 1;
  }
  else {
    uVar14 = 0;
    bVar15 = false;
    lVar13 = 1;
    do {
      iVar3 = _proc_name((&local_8098[0].tm_sec)[uVar14],&local_8198,0x100);
      if (iVar3 < 1) {
        _snprintf(&local_8198,0x100,"pid_%d");
        if (local_8198 == '\0') goto LAB_1000006d4;
LAB_10000066c:
        lVar9 = 0;
        pcVar10 = &local_8198;
        cVar8 = local_8198;
        do {
          pcVar10 = pcVar10 + 1;
          if ((cVar8 == '\\') || (lVar6 = lVar9, cVar8 == '\"')) {
            *(undefined1 *)((long)&local_8398 + lVar9) = 0x5c;
            lVar6 = lVar9 + 1;
          }
          *(char *)((long)&local_8398 + lVar6) = cVar8;
          lVar9 = lVar6 + 1;
        } while ((lVar6 + 3U < 0x200) && (cVar8 = *pcVar10, cVar8 != '\0'));
        *(undefined1 *)((long)&local_8398 + lVar6 + 1) = 0;
      }
      else {
        if (local_8198 != '\0') goto LAB_10000066c;
LAB_1000006d4:
        local_8398 = local_8398 & 0xffffffffffffff00;
      }
      if (bVar15) {
        (&_g_buf)[lVar13] = 0x2c;
        lVar13 = lVar13 + 1;
      }
      uVar2 = _snprintf(&_g_buf + lVar13,0x10000 - lVar13,"{\"pid\":%d,\"name\":\"%s\"}");
      lVar13 = lVar13 + (ulong)(uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU));
      uVar14 = uVar14 + 1;
      bVar15 = true;
    } while (uVar14 != uVar1);
  }
  *(undefined2 *)(&_g_buf + lVar13) = 0x5d;
  _puts(&_g_buf);
  _puts("=== TCP SOCKETS (JSON) ===");
  _g_buf = 0x5b;
  pFVar5 = _popen("netstat -an -p tcp 2>/dev/null","r");
  if (pFVar5 == (FILE *)0x0) {
    lVar13 = 1;
  }
  else {
    pcVar10 = _fgets((char *)local_8098,0x200,pFVar5);
    if (pcVar10 == (char *)0x0) {
      lVar13 = 1;
    }
    else {
      lVar13 = 1;
      bVar15 = true;
      do {
        iVar3 = _sscanf((char *)local_8098,"%7s %*s %*s %63s %63s %31s");
        if ((iVar3 == 4) && (local_78 == 0x6374 && local_76 == 'p')) {
          if (!bVar15) {
            (&_g_buf)[lVar13] = 0x2c;
            lVar13 = lVar13 + 1;
          }
          uVar1 = _snprintf(&_g_buf + lVar13,0x10000 - lVar13,
                            "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}");
          bVar15 = false;
          lVar13 = lVar13 + (ulong)(uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        }
        pcVar10 = _fgets((char *)local_8098,0x200,pFVar5);
      } while (pcVar10 != (char *)0x0);
    }
    _pclose(pFVar5);
  }
  *(undefined2 *)(&_g_buf + lVar13) = 0x5d;
  _puts(&_g_buf);
  _puts("=== FS /tmp (JSON) ===");
  _g_buf = 0x5b;
  lVar13 = _opendir("/tmp");
  if (lVar13 == 0) {
    lVar9 = 1;
  }
  else {
    bVar15 = false;
    lVar9 = 1;
    while (lVar6 = _readdir(lVar13), lVar6 != 0) {
      cVar8 = *(char *)(lVar6 + 0x15);
      if (cVar8 != '.') {
        if (bVar15) {
          (&_g_buf)[lVar9] = 0x2c;
          lVar9 = lVar9 + 1;
          cVar8 = *(char *)(lVar6 + 0x15);
        }
        lVar11 = 0;
        if (cVar8 != '\0') {
          pcVar10 = (char *)(lVar6 + 0x16);
          do {
            if ((cVar8 == '\\') || (cVar8 == '\"')) {
              *(undefined1 *)((long)&local_8098[0].tm_sec + lVar11) = 0x5c;
              lVar11 = lVar11 + 1;
              cVar8 = pcVar10[-1];
            }
            *(char *)((long)&local_8098[0].tm_sec + lVar11) = cVar8;
            uVar14 = lVar11 + 3;
            lVar11 = lVar11 + 1;
            if (0x3ff < uVar14) break;
            cVar8 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar8 != '\0');
        }
        *(undefined1 *)((long)&local_8098[0].tm_sec + lVar11) = 0;
        uVar1 = _snprintf(&_g_buf + lVar9,0x10000 - lVar9,"\"%s\"");
        lVar9 = lVar9 + (ulong)(uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        bVar15 = true;
      }
    }
    _closedir(lVar13);
  }
  *(undefined2 *)(&_g_buf + lVar9) = 0x5d;
  _puts(&_g_buf);
  iVar3 = _access("/tmp",0);
  pcVar10 = "true";
  if (iVar3 != 0) {
    pcVar10 = "false";
  }
  _puts(pcVar10);
  pFVar5 = _fopen("/tmp/jocky_test.txt","wb");
  if (pFVar5 != (FILE *)0x0) {
    _fputs("hello from jocky\n",pFVar5);
    _fclose(pFVar5);
  }
  pFVar5 = _fopen("/tmp/jocky_test.txt","rb");
  if (pFVar5 == (FILE *)0x0) {
    pcVar12 = "";
  }
  else {
    sVar7 = _fread(&_g_buf,1,0xffff,pFVar5);
    _fclose(pFVar5);
    (&_g_buf)[sVar7] = 0;
  }
  _puts(pcVar12);
  _puts("=== REGISTRY (Windows only) ===");
  _puts("[]");
  _puts("=== MEM DUMP (Windows only, pid=1) ===");
  iVar3 = _puts("done");
  if (*(long *)PTR____stack_chk_guard_100004010 == local_70) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar3);
}


===== FUNCTION ___stack_chk_fail @ 0x100000a44 size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000a4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _access @ 0x100000a50 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _access(char *param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__access_100004018)((int)param_1,param_2);
  return iVar1;
}


===== FUNCTION _closedir @ 0x100000a5c size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000a64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004020)();
  return;
}


===== FUNCTION _fclose @ 0x100000a68 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004028)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100000a74 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004030)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100000a80 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004038)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100000a8c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000a94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004040)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100000a98 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004048)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100000aa4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000aac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004050)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100000ab0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ab8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004058)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100000abc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004060)();
  return ptVar1;
}


===== FUNCTION _opendir @ 0x100000ac8 size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000ad0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004068)();
  return;
}


===== FUNCTION _pclose @ 0x100000ad4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000adc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004070)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100000ae0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ae8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004078)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100000aec size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000af4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004080)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100000af8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004088)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000b04 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004090)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100000b10 size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000b18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_100004098)();
  return;
}


===== FUNCTION _snprintf @ 0x100000b1c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a0)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100000b28 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100000b34 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b0)();
  return sVar1;
}


===== FUNCTION _time @ 0x100000b40 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR__time_1000040b8)();
  return tVar1;
}


===== FUNCTION ___chkstk_darwin @ 0x10001c000 size=1 =====
CFG blocks=1 edges=0

/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


