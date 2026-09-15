===== FUNCTION entry @ 0x100000548 size=1600 =====
CFG blocks=59 edges=88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry(void)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  FILE *pFVar7;
  size_t sVar8;
  long lVar9;
  long lVar10;
  char cVar11;
  long lVar12;
  bool bVar13;
  ulong uVar14;
  long lVar15;
  time_t local_93a0 [512];
  stat local_83a0 [3];
  char local_81a0;
  char acStack_819f [255];
  tm local_80a0 [585];
  short local_80;
  char local_7e;
  long local_78;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_78 = *(long *)PTR____stack_chk_guard_100004010;
  _puts("== sys.now() ==");
  local_93a0[0] = _time((time_t *)0x0);
  _localtime_r(local_93a0,local_80a0);
  _strftime(&_g_buf,0x10000,"%Y-%m-%dT%H:%M:%S",local_80a0);
  _puts(&_g_buf);
  _puts("== sys.cwd() ==");
  pcVar5 = _getcwd((char *)local_93a0,0x1000);
  _puts(pcVar5);
  _puts("== env.get() ==");
  pcVar6 = _getenv("USER");
  pcVar5 = "";
  if (pcVar6 != (char *)0x0) {
    pcVar5 = pcVar6;
  }
  _puts(pcVar5);
  pcVar6 = _getenv("NOT_A_REAL_VAR");
  pcVar5 = "";
  if (pcVar6 != (char *)0x0) {
    pcVar5 = pcVar6;
  }
  _puts(pcVar5);
  _puts("== sys.sleep() ==");
  local_80a0[0].tm_hour = _UNK_100000ca8;
  local_80a0[0].tm_mday = _UNK_100000cac;
  local_80a0[0].tm_sec = _DAT_100000ca0;
  local_80a0[0].tm_min = _UNK_100000ca4;
  _nanosleep((timespec *)local_80a0,(timespec *)0x0);
  _puts("slept 200ms");
  _puts("== sys.process_list() ==");
  _g_buf = 0x5b;
  uVar2 = _proc_listallpids(local_80a0,0x8000);
  if ((int)uVar2 < 1) {
    lVar15 = 1;
  }
  else {
    uVar14 = 0;
    bVar13 = false;
    lVar15 = 1;
    do {
      iVar4 = _proc_name((&local_80a0[0].tm_sec)[uVar14],&local_81a0,0x100);
      if (iVar4 < 1) {
        _snprintf(&local_81a0,0x100,"pid_%d");
      }
      if (local_81a0 == '\0') {
        lVar10 = 0;
      }
      else {
        lVar10 = 0;
        pcVar5 = &local_81a0;
        cVar11 = local_81a0;
        do {
          pcVar5 = pcVar5 + 1;
          if ((cVar11 == '\\') || (cVar11 == '\"')) {
            *(undefined1 *)((long)local_83a0[0].st_qspare + lVar10 + -0x80) = 0x5c;
            lVar10 = lVar10 + 1;
          }
          *(char *)((long)local_83a0[0].st_qspare + lVar10 + -0x80) = cVar11;
          uVar1 = lVar10 + 3;
          lVar10 = lVar10 + 1;
        } while ((uVar1 < 0x200) && (cVar11 = *pcVar5, cVar11 != '\0'));
      }
      *(undefined1 *)((long)local_83a0[0].st_qspare + lVar10 + -0x80) = 0;
      if (bVar13) {
        (&_g_buf)[lVar15] = 0x2c;
        lVar15 = lVar15 + 1;
      }
      uVar3 = _snprintf(&_g_buf + lVar15,0x10000 - lVar15,"{\"pid\":%d,\"name\":\"%s\"}");
      lVar15 = lVar15 + (ulong)(uVar3 & ((int)uVar3 >> 0x1f ^ 0xffffffffU));
      uVar14 = uVar14 + 1;
      bVar13 = true;
    } while (uVar14 != uVar2);
  }
  *(undefined2 *)(&_g_buf + lVar15) = 0x5d;
  _puts(&_g_buf);
  _puts("== net.sockets() ==");
  _g_buf = 0x5b;
  pFVar7 = _popen("netstat -an -p tcp 2>/dev/null","r");
  if (pFVar7 == (FILE *)0x0) {
    lVar15 = 1;
  }
  else {
    pcVar5 = _fgets((char *)local_80a0,0x200,pFVar7);
    if (pcVar5 == (char *)0x0) {
      lVar15 = 1;
    }
    else {
      lVar15 = 1;
      bVar13 = true;
      do {
        iVar4 = _sscanf((char *)local_80a0,"%7s %*s %*s %63s %63s %31s");
        if ((iVar4 == 4) && (local_80 == 0x6374 && local_7e == 'p')) {
          if (!bVar13) {
            (&_g_buf)[lVar15] = 0x2c;
            lVar15 = lVar15 + 1;
          }
          uVar2 = _snprintf(&_g_buf + lVar15,0x10000 - lVar15,
                            "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}");
          bVar13 = false;
          lVar15 = lVar15 + (ulong)(uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU));
        }
        pcVar5 = _fgets((char *)local_80a0,0x200,pFVar7);
      } while (pcVar5 != (char *)0x0);
    }
    _pclose(pFVar7);
  }
  *(undefined2 *)(&_g_buf + lVar15) = 0x5d;
  _puts(&_g_buf);
  _puts("== fs.write / fs.read ==");
  pFVar7 = _fopen("/tmp/jocky_system_tour.txt","wb");
  if (pFVar7 != (FILE *)0x0) {
    _fputs("hello from system tour\n",pFVar7);
    _fclose(pFVar7);
  }
  pFVar7 = _fopen("/tmp/jocky_system_tour.txt","rb");
  if (pFVar7 != (FILE *)0x0) {
    sVar8 = _fread(&_g_buf,1,0xffff,pFVar7);
    _fclose(pFVar7);
    (&_g_buf)[sVar8] = 0;
    _puts(&_g_buf);
  }
  _puts("== fs.exists ==");
  iVar4 = _stat("/tmp/jocky_system_tour.txt",local_83a0);
  pcVar5 = "true";
  if (iVar4 != 0) {
    pcVar5 = "false";
  }
  _puts(pcVar5);
  iVar4 = _stat("/no/such/path",local_83a0);
  pcVar5 = "true";
  if (iVar4 != 0) {
    pcVar5 = "false";
  }
  _puts(pcVar5);
  _puts("== fs.list ==");
  _g_buf = 0x5b;
  lVar15 = _opendir("/tmp");
  if (lVar15 == 0) {
    lVar10 = 1;
  }
  else {
    bVar13 = false;
    lVar10 = 1;
    while (lVar9 = _readdir(lVar15), lVar9 != 0) {
      cVar11 = *(char *)(lVar9 + 0x15);
      if (cVar11 != '.') {
        if (bVar13) {
          (&_g_buf)[lVar10] = 0x2c;
          lVar10 = lVar10 + 1;
          cVar11 = *(char *)(lVar9 + 0x15);
        }
        lVar12 = 0;
        if (cVar11 != '\0') {
          pcVar5 = (char *)(lVar9 + 0x16);
          do {
            if ((cVar11 == '\\') || (cVar11 == '\"')) {
              *(undefined1 *)((long)&local_80a0[0].tm_sec + lVar12) = 0x5c;
              lVar12 = lVar12 + 1;
              cVar11 = pcVar5[-1];
            }
            *(char *)((long)&local_80a0[0].tm_sec + lVar12) = cVar11;
            uVar14 = lVar12 + 3;
            lVar12 = lVar12 + 1;
            if (0x3ff < uVar14) break;
            cVar11 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar11 != '\0');
        }
        *(undefined1 *)((long)&local_80a0[0].tm_sec + lVar12) = 0;
        uVar2 = _snprintf(&_g_buf + lVar10,0x10000 - lVar10,"\"%s\"");
        lVar10 = lVar10 + (ulong)(uVar2 & ((int)uVar2 >> 0x1f ^ 0xffffffffU));
        bVar13 = true;
      }
    }
    _closedir(lVar15);
  }
  *(undefined2 *)(&_g_buf + lVar10) = 0x5d;
  _puts(&_g_buf);
  _puts("== reg.list (Windows only) ==");
  _puts("[]");
  _puts("== mem.dump (Windows only) ==");
  iVar4 = _puts("done");
  if (*(long *)PTR____stack_chk_guard_100004010 == local_78) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar4);
}


