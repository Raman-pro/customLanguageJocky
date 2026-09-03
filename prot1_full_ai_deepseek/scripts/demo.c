// JOCKY build 45568764BC7E95ED seed=7 date=2026-09-03 04:45:59
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

static const volatile uint8_t j_enc_0[] = {0xC5, 0xC4, 0xC7, 0xC6, 0xC1, 0xC0, 0xC3, 0xC2, 0xCD, 0xCC, 0x94, 0x97, 0x96, 0x91, 0x90, 0x93};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 245;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x1A, 0x1B, 0x18, 0x19, 0x1E, 0x1F, 0x1C, 0x1D, 0x12, 0x13, 0x4B, 0x48, 0x49, 0x4E, 0x4F, 0x4C};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 42;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xB1, 0xA1};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 195;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0xC8, 0xDD};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 191;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0x8E, 0xD1, 0xD3, 0xCE, 0xC2};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 161;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0x0D};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 127;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x03};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 9;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x27};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 85;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xB6};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 137;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0x22, 0x27, 0x3D, 0x3A, 0x2B, 0x20};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 110;
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x67, 0x71, 0x76, 0x63, 0x60, 0x6E, 0x6B, 0x71, 0x6A, 0x67, 0x66};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 34;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0xD5, 0xDA, 0xD9, 0xC5, 0xD3, 0xC9, 0xC1, 0xD7, 0xDF, 0xC2};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 150;
    j_rb[10] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xEB, 0xF6, 0xF2, 0xFA, 0xE0, 0xE8, 0xFE, 0xF6, 0xEB};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 191;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x48, 0x53, 0x4F, 0x42, 0x55};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 7;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x69, 0x62, 0x73, 0x74, 0x73, 0x66, 0x73, 0x27, 0x2A, 0x66, 0x69, 0x27, 0x2A, 0x77, 0x27, 0x73, 0x64, 0x77, 0x27, 0x35, 0x39, 0x28, 0x63, 0x62, 0x71, 0x28, 0x69, 0x72, 0x6B, 0x6B};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 7;
    j_rb[30] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xA2};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 208;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x9D, 0x8A, 0x99};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 233;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x2D, 0x72, 0x70, 0x6D, 0x61, 0x2D, 0x6C, 0x67, 0x76, 0x2D, 0x76, 0x61, 0x72};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 2;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0xE5, 0xBA, 0xB8, 0xA5, 0xA9, 0xE5, 0xA4, 0xAF, 0xBE, 0xE5, 0xBE, 0xA9, 0xBA, 0xFC};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 202;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x39, 0x3A, 0x3D, 0x3C, 0x2D};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 113;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0xB8, 0xBB, 0xB3, 0xA5, 0xAC};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 240;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0xAA, 0xA9, 0xA1, 0xB0, 0xBE};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 226;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xF3, 0xF0, 0xEE, 0xE7};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 187;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xE5, 0xF0};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 146;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xF9, 0xFF, 0xF8, 0xE8};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 141;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x41, 0x46, 0x4B, 0x54, 0x42};
