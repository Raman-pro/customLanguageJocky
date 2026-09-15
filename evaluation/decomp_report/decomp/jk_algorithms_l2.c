===== FUNCTION entry @ 0x100000598 size=5932 =====
CFG blocks=1 edges=0

void entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x00010000061c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((ulong)USHORT_100003bfe * 4 + 0x100000620))();
  return;
}


===== FUNCTION _j_4f7g6fui @ 0x100001cc4 size=816 =====
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
              _j_dc_25_j_rb = _j_enc_25 ^ 0x8f;
              DAT_1000081fb = DAT_100003c49 ^ 0x8f;
              DAT_1000081fc = DAT_100003c4a ^ 0x8f;
              DAT_1000081fd = DAT_100003c4b ^ 0x8f;
              DAT_1000081fe = DAT_100003c4c ^ 0x8f;
              DAT_1000081ff = 0;
              _puts((char *)&_j_dc_25_j_rb);
              unaff_x24 = 0;
              iVar2 = 2;
            }
          }
          else if ((iVar2 == 2) &&
                  (iVar2 = 3,
                  _j_4f7g6fui_j_7m5fgot7 + _j_4f7g6fui_j_7m5fgot7 * _j_4f7g6fui_j_7m5fgot7 < 0)) {
            _j_dc_27_j_rb = _j_enc_27 ^ 0xf5;
            DAT_100008201 = DAT_100003c4e ^ 0xf5;
            DAT_100008202 = DAT_100003c4f ^ 0xf5;
            DAT_100008203 = DAT_100003c50 ^ 0xf5;
            DAT_100008204 = DAT_100003c51 ^ 0xf5;
            DAT_100008205 = 0;
            _puts((char *)&_j_dc_27_j_rb);
            iVar2 = 3;
          }
        }
        if (4 < iVar2) break;
        if (iVar2 == 3) {
          iVar2 = 4;
          if (_j_4f7g6fui_j_l9dl9lcd + _j_4f7g6fui_j_l9dl9lcd * _j_4f7g6fui_j_l9dl9lcd < 0) {
            _j_dc_29_j_rb = _j_enc_29 ^ 0x95;
            DAT_100008207 = DAT_100003c53 ^ 0x95;
            DAT_100008208 = DAT_100003c54 ^ 0x95;
            DAT_100008209 = DAT_100003c55 ^ 0x95;
            DAT_10000820a = DAT_100003c56 ^ 0x95;
            DAT_10000820b = 0;
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
        _j_dc_33_j_rb = _j_enc_33 ^ 0xdc;
        DAT_10000820d = DAT_100003c58 ^ 0xdc;
        DAT_10000820e = DAT_100003c59 ^ 0xdc;
        DAT_10000820f = DAT_100003c5a ^ 0xdc;
        DAT_100008210 = DAT_100003c5b ^ 0xdc;
        DAT_100008211 = 0;
        _puts((char *)&_j_dc_33_j_rb);
        iVar2 = -1;
      }
    }
  } while (iVar2 != 5);
  return unaff_x19;
}


