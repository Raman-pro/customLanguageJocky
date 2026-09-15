// JOCKY build 40AF4D522633DDEE seed=424242 date=2026-09-03 13:47:36
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

static const volatile uint8_t j_enc_0[] = {0x7C, 0x7D, 0x7E, 0x7F, 0x78, 0x79, 0x7A, 0x7B, 0x74, 0x75, 0x2D, 0x2E, 0x2F, 0x28, 0x29, 0x2A};
static const char* j_dc_0(void) {
    static char j_rb[((3 + 14) ^ (3507 ^ 3507))];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ ((69 + 7) ^ (6419 ^ 6419));
    j_rb[(3 + 13)] = ((0 + 0) ^ (5802 ^ 5802));
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x06, 0x07, 0x04, 0x05, 0x02, 0x03, 0x00, 0x01, 0x0E, 0x0F, 0x57, 0x54, 0x55, 0x52, 0x53, 0x50};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = (0 + 0); j_i < (2 + 14); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 54;
    j_rb[((15 + 1) ^ (5942 ^ 5942))] = ((0 + 0) ^ (5637 ^ 5637));
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x41, 0x51};
static const char* j_dc_2(void) {
    static char j_rb[((2 + 1) ^ (4047 ^ 4047))];
    for (int j_i = 0; j_i < ((1 + 1) ^ (4796 ^ 4796)); j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 51;
    j_rb[(2 + 0)] = ((0 + 0) ^ (1616 ^ 1616));
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x5F, 0x4A};
static const char* j_dc_3(void) {
    static char j_rb[((0 + 3) ^ (19 ^ 19))];
    for (int j_i = (0 + 0); j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 40;
    j_rb[(0 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xE1, 0xBE, 0xBC, 0xA1, 0xAD};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5549 ^ 5549)); j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 206;
    j_rb[((2 + 3) ^ (9204 ^ 9204))] = ((0 + 0) ^ (9050 ^ 9050));
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0x5B};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_5[j_i] ^ ((20 + 21) ^ (480 ^ 480));
    j_rb[1] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x85};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 143;
    j_rb[(1 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x49};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 59;
    j_rb[1] = ((0 + 0) ^ (7434 ^ 7434));
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x0C};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < ((0 + 1) ^ (5576 ^ 5576)); j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 51;
    j_rb[((0 + 1) ^ (9394 ^ 9394))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xED, 0xE8, 0xF2, 0xF5, 0xE4, 0xEF};
