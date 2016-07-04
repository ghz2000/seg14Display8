/***********
***********/

#ifndef _lib14Seg_
#define _lib14Seg_

#include <Arduino.h>


//correct
#define sign_A 0x4791
#define sign_B 0x13B4
#define sign_C 0x4221
#define sign_D 0x13A4
#define sign_E 0x4631
#define sign_F 0x4611
#define sign_G 0x42B1
#define sign_H 0x4591
#define sign_I 0x1224
#define sign_J 0x01A1
#define sign_K 0x4C09
#define sign_L 0x4021
#define sign_M 0x6981
#define sign_N 0x6189
#define sign_O 0x43A1
#define sign_P 0x4711
#define sign_Q 0x43A9
#define sign_R 0x4719
#define sign_S 0x46B0
#define sign_T 0x1204
#define sign_U 0x41A1
#define sign_V 0x4803
#define sign_W 0x418B
#define sign_X 0x280A
#define sign_Y 0x2804
#define sign_Z 0x0A22

//incorrect
#define sign_Exclamation 0x01C0
#define sign_Wquot       0x1100
#define sign_Sharp       0x1594
#define sign_Doll        0x56B4
#define sign_Percent     0x4882
#define sign_And         0x3629
#define sign_Quot        0x0800
#define sign_RoundBracketS 0x0818
#define sign_RoundBracketE 0x2402
#define sign_Asta        0x3C1E
#define sign_Plus        0x1414
#define sign_Comma       0x0002
#define sign_Minus       0x0410
#define sign_Slash       0x0802
#define sign_Colon       0x1004
#define sign_SemiColon   0x1002
#define sign_AngleS      0x0808
#define sign_Equal       0x0430
#define sign_AngleE      0x2002
#define sign_Question    0x4314
#define sign_At          0x5331
#define sign_BoxS        0x2222
#define sign_En          0x2C14
#define sign_BoxE        0xA28
#define sign_Hat         0x0900
#define sign_Underbar    0x0020
#define sign_Grave       0x2000
#define sign_CurlyBracketS 0x2622
#define sign_CurlyBracketE 0x0A38
#define sign_Tate        0x4001
#define sign_Child       0x0200


#define sign_a 0x07B1
#define sign_b 0x44B1
#define sign_c 0x0431
#define sign_d 0x05B1
#define sign_e 0x0423
#define sign_f 0x4601
#define sign_g 0x23B0
#define sign_h 0x4405
#define sign_i 0x0004
#define sign_j 0x01A0
#define sign_k 0x180C
#define sign_l 0x1004
#define sign_m 0x0495
#define sign_n 0x0405
#define sign_o 0x04B1
#define sign_p 0x4E01
#define sign_q 0x2390
#define sign_r 0x0401
#define sign_s 0x0038
#define sign_t 0x4421
#define sign_u 0x00A1
#define sign_v 0x0003
#define sign_w 0x008B
#define sign_x 0x280A
#define sign_y 0x11B0
#define sign_z 0x0422

#define sign_0 0x43A1
#define sign_1 0x0980
#define sign_2 0x0731
#define sign_3 0x07B0
#define sign_4 0x4590
#define sign_5 0x46B0
#define sign_6 0x46B1
#define sign_7 0x4380
#define sign_8 0x47B1
#define sign_9 0x4790

#define sign_dot 0x0040

#define sign_ 0x0000

//#define sign_  0x
// 0x8000 表示用終端文字


#define __LEN 30

class C14Segment{
private:
public:
  uint16_t m_view[8];
  uint16_t m_str[__LEN];
  static const uint16_t ascii[];
  int m_RCK;
  int m_kido;
  int m_ViewLength;
  int m_speed;
  

public:
  C14Segment();
  void init(int RCK, int kido, int ViewLength);
  void update();
  void setChar(char *);
  void putnum();
  void cls();
  void showStop();
  void scroll();
  void setRCK(int RCK);
  void setBlight(int kido);
  void setViewLength(int ViewLength);
  void setScrollSpeed(int scrollSpeed);
  void showCycleX();
  void showCycleO();

};

extern C14Segment LED14Seg;

#endif
