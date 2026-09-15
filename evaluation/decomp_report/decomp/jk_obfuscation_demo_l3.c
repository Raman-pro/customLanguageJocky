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
      iVar8 = (int)_UNK_100001778;
      iVar9 = (int)((ulong)_UNK_100001778 >> 0x20);
      iVar6 = (int)_DAT_100001770;
      iVar7 = (int)((ulong)_DAT_100001770 >> 0x20);
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
    iVar11 = uVar5 + (int)PTR___mh_execute_header_100001780;
    iVar12 = uVar5 + (int)((ulong)PTR___mh_execute_header_100001780 >> 0x20);
    iVar13 = uVar5 + (int)_UNK_100001788;
    iVar14 = uVar5 + (int)((ulong)_UNK_100001788 >> 0x20);
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


===== FUNCTION entry @ 0x1000007a8 size=2560 =====
CFG blocks=1 edges=0

void entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001000008b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100001792 * 4 + 0x100000804))();
  return;
}


===== FUNCTION _j_oiwo6t0n @ 0x1000011a8 size=1456 =====
CFG blocks=42 edges=67

int _j_oiwo6t0n(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int local_6c;
  
  uVar2 = 0;
  do {
    do {
      while( true ) {
        while( true ) {
          while (2 < uVar2) {
            if (uVar2 == 3) {
              uVar2 = 4;
              if (_j_oiwo6t0n_j_l9dl9lcd + _j_oiwo6t0n_j_l9dl9lcd * _j_oiwo6t0n_j_l9dl9lcd < 0) {
                _j_dc_47_j_rb = _j_enc_47 ^ 0x5c;
                DAT_1000080db = DAT_1000017ee ^ 0x5c;
                DAT_1000080dc = DAT_1000017ef ^ 0x5c;
                DAT_1000080dd = DAT_1000017f0 ^ 0x5c;
                DAT_1000080de = DAT_1000017f1 ^ 0x5c;
                DAT_1000080df = 0;
                _puts((char *)&_j_dc_47_j_rb);
                uVar2 = 4;
              }
            }
            else if (uVar2 == 4) {
              uVar2 = 5;
              if (_j_oiwo6t0n_j_yn30xwb1 + _j_oiwo6t0n_j_yn30xwb1 * _j_oiwo6t0n_j_yn30xwb1 < 0) {
                _j_dc_49_j_rb = _j_enc_49 ^ 100;
                DAT_1000080e1 = DAT_1000017f3 ^ 100;
                DAT_1000080e2 = DAT_1000017f4 ^ 100;
                DAT_1000080e3 = DAT_1000017f5 ^ 100;
                DAT_1000080e4 = DAT_1000017f6 ^ 100;
                DAT_1000080e5 = 0;
                _puts((char *)&_j_dc_49_j_rb);
                uVar2 = 5;
              }
            }
            else if (uVar2 == 5) {
              return local_6c;
            }
          }
          if (uVar2 != 0) break;
          uVar2 = 1;
          if (_j_oiwo6t0n_j_c8jewur5 + _j_oiwo6t0n_j_c8jewur5 * _j_oiwo6t0n_j_c8jewur5 < 0) {
            _j_dc_43_j_rb = _j_enc_43 ^ 0x2c;
            DAT_1000080b1 = DAT_1000017cb ^ 0x2c;
            DAT_1000080b2 = DAT_1000017cc ^ 0x2c;
            DAT_1000080b3 = DAT_1000017cd ^ 0x2c;
            DAT_1000080b4 = DAT_1000017ce ^ 0x2c;
            DAT_1000080b5 = 0;
            _puts((char *)&_j_dc_43_j_rb);
            uVar2 = 1;
          }
        }
        if (uVar2 == 1) break;
        if (uVar2 == 2) {
          uVar2 = 3;
          if (_j_oiwo6t0n_j_ifxsxp8l + _j_oiwo6t0n_j_ifxsxp8l * _j_oiwo6t0n_j_ifxsxp8l < 0) {
            _j_dc_45_j_rb = _j_enc_45 ^ 0xc4;
            DAT_1000080d5 = DAT_1000017e9 ^ 0xc4;
            DAT_1000080d6 = DAT_1000017ea ^ 0xc4;
            DAT_1000080d7 = DAT_1000017eb ^ 0xc4;
            DAT_1000080d8 = DAT_1000017ec ^ 0xc4;
            DAT_1000080d9 = 0;
            _puts((char *)&_j_dc_45_j_rb);
            uVar2 = 3;
          }
        }
      }
      local_6c = 0;
      uVar2 = 2;
    } while (param_1 == 1);
    local_6c = 0;
    uVar2 = param_1;
    do {
      uVar1 = 0;
      do {
        while( true ) {
          while (uVar1 < 4) {
            if (uVar1 < 2) {
              if (uVar1 == 0) {
                uVar1 = 1;
                if (_j_t2hghb9f_j_d8trjgcf + _j_t2hghb9f_j_d8trjgcf * _j_t2hghb9f_j_d8trjgcf < 0) {
                  _j_dc_33_j_rb = _j_enc_33 ^ 0xc1;
                  DAT_1000080b7 = DAT_1000017d0 ^ 0xc1;
                  DAT_1000080b8 = DAT_1000017d1 ^ 0xc1;
                  DAT_1000080b9 = DAT_1000017d2 ^ 0xc1;
                  DAT_1000080ba = DAT_1000017d3 ^ 0xc1;
                  DAT_1000080bb = 0;
                  _puts((char *)&_j_dc_33_j_rb);
                  uVar1 = 1;
                }
              }
              else {
                uVar1 = 2;
                if (_j_t2hghb9f_j_esi0ml05 + _j_t2hghb9f_j_esi0ml05 * _j_t2hghb9f_j_esi0ml05 < 0) {
                  _j_dc_35_j_rb = _j_enc_35 ^ 0x84;
                  DAT_1000080bd = DAT_1000017d5 ^ 0x84;
                  DAT_1000080be = DAT_1000017d6 ^ 0x84;
                  DAT_1000080bf = DAT_1000017d7 ^ 0x84;
                  DAT_1000080c0 = DAT_1000017d8 ^ 0x84;
                  DAT_1000080c1 = 0;
                  _puts((char *)&_j_dc_35_j_rb);
                  uVar1 = 2;
                }
              }
            }
            else if (uVar1 == 2) {
              uVar1 = 3;
              if (_j_t2hghb9f_j_wz7tww6m + _j_t2hghb9f_j_wz7tww6m * _j_t2hghb9f_j_wz7tww6m < 0) {
                _j_dc_37_j_rb = _j_enc_37 ^ 0xc4;
                DAT_1000080c3 = DAT_1000017da ^ 0xc4;
                DAT_1000080c4 = DAT_1000017db ^ 0xc4;
                DAT_1000080c5 = DAT_1000017dc ^ 0xc4;
                DAT_1000080c6 = DAT_1000017dd ^ 0xc4;
                DAT_1000080c7 = 0;
                _puts((char *)&_j_dc_37_j_rb);
                uVar1 = 3;
              }
            }
            else {
              uVar1 = 4;
              if (_j_t2hghb9f_j_2rhh3gut + _j_t2hghb9f_j_2rhh3gut * _j_t2hghb9f_j_2rhh3gut < 0) {
                _j_dc_39_j_rb = _j_enc_39 ^ 0x77;
                DAT_1000080c9 = DAT_1000017df ^ 0x77;
                DAT_1000080ca = DAT_1000017e0 ^ 0x77;
                DAT_1000080cb = DAT_1000017e1 ^ 0x77;
                DAT_1000080cc = DAT_1000017e2 ^ 0x77;
                DAT_1000080cd = 0;
                _puts((char *)&_j_dc_39_j_rb);
                uVar1 = 4;
              }
            }
          }
          if (5 < uVar1) break;
          if (uVar1 == 4) {
            uVar1 = 5;
            if ((_j_t2hghb9f_j_e63tox7h + _j_t2hghb9f_j_e63tox7h * _j_t2hghb9f_j_e63tox7h &
                0x8000000000000001U) == 1) {
              _j_dc_41_j_rb = _j_enc_41 ^ 0xc4;
              DAT_1000080cf = DAT_1000017e4 ^ 0xc4;
              DAT_1000080d0 = DAT_1000017e5 ^ 0xc4;
              DAT_1000080d1 = DAT_1000017e6 ^ 0xc4;
              DAT_1000080d2 = DAT_1000017e7 ^ 0xc4;
              DAT_1000080d3 = 0;
              _puts((char *)&_j_dc_41_j_rb);
              uVar1 = 5;
            }
          }
          else {
            uVar1 = 6;
            if ((uVar2 & 1) == 0) {
              uVar2 = (int)uVar2 >> 1;
              goto LAB_1000013d0;
            }
          }
        }
      } while (uVar1 == 7);
      uVar2 = uVar2 * 3 + 1;
LAB_1000013d0:
      local_6c = local_6c + 1;
    } while (uVar2 != 1);
    uVar2 = 2;
  } while( true );
}


===== FUNCTION _printf @ 0x100001758 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100001764 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00010000176c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


