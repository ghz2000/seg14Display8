#include "lib14Seg.h"
#include <SPI.h>

C14Segment::C14Segment(){
  bitSet(TIMSK2, TOIE2);
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  SPI.setDataMode(SPI_MODE0);
  
  m_speed = 0;
}

void C14Segment::init(int RCK, int kido, int ViewLength){
  setRCK(RCK);
  setBlight(kido);
  setViewLength(ViewLength);
}

void C14Segment::setRCK(int RCK){
  m_RCK = RCK;
}

void C14Segment::setBlight(int kido){
  m_kido = kido;
}

void C14Segment::setScrollSpeed(int scrollSpeed){
  m_speed = scrollSpeed;
}

void C14Segment::setViewLength(int ViewLength){
  m_ViewLength = ViewLength-1;
}

void C14Segment::setChar(char *input){
  int i=0;
  memset(m_str, 0, __LEN * 2);
  for(; i<__LEN -1 && input[i]!=NULL; i++){
    m_str[i] = ascii[ input[i] - ' '+1];    //変な文字が来た時対策をしてない
  }
  m_str[i] = 0x8000;
}

void C14Segment::showStop(){
  for(int i=0; i<m_ViewLength +1; i++){
    m_view[m_ViewLength - i] = m_str[i];  //文字が少ない時にバグるんじゃないかな
  }
  m_speed = 0;
}

void C14Segment::scroll(){
  static int scroll;
  for(int i=0; i<m_ViewLength +1; i++){
    
    //スクロールするときは桁数分ずらして空白からスタートする｡
    if(i + scroll < m_ViewLength){
      //空白を入れる
      m_view[m_ViewLength - i] = 0x00;
    }else{
      //文字をスクロール用にセットする
      m_view[m_ViewLength - i] = m_str[i+scroll-m_ViewLength];  //文字が少ない時にバグるんじゃないかな

      //全部通り過ぎたところと 0x8000(表示用終端文字)を比較して一致したらスクロールをリセット
//      if(m_str[i+scroll-m_ViewLength-m_ViewLength] == 0x8000) scroll=-m_ViewLength-1;
      if(m_str[i+scroll-m_ViewLength-m_ViewLength] == 0x8000) scroll=-m_ViewLength;
    }
  }
  scroll++;
}

void C14Segment::putnum(){
}

void C14Segment::cls(){
}

uint16_t cycleX[8] = {0x1000, 0x2000, 0x0400, 0x0002, 0x0004, 0x0008, 0x0010, 0x0800 };
uint16_t cycleO[6] = {0x0200, 0x4000, 0x0001, 0x0020, 0x0080, 0x0100 };

//割り込みルーチン
void C14Segment::update(){
  static uint8_t row;
  static int count;

    digitalWrite(m_RCK, LOW);

    SPI.transfer((0xFF & ~(1<<row)) );
//    SPI.transfer(m_kido << 4 | (0x0F & ~(1<<row)) );

    SPI.transfer(m_view[row] >> 8 & 0xFF );
    SPI.transfer(m_view[row] & 0xFF);

    digitalWrite(m_RCK, HIGH);
    
    if(m_speed){
      if(m_speed < count){
        scroll();
        count = 0;
      }
      count++;
    }
    
    row++;
//    row &=0x03;  //4桁
    row &=0x07;  //8桁
}

const uint16_t C14Segment::ascii[] = { sign_,
  sign_,  sign_Exclamation,  sign_Wquot,  sign_Sharp,  sign_Doll,  sign_Percent,  sign_And,  sign_Quot,  sign_RoundBracketS,  sign_RoundBracketE,  sign_Asta,  sign_Plus,  sign_Comma,  sign_Minus,  sign_dot,  sign_Slash,
  sign_0, sign_1, sign_2, sign_3, sign_4, sign_5, sign_6, sign_7, sign_8, sign_9, sign_Colon , sign_SemiColon , sign_AngleS , sign_Equal , sign_AngleE , sign_Question ,
  sign_At,  sign_A, sign_B, sign_C, sign_D, sign_E, sign_F, sign_G, sign_H, sign_I, sign_J, sign_K, sign_L, sign_M, sign_N, sign_O,
  sign_P, sign_Q, sign_R, sign_S, sign_T, sign_U, sign_V, sign_W, sign_X, sign_Y, sign_Z, sign_BoxS , sign_En , sign_BoxE , sign_Hat , sign_Underbar ,
  sign_Grave,  sign_a, sign_b, sign_c, sign_d, sign_e, sign_f, sign_g, sign_h, sign_i, sign_j, sign_k, sign_l, sign_m, sign_n, sign_o,
  sign_p, sign_q, sign_r, sign_s, sign_t, sign_u, sign_v, sign_w, sign_x, sign_y, sign_z, sign_CurlyBracketS, sign_Tate, sign_CurlyBracketE, sign_Child};
  
C14Segment LED14Seg;

//タイマオーバーフロー割り込みを設定
ISR(TIMER2_OVF_vect){
  LED14Seg.update();
}