static const char* j_dc_25(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 39;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 235;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x1B, 0x1C, 0x11, 0x0E, 0x18};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 125;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x20, 0x26, 0x21, 0x31};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 84;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0xB1, 0xB6, 0xBB, 0xA4, 0xB2};
static const char* j_dc_29(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 215;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_30(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 131;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 181;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x7C, 0x7A, 0x7D, 0x6D};
static const char* j_dc_32(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 8;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x59, 0x5E, 0x53, 0x4C, 0x5A};
static const char* j_dc_33(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 63;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_34(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 248;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x2E, 0x29, 0x24, 0x3B, 0x2D};
static const char* j_dc_35(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 72;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xE3, 0xE5, 0xE2, 0xF2};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 151;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x5E, 0x59, 0x54, 0x4B, 0x5D};
static const char* j_dc_37(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 56;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0x72, 0x74, 0x73, 0x63};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 6;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x4F, 0x48, 0x45, 0x5A, 0x4C};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 41;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x9E, 0x98, 0x9F, 0x8F};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 234;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x96, 0x91, 0x9C, 0x83, 0x95};
static const char* j_dc_41(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 240;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x36, 0x33, 0x3F, 0x37, 0x25, 0x5C, 0x1A, 0x13, 0x0E, 0x19, 0x12, 0x0F, 0x15, 0x1F, 0x5C, 0x10, 0x1D, 0x12, 0x1B, 0x09, 0x1D, 0x1B, 0x19, 0x5C, 0x0A, 0x4C, 0x52, 0x4D};
static const char* j_dc_42(void) {
    static char j_rb[29];
    for (int j_i = 0; j_i < 28; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 124;
    j_rb[28] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x4D, 0x4B, 0x4C, 0x5C};
static const char* j_dc_43(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 57;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x97, 0x90, 0x9D, 0x82, 0x94};
static const char* j_dc_44(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 241;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x18, 0x1E, 0x19, 0x09};
static const char* j_dc_45(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 108;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_46(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ 58;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x59, 0x5F, 0x58, 0x48};
static const char* j_dc_47(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 45;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x35, 0x32, 0x3F, 0x20, 0x36};
static const char* j_dc_48(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 83;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0xDA, 0xDC, 0xDB, 0xCB};
static const char* j_dc_49(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 174;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x40, 0x47, 0x4A, 0x55, 0x43};
static const char* j_dc_50(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 38;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x8E, 0x88, 0x8F, 0x9F};
static const char* j_dc_51(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 250;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x29, 0x2E, 0x23, 0x3C, 0x2A};
static const char* j_dc_52(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 79;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x2E, 0x2C, 0x37, 0x33, 0x3B};
static const char* j_dc_53(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 94;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xE6, 0xE0, 0xE7, 0xF7};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 146;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x74, 0x73, 0x7E, 0x61, 0x77};
static const char* j_dc_55(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 18;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_56(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 243;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x05, 0x02, 0x0F, 0x10, 0x06};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 99;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_58(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0x4D, 0x4A, 0x47, 0x58, 0x4E};
static const char* j_dc_59(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 43;
    j_rb[5] = 0;
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

static volatile int32_t j_raojhvw9 = 801;
static volatile int32_t j_cxtij2d0 = 31960;

static bool j_1gg4zy7k(int32_t j_vuw7p4af);
static int32_t j_r7dcnie5(int32_t j_v61ud416);

static bool j_1gg4zy7k(int32_t j_vuw7p4af)
{
    int32_t j_rshy40ya = 0;
    while ((j_rshy40ya != -1))
    {
        switch (j_rshy40ya)
        {
            case 0:
                if ((j_vuw7p4af < 2))
                {
                    return false;
                }
                j_rshy40ya = 1;
                break;
            case 1:
                static volatile int64_t j_g5obeq90 = 54881;
                static volatile int64_t j_6qbti3fk = 19557;
                if ((((j_6qbti3fk * j_6qbti3fk) + j_6qbti3fk) < 0))
                {
                    volatile int64_t j_ui2i8487 = ((j_6qbti3fk * 61) + 557);
                    (void)printf("%s\n", 0 ? j_dc_24() : j_dc_25());
                }
                j_rshy40ya = 2;
                break;
            case 2:
                if ((((j_g5obeq90 * (j_g5obeq90 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_26() : j_dc_27());
                }
                j_rshy40ya = 3;
                break;
            case 3:
                int32_t j_n9rjprzt = 2;
                while (((j_n9rjprzt * j_n9rjprzt) <= j_vuw7p4af))
                {
                    if (((j_vuw7p4af % j_n9rjprzt) == 0))
                    {
                        return false;
                    }
                    j_n9rjprzt = (j_n9rjprzt + 1);
                }
                j_rshy40ya = 4;
                break;
            case 4:
                static volatile int64_t j_0awj4zme = 72747;
                if ((((j_0awj4zme * j_0awj4zme) + j_0awj4zme) < 0))
                {
                    volatile int64_t j_zz654elg = ((j_0awj4zme * 55) + 747);
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_rshy40ya = 5;
                break;
            case 5:
                return true;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_r7dcnie5(int32_t j_v61ud416)
{
    int32_t j_32nx10y6 = 0;
    while ((j_32nx10y6 != -1))
    {
        switch (j_32nx10y6)
        {
            case 0:
                static volatile int64_t j_g1n65ch6 = 96490;
                static volatile int64_t j_52w1jwrh = 4976;
                if ((((j_52w1jwrh * j_52w1jwrh) + j_52w1jwrh) < 0))
                {
                    volatile int64_t j_q5zfgl0g = ((j_52w1jwrh * 28) + 976);
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_32nx10y6 = 1;
                break;
            case 1:
                if ((((j_g1n65ch6 * j_g1n65ch6) + j_g1n65ch6) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_32nx10y6 = 2;
                break;
            case 2:
                int32_t j_azbz09tc = 0;
                for (int32_t j_sj29oxhz = 0; (j_sj29oxhz < j_v61ud416); j_sj29oxhz = (j_sj29oxhz + 1))
                {
                    j_azbz09tc = (j_azbz09tc + j_sj29oxhz);
                }
                j_32nx10y6 = 3;
                break;
            case 3:
                static volatile int64_t j_5ug1d6wt = 73884;
                if ((((j_5ug1d6wt * j_5ug1d6wt) + j_5ug1d6wt) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_34() : j_dc_35());
                }
                j_32nx10y6 = 4;
                break;
            case 4:
                static volatile int64_t j_armn7lt1 = 76722;
                if ((((j_armn7lt1 * (j_armn7lt1 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_36() : j_dc_37());
                }
                j_32nx10y6 = 5;
                break;
            case 5:
                return j_azbz09tc;
                break;
            case 6:
                static volatile int64_t j_s290tspo = 38817;
                static volatile int64_t j_q3v0kszc = 75563;
                if ((((j_q3v0kszc * j_q3v0kszc) + j_q3v0kszc) < 0))
                {
                    volatile int64_t j_52itf1cb = ((j_q3v0kszc * 70) + 563);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_32nx10y6 = 7;
                break;
            case 7:
                if ((((j_s290tspo * j_s290tspo) + j_s290tspo) < 0))
                {
                    volatile int64_t j_5pveza24 = ((j_s290tspo * 84) + 817);
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_32nx10y6 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

int32_t main(void)
{
    int32_t j_c0s7icbl = 0;
    while ((j_c0s7icbl != -1))
    {
        switch (j_c0s7icbl)
        {
            case 0:
                const char* j_mb4hg3n0 = j_dc_42();
                static volatile int64_t j_bcdpe9pk = 22618;
                if ((((j_bcdpe9pk * j_bcdpe9pk) + j_bcdpe9pk) < 0))
                {
                    volatile int64_t j_myk70g1l = ((j_bcdpe9pk * 71) + 618);
                    (void)printf("%s\n", 0 ? j_dc_43() : j_dc_44());
                }
                j_c0s7icbl = 1;
                break;
            case 1:
                int32_t j_izx0t6up = j_r7dcnie5(10);
                static volatile int64_t j_xe5mwy7c = 33602;
                static volatile int64_t j_wzoz3acc = 61108;
                if ((((j_wzoz3acc * j_wzoz3acc) + j_wzoz3acc) < 0))
                {
                    volatile int64_t j_xvhe3dow = ((j_wzoz3acc * 80) + 108);
                    (void)printf("%s\n", 0 ? j_dc_45() : j_dc_46());
                }
                j_c0s7icbl = 2;
                break;
            case 2:
                if ((((j_xe5mwy7c * j_xe5mwy7c) + j_xe5mwy7c) < 0))
                {
                    volatile int64_t j_bc7j5prq = ((j_xe5mwy7c * 52) + 602);
                    (void)printf("%s\n", 0 ? j_dc_47() : j_dc_48());
                }
                j_c0s7icbl = 3;
                break;
            case 3:
                static volatile int64_t j_xw6laelx = 67452;
                static volatile int64_t j_q3wjo41b = 92791;
                if ((((j_q3wjo41b * j_q3wjo41b) + j_q3wjo41b) < 0))
                {
                    volatile int64_t j_ue63jahe = ((j_q3wjo41b * 21) + 791);
                    (void)printf("%s\n", 0 ? j_dc_49() : j_dc_50());
                }
                j_c0s7icbl = 4;
                break;
            case 4:
                if ((((j_xw6laelx * j_xw6laelx) % 4) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_51() : j_dc_52());
                }
                j_c0s7icbl = 5;
                break;
            case 5:
                (void)printf("%s\n", j_mb4hg3n0);
                (void)printf("%d\n", j_izx0t6up);
                const char* j_adjm9rcj = j_dc_53();
                static volatile int64_t j_5ecj60ym = 40076;
                if ((((j_5ecj60ym * j_5ecj60ym) + j_5ecj60ym) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_54() : j_dc_55());
                }
                j_c0s7icbl = 6;
                break;
            case 6:
                if ((j_1gg4zy7k(7) && (j_str_len(j_adjm9rcj) == 5)))
                {
                    (void)printf("%s\n", true ? j_dc_56() : j_dc_57());
                }
                else
                {
                    (void)printf("%s\n", false ? j_dc_58() : j_dc_59());
                }
                j_c0s7icbl = 7;
                break;
            case 7:
                int32_t j_2zrufqur = 0;
                int32_t j_vuw7p4af = 2;
                while ((j_2zrufqur < 3))
                {
                    if (j_1gg4zy7k(j_vuw7p4af))
                    {
                        (void)printf("%d\n", j_vuw7p4af);
                        j_2zrufqur = (j_2zrufqur + 1);
                    }
                    j_vuw7p4af = (j_vuw7p4af + 1);
                }
                j_c0s7icbl = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}
