// JOCKY build 5B8D9F1BE2220CBA seed=12345 date=2026-09-03 05:00:05
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

static const volatile uint8_t j_enc_0[] = {0x13, 0x12, 0x11, 0x10, 0x17, 0x16, 0x15, 0x14, 0x1B, 0x1A, 0x42, 0x41, 0x40, 0x47, 0x46, 0x45};
static const char* j_dc_0(void) {
    static char j_rb[(6 + 11)];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ ((13 + 22) ^ (7781 ^ 7781));
    j_rb[((8 + 8) ^ (3660 ^ 3660))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ (13 + 5);
    j_rb[(15 + 1)] = ((0 + 0) ^ (8576 ^ 8576));
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xBA, 0xAA};
static const char* j_dc_2(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = ((0 + 0) ^ (2295 ^ 2295)); j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 200;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x58, 0x4D};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < (2 + 0); j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 47;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xDC, 0x83, 0x81, 0x9C, 0x90};
static const char* j_dc_4(void) {
    static char j_rb[((0 + 6) ^ (5428 ^ 5428))];
    for (int j_i = ((0 + 0) ^ (6261 ^ 6261)); j_i < ((3 + 2) ^ (7774 ^ 7774)); j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 243;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDB};
static const char* j_dc_5(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = (0 + 0); j_i < ((0 + 1) ^ (166 ^ 166)); j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 169;
    j_rb[1] = ((0 + 0) ^ (3853 ^ 3853));
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x64};
static const char* j_dc_6(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = 0; j_i < ((0 + 1) ^ (5671 ^ 5671)); j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 110;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8E};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (1 + 0); j_i++) j_rb[j_i] = j_enc_7[j_i] ^ ((194 + 58) ^ (6757 ^ 6757));
    j_rb[(1 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x5F};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 96;
    j_rb[((1 + 0) ^ (9568 ^ 9568))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xDD, 0xD8, 0xC2, 0xC5, 0xD4, 0xDF};
static const char* j_dc_9(void) {
    static char j_rb[((2 + 5) ^ (1230 ^ 1230))];
    for (int j_i = 0; j_i < ((2 + 4) ^ (3360 ^ 3360)); j_i++) j_rb[j_i] = j_enc_9[j_i] ^ (109 + 36);
    j_rb[6] = ((0 + 0) ^ (2023 ^ 2023));
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x71, 0x67, 0x60, 0x75, 0x76, 0x78, 0x7D, 0x67, 0x7C, 0x71, 0x70};
static const char* j_dc_10(void) {
    static char j_rb[(2 + 10)];
    for (int j_i = ((0 + 0) ^ (5566 ^ 5566)); j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 52;
    j_rb[((4 + 7) ^ (4889 ^ 4889))] = ((0 + 0) ^ (8617 ^ 8617));
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x82, 0x8D, 0x8E, 0x92, 0x84, 0x9E, 0x96, 0x80, 0x88, 0x95};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = ((0 + 0) ^ (1785 ^ 1785)); j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 193;
    j_rb[10] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x36, 0x2B, 0x2F, 0x27, 0x3D, 0x35, 0x23, 0x2B, 0x36};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = ((0 + 0) ^ (2605 ^ 2605)); j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 98;
    j_rb[(6 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0B, 0x10, 0x0C, 0x01, 0x16};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 68;
    j_rb[5] = ((0 + 0) ^ (6414 ^ 6414));
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x3C, 0x37, 0x26, 0x21, 0x26, 0x33, 0x26, 0x72, 0x7F, 0x33, 0x3C, 0x72, 0x7F, 0x22, 0x72, 0x26, 0x31, 0x22, 0x72, 0x60, 0x6C, 0x7D, 0x36, 0x37, 0x24, 0x7D, 0x3C, 0x27, 0x3E, 0x3E};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < (11 + 19); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ (44 + 38);
    j_rb[30] = ((0 + 0) ^ (6210 ^ 6210));
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x92};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = ((0 + 0) ^ (9399 ^ 9399)); j_i < (1 + 0); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ ((6 + 218) ^ (1846 ^ 1846));
    j_rb[1] = ((0 + 0) ^ (8125 ^ 8125));
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x80, 0x97, 0x84};
static const char* j_dc_16(void) {
    static char j_rb[(4 + 0)];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ (53 + 191);
    j_rb[3] = ((0 + 0) ^ (4553 ^ 4553));
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xE6, 0xB9, 0xBB, 0xA6, 0xAA, 0xE6, 0xA7, 0xAC, 0xBD, 0xE6, 0xBD, 0xAA, 0xB9};
static const char* j_dc_17(void) {
    static char j_rb[((1 + 13) ^ (2889 ^ 2889))];
    for (int j_i = 0; j_i < ((13 + 0) ^ (9824 ^ 9824)); j_i++) j_rb[j_i] = j_enc_17[j_i] ^ (191 + 10);
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x04, 0x5B, 0x59, 0x44, 0x48, 0x04, 0x45, 0x4E, 0x5F, 0x04, 0x5F, 0x48, 0x5B, 0x1D};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < (7 + 7); j_i++) j_rb[j_i] = j_enc_18[j_i] ^ ((40 + 3) ^ (8836 ^ 8836));
    j_rb[((10 + 4) ^ (449 ^ 449))] = ((0 + 0) ^ (6928 ^ 6928));
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xA3, 0xA0, 0xA7, 0xA6, 0xB7};
static const char* j_dc_19(void) {
    static char j_rb[((5 + 1) ^ (8273 ^ 8273))];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_19[j_i] ^ ((198 + 37) ^ (1017 ^ 1017));
    j_rb[((4 + 1) ^ (2476 ^ 2476))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x36, 0x35, 0x3D, 0x2B, 0x22};
static const char* j_dc_20(void) {
    static char j_rb[((1 + 5) ^ (4169 ^ 4169))];
    for (int j_i = (0 + 0); j_i < ((3 + 2) ^ (2384 ^ 2384)); j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 126;
    j_rb[((2 + 3) ^ (2885 ^ 2885))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x1A, 0x19, 0x11, 0x00, 0x0E};
static const char* j_dc_21(void) {
    static char j_rb[((6 + 0) ^ (951 ^ 951))];
    for (int j_i = ((0 + 0) ^ (95 ^ 95)); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ (57 + 25);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x29, 0x2A, 0x34, 0x3D};
static const char* j_dc_22(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_22[j_i] ^ ((19 + 78) ^ (3956 ^ 3956));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xF1, 0xE4};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 134;
    j_rb[(2 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xD6, 0xD6, 0xCB, 0x98, 0x92, 0x98, 0xC5, 0x85, 0x84, 0x9C, 0xC3, 0xC2, 0xCB, 0xD6, 0xD6};
static const char* j_dc_24(void) {
    static char j_rb[16];
    for (int j_i = ((0 + 0) ^ (6825 ^ 6825)); j_i < 15; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ (50 + 185);
    j_rb[(3 + 12)] = ((0 + 0) ^ (5346 ^ 5346));
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x92, 0x92, 0x8F, 0xDC, 0xD6, 0xDC, 0x81, 0xCC, 0xD8, 0xCB, 0x87, 0x86, 0x8F, 0x92, 0x92};
static const char* j_dc_25(void) {
    static char j_rb[(6 + 10)];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ (46 + 129);
    j_rb[15] = ((0 + 0) ^ (9371 ^ 9371));
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x2D, 0x2D, 0x30, 0x75, 0x7E, 0x66, 0x3E, 0x77, 0x75, 0x64, 0x38, 0x39, 0x30, 0x2D, 0x2D};
static const char* j_dc_26(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 16;
    j_rb[(10 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xD6, 0xD0, 0xC6, 0xD1};
static const char* j_dc_27(void) {
    static char j_rb[((4 + 1) ^ (9526 ^ 9526))];
    for (int j_i = ((0 + 0) ^ (8331 ^ 8331)); j_i < 4; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 131;
    j_rb[(0 + 4)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0xBA, 0xBB, 0xA0, 0xAB, 0xB5, 0xAB, 0xA6, 0xB1, 0xB5, 0xB8, 0xAB, 0xA2, 0xB5, 0xA6};
static const char* j_dc_28(void) {
    static char j_rb[((8 + 7) ^ (6040 ^ 6040))];
    for (int j_i = (0 + 0); j_i < 14; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((142 + 102) ^ (1492 ^ 1492));
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x58, 0x58, 0x45, 0x16, 0x1C, 0x16, 0x4B, 0x16, 0x09, 0x00, 0x00, 0x15, 0x4D, 0x4C, 0x45, 0x58, 0x58};
static const char* j_dc_29(void) {
    static char j_rb[((14 + 4) ^ (903 ^ 903))];
    for (int j_i = (0 + 0); j_i < 17; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 101;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x87, 0x98, 0x91, 0x84, 0x80, 0xD4, 0xC6, 0xC4, 0xC4, 0x99, 0x87};
static const char* j_dc_30(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (8793 ^ 8793)); j_i < (9 + 2); j_i++) j_rb[j_i] = j_enc_30[j_i] ^ ((175 + 69) ^ (7190 ^ 7190));
    j_rb[(4 + 7)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x9A, 0x9C, 0x9B, 0x8B};
static const char* j_dc_31(void) {
    static char j_rb[((0 + 5) ^ (4926 ^ 4926))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 238;
    j_rb[4] = ((0 + 0) ^ (967 ^ 967));
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x4B, 0x4C, 0x41, 0x5E, 0x48};
static const char* j_dc_32(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 45;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xFC, 0xFC, 0xE1, 0xB2, 0xB8, 0xB2, 0xEF, 0xB1, 0xB3, 0xAE, 0xA2, 0xA4, 0xB2, 0xB2, 0x9E, 0xAD, 0xA8, 0xB2, 0xB5, 0xE9, 0xE8, 0xE1, 0xFC, 0xFC};
static const char* j_dc_33(void) {
    static char j_rb[25];
    for (int j_i = ((0 + 0) ^ (2777 ^ 2777)); j_i < 24; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 193;
    j_rb[24] = ((0 + 0) ^ (8479 ^ 8479));
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x27, 0x27, 0x3A, 0x74, 0x7F, 0x6E, 0x34, 0x69, 0x75, 0x79, 0x71, 0x7F, 0x6E, 0x69, 0x32, 0x33, 0x3A, 0x27, 0x27};
static const char* j_dc_34(void) {
    static char j_rb[((6 + 14) ^ (4065 ^ 4065))];
    for (int j_i = ((0 + 0) ^ (2345 ^ 2345)); j_i < (6 + 13); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 26;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0xF0, 0xF6, 0xF1, 0xE1};
static const char* j_dc_35(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 132;
    j_rb[4] = ((0 + 0) ^ (6265 ^ 6265));
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xB4, 0xB3, 0xBE, 0xA1, 0xB7};
static const char* j_dc_36(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 210;
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xF9, 0xF9, 0xE4, 0xA2, 0xB7, 0xEA, 0xB3, 0xB6, 0xAD, 0xB0, 0xA1, 0xE4, 0xEB, 0xE4, 0xA2, 0xB7, 0xEA, 0xB6, 0xA1, 0xA5, 0xA0, 0xE4, 0xF9, 0xF9};
static const char* j_dc_37(void) {
    static char j_rb[25];
    for (int j_i = (0 + 0); j_i < 24; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 196;
    j_rb[24] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xE0, 0xBB, 0xA2, 0xBF, 0xE0, 0xA5, 0xA0, 0xAC, 0xA4, 0xB6, 0x90, 0xBC, 0xB6, 0xBC, 0xBB, 0xAA, 0xA2, 0x90, 0xBB, 0xA0, 0xBA, 0xBD, 0xE1, 0xBB, 0xB7, 0xBB};
static const char* j_dc_38(void) {
    static char j_rb[(0 + 27)];
    for (int j_i = 0; j_i < 26; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ (91 + 116);
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x1F, 0x12, 0x1B, 0x1B, 0x18, 0x57, 0x11, 0x05, 0x18, 0x1A, 0x57, 0x04, 0x0E, 0x04, 0x03, 0x12, 0x1A, 0x57, 0x03, 0x18, 0x02, 0x05, 0x7D};
static const char* j_dc_39(void) {
    static char j_rb[24];
    for (int j_i = (0 + 0); j_i < (4 + 19); j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 119;
    j_rb[23] = ((0 + 0) ^ (5354 ^ 5354));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xE1, 0xBA, 0xA3, 0xBE, 0xE1, 0xA4, 0xA1, 0xAD, 0xA5, 0xB7, 0x91, 0xBD, 0xB7, 0xBD, 0xBA, 0xAB, 0xA3, 0x91, 0xBA, 0xA1, 0xBB, 0xBC, 0xE0, 0xBA, 0xB6, 0xBA};
static const char* j_dc_40(void) {
    static char j_rb[27];
    for (int j_i = ((0 + 0) ^ (954 ^ 954)); j_i < (25 + 1); j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 206;
    j_rb[26] = ((0 + 0) ^ (8551 ^ 8551));
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xF9, 0xF9, 0xE4, 0xA2, 0xB7, 0xEA, 0xA1, 0xBC, 0xAD, 0xB7, 0xB0, 0xB7, 0xE4, 0xF9, 0xF9};
static const char* j_dc_41(void) {
    static char j_rb[((11 + 5) ^ (3414 ^ 3414))];
    for (int j_i = ((0 + 0) ^ (443 ^ 443)); j_i < ((10 + 5) ^ (527 ^ 527)); j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 196;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xDE, 0x85, 0x9C, 0x81, 0xDE, 0x9B, 0x9E, 0x92, 0x9A, 0x88, 0xAE, 0x82, 0x88, 0x82, 0x85, 0x94, 0x9C, 0xAE, 0x85, 0x9E, 0x84, 0x83, 0xDF, 0x85, 0x89, 0x85};
static const char* j_dc_42(void) {
    static char j_rb[(13 + 14)];
    for (int j_i = (0 + 0); j_i < 26; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 241;
    j_rb[(9 + 17)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x58, 0x5E, 0x59, 0x49};
static const char* j_dc_43(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((3 + 1) ^ (5839 ^ 5839)); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 44;
    j_rb[((1 + 3) ^ (9749 ^ 9749))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x50, 0x57, 0x5A, 0x45, 0x53};
static const char* j_dc_44(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = ((0 + 0) ^ (7450 ^ 7450)); j_i < 5; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ (34 + 20);
    j_rb[5] = ((0 + 0) ^ (2371 ^ 2371));
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xEB, 0xAA, 0xAB, 0xEB, 0xB7, 0xB1, 0xA7, 0xAC, 0xEB, 0xB4, 0xA5, 0xB0, 0xAC};
static const char* j_dc_45(void) {
    static char j_rb[(14 + 0)];
    for (int j_i = (0 + 0); j_i < ((5 + 8) ^ (1353 ^ 1353)); j_i++) j_rb[j_i] = j_enc_45[j_i] ^ (147 + 49);
    j_rb[((12 + 1) ^ (1989 ^ 1989))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x52, 0x54, 0x53, 0x43};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_46[j_i] ^ ((24 + 14) ^ (1951 ^ 1951));
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3A, 0x3D, 0x30, 0x2F, 0x39};
static const char* j_dc_47(void) {
    static char j_rb[((2 + 4) ^ (9623 ^ 9623))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 92;
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0xB1, 0xB1, 0xAC, 0xEA, 0xFF, 0xA2, 0xE0, 0xE5, 0xFF, 0xF8, 0xAC, 0xB1, 0xB1};
static const char* j_dc_48(void) {
    static char j_rb[14];
    for (int j_i = (0 + 0); j_i < 13; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 140;
    j_rb[((9 + 4) ^ (4293 ^ 4293))] = ((0 + 0) ^ (1941 ^ 1941));
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x4B, 0x10, 0x09, 0x14};
static const char* j_dc_49(void) {
    static char j_rb[((2 + 3) ^ (2820 ^ 2820))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ ((95 + 5) ^ (5196 ^ 5196));
    j_rb[((0 + 4) ^ (2078 ^ 2078))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x28, 0x28, 0x35, 0x67, 0x70, 0x72, 0x3B, 0x79, 0x7C, 0x66, 0x61, 0x35, 0x3D, 0x42, 0x7C, 0x7B, 0x71, 0x7A, 0x62, 0x66, 0x35, 0x7A, 0x7B, 0x79, 0x6C, 0x3C, 0x35, 0x28, 0x28};
static const char* j_dc_50(void) {
    static char j_rb[((23 + 7) ^ (98 ^ 98))];
    for (int j_i = 0; j_i < 29; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 21;
    j_rb[((4 + 25) ^ (4140 ^ 4140))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x6D, 0x6E, 0x69, 0x68, 0x79, 0x76, 0x6A, 0x63, 0x71, 0x72, 0x64, 0x77, 0x60, 0x79, 0x68, 0x4C, 0x46, 0x57, 0x4A, 0x56, 0x4A, 0x43, 0x51};
static const char* j_dc_51(void) {
    static char j_rb[(24 + 0)];
    for (int j_i = 0; j_i < 23; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 37;
    j_rb[(19 + 4)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x37, 0x37, 0x2A, 0x67, 0x6F, 0x67, 0x24, 0x6E, 0x7F, 0x67, 0x7A, 0x2A, 0x22, 0x5D, 0x63, 0x64, 0x6E, 0x65, 0x7D, 0x79, 0x2A, 0x65, 0x64, 0x66, 0x73, 0x23, 0x2A, 0x37, 0x37};
static const char* j_dc_52(void) {
    static char j_rb[(27 + 3)];
    for (int j_i = (0 + 0); j_i < 29; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 10;
    j_rb[29] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0xD9, 0x82, 0x9B, 0x86, 0xD9, 0x9C, 0x99, 0x95, 0x9D, 0x8F, 0xA9, 0x9B, 0x93, 0x9B, 0xD8, 0x94, 0x9F, 0x98};
static const char* j_dc_53(void) {
    static char j_rb[19];
    for (int j_i = 0; j_i < ((10 + 8) ^ (1398 ^ 1398)); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 246;
    j_rb[(1 + 17)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x4F, 0x44, 0x45, 0x4E};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ ((33 + 10) ^ (6024 ^ 6024));
    j_rb[4] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == ((0 + 0) ^ (6813 ^ 6813)); }

static char j_buf[(3590 + 61946)];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + 8 < cap; ++p) {
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
                    out[o++] = j_dc_0()[c >> ((1 + 3) ^ (8155 ^ 8155))];
                    out[o++] = j_dc_1()[c & (7 + 8)];
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
    ts.tv_sec = ms / ((854 + 146) ^ (2914 ^ 2914));
    ts.tv_nsec = (long)(ms % ((40 + 960) ^ (1143 ^ 1143))) * 1000000L;
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
    return access(path, F_OK) == (0 + 0);
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, j_dc_2());
    if (!f) return "";
    size_t n = fread(j_buf, ((1 + 0) ^ (3694 ^ 3694)), J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[(487 + 537)];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[(0 + 0)] == '.') continue;
            if (off > J_BUF_CAP - (118 + 82)) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > (0 + 0) ? n : (0 + 0));
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[((0 + 0) ^ (9995 ^ 9995))] == '.') continue;
            if (off > J_BUF_CAP - ((146 + 54) ^ (7721 ^ 7721))) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((0 + 1024) ^ (8398 ^ 8398))];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > (0 + 0) ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - (245 + 155)) break;
                char name[1024];
                size_t k = (0 + 0);
                for (size_t i = ((0 + 0) ^ (5495 ^ 5495)); pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (1806 ^ 1806));
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = (0 + 0); i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[((116 + 140) ^ (1511 ^ 1511))];
        int len = proc_name(pid, name, sizeof name);
        if (len <= (0 + 0)) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = ((0 + 0) ^ (2692 ^ 2692));
        char esc[(24 + 488)];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (2116 ^ 2116)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[((8 + 56) ^ (1989 ^ 1989))], name[(254 + 2)];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[((3 + 509) ^ (7671 ^ 7671))];
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
    char line[512];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[((3 + 61) ^ (759 ^ 759))], raddr[64], st[(15 + 1)];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != (3 + 0)) continue;
        if (*off > J_BUF_CAP - ((8 + 292) ^ (7502 ^ 7502))) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = (0 + 0);
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : (0 + 0));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = (0 + 0);
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : (0 + 1));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0)) == NO_ERROR) {
            for (DWORD i = ((0 + 0) ^ (7024 ^ 7024)); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[(33 + 31)], ri[(57 + 7)];
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
                if (off > J_BUF_CAP - ((292 + 8) ^ (5827 ^ 5827))) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[((27 + 5) ^ (4975 ^ 4975))];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == ((0 + 4) ^ (2882 ^ 2882))) {
                if (strncmp(proto, j_dc_16(), (3 + 0)) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > ((0 + 0) ^ (4502 ^ 4502)) ? n : (0 + 0));
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
    size_t off = ((0 + 0) ^ (7363 ^ 7363));
    j_buf[off++] = '[';
    int first = (1 + 0);
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + ((5 + 0) ^ (3148 ^ 3148)); }
    else if (strncmp(key, j_dc_20(), ((4 + 1) ^ (7958 ^ 7958))) == ((0 + 0) ^ (8870 ^ 8870))) { root = HKEY_CURRENT_USER; sub = key + ((3 + 2) ^ (7986 ^ 7986)); }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), (2 + 2)) == 0) { root = HKEY_USERS; sub = key + ((0 + 4) ^ (439 ^ 439)); }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, ((0 + 0) ^ (8497 ^ 8497)), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = ((0 + 0) ^ (9524 ^ 9524)); ; ++i) {
            char s[((204 + 52) ^ (8139 ^ 8139))];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - ((13 + 387) ^ (1512 ^ 1512))) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((221 + 291) ^ (4308 ^ 4308))];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : 0);
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
    unsigned long regions = ((0 + 0) ^ (8871 ^ 8871));
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < ((30330 + 69670) ^ (4788 ^ 4788))) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = (0 + 0);
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, ((1 + 0) ^ (6450 ^ 6450)), read, out);
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

static volatile int32_t j_f7g6fuiz = 6820;
static volatile int32_t j_jsufqwit = ((15103 + 38068) ^ (4828 ^ 4828));

__attribute__((used)) static int32_t j_z_5ppufq(int32_t j_n) {
    int32_t j_s = 0;
    int32_t j_i = 1;
    while (j_i <= j_n) {
        if ((j_i % ((2 + 1) ^ (2782 ^ 2782))) == (0 + 0)) j_s = j_s + j_i;
        else j_s = j_s + j_i * 2;
        j_i = j_i + ((1 + 0) ^ (3660 ^ 3660));
    }
    return j_s;
}

__attribute__((used)) static int32_t j_z_x7fm52(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * ((29 + 2) ^ (9695 ^ 9695)) + j_c) % 10007;
        j_t = j_t + (1 + 0);
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_hy797h(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % ((8124 + 1883) ^ (2750 ^ 2750));
        j_t = j_t + (0 + 1);
    }
    return j_r;
}

static int32_t j_tr_w8kitx(void) {
    int32_t j_ghb9foiw = ((0 + 0) ^ (9081 ^ 9081));
    while ((j_ghb9foiw != -1))
    {
        switch (j_ghb9foiw)
        {
            case 0:
                (void)printf("%s\n", j_dc_24());
                (void)printf("%s\n", j_sys_now());
                static volatile int64_t j_o6t0nvls = 70902;
                if ((((j_o6t0nvls * j_o6t0nvls) + j_o6t0nvls) >= 0))
                {
                    (void)printf("%s\n", j_dc_25());
                }
                else
                {
                    volatile int64_t j_2wrj8m2p = ((j_o6t0nvls * 2) + (0 + 1));
                }
                j_ghb9foiw = (1 + 0);
                break;
            case 1:
                (void)printf("%s\n", j_sys_cwd());
                static volatile int64_t j_7e3padoq = ((31756 + 39992) ^ (5356 ^ 5356));
                if ((((j_7e3padoq * j_7e3padoq) + j_7e3padoq) >= 0))
                {
                    (void)printf("%s\n", j_dc_26());
                }
                else
                {
                    volatile int64_t j_ql8pat8l = ((j_7e3padoq * 2) + ((1 + 0) ^ (3009 ^ 3009)));
                }
                j_ghb9foiw = (1 + 1);
                break;
            case 2:
                (void)printf("%s\n", j_env_get(j_dc_27()));
                (void)printf("%s\n", j_env_get(j_dc_28()));
                (void)printf("%s\n", j_dc_29());
                (void)j_sys_sleep(200);
                static volatile int64_t j_vogp4vxx = 35707;
                if ((((j_vogp4vxx * j_vogp4vxx) + j_vogp4vxx) >= 0))
                {
                    (void)printf("%s\n", j_dc_30());
                }
                else
                {
                    volatile int64_t j_ehlw0m3t = ((j_vogp4vxx * 2) + 1);
                }
                j_ghb9foiw = 3;
                break;
            case 3:
                static volatile int64_t j_uz7o1dww = 86933;
                if ((((j_uz7o1dww * (j_uz7o1dww + (0 + 1))) % 2) == (1 + 0)))
                {
                    (void)printf("%s\n", 0 ? j_dc_31() : j_dc_32());
                }
                j_ghb9foiw = (4 + 0);
                break;
            case 4:
                (void)printf("%s\n", j_dc_33());
                static volatile int64_t j_cl9v0u1j = (1346 + 55609);
                if ((((j_cl9v0u1j * j_cl9v0u1j) + j_cl9v0u1j) >= ((0 + 0) ^ (3135 ^ 3135))))
                {
                    (void)printf("%s\n", j_sys_process_list());
                }
                else
                {
                    volatile int64_t j_d8trjgcf = ((j_cl9v0u1j * ((1 + 1) ^ (4652 ^ 4652))) + 1);
                }
                j_ghb9foiw = (0 + 5);
                break;
            case 5:
                (void)printf("%s\n", j_dc_34());
                static volatile int64_t j_gd3i4eu3 = (53479 + 10451);
                if ((((j_gd3i4eu3 * j_gd3i4eu3) + j_gd3i4eu3) >= 0))
                {
                    (void)printf("%s\n", j_net_sockets());
                }
                else
                {
                    volatile int64_t j_wz7tww6m = ((j_gd3i4eu3 * 2) + (1 + 0));
                }
                j_ghb9foiw = 6;
                break;
            case 6:
                static volatile int64_t j_esi0ml05 = (56873 + 24618);
                if ((((j_esi0ml05 * j_esi0ml05) + j_esi0ml05) < 0))
                {
                    volatile int64_t j_2rhh3gut = ((j_esi0ml05 * 27) + (206 + 285));
                    (void)printf("%s\n", 0 ? j_dc_35() : j_dc_36());
                }
                j_ghb9foiw = (3 + 4);
                break;
            case 7:
                static volatile int64_t j_si31ndk9 = 44312;
                if ((((j_si31ndk9 * j_si31ndk9) + j_si31ndk9) >= ((0 + 0) ^ (1465 ^ 1465))))
                {
                    (void)printf("%s\n", j_dc_37());
                }
                else
                {
                    volatile int64_t j_e63tox7h = ((j_si31ndk9 * 2) + (1 + 0));
                }
                j_ghb9foiw = 8;
                break;
            case 8:
                static volatile int64_t j_gmqpdmt0 = (5824 + 54469);
                if ((((j_gmqpdmt0 * j_gmqpdmt0) + j_gmqpdmt0) >= 0))
                {
                    (void)j_fs_write(j_dc_38(), j_dc_39());
                }
                else
                {
                    volatile int64_t j_c8jewur5 = ((j_gmqpdmt0 * (2 + 0)) + (1 + 0));
                }
                j_ghb9foiw = ((7 + 2) ^ (8635 ^ 8635));
                break;
            case 9:
                static volatile int64_t j_468tmzoa = 40393;
                if ((((j_468tmzoa * j_468tmzoa) + j_468tmzoa) >= ((0 + 0) ^ (8778 ^ 8778))))
                {
                    (void)printf("%s\n", j_fs_read(j_dc_40()));
                }
                else
                {
                    volatile int64_t j_qo32bb5q = ((j_468tmzoa * 2) + ((0 + 1) ^ (283 ^ 283)));
                }
                j_ghb9foiw = 10;
                break;
            case 10:
                (void)printf("%s\n", j_dc_41());
                (void)printf("%s\n", j_fs_exists(j_dc_42()) ? j_dc_43() : j_dc_44());
                (void)printf("%s\n", j_fs_exists(j_dc_45()) ? j_dc_46() : j_dc_47());
                (void)printf("%s\n", j_dc_48());
                (void)printf("%s\n", j_fs_list(j_dc_49()));
                (void)printf("%s\n", j_dc_50());
                static volatile int64_t j_ifxsxp8l = 72497;
                if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) >= 0))
                {
                    (void)printf("%s\n", j_reg_list(j_dc_51()));
                }
                else
                {
                    volatile int64_t j_l9dl9lcd = ((j_ifxsxp8l * 2) + (0 + 1));
                }
                j_ghb9foiw = (7 + 4);
                break;
            case 11:
                (void)printf("%s\n", j_dc_52());
                static volatile int64_t j_7m5fgot7 = ((34059 + 58994) ^ (4440 ^ 4440));
                if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) >= ((0 + 0) ^ (7084 ^ 7084))))
                {
                    (void)j_mem_dump(((0 + 1) ^ (9389 ^ 9389)), j_dc_53());
                }
                else
                {
                    volatile int64_t j_yn30xwb1 = ((j_7m5fgot7 * 2) + 1);
                }
                j_ghb9foiw = 12;
                break;
            case 12:
                (void)printf("%s\n", j_dc_54());
                j_ghb9foiw = -((1 + 0) ^ (6175 ^ 6175));
                break;
            default:
                break;
        }
    }
    return 0;
}
static int32_t j_tr_bib5dw(void) { return j_tr_w8kitx(); }
static int32_t j_tr_zyw4k4(void) { return j_tr_bib5dw(); }
int32_t main(void) { return j_tr_zyw4k4(); }

