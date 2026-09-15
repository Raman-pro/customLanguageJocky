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
      iVar8 = (int)_UNK_100003df8;
      iVar9 = (int)((ulong)_UNK_100003df8 >> 0x20);
      iVar6 = (int)_DAT_100003df0;
      iVar7 = (int)((ulong)_DAT_100003df0 >> 0x20);
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
    iVar11 = uVar5 + (int)PTR___mh_execute_header_100003e00;
    iVar12 = uVar5 + (int)((ulong)PTR___mh_execute_header_100003e00 >> 0x20);
    iVar13 = uVar5 + (int)_UNK_100003e08;
    iVar14 = uVar5 + (int)((ulong)_UNK_100003e08 >> 0x20);
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


===== FUNCTION entry @ 0x1000007a8 size=5888 =====
CFG blocks=1 edges=0

void entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100000830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100003e12 * 4 + 0x100000834))();
  return;
}


===== FUNCTION _j_4f7g6fui @ 0x100001ea8 size=812 =====
CFG blocks=28 edges=43

ulong _j_4f7g6fui(ulong param_1)

{
  uint uVar1;
  int iVar2;
  ulong unaff_x19;
  int unaff_w21;
  ulong unaff_x24;
  ulong uVar3;
  
  iVar2 = 0;
  uVar1 = (uint)param_1;
  do {
    while( true ) {
      while( true ) {
        while (iVar2 < 3) {
          if (iVar2 < 1) {
            if (iVar2 == 0) {
              iVar2 = 1;
              if (uVar1 < 2) {
                return param_1;
              }
            }
            else if (iVar2 == -1) {
              return 0;
            }
          }
          else if (iVar2 == 1) {
            unaff_x24 = 0;
            unaff_x19 = 1;
            iVar2 = 2;
            unaff_w21 = 2;
            if (_j_4f7g6fui_j_ifxsxp8l + _j_4f7g6fui_j_ifxsxp8l * _j_4f7g6fui_j_ifxsxp8l < 0) {
              _j_dc_25_j_rb = _j_enc_25 ^ 0xaf;
              DAT_10000c1fb = DAT_100003e5d ^ 0xaf;
              DAT_10000c1fc = DAT_100003e5e ^ 0xaf;
              DAT_10000c1fd = DAT_100003e5f ^ 0xaf;
              DAT_10000c1fe = DAT_100003e60 ^ 0xaf;
              DAT_10000c1ff = 0;
              _puts((char *)&_j_dc_25_j_rb);
              unaff_x24 = 0;
              iVar2 = 2;
            }
          }
          else if ((iVar2 == 2) &&
                  (iVar2 = 3,
                  _j_4f7g6fui_j_7m5fgot7 + _j_4f7g6fui_j_7m5fgot7 * _j_4f7g6fui_j_7m5fgot7 < 0)) {
            _j_dc_27_j_rb = _j_enc_27 ^ 0x83;
            DAT_10000c201 = DAT_100003e62 ^ 0x83;
            DAT_10000c202 = DAT_100003e63 ^ 0x83;
            DAT_10000c203 = DAT_100003e64 ^ 0x83;
            DAT_10000c204 = DAT_100003e65 ^ 0x83;
            DAT_10000c205 = 0;
            _puts((char *)&_j_dc_27_j_rb);
            iVar2 = 3;
          }
        }
        if (4 < iVar2) break;
        if (iVar2 == 3) {
          iVar2 = 4;
          if (_j_4f7g6fui_j_l9dl9lcd + _j_4f7g6fui_j_l9dl9lcd * _j_4f7g6fui_j_l9dl9lcd < 0) {
            _j_dc_29_j_rb = _j_enc_29 ^ 0x65;
            DAT_10000c207 = DAT_100003e67 ^ 0x65;
            DAT_10000c208 = DAT_100003e68 ^ 0x65;
            DAT_10000c209 = DAT_100003e69 ^ 0x65;
            DAT_10000c20a = DAT_100003e6a ^ 0x65;
            DAT_10000c20b = 0;
            _puts((char *)&_j_dc_29_j_rb);
            iVar2 = 4;
          }
        }
        else if ((iVar2 == 4) && (iVar2 = 5, unaff_w21 <= (int)uVar1)) {
          iVar2 = (uVar1 + 1) - unaff_w21;
          uVar3 = unaff_x24;
          do {
            unaff_x24 = unaff_x19;
            unaff_x19 = (ulong)(uint)((int)unaff_x24 + (int)uVar3);
            iVar2 = iVar2 + -1;
            uVar3 = unaff_x24;
          } while (iVar2 != 0);
          iVar2 = 5;
          unaff_w21 = uVar1 + 1;
        }
      }
      if (iVar2 != 7) break;
      iVar2 = -1;
      if (_j_4f7g6fui_j_qb8n9rkr + _j_4f7g6fui_j_qb8n9rkr * _j_4f7g6fui_j_qb8n9rkr < 0) {
        _j_dc_33_j_rb = _j_enc_33 ^ 0xc1;
        DAT_10000c20d = DAT_100003e6c ^ 0xc1;
        DAT_10000c20e = DAT_100003e6d ^ 0xc1;
        DAT_10000c20f = DAT_100003e6e ^ 0xc1;
        DAT_10000c210 = DAT_100003e6f ^ 0xc1;
        DAT_10000c211 = 0;
        _puts((char *)&_j_dc_33_j_rb);
        iVar2 = -1;
      }
    }
  } while (iVar2 != 5);
  return unaff_x19;
}


===== FUNCTION _j_t2hghb9f @ 0x1000021d4 size=600 =====
CFG blocks=17 edges=26

