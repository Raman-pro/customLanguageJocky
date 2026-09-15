// JOCKY build 5B8D9F1BE2220CBA seed=12345 date=2026-09-03 05:00:04
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
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 35;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_1(void) {
    static char j_rb[((7 + 10) ^ (6414 ^ 6414))];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ (6 + 12);
    j_rb[(12 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xBA, 0xAA};
static const char* j_dc_2(void) {
    static char j_rb[((0 + 3) ^ (6210 ^ 6210))];
    for (int j_i = 0; j_i < ((0 + 2) ^ (9399 ^ 9399)); j_i++) j_rb[j_i] = j_enc_2[j_i] ^ (76 + 124);
    j_rb[((0 + 2) ^ (1846 ^ 1846))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x58, 0x4D};
static const char* j_dc_3(void) {
    static char j_rb[((2 + 1) ^ (8125 ^ 8125))];
    for (int j_i = (0 + 0); j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 47;
    j_rb[(2 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xDC, 0x83, 0x81, 0x9C, 0x90};
static const char* j_dc_4(void) {
    static char j_rb[((1 + 5) ^ (4553 ^ 4553))];
    for (int j_i = ((0 + 0) ^ (2889 ^ 2889)); j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ ((11 + 232) ^ (9824 ^ 9824));
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDB};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ (142 + 27);
    j_rb[((0 + 1) ^ (8836 ^ 8836))] = ((0 + 0) ^ (449 ^ 449));
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x64};
static const char* j_dc_6(void) {
    static char j_rb[((2 + 0) ^ (6928 ^ 6928))];
    for (int j_i = ((0 + 0) ^ (8273 ^ 8273)); j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ (17 + 93);
    j_rb[((0 + 1) ^ (1017 ^ 1017))] = ((0 + 0) ^ (2476 ^ 2476));
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8E};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = ((0 + 0) ^ (4169 ^ 4169)); j_i < (1 + 0); j_i++) j_rb[j_i] = j_enc_7[j_i] ^ ((35 + 217) ^ (2384 ^ 2384));
    j_rb[1] = ((0 + 0) ^ (2885 ^ 2885));
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x5F};
static const char* j_dc_8(void) {
    static char j_rb[(2 + 0)];
    for (int j_i = ((0 + 0) ^ (951 ^ 951)); j_i < ((1 + 0) ^ (95 ^ 95)); j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 96;
    j_rb[(1 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xDD, 0xD8, 0xC2, 0xC5, 0xD4, 0xDF};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = (0 + 0); j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ (23 + 122);
    j_rb[((5 + 1) ^ (3956 ^ 3956))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x71, 0x67, 0x60, 0x75, 0x76, 0x78, 0x7D, 0x67, 0x7C, 0x71, 0x70};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 52;
    j_rb[11] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x82, 0x8D, 0x8E, 0x92, 0x84, 0x9E, 0x96, 0x80, 0x88, 0x95};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < ((1 + 9) ^ (6825 ^ 6825)); j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 193;
    j_rb[(8 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x36, 0x2B, 0x2F, 0x27, 0x3D, 0x35, 0x23, 0x2B, 0x36};
static const char* j_dc_12(void) {
    static char j_rb[((9 + 1) ^ (5346 ^ 5346))];
    for (int j_i = (0 + 0); j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 98;
    j_rb[(2 + 7)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0B, 0x10, 0x0C, 0x01, 0x16};
static const char* j_dc_13(void) {
    static char j_rb[((6 + 0) ^ (9371 ^ 9371))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 68;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x3C, 0x37, 0x26, 0x21, 0x26, 0x33, 0x26, 0x72, 0x7F, 0x33, 0x3C, 0x72, 0x7F, 0x22, 0x72, 0x26, 0x31, 0x22, 0x72, 0x60, 0x6C, 0x7D, 0x36, 0x37, 0x24, 0x7D, 0x3C, 0x27, 0x3E, 0x3E};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = ((0 + 0) ^ (9526 ^ 9526)); j_i < ((24 + 6) ^ (8331 ^ 8331)); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 82;
    j_rb[30] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x92};
static const char* j_dc_15(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = ((0 + 0) ^ (6040 ^ 6040)); j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 224;
    j_rb[((1 + 0) ^ (1492 ^ 1492))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x80, 0x97, 0x84};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = ((0 + 0) ^ (903 ^ 903)); j_i < (0 + 3); j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 244;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xE6, 0xB9, 0xBB, 0xA6, 0xAA, 0xE6, 0xA7, 0xAC, 0xBD, 0xE6, 0xBD, 0xAA, 0xB9};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < ((13 + 0) ^ (8793 ^ 8793)); j_i++) j_rb[j_i] = j_enc_17[j_i] ^ (143 + 58);
    j_rb[((0 + 13) ^ (7190 ^ 7190))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x04, 0x5B, 0x59, 0x44, 0x48, 0x04, 0x45, 0x4E, 0x5F, 0x04, 0x5F, 0x48, 0x5B, 0x1D};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = ((0 + 0) ^ (4926 ^ 4926)); j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 43;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xA3, 0xA0, 0xA7, 0xA6, 0xB7};
static const char* j_dc_19(void) {
    static char j_rb[((1 + 5) ^ (967 ^ 967))];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 235;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x36, 0x35, 0x3D, 0x2B, 0x22};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((5 + 0) ^ (2777 ^ 2777)); j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 126;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x1A, 0x19, 0x11, 0x00, 0x0E};
static const char* j_dc_21(void) {
    static char j_rb[((6 + 0) ^ (8479 ^ 8479))];
    for (int j_i = ((0 + 0) ^ (4065 ^ 4065)); j_i < ((0 + 5) ^ (2345 ^ 2345)); j_i++) j_rb[j_i] = j_enc_21[j_i] ^ (35 + 47);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x29, 0x2A, 0x34, 0x3D};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ (37 + 60);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xF1, 0xE4};
static const char* j_dc_23(void) {
    static char j_rb[((2 + 1) ^ (6265 ^ 6265))];
    for (int j_i = 0; j_i < (2 + 0); j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 134;
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xD6, 0xD6, 0xD6, 0xCB, 0xB8, 0xB2, 0xB8, 0xBF, 0xAE, 0xA6, 0xCB, 0xD6, 0xD6, 0xD6};
static const char* j_dc_24(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < (3 + 11); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 235;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xDB, 0xDD, 0xDA, 0xCA};
static const char* j_dc_25(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 175;
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_26(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ (12 + 4);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xD6, 0xD0, 0xC6, 0xD1};
static const char* j_dc_27(void) {
    static char j_rb[((3 + 2) ^ (5354 ^ 5354))];
    for (int j_i = 0; j_i < ((4 + 0) ^ (954 ^ 954)); j_i++) j_rb[j_i] = j_enc_27[j_i] ^ (112 + 19);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0xC9, 0xC9, 0xC9, 0xD4, 0xA4, 0xA6, 0xBB, 0xB7, 0xB1, 0xA7, 0xA7, 0xB1, 0xA7, 0xD4, 0xDC, 0xBE, 0xA7, 0xBB, 0xBA, 0xDD, 0xD4, 0xC9, 0xC9, 0xC9};
static const char* j_dc_28(void) {
    static char j_rb[((22 + 3) ^ (8551 ^ 8551))];
    for (int j_i = ((0 + 0) ^ (3414 ^ 3414)); j_i < ((18 + 6) ^ (443 ^ 443)); j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((35 + 209) ^ (527 ^ 527));
    j_rb[24] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x58, 0x58, 0x58, 0x45, 0x31, 0x26, 0x35, 0x45, 0x36, 0x2A, 0x26, 0x2E, 0x20, 0x31, 0x36, 0x45, 0x4D, 0x2F, 0x36, 0x2A, 0x2B, 0x4C, 0x45, 0x58, 0x58, 0x58};
static const char* j_dc_29(void) {
    static char j_rb[27];
    for (int j_i = (0 + 0); j_i < (21 + 5); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 101;
    j_rb[26] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xC9, 0xC9, 0xC9, 0xD4, 0xB2, 0xA7, 0xD4, 0xDB, 0x80, 0x99, 0x84, 0xD4, 0xDC, 0xBE, 0xA7, 0xBB, 0xBA, 0xDD, 0xD4, 0xC9, 0xC9, 0xC9};
static const char* j_dc_30(void) {
    static char j_rb[23];
    for (int j_i = 0; j_i < (2 + 20); j_i++) j_rb[j_i] = j_enc_30[j_i] ^ ((198 + 46) ^ (5839 ^ 5839));
    j_rb[22] = ((0 + 0) ^ (9749 ^ 9749));
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0xC1, 0x9A, 0x83, 0x9E};
static const char* j_dc_31(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((4 + 0) ^ (7450 ^ 7450)); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 238;
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x02, 0x59, 0x40, 0x5D};
static const char* j_dc_32(void) {
    static char j_rb[((2 + 3) ^ (2371 ^ 2371))];
    for (int j_i = (0 + 0); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_32[j_i] ^ ((9 + 36) ^ (1353 ^ 1353));
    j_rb[(3 + 1)] = ((0 + 0) ^ (1989 ^ 1989));
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_33(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ (96 + 97);
    j_rb[((3 + 1) ^ (1951 ^ 1951))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_34(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (9623 ^ 9623)); j_i < 5; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 26;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0xF0, 0xF6, 0xF1, 0xE1};
static const char* j_dc_35(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 132;
    j_rb[4] = ((0 + 0) ^ (4293 ^ 4293));
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xB4, 0xB3, 0xBE, 0xA1, 0xB7};
static const char* j_dc_36(void) {
    static char j_rb[((1 + 5) ^ (1941 ^ 1941))];
    for (int j_i = ((0 + 0) ^ (2820 ^ 2820)); j_i < 5; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 210;
    j_rb[((1 + 4) ^ (5196 ^ 5196))] = ((0 + 0) ^ (2078 ^ 2078));
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xEB, 0xB0, 0xA9, 0xB4, 0xEB, 0xAE, 0xAB, 0xA7, 0xAF, 0xBD, 0x9B, 0xB0, 0xA1, 0xB7, 0xB0, 0xEA, 0xB0, 0xBC, 0xB0};
static const char* j_dc_37(void) {
    static char j_rb[20];
    for (int j_i = ((0 + 0) ^ (98 ^ 98)); j_i < 19; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 196;
    j_rb[19] = ((0 + 0) ^ (4140 ^ 4140));
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xA7, 0xAA, 0xA3, 0xA3, 0xA0, 0xEF, 0xA9, 0xBD, 0xA0, 0xA2, 0xEF, 0xA5, 0xA0, 0xAC, 0xA4, 0xB6, 0xC5};
static const char* j_dc_38(void) {
    static char j_rb[18];
    for (int j_i = (0 + 0); j_i < 17; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 207;
    j_rb[17] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x58, 0x03, 0x1A, 0x07, 0x58, 0x1D, 0x18, 0x14, 0x1C, 0x0E, 0x28, 0x03, 0x12, 0x04, 0x03, 0x59, 0x03, 0x0F, 0x03};
static const char* j_dc_39(void) {
    static char j_rb[(15 + 5)];
    for (int j_i = (0 + 0); j_i < (0 + 19); j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 119;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xF3, 0xF3, 0xF3, 0xEE, 0x9C, 0x8B, 0x89, 0x87, 0x9D, 0x9A, 0x9C, 0x97, 0xEE, 0xE6, 0x99, 0xA7, 0xA0, 0xAA, 0xA1, 0xB9, 0xBD, 0xEE, 0xA1, 0xA0, 0xA2, 0xB7, 0xE7, 0xEE, 0xF3, 0xF3, 0xF3};
static const char* j_dc_40(void) {
    static char j_rb[(4 + 28)];
    for (int j_i = 0; j_i < 31; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ ((148 + 58) ^ (1398 ^ 1398));
    j_rb[31] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x8C, 0x8F, 0x88, 0x89, 0x98, 0x97, 0x8B, 0x82, 0x90, 0x93, 0x85, 0x96, 0x81, 0x98, 0x89, 0xAD, 0xA7, 0xB6, 0xAB, 0xB7, 0xAB, 0xA2, 0xB0};
static const char* j_dc_41(void) {
    static char j_rb[24];
    for (int j_i = 0; j_i < 23; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 196;
    j_rb[((1 + 22) ^ (6024 ^ 6024))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xCC, 0xCC, 0xCC, 0xD1, 0xBC, 0xB4, 0xBC, 0xD1, 0xB5, 0xA4, 0xBC, 0xA1, 0xD1, 0xD9, 0xA6, 0x98, 0x9F, 0x95, 0x9E, 0x86, 0x82, 0xD1, 0x9E, 0x9F, 0x9D, 0x88, 0xDD, 0xD1, 0x81, 0x98, 0x95, 0xCC, 0xC0, 0xD8, 0xD1, 0xCC, 0xCC, 0xCC};
static const char* j_dc_42(void) {
    static char j_rb[39];
    for (int j_i = ((0 + 0) ^ (6813 ^ 6813)); j_i < (26 + 12); j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 241;
    j_rb[38] = ((0 + 0) ^ (8155 ^ 8155));
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x03, 0x58, 0x41, 0x5C, 0x03, 0x46, 0x43, 0x4F, 0x47, 0x55, 0x73, 0x41, 0x49, 0x41, 0x02, 0x4E, 0x45, 0x42};
static const char* j_dc_43(void) {
    static char j_rb[(15 + 4)];
    for (int j_i = ((0 + 0) ^ (2914 ^ 2914)); j_i < ((18 + 0) ^ (1143 ^ 1143)); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ (11 + 33);
    j_rb[((2 + 16) ^ (3694 ^ 3694))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x52, 0x59, 0x58, 0x53};
static const char* j_dc_44(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ (3 + 51);
    j_rb[(0 + 4)] = (0 + 0);
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[(22602 + 42934)];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = (0 + 0);
    for (const char* p = s; *p && o + ((0 + 8) ^ (9995 ^ 9995)) < cap; ++p) {
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
                    out[o++] = j_dc_0()[c >> ((1 + 3) ^ (7721 ^ 7721))];
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
    ts.tv_sec = ms / ((591 + 409) ^ (8398 ^ 8398));
    ts.tv_nsec = (long)(ms % (172 + 828)) * 1000000L;
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
    size_t n = fread(j_buf, 1, J_BUF_CAP - 1, f);
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
    int first = (0 + 1);
#if defined(_WIN32)
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[(0 + 0)] == '.') continue;
            if (off > J_BUF_CAP - ((119 + 81) ^ (5495 ^ 5495))) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((340 + 684) ^ (1806 ^ 1806))];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (1511 ^ 1511)) ? n : (0 + 0));
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = ((0 + 0) ^ (2692 ^ 2692));
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, (0 + 0));
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - ((184 + 216) ^ (2116 ^ 2116))) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = ((0 + 0) ^ (1989 ^ 1989)); pe.szExeFile[i] && k + (1 + 0) < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > ((0 + 0) ^ (7671 ^ 7671)) ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= ((0 + 0) ^ (759 ^ 759))) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[(441 + 71)];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (7502 ^ 7502)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[(0 + 0)] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[(57 + 7)], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[512];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
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
    char line[((82 + 430) ^ (7024 ^ 7024))];
    int skip = (0 + 1);
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = (0 + 0); continue; }
        char laddr[((30 + 34) ^ (5827 ^ 5827))], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = ((0 + 0) ^ (4975 ^ 4975));
    j_buf[off++] = '[';
    int first = ((0 + 1) ^ (2882 ^ 2882));
#if defined(_WIN32)
    ULONG sz = (0 + 0);
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0)) == NO_ERROR) {
            for (DWORD i = ((0 + 0) ^ (4502 ^ 4502)); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[(51 + 13)], ri[((60 + 4) ^ (7363 ^ 7363))];
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
                if (off > J_BUF_CAP - (241 + 59)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : ((0 + 0) ^ (3148 ^ 3148)));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[((100 + 412) ^ (7958 ^ 7958))];
        while (fgets(line, sizeof line, ns)) {
            char proto[((6 + 2) ^ (8870 ^ 8870))], laddr[((4 + 60) ^ (7986 ^ 7986))], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), (2 + 1)) != 0) continue;
                if (off > J_BUF_CAP - ((82 + 218) ^ (439 ^ 439))) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (8497 ^ 8497));
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > ((0 + 0) ^ (9524 ^ 9524)) ? n : ((0 + 0) ^ (8139 ^ 8139)));
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
    size_t off = ((0 + 0) ^ (1512 ^ 1512));
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), ((5 + 0) ^ (4308 ^ 4308))) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, j_dc_20(), ((5 + 0) ^ (8871 ^ 8871))) == ((0 + 0) ^ (4788 ^ 4788))) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), (2 + 3)) == ((0 + 0) ^ (6450 ^ 6450))) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), ((3 + 1) ^ (4828 ^ 4828))) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, ((0 + 0) ^ (2782 ^ 2782)), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = (0 + 0); ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - ((279 + 121) ^ (3660 ^ 3660))) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((91 + 421) ^ (9695 ^ 9695))];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : (0 + 0));
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
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : ((0 + 1) ^ (2750 ^ 2750)));
            SIZE_T read = (0 + 0);
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, ((0 + 1) ^ (9081 ^ 9081)), read, out);
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
static volatile int32_t j_jsufqwit = 53171;

