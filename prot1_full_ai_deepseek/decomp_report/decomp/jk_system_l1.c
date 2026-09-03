===== FUNCTION entry @ 0x100000598 size=1632 =====
CFG blocks=53 edges=78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 entry(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  FILE *pFVar5;
  char *pcVar6;
  size_t sVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  bool bVar11;
  tm *ptVar12;
  time_t local_83a0 [64];
  char acStack_81a0 [256];
  tm local_80a0 [585];
  short local_80;
  char local_7e;
  long local_78;
  
  (*(code *)PTR____chkstk_darwin_100004000)();
  local_78 = *(long *)PTR____stack_chk_guard_100004010;
  _puts("== sys.now() ==");
  local_83a0[0] = _time((time_t *)0x0);
  _localtime_r(local_83a0,local_80a0);
  _strftime((char *)&_j_buf,0x10000,"%Y-%m-%dT%H:%M:%S",local_80a0);
  _puts((char *)&_j_buf);
  _puts("== sys.cwd() ==");
  _getcwd((char *)&_j_buf,0x10000);
  _puts((char *)&_j_buf);
  _puts("== env.get() ==");
  pcVar4 = _getenv("USER");
  pcVar6 = "";
  if (pcVar4 != (char *)0x0) {
    pcVar6 = pcVar4;
  }
  _puts(pcVar6);
  pcVar4 = _getenv("NOT_A_REAL_VAR");
  pcVar6 = "";
  if (pcVar4 != (char *)0x0) {
    pcVar6 = pcVar4;
  }
  _puts(pcVar6);
  _puts("== sys.sleep() ==");
  local_80a0[0].tm_hour = _UNK_100000e18;
  local_80a0[0].tm_mday = _UNK_100000e1c;
  local_80a0[0].tm_sec = _DAT_100000e10;
  local_80a0[0].tm_min = _UNK_100000e14;
  _nanosleep((timespec *)local_80a0,(timespec *)0x0);
  _puts("slept 200ms");
  if ((_main_j_ghb9foiw + _main_j_ghb9foiw * _main_j_ghb9foiw & 0x8000000000000001U) == 1) {
    _puts("false");
  }
  _puts("== sys.process_list() ==");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  uVar1 = _proc_listallpids(local_80a0,0x8000);
  if ((int)uVar1 < 1) {
    uVar9 = 1;
  }
  else {
    iVar2 = _proc_name(local_80a0[0].tm_sec,acStack_81a0,0x100);
    if (iVar2 < 1) {
      _snprintf(acStack_81a0,0x100,"pid_%d");
    }
    _j_json_escape(local_83a0,0x200,acStack_81a0);
    uVar3 = _snprintf((char *)((long)&_j_buf + 1),0xffff,"{\"pid\":%d,\"name\":\"%s\"}");
    uVar9 = (ulong)((uVar3 & ((int)uVar3 >> 0x1f ^ 0xffffffffU)) + 1);
    if (uVar1 != 1) {
      lVar10 = (ulong)uVar1 - 1;
      ptVar12 = local_80a0;
      do {
        ptVar12 = (tm *)&ptVar12->tm_min;
        if (0xfe70 < uVar9) break;
        iVar2 = _proc_name(*(int *)ptVar12,acStack_81a0,0x100);
        if (iVar2 < 1) {
          _snprintf(acStack_81a0,0x100,"pid_%d");
        }
        *(undefined1 *)((long)&_j_buf + uVar9) = 0x2c;
        _j_json_escape(local_83a0,0x200,acStack_81a0);
        uVar1 = _snprintf((char *)((long)&_j_buf + uVar9 + 1),0xffff - uVar9,
                          "{\"pid\":%d,\"name\":\"%s\"}");
        uVar9 = uVar9 + 1 + (ulong)(uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
    }
  }
  *(undefined2 *)((long)&_j_buf + uVar9) = 0x5d;
  _puts((char *)&_j_buf);
  _puts("== net.sockets() ==");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  pFVar5 = _popen("netstat -an -p tcp 2>/dev/null","r");
  if (pFVar5 == (FILE *)0x0) {
    uVar9 = 1;
  }
  else {
    pcVar6 = _fgets((char *)local_80a0,0x200,pFVar5);
    if (pcVar6 == (char *)0x0) {
      uVar9 = 1;
    }
    else {
      uVar9 = 1;
      bVar11 = true;
      do {
        iVar2 = _sscanf((char *)local_80a0,"%7s %*s %*s %63s %63s %31s");
        if ((iVar2 == 4) && (local_80 == 0x6374 && local_7e == 'p')) {
          if (0xfed4 < uVar9) break;
          if (!bVar11) {
            *(undefined1 *)((long)&_j_buf + uVar9) = 0x2c;
            uVar9 = uVar9 + 1;
          }
          uVar1 = _snprintf((char *)((long)&_j_buf + uVar9),0x10000 - uVar9,
                            "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}");
          bVar11 = false;
          uVar9 = uVar9 + (uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        }
        pcVar6 = _fgets((char *)local_80a0,0x200,pFVar5);
      } while (pcVar6 != (char *)0x0);
    }
    _pclose(pFVar5);
  }
  pcVar6 = (char *)&_j_buf;
  *(undefined2 *)((long)&_j_buf + uVar9) = 0x5d;
  _puts((char *)&_j_buf);
  if (_main_j_o6t0nvls + _main_j_o6t0nvls * _main_j_o6t0nvls < 0) {
    local_80a0[0]._0_8_ = _main_j_o6t0nvls * 0x1b + 0x1eb;
    _puts("false");
  }
  _puts("== fs.write / fs.read ==");
  pFVar5 = _fopen("/tmp/jocky_system_tour.txt","wb");
  if (pFVar5 != (FILE *)0x0) {
    _fputs("hello from system tour\n",pFVar5);
    _fclose(pFVar5);
  }
  pFVar5 = _fopen("/tmp/jocky_system_tour.txt","rb");
  if (pFVar5 == (FILE *)0x0) {
    pcVar6 = "";
  }
  else {
    sVar7 = _fread(&_j_buf,1,0xffff,pFVar5);
    _fclose(pFVar5);
    *(undefined1 *)((long)&_j_buf + sVar7) = 0;
  }
  _puts(pcVar6);
  _puts("== fs.exists ==");
  iVar2 = _access("/tmp/jocky_system_tour.txt",0);
  pcVar6 = "true";
  if (iVar2 != 0) {
    pcVar6 = "false";
  }
  _puts(pcVar6);
  iVar2 = _access("/no/such/path",0);
  pcVar6 = "true";
  if (iVar2 != 0) {
    pcVar6 = "false";
  }
  _puts(pcVar6);
  _puts("== fs.list ==");
  _j_buf = CONCAT11(_j_buf._1_1_,0x5b);
  lVar10 = _opendir("/tmp");
  if (lVar10 == 0) {
    uVar9 = 1;
  }
  else {
    bVar11 = false;
    uVar9 = 1;
    while (lVar8 = _readdir(lVar10), lVar8 != 0) {
      if (*(char *)(lVar8 + 0x15) != '.') {
        if (0xff38 < uVar9) break;
        if (bVar11) {
          *(undefined1 *)((long)&_j_buf + uVar9) = 0x2c;
          uVar9 = uVar9 + 1;
        }
        _j_json_escape(local_80a0,0x400,lVar8 + 0x15);
        uVar1 = _snprintf((char *)((long)&_j_buf + uVar9),0x10000 - uVar9,"\"%s\"");
        uVar9 = uVar9 + (uVar1 & ((int)uVar1 >> 0x1f ^ 0xffffffffU));
        bVar11 = true;
      }
    }
    _closedir(lVar10);
  }
  *(undefined2 *)((long)&_j_buf + uVar9) = 0x5d;
  _puts((char *)&_j_buf);
  _puts("== reg.list (Windows only) ==");
  _j_buf = 0x5d5b;
  DAT_100008012 = 0;
  _puts((char *)&_j_buf);
  _puts("== mem.dump (Windows only) ==");
  iVar2 = _puts("done");
  if (*(long *)PTR____stack_chk_guard_100004010 == local_78) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar2);
}


===== FUNCTION _j_json_escape @ 0x100000bf8 size=260 =====
CFG blocks=21 edges=30

void _j_json_escape(undefined1 *param_1,ulong param_2,byte *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  
  uVar3 = DAT_100000e20;
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
        goto LAB_100000c34;
      }
      if (uVar5 == 10) {
        *(undefined2 *)(param_1 + lVar4) = 0x6e5c;
        goto LAB_100000c34;
      }
LAB_100000c9c:
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
        if (uVar5 != 0x22) goto LAB_100000c9c;
        *(undefined2 *)(param_1 + lVar4) = 0x225c;
      }
LAB_100000c34:
      lVar4 = lVar4 + 2;
      uVar5 = (uint)*param_3;
      if (*param_3 == 0) break;
    }
  } while (lVar4 + 8U < param_2);
  param_1[lVar4] = 0;
  return;
}