int _j_t2hghb9f(int param_1)

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
          while (uVar2 < 2) {
            if (uVar2 == 0) {
              uVar2 = 1;
              if ((_j_t2hghb9f_j_xsop1o4p + _j_t2hghb9f_j_xsop1o4p * _j_t2hghb9f_j_xsop1o4p &
                  0x8000000000000001U) == 1) {
                _j_dc_35_j_rb = _j_enc_35 ^ 0x84;
                DAT_10000c235 = DAT_100003e91 ^ 0x84;
                DAT_10000c236 = DAT_100003e92 ^ 0x84;
                DAT_10000c237 = DAT_100003e93 ^ 0x84;
                DAT_10000c238 = DAT_100003e94 ^ 0x84;
                DAT_10000c239 = 0;
                _puts((char *)&_j_dc_35_j_rb);
                uVar2 = 1;
              }
            }
            else if ((uVar2 == 1) && (uVar2 = 2, param_1 < 2)) {
              return param_1 + local_6c;
            }
          }
          if (uVar2 != 2) break;
          uVar2 = 3;
          if (_j_t2hghb9f_j_ney0af9f + _j_t2hghb9f_j_ney0af9f * _j_t2hghb9f_j_ney0af9f < 0) {
            _j_dc_37_j_rb = _j_enc_37 ^ 0xc4;
            DAT_10000c23b = DAT_100003e96 ^ 0xc4;
            DAT_10000c23c = DAT_100003e97 ^ 0xc4;
            DAT_10000c23d = DAT_100003e98 ^ 0xc4;
            DAT_10000c23e = DAT_100003e99 ^ 0xc4;
            DAT_10000c23f = 0;
            _puts((char *)&_j_dc_37_j_rb);
            uVar2 = 3;
          }
        }
        if (uVar2 != 3) break;
        uVar2 = 4;
        if (_j_t2hghb9f_j_mbs50pn8 + _j_t2hghb9f_j_mbs50pn8 * _j_t2hghb9f_j_mbs50pn8 < 0) {
          _j_dc_39_j_rb = _j_enc_39 ^ 0x77;
          DAT_10000c241 = DAT_100003e9b ^ 0x77;
          DAT_10000c242 = DAT_100003e9c ^ 0x77;
          DAT_10000c243 = DAT_100003e9d ^ 0x77;
          DAT_10000c244 = DAT_100003e9e ^ 0x77;
          DAT_10000c245 = 0;
          _puts((char *)&_j_dc_39_j_rb);
          uVar2 = 4;
        }
      }
    } while (uVar2 != 4);
    iVar1 = _j_t2hghb9f(param_1 + -1);
    param_1 = param_1 + -2;
    local_6c = iVar1 + local_6c;
  } while( true );
}


===== FUNCTION _j_vls2wrj8 @ 0x10000242c size=852 =====
CFG blocks=26 edges=40

uint _j_vls2wrj8(uint param_1,uint param_2)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  uint local_70;
  uint local_6c;
  
  local_70 = param_1;
  local_6c = param_2;
  do {
    uVar2 = 0;
    do {
      while( true ) {
        while (uVar2 < 4) {
          if (uVar2 < 2) {
            if (uVar2 == 0) {
              uVar2 = 1;
              if (_j_vls2wrj8_j_wkye35n7 + _j_vls2wrj8_j_wkye35n7 * _j_vls2wrj8_j_wkye35n7 < 0) {
                _j_dc_49_j_rb = _j_enc_49 ^ 100;
                DAT_10000c275 = DAT_100003ecc ^ 100;
                DAT_10000c276 = DAT_100003ecd ^ 100;
                DAT_10000c277 = DAT_100003ece ^ 100;
                DAT_10000c278 = DAT_100003ecf ^ 100;
                DAT_10000c279 = 0;
                _puts((char *)&_j_dc_49_j_rb);
                uVar2 = 1;
              }
            }
            else {
              uVar2 = 2;
              if (_j_vls2wrj8_j_vyo8ezrt + _j_vls2wrj8_j_vyo8ezrt * _j_vls2wrj8_j_vyo8ezrt < 0) {
                _j_dc_51_j_rb = _j_enc_51 ^ 0x25;
                DAT_10000c27b = DAT_100003ed1 ^ 0x25;
                DAT_10000c27c = DAT_100003ed2 ^ 0x25;
                DAT_10000c27d = DAT_100003ed3 ^ 0x25;
                DAT_10000c27e = DAT_100003ed4 ^ 0x25;
                DAT_10000c27f = 0;
                _puts((char *)&_j_dc_51_j_rb);
                uVar2 = 2;
              }
            }
          }
          else if (uVar2 == 2) {
            uVar2 = 3;
            if (_j_vls2wrj8_j_7yom7oru + _j_vls2wrj8_j_7yom7oru * _j_vls2wrj8_j_7yom7oru < 0) {
              _j_dc_53_j_rb = _j_enc_53 ^ 0xf6;
              DAT_10000c281 = DAT_100003ed6 ^ 0xf6;
              DAT_10000c282 = DAT_100003ed7 ^ 0xf6;
              DAT_10000c283 = DAT_100003ed8 ^ 0xf6;
              DAT_10000c284 = DAT_100003ed9 ^ 0xf6;
              DAT_10000c285 = 0;
              _puts((char *)&_j_dc_53_j_rb);
              uVar2 = 3;
            }
          }
          else {
            uVar2 = 4;
            if (_j_vls2wrj8_j_46wox3cs + _j_vls2wrj8_j_46wox3cs * _j_vls2wrj8_j_46wox3cs < 0) {
              _j_dc_55_j_rb = _j_enc_55 ^ 0x5b;
              DAT_10000c287 = DAT_100003edb ^ 0x5b;
              DAT_10000c288 = DAT_100003edc ^ 0x5b;
              DAT_10000c289 = DAT_100003edd ^ 0x5b;
              DAT_10000c28a = DAT_100003ede ^ 0x5b;
              DAT_10000c28b = 0;
              _puts((char *)&_j_dc_55_j_rb);
              uVar2 = 4;
            }
          }
        }
        if (5 < uVar2) break;
        if (uVar2 == 4) {
          uVar3 = _j_vls2wrj8_j_00zpd4o1 * _j_vls2wrj8_j_00zpd4o1 & 3;
          uVar1 = -(_j_vls2wrj8_j_00zpd4o1 * _j_vls2wrj8_j_00zpd4o1);
          if (-1 < (long)uVar1) {
            uVar3 = -(uVar1 & 3);
          }
          uVar2 = 5;
          if (1 < (long)uVar3) {
            _j_dc_57_j_rb = _j_enc_57 ^ 0x5d;
            DAT_10000c28d = DAT_100003ee0 ^ 0x5d;
            DAT_10000c28e = DAT_100003ee1 ^ 0x5d;
            DAT_10000c28f = DAT_100003ee2 ^ 0x5d;
            DAT_10000c290 = DAT_100003ee3 ^ 0x5d;
            DAT_10000c291 = 0;
            _puts((char *)&_j_dc_57_j_rb);
            uVar2 = 5;
          }
        }
        else {
          uVar2 = 6;
          if (local_6c == 0) {
            return local_70;
          }
        }
      }
    } while (uVar2 == 7);
    uVar2 = 0;
    if (local_6c != 0) {
      uVar2 = local_70 / local_6c;
    }
    uVar2 = local_70 - uVar2 * local_6c;
    local_70 = local_6c;
    local_6c = uVar2;
  } while( true );
}


