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
      iVar8 = (int)_UNK_100003f98;
      iVar9 = (int)((ulong)_UNK_100003f98 >> 0x20);
      iVar6 = (int)_DAT_100003f90;
      iVar7 = (int)((ulong)_DAT_100003f90 >> 0x20);
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
    iVar11 = uVar5 + (int)PTR___mh_execute_header_100003fa0;
    iVar12 = uVar5 + (int)((ulong)PTR___mh_execute_header_100003fa0 >> 0x20);
    iVar13 = uVar5 + (int)_UNK_100003fa8;
    iVar14 = uVar5 + (int)((ulong)_UNK_100003fa8 >> 0x20);
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


===== FUNCTION entry @ 0x1000007a8 size=10580 =====
CFG blocks=1 edges=0

void entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000824. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100003fb2 * 4 + 0x1000007cc))();
  return;
}


===== FUNCTION _j_4f7g6fui @ 0x1000030fc size=824 =====
CFG blocks=19 edges=30

int _j_4f7g6fui(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    while( true ) {
      while( true ) {
        while (uVar1 < 3) {
          if (uVar1 == 0) {
            uVar1 = 1;
            if (_j_4f7g6fui_j_gmqpdmt0 + _j_4f7g6fui_j_gmqpdmt0 * _j_4f7g6fui_j_gmqpdmt0 < 0) {
              _j_dc_25_j_rb = _j_enc_25 ^ 0xaf;
              DAT_10000c371 = DAT_10000417f ^ 0xaf;
              DAT_10000c372 = DAT_100004180 ^ 0xaf;
              DAT_10000c373 = DAT_100004181 ^ 0xaf;
              DAT_10000c374 = DAT_100004182 ^ 0xaf;
              DAT_10000c375 = 0;
              _puts((char *)&_j_dc_25_j_rb);
              uVar1 = 1;
            }
          }
          else if (uVar1 == 1) {
            uVar1 = 2;
            if ((_j_4f7g6fui_j_468tmzoa + _j_4f7g6fui_j_468tmzoa * _j_4f7g6fui_j_468tmzoa &
                0x8000000000000001U) == 1) {
              _j_dc_27_j_rb = _j_enc_27 ^ 0x83;
              DAT_10000c377 = DAT_100004184 ^ 0x83;
              DAT_10000c378 = DAT_100004185 ^ 0x83;
              DAT_10000c379 = DAT_100004186 ^ 0x83;
              DAT_10000c37a = DAT_100004187 ^ 0x83;
              DAT_10000c37b = 0;
              _puts((char *)&_j_dc_27_j_rb);
              uVar1 = 2;
            }
          }
          else if (uVar1 == 2) {
            uVar1 = 3;
            if (_j_4f7g6fui_j_qo32bb5q + _j_4f7g6fui_j_qo32bb5q * _j_4f7g6fui_j_qo32bb5q < 0) {
              _j_dc_29_j_rb = _j_enc_29 ^ 0x65;
              DAT_10000c37d = DAT_100004189 ^ 0x65;
              DAT_10000c37e = DAT_10000418a ^ 0x65;
              DAT_10000c37f = DAT_10000418b ^ 0x65;
              DAT_10000c380 = DAT_10000418c ^ 0x65;
              DAT_10000c381 = 0;
              _puts((char *)&_j_dc_29_j_rb);
              uVar1 = 3;
            }
          }
        }
        if (uVar1 != 3) break;
        uVar1 = 4;
        if (_j_4f7g6fui_j_l9dl9lcd + _j_4f7g6fui_j_l9dl9lcd * _j_4f7g6fui_j_l9dl9lcd < 0) {
          _j_dc_31_j_rb = _j_enc_31 ^ 0xee;
          DAT_10000c383 = DAT_10000418e ^ 0xee;
          DAT_10000c384 = DAT_10000418f ^ 0xee;
          DAT_10000c385 = DAT_100004190 ^ 0xee;
          DAT_10000c386 = DAT_100004191 ^ 0xee;
          DAT_10000c387 = 0;
          _puts((char *)&_j_dc_31_j_rb);
          uVar1 = 4;
        }
      }
      if (uVar1 != 4) break;
      uVar1 = 5;
      if (_j_4f7g6fui_j_7m5fgot7 + _j_4f7g6fui_j_7m5fgot7 * _j_4f7g6fui_j_7m5fgot7 < 0) {
        _j_dc_33_j_rb = _j_enc_33 ^ 0xc1;
        DAT_10000c389 = DAT_100004193 ^ 0xc1;
        DAT_10000c38a = DAT_100004194 ^ 0xc1;
        DAT_10000c38b = DAT_100004195 ^ 0xc1;
        DAT_10000c38c = DAT_100004196 ^ 0xc1;
        DAT_10000c38d = 0;
        _puts((char *)&_j_dc_33_j_rb);
        uVar1 = 5;
      }
    }
  } while (uVar1 != 5);
  return param_1 << 1;
}