===== FUNCTION ___stack_chk_fail @ 0x100000cfc size=12 =====
CFG blocks=1 edges=0

void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000d04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


===== FUNCTION _access @ 0x100000d08 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _access(char *param_1,int param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__access_100004018)((int)param_1,param_2);
  return iVar1;
}


===== FUNCTION _closedir @ 0x100000d14 size=12 =====
CFG blocks=1 edges=0

void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004020)();
  return;
}


===== FUNCTION _fclose @ 0x100000d20 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004028)((int)param_1);
  return iVar1;
}


===== FUNCTION _fgets @ 0x100000d2c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004030)(param_1,param_2);
  return pcVar1;
}


===== FUNCTION _fopen @ 0x100000d38 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004038)();
  return pFVar1;
}


===== FUNCTION _fputs @ 0x100000d44 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fputs(char *param_1,FILE *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fputs_100004040)((int)param_1);
  return iVar1;
}


===== FUNCTION _fread @ 0x100000d50 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004048)();
  return sVar1;
}


===== FUNCTION _getcwd @ 0x100000d5c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004050)();
  return pcVar1;
}


===== FUNCTION _getenv @ 0x100000d68 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_100004058)();
  return pcVar1;
}


===== FUNCTION _localtime_r @ 0x100000d74 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * _localtime_r(time_t *param_1,tm *param_2)