===== FUNCTION _j_t8lvogp4 @ 0x100002780 size=940 =====
CFG blocks=35 edges=53

undefined8 _j_t8lvogp4(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    do {
      while( true ) {
        while( true ) {
          while (iVar2 < 3) {
            if (iVar2 < 1) {
              if (iVar2 == 0) {
                iVar2 = 1;
                if (_j_t8lvogp4_j_6lcv1ym4 + _j_t8lvogp4_j_6lcv1ym4 * _j_t8lvogp4_j_6lcv1ym4 < 0) {
                  _j_dc_59_j_rb = _j_enc_59 ^ 0xdd;
                  DAT_10000c2a3 = DAT_100003ef4 ^ 0xdd;
                  DAT_10000c2a4 = DAT_100003ef5 ^ 0xdd;
                  DAT_10000c2a5 = DAT_100003ef6 ^ 0xdd;
                  DAT_10000c2a6 = DAT_100003ef7 ^ 0xdd;
                  DAT_10000c2a7 = 0;
                  _puts((char *)&_j_dc_59_j_rb);
                  iVar2 = 1;
                }
              }
              else if (iVar2 == -1) {
                return 0;
              }
            }
            else if (iVar2 == 1) {
              iVar2 = 2;
              if (_j_t8lvogp4_j_s1u5c2bw + _j_t8lvogp4_j_s1u5c2bw * _j_t8lvogp4_j_s1u5c2bw < 0) {
                _j_dc_61_j_rb = _j_enc_61 ^ 0x1a;
                DAT_10000c2a9 = DAT_100003ef9 ^ 0x1a;
                DAT_10000c2aa = DAT_100003efa ^ 0x1a;
                DAT_10000c2ab = DAT_100003efb ^ 0x1a;
                DAT_10000c2ac = DAT_100003efc ^ 0x1a;
                DAT_10000c2ad = 0;
                _puts((char *)&_j_dc_61_j_rb);
                iVar2 = 2;
              }
            }
            else if ((iVar2 == 2) && (iVar2 = 3, (int)param_1 < 2)) {
              return 0;
            }
          }
          if (iVar2 < 5) break;
          if (iVar2 == 7) {
            iVar2 = 8;
            if (_j_t8lvogp4_j_6t4eaaox + _j_t8lvogp4_j_6t4eaaox * _j_t8lvogp4_j_6t4eaaox < 0) {
              _j_dc_67_j_rb = _j_enc_67 ^ 0x79;
              DAT_10000c2b5 = DAT_100003f03 ^ 0x79;
              DAT_10000c2b6 = DAT_100003f04 ^ 0x79;
              DAT_10000c2b7 = DAT_100003f05 ^ 0x79;
              DAT_10000c2b8 = DAT_100003f06 ^ 0x79;
              DAT_10000c2b9 = 0;
              _puts((char *)&_j_dc_67_j_rb);
              iVar2 = 8;
            }
          }
          else if (iVar2 == 8) {
            iVar2 = -1;
            if (_j_t8lvogp4_j_2c53ign6 + _j_t8lvogp4_j_2c53ign6 * _j_t8lvogp4_j_2c53ign6 < 0) {
              _j_dc_69_j_rb = _j_enc_69 ^ 0xa1;
              DAT_10000c2bb = DAT_100003f08 ^ 0xa1;
              DAT_10000c2bc = DAT_100003f09 ^ 0xa1;
              DAT_10000c2bd = DAT_100003f0a ^ 0xa1;
              DAT_10000c2be = DAT_100003f0b ^ 0xa1;
              DAT_10000c2bf = 0;
              _puts((char *)&_j_dc_69_j_rb);
              iVar2 = -1;
            }
          }
          else if (iVar2 == 5) {
            return 1;
          }
        }
        if (iVar2 == 3) break;
        if ((iVar2 == 4) &&
           (iVar2 = 5, _j_t8lvogp4_j_r3lyvytq + _j_t8lvogp4_j_r3lyvytq * _j_t8lvogp4_j_r3lyvytq < 0)
           ) {
          _j_dc_63_j_rb = _j_enc_63 ^ 0xdb;
          DAT_10000c2af = DAT_100003efe ^ 0xdb;
          DAT_10000c2b0 = DAT_100003eff ^ 0xdb;
          DAT_10000c2b1 = DAT_100003f00 ^ 0xdb;
          DAT_10000c2b2 = DAT_100003f01 ^ 0xdb;
          DAT_10000c2b3 = 0;
          _puts((char *)&_j_dc_63_j_rb);
          iVar2 = 5;
        }
      }
      iVar2 = 4;
    } while ((int)param_1 < 4);
    uVar3 = 2;
    do {
      uVar1 = 0;
      if (uVar3 != 0) {
        uVar1 = param_1 / uVar3;
      }
      if (param_1 == uVar1 * uVar3) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while ((int)(uVar3 * uVar3) <= (int)param_1);
    iVar2 = 4;
  } while( true );
}


