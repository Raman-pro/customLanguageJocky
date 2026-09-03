// JOCKY build AC4DFB46A4859EB6 seed=5 date=2026-09-03 03:54:30
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

static const volatile uint8_t j_enc_0[] = {0xF4, 0xF5, 0xF6, 0xF7, 0xF0, 0xF1, 0xF2, 0xF3, 0xFC, 0xFD, 0xA5, 0xA6, 0xA7, 0xA0, 0xA1, 0xA2};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ ((114 + 82) ^ (1282 ^ 1282));
    j_rb[(9 + 7)] = ((0 + 0) ^ (2776 ^ 2776));
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0xCE, 0xCF, 0xCC, 0xCD, 0xCA, 0xCB, 0xC8, 0xC9, 0xC6, 0xC7, 0x9F, 0x9C, 0x9D, 0x9A, 0x9B, 0x98};
static const char* j_dc_1(void) {
    static char j_rb[(7 + 10)];
    for (int j_i = (0 + 0); j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 254;
    j_rb[(9 + 7)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x69, 0x79};
static const char* j_dc_2(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = (0 + 0); j_i < ((0 + 2) ^ (3606 ^ 3606)); j_i++) j_rb[j_i] = j_enc_2[j_i] ^ (15 + 12);
    j_rb[((1 + 1) ^ (4375 ^ 4375))] = ((0 + 0) ^ (7612 ^ 7612));
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x6D, 0x78};
static const char* j_dc_3(void) {
    static char j_rb[(2 + 1)];
    for (int j_i = 0; j_i < (0 + 2); j_i++) j_rb[j_i] = j_enc_3[j_i] ^ (1 + 25);
    j_rb[((1 + 1) ^ (1520 ^ 1520))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0x99, 0xC6, 0xC4, 0xD9, 0xD5};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 182;
    j_rb[5] = ((0 + 0) ^ (2722 ^ 2722));
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDE};
static const char* j_dc_5(void) {
    static char j_rb[((1 + 1) ^ (4563 ^ 4563))];
    for (int j_i = ((0 + 0) ^ (1665 ^ 1665)); j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 172;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x85};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 143;
    j_rb[(1 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8F};
static const char* j_dc_7(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = ((0 + 0) ^ (3019 ^ 3019)); j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 253;
    j_rb[(1 + 0)] = ((0 + 0) ^ (4317 ^ 4317));
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xF0};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ ((149 + 58) ^ (2461 ^ 2461));
    j_rb[((1 + 0) ^ (1072 ^ 1072))] = ((0 + 0) ^ (1637 ^ 1637));
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0x50, 0x55, 0x4F, 0x48, 0x59, 0x52};
static const char* j_dc_9(void) {
    static char j_rb[(4 + 3)];
    for (int j_i = 0; j_i < ((3 + 3) ^ (9360 ^ 9360)); j_i++) j_rb[j_i] = j_enc_9[j_i] ^ ((5 + 23) ^ (4967 ^ 4967));
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0xAD, 0xBB, 0xBC, 0xA9, 0xAA, 0xA4, 0xA1, 0xBB, 0xA0, 0xAD, 0xAC};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (3003 ^ 3003)); j_i < ((10 + 1) ^ (5801 ^ 5801)); j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 232;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0xD5, 0xDA, 0xD9, 0xC5, 0xD3, 0xC9, 0xC1, 0xD7, 0xDF, 0xC2};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < (5 + 5); j_i++) j_rb[j_i] = j_enc_11[j_i] ^ (43 + 107);
    j_rb[((0 + 10) ^ (8151 ^ 8151))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xD8, 0xC5, 0xC1, 0xC9, 0xD3, 0xDB, 0xCD, 0xC5, 0xD8};