{
  tm *ptVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ptVar1 = (tm *)(*(code *)PTR__localtime_r_100004060)();
  return ptVar1;
}


===== FUNCTION _nanosleep @ 0x100000d80 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _nanosleep(timespec *param_1,timespec *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000d88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__nanosleep_100004068)((int)param_1);
  return iVar1;
}


===== FUNCTION _opendir @ 0x100000d8c size=12 =====
CFG blocks=1 edges=0

void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000d94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_100004070)();
  return;
}


===== FUNCTION _pclose @ 0x100000d98 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _pclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__pclose_100004078)((int)param_1);
  return iVar1;
}


===== FUNCTION _popen @ 0x100000da4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _popen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000dac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__popen_100004080)();
  return pFVar1;
}


===== FUNCTION _proc_listallpids @ 0x100000db0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_listallpids(void *buffer,int buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_listallpids_100004088)((int)buffer,buffersize);
  return iVar1;
}


===== FUNCTION _proc_name @ 0x100000dbc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _proc_name(int pid,void *buffer,uint32_t buffersize)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000dc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__proc_name_100004090)(pid,buffer,buffersize);
  return iVar1;
}


===== FUNCTION _puts @ 0x100000dc8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004098)((int)param_1);
  return iVar1;
}


===== FUNCTION _readdir @ 0x100000dd4 size=12 =====
CFG blocks=1 edges=0

void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_1000040a0)();
  return;
}


===== FUNCTION _snprintf @ 0x100000de0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040a8)((int)param_1);
  return iVar1;
}


===== FUNCTION _sscanf @ 0x100000dec size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _sscanf(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000df4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__sscanf_1000040b0)((int)param_1);
  return iVar1;
}


===== FUNCTION _strftime @ 0x100000df8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strftime(char *param_1,size_t param_2,char *param_3,tm *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strftime_1000040b8)();
  return sVar1;
}


===== FUNCTION _time @ 0x100000e04 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t _time(time_t *param_1)

{
  time_t tVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100000e0c. Too many branches */
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