===== FUNCTION _j_t8lvogp4 @ 0x100003434 size=744 =====
CFG blocks=20 edges=31

int _j_t8lvogp4(int param_1)

{
  uint uVar1;
  int local_6c;
  
  local_6c = 1;
  do {
    uVar1 = 0;
    do {
      while( true ) {
        while( true ) {
          while (uVar1 < 3) {
            if (uVar1 == 0) {
              uVar1 = 1;
              if (_j_t8lvogp4_j_c4i39azk + _j_t8lvogp4_j_c4i39azk * _j_t8lvogp4_j_c4i39azk < 0) {
                _j_dc_57_j_rb = _j_enc_57 ^ 0x5d;
                DAT_10000c3e0 = DAT_1000041df ^ 0x5d;
                DAT_10000c3e1 = DAT_1000041e0 ^ 0x5d;
                DAT_10000c3e2 = DAT_1000041e1 ^ 0x5d;
                DAT_10000c3e3 = DAT_1000041e2 ^ 0x5d;
                DAT_10000c3e4 = 0;
                _puts((char *)&_j_dc_57_j_rb);
                uVar1 = 1;
              }
            }
            else if (uVar1 == 1) {
              uVar1 = 2;
              if (_j_t8lvogp4_j_6lcv1ym4 + _j_t8lvogp4_j_6lcv1ym4 * _j_t8lvogp4_j_6lcv1ym4 < 0) {
                _j_dc_59_j_rb = _j_enc_59 ^ 0xdd;
                DAT_10000c3e6 = DAT_1000041e4 ^ 0xdd;
                DAT_10000c3e7 = DAT_1000041e5 ^ 0xdd;
                DAT_10000c3e8 = DAT_1000041e6 ^ 0xdd;
                DAT_10000c3e9 = DAT_1000041e7 ^ 0xdd;
                DAT_10000c3ea = 0;
                _puts((char *)&_j_dc_59_j_rb);
                uVar1 = 2;
              }
            }
            else if (uVar1 == 2) {
              uVar1 = 3;
              if (_j_t8lvogp4_j_tr73225m + _j_t8lvogp4_j_tr73225m * _j_t8lvogp4_j_tr73225m < 0) {
                _j_dc_61_j_rb = _j_enc_61 ^ 0x1a;
                DAT_10000c3ec = DAT_1000041e9 ^ 0x1a;
                DAT_10000c3ed = DAT_1000041ea ^ 0x1a;
                DAT_10000c3ee = DAT_1000041eb ^ 0x1a;
                DAT_10000c3ef = DAT_1000041ec ^ 0x1a;
                DAT_10000c3f0 = 0;
                _puts((char *)&_j_dc_61_j_rb);
                uVar1 = 3;
              }
            }
          }
          if (uVar1 != 3) break;
          uVar1 = 4;
          if (_j_t8lvogp4_j_r3lyvytq + _j_t8lvogp4_j_r3lyvytq * _j_t8lvogp4_j_r3lyvytq < 0) {
            _j_dc_63_j_rb = _j_enc_63 ^ 0xdb;
            DAT_10000c3f2 = DAT_1000041ee ^ 0xdb;
            DAT_10000c3f3 = DAT_1000041ef ^ 0xdb;
            DAT_10000c3f4 = DAT_1000041f0 ^ 0xdb;
            DAT_10000c3f5 = DAT_1000041f1 ^ 0xdb;
            DAT_10000c3f6 = 0;
            _puts((char *)&_j_dc_63_j_rb);
            uVar1 = 4;
          }
        }
        if (uVar1 != 4) break;
        uVar1 = 5;
        if (param_1 < 2) {
          return local_6c;
        }
      }
    } while (uVar1 != 5);
    local_6c = param_1 * local_6c;
    param_1 = param_1 + -1;
  } while( true );
}