static const char* j_dc_9(void) {
    static char j_rb[(1 + 6)];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 161;
    j_rb[(4 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x05, 0x13, 0x14, 0x01, 0x02, 0x0C, 0x09, 0x13, 0x08, 0x05, 0x04};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (8530 ^ 8530)); j_i < (9 + 2); j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 64;
    j_rb[((4 + 7) ^ (7197 ^ 7197))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x30, 0x3F, 0x3C, 0x20, 0x36, 0x2C, 0x24, 0x32, 0x3A, 0x27};
static const char* j_dc_11(void) {
    static char j_rb[(1 + 10)];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ (71 + 44);
    j_rb[(1 + 9)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xBB, 0xA6, 0xA2, 0xAA, 0xB0, 0xB8, 0xAE, 0xA6, 0xBB};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = ((0 + 0) ^ (6060 ^ 6060)); j_i < (0 + 9); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 239;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x69, 0x72, 0x6E, 0x63, 0x74};
static const char* j_dc_13(void) {
    static char j_rb[((6 + 0) ^ (4854 ^ 4854))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 38;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x45, 0x4E, 0x5F, 0x58, 0x5F, 0x4A, 0x5F, 0x0B, 0x06, 0x4A, 0x45, 0x0B, 0x06, 0x5B, 0x0B, 0x5F, 0x48, 0x5B, 0x0B, 0x19, 0x15, 0x04, 0x4F, 0x4E, 0x5D, 0x04, 0x45, 0x5E, 0x47, 0x47};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < ((5 + 25) ^ (7412 ^ 7412)); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 43;
    j_rb[(23 + 7)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x9D};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = ((0 + 0) ^ (3398 ^ 3398)); j_i < ((0 + 1) ^ (1932 ^ 1932)); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 239;
    j_rb[(0 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0xB9, 0xAE, 0xBD};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ ((158 + 47) ^ (1688 ^ 1688));
    j_rb[3] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x88, 0xD7, 0xD5, 0xC8, 0xC4, 0x88, 0xC9, 0xC2, 0xD3, 0x88, 0xD3, 0xC4, 0xD7};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 167;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x1E, 0x41, 0x43, 0x5E, 0x52, 0x1E, 0x5F, 0x54, 0x45, 0x1E, 0x45, 0x52, 0x41, 0x07};
static const char* j_dc_18(void) {
    static char j_rb[((4 + 11) ^ (2125 ^ 2125))];
    for (int j_i = (0 + 0); j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ ((36 + 13) ^ (8576 ^ 8576));
    j_rb[14] = ((0 + 0) ^ (4132 ^ 4132));
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x1C, 0x1F, 0x18, 0x19, 0x08};
static const char* j_dc_19(void) {
    static char j_rb[((6 + 0) ^ (4234 ^ 4234))];
    for (int j_i = ((0 + 0) ^ (4432 ^ 4432)); j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 84;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x1C, 0x1F, 0x17, 0x01, 0x08};
static const char* j_dc_20(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 84;
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x6B, 0x68, 0x60, 0x71, 0x7F};
static const char* j_dc_21(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ (25 + 10);
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xB3, 0xB0, 0xAE, 0xA7};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ ((5 + 246) ^ (9695 ^ 9695));
    j_rb[((4 + 0) ^ (4772 ^ 4772))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0x03, 0x16};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 116;
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xC3, 0xC5, 0xC2, 0xD2};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 183;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xDC, 0xDB, 0xD6, 0xC9, 0xDF};
static const char* j_dc_25(void) {
    static char j_rb[((6 + 0) ^ (9043 ^ 9043))];
    for (int j_i = 0; j_i < ((4 + 1) ^ (5515 ^ 5515)); j_i++) j_rb[j_i] = j_enc_25[j_i] ^ ((45 + 141) ^ (4609 ^ 4609));
    j_rb[5] = ((0 + 0) ^ (6944 ^ 6944));
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0xF6, 0xF0, 0xF7, 0xE7};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ (97 + 33);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xBB, 0xBC, 0xB1, 0xAE, 0xB8};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_27[j_i] ^ (151 + 70);
    j_rb[5] = ((0 + 0) ^ (5764 ^ 5764));
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x31, 0x37, 0x30, 0x20};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 69;
    j_rb[4] = ((0 + 0) ^ (2973 ^ 2973));
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x4C, 0x4B, 0x46, 0x59, 0x4F};
static const char* j_dc_29(void) {
    static char j_rb[((6 + 0) ^ (3721 ^ 3721))];
    for (int j_i = 0; j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ ((29 + 13) ^ (1964 ^ 1964));
    j_rb[((3 + 2) ^ (2857 ^ 2857))] = ((0 + 0) ^ (4289 ^ 4289));
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xFD, 0xFB, 0xFC, 0xEC};
static const char* j_dc_30(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2454 ^ 2454)); j_i < 4; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ ((31 + 106) ^ (8657 ^ 8657));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x48, 0x4F, 0x42, 0x5D, 0x4B};
static const char* j_dc_31(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ ((19 + 27) ^ (6115 ^ 6115));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0xB1, 0xB7, 0xB0, 0xA0};
static const char* j_dc_32(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ ((113 + 84) ^ (3884 ^ 3884));
    j_rb[((2 + 2) ^ (1913 ^ 1913))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x4A, 0x4D, 0x40, 0x5F, 0x49};
static const char* j_dc_33(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 44;
    j_rb[((4 + 1) ^ (7110 ^ 7110))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x3F, 0x39, 0x3E, 0x2E};
static const char* j_dc_34(void) {
    static char j_rb[((0 + 5) ^ (7229 ^ 7229))];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 75;
    j_rb[4] = ((0 + 0) ^ (1478 ^ 1478));
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x75, 0x72, 0x7F, 0x60, 0x76};
static const char* j_dc_35(void) {
    static char j_rb[((6 + 0) ^ (5774 ^ 5774))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 19;
    j_rb[((5 + 0) ^ (5467 ^ 5467))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((4 + 0) ^ (8780 ^ 8780)); j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 244;
    j_rb[((1 + 3) ^ (6602 ^ 6602))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xA9, 0xAE, 0xA3, 0xBC, 0xAA};
static const char* j_dc_37(void) {
    static char j_rb[((6 + 0) ^ (6148 ^ 6148))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 207;
    j_rb[(2 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xFE, 0xF8, 0xFF, 0xEF};
static const char* j_dc_38(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ ((132 + 6) ^ (711 ^ 711));
    j_rb[((1 + 3) ^ (8684 ^ 8684))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x45, 0x42, 0x4F, 0x50, 0x46};
static const char* j_dc_39(void) {
    static char j_rb[((0 + 6) ^ (3752 ^ 3752))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ (15 + 20);
    j_rb[5] = ((0 + 0) ^ (6368 ^ 6368));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x28, 0x2E, 0x29, 0x39};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ (2 + 90);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x70, 0x77, 0x7A, 0x65, 0x73};
static const char* j_dc_41(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 22;
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x0B, 0x0D, 0x0A, 0x1A};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ ((47 + 80) ^ (5351 ^ 5351));
    j_rb[((3 + 1) ^ (6341 ^ 6341))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x8B, 0x8C, 0x81, 0x9E, 0x88};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7696 ^ 7696)); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 237;
    j_rb[(4 + 1)] = ((0 + 0) ^ (1059 ^ 1059));
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x2F, 0x29, 0x2E, 0x3E};
static const char* j_dc_44(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 91;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x09, 0x0E, 0x03, 0x1C, 0x0A};
static const char* j_dc_45(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 111;
    j_rb[((4 + 1) ^ (6092 ^ 6092))] = ((0 + 0) ^ (3743 ^ 3743));
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x40, 0x45, 0x49, 0x41, 0x53, 0x2A, 0x6C, 0x65, 0x78, 0x6F, 0x64, 0x79, 0x63, 0x69, 0x2A, 0x66, 0x6B, 0x64, 0x6D, 0x7F, 0x6B, 0x6D, 0x6F, 0x2A, 0x7C, 0x3A, 0x24, 0x3B};
static const char* j_dc_46(void) {
    static char j_rb[(8 + 21)];
    for (int j_i = (0 + 0); j_i < 28; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ (4 + 6);
    j_rb[28] = ((0 + 0) ^ (5700 ^ 5700));
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0xE4, 0xE2, 0xE5, 0xF5};
static const char* j_dc_47(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ (113 + 31);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x1A, 0x1D, 0x10, 0x0F, 0x19};
static const char* j_dc_48(void) {
    static char j_rb[((6 + 0) ^ (8513 ^ 8513))];
    for (int j_i = (0 + 0); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_48[j_i] ^ (51 + 73);
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0xF9, 0xFF, 0xF8, 0xE8};
static const char* j_dc_49(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (5417 ^ 5417)); j_i < ((3 + 1) ^ (6716 ^ 6716)); j_i++) j_rb[j_i] = j_enc_49[j_i] ^ (25 + 116);
    j_rb[(0 + 4)] = ((0 + 0) ^ (7078 ^ 7078));
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x32, 0x35, 0x38, 0x27, 0x31};
static const char* j_dc_50(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = ((0 + 0) ^ (2816 ^ 2816)); j_i < ((2 + 3) ^ (2034 ^ 2034)); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 84;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x7A, 0x7C, 0x7B, 0x6B};
static const char* j_dc_51(void) {
    static char j_rb[((3 + 2) ^ (5959 ^ 5959))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ ((5 + 9) ^ (3841 ^ 3841));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x48, 0x4F, 0x42, 0x5D, 0x4B};
static const char* j_dc_52(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 46;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0xD2, 0xD4, 0xD3, 0xC3};
static const char* j_dc_53(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 166;
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_54(void) {
    static char j_rb[((3 + 3) ^ (1335 ^ 1335))];
    for (int j_i = ((0 + 0) ^ (1867 ^ 1867)); j_i < 5; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 58;
    j_rb[((1 + 4) ^ (7894 ^ 7894))] = ((0 + 0) ^ (5721 ^ 5721));
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x10, 0x12, 0x09, 0x0D, 0x05};
static const char* j_dc_55(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_55[j_i] ^ ((25 + 71) ^ (6382 ^ 6382));
    j_rb[5] = ((0 + 0) ^ (3244 ^ 3244));
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x28, 0x2E, 0x29, 0x39};
static const char* j_dc_56(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (9756 ^ 9756)); j_i < ((0 + 4) ^ (954 ^ 954)); j_i++) j_rb[j_i] = j_enc_56[j_i] ^ (33 + 59);
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0xEE, 0xE9, 0xE4, 0xFB, 0xED};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_57[j_i] ^ (81 + 55);
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x08, 0x0E, 0x09, 0x19};
static const char* j_dc_58(void) {
    static char j_rb[((0 + 5) ^ (7547 ^ 7547))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 124;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xB9, 0xBE, 0xB3, 0xAC, 0xBA};
static const char* j_dc_59(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = (0 + 0); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 223;
    j_rb[((4 + 1) ^ (3272 ^ 3272))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x2D, 0x2B, 0x2C, 0x3C};
static const char* j_dc_60(void) {
    static char j_rb[((1 + 4) ^ (5856 ^ 5856))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ (3 + 86);
    j_rb[(4 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x51, 0x56, 0x5B, 0x44, 0x52};
static const char* j_dc_61(void) {
    static char j_rb[((0 + 6) ^ (5308 ^ 5308))];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_61[j_i] ^ ((49 + 6) ^ (2861 ^ 2861));
    j_rb[((2 + 3) ^ (7780 ^ 7780))] = ((0 + 0) ^ (15 ^ 15));
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x36, 0x30, 0x37, 0x27};
static const char* j_dc_62(void) {
    static char j_rb[((4 + 1) ^ (1776 ^ 1776))];
    for (int j_i = (0 + 0); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 66;
    j_rb[4] = ((0 + 0) ^ (6290 ^ 6290));
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0x73, 0x74, 0x79, 0x66, 0x70};
static const char* j_dc_63(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = ((0 + 0) ^ (3465 ^ 3465)); j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 21;
    j_rb[5] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == ((0 + 0) ^ (3713 ^ 3713)); }

static char j_buf[((47941 + 17595) ^ (5976 ^ 5976))];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = (0 + 0);
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
    ts.tv_nsec = (long)(ms % (810 + 190)) * 1000000L;
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
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = ((0 + 1) ^ (4170 ^ 4170));
#if defined(_WIN32)
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - (124 + 76)) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[(259 + 765)];
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
            if (off > J_BUF_CAP - (111 + 89)) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (7763 ^ 7763));
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (3950 ^ 3950)) ? n : (0 + 0));
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
    int first = ((0 + 1) ^ (8919 ^ 8919));
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - (166 + 234)) break;
                char name[1024];
                size_t k = (0 + 0);
                for (size_t i = ((0 + 0) ^ (86 ^ 86)); pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[((169 + 1879) ^ (845 ^ 845))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > ((0 + 0) ^ (8515 ^ 8515)) ? n : (0 + 0));
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = ((0 + 0) ^ (8034 ^ 8034)); i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - (206 + 194)) break;
        char name[(177 + 79)];
        int len = proc_name(pid, name, sizeof name);
        if (len <= ((0 + 0) ^ (8765 ^ 8765))) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = (0 + 0);
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : ((0 + 0) ^ (9084 ^ 9084)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[((8 + 56) ^ (5443 ^ 5443))], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (1620 ^ 1620));
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
    char line[(204 + 308)];
    int skip = ((1 + 0) ^ (7046 ^ 7046));
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = (0 + 0); continue; }
        char laddr[(36 + 28)], raddr[64], st[(11 + 5)];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - (141 + 159)) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : ((0 + 0) ^ (88 ^ 88)));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = ((0 + 0) ^ (3843 ^ 3843));
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    ULONG sz = (0 + 0);
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0)) == NO_ERROR) {
            for (DWORD i = (0 + 0); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[((35 + 29) ^ (4216 ^ 4216))], ri[64];
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
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : ((0 + 0) ^ (1591 ^ 1591)));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[(419 + 93)];
        while (fgets(line, sizeof line, ns)) {
            char proto[(4 + 4)], laddr[((19 + 45) ^ (7 ^ 7))], raddr[(60 + 4)], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), ((2 + 1) ^ (7451 ^ 7451))) != 0) continue;
                if (off > J_BUF_CAP - ((198 + 102) ^ (318 ^ 318))) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > (0 + 0) ? n : 0);
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
    int first = ((1 + 0) ^ (6494 ^ 6494));
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + (2 + 3); }
    else if (strncmp(key, j_dc_20(), (3 + 2)) == (0 + 0)) { root = HKEY_CURRENT_USER; sub = key + ((5 + 0) ^ (2739 ^ 2739)); }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + (5 + 0); }
    else if (strncmp(key, j_dc_22(), 4) == 0) { root = HKEY_USERS; sub = key + ((2 + 2) ^ (4000 ^ 4000)); }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = ((0 + 0) ^ (7145 ^ 7145)); ; ++i) {
            char s[((228 + 28) ^ (4894 ^ 4894))];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (317 ^ 317));
            char esc[((229 + 283) ^ (5784 ^ 5784))];
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
    unsigned long regions = (0 + 0);
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, (0 + 1), read, out);
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