===== FUNCTION _j_vxxehlw0 @ 0x100002b2c size=1004 =====
CFG blocks=28 edges=45

/* WARNING: Removing unreachable block (ram,0x000100002ed0) */
/* WARNING: Removing unreachable block (ram,0x000100002edc) */

ulong _j_vxxehlw0(uint param_1)

{
  ulong uVar1;
  uint uVar2;
  uint in_w9;
  ulong uVar3;
  uint uVar4;
  ulong unaff_x25;
  
  uVar2 = 0;
  do {
    while( true ) {
      while( true ) {
        while (uVar4 = in_w9, in_w9 = uVar4, uVar2 < 3) {
          if (uVar2 == 0) {
            uVar3 = _j_vxxehlw0_j_ybligual * _j_vxxehlw0_j_ybligual & 3;
            uVar1 = -(_j_vxxehlw0_j_ybligual * _j_vxxehlw0_j_ybligual);
            if (-1 < (long)uVar1) {
              uVar3 = -(uVar1 & 3);
            }
            uVar2 = 1;
            if (1 < (long)uVar3) {
              _j_dc_71_j_rb = _j_enc_71 ^ 0x25;
              DAT_10000c317 = DAT_100003f59 ^ 0x25;
              DAT_10000c318 = DAT_100003f5a ^ 0x25;
              DAT_10000c319 = DAT_100003f5b ^ 0x25;
              DAT_10000c31a = DAT_100003f5c ^ 0x25;
              DAT_10000c31b = 0;
              _puts((char *)&_j_dc_71_j_rb);
              uVar2 = 1;
            }
          }
          else if (uVar2 == 1) {
            uVar2 = 2;
            if (_j_vxxehlw0_j_r5oqef5n + _j_vxxehlw0_j_r5oqef5n * _j_vxxehlw0_j_r5oqef5n < 0) {
              _j_dc_73_j_rb = _j_enc_73 ^ 0x62;
              DAT_10000c31d = DAT_100003f5e ^ 0x62;
              DAT_10000c31e = DAT_100003f5f ^ 0x62;
              DAT_10000c31f = DAT_100003f60 ^ 0x62;
              DAT_10000c320 = DAT_100003f61 ^ 0x62;
              DAT_10000c321 = 0;
              _puts((char *)&_j_dc_73_j_rb);
              uVar2 = 2;
            }
          }
          else if (uVar2 == 2) {
            unaff_x25 = 0;
            uVar2 = 3;
            in_w9 = param_1;
            if (_j_vxxehlw0_j_ey467ne8 + _j_vxxehlw0_j_ey467ne8 * _j_vxxehlw0_j_ey467ne8 < 0) {
              _j_dc_75_j_rb = _j_enc_75 ^ 0xb1;
              DAT_10000c323 = DAT_100003f63 ^ 0xb1;
              DAT_10000c324 = DAT_100003f64 ^ 0xb1;
              DAT_10000c325 = DAT_100003f65 ^ 0xb1;
              DAT_10000c326 = DAT_100003f66 ^ 0xb1;
              DAT_10000c327 = 0;
              _puts((char *)&_j_dc_75_j_rb);
              unaff_x25 = 0;
              uVar2 = 3;
            }
          }
        }
        if (4 < uVar2) break;
        if (uVar2 == 3) {
          uVar2 = 4;
          if (_j_vxxehlw0_j_8o5fuudq + _j_vxxehlw0_j_8o5fuudq * _j_vxxehlw0_j_8o5fuudq < 0) {
            _j_dc_77_j_rb = _j_enc_77 ^ 0x10;
            DAT_10000c329 = DAT_100003f68 ^ 0x10;
            DAT_10000c32a = DAT_100003f69 ^ 0x10;
            DAT_10000c32b = DAT_100003f6a ^ 0x10;
            DAT_10000c32c = DAT_100003f6b ^ 0x10;
            DAT_10000c32d = 0;
            _puts((char *)&_j_dc_77_j_rb);
            uVar2 = 4;
          }
        }
        else if ((uVar2 == 4) &&
                (uVar2 = 5,
                _j_vxxehlw0_j_5tphmacs + _j_vxxehlw0_j_5tphmacs * _j_vxxehlw0_j_5tphmacs < 0)) {
          _j_dc_79_j_rb = _j_enc_79 ^ 0xd3;
          DAT_10000c32f = DAT_100003f6d ^ 0xd3;
          DAT_10000c330 = DAT_100003f6e ^ 0xd3;
          DAT_10000c331 = DAT_100003f6f ^ 0xd3;
          DAT_10000c332 = DAT_100003f70 ^ 0xd3;
          DAT_10000c333 = 0;
          _puts((char *)&_j_dc_79_j_rb);
          uVar2 = 5;
        }
      }
      if (uVar2 != 5) break;
      uVar2 = 6;
      in_w9 = 1;
      if (uVar4 != 1) {
        do {
          uVar2 = (int)uVar4 >> 1;
          if ((uVar4 & 1) != 0) {
            uVar2 = uVar4 * 3 + 1;
          }
          unaff_x25 = (ulong)((int)unaff_x25 + 1);
          uVar4 = uVar2;
        } while (uVar2 != 1);
        uVar2 = 6;
        in_w9 = 1;
      }
    }
  } while (uVar2 != 6);
  return unaff_x25;
}