static const char* j_dc_12(void) {
    static char j_rb[((6 + 4) ^ (7714 ^ 7714))];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ ((45 + 95) ^ (6366 ^ 6366));
    j_rb[((1 + 8) ^ (4523 ^ 4523))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0F, 0x14, 0x08, 0x05, 0x12};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 64;
    j_rb[((4 + 1) ^ (1101 ^ 1101))] = ((0 + 0) ^ (1948 ^ 1948));
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0xB4, 0xBF, 0xAE, 0xA9, 0xAE, 0xBB, 0xAE, 0xFA, 0xF7, 0xBB, 0xB4, 0xFA, 0xF7, 0xAA, 0xFA, 0xAE, 0xB9, 0xAA, 0xFA, 0xE8, 0xE4, 0xF5, 0xBE, 0xBF, 0xAC, 0xF5, 0xB4, 0xAF, 0xB6, 0xB6};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = (0 + 0); j_i < ((2 + 28) ^ (6812 ^ 6812)); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 218;
    j_rb[30] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xE4};
static const char* j_dc_15(void) {
    static char j_rb[((2 + 0) ^ (1678 ^ 1678))];
    for (int j_i = (0 + 0); j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 150;
    j_rb[((1 + 0) ^ (7203 ^ 7203))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x9E, 0x89, 0x9A};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = (0 + 0); j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 234;
    j_rb[(0 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x74, 0x2B, 0x29, 0x34, 0x38, 0x74, 0x35, 0x3E, 0x2F, 0x74, 0x2F, 0x38, 0x2B};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = ((0 + 0) ^ (1588 ^ 1588)); j_i < (2 + 11); j_i++) j_rb[j_i] = j_enc_17[j_i] ^ ((46 + 45) ^ (9954 ^ 9954));
    j_rb[((5 + 8) ^ (2563 ^ 2563))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x9A, 0xC5, 0xC7, 0xDA, 0xD6, 0x9A, 0xDB, 0xD0, 0xC1, 0x9A, 0xC1, 0xD6, 0xC5, 0x83};
static const char* j_dc_18(void) {
    static char j_rb[(7 + 8)];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 181;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x64, 0x67, 0x60, 0x61, 0x70};
static const char* j_dc_19(void) {
    static char j_rb[((1 + 5) ^ (8173 ^ 8173))];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_19[j_i] ^ (26 + 18);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x2C, 0x2F, 0x27, 0x31, 0x38};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 100;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0xCE, 0xCD, 0xC5, 0xD4, 0xDA};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ (79 + 55);
    j_rb[(4 + 1)] = ((0 + 0) ^ (2713 ^ 2713));
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x54, 0x57, 0x49, 0x40};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2778 ^ 2778)); j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 28;
    j_rb[(3 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xFF, 0xEA};
static const char* j_dc_23(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = ((0 + 0) ^ (9745 ^ 9745)); j_i < ((1 + 1) ^ (724 ^ 724)); j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 136;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xBF, 0xBF, 0xA2, 0xF1, 0xFB, 0xF1, 0xAC, 0xEC, 0xED, 0xF5, 0xAA, 0xAB, 0xA2, 0xBF, 0xBF};
static const char* j_dc_24(void) {
    static char j_rb[((6 + 10) ^ (1159 ^ 1159))];
    for (int j_i = 0; j_i < (12 + 3); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ (101 + 29);
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x71, 0x71, 0x6C, 0x3F, 0x35, 0x3F, 0x62, 0x2F, 0x3B, 0x28, 0x64, 0x65, 0x6C, 0x71, 0x71};
static const char* j_dc_25(void) {
    static char j_rb[16];
    for (int j_i = ((0 + 0) ^ (5933 ^ 5933)); j_i < 15; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 76;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0xA2, 0xA2, 0xBF, 0xFA, 0xF1, 0xE9, 0xB1, 0xF8, 0xFA, 0xEB, 0xB7, 0xB6, 0xBF, 0xA2, 0xA2};
static const char* j_dc_26(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < (11 + 4); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 159;
    j_rb[((0 + 15) ^ (1513 ^ 1513))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x94, 0x92, 0x84, 0x93};
static const char* j_dc_27(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x38, 0x39, 0x22, 0x29, 0x37, 0x29, 0x24, 0x33, 0x37, 0x3A, 0x29, 0x20, 0x37, 0x24};
static const char* j_dc_28(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((18 + 100) ^ (4124 ^ 4124));
    j_rb[14] = ((0 + 0) ^ (8044 ^ 8044));
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x32, 0x32, 0x2F, 0x7C, 0x76, 0x7C, 0x21, 0x7C, 0x63, 0x6A, 0x6A, 0x7F, 0x27, 0x26, 0x2F, 0x32, 0x32};
static const char* j_dc_29(void) {
    static char j_rb[18];
    for (int j_i = (0 + 0); j_i < 17; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ (9 + 6);
    j_rb[(17 + 0)] = ((0 + 0) ^ (6151 ^ 6151));
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xFB, 0xE4, 0xED, 0xF8, 0xFC, 0xA8, 0xBA, 0xB8, 0xB8, 0xE5, 0xFB};
static const char* j_dc_30(void) {
    static char j_rb[(9 + 3)];
    for (int j_i = ((0 + 0) ^ (2589 ^ 2589)); j_i < 11; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 136;
    j_rb[(3 + 8)] = ((0 + 0) ^ (8631 ^ 8631));
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0xC5, 0xC3, 0xC4, 0xD4};
static const char* j_dc_31(void) {
    static char j_rb[((1 + 4) ^ (8722 ^ 8722))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ ((136 + 41) ^ (2938 ^ 2938));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x34, 0x33, 0x3E, 0x21, 0x37};
static const char* j_dc_32(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5829 ^ 5829)); j_i < 5; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 82;
    j_rb[5] = ((0 + 0) ^ (9322 ^ 9322));
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xCE, 0xCE, 0xD3, 0x80, 0x8A, 0x80, 0xDD, 0x83, 0x81, 0x9C, 0x90, 0x96, 0x80, 0x80, 0xAC, 0x9F, 0x9A, 0x80, 0x87, 0xDB, 0xDA, 0xD3, 0xCE, 0xCE};
static const char* j_dc_33(void) {
    static char j_rb[25];
    for (int j_i = (0 + 0); j_i < 24; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ (50 + 193);
    j_rb[24] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x19, 0x19, 0x04, 0x4A, 0x41, 0x50, 0x0A, 0x57, 0x4B, 0x47, 0x4F, 0x41, 0x50, 0x57, 0x0C, 0x0D, 0x04, 0x19, 0x19};
static const char* j_dc_34(void) {
    static char j_rb[(15 + 5)];
    for (int j_i = (0 + 0); j_i < ((19 + 0) ^ (5892 ^ 5892)); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 36;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x11, 0x11, 0x0C, 0x4A, 0x5F, 0x02, 0x5B, 0x5E, 0x45, 0x58, 0x49, 0x0C, 0x03, 0x0C, 0x4A, 0x5F, 0x02, 0x5E, 0x49, 0x4D, 0x48, 0x0C, 0x11, 0x11};
static const char* j_dc_35(void) {
    static char j_rb[(0 + 25)];
    for (int j_i = (0 + 0); j_i < 24; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ (24 + 20);
    j_rb[24] = ((0 + 0) ^ (5370 ^ 5370));
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x9B, 0xC0, 0xD9, 0xC4, 0x9B, 0xDE, 0xDB, 0xD7, 0xDF, 0xCD, 0xEB, 0xC7, 0xCD, 0xC7, 0xC0, 0xD1, 0xD9, 0xEB, 0xC0, 0xDB, 0xC1, 0xC6, 0x9A, 0xC0, 0xCC, 0xC0};
static const char* j_dc_36(void) {
    static char j_rb[27];
    for (int j_i = (0 + 0); j_i < 26; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ ((60 + 120) ^ (2455 ^ 2455));
    j_rb[26] = ((0 + 0) ^ (2999 ^ 2999));
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x96, 0x9B, 0x92, 0x92, 0x91, 0xDE, 0x98, 0x8C, 0x91, 0x93, 0xDE, 0x8D, 0x87, 0x8D, 0x8A, 0x9B, 0x93, 0xDE, 0x8A, 0x91, 0x8B, 0x8C, 0xF4};
static const char* j_dc_37(void) {
    static char j_rb[24];
    for (int j_i = (0 + 0); j_i < ((8 + 15) ^ (4874 ^ 4874)); j_i++) j_rb[j_i] = j_enc_37[j_i] ^ (234 + 20);
    j_rb[(17 + 6)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xC6, 0xC0, 0xC7, 0xD7};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2718 ^ 2718)); j_i < ((0 + 4) ^ (3266 ^ 3266)); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 178;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0xAE, 0xA9, 0xA4, 0xBB, 0xAD};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((2 + 3) ^ (5757 ^ 5757)); j_i++) j_rb[j_i] = j_enc_39[j_i] ^ ((36 + 164) ^ (1119 ^ 1119));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x76, 0x2D, 0x34, 0x29, 0x76, 0x33, 0x36, 0x3A, 0x32, 0x20, 0x06, 0x2A, 0x20, 0x2A, 0x2D, 0x3C, 0x34, 0x06, 0x2D, 0x36, 0x2C, 0x2B, 0x77, 0x2D, 0x21, 0x2D};
static const char* j_dc_40(void) {
    static char j_rb[(23 + 4)];
    for (int j_i = 0; j_i < ((18 + 8) ^ (5285 ^ 5285)); j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 89;
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x93, 0x93, 0x8E, 0xC8, 0xDD, 0x80, 0xCB, 0xD6, 0xC7, 0xDD, 0xDA, 0xDD, 0x8E, 0x93, 0x93};
static const char* j_dc_41(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 174;
    j_rb[(3 + 12)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xBC, 0xE7, 0xFE, 0xE3, 0xBC, 0xF9, 0xFC, 0xF0, 0xF8, 0xEA, 0xCC, 0xE0, 0xEA, 0xE0, 0xE7, 0xF6, 0xFE, 0xCC, 0xE7, 0xFC, 0xE6, 0xE1, 0xBD, 0xE7, 0xEB, 0xE7};
static const char* j_dc_42(void) {
    static char j_rb[27];
    for (int j_i = 0; j_i < 26; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 147;
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0xC8, 0xCE, 0xC9, 0xD9};
static const char* j_dc_43(void) {
    static char j_rb[((2 + 3) ^ (2300 ^ 2300))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 188;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x4F, 0x48, 0x45, 0x5A, 0x4C};
static const char* j_dc_44(void) {
    static char j_rb[((4 + 2) ^ (661 ^ 661))];
    for (int j_i = (0 + 0); j_i < ((4 + 1) ^ (5453 ^ 5453)); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ (35 + 6);
    j_rb[(1 + 4)] = ((0 + 0) ^ (1717 ^ 1717));
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x33, 0x72, 0x73, 0x33, 0x6F, 0x69, 0x7F, 0x74, 0x33, 0x6C, 0x7D, 0x68, 0x74};
static const char* j_dc_45(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 28;
    j_rb[(2 + 11)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x27, 0x21, 0x26, 0x36};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_46[j_i] ^ (64 + 19);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x1A, 0x1D, 0x10, 0x0F, 0x19};
static const char* j_dc_47(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((2 + 3) ^ (5929 ^ 5929)); j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 124;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0xF5, 0xF5, 0xE8, 0xAE, 0xBB, 0xE6, 0xA4, 0xA1, 0xBB, 0xBC, 0xE8, 0xF5, 0xF5};
static const char* j_dc_48(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < (5 + 8); j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 200;
    j_rb[(9 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x9E, 0xC5, 0xDC, 0xC1};
static const char* j_dc_49(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (4682 ^ 4682)); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 177;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0xB9, 0xB9, 0xA4, 0xF6, 0xE1, 0xE3, 0xAA, 0xE8, 0xED, 0xF7, 0xF0, 0xA4, 0xAC, 0xD3, 0xED, 0xEA, 0xE0, 0xEB, 0xF3, 0xF7, 0xA4, 0xEB, 0xEA, 0xE8, 0xFD, 0xAD, 0xA4, 0xB9, 0xB9};
static const char* j_dc_50(void) {
    static char j_rb[30];
    for (int j_i = ((0 + 0) ^ (526 ^ 526)); j_i < 29; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ (39 + 93);
    j_rb[(8 + 21)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x16, 0x15, 0x12, 0x13, 0x02, 0x0D, 0x11, 0x18, 0x0A, 0x09, 0x1F, 0x0C, 0x1B, 0x02, 0x13, 0x37, 0x3D, 0x2C, 0x31, 0x2D, 0x31, 0x38, 0x2A};
static const char* j_dc_51(void) {
    static char j_rb[24];
    for (int j_i = 0; j_i < (6 + 17); j_i++) j_rb[j_i] = j_enc_51[j_i] ^ (30 + 64);
    j_rb[23] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x9D, 0x9B, 0x9C, 0x8C};
static const char* j_dc_52(void) {
    static char j_rb[((2 + 3) ^ (9727 ^ 9727))];
    for (int j_i = (0 + 0); j_i < ((3 + 1) ^ (9834 ^ 9834)); j_i++) j_rb[j_i] = j_enc_52[j_i] ^ ((74 + 159) ^ (8854 ^ 8854));
    j_rb[(1 + 3)] = ((0 + 0) ^ (3117 ^ 3117));
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0xEB, 0xEC, 0xE1, 0xFE, 0xE8};
static const char* j_dc_53(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 141;
    j_rb[5] = ((0 + 0) ^ (3298 ^ 3298));
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xF0, 0xF0, 0xED, 0xA0, 0xA8, 0xA0, 0xE3, 0xA9, 0xB8, 0xA0, 0xBD, 0xED, 0xE5, 0x9A, 0xA4, 0xA3, 0xA9, 0xA2, 0xBA, 0xBE, 0xED, 0xA2, 0xA3, 0xA1, 0xB4, 0xE4, 0xED, 0xF0, 0xF0};
static const char* j_dc_54(void) {
    static char j_rb[(23 + 7)];
    for (int j_i = 0; j_i < ((0 + 29) ^ (7161 ^ 7161)); j_i++) j_rb[j_i] = j_enc_54[j_i] ^ (19 + 186);
    j_rb[29] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x1A, 0x41, 0x58, 0x45, 0x1A, 0x5F, 0x5A, 0x56, 0x5E, 0x4C, 0x6A, 0x58, 0x50, 0x58, 0x1B, 0x57, 0x5C, 0x5B};
static const char* j_dc_55(void) {
    static char j_rb[19];
    for (int j_i = ((0 + 0) ^ (5947 ^ 5947)); j_i < 18; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ ((6 + 47) ^ (7230 ^ 7230));
    j_rb[18] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xAB, 0xA0, 0xA1, 0xAA};
static const char* j_dc_56(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 207;
    j_rb[(3 + 1)] = ((0 + 0) ^ (7352 ^ 7352));
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == (0 + 0); }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = ((0 + 0) ^ (5491 ^ 5491));
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
                    out[o++] = j_dc_0()[c >> ((1 + 3) ^ (2222 ^ 2222))];
                    out[o++] = j_dc_1()[c & ((9 + 6) ^ (9616 ^ 9616))];
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
    return access(path, F_OK) == (0 + 0);
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
    size_t off = ((0 + 0) ^ (5501 ^ 5501));
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[((713 + 311) ^ (6731 ^ 6731))];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[((0 + 0) ^ (6040 ^ 6040))] == '.') continue;
            if (off > J_BUF_CAP - (53 + 147)) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[((340 + 684) ^ (3569 ^ 3569))];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (9925 ^ 9925)) ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - (120 + 80)) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[(758 + 266)];
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
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[(550 + 474)];
                size_t k = ((0 + 0) ^ (7085 ^ 7085));
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (5095 ^ 5095)));
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[((353 + 7839) ^ (8821 ^ 8821))];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[((82 + 174) ^ (8532 ^ 8532))];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[((177 + 335) ^ (5493 ^ 5493))];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : (0 + 0));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[(13 + 51)], name[(210 + 46)];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[((379 + 133) ^ (5922 ^ 5922))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (6730 ^ 6730)));
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
    char line[((405 + 107) ^ (9121 ^ 9121))];
    int skip = ((0 + 1) ^ (5850 ^ 5850));
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[((37 + 27) ^ (4550 ^ 4550))], raddr[((46 + 18) ^ (897 ^ 897))], st[(8 + 8)];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - (168 + 132)) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : ((0 + 0) ^ (6318 ^ 6318)));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = (1 + 0);
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (7854 ^ 7854)));
    char* t = (char*)malloc(sz ? sz : ((0 + 1) ^ (7551 ^ 7551)));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (7586 ^ 7586))) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[((64 + 0) ^ (3632 ^ 3632))];
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
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (8585 ^ 8585));
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
            char proto[(6 + 2)], laddr[64], raddr[64], st[((11 + 21) ^ (5970 ^ 5970))];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == (3 + 1)) {
                if (strncmp(proto, j_dc_16(), (1 + 2)) != (0 + 0)) continue;
                if (off > J_BUF_CAP - (179 + 121)) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : (0 + 0));
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
    size_t off = ((0 + 0) ^ (3040 ^ 3040));
    j_buf[off++] = '[';
    int first = ((0 + 1) ^ (8002 ^ 8002));
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), (5 + 0)) == (0 + 0)) { root = HKEY_LOCAL_MACHINE; sub = key + ((2 + 3) ^ (4609 ^ 4609)); }
    else if (strncmp(key, j_dc_20(), ((5 + 0) ^ (7429 ^ 7429))) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + (0 + 5); }
    else if (strncmp(key, j_dc_22(), 4) == (0 + 0)) { root = HKEY_USERS; sub = key + (3 + 1); }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, (0 + 0), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = ((0 + 0) ^ (5890 ^ 5890)); ; ++i) {
            char s[((201 + 55) ^ (4396 ^ 4396))];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - (289 + 111)) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
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
    unsigned long regions = (0 + 0);
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < ((60742 + 39258) ^ (9877 ^ 9877))) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = ((0 + 0) ^ (6025 ^ 6025));
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