===== FUNCTION _j_m3tuz7o1 @ 0x10000371c size=752 =====
CFG blocks=20 edges=31

int _j_m3tuz7o1(int param_1)

{
  int iVar1;
  uint uVar2;
  int local_6c;
  
  local_6c = 0;
  do {
    uVar2 = 0;
    do {
      while( true ) {
        while( true ) {
          while (uVar2 < 3) {
            if (uVar2 == 0) {
              uVar2 = 1;
              if (param_1 < 2) {
                return param_1 + local_6c;
              }
            }
            else if (uVar2 == 1) {
              uVar2 = 2;
              if (_j_m3tuz7o1_j_0dnkds5g + _j_m3tuz7o1_j_0dnkds5g * _j_m3tuz7o1_j_0dnkds5g < 0) {
                _j_dc_65_j_rb = _j_enc_65 ^ 0x2a;
                DAT_10000c3f8 = DAT_1000041f3 ^ 0x2a;
                DAT_10000c3f9 = DAT_1000041f4 ^ 0x2a;
                DAT_10000c3fa = DAT_1000041f5 ^ 0x2a;
                DAT_10000c3fb = DAT_1000041f6 ^ 0x2a;
                DAT_10000c3fc = 0;
                _puts((char *)&_j_dc_65_j_rb);
                uVar2 = 2;
              }
            }
            else if ((uVar2 == 2) &&
                    (uVar2 = 3,
                    _j_m3tuz7o1_j_9kqju9v1 + _j_m3tuz7o1_j_9kqju9v1 * _j_m3tuz7o1_j_9kqju9v1 < 0)) {
              _j_dc_67_j_rb = _j_enc_67 ^ 0x79;
              DAT_10000c3fe = DAT_1000041f8 ^ 0x79;
              DAT_10000c3ff = DAT_1000041f9 ^ 0x79;
              DAT_10000c400 = DAT_1000041fa ^ 0x79;
              DAT_10000c401 = DAT_1000041fb ^ 0x79;
              DAT_10000c402 = 0;
              _puts((char *)&_j_dc_67_j_rb);
              uVar2 = 3;
            }
          }
          if (uVar2 != 3) break;
          uVar2 = 4;
          if (_j_m3tuz7o1_j_andim2q7 + _j_m3tuz7o1_j_andim2q7 * _j_m3tuz7o1_j_andim2q7 < 0) {
            _j_dc_69_j_rb = _j_enc_69 ^ 0xa1;
            DAT_10000c404 = DAT_1000041fd ^ 0xa1;
            DAT_10000c405 = DAT_1000041fe ^ 0xa1;
            DAT_10000c406 = DAT_1000041ff ^ 0xa1;
            DAT_10000c407 = DAT_100004200 ^ 0xa1;
            DAT_10000c408 = 0;
            _puts((char *)&_j_dc_69_j_rb);
            uVar2 = 4;
          }
        }
        if (uVar2 != 4) break;
        uVar2 = 5;
        if ((_j_m3tuz7o1_j_r5oqef5n * _j_m3tuz7o1_j_r5oqef5n & 0x8000000000000003U) == 3) {
          _j_dc_71_j_rb = _j_enc_71 ^ 0x25;
          DAT_10000c40a = DAT_100004202 ^ 0x25;
          DAT_10000c40b = DAT_100004203 ^ 0x25;
          DAT_10000c40c = DAT_100004204 ^ 0x25;
          DAT_10000c40d = DAT_100004205 ^ 0x25;
          DAT_10000c40e = 0;
          _puts((char *)&_j_dc_71_j_rb);
          uVar2 = 5;
        }
      }
    } while (uVar2 != 5);
    iVar1 = _j_m3tuz7o1(param_1 + -1);
    param_1 = param_1 + -2;
    local_6c = iVar1 + local_6c;
  } while( true );
}