===== FUNCTION _j_m3tuz7o1 @ 0x100002f18 size=952 =====
CFG blocks=24 edges=39

ulong _j_m3tuz7o1(uint param_1)

{
  ulong in_x9;
  uint uVar1;
  ulong uVar2;
  ulong unaff_x25;
  
  uVar1 = 0;
  do {
    while( true ) {
      while( true ) {
        while (uVar2 = in_x9, in_x9 = uVar2, uVar1 < 3) {
          if (uVar1 == 0) {
            unaff_x25 = 0;
            uVar1 = 1;
            in_x9 = (ulong)param_1;
            if (_j_m3tuz7o1_j_jhb16brr + _j_m3tuz7o1_j_jhb16brr * _j_m3tuz7o1_j_jhb16brr < 0) {
              _j_dc_83_j_rb = _j_enc_83 ^ 0xde;
              DAT_10000c349 = DAT_100003f85 ^ 0xde;
              DAT_10000c34a = DAT_100003f86 ^ 0xde;
              DAT_10000c34b = DAT_100003f87 ^ 0xde;
              DAT_10000c34c = DAT_100003f88 ^ 0xde;
              DAT_10000c34d = 0;
              _puts((char *)&_j_dc_83_j_rb);
              unaff_x25 = 0;
              uVar1 = 1;
              in_x9 = (ulong)param_1;
            }
          }
          else if (uVar1 == 1) {
            uVar1 = 2;
            if (_j_m3tuz7o1_j_qwk265v2 + _j_m3tuz7o1_j_qwk265v2 * _j_m3tuz7o1_j_qwk265v2 < 0) {
              _j_dc_85_j_rb = _j_enc_85 ^ 0xbf;
              DAT_10000c34f = DAT_100003f8a ^ 0xbf;
              DAT_10000c350 = DAT_100003f8b ^ 0xbf;
              DAT_10000c351 = DAT_100003f8c ^ 0xbf;
              DAT_10000c352 = DAT_100003f8d ^ 0xbf;
              DAT_10000c353 = 0;
              _puts((char *)&_j_dc_85_j_rb);
              uVar1 = 2;
            }
          }
          else if (uVar1 == 2) {
            uVar1 = 3;
            if (_j_m3tuz7o1_j_l17cumr5 + _j_m3tuz7o1_j_l17cumr5 * _j_m3tuz7o1_j_l17cumr5 < 0) {
              _j_dc_87_j_rb = _j_enc_87 ^ 0x9a;
              DAT_10000c355 = DAT_100003f8f ^ 0x9a;
              DAT_10000c356 = DAT_100003f90 ^ 0x9a;
              DAT_10000c357 = DAT_100003f91 ^ 0x9a;
              DAT_10000c358 = DAT_100003f92 ^ 0x9a;
              DAT_10000c359 = 0;
              _puts((char *)&_j_dc_87_j_rb);
              uVar1 = 3;
            }
          }
        }
        if (4 < uVar1) break;
        if (uVar1 == 3) {
          uVar1 = 4;
          in_x9 = 0;
          if (0 < (int)uVar2) {
            do {
              uVar1 = (uint)uVar2;
              unaff_x25 = (ulong)(uVar1 + (int)((uVar2 & 0xffffffff) / 10) * -10 + (int)unaff_x25);
              uVar2 = (uVar2 & 0xffffffff) / 10;
            } while (9 < uVar1);
            uVar1 = 4;
            in_x9 = 0;
          }
        }
        else if (uVar1 == 4) {
          uVar1 = 5;
          if ((_j_m3tuz7o1_j_vl90z625 * _j_m3tuz7o1_j_vl90z625 & 0x8000000000000003U) == 3) {
            _j_dc_89_j_rb = _j_enc_89 ^ 0x42;
            DAT_10000c35b = DAT_100003f94 ^ 0x42;
            DAT_10000c35c = DAT_100003f95 ^ 0x42;
            DAT_10000c35d = DAT_100003f96 ^ 0x42;
            DAT_10000c35e = DAT_100003f97 ^ 0x42;
            DAT_10000c35f = 0;
            _puts((char *)&_j_dc_89_j_rb);
            uVar1 = 5;
          }
        }
      }
      if (uVar1 != 5) break;
      uVar1 = 6;
      if (((uint)_j_m3tuz7o1_j_yackb9o9 * ~(uint)_j_m3tuz7o1_j_yackb9o9 & 1) != 0) {
        _j_dc_91_j_rb = _j_enc_91 ^ 100;
        DAT_10000c361 = DAT_100003f99 ^ 100;
        DAT_10000c362 = DAT_100003f9a ^ 100;
        DAT_10000c363 = DAT_100003f9b ^ 100;
        DAT_10000c364 = DAT_100003f9c ^ 100;
        DAT_10000c365 = 0;
        _puts((char *)&_j_dc_91_j_rb);
        uVar1 = 6;
      }
    }
  } while (uVar1 != 6);
  return unaff_x25;
}


===== FUNCTION _j_dwwcl9v0 @ 0x1000032d0 size=308 =====
CFG blocks=14 edges=21