===== FUNCTION ___stack_chk_fail @ 0x100000b88 size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000b90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _closedir @ 0x100000b94 size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004018)();
  return;
}


===== FUNCTION _fclose @ 0x100000ba0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000ba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004020)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100000bac size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004028)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100000bb8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004030)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100000bc4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004038)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100000bd0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004040)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100000bdc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000be4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004048)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100000be8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004050)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100000bf4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000bfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004058)();
  return ptVar1;
}


===== FUNCTION _nanosleep @ 0x100000c00 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _nanosleep(timespec *param_1,timespec *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__nanosleep_100004060)((int)param_1);
  return iVar1;
}


===== FUNCTION _opendir @ 0x100000c0c size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004068)();
  return;
}


===== FUNCTION _pclose @ 0x100000c18 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004070)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100000c24 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004078)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100000c30 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004080)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100000c3c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004088)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000c48 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004090)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100000c54 size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_100004098)();
  return;
}


===== FUNCTION _snprintf @ 0x100000c60 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a0)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100000c6c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _stat @ 0x100000c78 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _stat(char *param_1,stat *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__stat_1000040b0)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100000c84 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b8)();
  return sVar1;
}


===== FUNCTION _time @ 0x100000c90 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  tVar1 = (*(code *)PTR__time_1000040c0)();
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