===== FUNCTION _j_t2hghb9f @ 0x100001ff4 size=604 =====
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
                _j_dc_35_j_rb = _j_enc_35 ^ 0x6e;
                DAT_100008235 = DAT_100003c7d ^ 0x6e;
                DAT_100008236 = DAT_100003c7e ^ 0x6e;
                DAT_100008237 = DAT_100003c7f ^ 0x6e;
                DAT_100008238 = DAT_100003c80 ^ 0x6e;
                DAT_100008239 = 0;
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
            _j_dc_37_j_rb = _j_enc_37 ^ 0x5c;
            DAT_10000823b = DAT_100003c82 ^ 0x5c;
            DAT_10000823c = DAT_100003c83 ^ 0x5c;
            DAT_10000823d = DAT_100003c84 ^ 0x5c;
            DAT_10000823e = DAT_100003c85 ^ 0x5c;
            DAT_10000823f = 0;
            _puts((char *)&_j_dc_37_j_rb);
            uVar2 = 3;
          }
        }
        if (uVar2 != 3) break;
        uVar2 = 4;
        if (_j_t2hghb9f_j_mbs50pn8 + _j_t2hghb9f_j_mbs50pn8 * _j_t2hghb9f_j_mbs50pn8 < 0) {
          _j_dc_39_j_rb = _j_enc_39 ^ 0x53;
          DAT_100008241 = DAT_100003c87 ^ 0x53;
          DAT_100008242 = DAT_100003c88 ^ 0x53;
          DAT_100008243 = DAT_100003c89 ^ 0x53;
          DAT_100008244 = DAT_100003c8a ^ 0x53;
          DAT_100008245 = 0;
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


===== FUNCTION _j_vls2wrj8 @ 0x100002250 size=848 =====
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
                _j_dc_49_j_rb = _j_enc_49 ^ 0x60;
                DAT_100008275 = DAT_100003cb8 ^ 0x60;
                DAT_100008276 = DAT_100003cb9 ^ 0x60;
                DAT_100008277 = DAT_100003cba ^ 0x60;
                DAT_100008278 = DAT_100003cbb ^ 0x60;
                DAT_100008279 = 0;
                _puts((char *)&_j_dc_49_j_rb);
                uVar2 = 1;
              }
            }
            else {
              uVar2 = 2;
              if (_j_vls2wrj8_j_vyo8ezrt + _j_vls2wrj8_j_vyo8ezrt * _j_vls2wrj8_j_vyo8ezrt < 0) {
                _j_dc_51_j_rb = _j_enc_51 ^ 0x34;
                DAT_10000827b = DAT_100003cbd ^ 0x34;
                DAT_10000827c = DAT_100003cbe ^ 0x34;
                DAT_10000827d = DAT_100003cbf ^ 0x34;
                DAT_10000827e = DAT_100003cc0 ^ 0x34;
                DAT_10000827f = 0;
                _puts((char *)&_j_dc_51_j_rb);
                uVar2 = 2;
              }
            }
          }
          else if (uVar2 == 2) {
            uVar2 = 3;
            if (_j_vls2wrj8_j_7yom7oru + _j_vls2wrj8_j_7yom7oru * _j_vls2wrj8_j_7yom7oru < 0) {
              _j_dc_53_j_rb = _j_enc_53 ^ 0x62;
              DAT_100008281 = DAT_100003cc2 ^ 0x62;
              DAT_100008282 = DAT_100003cc3 ^ 0x62;
              DAT_100008283 = DAT_100003cc4 ^ 0x62;
              DAT_100008284 = DAT_100003cc5 ^ 0x62;
              DAT_100008285 = 0;
              _puts((char *)&_j_dc_53_j_rb);
              uVar2 = 3;
            }
          }
          else {
            uVar2 = 4;
            if (_j_vls2wrj8_j_46wox3cs + _j_vls2wrj8_j_46wox3cs * _j_vls2wrj8_j_46wox3cs < 0) {
              _j_dc_55_j_rb = _j_enc_55 ^ 0x52;
              DAT_100008287 = DAT_100003cc7 ^ 0x52;
              DAT_100008288 = DAT_100003cc8 ^ 0x52;
              DAT_100008289 = DAT_100003cc9 ^ 0x52;
              DAT_10000828a = DAT_100003cca ^ 0x52;
              DAT_10000828b = 0;
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
            _j_dc_57_j_rb = _j_enc_57 ^ 0xf4;
            DAT_10000828d = DAT_100003ccc ^ 0xf4;
            DAT_10000828e = DAT_100003ccd ^ 0xf4;
            DAT_10000828f = DAT_100003cce ^ 0xf4;
            DAT_100008290 = DAT_100003ccf ^ 0xf4;
            DAT_100008291 = 0;
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


===== FUNCTION _j_t8lvogp4 @ 0x1000025a0 size=936 =====
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
                  _j_dc_59_j_rb = _j_enc_59 ^ 0x2b;
                  DAT_1000082a3 = DAT_100003ce0 ^ 0x2b;
                  DAT_1000082a4 = DAT_100003ce1 ^ 0x2b;
                  DAT_1000082a5 = DAT_100003ce2 ^ 0x2b;
                  DAT_1000082a6 = DAT_100003ce3 ^ 0x2b;
                  DAT_1000082a7 = 0;
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
                _j_dc_61_j_rb = _j_enc_61 ^ 0x7e;
                DAT_1000082a9 = DAT_100003ce5 ^ 0x7e;
                DAT_1000082aa = DAT_100003ce6 ^ 0x7e;
                DAT_1000082ab = DAT_100003ce7 ^ 0x7e;
                DAT_1000082ac = DAT_100003ce8 ^ 0x7e;
                DAT_1000082ad = 0;
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
              _j_dc_67_j_rb = _j_enc_67 ^ 0x10;
              DAT_1000082b5 = DAT_100003cef ^ 0x10;
              DAT_1000082b6 = DAT_100003cf0 ^ 0x10;
              DAT_1000082b7 = DAT_100003cf1 ^ 0x10;
              DAT_1000082b8 = DAT_100003cf2 ^ 0x10;
              DAT_1000082b9 = 0;
              _puts((char *)&_j_dc_67_j_rb);
              iVar2 = 8;
            }
          }
          else if (iVar2 == 8) {
            iVar2 = -1;
            if (_j_t8lvogp4_j_2c53ign6 + _j_t8lvogp4_j_2c53ign6 * _j_t8lvogp4_j_2c53ign6 < 0) {
              _j_dc_69_j_rb = _j_enc_69 ^ 0xf4;
              DAT_1000082bb = DAT_100003cf4 ^ 0xf4;
              DAT_1000082bc = DAT_100003cf5 ^ 0xf4;
              DAT_1000082bd = DAT_100003cf6 ^ 0xf4;
              DAT_1000082be = DAT_100003cf7 ^ 0xf4;
              DAT_1000082bf = 0;
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
          _j_dc_63_j_rb = _j_enc_63 ^ 0x61;
          DAT_1000082af = DAT_100003cea ^ 0x61;
          DAT_1000082b0 = DAT_100003ceb ^ 0x61;
          DAT_1000082b1 = DAT_100003cec ^ 0x61;
          DAT_1000082b2 = DAT_100003ced ^ 0x61;
          DAT_1000082b3 = 0;
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


===== FUNCTION _j_vxxehlw0 @ 0x100002948 size=1004 =====
CFG blocks=28 edges=45

/* WARNING: Removing unreachable block (ram,0x000100002cec) */
/* WARNING: Removing unreachable block (ram,0x000100002cf8) */

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
              _j_dc_71_j_rb = _j_enc_71 ^ 0xf4;
              DAT_100008317 = DAT_100003d45 ^ 0xf4;
              DAT_100008318 = DAT_100003d46 ^ 0xf4;
              DAT_100008319 = DAT_100003d47 ^ 0xf4;
              DAT_10000831a = DAT_100003d48 ^ 0xf4;
              DAT_10000831b = 0;
              _puts((char *)&_j_dc_71_j_rb);
              uVar2 = 1;
            }
          }
          else if (uVar2 == 1) {
            uVar2 = 2;
            if (_j_vxxehlw0_j_r5oqef5n + _j_vxxehlw0_j_r5oqef5n * _j_vxxehlw0_j_r5oqef5n < 0) {
              _j_dc_73_j_rb = _j_enc_73 ^ 0x2d;
              DAT_10000831d = DAT_100003d4a ^ 0x2d;
              DAT_10000831e = DAT_100003d4b ^ 0x2d;
              DAT_10000831f = DAT_100003d4c ^ 0x2d;
              DAT_100008320 = DAT_100003d4d ^ 0x2d;
              DAT_100008321 = 0;
              _puts((char *)&_j_dc_73_j_rb);
              uVar2 = 2;
            }
          }
          else if (uVar2 == 2) {
            unaff_x25 = 0;
            uVar2 = 3;
            in_w9 = param_1;
            if (_j_vxxehlw0_j_ey467ne8 + _j_vxxehlw0_j_ey467ne8 * _j_vxxehlw0_j_ey467ne8 < 0) {
              _j_dc_75_j_rb = _j_enc_75 ^ 0x1a;
              DAT_100008323 = DAT_100003d4f ^ 0x1a;
              DAT_100008324 = DAT_100003d50 ^ 0x1a;
              DAT_100008325 = DAT_100003d51 ^ 0x1a;
              DAT_100008326 = DAT_100003d52 ^ 0x1a;
              DAT_100008327 = 0;
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
            _j_dc_77_j_rb = _j_enc_77 ^ 0xd2;
            DAT_100008329 = DAT_100003d54 ^ 0xd2;
            DAT_10000832a = DAT_100003d55 ^ 0xd2;
            DAT_10000832b = DAT_100003d56 ^ 0xd2;
            DAT_10000832c = DAT_100003d57 ^ 0xd2;
            DAT_10000832d = 0;
            _puts((char *)&_j_dc_77_j_rb);
            uVar2 = 4;
          }
        }
        else if ((uVar2 == 4) &&
                (uVar2 = 5,
                _j_vxxehlw0_j_5tphmacs + _j_vxxehlw0_j_5tphmacs * _j_vxxehlw0_j_5tphmacs < 0)) {
          _j_dc_79_j_rb = _j_enc_79 ^ 0xcf;
          DAT_10000832f = DAT_100003d59 ^ 0xcf;
          DAT_100008330 = DAT_100003d5a ^ 0xcf;
          DAT_100008331 = DAT_100003d5b ^ 0xcf;
          DAT_100008332 = DAT_100003d5c ^ 0xcf;
          DAT_100008333 = 0;
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


===== FUNCTION _j_m3tuz7o1 @ 0x100002d34 size=952 =====
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
              _j_dc_83_j_rb = _j_enc_83 ^ 0xf1;
              DAT_100008349 = DAT_100003d71 ^ 0xf1;
              DAT_10000834a = DAT_100003d72 ^ 0xf1;
              DAT_10000834b = DAT_100003d73 ^ 0xf1;
              DAT_10000834c = DAT_100003d74 ^ 0xf1;
              DAT_10000834d = 0;
              _puts((char *)&_j_dc_83_j_rb);
              unaff_x25 = 0;
              uVar1 = 1;
              in_x9 = (ulong)param_1;
            }
          }
          else if (uVar1 == 1) {
            uVar1 = 2;
            if (_j_m3tuz7o1_j_qwk265v2 + _j_m3tuz7o1_j_qwk265v2 * _j_m3tuz7o1_j_qwk265v2 < 0) {
              _j_dc_85_j_rb = _j_enc_85 ^ 0x36;
              DAT_10000834f = DAT_100003d76 ^ 0x36;
              DAT_100008350 = DAT_100003d77 ^ 0x36;
              DAT_100008351 = DAT_100003d78 ^ 0x36;
              DAT_100008352 = DAT_100003d79 ^ 0x36;
              DAT_100008353 = 0;
              _puts((char *)&_j_dc_85_j_rb);
              uVar1 = 2;
            }
          }
          else if (uVar1 == 2) {
            uVar1 = 3;
            if (_j_m3tuz7o1_j_l17cumr5 + _j_m3tuz7o1_j_l17cumr5 * _j_m3tuz7o1_j_l17cumr5 < 0) {
              _j_dc_87_j_rb = _j_enc_87 ^ 0x26;
              DAT_100008355 = DAT_100003d7b ^ 0x26;
              DAT_100008356 = DAT_100003d7c ^ 0x26;
              DAT_100008357 = DAT_100003d7d ^ 0x26;
              DAT_100008358 = DAT_100003d7e ^ 0x26;
              DAT_100008359 = 0;
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
            _j_dc_89_j_rb = _j_enc_89 ^ 0x8c;
            DAT_10000835b = DAT_100003d80 ^ 0x8c;
            DAT_10000835c = DAT_100003d81 ^ 0x8c;
            DAT_10000835d = DAT_100003d82 ^ 0x8c;
            DAT_10000835e = DAT_100003d83 ^ 0x8c;
            DAT_10000835f = 0;
            _puts((char *)&_j_dc_89_j_rb);
            uVar1 = 5;
          }
        }
      }
      if (uVar1 != 5) break;
      uVar1 = 6;
      if (((uint)_j_m3tuz7o1_j_yackb9o9 * ~(uint)_j_m3tuz7o1_j_yackb9o9 & 1) != 0) {
        _j_dc_91_j_rb = _j_enc_91 ^ 0x15;
        DAT_100008361 = DAT_100003d85 ^ 0x15;
        DAT_100008362 = DAT_100003d86 ^ 0x15;
        DAT_100008363 = DAT_100003d87 ^ 0x15;
        DAT_100008364 = DAT_100003d88 ^ 0x15;
        DAT_100008365 = 0;
        _puts((char *)&_j_dc_91_j_rb);
        uVar1 = 6;
      }
    }
  } while (uVar1 != 6);
  return unaff_x25;
}