__attribute__((used)) static int32_t j_z_5ppufq(int32_t j_n) {
    int32_t j_s = 0;
    int32_t j_i = 1;
    while (j_i <= j_n) {
        if ((j_i % (2 + 1)) == (0 + 0)) j_s = j_s + j_i;
        else j_s = j_s + j_i * ((0 + 2) ^ (5356 ^ 5356));
        j_i = j_i + 1;
    }
    return j_s;
}

__attribute__((used)) static int32_t j_z_x7fm52(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * ((7 + 24) ^ (3009 ^ 3009)) + j_c) % (7804 + 2203);
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_hy797h(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

static int32_t j_tr_w8kitx(void) {
    int32_t j_ghb9foiw = 0;
    while ((j_ghb9foiw != -1))
    {
        switch (j_ghb9foiw)
        {
            case 0:
                (void)printf("%s\n", j_dc_24());
                (void)printf("%s\n", j_sys_now());
                static volatile int64_t j_o6t0nvls = (14926 + 72007);
                if ((((j_o6t0nvls * (j_o6t0nvls + 1)) % (2 + 0)) == 1))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_25() : j_dc_26());
                }
                j_ghb9foiw = (0 + 1);
                break;
            case 1:
                static volatile int64_t j_2wrj8m2p = ((55068 + 15834) ^ (3135 ^ 3135));
                if ((((j_2wrj8m2p * j_2wrj8m2p) + j_2wrj8m2p) >= ((0 + 0) ^ (4652 ^ 4652))))
                {
                    (void)printf("%s\n", j_sys_cwd());
                }
                else
                {
                    volatile int64_t j_7e3padoq = ((j_2wrj8m2p * 2) + (0 + 1));
                }
                j_ghb9foiw = (1 + 1);
                break;
            case 2:
                (void)printf("%s\n", j_env_get(j_dc_27()));
                static volatile int64_t j_ql8pat8l = 71748;
                if ((((j_ql8pat8l * j_ql8pat8l) + j_ql8pat8l) >= 0))
                {
                    (void)printf("%s\n", j_dc_28());
                }
                else
                {
                    volatile int64_t j_vogp4vxx = ((j_ql8pat8l * (2 + 0)) + 1);
                }
                j_ghb9foiw = (1 + 2);
                break;
            case 3:
                (void)printf("%s\n", j_sys_process_list());
                (void)printf("%s\n", j_dc_29());
                (void)printf("%s\n", j_net_sockets());
                (void)printf("%s\n", j_dc_30());
                static volatile int64_t j_ehlw0m3t = 35707;
                if ((((j_ehlw0m3t * j_ehlw0m3t) + j_ehlw0m3t) >= 0))
                {
                    (void)printf("%s\n", j_fs_list(j_dc_31()));
                }
                else
                {
                    volatile int64_t j_uz7o1dww = ((j_ehlw0m3t * (2 + 0)) + 1);
                }
                j_ghb9foiw = (2 + 2);
                break;
            case 4:
                (void)printf("%s\n", j_fs_exists(j_dc_32()) ? j_dc_33() : j_dc_34());
                static volatile int64_t j_cl9v0u1j = 81491;
                if ((((j_cl9v0u1j * j_cl9v0u1j) + j_cl9v0u1j) < ((0 + 0) ^ (1465 ^ 1465))))
                {
                    volatile int64_t j_d8trjgcf = ((j_cl9v0u1j * 27) + (361 + 130));
                    (void)printf("%s\n", 0 ? j_dc_35() : j_dc_36());
                }
                j_ghb9foiw = (4 + 1);
                break;
            case 5:
                static volatile int64_t j_gd3i4eu3 = 56955;
                if ((((j_gd3i4eu3 * j_gd3i4eu3) + j_gd3i4eu3) >= (0 + 0)))
                {
                    (void)j_fs_write(j_dc_37(), j_dc_38());
                }
                else
                {
                    volatile int64_t j_wz7tww6m = ((j_gd3i4eu3 * (1 + 1)) + ((1 + 0) ^ (8635 ^ 8635)));
                }
                j_ghb9foiw = 6;
                break;
            case 6:
                (void)printf("%s\n", j_fs_read(j_dc_39()));
                static volatile int64_t j_esi0ml05 = ((19462 + 44468) ^ (8778 ^ 8778));
                if ((((j_esi0ml05 * j_esi0ml05) + j_esi0ml05) >= 0))
                {
                    (void)printf("%s\n", j_dc_40());
                }
                else
                {
                    volatile int64_t j_2rhh3gut = ((j_esi0ml05 * ((0 + 2) ^ (283 ^ 283))) + 1);
                }
                j_ghb9foiw = 7;
                break;
            case 7:
                static volatile int64_t j_si31ndk9 = 44312;
                if ((((j_si31ndk9 * j_si31ndk9) + j_si31ndk9) >= 0))
                {
                    (void)printf("%s\n", j_reg_list(j_dc_41()));
                }
                else
                {
                    volatile int64_t j_e63tox7h = ((j_si31ndk9 * (0 + 2)) + (1 + 0));
                }
                j_ghb9foiw = ((0 + 8) ^ (4440 ^ 4440));
                break;
            case 8:
                static volatile int64_t j_gmqpdmt0 = ((43259 + 17034) ^ (7084 ^ 7084));
                if ((((j_gmqpdmt0 * j_gmqpdmt0) + j_gmqpdmt0) >= ((0 + 0) ^ (9389 ^ 9389))))
                {
                    (void)printf("%s\n", j_dc_42());
                }
                else
                {
                    volatile int64_t j_c8jewur5 = ((j_gmqpdmt0 * 2) + 1);
                }
                j_ghb9foiw = 9;
                break;
            case 9:
                static volatile int64_t j_468tmzoa = 40393;
                if ((((j_468tmzoa * j_468tmzoa) + j_468tmzoa) >= 0))
                {
                    (void)j_mem_dump(1, j_dc_43());
                }
                else
                {
                    volatile int64_t j_qo32bb5q = ((j_468tmzoa * (0 + 2)) + 1);
                }
                j_ghb9foiw = (4 + 6);
                break;
            case 10:
                (void)printf("%s\n", j_dc_44());
                j_ghb9foiw = -((0 + 1) ^ (4489 ^ 4489));
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

