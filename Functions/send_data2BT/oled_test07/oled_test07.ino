#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI


// void draw(void) {
//   // graphic commands to redraw the complete screen should be placed here
//   u8g.setFont(u8g_font_unifont);
//   //u8g.setFont(u8g_font_osb21);
//   u8g.drawStr( 0, 22, "Hello World!");
// }

void L(void) {
  // graphic commands to redraw the complete screen should be placed here
  // u8g.setFon/t(u8g_font_unifont);
  u8g.setFont(u8g_font_10x20);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr(0, 22, "<");
}

void B(void) {
  // graphic commands to redraw the complete screen should be placed here
  // u8g.setF/ont(u8g_font_unifont);
  u8g.setFont(u8g_font_10x20);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr(50, 40, "___");
}

void R(void) {
  // graphic commands to redraw the complete screen should be placed here
  // u8g.setFont(u8g_font_unifont);
  u8g.setFont(u8g_font_10x20);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr(100, 22, ">");
}

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();

  // // assign default color value
  // if (u8g.getMode() == U8G_MODE_R3G3B2) {
  //   u8g.setColorIndex(255);  // white
  // } else if (u8g.getMode() == U8G_MODE_GRAY2BIT) {
  //   u8g.setColorIndex(3);  // max intensity
  // } else if (u8g.getMode() == U8G_MODE_BW) {
  //   u8g.setColorIndex(1);  // pixel on
  // } else if (u8g.getMode() == U8G_MODE_HICOLOR) {
  //   u8g.setHiColorByRGB(255, 255, 255);
  // }
  // pinMode(8, OUTPUT);

  Serial.begin(9600);
}


void loop(void) {

  char check = Serial.read();
  char check_old ;

  if (check == '1') {
    Serial.println("AAA");
    // picture loop
    u8g.firstPage();
    do {
      L();
    } while (u8g.nextPage());
  } 
  else if (check == '2') {
    Serial.println("BBB");
    // picture loop
    u8g.firstPage();
    do {
      B();
    } while (u8g.nextPage());
  } 
  else if (check == '3') {
    Serial.println("CCC");
    // picture loop
    u8g.firstPage();
    do {
      R();
    } while (u8g.nextPage());
  }
  else{
    Serial.println("DDD");
    // picture loop
    u8g.firstPage();
    do {
    } while (u8g.nextPage());
  }
}