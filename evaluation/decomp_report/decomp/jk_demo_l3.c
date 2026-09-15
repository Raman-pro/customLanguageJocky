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
      iVar8 = (int)_UNK_100001098;
      iVar9 = (int)((ulong)_UNK_100001098 >> 0x20);
      iVar6 = (int)_DAT_100001090;
      iVar7 = (int)((ulong)_DAT_100001090 >> 0x20);
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
    iVar11 = uVar5 + (int)PTR___mh_execute_header_1000010a0;
    iVar12 = uVar5 + (int)((ulong)PTR___mh_execute_header_1000010a0 >> 0x20);
    iVar13 = uVar5 + (int)_UNK_1000010a8;
    iVar14 = uVar5 + (int)((ulong)_UNK_1000010a8 >> 0x20);
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


===== FUNCTION entry @ 0x1000007a8 size=2232 =====
CFG blocks=70 edges=113

undefined8 entry(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  uint unaff_w24;
  int local_6c;
  
  iVar6 = 0;
  do {
    do {
      while( true ) {
        while( true ) {
          while (iVar6 < 3) {
            if (iVar6 < 1) {
              if (iVar6 == 0) {
                lVar8 = 0;
                do {
                  (&_j_dc_38_j_rb)[lVar8] = (&_j_enc_38)[lVar8] ^ 0xcf;
                  lVar8 = lVar8 + 1;
                } while (lVar8 != 0x1c);
                uVar7 = 0;
                DAT_10000806c = 0;
                do {
                  while( true ) {
                    while (uVar7 < 4) {
                      if (uVar7 < 2) {
                        if (uVar7 == 0) {
                          uVar7 = 1;
                          if (_j_t2hghb9f_j_2rhh3gut +
                              _j_t2hghb9f_j_2rhh3gut * _j_t2hghb9f_j_2rhh3gut < 0) {
                            _j_dc_29_j_rb = _j_enc_29 ^ 0x65;
                            DAT_10000806e = DAT_1000010cd ^ 0x65;
                            DAT_10000806f = DAT_1000010ce ^ 0x65;
                            DAT_100008070 = DAT_1000010cf ^ 0x65;
                            DAT_100008071 = DAT_1000010d0 ^ 0x65;
                            DAT_100008072 = 0;
                            _puts((char *)&_j_dc_29_j_rb);
                            uVar7 = 1;
                          }
                        }
                        else {
                          uVar7 = 2;
                          if (_j_t2hghb9f_j_e63tox7h +
                              _j_t2hghb9f_j_e63tox7h * _j_t2hghb9f_j_e63tox7h < 0) {
                            _j_dc_31_j_rb = _j_enc_31 ^ 0xee;
                            DAT_100008074 = DAT_1000010d2 ^ 0xee;
                            DAT_100008075 = DAT_1000010d3 ^ 0xee;
                            DAT_100008076 = DAT_1000010d4 ^ 0xee;
                            DAT_100008077 = DAT_1000010d5 ^ 0xee;
                            DAT_100008078 = 0;
                            _puts((char *)&_j_dc_31_j_rb);
                            uVar7 = 2;
                          }
                        }
                      }
                      else if (uVar7 == 2) {
                        uVar7 = 3;
                        if ((_j_t2hghb9f_j_esi0ml05 +
                             _j_t2hghb9f_j_esi0ml05 * _j_t2hghb9f_j_esi0ml05 & 0x8000000000000001U)
                            == 1) {
                          _j_dc_33_j_rb = _j_enc_33 ^ 0xc1;
                          DAT_10000807a = DAT_1000010d7 ^ 0xc1;
                          DAT_10000807b = DAT_1000010d8 ^ 0xc1;
                          DAT_10000807c = DAT_1000010d9 ^ 0xc1;
                          DAT_10000807d = DAT_1000010da ^ 0xc1;
                          DAT_10000807e = 0;
                          _puts((char *)&_j_dc_33_j_rb);
                          uVar7 = 3;
                        }
                      }
                      else {
                        uVar7 = 4;
                        if (_j_t2hghb9f_j_wz7tww6m + _j_t2hghb9f_j_wz7tww6m * _j_t2hghb9f_j_wz7tww6m
                            < 0) {
                          _j_dc_35_j_rb = _j_enc_35 ^ 0x84;
                          DAT_100008080 = DAT_1000010dc ^ 0x84;
                          DAT_100008081 = DAT_1000010dd ^ 0x84;
                          DAT_100008082 = DAT_1000010de ^ 0x84;
                          DAT_100008083 = DAT_1000010df ^ 0x84;
                          DAT_100008084 = 0;
                          _puts((char *)&_j_dc_35_j_rb);
                          uVar7 = 4;
                        }
                      }
                    }
                    if (5 < uVar7) break;
                    if (uVar7 == 4) {
                      uVar7 = 5;
                    }
                    else {
                      uVar7 = 6;
                      if (_j_t2hghb9f_j_468tmzoa + _j_t2hghb9f_j_468tmzoa * _j_t2hghb9f_j_468tmzoa <
                          0) {
                        _j_dc_37_j_rb = _j_enc_37 ^ 0xc4;
                        DAT_100008086 = DAT_1000010e1 ^ 0xc4;
                        DAT_100008087 = DAT_1000010e2 ^ 0xc4;
                        DAT_100008088 = DAT_1000010e3 ^ 0xc4;
                        DAT_100008089 = DAT_1000010e4 ^ 0xc4;
                        DAT_10000808a = 0;
                        _puts((char *)&_j_dc_37_j_rb);
                        uVar7 = 6;
                      }
                    }
                  }
                } while (uVar7 == 7);
                iVar6 = 1;
                if (_j_tr_w8kitx_j_7m5fgot7 + _j_tr_w8kitx_j_7m5fgot7 * _j_tr_w8kitx_j_7m5fgot7 < 0)
                {
                  _j_dc_40_j_rb = _j_enc_40 ^ 0xce;
                  DAT_10000808c = DAT_1000010e6 ^ 0xce;
                  DAT_10000808d = DAT_1000010e7 ^ 0xce;
                  DAT_10000808e = DAT_1000010e8 ^ 0xce;
                  DAT_10000808f = DAT_1000010e9 ^ 0xce;
                  DAT_100008090 = 0;
                  _puts((char *)&_j_dc_40_j_rb);
                  iVar6 = 1;
                }
              }
              else if (iVar6 == -1) {
                return 0;
              }
            }
            else if (iVar6 == 1) {
              iVar6 = 2;
              if (_j_tr_w8kitx_j_kiietxma + _j_tr_w8kitx_j_kiietxma * _j_tr_w8kitx_j_kiietxma < 0) {
                _j_dc_42_j_rb = _j_enc_42 ^ 0xf1;
                DAT_100008092 = DAT_1000010eb ^ 0xf1;
                DAT_100008093 = DAT_1000010ec ^ 0xf1;
                DAT_100008094 = DAT_1000010ed ^ 0xf1;
                DAT_100008095 = DAT_1000010ee ^ 0xf1;
                DAT_100008096 = 0;
                _puts((char *)&_j_dc_42_j_rb);
                iVar6 = 2;
              }
            }
            else if (iVar6 == 2) {
              _puts(&_j_dc_38_j_rb);
              _printf("%d\n");
              _j_dc_43_j_rb = _j_enc_43 ^ 0x2c;
              DAT_100008098 = DAT_1000010f0 ^ 0x2c;
              DAT_100008099 = DAT_1000010f1 ^ 0x2c;
              DAT_10000809a = DAT_1000010f2 ^ 0x2c;
              DAT_10000809b = DAT_1000010f3 ^ 0x2c;
              DAT_10000809c = 0;
              uVar7 = 0;
              while( true ) {
                while (uVar7 < 2) {
                  bVar1 = uVar7 != 0;
                  uVar7 = 1;
                  if ((bVar1) &&
                     (uVar7 = 2,
                     (_j_4f7g6fui_j_vogp4vxx + _j_4f7g6fui_j_vogp4vxx * _j_4f7g6fui_j_vogp4vxx &
                     0x8000000000000001U) == 1)) {
                    _j_dc_25_j_rb = _j_enc_25 ^ 0xaf;
                    DAT_10000809e = DAT_1000010f5 ^ 0xaf;
                    DAT_10000809f = DAT_1000010f6 ^ 0xaf;
                    DAT_1000080a0 = DAT_1000010f7 ^ 0xaf;
                    DAT_1000080a1 = DAT_1000010f8 ^ 0xaf;
                    DAT_1000080a2 = 0;
                    _puts((char *)&_j_dc_25_j_rb);
                    uVar7 = 2;
                  }
                }
                if (uVar7 != 2) break;
                uVar7 = 3;
              }
              sVar5 = _strlen((char *)&_j_dc_43_j_rb);
              if ((int)sVar5 == 5) {
                _j_dc_44_j_rb = _j_enc_44 ^ 0x36;
                pcVar4 = (char *)&_j_dc_44_j_rb;
                DAT_1000080a4 = DAT_1000010fa ^ 0x36;
                DAT_1000080a5 = DAT_1000010fb ^ 0x36;
                DAT_1000080a6 = DAT_1000010fc ^ 0x36;
                DAT_1000080a7 = 0;
              }
              else {
                _j_dc_47_j_rb = _j_enc_47 ^ 0x5c;
                pcVar4 = (char *)&_j_dc_47_j_rb;
                DAT_1000080a9 = DAT_1000010fe ^ 0x5c;
                DAT_1000080aa = DAT_1000010ff ^ 0x5c;
                DAT_1000080ab = DAT_100001100 ^ 0x5c;
                DAT_1000080ac = DAT_100001101 ^ 0x5c;
                DAT_1000080ad = 0;
              }
              _puts(pcVar4);
              iVar6 = 3;
            }
          }
          if (iVar6 != 3) break;
          iVar6 = 4;
          if (_j_tr_w8kitx_j_qb8n9rkr + _j_tr_w8kitx_j_qb8n9rkr * _j_tr_w8kitx_j_qb8n9rkr < 0) {
            _j_dc_49_j_rb = _j_enc_49 ^ 100;
            DAT_1000080af = DAT_100001103 ^ 100;
            DAT_1000080b0 = DAT_100001104 ^ 100;
            DAT_1000080b1 = DAT_100001105 ^ 100;
            DAT_1000080b2 = DAT_100001106 ^ 100;
            DAT_1000080b3 = 0;
            _puts((char *)&_j_dc_49_j_rb);
            iVar6 = 4;
          }
        }
        if (iVar6 != 4) break;
        local_6c = 0;
        unaff_w24 = 2;
        iVar6 = 5;
        if (_j_tr_w8kitx_j_c1wchsa4 + _j_tr_w8kitx_j_c1wchsa4 * _j_tr_w8kitx_j_c1wchsa4 < 0) {
          _j_dc_51_j_rb = _j_enc_51 ^ 0x25;
          DAT_1000080b5 = DAT_100001108 ^ 0x25;
          DAT_1000080b6 = DAT_100001109 ^ 0x25;
          DAT_1000080b7 = DAT_10000110a ^ 0x25;
          DAT_1000080b8 = DAT_10000110b ^ 0x25;
          DAT_1000080b9 = 0;
          _puts((char *)&_j_dc_51_j_rb);
          local_6c = 0;
          unaff_w24 = 2;
          iVar6 = 5;
        }
      }
    } while ((iVar6 != 5) || (iVar6 = -1, 2 < local_6c));
    do {
      uVar7 = 0;
      do {
        while( true ) {
          while (uVar7 < 2) {
            if (uVar7 == 0) {
              uVar7 = 1;
              if ((int)unaff_w24 < 2) goto LAB_1000009b8;
            }
            else if ((uVar7 == 1) &&
                    (uVar7 = 2,
                    (_j_4f7g6fui_j_vogp4vxx + _j_4f7g6fui_j_vogp4vxx * _j_4f7g6fui_j_vogp4vxx &
                    0x8000000000000001U) == 1)) {
              _j_dc_25_j_rb = _j_enc_25 ^ 0xaf;
              DAT_10000809e = DAT_1000010f5 ^ 0xaf;
              DAT_10000809f = DAT_1000010f6 ^ 0xaf;
              DAT_1000080a0 = DAT_1000010f7 ^ 0xaf;
              DAT_1000080a1 = DAT_1000010f8 ^ 0xaf;
              DAT_1000080a2 = 0;
              _puts((char *)&_j_dc_25_j_rb);
              uVar7 = 2;
            }
          }
          if (uVar7 != 2) break;
          uVar7 = 3;
          if (3 < (int)unaff_w24) {
            do {
              uVar2 = uVar7 - 1;
              uVar3 = 0;
              if (uVar2 != 0) {
                uVar3 = unaff_w24 / uVar2;
              }
              if (unaff_w24 == uVar3 * uVar2) goto LAB_1000009b8;
              iVar6 = uVar7 * uVar7;
              uVar7 = uVar7 + 1;
            } while (iVar6 <= (int)unaff_w24);
            uVar7 = 3;
          }
        }
      } while (uVar7 != 3);
      _printf("%d\n");
      local_6c = local_6c + 1;
LAB_1000009b8:
      unaff_w24 = unaff_w24 + 1;
    } while (local_6c < 3);
    iVar6 = -1;
  } while( true );
}


===== FUNCTION _printf @ 0x100001060 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x10000106c size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


===== FUNCTION _strlen @ 0x100001078 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100001080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004010)();
  return sVar1;
}