ulong _j_dwwcl9v0(ulong param_1)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  uVar2 = param_1;
  do {
    while( true ) {
      while (iVar1 = (int)param_1, 1 < uVar3) {
        if (uVar3 == 2) {
          uVar3 = 3;
          uVar4 = param_1;
          if (0 < iVar1) {
            do {
              uVar3 = (uint)uVar4;
              uVar2 = (ulong)(uVar3 + (int)((uVar4 & 0xffffffff) / 10) * -10 + (int)uVar2 * 10);
              uVar4 = (uVar4 & 0xffffffff) / 10;
            } while (9 < uVar3);
            uVar3 = 3;
          }
        }
        else if (uVar3 == 3) {
          return uVar2;
        }
      }
      if (uVar3 == 0) break;
      if (uVar3 == 1) {
        uVar2 = 0;
        uVar3 = 2;
        if (_j_dwwcl9v0_j_051xehyu + _j_dwwcl9v0_j_051xehyu * _j_dwwcl9v0_j_051xehyu < 0) {
          _j_dc_93_j_rb = _j_enc_93 ^ 0x18;
          DAT_10000c37c = DAT_100003fb2 ^ 0x18;
          DAT_10000c37d = DAT_100003fb3 ^ 0x18;
          DAT_10000c37e = DAT_100003fb4 ^ 0x18;
          DAT_10000c37f = DAT_100003fb5 ^ 0x18;
          DAT_10000c380 = 0;
          _puts((char *)&_j_dc_93_j_rb);
          uVar2 = 0;
          uVar3 = 2;
        }
      }
    }
    uVar3 = 1;
  } while (-1 < iVar1);
  iVar1 = _j_dwwcl9v0(-iVar1);
  return (ulong)(uint)-iVar1;
}


===== FUNCTION _j_u1jd8trj @ 0x100003404 size=1020 =====
CFG blocks=32 edges=51