static volatile int32_t j_eu86fdnm = (23866 + 23851);
static volatile int32_t j_e8lb4fzb = 42493;

__attribute__((used)) static int32_t j_z_p1k046(int32_t j_a, int32_t j_b) {
    int32_t j_r = (0 + 0);
    for (int32_t j_i = 0; j_i < j_a; j_i++) {
        j_r = j_r + j_b;
        if (j_r > 1000) j_r = j_r - (974 + 26);
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_iimuue(int32_t j_n) {
    int32_t j_s = ((0 + 0) ^ (2741 ^ 2741));
    int32_t j_i = ((1 + 0) ^ (1370 ^ 1370));
    while (j_i <= j_n) {
        if ((j_i % 3) == ((0 + 0) ^ (7153 ^ 7153))) j_s = j_s + j_i;
        else j_s = j_s + j_i * (1 + 1);
        j_i = j_i + ((1 + 0) ^ (1157 ^ 1157));
    }
    return j_s;
}

static int32_t j_tr_90wra8(void) {
    int32_t j_yoegwk9g = (0 + 0);
    while ((j_yoegwk9g != -((1 + 0) ^ (8702 ^ 8702))))
    {
        switch (j_yoegwk9g)
        {
            case 0:
                (void)printf("%s\n", j_dc_24());
                (void)printf("%s\n", j_sys_now());
                static volatile int64_t j_skcdv8tg = 64313;
                if ((((j_skcdv8tg * j_skcdv8tg) + j_skcdv8tg) >= 0))
                {
                    (void)printf("%s\n", j_dc_25());
                }
                else
                {
                    volatile int64_t j_ts69rxxk = ((j_skcdv8tg * (1 + 1)) + 1);
                }
                j_yoegwk9g = (0 + 1);
                break;
            case 1:
                (void)printf("%s\n", j_sys_cwd());
                static volatile int64_t j_avqzlje8 = (23658 + 33338);
                if ((((j_avqzlje8 * j_avqzlje8) + j_avqzlje8) >= 0))
                {
                    (void)printf("%s\n", j_dc_26());
                }
                else
                {
                    volatile int64_t j_fttjbxl0 = ((j_avqzlje8 * (0 + 2)) + (0 + 1));
                }
                j_yoegwk9g = (2 + 0);
                break;
            case 2:
                (void)printf("%s\n", j_env_get(j_dc_27()));
                (void)printf("%s\n", j_env_get(j_dc_28()));
                (void)printf("%s\n", j_dc_29());
                (void)j_sys_sleep(200);
                static volatile int64_t j_feud84mg = 40802;
                if ((((j_feud84mg * j_feud84mg) + j_feud84mg) >= (0 + 0)))
                {
                    (void)printf("%s\n", j_dc_30());
                }
                else
                {
                    volatile int64_t j_x93k13me = ((j_feud84mg * (2 + 0)) + 1);
                }
                j_yoegwk9g = (2 + 1);
                break;
            case 3:
                static volatile int64_t j_j7bdkrjo = (14957 + 78763);
                if ((((j_j7bdkrjo * j_j7bdkrjo) % ((2 + 2) ^ (3491 ^ 3491))) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_31() : j_dc_32());
                }
                j_yoegwk9g = 4;
                break;
            case 4:
                static volatile int64_t j_vx20kdyj = 65550;
                if ((((j_vx20kdyj * j_vx20kdyj) + j_vx20kdyj) >= 0))
                {
                    (void)printf("%s\n", j_dc_33());
                }
                else
                {
                    volatile int64_t j_essj6r75 = ((j_vx20kdyj * ((2 + 0) ^ (7660 ^ 7660))) + ((1 + 0) ^ (4104 ^ 4104)));
                }
                j_yoegwk9g = 5;
                break;
            case 5:
                static volatile int64_t j_e95ewu13 = (15409 + 3527);
                if ((((j_e95ewu13 * j_e95ewu13) + j_e95ewu13) >= 0))
                {
                    (void)printf("%s\n", j_sys_process_list());
                }
                else
                {
                    volatile int64_t j_6ojr8gh1 = ((j_e95ewu13 * ((1 + 1) ^ (9807 ^ 9807))) + 1);
                }
                j_yoegwk9g = ((5 + 1) ^ (530 ^ 530));
                break;
            case 6:
                (void)printf("%s\n", j_dc_34());
                (void)printf("%s\n", j_net_sockets());
                (void)printf("%s\n", j_dc_35());
                (void)j_fs_write(j_dc_36(), j_dc_37());
                static volatile int64_t j_7kmyszx5 = ((67522 + 14024) ^ (6156 ^ 6156));
                if ((((j_7kmyszx5 * j_7kmyszx5) + j_7kmyszx5) < (0 + 0)))
                {
                    volatile int64_t j_gjsf7rnt = ((j_7kmyszx5 * (25 + 62)) + (30 + 516));
                    (void)printf("%s\n", ((0 + 0) ^ (4820 ^ 4820)) ? j_dc_38() : j_dc_39());
                }
                j_yoegwk9g = ((3 + 4) ^ (5061 ^ 5061));
                break;
            case 7:
                (void)printf("%s\n", j_fs_read(j_dc_40()));
                (void)printf("%s\n", j_dc_41());
                static volatile int64_t j_q4uf8qqq = 70809;
                if ((((j_q4uf8qqq * j_q4uf8qqq) + j_q4uf8qqq) >= (0 + 0)))
                {
                    (void)printf("%s\n", j_fs_exists(j_dc_42()) ? j_dc_43() : j_dc_44());
                }
                else
                {
                    volatile int64_t j_auxxckq7 = ((j_q4uf8qqq * (1 + 1)) + (0 + 1));
                }
                j_yoegwk9g = ((7 + 1) ^ (483 ^ 483));
                break;
            case 8:
                static volatile int64_t j_x441a4vv = ((3 + 40468) ^ (1678 ^ 1678));
                if ((((j_x441a4vv * j_x441a4vv) + j_x441a4vv) >= 0))
                {
                    (void)printf("%s\n", j_fs_exists(j_dc_45()) ? j_dc_46() : j_dc_47());
                }
                else
                {
                    volatile int64_t j_1fiu6z6i = ((j_x441a4vv * ((2 + 0) ^ (2684 ^ 2684))) + 1);
                }
                j_yoegwk9g = 9;
                break;
            case 9:
                static volatile int64_t j_a5qropmu = 79795;
                if ((((j_a5qropmu * j_a5qropmu) + j_a5qropmu) >= 0))
                {
                    (void)printf("%s\n", j_dc_48());
                }
                else
                {
                    volatile int64_t j_cwfqwkyz = ((j_a5qropmu * 2) + 1);
                }
                j_yoegwk9g = 10;
                break;
            case 10:
                static volatile int64_t j_puxy5z2v = ((5734 + 64678) ^ (6592 ^ 6592));
                if ((((j_puxy5z2v * j_puxy5z2v) + j_puxy5z2v) >= (0 + 0)))
                {
                    (void)printf("%s\n", j_fs_list(j_dc_49()));
                }
                else
                {
                    volatile int64_t j_eavo7d68 = ((j_puxy5z2v * ((0 + 2) ^ (4484 ^ 4484))) + ((0 + 1) ^ (4055 ^ 4055)));
                }
                j_yoegwk9g = ((10 + 1) ^ (7387 ^ 7387));
                break;
            case 11:
                static volatile int64_t j_0mykle97 = 29631;
                if ((((j_0mykle97 * j_0mykle97) + j_0mykle97) >= 0))
                {
                    (void)printf("%s\n", j_dc_50());
                }
                else
                {
                    volatile int64_t j_wye4z15l = ((j_0mykle97 * ((1 + 1) ^ (276 ^ 276))) + (1 + 0));
                }
                j_yoegwk9g = 12;
                break;
            case 12:
                (void)printf("%s\n", j_reg_list(j_dc_51()));
                static volatile int64_t j_rg9wqhim = 64893;
                if ((((j_rg9wqhim * j_rg9wqhim) + j_rg9wqhim) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_52() : j_dc_53());
                }
                j_yoegwk9g = (12 + 1);
                break;
            case 13:
                (void)printf("%s\n", j_dc_54());
                (void)j_mem_dump((1 + 0), j_dc_55());
                (void)printf("%s\n", j_dc_56());
                j_yoegwk9g = -(0 + 1);
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}
static int32_t j_tr_p6i3mo(void) { return j_tr_90wra8(); }
static int32_t j_tr_vxbcb4(void) { return j_tr_p6i3mo(); }
static int32_t j_tr_82p71a(void) { return j_tr_vxbcb4(); }
int32_t main(void) { return j_tr_82p71a(); }

