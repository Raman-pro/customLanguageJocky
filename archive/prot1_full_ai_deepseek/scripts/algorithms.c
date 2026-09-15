// JOCKY build E201C1E3F4EA77B7 seed=1 date=2026-09-03 03:55:31
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <direct.h>
#elif defined(__APPLE__)
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static const volatile uint8_t j_enc_0[] = {0xEB, 0xEA, 0xE9, 0xE8, 0xEF, 0xEE, 0xED, 0xEC, 0xE3, 0xE2, 0xBA, 0xB9, 0xB8, 0xBF, 0xBE, 0xBD};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < (3 + 13); j_i++) j_rb[j_i] = j_enc_0[j_i] ^ (98 + 121);
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x1D, 0x1C, 0x1F, 0x1E, 0x19, 0x18, 0x1B, 0x1A, 0x15, 0x14, 0x4C, 0x4F, 0x4E, 0x49, 0x48, 0x4B};
static const char* j_dc_1(void) {
    static char j_rb[(17 + 0)];
    for (int j_i = 0; j_i < (10 + 6); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ (42 + 3);
    j_rb[((14 + 2) ^ (3240 ^ 3240))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x59, 0x49};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < (1 + 1); j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 43;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x97, 0x82};
static const char* j_dc_3(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = ((0 + 0) ^ (6133 ^ 6133)); j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 224;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xFF, 0xA0, 0xA2, 0xBF, 0xB3};
static const char* j_dc_4(void) {
    static char j_rb[((3 + 3) ^ (2917 ^ 2917))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 208;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xA6};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 212;
    j_rb[((1 + 0) ^ (4488 ^ 4488))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x75};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < ((0 + 1) ^ (8760 ^ 8760)); j_i++) j_rb[j_i] = j_enc_6[j_i] ^ ((7 + 120) ^ (7324 ^ 7324));
    j_rb[(1 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x35};
static const char* j_dc_7(void) {
    static char j_rb[((0 + 2) ^ (8413 ^ 8413))];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ (3 + 68);
    j_rb[(0 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xBC};
static const char* j_dc_8(void) {
    static char j_rb[((0 + 2) ^ (7728 ^ 7728))];
    for (int j_i = ((0 + 0) ^ (1101 ^ 1101)); j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 131;
    j_rb[(1 + 0)] = ((0 + 0) ^ (1978 ^ 1978));
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0x24, 0x21, 0x3B, 0x3C, 0x2D, 0x26};
static const char* j_dc_9(void) {
    static char j_rb[((4 + 3) ^ (9524 ^ 9524))];
    for (int j_i = ((0 + 0) ^ (6509 ^ 6509)); j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ ((24 + 80) ^ (9288 ^ 9288));
    j_rb[6] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0xB6, 0xA0, 0xA7, 0xB2, 0xB1, 0xBF, 0xBA, 0xA0, 0xBB, 0xB6, 0xB7};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (1167 ^ 1167)); j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ (35 + 208);
    j_rb[(5 + 6)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0xDB, 0xD4, 0xD7, 0xCB, 0xDD, 0xC7, 0xCF, 0xD9, 0xD1, 0xCC};
static const char* j_dc_11(void) {
    static char j_rb[((4 + 7) ^ (8031 ^ 8031))];
    for (int j_i = 0; j_i < (6 + 4); j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 152;
    j_rb[10] = ((0 + 0) ^ (8745 ^ 8745));
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xD6, 0xCB, 0xCF, 0xC7, 0xDD, 0xD5, 0xC3, 0xCB, 0xD6};
static const char* j_dc_12(void) {
    static char j_rb[((4 + 6) ^ (6816 ^ 6816))];
    for (int j_i = (0 + 0); j_i < ((4 + 5) ^ (8031 ^ 8031)); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 130;
    j_rb[9] = ((0 + 0) ^ (7846 ^ 7846));
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x72, 0x69, 0x75, 0x78, 0x6F};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7722 ^ 7722)); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 61;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0xE3, 0xE8, 0xF9, 0xFE, 0xF9, 0xEC, 0xF9, 0xAD, 0xA0, 0xEC, 0xE3, 0xAD, 0xA0, 0xFD, 0xAD, 0xF9, 0xEE, 0xFD, 0xAD, 0xBF, 0xB3, 0xA2, 0xE9, 0xE8, 0xFB, 0xA2, 0xE3, 0xF8, 0xE1, 0xE1};
static const char* j_dc_14(void) {
    static char j_rb[(20 + 11)];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ (124 + 17);
    j_rb[30] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xF2};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < ((0 + 1) ^ (8412 ^ 8412)); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 128;
    j_rb[(0 + 1)] = ((0 + 0) ^ (9231 ^ 9231));
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x4C, 0x5B, 0x48};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = (0 + 0); j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ ((35 + 21) ^ (8104 ^ 8104));
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x39, 0x66, 0x64, 0x79, 0x75, 0x39, 0x78, 0x73, 0x62, 0x39, 0x62, 0x75, 0x66};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = ((0 + 0) ^ (4166 ^ 4166)); j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 22;
    j_rb[((9 + 4) ^ (273 ^ 273))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0xCF, 0x90, 0x92, 0x8F, 0x83, 0xCF, 0x8E, 0x85, 0x94, 0xCF, 0x94, 0x83, 0x90, 0xD6};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 224;
    j_rb[(4 + 10)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xF2, 0xF1, 0xF6, 0xF7, 0xE6};
static const char* j_dc_19(void) {
    static char j_rb[((3 + 3) ^ (1057 ^ 1057))];
    for (int j_i = ((0 + 0) ^ (818 ^ 818)); j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ ((58 + 128) ^ (4788 ^ 4788));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0xE9, 0xEA, 0xE2, 0xF4, 0xFD};
static const char* j_dc_20(void) {
    static char j_rb[((1 + 5) ^ (5481 ^ 5481))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 161;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x31, 0x32, 0x3A, 0x2B, 0x25};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 121;
    j_rb[5] = ((0 + 0) ^ (3352 ^ 3352));
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xA8, 0xAB, 0xB5, 0xBC};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ ((102 + 122) ^ (1027 ^ 1027));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0x99, 0x8C};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = (0 + 0); j_i < ((2 + 0) ^ (4852 ^ 4852)); j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 238;
    j_rb[2] = ((0 + 0) ^ (1001 ^ 1001));
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x32, 0x34, 0x33, 0x23};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (9306 ^ 9306)); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ (65 + 5);
    j_rb[4] = ((0 + 0) ^ (2105 ^ 2105));
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x29, 0x2E, 0x23, 0x3C, 0x2A};
static const char* j_dc_25(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_25[j_i] ^ ((4 + 75) ^ (1574 ^ 1574));
    j_rb[(2 + 3)] = ((0 + 0) ^ (1477 ^ 1477));
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x51, 0x57, 0x50, 0x40};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (67 ^ 67)); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ ((5 + 32) ^ (6865 ^ 6865));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x62, 0x65, 0x68, 0x77, 0x61};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_27[j_i] ^ (0 + 4);
    j_rb[5] = ((0 + 0) ^ (6766 ^ 6766));
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((15 + 11) ^ (502 ^ 502));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x86, 0x81, 0x8C, 0x93, 0x85};
static const char* j_dc_29(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 224;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xEA, 0xEC, 0xEB, 0xFB};
static const char* j_dc_30(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = ((0 + 0) ^ (4982 ^ 4982)); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 158;
    j_rb[4] = ((0 + 0) ^ (633 ^ 633));
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x80, 0x87, 0x8A, 0x95, 0x83};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ (204 + 26);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0xE3, 0xE5, 0xE2, 0xF2};
static const char* j_dc_32(void) {
    static char j_rb[((4 + 1) ^ (1959 ^ 1959))];
    for (int j_i = 0; j_i < ((4 + 0) ^ (752 ^ 752)); j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 151;
    j_rb[4] = ((0 + 0) ^ (635 ^ 635));
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x9A, 0x9D, 0x90, 0x8F, 0x99};
static const char* j_dc_33(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < ((4 + 1) ^ (9737 ^ 9737)); j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 252;
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x82, 0x84, 0x83, 0x93};
static const char* j_dc_34(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 246;
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_35(void) {
    static char j_rb[((1 + 5) ^ (4064 ^ 4064))];
    for (int j_i = ((0 + 0) ^ (8791 ^ 8791)); j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ ((35 + 23) ^ (5790 ^ 5790));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x77, 0x71, 0x76, 0x66};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 3;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x58, 0x5F, 0x52, 0x4D, 0x5B};
static const char* j_dc_37(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 62;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_38(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < ((1 + 3) ^ (3411 ^ 3411)); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 229;
    j_rb[(4 + 0)] = ((0 + 0) ^ (758 ^ 758));
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x67, 0x60, 0x6D, 0x72, 0x64};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ (1 + 0);
    j_rb[5] = ((0 + 0) ^ (4383 ^ 4383));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_40(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ ((27 + 202) ^ (4448 ^ 4448));
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_41(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5545 ^ 5545)); j_i < ((5 + 0) ^ (737 ^ 737)); j_i++) j_rb[j_i] = j_enc_41[j_i] ^ ((36 + 145) ^ (9340 ^ 9340));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xD7, 0xD1, 0xD6, 0xC6};
static const char* j_dc_42(void) {
    static char j_rb[((5 + 0) ^ (2762 ^ 2762))];
    for (int j_i = ((0 + 0) ^ (8357 ^ 8357)); j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 163;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x88, 0x8F, 0x82, 0x9D, 0x8B};
static const char* j_dc_43(void) {
    static char j_rb[((6 + 0) ^ (8528 ^ 8528))];
    for (int j_i = ((0 + 0) ^ (8633 ^ 8633)); j_i < ((0 + 5) ^ (5901 ^ 5901)); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 238;
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x7F, 0x79, 0x7E, 0x6E};
static const char* j_dc_44(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (9542 ^ 9542)); j_i < 4; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ ((0 + 11) ^ (1554 ^ 1554));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_45(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ (125 + 40);
    j_rb[((0 + 5) ^ (4422 ^ 4422))] = ((0 + 0) ^ (4286 ^ 4286));
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (4486 ^ 4486)); j_i < 4; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ (62 + 64);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3D, 0x3A, 0x37, 0x28, 0x3E};
static const char* j_dc_47(void) {
    static char j_rb[((1 + 5) ^ (7234 ^ 7234))];
    for (int j_i = ((0 + 0) ^ (9795 ^ 9795)); j_i < 5; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 91;
    j_rb[((5 + 0) ^ (4542 ^ 4542))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x56, 0x50, 0x57, 0x47};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 34;
    j_rb[((2 + 2) ^ (4147 ^ 4147))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x55, 0x52, 0x5F, 0x40, 0x56};
static const char* j_dc_49(void) {
    static char j_rb[((5 + 1) ^ (7898 ^ 7898))];
    for (int j_i = 0; j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 51;
    j_rb[(3 + 2)] = ((0 + 0) ^ (803 ^ 803));
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (9600 ^ 9600)); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ (104 + 30);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0xFB, 0xFC, 0xF1, 0xEE, 0xF8};
static const char* j_dc_51(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7121 ^ 7121)); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 157;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0xDC, 0xDA, 0xDD, 0xCD};
static const char* j_dc_52(void) {
    static char j_rb[((3 + 2) ^ (3316 ^ 3316))];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 168;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0xC5, 0xC2, 0xCF, 0xD0, 0xC6};
static const char* j_dc_53(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = ((0 + 0) ^ (5666 ^ 5666)); j_i < ((5 + 0) ^ (7657 ^ 7657)); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 163;
    j_rb[(3 + 2)] = ((0 + 0) ^ (7670 ^ 7670));
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_54(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (5927 ^ 5927)); j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ ((121 + 89) ^ (1409 ^ 1409));
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0xFA, 0xFD, 0xF0, 0xEF, 0xF9};
static const char* j_dc_55(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 156;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xCC, 0xCA, 0xCD, 0xDD};
static const char* j_dc_56(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ (141 + 43);
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x35, 0x32, 0x3F, 0x20, 0x36};
static const char* j_dc_57(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ ((37 + 46) ^ (9002 ^ 9002));
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x2E, 0x28, 0x2F, 0x3F};
static const char* j_dc_58(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((3 + 1) ^ (9093 ^ 9093)); j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 90;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xF2, 0xF5, 0xF8, 0xE7, 0xF1};
static const char* j_dc_59(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_59[j_i] ^ ((122 + 26) ^ (8840 ^ 8840));
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0xC0, 0xC6, 0xC1, 0xD1};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 180;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x30, 0x37, 0x3A, 0x25, 0x33};
static const char* j_dc_61(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ ((6 + 80) ^ (5982 ^ 5982));
    j_rb[(0 + 5)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x8D, 0x8B, 0x8C, 0x9C};
static const char* j_dc_62(void) {
    static char j_rb[((0 + 5) ^ (5627 ^ 5627))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 249;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0xFC, 0xFB, 0xF6, 0xE9, 0xFF};
static const char* j_dc_63(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 154;
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_64(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 165;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x38, 0x3F, 0x32, 0x2D, 0x3B};
static const char* j_dc_65(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 94;
    j_rb[((3 + 2) ^ (4950 ^ 4950))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0x40, 0x46, 0x41, 0x51};
static const char* j_dc_66(void) {
    static char j_rb[((0 + 5) ^ (3020 ^ 3020))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 52;
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0xD5, 0xD2, 0xDF, 0xC0, 0xD6};
static const char* j_dc_67(void) {
    static char j_rb[((4 + 2) ^ (8676 ^ 8676))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ 179;
    j_rb[((5 + 0) ^ (1282 ^ 1282))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0x41, 0x47, 0x40, 0x50};
static const char* j_dc_68(void) {
    static char j_rb[((5 + 0) ^ (7418 ^ 7418))];
    for (int j_i = 0; j_i < ((1 + 3) ^ (65 ^ 65)); j_i++) j_rb[j_i] = j_enc_68[j_i] ^ 53;
    j_rb[4] = ((0 + 0) ^ (578 ^ 578));
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0x59, 0x5E, 0x53, 0x4C, 0x5A};
static const char* j_dc_69(void) {
    static char j_rb[((3 + 3) ^ (1565 ^ 1565))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 63;
    j_rb[5] = ((0 + 0) ^ (6973 ^ 6973));
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_70(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ ((11 + 5) ^ (5862 ^ 5862));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_71(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((2 + 3) ^ (3138 ^ 3138)); j_i++) j_rb[j_i] = j_enc_71[j_i] ^ ((139 + 42) ^ (7722 ^ 7722));
    j_rb[((5 + 0) ^ (9647 ^ 9647))] = ((0 + 0) ^ (6427 ^ 6427));
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0x99, 0x9F, 0x98, 0x88};
static const char* j_dc_72(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_72[j_i] ^ (226 + 11);
    j_rb[4] = ((0 + 0) ^ (1662 ^ 1662));
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_73(void) {
    static char j_rb[((5 + 1) ^ (9280 ^ 9280))];
    for (int j_i = 0; j_i < ((0 + 5) ^ (6822 ^ 6822)); j_i++) j_rb[j_i] = j_enc_73[j_i] ^ (7 + 19);
    j_rb[((2 + 3) ^ (1009 ^ 1009))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0x7A, 0x7C, 0x7B, 0x6B};
static const char* j_dc_74(void) {
    static char j_rb[((3 + 2) ^ (4654 ^ 4654))];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_74[j_i] ^ (7 + 7);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0xE7, 0xE0, 0xED, 0xF2, 0xE4};
static const char* j_dc_75(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_75[j_i] ^ (19 + 110);
    j_rb[((1 + 4) ^ (2221 ^ 2221))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0x2A, 0x2C, 0x2B, 0x3B};
static const char* j_dc_76(void) {
    static char j_rb[((3 + 2) ^ (4975 ^ 4975))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_76[j_i] ^ ((25 + 69) ^ (1363 ^ 1363));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_77[] = {0x1B, 0x1C, 0x11, 0x0E, 0x18};
static const char* j_dc_77(void) {
    static char j_rb[((1 + 5) ^ (9235 ^ 9235))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_77[j_i] ^ (120 + 5);
    j_rb[((4 + 1) ^ (9356 ^ 9356))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_78[] = {0x66, 0x60, 0x67, 0x77};
static const char* j_dc_78(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_78[j_i] ^ 18;
    j_rb[((1 + 3) ^ (3464 ^ 3464))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_79[] = {0x61, 0x66, 0x6B, 0x74, 0x62};
static const char* j_dc_79(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (4985 ^ 4985)); j_i < 5; j_i++) j_rb[j_i] = j_enc_79[j_i] ^ (1 + 6);
    j_rb[(0 + 5)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_80[] = {0x53, 0x55, 0x52, 0x42};
static const char* j_dc_80(void) {
    static char j_rb[((3 + 2) ^ (5666 ^ 5666))];
    for (int j_i = 0; j_i < ((3 + 1) ^ (7488 ^ 7488)); j_i++) j_rb[j_i] = j_enc_80[j_i] ^ 39;
    j_rb[((2 + 2) ^ (7985 ^ 7985))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_81[] = {0x5F, 0x58, 0x55, 0x4A, 0x5C};
static const char* j_dc_81(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_81[j_i] ^ (16 + 41);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_82[] = {0x85, 0x83, 0x84, 0x94};
static const char* j_dc_82(void) {
    static char j_rb[((5 + 0) ^ (62 ^ 62))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_82[j_i] ^ (170 + 71);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_83[] = {0xB5, 0xB2, 0xBF, 0xA0, 0xB6};
static const char* j_dc_83(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((0 + 5) ^ (2970 ^ 2970)); j_i++) j_rb[j_i] = j_enc_83[j_i] ^ (96 + 115);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_84[] = {0xAF, 0xA9, 0xAE, 0xBE};
static const char* j_dc_84(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (390 ^ 390)); j_i < 4; j_i++) j_rb[j_i] = j_enc_84[j_i] ^ (180 + 39);
    j_rb[4] = ((0 + 0) ^ (4837 ^ 4837));
    return j_rb;
}

static const volatile uint8_t j_enc_85[] = {0xF5, 0xF2, 0xFF, 0xE0, 0xF6};
static const char* j_dc_85(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (9616 ^ 9616)); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_85[j_i] ^ 147;
    j_rb[(4 + 1)] = ((0 + 0) ^ (2076 ^ 2076));
    return j_rb;
}

static const volatile uint8_t j_enc_86[] = {0xCD, 0xCB, 0xCC, 0xDC};
static const char* j_dc_86(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((0 + 4) ^ (9024 ^ 9024)); j_i++) j_rb[j_i] = j_enc_86[j_i] ^ ((90 + 95) ^ (2465 ^ 2465));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_87[] = {0x44, 0x43, 0x4E, 0x51, 0x47};
static const char* j_dc_87(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6150 ^ 6150)); j_i < ((1 + 4) ^ (150 ^ 150)); j_i++) j_rb[j_i] = j_enc_87[j_i] ^ 34;
    j_rb[(4 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_88[] = {0xC9, 0xCF, 0xC8, 0xD8};
static const char* j_dc_88(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_88[j_i] ^ ((121 + 68) ^ (2402 ^ 2402));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_89[] = {0x8B, 0x8C, 0x81, 0x9E, 0x88};
static const char* j_dc_89(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_89[j_i] ^ (55 + 182);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_90[] = {0x59, 0x5F, 0x58, 0x48};
static const char* j_dc_90(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7513 ^ 7513)); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_90[j_i] ^ 45;
    j_rb[((0 + 4) ^ (6667 ^ 6667))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_91[] = {0xCF, 0xC8, 0xC5, 0xDA, 0xCC};
static const char* j_dc_91(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_91[j_i] ^ 169;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_92[] = {0x51, 0x57, 0x50, 0x40};
static const char* j_dc_92(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (183 ^ 183)); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_92[j_i] ^ ((7 + 30) ^ (2299 ^ 2299));
    j_rb[((0 + 4) ^ (8764 ^ 8764))] = ((0 + 0) ^ (4581 ^ 4581));
    return j_rb;
}

static const volatile uint8_t j_enc_93[] = {0xEA, 0xED, 0xE0, 0xFF, 0xE9};
static const char* j_dc_93(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((5 + 0) ^ (7637 ^ 7637)); j_i++) j_rb[j_i] = j_enc_93[j_i] ^ 140;
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_94[] = {0xC9, 0xCF, 0xC8, 0xD8};
static const char* j_dc_94(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_94[j_i] ^ 189;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_95[] = {0xD9, 0xDE, 0xD3, 0xCC, 0xDA};
static const char* j_dc_95(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_95[j_i] ^ 191;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_96[] = {0x7D, 0x7B, 0x7C, 0x6C};
static const char* j_dc_96(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_96[j_i] ^ 9;
    j_rb[((1 + 3) ^ (8752 ^ 8752))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_97[] = {0xD5, 0xD2, 0xDF, 0xC0, 0xD6};
static const char* j_dc_97(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_97[j_i] ^ 179;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_98[] = {0xC9, 0xCF, 0xC8, 0xD8};
static const char* j_dc_98(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_98[j_i] ^ 189;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_99[] = {0xF5, 0xF2, 0xFF, 0xE0, 0xF6};
static const char* j_dc_99(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (840 ^ 840)); j_i < ((3 + 2) ^ (7633 ^ 7633)); j_i++) j_rb[j_i] = j_enc_99[j_i] ^ 147;
    j_rb[(5 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_100[] = {0x98, 0x9E, 0x99, 0x89};
static const char* j_dc_100(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_100[j_i] ^ (22 + 214);
    j_rb[(0 + 4)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_101[] = {0xB3, 0xB4, 0xB9, 0xA6, 0xB0};
static const char* j_dc_101(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_101[j_i] ^ ((135 + 78) ^ (6915 ^ 6915));
    j_rb[((3 + 2) ^ (4340 ^ 4340))] = ((0 + 0) ^ (5169 ^ 5169));
    return j_rb;
}

static const volatile uint8_t j_enc_102[] = {0x0C, 0x0A, 0x0D, 0x1D};
static const char* j_dc_102(void) {
    static char j_rb[((1 + 4) ^ (9757 ^ 9757))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_102[j_i] ^ ((47 + 73) ^ (2942 ^ 2942));
    j_rb[(0 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_103[] = {0xB3, 0xB4, 0xB9, 0xA6, 0xB0};
static const char* j_dc_103(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_103[j_i] ^ (85 + 128);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_104[] = {0xD5, 0xD3, 0xD4, 0xC4};
static const char* j_dc_104(void) {
    static char j_rb[((5 + 0) ^ (3515 ^ 3515))];
    for (int j_i = 0; j_i < ((0 + 4) ^ (6160 ^ 6160)); j_i++) j_rb[j_i] = j_enc_104[j_i] ^ 161;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_105[] = {0xF4, 0xF3, 0xFE, 0xE1, 0xF7};
static const char* j_dc_105(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_105[j_i] ^ ((124 + 22) ^ (6181 ^ 6181));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_106[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_106(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_106[j_i] ^ 126;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_107[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_107(void) {
    static char j_rb[((2 + 4) ^ (4036 ^ 4036))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_107[j_i] ^ ((15 + 43) ^ (6791 ^ 6791));
    j_rb[5] = ((0 + 0) ^ (5042 ^ 5042));
    return j_rb;
}

static const volatile uint8_t j_enc_108[] = {0x6B, 0x6D, 0x6A, 0x7A};
static const char* j_dc_108(void) {
    static char j_rb[((0 + 5) ^ (4509 ^ 4509))];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (2394 ^ 2394)); j_i++) j_rb[j_i] = j_enc_108[j_i] ^ 31;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_109[] = {0xD6, 0xD1, 0xDC, 0xC3, 0xD5};
static const char* j_dc_109(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_109[j_i] ^ 176;
    j_rb[((1 + 4) ^ (818 ^ 818))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_110[] = {0x5F, 0x59, 0x5E, 0x4E};
static const char* j_dc_110(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((1 + 3) ^ (1648 ^ 1648)); j_i++) j_rb[j_i] = j_enc_110[j_i] ^ 43;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_111[] = {0xEA, 0xED, 0xE0, 0xFF, 0xE9};
static const char* j_dc_111(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((1 + 4) ^ (6901 ^ 6901)); j_i++) j_rb[j_i] = j_enc_111[j_i] ^ (72 + 68);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_112[] = {0x1E, 0x18, 0x1F, 0x0F};
static const char* j_dc_112(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((2 + 2) ^ (7486 ^ 7486)); j_i++) j_rb[j_i] = j_enc_112[j_i] ^ ((91 + 15) ^ (8545 ^ 8545));
    j_rb[(1 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_113[] = {0x16, 0x11, 0x1C, 0x03, 0x15};
static const char* j_dc_113(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6269 ^ 6269)); j_i < 5; j_i++) j_rb[j_i] = j_enc_113[j_i] ^ 112;
    j_rb[((1 + 4) ^ (2871 ^ 2871))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_114[] = {0x11, 0x17, 0x10, 0x00};
static const char* j_dc_114(void) {
    static char j_rb[((0 + 5) ^ (1121 ^ 1121))];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_114[j_i] ^ 101;
    j_rb[4] = ((0 + 0) ^ (6433 ^ 6433));
    return j_rb;
}

static const volatile uint8_t j_enc_115[] = {0x3E, 0x39, 0x34, 0x2B, 0x3D};
static const char* j_dc_115(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_115[j_i] ^ 88;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_116[] = {0x00, 0x06, 0x01, 0x11};
static const char* j_dc_116(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_116[j_i] ^ 116;
    j_rb[4] = ((0 + 0) ^ (897 ^ 897));
    return j_rb;
}

static const volatile uint8_t j_enc_117[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_117(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_117[j_i] ^ 58;
    j_rb[5] = ((0 + 0) ^ (8883 ^ 8883));
    return j_rb;
}

static const volatile uint8_t j_enc_118[] = {0x93, 0x95, 0x92, 0x82};
static const char* j_dc_118(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_118[j_i] ^ 231;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_119[] = {0x6E, 0x69, 0x64, 0x7B, 0x6D};
static const char* j_dc_119(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_119[j_i] ^ 8;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_120[] = {0xD8, 0xDE, 0xD9, 0xC9};
static const char* j_dc_120(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < ((2 + 2) ^ (4615 ^ 4615)); j_i++) j_rb[j_i] = j_enc_120[j_i] ^ 172;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_121[] = {0xBB, 0xBC, 0xB1, 0xAE, 0xB8};
static const char* j_dc_121(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_121[j_i] ^ 221;
    j_rb[(3 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_122[] = {0x67, 0x61, 0x66, 0x76};
static const char* j_dc_122(void) {
    static char j_rb[((0 + 5) ^ (873 ^ 873))];
    for (int j_i = 0; j_i < ((0 + 4) ^ (8597 ^ 8597)); j_i++) j_rb[j_i] = j_enc_122[j_i] ^ (3 + 16);
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_123[] = {0x68, 0x6F, 0x62, 0x7D, 0x6B};
static const char* j_dc_123(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((5 + 0) ^ (1072 ^ 1072)); j_i++) j_rb[j_i] = j_enc_123[j_i] ^ 14;
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_124[] = {0xF1, 0xF7, 0xF0, 0xE0};
static const char* j_dc_124(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (2408 ^ 2408)); j_i < ((1 + 3) ^ (6601 ^ 6601)); j_i++) j_rb[j_i] = j_enc_124[j_i] ^ ((106 + 27) ^ (1825 ^ 1825));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_125[] = {0x52, 0x55, 0x58, 0x47, 0x51};
static const char* j_dc_125(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (40 ^ 40)); j_i < 5; j_i++) j_rb[j_i] = j_enc_125[j_i] ^ 52;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_126[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_126(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = ((0 + 0) ^ (6583 ^ 6583)); j_i < 4; j_i++) j_rb[j_i] = j_enc_126[j_i] ^ 131;
    j_rb[((2 + 2) ^ (5617 ^ 5617))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_127[] = {0xB2, 0xB5, 0xB8, 0xA7, 0xB1};
static const char* j_dc_127(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = (0 + 0); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_127[j_i] ^ 212;
    j_rb[5] = ((0 + 0) ^ (9286 ^ 9286));
    return j_rb;
}

static const volatile uint8_t j_enc_128[] = {0x61, 0x67, 0x60, 0x70};
static const char* j_dc_128(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (7272 ^ 7272)); j_i < 4; j_i++) j_rb[j_i] = j_enc_128[j_i] ^ (13 + 8);
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_129[] = {0x32, 0x35, 0x38, 0x27, 0x31};
static const char* j_dc_129(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_129[j_i] ^ ((75 + 9) ^ (3265 ^ 3265));
    j_rb[((5 + 0) ^ (7765 ^ 7765))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_130[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_130(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (1461 ^ 1461)); j_i < 4; j_i++) j_rb[j_i] = j_enc_130[j_i] ^ (28 + 103);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_131[] = {0x67, 0x60, 0x6D, 0x72, 0x64};
static const char* j_dc_131(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_131[j_i] ^ ((1 + 0) ^ (5197 ^ 5197));
    j_rb[(4 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_132[] = {0xED, 0xEB, 0xEC, 0xFC};
static const char* j_dc_132(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_132[j_i] ^ 153;
    j_rb[4] = ((0 + 0) ^ (6546 ^ 6546));
    return j_rb;
}

static const volatile uint8_t j_enc_133[] = {0xE1, 0xE6, 0xEB, 0xF4, 0xE2};
static const char* j_dc_133(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((3 + 2) ^ (4242 ^ 4242)); j_i++) j_rb[j_i] = j_enc_133[j_i] ^ 135;
    j_rb[((0 + 5) ^ (183 ^ 183))] = ((0 + 0) ^ (9351 ^ 9351));
    return j_rb;
}

static const volatile uint8_t j_enc_134[] = {0x61, 0x67, 0x60, 0x70};
static const char* j_dc_134(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_134[j_i] ^ 21;
    j_rb[4] = ((0 + 0) ^ (2646 ^ 2646));
    return j_rb;
}

static const volatile uint8_t j_enc_135[] = {0x1C, 0x1B, 0x16, 0x09, 0x1F};
static const char* j_dc_135(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < ((2 + 3) ^ (2496 ^ 2496)); j_i++) j_rb[j_i] = j_enc_135[j_i] ^ (91 + 31);
    j_rb[(4 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_136[] = {0x6B, 0x6B, 0x76, 0x30, 0x3F, 0x34, 0x39, 0x38, 0x37, 0x35, 0x35, 0x3F, 0x76, 0x7E, 0x3F, 0x22, 0x33, 0x24, 0x37, 0x22, 0x3F, 0x20, 0x33, 0x7F, 0x76, 0x6B, 0x6B};
static const char* j_dc_136(void) {
    static char j_rb[28];
    for (int j_i = ((0 + 0) ^ (4612 ^ 4612)); j_i < (14 + 13); j_i++) j_rb[j_i] = j_enc_136[j_i] ^ (48 + 38);
    j_rb[((10 + 17) ^ (4565 ^ 4565))] = ((0 + 0) ^ (6621 ^ 6621));
    return j_rb;
}

static const volatile uint8_t j_enc_137[] = {0xCB, 0xCD, 0xCA, 0xDA};
static const char* j_dc_137(void) {
    static char j_rb[((5 + 0) ^ (8382 ^ 8382))];
    for (int j_i = (0 + 0); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_137[j_i] ^ 191;
    j_rb[((2 + 2) ^ (1336 ^ 1336))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_138[] = {0x31, 0x36, 0x3B, 0x24, 0x32};
static const char* j_dc_138(void) {
    static char j_rb[((3 + 3) ^ (6708 ^ 6708))];
    for (int j_i = (0 + 0); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_138[j_i] ^ 87;
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_139[] = {0x56, 0x56, 0x4B, 0x0D, 0x02, 0x09, 0x04, 0x05, 0x0A, 0x08, 0x08, 0x02, 0x4B, 0x43, 0x19, 0x0E, 0x08, 0x1E, 0x19, 0x18, 0x02, 0x1D, 0x0E, 0x42, 0x4B, 0x56, 0x56};
static const char* j_dc_139(void) {
    static char j_rb[28];
    for (int j_i = 0; j_i < ((14 + 13) ^ (9800 ^ 9800)); j_i++) j_rb[j_i] = j_enc_139[j_i] ^ ((40 + 67) ^ (7475 ^ 7475));
    j_rb[27] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_140[] = {0xC8, 0xCE, 0xC9, 0xD9};
static const char* j_dc_140(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_140[j_i] ^ 188;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_141[] = {0x62, 0x65, 0x68, 0x77, 0x61};
static const char* j_dc_141(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_141[j_i] ^ 4;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_142[] = {0x4F, 0x49, 0x4E, 0x5E};
static const char* j_dc_142(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_142[j_i] ^ 59;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_143[] = {0xCB, 0xCC, 0xC1, 0xDE, 0xC8};
static const char* j_dc_143(void) {
    static char j_rb[((1 + 5) ^ (1066 ^ 1066))];
    for (int j_i = (0 + 0); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_143[j_i] ^ ((53 + 120) ^ (1804 ^ 1804));
    j_rb[(0 + 5)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_144[] = {0x47, 0x47, 0x5A, 0x1C, 0x1B, 0x19, 0x0E, 0x15, 0x08, 0x13, 0x1B, 0x16, 0x5A, 0x47, 0x47};
static const char* j_dc_144(void) {
    static char j_rb[(0 + 16)];
    for (int j_i = 0; j_i < ((8 + 7) ^ (9043 ^ 9043)); j_i++) j_rb[j_i] = j_enc_144[j_i] ^ 122;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_145[] = {0x01, 0x01, 0x1C, 0x5B, 0x4E, 0x59, 0x5D, 0x48, 0x59, 0x4F, 0x48, 0x1C, 0x5F, 0x53, 0x51, 0x51, 0x53, 0x52, 0x1C, 0x58, 0x55, 0x4A, 0x55, 0x4F, 0x53, 0x4E, 0x1C, 0x01, 0x01};
static const char* j_dc_145(void) {
    static char j_rb[(21 + 9)];
    for (int j_i = 0; j_i < 29; j_i++) j_rb[j_i] = j_enc_145[j_i] ^ 60;
    j_rb[(28 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_146[] = {0x09, 0x09, 0x14, 0x44, 0x46, 0x5D, 0x59, 0x55, 0x58, 0x5D, 0x40, 0x4D, 0x14, 0x09, 0x09};
static const char* j_dc_146(void) {
    static char j_rb[16];
    for (int j_i = ((0 + 0) ^ (7207 ^ 7207)); j_i < 15; j_i++) j_rb[j_i] = j_enc_146[j_i] ^ ((3 + 49) ^ (135 ^ 135));
    j_rb[(2 + 13)] = ((0 + 0) ^ (4718 ^ 4718));
    return j_rb;
}

static const volatile uint8_t j_enc_147[] = {0x94, 0x92, 0x95, 0x85};
static const char* j_dc_147(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_147[j_i] ^ ((112 + 112) ^ (2904 ^ 2904));
    j_rb[((1 + 3) ^ (1839 ^ 1839))] = ((0 + 0) ^ (3833 ^ 3833));
    return j_rb;
}

static const volatile uint8_t j_enc_148[] = {0xCE, 0xC9, 0xC4, 0xDB, 0xCD};
static const char* j_dc_148(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6657 ^ 6657)); j_i < 5; j_i++) j_rb[j_i] = j_enc_148[j_i] ^ (82 + 86);
    j_rb[5] = ((0 + 0) ^ (1674 ^ 1674));
    return j_rb;
}

static const volatile uint8_t j_enc_149[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_149(void) {
    static char j_rb[((1 + 4) ^ (1985 ^ 1985))];
    for (int j_i = 0; j_i < ((2 + 2) ^ (594 ^ 594)); j_i++) j_rb[j_i] = j_enc_149[j_i] ^ (98 + 33);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_150[] = {0x55, 0x52, 0x5F, 0x40, 0x56};
static const char* j_dc_150(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_150[j_i] ^ 51;
    j_rb[(3 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_151[] = {0x4D, 0x4B, 0x4C, 0x5C};
static const char* j_dc_151(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = ((0 + 0) ^ (1149 ^ 1149)); j_i < 4; j_i++) j_rb[j_i] = j_enc_151[j_i] ^ 57;
    j_rb[((3 + 1) ^ (4684 ^ 4684))] = ((0 + 0) ^ (7187 ^ 7187));
    return j_rb;
}

static const volatile uint8_t j_enc_152[] = {0xC6, 0xC1, 0xCC, 0xD3, 0xC5};
static const char* j_dc_152(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6218 ^ 6218)); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_152[j_i] ^ 160;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_153[] = {0x10, 0x16, 0x11, 0x01};
static const char* j_dc_153(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_153[j_i] ^ 100;
    j_rb[(0 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_154[] = {0x9B, 0x9C, 0x91, 0x8E, 0x98};
static const char* j_dc_154(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((1 + 4) ^ (9559 ^ 9559)); j_i++) j_rb[j_i] = j_enc_154[j_i] ^ (118 + 135);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_155[] = {0x80, 0x80, 0x9D, 0xCD, 0xCF, 0xD4, 0xD0, 0xD8, 0xCE, 0x9D, 0xC8, 0xCD, 0x9D, 0xC9, 0xD2, 0x9D, 0x8E, 0x8D, 0x9D, 0x80, 0x80};
static const char* j_dc_155(void) {
    static char j_rb[22];
    for (int j_i = (0 + 0); j_i < 21; j_i++) j_rb[j_i] = j_enc_155[j_i] ^ (161 + 28);
    j_rb[((20 + 1) ^ (7713 ^ 7713))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_156[] = {0xC8, 0xC8, 0xD5, 0x96, 0x9A, 0x99, 0x99, 0x94, 0x81, 0x8F, 0xD5, 0x86, 0x81, 0x90, 0x85, 0x86, 0xD5, 0xC8, 0xC8};
static const char* j_dc_156(void) {
    static char j_rb[(14 + 6)];
    for (int j_i = 0; j_i < (18 + 1); j_i++) j_rb[j_i] = j_enc_156[j_i] ^ 245;
    j_rb[(6 + 13)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_157[] = {0xC4, 0xC4, 0xD9, 0x8A, 0x8C, 0x94, 0xD9, 0x96, 0x9F, 0xD9, 0x9D, 0x90, 0x9E, 0x90, 0x8D, 0x8A, 0xD9, 0xC4, 0xC4};
static const char* j_dc_157(void) {
    static char j_rb[((1 + 19) ^ (3160 ^ 3160))];
    for (int j_i = (0 + 0); j_i < 19; j_i++) j_rb[j_i] = j_enc_157[j_i] ^ (239 + 10);
    j_rb[((13 + 6) ^ (55 ^ 55))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_158[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_158(void) {
    static char j_rb[((3 + 2) ^ (8227 ^ 8227))];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_158[j_i] ^ 58;
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_159[] = {0x56, 0x51, 0x5C, 0x43, 0x55};
static const char* j_dc_159(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_159[j_i] ^ (32 + 16);
    j_rb[(5 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_160[] = {0x1C, 0x1C, 0x01, 0x53, 0x44, 0x57, 0x44, 0x53, 0x52, 0x44, 0x01, 0x45, 0x48, 0x46, 0x48, 0x55, 0x52, 0x01, 0x1C, 0x1C};
static const char* j_dc_160(void) {
    static char j_rb[21];
    for (int j_i = 0; j_i < 20; j_i++) j_rb[j_i] = j_enc_160[j_i] ^ 33;
    j_rb[(0 + 20)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_161[] = {0x15, 0x13, 0x14, 0x04};
static const char* j_dc_161(void) {
    static char j_rb[((5 + 0) ^ (3742 ^ 3742))];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_161[j_i] ^ 97;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_162[] = {0x4E, 0x49, 0x44, 0x5B, 0x4D};
static const char* j_dc_162(void) {
    static char j_rb[((6 + 0) ^ (5422 ^ 5422))];
    for (int j_i = 0; j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_162[j_i] ^ 40;
    j_rb[((3 + 2) ^ (3853 ^ 3853))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_163[] = {0xD9, 0xD9, 0xC4, 0x94, 0x8B, 0x93, 0x81, 0x96, 0xC4, 0xD9, 0xD9};
static const char* j_dc_163(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (7528 ^ 7528)); j_i < 11; j_i++) j_rb[j_i] = j_enc_163[j_i] ^ ((136 + 92) ^ (6829 ^ 6829));
    j_rb[(2 + 9)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_164[] = {0x5A, 0x5A, 0x47, 0x0A, 0x0E, 0x09, 0x47, 0x48, 0x47, 0x0A, 0x06, 0x1F, 0x47, 0x08, 0x01, 0x47, 0x13, 0x0F, 0x15, 0x02, 0x02, 0x47, 0x5A, 0x5A};
static const char* j_dc_164(void) {
    static char j_rb[((6 + 19) ^ (4919 ^ 4919))];
    for (int j_i = 0; j_i < ((1 + 23) ^ (5690 ^ 5690)); j_i++) j_rb[j_i] = j_enc_164[j_i] ^ 103;
    j_rb[24] = ((0 + 0) ^ (1498 ^ 1498));
    return j_rb;
}

static const volatile uint8_t j_enc_165[] = {0x77, 0x77, 0x6A, 0x3A, 0x2B, 0x26, 0x23, 0x24, 0x2E, 0x38, 0x25, 0x27, 0x2F, 0x6A, 0x24, 0x3F, 0x27, 0x28, 0x2F, 0x38, 0x6A, 0x77, 0x77};
static const char* j_dc_165(void) {
    static char j_rb[24];
    for (int j_i = 0; j_i < ((20 + 3) ^ (3525 ^ 3525)); j_i++) j_rb[j_i] = j_enc_165[j_i] ^ 74;
    j_rb[((10 + 13) ^ (2545 ^ 2545))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_166[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_166(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (9524 ^ 9524)); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_166[j_i] ^ (22 + 36);
    j_rb[((1 + 3) ^ (7257 ^ 7257))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_167[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_167(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_167[j_i] ^ (114 + 51);
    j_rb[((3 + 2) ^ (4941 ^ 4941))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_168[] = {0x23, 0x25, 0x22, 0x32};
static const char* j_dc_168(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = ((0 + 0) ^ (6765 ^ 6765)); j_i < 4; j_i++) j_rb[j_i] = j_enc_168[j_i] ^ 87;
    j_rb[(0 + 4)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_169[] = {0x2B, 0x2C, 0x21, 0x3E, 0x28};
static const char* j_dc_169(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_169[j_i] ^ ((9 + 68) ^ (374 ^ 374));
    j_rb[((3 + 2) ^ (8702 ^ 8702))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_170[] = {0x2F, 0x29, 0x2E, 0x3E};
static const char* j_dc_170(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_170[j_i] ^ ((55 + 36) ^ (621 ^ 621));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_171[] = {0x73, 0x74, 0x79, 0x66, 0x70};
static const char* j_dc_171(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_171[j_i] ^ (2 + 19);
    j_rb[5] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + ((0 + 8) ^ (4175 ^ 4175)) < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default:
                if (c < 0x20) {
                    out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
                    out[o++] = j_dc_0()[c >> (0 + 4)];
                    out[o++] = j_dc_1()[c & 15];
                } else out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static const char* j_sys_now(void) {
    time_t t = time(NULL);
#if defined(_WIN32)
    struct tm* tmv = localtime(&t);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", tmv);
#else
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", &tmv);
#endif
    return j_buf;
}

static void j_sys_sleep(int32_t ms) {
#if defined(_WIN32)
    Sleep((DWORD)ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

static const char* j_sys_cwd(void) {
#if defined(_WIN32)
    _getcwd(j_buf, (int)J_BUF_CAP);
#else
    getcwd(j_buf, J_BUF_CAP);
#endif
    return j_buf;
}

static const char* j_env_get(const char* name) {
    const char* v = getenv(name);
    return v ? v : "";
}

static bool j_fs_exists(const char* path) {
#if defined(_WIN32)
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    return access(path, F_OK) == 0;
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, j_dc_2());
    if (!f) return "";
    size_t n = fread(j_buf, (1 + 0), J_BUF_CAP - (1 + 0), f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = ((0 + 0) ^ (9290 ^ 9290));
    j_buf[off++] = '[';
    int first = ((1 + 0) ^ (6240 ^ 6240));
#if defined(_WIN32)
    char pattern[((208 + 816) ^ (822 ^ 822))];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > (0 + 0) ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - (118 + 82)) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (456 ^ 456));
            char esc[((779 + 245) ^ (3893 ^ 3893))];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = ((0 + 0) ^ (7399 ^ 7399));
    j_buf[off++] = '[';
    int first = ((1 + 0) ^ (2167 ^ 2167));
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - ((230 + 170) ^ (7928 ^ 7928))) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = ((0 + 0) ^ (6578 ^ 6578)); pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[(1012 + 7180)];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[(243 + 13)];
        int len = proc_name(pid, name, sizeof name);
        if (len <= (0 + 0)) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = (0 + 0);
        char esc[(5 + 507)];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[((0 + 0) ^ (3449 ^ 3449))] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[(51 + 205)];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - (306 + 94)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[((47 + 465) ^ (9592 ^ 9592))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_net_proc_parse(const char* path, size_t* off, int* first) {
    FILE* f = fopen(path, j_dc_7());
    if (!f) return;
    char line[((184 + 328) ^ (4879 ^ 4879))];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = ((0 + 0) ^ (6701 ^ 6701)); continue; }
        char laddr[64], raddr[(14 + 50)], st[((6 + 10) ^ (4926 ^ 4926))];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - ((91 + 209) ^ (6448 ^ 6448))) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : ((0 + 0) ^ (2439 ^ 2439)));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = ((0 + 0) ^ (9017 ^ 9017));
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = ((0 + 0) ^ (1034 ^ 1034));
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0));
    char* t = (char*)malloc(sz ? sz : (1 + 0));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0)) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[((51 + 13) ^ (2378 ^ 2378))], ri[64];
                snprintf(li, sizeof li, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwLocalAddr), (unsigned)ntohs((u_short)r->dwLocalPort));
                snprintf(ri, sizeof ri, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwRemoteAddr), (unsigned)ntohs((u_short)r->dwRemotePort));
                const char* state = j_dc_8();
                switch (r->dwState) {
                    case 2:  state = j_dc_9(); break;
                    case 5:  state = j_dc_10(); break;
                    case 8:  state = j_dc_11(); break;
                    case 11: state = j_dc_12(); break;
                    default: state = j_dc_13(); break;
                }
                if (off > J_BUF_CAP - ((169 + 131) ^ (8565 ^ 8565))) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (8220 ^ 8220));
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : (0 + 0));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == ((2 + 2) ^ (5097 ^ 5097))) {
                if (strncmp(proto, j_dc_16(), 3) != ((0 + 0) ^ (5487 ^ 5487))) continue;
                if (off > J_BUF_CAP - (90 + 210)) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > ((0 + 0) ^ (8976 ^ 8976)) ? n : 0);
            }
        }
        pclose(ns);
    }
#else
    j_net_proc_parse(j_dc_17(), &off, &first);
    j_net_proc_parse(j_dc_18(), &off, &first);
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_reg_list(const char* key) {
    size_t off = ((0 + 0) ^ (7736 ^ 7736));
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), ((4 + 1) ^ (4410 ^ 4410))) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + (5 + 0); }
    else if (strncmp(key, j_dc_20(), ((2 + 3) ^ (4738 ^ 4738))) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), (5 + 0)) == ((0 + 0) ^ (4500 ^ 4500))) { root = HKEY_CLASSES_ROOT; sub = key + (2 + 3); }
    else if (strncmp(key, j_dc_22(), ((3 + 1) ^ (6979 ^ 6979))) == (0 + 0)) { root = HKEY_USERS; sub = key + ((0 + 4) ^ (8131 ^ 8131)); }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (5616 ^ 5616));
            char esc[(55 + 457)];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > (0 + 0) ? n2 : (0 + 0));
        }
        RegCloseKey(hk);
    }
#else
    (void)key;
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_mem_dump(int32_t pid, const char* path) {
#if defined(_WIN32)
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, (DWORD)pid);
    if (!h) return;
    FILE* out = fopen(path, j_dc_23());
    if (!out) { CloseHandle(h); return; }
    unsigned char* base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    unsigned long regions = 0;
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < ((46909 + 53091) ^ (6053 ^ 6053))) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = (0 + 0);
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, 1, read, out);
            }
            free(chunk);
        }
        base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
    }
    fclose(out);
    CloseHandle(h);
#else
    (void)pid; (void)path;
#endif
}

static volatile int32_t j_xt2qddae = (28271 + 9817);
static volatile int32_t j_mkx2zwwr = (6669 + 28475);

static int32_t j_6gssa7uj(int32_t j_6euxfluj);
static int32_t j_n49ux56p(int32_t j_6euxfluj);
static int32_t j_xg1b6c1n(int32_t j_6euxfluj);
static int32_t j_vu0yg17q(int32_t j_i66zt01p, int32_t j_ospmyf0h);
static bool j_1xkzpha6(int32_t j_6euxfluj);
static int32_t j_hrr5osqe(int32_t j_6euxfluj);
static int32_t j_g9x5rzlj(int32_t j_6euxfluj);
static int32_t j_cznb8aac(int32_t j_6euxfluj);
static int32_t j_xad10s9i(int32_t j_6c6x6f0a, int32_t j_l08o3mnd);
static int32_t j_p56139q7(int32_t j_i66zt01p, int32_t j_ospmyf0h, int32_t j_9jzx6pkp);
static int32_t j_6j95do8d(int32_t j_i66zt01p, int32_t j_ospmyf0h, int32_t j_9jzx6pkp);
static bool j_g396e7d4(int32_t j_6euxfluj);

static int32_t j_6gssa7uj(int32_t j_6euxfluj)
{
    int32_t j_21ahhhe3 = (0 + 0);
    while ((j_21ahhhe3 != -1))
    {
        switch (j_21ahhhe3)
        {
            case 0:
                static volatile int64_t j_vxs0t3hw = (52170 + 35579);
                static volatile int64_t j_eee7mwgd = 57113;
                static volatile int64_t j_rm2fs6zk = 26644;
                if ((((j_rm2fs6zk * j_rm2fs6zk) + j_rm2fs6zk) < 0))
                {
                    volatile int64_t j_2bkxss77 = ((j_rm2fs6zk * 69) + 644);
                    (void)printf("%s\n", (0 + 0) ? j_dc_24() : j_dc_25());
                }
                j_21ahhhe3 = ((0 + 1) ^ (6088 ^ 6088));
                break;
            case 1:
                if ((((j_eee7mwgd * j_eee7mwgd) + j_eee7mwgd) < 0))
                {
                    volatile int64_t j_exm0gcsl = ((j_eee7mwgd * ((55 + 5) ^ (1896 ^ 1896))) + 113);
                    (void)printf("%s\n", ((0 + 0) ^ (9841 ^ 9841)) ? j_dc_26() : j_dc_27());
                }
                j_21ahhhe3 = 2;
                break;
            case 2:
                if ((((j_vxs0t3hw * j_vxs0t3hw) + j_vxs0t3hw) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_21ahhhe3 = 3;
                break;
            case 3:
                static volatile int64_t j_g74a8z83 = ((65182 + 18674) ^ (3887 ^ 3887));
                if ((((j_g74a8z83 * j_g74a8z83) + j_g74a8z83) < (0 + 0)))
                {
                    volatile int64_t j_vsv48048 = ((j_g74a8z83 * ((79 + 6) ^ (4658 ^ 4658))) + 856);
                    (void)printf("%s\n", ((0 + 0) ^ (2106 ^ 2106)) ? j_dc_30() : j_dc_31());
                }
                j_21ahhhe3 = (4 + 0);
                break;
            case 4:
                if ((j_6euxfluj < 2))
                {
                    return j_6euxfluj;
                }
                j_21ahhhe3 = 5;
                break;
            case 5:
                static volatile int64_t j_hg2beufw = ((6089 + 33068) ^ (8445 ^ 8445));
                if ((((j_hg2beufw * j_hg2beufw) + j_hg2beufw) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_21ahhhe3 = ((1 + 5) ^ (6849 ^ 6849));
                break;
            case 6:
                int32_t j_i66zt01p = (0 + 0);
                int32_t j_ospmyf0h = 1;
                int32_t j_mu5791fg = 2;
                while ((j_mu5791fg <= j_6euxfluj))
                {
                    int32_t j_urz8amwl = (j_i66zt01p + j_ospmyf0h);
                    j_i66zt01p = j_ospmyf0h;
                    j_ospmyf0h = j_urz8amwl;
                    j_mu5791fg = (j_mu5791fg + 1);
                }
                j_21ahhhe3 = ((7 + 0) ^ (4909 ^ 4909));
                break;
            case 7:
                return j_ospmyf0h;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_n49ux56p(int32_t j_6euxfluj)
{
    int32_t j_xef5gypb = 0;
    while ((j_xef5gypb != -1))
    {
        switch (j_xef5gypb)
        {
            case 0:
                static volatile int64_t j_y5asbtjo = ((31751 + 2859) ^ (9100 ^ 9100));
                static volatile int64_t j_62tmwofx = (5233 + 602);
                if ((((j_62tmwofx * j_62tmwofx) + j_62tmwofx) < 0))
                {
                    volatile int64_t j_9r0hu4z5 = ((j_62tmwofx * 94) + 835);
                    (void)printf("%s\n", (0 + 0) ? j_dc_34() : j_dc_35());
                }
                j_xef5gypb = 1;
                break;
            case 1:
                if ((((j_y5asbtjo * (j_y5asbtjo + 1)) % ((0 + 2) ^ (7621 ^ 7621))) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_36() : j_dc_37());
                }
                j_xef5gypb = 2;
                break;
            case 2:
                if ((j_6euxfluj < ((2 + 0) ^ (9127 ^ 9127))))
                {
                    return j_6euxfluj;
                }
                j_xef5gypb = 3;
                break;
            case 3:
                static volatile int64_t j_v14jdemq = (8761 + 61239);
                if ((((j_v14jdemq * j_v14jdemq) + j_v14jdemq) < (0 + 0)))
                {
                    volatile int64_t j_09cizgcp = ((j_v14jdemq * (63 + 13)) + ((0 + 0) ^ (7465 ^ 7465)));
                    (void)printf("%s\n", ((0 + 0) ^ (5580 ^ 5580)) ? j_dc_38() : j_dc_39());
                }
                j_xef5gypb = 4;
                break;
            case 4:
                static volatile int64_t j_xqd52eow = 12844;
                if ((((j_xqd52eow * j_xqd52eow) + j_xqd52eow) < 0))
                {
                    volatile int64_t j_3q4ei1h5 = ((j_xqd52eow * 78) + ((557 + 287) ^ (5171 ^ 5171)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_40() : j_dc_41());
                }
                j_xef5gypb = (1 + 4);
                break;
            case 5:
                return (j_n49ux56p((j_6euxfluj - (1 + 0))) + j_n49ux56p((j_6euxfluj - 2)));
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_xg1b6c1n(int32_t j_6euxfluj)
{
    int32_t j_ylegiqx7 = 0;
    while ((j_ylegiqx7 != -1))
    {
        switch (j_ylegiqx7)
        {
            case 0:
                static volatile int64_t j_a9w4oskl = (10637 + 13326);
                if ((((j_a9w4oskl * j_a9w4oskl) + j_a9w4oskl) < (0 + 0)))
                {
                    volatile int64_t j_250ezy55 = ((j_a9w4oskl * 3) + ((618 + 345) ^ (2067 ^ 2067)));
                    (void)printf("%s\n", ((0 + 0) ^ (1421 ^ 1421)) ? j_dc_42() : j_dc_43());
                }
                j_ylegiqx7 = 1;
                break;
            case 1:
                static volatile int64_t j_eh2w5xyw = ((27482 + 68989) ^ (6237 ^ 6237));
                if ((((j_eh2w5xyw * j_eh2w5xyw) + j_eh2w5xyw) < (0 + 0)))
                {
                    (void)printf("%s\n", 0 ? j_dc_44() : j_dc_45());
                }
                j_ylegiqx7 = 2;
                break;
            case 2:
                if ((j_6euxfluj <= 1))
                {
                    return ((1 + 0) ^ (7653 ^ 7653));
                }
                j_ylegiqx7 = ((3 + 0) ^ (3318 ^ 3318));
                break;
            case 3:
                static volatile int64_t j_l7ytm7y1 = (12042 + 31740);
                static volatile int64_t j_tt18d6dl = (6713 + 38418);
                if ((((j_tt18d6dl * j_tt18d6dl) + j_tt18d6dl) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_46() : j_dc_47());
                }
                j_ylegiqx7 = 4;
                break;
            case 4:
                if ((((j_l7ytm7y1 * (j_l7ytm7y1 + (1 + 0))) % ((2 + 0) ^ (103 ^ 103))) == 1))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (1401 ^ 1401)) ? j_dc_48() : j_dc_49());
                }
                j_ylegiqx7 = ((2 + 3) ^ (7457 ^ 7457));
                break;
            case 5:
                return (j_6euxfluj * j_xg1b6c1n((j_6euxfluj - 1)));
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_vu0yg17q(int32_t j_i66zt01p, int32_t j_ospmyf0h)
{
    int32_t j_alg1znte = 0;
    while ((j_alg1znte != -(0 + 1)))
    {
        switch (j_alg1znte)
        {
            case 0:
                static volatile int64_t j_zpit4y0w = 94871;
                if ((((j_zpit4y0w * j_zpit4y0w) + j_zpit4y0w) < ((0 + 0) ^ (4725 ^ 4725))))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_50() : j_dc_51());
                }
                j_alg1znte = 1;
                break;
            case 1:
                static volatile int64_t j_jc0hahjx = ((21216 + 7120) ^ (8752 ^ 8752));
                if ((((j_jc0hahjx * j_jc0hahjx) + j_jc0hahjx) < ((0 + 0) ^ (4641 ^ 4641))))
                {
                    volatile int64_t j_jps7thum = ((j_jc0hahjx * (5 + 13)) + (123 + 213));
                    (void)printf("%s\n", 0 ? j_dc_52() : j_dc_53());
                }
                j_alg1znte = (2 + 0);
                break;
            case 2:
                static volatile int64_t j_75m7hqw1 = 21251;
                static volatile int64_t j_oibjo05z = (4 + 1739);
                if ((((j_oibjo05z * j_oibjo05z) + j_oibjo05z) < 0))
                {
                    volatile int64_t j_ner6bds9 = ((j_oibjo05z * 84) + 743);
                    (void)printf("%s\n", 0 ? j_dc_54() : j_dc_55());
                }
                j_alg1znte = 3;
                break;
            case 3:
                if ((((j_75m7hqw1 * j_75m7hqw1) + j_75m7hqw1) < 0))
                {
                    volatile int64_t j_5otpwpur = ((j_75m7hqw1 * ((69 + 23) ^ (5781 ^ 5781))) + (184 + 67));
                    (void)printf("%s\n", ((0 + 0) ^ (5043 ^ 5043)) ? j_dc_56() : j_dc_57());
                }
                j_alg1znte = ((0 + 4) ^ (1433 ^ 1433));
                break;
            case 4:
                static volatile int64_t j_1j014eey = ((24095 + 13676) ^ (6116 ^ 6116));
                if ((((j_1j014eey * j_1j014eey) + j_1j014eey) < (0 + 0)))
                {
                    volatile int64_t j_132a8phh = ((j_1j014eey * ((57 + 23) ^ (9815 ^ 9815))) + (177 + 594));
                    (void)printf("%s\n", ((0 + 0) ^ (4564 ^ 4564)) ? j_dc_58() : j_dc_59());
                }
                j_alg1znte = 5;
                break;
            case 5:
                if ((j_ospmyf0h == (0 + 0)))
                {
                    return j_i66zt01p;
                }
                j_alg1znte = (1 + 5);
                break;
            case 6:
                return j_vu0yg17q(j_ospmyf0h, (j_i66zt01p % j_ospmyf0h));
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static bool j_1xkzpha6(int32_t j_6euxfluj)
{
    int32_t j_61t4slof = (0 + 0);
    while ((j_61t4slof != -1))
    {
        switch (j_61t4slof)
        {
            case 0:
                static volatile int64_t j_py3j5iei = 14764;
                if ((((j_py3j5iei * j_py3j5iei) + j_py3j5iei) < 0))
                {
                    volatile int64_t j_20piove4 = ((j_py3j5iei * (57 + 39)) + 764);
                    (void)printf("%s\n", (0 + 0) ? j_dc_60() : j_dc_61());
                }
                j_61t4slof = 1;
                break;
            case 1:
                if ((j_6euxfluj < ((1 + 1) ^ (8865 ^ 8865))))
                {
                    return false;
                }
                j_61t4slof = 2;
                break;
            case 2:
                static volatile int64_t j_lpq2z119 = 98416;
                if ((((j_lpq2z119 * (j_lpq2z119 + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (5861 ^ 5861)) ? j_dc_62() : j_dc_63());
                }
                j_61t4slof = ((0 + 3) ^ (1903 ^ 1903));
                break;
            case 3:
                static volatile int64_t j_clg0n0rl = ((38671 + 31719) ^ (2281 ^ 2281));
                if ((((j_clg0n0rl * j_clg0n0rl) + j_clg0n0rl) < ((0 + 0) ^ (6149 ^ 6149))))
                {
                    volatile int64_t j_t59q2vp7 = ((j_clg0n0rl * ((5 + 2) ^ (1525 ^ 1525))) + 390);
                    (void)printf("%s\n", 0 ? j_dc_64() : j_dc_65());
                }
                j_61t4slof = 4;
                break;
            case 4:
                int32_t j_mu5791fg = 2;
                static volatile int64_t j_xuomyzpd = ((5715 + 25641) ^ (2207 ^ 2207));
                if ((((j_xuomyzpd * (j_xuomyzpd + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (4232 ^ 4232)) ? j_dc_66() : j_dc_67());
                }
                j_61t4slof = 5;
                break;
            case 5:
                while (((j_mu5791fg * j_mu5791fg) <= j_6euxfluj))
                {
                    if (((j_6euxfluj % j_mu5791fg) == 0))
                    {
                        return false;
                    }
                    j_mu5791fg = (j_mu5791fg + 1);
                }
                j_61t4slof = ((1 + 5) ^ (262 ^ 262));
                break;
            case 6:
                static volatile int64_t j_1x9g18xm = (48238 + 43594);
                if ((((j_1x9g18xm * j_1x9g18xm) + j_1x9g18xm) < ((0 + 0) ^ (8571 ^ 8571))))
                {
                    volatile int64_t j_02ecq2wy = ((j_1x9g18xm * 89) + (440 + 392));
                    (void)printf("%s\n", 0 ? j_dc_68() : j_dc_69());
                }
                j_61t4slof = (0 + 7);
                break;
            case 7:
                return true;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_hrr5osqe(int32_t j_6euxfluj)
{
    int32_t j_n4ltdeug = (0 + 0);
    while ((j_n4ltdeug != -1))
    {
        switch (j_n4ltdeug)
        {
            case 0:
                int32_t j_d6yhtdtq = ((0 + 0) ^ (8216 ^ 8216));
                static volatile int64_t j_1lo5x4iu = 66230;
                if ((((j_1lo5x4iu * j_1lo5x4iu) + j_1lo5x4iu) < 0))
                {
                    volatile int64_t j_rows7ji1 = ((j_1lo5x4iu * (21 + 55)) + (105 + 125));
                    (void)printf("%s\n", (0 + 0) ? j_dc_70() : j_dc_71());
                }
                j_n4ltdeug = 1;
                break;
            case 1:
                static volatile int64_t j_tm4191cb = 40588;
                if ((((j_tm4191cb * j_tm4191cb) % 4) < ((0 + 2) ^ (5751 ^ 5751))))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (1340 ^ 1340)) ? j_dc_72() : j_dc_73());
                }
                j_n4ltdeug = (2 + 0);
                break;
            case 2:
                static volatile int64_t j_2yg0vujt = 716;
                if ((((j_2yg0vujt * j_2yg0vujt) + j_2yg0vujt) < 0))
                {
                    volatile int64_t j_51e9pr7a = ((j_2yg0vujt * 41) + 716);
                    (void)printf("%s\n", 0 ? j_dc_74() : j_dc_75());
                }
                j_n4ltdeug = 3;
                break;
            case 3:
                int32_t j_pqtv7ww3 = j_6euxfluj;
                static volatile int64_t j_apqebcyo = ((33952 + 3280) ^ (2190 ^ 2190));
                if ((((j_apqebcyo * j_apqebcyo) + j_apqebcyo) < (0 + 0)))
                {
                    volatile int64_t j_zvt1ulm2 = ((j_apqebcyo * 23) + ((154 + 78) ^ (2855 ^ 2855)));
                    (void)printf("%s\n", 0 ? j_dc_76() : j_dc_77());
                }
                j_n4ltdeug = 4;
                break;
            case 4:
                static volatile int64_t j_m5b77shp = (14261 + 80554);
                if ((((j_m5b77shp * j_m5b77shp) + j_m5b77shp) < 0))
                {
                    volatile int64_t j_xbzjzg8e = ((j_m5b77shp * 86) + (689 + 126));
                    (void)printf("%s\n", (0 + 0) ? j_dc_78() : j_dc_79());
                }
                j_n4ltdeug = (1 + 4);
                break;
            case 5:
                while ((j_pqtv7ww3 != 1))
                {
                    if (((j_pqtv7ww3 % ((0 + 2) ^ (695 ^ 695))) == 0))
                    {
                        j_pqtv7ww3 = (j_pqtv7ww3 / (1 + 1));
                    }
                    else
                    {
                        j_pqtv7ww3 = ((j_pqtv7ww3 * 3) + 1);
                    }
                    j_d6yhtdtq = (j_d6yhtdtq + (0 + 1));
                }
                j_n4ltdeug = (6 + 0);
                break;
            case 6:
                return j_d6yhtdtq;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_g9x5rzlj(int32_t j_6euxfluj)
{
    int32_t j_kgw3i0s4 = 0;
    while ((j_kgw3i0s4 != -1))
    {
        switch (j_kgw3i0s4)
        {
            case 0:
                int32_t j_he417enk = 0;
                static volatile int64_t j_hcmrdfmc = 62070;
                if ((((j_hcmrdfmc * j_hcmrdfmc) + j_hcmrdfmc) < (0 + 0)))
                {
                    volatile int64_t j_e2wqoec4 = ((j_hcmrdfmc * ((26 + 7) ^ (9296 ^ 9296))) + ((2 + 68) ^ (2190 ^ 2190)));
                    (void)printf("%s\n", ((0 + 0) ^ (684 ^ 684)) ? j_dc_80() : j_dc_81());
                }
                j_kgw3i0s4 = 1;
                break;
            case 1:
                int32_t j_8n538ums = j_6euxfluj;
                while ((j_8n538ums > ((0 + 0) ^ (8815 ^ 8815))))
                {
                    j_he417enk = (j_he417enk + (j_8n538ums % 10));
                    j_8n538ums = (j_8n538ums / 10);
                }
                j_kgw3i0s4 = (0 + 2);
                break;
            case 2:
                return j_he417enk;
                break;
            case 3:
                static volatile int64_t j_nxir391i = 78740;
                if ((((j_nxir391i * j_nxir391i) + j_nxir391i) < 0))
                {
                    volatile int64_t j_cwnx57gc = ((j_nxir391i * ((74 + 3) ^ (4874 ^ 4874))) + 740);
                    (void)printf("%s\n", 0 ? j_dc_82() : j_dc_83());
                }
                j_kgw3i0s4 = 4;
                break;
            case 4:
                static volatile int64_t j_xqm36v3g = ((16289 + 5351) ^ (9784 ^ 9784));
                static volatile int64_t j_o4jhhczq = 82769;
                if ((((j_o4jhhczq * j_o4jhhczq) % 4) < (1 + 1)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_84() : j_dc_85());
                }
                j_kgw3i0s4 = ((0 + 5) ^ (1487 ^ 1487));
                break;
            case 5:
                if ((((j_xqm36v3g * (j_xqm36v3g + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (1188 ^ 1188)) ? j_dc_86() : j_dc_87());
                }
                j_kgw3i0s4 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_cznb8aac(int32_t j_6euxfluj)
{
    int32_t j_vj4cu3fz = (0 + 0);
    while ((j_vj4cu3fz != -(0 + 1)))
    {
        switch (j_vj4cu3fz)
        {
            case 0:
                if ((j_6euxfluj < 0))
                {
                    return -(j_cznb8aac(-(j_6euxfluj)));
                }
                j_vj4cu3fz = 1;
                break;
            case 1:
                int32_t j_gabsbvd3 = ((0 + 0) ^ (9235 ^ 9235));
                int32_t j_8n538ums = j_6euxfluj;
                while ((j_8n538ums > 0))
                {
                    j_gabsbvd3 = ((j_gabsbvd3 * ((9 + 1) ^ (5594 ^ 5594))) + (j_8n538ums % 10));
                    j_8n538ums = (j_8n538ums / 10);
                }
                j_vj4cu3fz = ((2 + 0) ^ (117 ^ 117));
                break;
            case 2:
                static volatile int64_t j_tfl3qilm = ((17468 + 75721) ^ (5852 ^ 5852));
                if ((((j_tfl3qilm * j_tfl3qilm) + j_tfl3qilm) < (0 + 0)))
                {
                    volatile int64_t j_yjfwzqbw = ((j_tfl3qilm * 97) + 189);
                    (void)printf("%s\n", (0 + 0) ? j_dc_88() : j_dc_89());
                }
                j_vj4cu3fz = 3;
                break;
            case 3:
                static volatile int64_t j_99ij4lay = ((90563 + 5298) ^ (7088 ^ 7088));
                if ((((j_99ij4lay * j_99ij4lay) + j_99ij4lay) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_90() : j_dc_91());
                }
                j_vj4cu3fz = 4;
                break;
            case 4:
                return j_gabsbvd3;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_xad10s9i(int32_t j_6c6x6f0a, int32_t j_l08o3mnd)
{
    int32_t j_0xr20z3t = 0;
    while ((j_0xr20z3t != -1))
    {
        switch (j_0xr20z3t)
        {
            case 0:
                int32_t j_wmvosp3p = (1 + 0);
                int32_t j_mu5791fg = ((0 + 0) ^ (8691 ^ 8691));
                while ((j_mu5791fg < j_l08o3mnd))
                {
                    j_wmvosp3p = (j_wmvosp3p * j_6c6x6f0a);
                    j_mu5791fg = (j_mu5791fg + (1 + 0));
                }
                j_0xr20z3t = ((0 + 1) ^ (5530 ^ 5530));
                break;
            case 1:
                return j_wmvosp3p;
                break;
            case 2:
                static volatile int64_t j_beyesr1v = (16581 + 36046);
                static volatile int64_t j_ynaogdwf = 32186;
                static volatile int64_t j_iuj2w0gx = ((25048 + 3009) ^ (1770 ^ 1770));
                static volatile int64_t j_rkpa0mhc = ((8715 + 2226) ^ (1309 ^ 1309));
                if ((((j_rkpa0mhc * j_rkpa0mhc) + j_rkpa0mhc) < ((0 + 0) ^ (1887 ^ 1887))))
                {
                    volatile int64_t j_ceq71p6t = ((j_rkpa0mhc * ((32 + 7) ^ (2424 ^ 2424))) + 941);
                    (void)printf("%s\n", (0 + 0) ? j_dc_92() : j_dc_93());
                }
                j_0xr20z3t = 3;
                break;
            case 3:
                if ((((j_iuj2w0gx * j_iuj2w0gx) + j_iuj2w0gx) < ((0 + 0) ^ (4859 ^ 4859))))
                {
                    volatile int64_t j_h2t00ozk = ((j_iuj2w0gx * ((38 + 11) ^ (9542 ^ 9542))) + 57);
                    (void)printf("%s\n", (0 + 0) ? j_dc_94() : j_dc_95());
                }
                j_0xr20z3t = 4;
                break;
            case 4:
                if ((((j_ynaogdwf * j_ynaogdwf) + j_ynaogdwf) < (0 + 0)))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_96() : j_dc_97());
                }
                j_0xr20z3t = 5;
                break;
            case 5:
                static volatile int64_t j_b9ek4v6n = 98004;
                if ((((j_b9ek4v6n * j_b9ek4v6n) + j_b9ek4v6n) < (0 + 0)))
                {
                    (void)printf("%s\n", 0 ? j_dc_98() : j_dc_99());
                }
                j_0xr20z3t = (5 + 1);
                break;
            case 6:
                if ((((j_beyesr1v * j_beyesr1v) + j_beyesr1v) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_100() : j_dc_101());
                }
                j_0xr20z3t = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_p56139q7(int32_t j_i66zt01p, int32_t j_ospmyf0h, int32_t j_9jzx6pkp)
{
    int32_t j_llh8aelw = 0;
    while ((j_llh8aelw != -(0 + 1)))
    {
        switch (j_llh8aelw)
        {
            case 0:
                if (((j_i66zt01p >= j_ospmyf0h) && (j_i66zt01p >= j_9jzx6pkp)))
                {
                    return j_i66zt01p;
                }
                j_llh8aelw = 1;
                break;
            case 1:
                static volatile int64_t j_guoffkmx = 21522;
                static volatile int64_t j_axibmt6n = (27180 + 32281);
                if ((((j_axibmt6n * j_axibmt6n) + j_axibmt6n) < 0))
                {
                    volatile int64_t j_cfod56e8 = ((j_axibmt6n * ((69 + 8) ^ (9471 ^ 9471))) + (294 + 167));
                    (void)printf("%s\n", (0 + 0) ? j_dc_102() : j_dc_103());
                }
                j_llh8aelw = ((2 + 0) ^ (9768 ^ 9768));
                break;
            case 2:
                if ((((j_guoffkmx * j_guoffkmx) + j_guoffkmx) < 0))
                {
                    volatile int64_t j_z67vkc16 = ((j_guoffkmx * ((5 + 4) ^ (1780 ^ 1780))) + ((452 + 70) ^ (9679 ^ 9679)));
                    (void)printf("%s\n", 0 ? j_dc_104() : j_dc_105());
                }
                j_llh8aelw = ((2 + 1) ^ (8115 ^ 8115));
                break;
            case 3:
                static volatile int64_t j_0iisfg2l = ((79593 + 4612) ^ (8359 ^ 8359));
                if ((((j_0iisfg2l * j_0iisfg2l) + j_0iisfg2l) < 0))
                {
                    volatile int64_t j_nqx0bbjr = ((j_0iisfg2l * 52) + ((22 + 183) ^ (8100 ^ 8100)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_106() : j_dc_107());
                }
                j_llh8aelw = ((4 + 0) ^ (1186 ^ 1186));
                break;
            case 4:
                if (((j_ospmyf0h >= j_i66zt01p) && (j_ospmyf0h >= j_9jzx6pkp)))
                {
                    return j_ospmyf0h;
                }
                j_llh8aelw = (0 + 5);
                break;
            case 5:
                static volatile int64_t j_ard2v141 = (5458 + 33551);
                static volatile int64_t j_jhvttzse = 51982;
                if ((((j_jhvttzse * j_jhvttzse) + j_jhvttzse) < 0))
                {
                    volatile int64_t j_40u0p3ey = ((j_jhvttzse * 56) + 982);
                    (void)printf("%s\n", 0 ? j_dc_108() : j_dc_109());
                }
                j_llh8aelw = 6;
                break;
            case 6:
                if ((((j_ard2v141 * j_ard2v141) + j_ard2v141) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (553 ^ 553)) ? j_dc_110() : j_dc_111());
                }
                j_llh8aelw = (7 + 0);
                break;
            case 7:
                return j_9jzx6pkp;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_6j95do8d(int32_t j_i66zt01p, int32_t j_ospmyf0h, int32_t j_9jzx6pkp)
{
    int32_t j_lsij4bis = (0 + 0);
    while ((j_lsij4bis != -((1 + 0) ^ (7419 ^ 7419))))
    {
        switch (j_lsij4bis)
        {
            case 0:
                static volatile int64_t j_o0bquczh = 38111;
                if ((((j_o0bquczh * j_o0bquczh) + j_o0bquczh) < (0 + 0)))
                {
                    volatile int64_t j_mm07z5d7 = ((j_o0bquczh * (4 + 1)) + (42 + 69));
                    (void)printf("%s\n", 0 ? j_dc_112() : j_dc_113());
                }
                j_lsij4bis = 1;
                break;
            case 1:
                if (((j_i66zt01p <= j_ospmyf0h) && (j_i66zt01p <= j_9jzx6pkp)))
                {
                    return j_i66zt01p;
                }
                j_lsij4bis = 2;
                break;
            case 2:
                static volatile int64_t j_i8h5dxg1 = 73324;
                if ((((j_i8h5dxg1 * j_i8h5dxg1) + j_i8h5dxg1) < (0 + 0)))
                {
                    volatile int64_t j_zhe99m3f = ((j_i8h5dxg1 * 8) + (57 + 267));
                    (void)printf("%s\n", ((0 + 0) ^ (4975 ^ 4975)) ? j_dc_114() : j_dc_115());
                }
                j_lsij4bis = 3;
                break;
            case 3:
                static volatile int64_t j_5c0ic5gp = (27466 + 67058);
                if ((((j_5c0ic5gp * j_5c0ic5gp) + j_5c0ic5gp) < (0 + 0)))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (3426 ^ 3426)) ? j_dc_116() : j_dc_117());
                }
                j_lsij4bis = (3 + 1);
                break;
            case 4:
                if (((j_ospmyf0h <= j_i66zt01p) && (j_ospmyf0h <= j_9jzx6pkp)))
                {
                    return j_ospmyf0h;
                }
                j_lsij4bis = (5 + 0);
                break;
            case 5:
                return j_9jzx6pkp;
                break;
            case 6:
                static volatile int64_t j_l11kurqw = (51636 + 40049);
                if ((((j_l11kurqw * j_l11kurqw) + j_l11kurqw) < (0 + 0)))
                {
                    volatile int64_t j_ksv9hbhy = ((j_l11kurqw * 17) + (359 + 326));
                    (void)printf("%s\n", 0 ? j_dc_118() : j_dc_119());
                }
                j_lsij4bis = 7;
                break;
            case 7:
                static volatile int64_t j_ae7fpe7g = ((27449 + 40934) ^ (6717 ^ 6717));
                if ((((j_ae7fpe7g * j_ae7fpe7g) + j_ae7fpe7g) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_120() : j_dc_121());
                }
                j_lsij4bis = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static bool j_g396e7d4(int32_t j_6euxfluj)
{
    int32_t j_bd928pje = 0;
    while ((j_bd928pje != -((0 + 1) ^ (8004 ^ 8004))))
    {
        switch (j_bd928pje)
        {
            case 0:
                static volatile int64_t j_7jga1j9f = ((31147 + 3220) ^ (7685 ^ 7685));
                static volatile int64_t j_vgw16dig = ((19215 + 79548) ^ (1369 ^ 1369));
                if ((((j_vgw16dig * j_vgw16dig) + j_vgw16dig) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (8845 ^ 8845)) ? j_dc_122() : j_dc_123());
                }
                j_bd928pje = ((1 + 0) ^ (7544 ^ 7544));
                break;
            case 1:
                static volatile int64_t j_e7f0m5s5 = (34338 + 2980);
                if ((((j_e7f0m5s5 * (j_e7f0m5s5 + (1 + 0))) % 2) == (0 + 1)))
                {
                    (void)printf("%s\n", 0 ? j_dc_124() : j_dc_125());
                }
                j_bd928pje = (0 + 2);
                break;
            case 2:
                static volatile int64_t j_n41w8h63 = 23647;
                static volatile int64_t j_fw05477e = 34659;
                if ((((j_fw05477e * j_fw05477e) + j_fw05477e) < 0))
                {
                    volatile int64_t j_rf1o0h9j = ((j_fw05477e * 42) + 659);
                    (void)printf("%s\n", 0 ? j_dc_126() : j_dc_127());
                }
                j_bd928pje = 3;
                break;
            case 3:
                if ((((j_n41w8h63 * j_n41w8h63) + j_n41w8h63) < ((0 + 0) ^ (5370 ^ 5370))))
                {
                    volatile int64_t j_zt8for68 = ((j_n41w8h63 * 45) + 647);
                    (void)printf("%s\n", 0 ? j_dc_128() : j_dc_129());
                }
                j_bd928pje = (3 + 1);
                break;
            case 4:
                static volatile int64_t j_p8s3419v = (64737 + 22330);
                if ((((j_p8s3419v * j_p8s3419v) + j_p8s3419v) < ((0 + 0) ^ (5477 ^ 5477))))
                {
                    volatile int64_t j_ritgioh9 = ((j_p8s3419v * ((0 + 3) ^ (1558 ^ 1558))) + ((20 + 47) ^ (8400 ^ 8400)));
                    (void)printf("%s\n", 0 ? j_dc_130() : j_dc_131());
                }
                j_bd928pje = ((1 + 4) ^ (1366 ^ 1366));
                break;
            case 5:
                if ((((j_7jga1j9f * j_7jga1j9f) % ((0 + 4) ^ (2493 ^ 2493))) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (5748 ^ 5748)) ? j_dc_132() : j_dc_133());
                }
                j_bd928pje = 6;
                break;
            case 6:
                return (j_6euxfluj == j_cznb8aac(j_6euxfluj));
                break;
            case 7:
                static volatile int64_t j_a3j18zaf = ((69730 + 386) ^ (8899 ^ 8899));
                if ((((j_a3j18zaf * j_a3j18zaf) + j_a3j18zaf) < 0))
                {
                    volatile int64_t j_912x0v9n = ((j_a3j18zaf * ((19 + 53) ^ (9729 ^ 9729))) + 116);
                    (void)printf("%s\n", 0 ? j_dc_134() : j_dc_135());
                }
                j_bd928pje = -(0 + 1);
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

__attribute__((used)) static int32_t j_z_vbxa3z(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (728 ^ 728));
    while (j_t < j_b) {
        j_r = (j_r * (16 + 15) + j_c) % (867 + 9140);
        j_t = j_t + ((1 + 0) ^ (5789 ^ 5789));
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_scsp2i(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = (0 + 0);
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % (4521 + 5486);
        j_t = j_t + (1 + 0);
    }
    return j_r;
}

static int32_t j_tr_khv5jb(void) {
    int32_t j_zwnc54g6 = 0;
    while ((j_zwnc54g6 != -(0 + 1)))
    {
        switch (j_zwnc54g6)
        {
            case 0:
                (void)printf("%s\n", j_dc_136());
                static volatile int64_t j_dj4sh6dz = ((23982 + 15635) ^ (9546 ^ 9546));
                if ((((j_dj4sh6dz * j_dj4sh6dz) + j_dj4sh6dz) < (0 + 0)))
                {
                    volatile int64_t j_zezoft77 = ((j_dj4sh6dz * 15) + 617);
                    (void)printf("%s\n", 0 ? j_dc_137() : j_dc_138());
                }
                j_zwnc54g6 = 1;
                break;
            case 1:
                static volatile int64_t j_ezqznmz9 = (12215 + 28177);
                if ((((j_ezqznmz9 * j_ezqznmz9) + j_ezqznmz9) >= ((0 + 0) ^ (7285 ^ 7285))))
                {
                    (void)printf("%d\n", j_6gssa7uj(((0 + 0) ^ (581 ^ 581))));
                }
                else
                {
                    volatile int64_t j_t1s8h93o = ((j_ezqznmz9 * 2) + ((1 + 0) ^ (6331 ^ 6331)));
                }
                j_zwnc54g6 = (0 + 2);
                break;
            case 2:
                (void)printf("%d\n", j_6gssa7uj(1));
                (void)printf("%d\n", j_6gssa7uj(10));
                (void)printf("%d\n", j_6gssa7uj((13 + 7)));
                (void)printf("%s\n", j_dc_139());
                static volatile int64_t j_6u4zt17y = 48195;
                if ((((j_6u4zt17y * j_6u4zt17y) + j_6u4zt17y) >= 0))
                {
                    (void)printf("%d\n", j_n49ux56p((0 + 0)));
                }
                else
                {
                    volatile int64_t j_wpqfqqz5 = ((j_6u4zt17y * 2) + (1 + 0));
                }
                j_zwnc54g6 = ((0 + 3) ^ (1557 ^ 1557));
                break;
            case 3:
                static volatile int64_t j_gheemppo = ((4084 + 142) ^ (4299 ^ 4299));
                if ((((j_gheemppo * j_gheemppo) + j_gheemppo) >= 0))
                {
                    (void)printf("%d\n", j_n49ux56p((1 + 0)));
                }
                else
                {
                    volatile int64_t j_zhjil9me = ((j_gheemppo * 2) + (0 + 1));
                }
                j_zwnc54g6 = (2 + 2);
                break;
            case 4:
                static volatile int64_t j_0fxdfluu = ((32449 + 34368) ^ (3633 ^ 3633));
                if ((((j_0fxdfluu * j_0fxdfluu) + j_0fxdfluu) >= (0 + 0)))
                {
                    (void)printf("%d\n", j_n49ux56p(10));
                }
                else
                {
                    volatile int64_t j_rxstsghw = ((j_0fxdfluu * (1 + 1)) + (0 + 1));
                }
                j_zwnc54g6 = (5 + 0);
                break;
            case 5:
                static volatile int64_t j_8mrz9qrv = (16563 + 39666);
                if ((((j_8mrz9qrv * j_8mrz9qrv) + j_8mrz9qrv) < 0))
                {
                    volatile int64_t j_3zyorchx = ((j_8mrz9qrv * 21) + 229);
                    (void)printf("%s\n", 0 ? j_dc_140() : j_dc_141());
                }
                j_zwnc54g6 = (6 + 0);
                break;
            case 6:
                static volatile int64_t j_rfq06xoi = ((17202 + 20198) ^ (3100 ^ 3100));
                if ((((j_rfq06xoi * j_rfq06xoi) + j_rfq06xoi) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (3730 ^ 3730)) ? j_dc_142() : j_dc_143());
                }
                j_zwnc54g6 = 7;
                break;
            case 7:
                (void)printf("%s\n", j_dc_144());
                (void)printf("%d\n", j_xg1b6c1n(0));
                (void)printf("%d\n", j_xg1b6c1n(5));
                (void)printf("%d\n", j_xg1b6c1n((6 + 2)));
                static volatile int64_t j_b6q3vtlg = ((4613 + 22473) ^ (7552 ^ 7552));
                if ((((j_b6q3vtlg * j_b6q3vtlg) + j_b6q3vtlg) >= 0))
                {
                    (void)printf("%s\n", j_dc_145());
                }
                else
                {
                    volatile int64_t j_a5zaogt1 = ((j_b6q3vtlg * 2) + ((1 + 0) ^ (8363 ^ 8363)));
                }
                j_zwnc54g6 = ((7 + 1) ^ (9185 ^ 9185));
                break;
            case 8:
                (void)printf("%d\n", j_vu0yg17q(48, 36));
                static volatile int64_t j_71dduxm9 = (24992 + 68063);
                if ((((j_71dduxm9 * j_71dduxm9) + j_71dduxm9) >= ((0 + 0) ^ (7194 ^ 7194))))
                {
                    (void)printf("%d\n", j_vu0yg17q(17, (3 + 2)));
                }
                else
                {
                    volatile int64_t j_luencyqy = ((j_71dduxm9 * ((1 + 1) ^ (8786 ^ 8786))) + (0 + 1));
                }
                j_zwnc54g6 = (1 + 8);
                break;
            case 9:
                (void)printf("%d\n", j_vu0yg17q(((44 + 56) ^ (8414 ^ 8414)), ((7 + 3) ^ (3454 ^ 3454))));
                static volatile int64_t j_w64pivru = 84539;
                if ((((j_w64pivru * j_w64pivru) + j_w64pivru) >= (0 + 0)))
                {
                    (void)printf("%s\n", j_dc_146());
                }
                else
                {
                    volatile int64_t j_nb4bont7 = ((j_w64pivru * ((0 + 2) ^ (8746 ^ 8746))) + (1 + 0));
                }
                j_zwnc54g6 = 10;
                break;
            case 10:
                (void)printf("%s\n", j_1xkzpha6(2) ? j_dc_147() : j_dc_148());
                (void)printf("%s\n", j_1xkzpha6(17) ? j_dc_149() : j_dc_150());
                (void)printf("%s\n", j_1xkzpha6(18) ? j_dc_151() : j_dc_152());
                (void)printf("%s\n", j_1xkzpha6(((64 + 33) ^ (7709 ^ 7709))) ? j_dc_153() : j_dc_154());
                (void)printf("%s\n", j_dc_155());
                for (int32_t j_mu5791fg = ((0 + 2) ^ (9329 ^ 9329)); (j_mu5791fg <= 30); j_mu5791fg = (j_mu5791fg + 1))
                {
                    if (j_1xkzpha6(j_mu5791fg))
                    {
                        (void)printf("%d\n", j_mu5791fg);
                    }
                }
                j_zwnc54g6 = ((11 + 0) ^ (7201 ^ 7201));
                break;
            case 11:
                (void)printf("%s\n", j_dc_156());
                (void)printf("%d\n", j_hrr5osqe(1));
                (void)printf("%d\n", j_hrr5osqe(((24 + 3) ^ (6758 ^ 6758))));
                (void)printf("%d\n", j_hrr5osqe((1 + 5)));
                (void)printf("%s\n", j_dc_157());
                static volatile int64_t j_dikxl147 = ((9350 + 63910) ^ (8854 ^ 8854));
                if ((((j_dikxl147 * j_dikxl147) + j_dikxl147) >= ((0 + 0) ^ (4379 ^ 4379))))
                {
                    (void)printf("%d\n", j_g9x5rzlj(0));
                }
                else
                {
                    volatile int64_t j_y7di46zt = ((j_dikxl147 * (0 + 2)) + 1);
                }
                j_zwnc54g6 = (12 + 0);
                break;
            case 12:
                (void)printf("%d\n", j_g9x5rzlj((10886 + 1459)));
                (void)printf("%d\n", j_g9x5rzlj((275 + 724)));
                static volatile int64_t j_8mxjmdzn = 31523;
                if ((((j_8mxjmdzn * j_8mxjmdzn) + j_8mxjmdzn) < ((0 + 0) ^ (1565 ^ 1565))))
                {
                    (void)printf("%s\n", 0 ? j_dc_158() : j_dc_159());
                }
                j_zwnc54g6 = ((0 + 13) ^ (2745 ^ 2745));
                break;
            case 13:
                (void)printf("%s\n", j_dc_160());
                static volatile int64_t j_zb3tjste = 86848;
                if ((((j_zb3tjste * j_zb3tjste) % 4) < (1 + 1)))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (1842 ^ 1842)) ? j_dc_161() : j_dc_162());
                }
                j_zwnc54g6 = ((8 + 6) ^ (6367 ^ 6367));
                break;
            case 14:
                (void)printf("%d\n", j_cznb8aac(((7994 + 4351) ^ (7902 ^ 7902))));
                (void)printf("%d\n", j_cznb8aac(-(123)));
                (void)printf("%d\n", j_cznb8aac(((6 + 1) ^ (2052 ^ 2052))));
                static volatile int64_t j_6mj0dl2a = ((64311 + 303) ^ (8093 ^ 8093));
                if ((((j_6mj0dl2a * j_6mj0dl2a) + j_6mj0dl2a) >= ((0 + 0) ^ (8246 ^ 8246))))
                {
                    (void)printf("%s\n", j_dc_163());
                }
                else
                {
                    volatile int64_t j_60wifs0x = ((j_6mj0dl2a * (0 + 2)) + 1);
                }
                j_zwnc54g6 = (5 + 10);
                break;
            case 15:
                (void)printf("%d\n", j_xad10s9i(2, 10));
                static volatile int64_t j_4mdasgc8 = 49694;
                if ((((j_4mdasgc8 * j_4mdasgc8) + j_4mdasgc8) >= 0))
                {
                    (void)printf("%d\n", j_xad10s9i(((2 + 1) ^ (1394 ^ 1394)), ((1 + 2) ^ (155 ^ 155))));
                }
                else
                {
                    volatile int64_t j_lo6rnk00 = ((j_4mdasgc8 * ((2 + 0) ^ (1883 ^ 1883))) + 1);
                }
                j_zwnc54g6 = ((3 + 13) ^ (2902 ^ 2902));
                break;
            case 16:
                (void)printf("%d\n", j_xad10s9i(5, ((0 + 0) ^ (2206 ^ 2206))));
                (void)printf("%s\n", j_dc_164());
                (void)printf("%d\n", j_p56139q7(3, ((5 + 4) ^ (8111 ^ 8111)), 6));
                (void)printf("%d\n", j_6j95do8d(((0 + 3) ^ (5393 ^ 5393)), ((9 + 0) ^ (7176 ^ 7176)), ((4 + 2) ^ (6420 ^ 6420))));
                (void)printf("%d\n", j_p56139q7(-(5), -(((0 + 1) ^ (9548 ^ 9548))), -(3)));
                (void)printf("%s\n", j_dc_165());
                (void)printf("%s\n", j_g396e7d4(121) ? j_dc_166() : j_dc_167());
                (void)printf("%s\n", j_g396e7d4(((7800 + 4521) ^ (7071 ^ 7071))) ? j_dc_168() : j_dc_169());
                (void)printf("%s\n", j_g396e7d4(((22 + 101) ^ (1175 ^ 1175))) ? j_dc_170() : j_dc_171());
                j_zwnc54g6 = -(1 + 0);
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}
static int32_t j_tr_ov70na(void) { return j_tr_khv5jb(); }
static int32_t j_tr_f2y9g1(void) { return j_tr_ov70na(); }
static int32_t j_tr_p29y2w(void) { return j_tr_f2y9g1(); }
int32_t main(void) { return j_tr_p29y2w(); }