ulong _j_u1jd8trj(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  uint uVar6;
  uint uVar7;
  int in_w11;
  int iVar8;
  ulong unaff_x25;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined1 auVar14 [16];
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  
  uVar6 = 0;
LAB_100003468:
  do {
    while( true ) {
      while( true ) {
        while (iVar8 = in_w11, in_w11 = iVar8, uVar6 < 3) {
          if (uVar6 == 0) {
            uVar6 = 1;
            if (_j_u1jd8trj_j_lhwxqj9r + _j_u1jd8trj_j_lhwxqj9r * _j_u1jd8trj_j_lhwxqj9r < 0) {
              _j_dc_97_j_rb = _j_enc_97 ^ 0xf3;
              DAT_10000c38e = DAT_100003fc2 ^ 0xf3;
              DAT_10000c38f = DAT_100003fc3 ^ 0xf3;
              DAT_10000c390 = DAT_100003fc4 ^ 0xf3;
              DAT_10000c391 = DAT_100003fc5 ^ 0xf3;
              DAT_10000c392 = 0;
              _puts((char *)&_j_dc_97_j_rb);
              uVar6 = 1;
            }
          }
          else if (uVar6 == 1) {
            unaff_x25 = 1;
            uVar6 = 2;
            if (_j_u1jd8trj_j_x7von3v7 + _j_u1jd8trj_j_x7von3v7 * _j_u1jd8trj_j_x7von3v7 < 0) {
              _j_dc_99_j_rb = _j_enc_99 ^ 0xa0;
              DAT_10000c394 = DAT_100003fc7 ^ 0xa0;
              DAT_10000c395 = DAT_100003fc8 ^ 0xa0;
              DAT_10000c396 = DAT_100003fc9 ^ 0xa0;
              DAT_10000c397 = DAT_100003fca ^ 0xa0;
              DAT_10000c398 = 0;
              _puts((char *)&_j_dc_99_j_rb);
              uVar6 = 2;
            }
          }
          else if ((uVar6 == 2) &&
                  (uVar6 = 3,
                  _j_u1jd8trj_j_hoslr0at + _j_u1jd8trj_j_hoslr0at * _j_u1jd8trj_j_hoslr0at < 0)) {
            _j_dc_101_j_rb = _j_enc_101 ^ 0x1d;
            DAT_10000c39a = DAT_100003fcc ^ 0x1d;
            DAT_10000c39b = DAT_100003fcd ^ 0x1d;
            DAT_10000c39c = DAT_100003fce ^ 0x1d;
            DAT_10000c39d = DAT_100003fcf ^ 0x1d;
            DAT_10000c39e = 0;
            _puts((char *)&_j_dc_101_j_rb);
            uVar6 = 3;
          }
        }
        if (uVar6 != 3) break;
        uVar6 = 4;
        in_w11 = 0;
        if (_j_u1jd8trj_j_mhn3wxje + _j_u1jd8trj_j_mhn3wxje * _j_u1jd8trj_j_mhn3wxje < 0) {
          _j_dc_103_j_rb = _j_enc_103 ^ 0xa5;
          DAT_10000c3a0 = DAT_100003fd1 ^ 0xa5;
          DAT_10000c3a1 = DAT_100003fd2 ^ 0xa5;
          DAT_10000c3a2 = DAT_100003fd3 ^ 0xa5;
          DAT_10000c3a3 = DAT_100003fd4 ^ 0xa5;
          DAT_10000c3a4 = 0;
          _puts((char *)&_j_dc_103_j_rb);
          uVar6 = 4;
          in_w11 = 0;
        }
      }
      if (uVar6 == 4) break;
      if (uVar6 == 5) {
        return unaff_x25;
      }
    }
    uVar6 = 5;
    uVar2 = param_2 - iVar8;
  } while (uVar2 == 0 || param_2 < iVar8);
  if (3 < uVar2) {
    if (0xf < uVar2) goto LAB_100003708;
    uVar7 = 0;
    goto LAB_100003774;
  }
  goto LAB_1000037c0;
LAB_100003708:
  uVar7 = uVar2 & 0xfffffff0;
  iVar9 = 1;
  iVar10 = 1;
  iVar11 = 1;
  iVar12 = 1;
  iVar13 = (int)unaff_x25;
  iVar15 = 1;
  iVar16 = 1;
  iVar17 = 1;
  iVar18 = 1;
  iVar19 = 1;
  iVar20 = 1;
  iVar21 = 1;
  iVar22 = 1;
  iVar23 = 1;
  iVar24 = 1;
  iVar25 = 1;
  uVar6 = uVar7;
  do {
    iVar13 = iVar13 * param_1;
    iVar15 = iVar15 * param_1;
    iVar16 = iVar16 * param_1;
    iVar17 = iVar17 * param_1;
    iVar9 = iVar9 * param_1;
    iVar10 = iVar10 * param_1;
    iVar11 = iVar11 * param_1;
    iVar12 = iVar12 * param_1;
    iVar18 = iVar18 * param_1;
    iVar19 = iVar19 * param_1;
    iVar20 = iVar20 * param_1;
    iVar21 = iVar21 * param_1;
    iVar22 = iVar22 * param_1;
    iVar23 = iVar23 * param_1;
    iVar24 = iVar24 * param_1;
    iVar25 = iVar25 * param_1;
    uVar6 = uVar6 - 0x10;
  } while (uVar6 != 0);
  iVar13 = iVar22 * iVar18 * iVar9 * iVar13;
  iVar9 = iVar23 * iVar19 * iVar10 * iVar15;
  iVar10 = iVar24 * iVar20 * iVar11 * iVar16;
  iVar11 = iVar25 * iVar21 * iVar12 * iVar17;
  auVar14._4_4_ = iVar9;
  auVar14._0_4_ = iVar13;
  auVar14._8_4_ = iVar10;
  auVar14._12_4_ = iVar11;
  auVar5._4_4_ = iVar9;
  auVar5._0_4_ = iVar13;
  auVar5._8_4_ = iVar10;
  auVar5._12_4_ = iVar11;
  auVar14 = NEON_ext(auVar14,auVar5,8,1);
  unaff_x25 = (ulong)(uint)(iVar13 * auVar14._0_4_ * iVar9 * auVar14._4_4_);
  uVar6 = 5;
  in_w11 = param_2;
  if (uVar2 != uVar7) {
    if ((uVar2 & 0xc) == 0) {
      iVar8 = iVar8 + uVar7;
    }
    else {
LAB_100003774:
      uVar1 = uVar2 & 0xfffffffc;
      iVar8 = iVar8 + uVar1;
      iVar10 = 1;
      iVar11 = 1;
      iVar12 = 1;
      iVar9 = (int)unaff_x25;
      iVar13 = uVar7 - uVar1;
      do {
        iVar9 = iVar9 * param_1;
        iVar10 = iVar10 * param_1;
        iVar11 = iVar11 * param_1;
        iVar12 = iVar12 * param_1;
        iVar13 = iVar13 + 4;
      } while (iVar13 != 0);
      auVar3._4_4_ = iVar10;
      auVar3._0_4_ = iVar9;
      auVar3._8_4_ = iVar11;
      auVar3._12_4_ = iVar12;
      auVar4._4_4_ = iVar10;
      auVar4._0_4_ = iVar9;
      auVar4._8_4_ = iVar11;
      auVar4._12_4_ = iVar12;
      auVar14 = NEON_ext(auVar3,auVar4,8,1);
      unaff_x25 = (ulong)(uint)(iVar9 * auVar14._0_4_ * iVar10 * auVar14._4_4_);
      uVar6 = 5;
      in_w11 = param_2;
      if (uVar2 == uVar1) goto LAB_100003468;
    }
LAB_1000037c0:
    iVar8 = param_2 - iVar8;
    do {
      unaff_x25 = (ulong)(uint)((int)unaff_x25 * param_1);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar6 = 5;
    in_w11 = param_2;
  }
  goto LAB_100003468;
}


===== FUNCTION _j_w6mesi0m @ 0x100003800 size=788 =====
CFG blocks=23 edges=34

int _j_w6mesi0m(int param_1,int param_2,int param_3)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar2 = 0;
  do {
    while( true ) {
      while( true ) {
        while (3 < uVar2) {
          if (uVar2 < 6) {
            if (uVar2 == 4) {
              uVar2 = 5;
              if (param_1 <= param_2 && param_3 <= param_2) {
                return param_2;
              }
            }
            else {
              uVar2 = 6;
              if (_j_w6mesi0m_j_2166sej3 + _j_w6mesi0m_j_2166sej3 * _j_w6mesi0m_j_2166sej3 < 0) {
                _j_dc_111_j_rb = _j_enc_111 ^ 0xe9;
                DAT_10000c3d1 = DAT_100003ffd ^ 0xe9;
                DAT_10000c3d2 = DAT_100003ffe ^ 0xe9;
                DAT_10000c3d3 = DAT_100003fff ^ 0xe9;
                DAT_10000c3d4 = DAT_100004000 ^ 0xe9;
                DAT_10000c3d5 = 0;
                _puts((char *)&_j_dc_111_j_rb);
                uVar2 = 6;
              }
            }
          }
          else if (uVar2 != 7) {
            return param_3;
          }
        }
        if (uVar2 < 2) break;
        if (uVar2 == 2) {
          uVar2 = 3;
          if (_j_w6mesi0m_j_y3ncgfwg + _j_w6mesi0m_j_y3ncgfwg * _j_w6mesi0m_j_y3ncgfwg < 0) {
            _j_dc_107_j_rb = _j_enc_107 ^ 0xf8;
            DAT_10000c3c5 = DAT_100003ff3 ^ 0xf8;
            DAT_10000c3c6 = DAT_100003ff4 ^ 0xf8;
            DAT_10000c3c7 = DAT_100003ff5 ^ 0xf8;
            DAT_10000c3c8 = DAT_100003ff6 ^ 0xf8;
            DAT_10000c3c9 = 0;
            _puts((char *)&_j_dc_107_j_rb);
            uVar2 = 3;
          }
        }
        else {
          uVar3 = _j_w6mesi0m_j_7gvi8asa * _j_w6mesi0m_j_7gvi8asa & 3;
          uVar1 = -(_j_w6mesi0m_j_7gvi8asa * _j_w6mesi0m_j_7gvi8asa);
          if (-1 < (long)uVar1) {
            uVar3 = -(uVar1 & 3);
          }
          uVar2 = 4;
          if (1 < (long)uVar3) {
            _j_dc_109_j_rb = _j_enc_109 ^ 0x3a;
            DAT_10000c3cb = DAT_100003ff8 ^ 0x3a;
            DAT_10000c3cc = DAT_100003ff9 ^ 0x3a;
            DAT_10000c3cd = DAT_100003ffa ^ 0x3a;
            DAT_10000c3ce = DAT_100003ffb ^ 0x3a;
            DAT_10000c3cf = 0;
            _puts((char *)&_j_dc_109_j_rb);
            uVar2 = 4;
          }
        }
      }
      if (uVar2 == 0) break;
      uVar2 = 2;
      if (_j_w6mesi0m_j_9q46v2mt + _j_w6mesi0m_j_9q46v2mt * _j_w6mesi0m_j_9q46v2mt < 0) {
        _j_dc_105_j_rb = _j_enc_105 ^ 0xc1;
        DAT_10000c3bf = DAT_100003fee ^ 0xc1;
        DAT_10000c3c0 = DAT_100003fef ^ 0xc1;
        DAT_10000c3c1 = DAT_100003ff0 ^ 0xc1;
        DAT_10000c3c2 = DAT_100003ff1 ^ 0xc1;
        DAT_10000c3c3 = 0;
        _puts((char *)&_j_dc_105_j_rb);
        uVar2 = 2;
      }
    }
    uVar2 = 1;
  } while (param_1 < param_2 || param_1 < param_3);
  return param_1;
}