===== FUNCTION _j_dwwcl9v0 @ 0x1000030ec size=308 =====
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
          _j_dc_93_j_rb = _j_enc_93 ^ 10;
          DAT_10000837c = DAT_100003d9e ^ 10;
          DAT_10000837d = DAT_100003d9f ^ 10;
          DAT_10000837e = DAT_100003da0 ^ 10;
          DAT_10000837f = DAT_100003da1 ^ 10;
          DAT_100008380 = 0;
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


===== FUNCTION _j_u1jd8trj @ 0x100003220 size=1020 =====
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
LAB_100003284:
  do {
    while( true ) {
      while( true ) {
        while (iVar8 = in_w11, in_w11 = iVar8, uVar6 < 3) {
          if (uVar6 == 0) {
            uVar6 = 1;
            if (_j_u1jd8trj_j_lhwxqj9r + _j_u1jd8trj_j_lhwxqj9r * _j_u1jd8trj_j_lhwxqj9r < 0) {
              _j_dc_97_j_rb = _j_enc_97 ^ 0x86;
              DAT_10000838e = DAT_100003dae ^ 0x86;
              DAT_10000838f = DAT_100003daf ^ 0x86;
              DAT_100008390 = DAT_100003db0 ^ 0x86;
              DAT_100008391 = DAT_100003db1 ^ 0x86;
              DAT_100008392 = 0;
              _puts((char *)&_j_dc_97_j_rb);
              uVar6 = 1;
            }
          }
          else if (uVar6 == 1) {
            unaff_x25 = 1;
            uVar6 = 2;
            if (_j_u1jd8trj_j_x7von3v7 + _j_u1jd8trj_j_x7von3v7 * _j_u1jd8trj_j_x7von3v7 < 0) {
              _j_dc_99_j_rb = _j_enc_99 ^ 0xf;
              DAT_100008394 = DAT_100003db3 ^ 0xf;
              DAT_100008395 = DAT_100003db4 ^ 0xf;
              DAT_100008396 = DAT_100003db5 ^ 0xf;
              DAT_100008397 = DAT_100003db6 ^ 0xf;
              DAT_100008398 = 0;
              _puts((char *)&_j_dc_99_j_rb);
              uVar6 = 2;
            }
          }
          else if ((uVar6 == 2) &&
                  (uVar6 = 3,
                  _j_u1jd8trj_j_hoslr0at + _j_u1jd8trj_j_hoslr0at * _j_u1jd8trj_j_hoslr0at < 0)) {
            _j_dc_101_j_rb = _j_enc_101 ^ 0x8d;
            DAT_10000839a = DAT_100003db8 ^ 0x8d;
            DAT_10000839b = DAT_100003db9 ^ 0x8d;
            DAT_10000839c = DAT_100003dba ^ 0x8d;
            DAT_10000839d = DAT_100003dbb ^ 0x8d;
            DAT_10000839e = 0;
            _puts((char *)&_j_dc_101_j_rb);
            uVar6 = 3;
          }
        }
        if (uVar6 != 3) break;
        uVar6 = 4;
        in_w11 = 0;
        if (_j_u1jd8trj_j_mhn3wxje + _j_u1jd8trj_j_mhn3wxje * _j_u1jd8trj_j_mhn3wxje < 0) {
          _j_dc_103_j_rb = _j_enc_103 ^ 0xb0;
          DAT_1000083a0 = DAT_100003dbd ^ 0xb0;
          DAT_1000083a1 = DAT_100003dbe ^ 0xb0;
          DAT_1000083a2 = DAT_100003dbf ^ 0xb0;
          DAT_1000083a3 = DAT_100003dc0 ^ 0xb0;
          DAT_1000083a4 = 0;
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
    if (0xf < uVar2) goto LAB_100003524;
    uVar7 = 0;
    goto LAB_100003590;
  }
  goto LAB_1000035dc;
LAB_100003524:
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
LAB_100003590:
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
      if (uVar2 == uVar1) goto LAB_100003284;
    }
LAB_1000035dc:
    iVar8 = param_2 - iVar8;
    do {
      unaff_x25 = (ulong)(uint)((int)unaff_x25 * param_1);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar6 = 5;
    in_w11 = param_2;
  }
  goto LAB_100003284;
}


===== FUNCTION _j_w6mesi0m @ 0x10000361c size=780 =====
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
                _j_dc_111_j_rb = _j_enc_111 ^ 0x5f;
                DAT_1000083d1 = DAT_100003de9 ^ 0x5f;
                DAT_1000083d2 = DAT_100003dea ^ 0x5f;
                DAT_1000083d3 = DAT_100003deb ^ 0x5f;
                DAT_1000083d4 = DAT_100003dec ^ 0x5f;
                DAT_1000083d5 = 0;
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
            _j_dc_107_j_rb = _j_enc_107 ^ 0x87;
            DAT_1000083c5 = DAT_100003ddf ^ 0x87;
            DAT_1000083c6 = DAT_100003de0 ^ 0x87;
            DAT_1000083c7 = DAT_100003de1 ^ 0x87;
            DAT_1000083c8 = DAT_100003de2 ^ 0x87;
            DAT_1000083c9 = 0;
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
            _j_dc_109_j_rb = _j_enc_109 ^ 0xf3;
            DAT_1000083cb = DAT_100003de4 ^ 0xf3;
            DAT_1000083cc = DAT_100003de5 ^ 0xf3;
            DAT_1000083cd = DAT_100003de6 ^ 0xf3;
            DAT_1000083ce = DAT_100003de7 ^ 0xf3;
            DAT_1000083cf = 0;
            _puts((char *)&_j_dc_109_j_rb);
            uVar2 = 4;
          }
        }
      }
      if (uVar2 == 0) break;
      uVar2 = 2;
      if (_j_w6mesi0m_j_9q46v2mt + _j_w6mesi0m_j_9q46v2mt * _j_w6mesi0m_j_9q46v2mt < 0) {
        _j_dc_105_j_rb = _j_enc_105 ^ 0xa5;
        DAT_1000083bf = DAT_100003dda ^ 0xa5;
        DAT_1000083c0 = DAT_100003ddb ^ 0xa5;
        DAT_1000083c1 = DAT_100003ddc ^ 0xa5;
        DAT_1000083c2 = DAT_100003ddd ^ 0xa5;
        DAT_1000083c3 = 0;
        _puts((char *)&_j_dc_105_j_rb);
        uVar2 = 2;
      }
    }
    uVar2 = 1;
  } while (param_1 < param_2 || param_1 < param_3);
  return param_1;
}