static volatile int32_t j_yha1ne0q = 50874;
static volatile int32_t j_811lpzlr = ((25272 + 10190) ^ (2108 ^ 2108));

static bool j_1kr86out(int32_t j_1rcp31by);
static int32_t j_l8tsii7d(int32_t j_r17cneo7);

static bool j_1kr86out(int32_t j_1rcp31by)
{
    int32_t j_l0glq4tl = (0 + 0);
    while ((j_l0glq4tl != -1))
    {
        switch (j_l0glq4tl)
        {
            case 0:
                if ((j_1rcp31by < 2))
                {
                    return false;
                }
                j_l0glq4tl = 1;
                break;
            case 1:
                static volatile int64_t j_nfsw0o4g = 29747;
                static volatile int64_t j_ptbvbq2s = ((10656 + 74742) ^ (5194 ^ 5194));
                if ((((j_ptbvbq2s * j_ptbvbq2s) + j_ptbvbq2s) < ((0 + 0) ^ (7255 ^ 7255))))
                {
                    volatile int64_t j_od7rgsqk = ((j_ptbvbq2s * (71 + 20)) + ((74 + 324) ^ (9136 ^ 9136)));
                    (void)printf("%s\n", 0 ? j_dc_24() : j_dc_25());
                }
                j_l0glq4tl = ((1 + 1) ^ (542 ^ 542));
                break;
            case 2:
                if ((((j_nfsw0o4g * j_nfsw0o4g) + j_nfsw0o4g) < (0 + 0)))
                {
                    volatile int64_t j_x66so2d0 = ((j_nfsw0o4g * 87) + 747);
                    (void)printf("%s\n", ((0 + 0) ^ (2419 ^ 2419)) ? j_dc_26() : j_dc_27());
                }
                j_l0glq4tl = ((1 + 2) ^ (7297 ^ 7297));
                break;
            case 3:
                int32_t j_6zu005bu = ((1 + 1) ^ (8557 ^ 8557));
                static volatile int64_t j_7n0vz1w4 = 10899;
                static volatile int64_t j_330zsatz = ((11887 + 61826) ^ (1300 ^ 1300));
                if ((((j_330zsatz * j_330zsatz) + j_330zsatz) < ((0 + 0) ^ (3256 ^ 3256))))
                {
                    volatile int64_t j_0kqj9lqm = ((j_330zsatz * 11) + ((691 + 22) ^ (1782 ^ 1782)));
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_l0glq4tl = 4;
                break;
            case 4:
                if ((((j_7n0vz1w4 * j_7n0vz1w4) + j_7n0vz1w4) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_l0glq4tl = 5;
                break;
            case 5:
                while (((j_6zu005bu * j_6zu005bu) <= j_1rcp31by))
                {
                    if (((j_1rcp31by % j_6zu005bu) == 0))
                    {
                        return false;
                    }
                    j_6zu005bu = (j_6zu005bu + (1 + 0));
                }
                j_l0glq4tl = ((2 + 4) ^ (8472 ^ 8472));
                break;
            case 6:
                static volatile int64_t j_0xvz9ova = 99388;
                if ((((j_0xvz9ova * j_0xvz9ova) + j_0xvz9ova) < ((0 + 0) ^ (6590 ^ 6590))))
                {
                    volatile int64_t j_1sx84g7o = ((j_0xvz9ova * ((20 + 52) ^ (2101 ^ 2101))) + ((135 + 253) ^ (1523 ^ 1523)));
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_l0glq4tl = 7;
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

static int32_t j_l8tsii7d(int32_t j_r17cneo7)
{
    int32_t j_rx2pm3x8 = ((0 + 0) ^ (5185 ^ 5185));
    while ((j_rx2pm3x8 != -(1 + 0)))
    {
        switch (j_rx2pm3x8)
        {
            case 0:
                static volatile int64_t j_jngbvkff = (5563 + 57231);
                static volatile int64_t j_r5faw390 = (41894 + 38816);
                if ((((j_r5faw390 * j_r5faw390) + j_r5faw390) < ((0 + 0) ^ (5102 ^ 5102))))
                {
                    volatile int64_t j_362h0z27 = ((j_r5faw390 * (12 + 85)) + 710);
                    (void)printf("%s\n", ((0 + 0) ^ (7112 ^ 7112)) ? j_dc_34() : j_dc_35());
                }
                j_rx2pm3x8 = 1;
                break;
            case 1:
                static volatile int64_t j_ad1w83hd = 53142;
                if ((((j_ad1w83hd * j_ad1w83hd) % ((1 + 3) ^ (6057 ^ 6057))) == (1 + 2)))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_36() : j_dc_37());
                }
                j_rx2pm3x8 = 2;
                break;
            case 2:
                static volatile int64_t j_sbcw15pq = (62685 + 16070);
                if ((((j_sbcw15pq * j_sbcw15pq) + j_sbcw15pq) < ((0 + 0) ^ (5386 ^ 5386))))
                {
                    volatile int64_t j_ibjvccdb = ((j_sbcw15pq * ((5 + 18) ^ (1516 ^ 1516))) + 755);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_rx2pm3x8 = 3;
                break;
            case 3:
                static volatile int64_t j_zln7oh9y = ((30131 + 62951) ^ (4932 ^ 4932));
                if ((((j_zln7oh9y * j_zln7oh9y) + j_zln7oh9y) < (0 + 0)))
                {
                    volatile int64_t j_x2fs77p5 = ((j_zln7oh9y * (6 + 4)) + 82);
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_rx2pm3x8 = 4;
                break;
            case 4:
                if ((((j_jngbvkff * (j_jngbvkff + ((1 + 0) ^ (9142 ^ 9142)))) % ((0 + 2) ^ (865 ^ 865))) == (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_42() : j_dc_43());
                }
                j_rx2pm3x8 = 5;
                break;
            case 5:
                static volatile int64_t j_82cj4mcv = ((41915 + 18432) ^ (2597 ^ 2597));
                if ((((j_82cj4mcv * j_82cj4mcv) + j_82cj4mcv) < (0 + 0)))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (7531 ^ 7531)) ? j_dc_44() : j_dc_45());
                }
                j_rx2pm3x8 = 6;
                break;
            case 6:
                int32_t j_7tbeima4 = ((0 + 0) ^ (5936 ^ 5936));
                for (int32_t j_bwded2x6 = 0; (j_bwded2x6 < j_r17cneo7); j_bwded2x6 = (j_bwded2x6 + 1))
                {
                    j_7tbeima4 = (j_7tbeima4 + j_bwded2x6);
                }
                j_rx2pm3x8 = 7;
                break;
            case 7:
                return j_7tbeima4;
                break;
            default:
                break;
        }
    }
    return 0;
}

__attribute__((used)) static int32_t j_z_rbozf8(int32_t j_a, int32_t j_b) {
    int32_t j_r = 0;
    for (int32_t j_i = 0; j_i < j_a; j_i++) {
        j_r = j_r + j_b;
        if (j_r > ((806 + 194) ^ (6051 ^ 6051))) j_r = j_r - (951 + 49);
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_j514ug(int32_t j_a, int32_t j_b) {
    int32_t j_r = ((0 + 0) ^ (4408 ^ 4408));
    for (int32_t j_i = 0; j_i < j_a; j_i++) {
        j_r = j_r + j_b;
        if (j_r > (439 + 561)) j_r = j_r - ((880 + 120) ^ (5802 ^ 5802));
    }
    return j_r;
}

static int32_t j_tr_mc2l2f(void) {
    int32_t j_u5uixy4d = 0;
    while ((j_u5uixy4d != -1))
    {
        switch (j_u5uixy4d)
        {
            case 0:
                const char* j_t6yd78zc = j_dc_46();
                int32_t j_aeu5rnd0 = j_l8tsii7d((4 + 6));
                static volatile int64_t j_gakcaapp = ((39367 + 49311) ^ (5173 ^ 5173));
                if ((((j_gakcaapp * j_gakcaapp) + j_gakcaapp) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (4366 ^ 4366)) ? j_dc_47() : j_dc_48());
                }
                j_u5uixy4d = (0 + 1);
                break;
            case 1:
                static volatile int64_t j_79oxrp26 = 62681;
                if ((((j_79oxrp26 * j_79oxrp26) + j_79oxrp26) < 0))
                {
                    volatile int64_t j_uujc2mpn = ((j_79oxrp26 * 31) + (555 + 126));
                    (void)printf("%s\n", 0 ? j_dc_49() : j_dc_50());
                }
                j_u5uixy4d = (1 + 1);
                break;
            case 2:
                static volatile int64_t j_r7l6h22c = (23317 + 38472);
                if ((((j_r7l6h22c * j_r7l6h22c) + j_r7l6h22c) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (1026 ^ 1026)) ? j_dc_51() : j_dc_52());
                }
                j_u5uixy4d = (3 + 0);
                break;
            case 3:
                static volatile int64_t j_abjvdefg = (76442 + 12041);
                if ((((j_abjvdefg * j_abjvdefg) + j_abjvdefg) < ((0 + 0) ^ (7607 ^ 7607))))
                {
                    volatile int64_t j_ilr1tenp = ((j_abjvdefg * (35 + 6)) + (221 + 262));
                    (void)printf("%s\n", 0 ? j_dc_53() : j_dc_54());
                }
                j_u5uixy4d = (4 + 0);
                break;
            case 4:
                (void)printf("%s\n", j_t6yd78zc);
                (void)printf("%d\n", j_aeu5rnd0);
                const char* j_pna05dc9 = j_dc_55();
                if ((j_1kr86out((4 + 3)) && (j_str_len(j_pna05dc9) == (0 + 5))))
                {
                    (void)printf("%s\n", true ? j_dc_56() : j_dc_57());
                }
                else
                {
                    (void)printf("%s\n", false ? j_dc_58() : j_dc_59());
                }
                j_u5uixy4d = ((2 + 3) ^ (9893 ^ 9893));
                break;
            case 5:
                int32_t j_18my6jqp = 0;
                int32_t j_1rcp31by = (2 + 0);
                static volatile int64_t j_f9rtg3ts = 38080;
                static volatile int64_t j_8alalwsd = 7054;
                if ((((j_8alalwsd * j_8alalwsd) + j_8alalwsd) < ((0 + 0) ^ (4900 ^ 4900))))
                {
                    volatile int64_t j_3xbbyr5f = ((j_8alalwsd * (0 + 4)) + ((1 + 53) ^ (3724 ^ 3724)));
                    (void)printf("%s\n", 0 ? j_dc_60() : j_dc_61());
                }
                j_u5uixy4d = 6;
                break;
            case 6:
                if ((((j_f9rtg3ts * j_f9rtg3ts) + j_f9rtg3ts) >= ((0 + 0) ^ (4050 ^ 4050))))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_62() : j_dc_63());
                }
                j_u5uixy4d = (2 + 5);
                break;
            case 7:
                while ((j_18my6jqp < ((3 + 0) ^ (8780 ^ 8780))))
                {
                    if (j_1kr86out(j_1rcp31by))
                    {
                        (void)printf("%d\n", j_1rcp31by);
                        j_18my6jqp = (j_18my6jqp + 1);
                    }
                    j_1rcp31by = (j_1rcp31by + 1);
                }
                j_u5uixy4d = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}
static int32_t j_tr_57csx5(void) { return j_tr_mc2l2f(); }
static int32_t j_tr_45bp1u(void) { return j_tr_57csx5(); }
int32_t main(void) { return j_tr_45bp1u(); }