===== FUNCTION _j_dk9e63to @ 0x100003b14 size=696 =====
CFG blocks=18 edges=28

bool _j_dk9e63to(int param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  do {
    while( true ) {
      while( true ) {
        while (uVar3 < 2) {
          if (uVar3 == 0) {
            uVar3 = 1;
            if (_j_dk9e63to_j_43e124er + _j_dk9e63to_j_43e124er * _j_dk9e63to_j_43e124er < 0) {
              _j_dc_125_j_rb = _j_enc_125 ^ 0xf6;
              DAT_10000c3ef = DAT_100004019 ^ 0xf6;
              DAT_10000c3f0 = DAT_10000401a ^ 0xf6;
              DAT_10000c3f1 = DAT_10000401b ^ 0xf6;
              DAT_10000c3f2 = DAT_10000401c ^ 0xf6;
              DAT_10000c3f3 = 0;
              _puts((char *)&_j_dc_125_j_rb);
              uVar3 = 1;
            }
          }
          else if ((uVar3 == 1) &&
                  (uVar3 = 2,
                  _j_dk9e63to_j_ym23c5kb + _j_dk9e63to_j_ym23c5kb * _j_dk9e63to_j_ym23c5kb < 0)) {
            _j_dc_127_j_rb = _j_enc_127 ^ 0xc3;
            DAT_10000c3f5 = DAT_10000401e ^ 0xc3;
            DAT_10000c3f6 = DAT_10000401f ^ 0xc3;
            DAT_10000c3f7 = DAT_100004020 ^ 0xc3;
            DAT_10000c3f8 = DAT_100004021 ^ 0xc3;
            DAT_10000c3f9 = 0;
            _puts((char *)&_j_dc_127_j_rb);
            uVar3 = 2;
          }
        }
        if (uVar3 != 2) break;
        uVar4 = _j_dk9e63to_j_awdsb5zl * _j_dk9e63to_j_awdsb5zl & 3;
        uVar1 = -(_j_dk9e63to_j_awdsb5zl * _j_dk9e63to_j_awdsb5zl);
        if (-1 < (long)uVar1) {
          uVar4 = -(uVar1 & 3);
        }
        uVar3 = 3;
        if (1 < (long)uVar4) {
          _j_dc_129_j_rb = _j_enc_129 ^ 0x3f;
          DAT_10000c3fb = DAT_100004023 ^ 0x3f;
          DAT_10000c3fc = DAT_100004024 ^ 0x3f;
          DAT_10000c3fd = DAT_100004025 ^ 0x3f;
          DAT_10000c3fe = DAT_100004026 ^ 0x3f;
          DAT_10000c3ff = 0;
          _puts((char *)&_j_dc_129_j_rb);
          uVar3 = 3;
        }
      }
      if (uVar3 != 3) break;
      uVar3 = 4;
      if (((uint)_j_dk9e63to_j_8iipg4vh * ~(uint)_j_dk9e63to_j_8iipg4vh & 1) != 0) {
        _j_dc_131_j_rb = _j_enc_131 ^ 0xf8;
        DAT_10000c401 = DAT_100004028 ^ 0xf8;
        DAT_10000c402 = DAT_100004029 ^ 0xf8;
        DAT_10000c403 = DAT_10000402a ^ 0xf8;
        DAT_10000c404 = DAT_10000402b ^ 0xf8;
        DAT_10000c405 = 0;
        _puts((char *)&_j_dc_131_j_rb);
        uVar3 = 4;
      }
    }
  } while (uVar3 != 4);
  iVar2 = _j_dwwcl9v0(param_1);
  return param_1 == iVar2;
}


===== FUNCTION _printf @ 0x100003dcc size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100008000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100003dd8 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100008008)((int)param_1);
  return iVar1;
}