===== FUNCTION _j_dk9e63to @ 0x100003928 size=700 =====
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
              _j_dc_125_j_rb = _j_enc_125 ^ 0xf;
              DAT_1000083ef = DAT_100003e05 ^ 0xf;
              DAT_1000083f0 = DAT_100003e06 ^ 0xf;
              DAT_1000083f1 = DAT_100003e07 ^ 0xf;
              DAT_1000083f2 = DAT_100003e08 ^ 0xf;
              DAT_1000083f3 = 0;
              _puts((char *)&_j_dc_125_j_rb);
              uVar3 = 1;
            }
          }
          else if ((uVar3 == 1) &&
                  (uVar3 = 2,
                  _j_dk9e63to_j_ym23c5kb + _j_dk9e63to_j_ym23c5kb * _j_dk9e63to_j_ym23c5kb < 0)) {
            _j_dc_127_j_rb = _j_enc_127 ^ 0x3a;
            DAT_1000083f5 = DAT_100003e0a ^ 0x3a;
            DAT_1000083f6 = DAT_100003e0b ^ 0x3a;
            DAT_1000083f7 = DAT_100003e0c ^ 0x3a;
            DAT_1000083f8 = DAT_100003e0d ^ 0x3a;
            DAT_1000083f9 = 0;
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
          _j_dc_129_j_rb = _j_enc_129 ^ 0x81;
          DAT_1000083fb = DAT_100003e0f ^ 0x81;
          DAT_1000083fc = DAT_100003e10 ^ 0x81;
          DAT_1000083fd = DAT_100003e11 ^ 0x81;
          DAT_1000083fe = DAT_100003e12 ^ 0x81;
          DAT_1000083ff = 0;
          _puts((char *)&_j_dc_129_j_rb);
          uVar3 = 3;
        }
      }
      if (uVar3 != 3) break;
      uVar3 = 4;
      if (((uint)_j_dk9e63to_j_8iipg4vh * ~(uint)_j_dk9e63to_j_8iipg4vh & 1) != 0) {
        _j_dc_131_j_rb = _j_enc_131 ^ 0x91;
        DAT_100008401 = DAT_100003e14 ^ 0x91;
        DAT_100008402 = DAT_100003e15 ^ 0x91;
        DAT_100008403 = DAT_100003e16 ^ 0x91;
        DAT_100008404 = DAT_100003e17 ^ 0x91;
        DAT_100008405 = 0;
        _puts((char *)&_j_dc_131_j_rb);
        uVar3 = 4;
      }
    }
  } while (uVar3 != 4);
  iVar2 = _j_dwwcl9v0(param_1);
  return param_1 == iVar2;
}


===== FUNCTION _printf @ 0x100003be4 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003bec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004000)((int)param_1);
  return iVar1;
}


===== FUNCTION _puts @ 0x100003bf0 size=12 =====
CFG blocks=1 edges=0

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004008)((int)param_1);
  return iVar1;
}