===== FUNCTION _j_dwwcl9v0 @ 0x100003a0c size=768 =====
CFG blocks=22 edges=33

undefined8 _j_dwwcl9v0(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    while( true ) {
      while( true ) {
        while (iVar2 < 2) {
          if (iVar2 == 0) {
            iVar2 = 1;
            if (((uint)_j_dwwcl9v0_j_ey467ne8 * ~(uint)_j_dwwcl9v0_j_ey467ne8 & 1) != 0) {
              _j_dc_75_j_rb = _j_enc_75 ^ 0xb1;
              DAT_10000c42d = DAT_100004225 ^ 0xb1;
              DAT_10000c42e = DAT_100004226 ^ 0xb1;
              DAT_10000c42f = DAT_100004227 ^ 0xb1;
              DAT_10000c430 = DAT_100004228 ^ 0xb1;
              DAT_10000c431 = 0;
              _puts((char *)&_j_dc_75_j_rb);
              iVar2 = 1;
            }
          }
          else if (iVar2 == 1) {
            iVar2 = 2;
            if (_j_dwwcl9v0_j_eymlwma1 + _j_dwwcl9v0_j_eymlwma1 * _j_dwwcl9v0_j_eymlwma1 < 0) {
              _j_dc_77_j_rb = _j_enc_77 ^ 0x10;
              DAT_10000c433 = DAT_10000422a ^ 0x10;
              DAT_10000c434 = DAT_10000422b ^ 0x10;
              DAT_10000c435 = DAT_10000422c ^ 0x10;
              DAT_10000c436 = DAT_10000422d ^ 0x10;
              DAT_10000c437 = 0;
              _puts((char *)&_j_dc_77_j_rb);
              iVar2 = 2;
            }
          }
          else if (iVar2 == -1) {
            return 0;
          }
        }
        if (iVar2 < 5) break;
        if (iVar2 == 5) {
          iVar2 = 6;
          if (_j_dwwcl9v0_j_htb3rgly + _j_dwwcl9v0_j_htb3rgly * _j_dwwcl9v0_j_htb3rgly < 0) {
            _j_dc_81_j_rb = ~_j_enc_81;
            DAT_10000c439 = ~DAT_10000422f;
            DAT_10000c43a = ~DAT_100004230;
            DAT_10000c43b = ~DAT_100004231;
            DAT_10000c43c = ~DAT_100004232;
            DAT_10000c43d = 0;
            _puts((char *)&_j_dc_81_j_rb);
            iVar2 = 6;
          }
        }
        else if ((iVar2 == 6) &&
                (iVar2 = -1,
                _j_dwwcl9v0_j_qumacpti + _j_dwwcl9v0_j_qumacpti * _j_dwwcl9v0_j_qumacpti < 0)) {
          _j_dc_83_j_rb = _j_enc_83 ^ 0xde;
          DAT_10000c43f = DAT_100004234 ^ 0xde;
          DAT_10000c440 = DAT_100004235 ^ 0xde;
          DAT_10000c441 = DAT_100004236 ^ 0xde;
          DAT_10000c442 = DAT_100004237 ^ 0xde;
          DAT_10000c443 = 0;
          _puts((char *)&_j_dc_83_j_rb);
          iVar2 = -1;
        }
      }
      if (iVar2 == 2) break;
      if (iVar2 == 3) {
        uVar1 = _j_u1jd8trj(param_1 + -1);
        return uVar1;
      }
    }
    iVar2 = 3;
  } while (param_1 != 0);
  return 1;
}


===== FUNCTION _j_u1jd8trj @ 0x100003d0c size=580 =====
CFG blocks=18 edges=26

undefined8 _j_u1jd8trj(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    while( true ) {
      while( true ) {
        while (iVar2 < 2) {
          if (iVar2 == 0) {
            iVar2 = 1;
            if (_j_u1jd8trj_j_jhb16brr + _j_u1jd8trj_j_jhb16brr * _j_u1jd8trj_j_jhb16brr < 0) {
              _j_dc_85_j_rb = _j_enc_85 ^ 0xbf;
              DAT_10000c450 = DAT_100004242 ^ 0xbf;
              DAT_10000c451 = DAT_100004243 ^ 0xbf;
              DAT_10000c452 = DAT_100004244 ^ 0xbf;
              DAT_10000c453 = DAT_100004245 ^ 0xbf;
              DAT_10000c454 = 0;
              _puts((char *)&_j_dc_85_j_rb);
              iVar2 = 1;
            }
          }
          else if (iVar2 == 1) {
            iVar2 = 2;
            if (_j_u1jd8trj_j_kpt5jy74 + _j_u1jd8trj_j_kpt5jy74 * _j_u1jd8trj_j_kpt5jy74 < 0) {
              _j_dc_87_j_rb = _j_enc_87 ^ 0x9a;
              DAT_10000c456 = DAT_100004247 ^ 0x9a;
              DAT_10000c457 = DAT_100004248 ^ 0x9a;
              DAT_10000c458 = DAT_100004249 ^ 0x9a;
              DAT_10000c459 = DAT_10000424a ^ 0x9a;
              DAT_10000c45a = 0;
              _puts((char *)&_j_dc_87_j_rb);
              iVar2 = 2;
            }
          }
          else if (iVar2 == -1) {
            return 0;
          }
        }
        if (iVar2 != 2) break;
        iVar2 = 3;
        if (param_1 == 0) {
          return 0;
        }
      }
      if (iVar2 != 5) break;
      iVar2 = -1;
      if (_j_u1jd8trj_j_vl90z625 + _j_u1jd8trj_j_vl90z625 * _j_u1jd8trj_j_vl90z625 < 0) {
        _j_dc_91_j_rb = _j_enc_91 ^ 100;
        DAT_10000c45c = DAT_10000424c ^ 100;
        DAT_10000c45d = DAT_10000424d ^ 100;
        DAT_10000c45e = DAT_10000424e ^ 100;
        DAT_10000c45f = DAT_10000424f ^ 100;
        DAT_10000c460 = 0;
        _puts((char *)&_j_dc_91_j_rb);
        iVar2 = -1;
      }
    }
  } while (iVar2 != 3);
  uVar1 = _j_dwwcl9v0(param_1 + -1);
  return uVar1;
}


===== FUNCTION _printf @ 0x100003f50 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003f58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100008000)((int)param_1);
  return iVar1;
}


===== FUNCTION _putchar @ 0x100003f5c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _putchar(int param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003f64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__putchar_100008008)(param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100003f68 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003f70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100008010)((int)param_1);
  return iVar1;
}


===== FUNCTION _strcmp @ 0x100003f74 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strcmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003f7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strcmp_100008018)((int)param_1);
  return iVar1;
}


===== FUNCTION _strlen @ 0x100003f80 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003f88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100008020)();
  return sVar1;
}


