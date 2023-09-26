// Họa Tiết Hiệu Ứng Ma Trận
// Khởi đông: 2023.08.05
// Phiên bản: 2023.08.05

#include <stdio.h>
#include <stdlib.h>

#define kSAI 0
#define kDUNG 1

#pragma mark ====== SVG ======
// Lưu đầu tệp SVG
void luuDauSVG( FILE *tep, unsigned int beRong, unsigned int beCao ) {    // ---- đầu tập tin SVG

   fprintf( tep, "<svg version=\"1.1\" width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n\n", beRong, beCao );
}

// Vẽ hình chữ nhật tại góc trái dưới tại (gocX; gocY)
void chuNhat( FILE *tep, float gocX, float gocY, float beRong, float beCao, unsigned char toDay, unsigned int mauToDay, float doDucToDay,
         unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet ) {
   
	fprintf( tep, "<rect x=\"%5.1f\" y=\"%5.1f\" width=\"%5.1f\" height=\"%5.1f\" ", gocX, gocY, beRong, beCao );
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}

   fprintf( tep, "/>\n\n" );
}

void vanBan_ngang( FILE *tep, char *xau, float viTriX, float viTriY, char *giaDinhPhong, float coKichPhong, char *beDayPhong,
                       unsigned char toDay, unsigned int mauToDay, float doDucToDay, unsigned char net, float beRongNet, unsigned int mauNet, float doDucNet, char *canhHang ) {

   fprintf( tep, "<text x=\"%5.1f\" y=\"%5.1f\" font-family=\"%s\" font-size=\"%5.1f\" font-weight=\"%s\" writing-mode=\"lr\" ", viTriX, viTriY, giaDinhPhong, coKichPhong, beDayPhong );
   
   fprintf( tep, "text-anchor=\"%s\" ", canhHang );   // start middle  end
   
	if( toDay )
	   fprintf( tep, "fill=\"#%06X\" fill-opacity=\"%4.2f\" ", mauToDay, doDucToDay );
	else
	   fprintf( tep, "fill=\"none\" " );
	if( net ) {
	   fprintf( tep, "stroke=\"#%06X\" stroke-opacity=\"%4.2f\" ", mauNet, doDucNet );
	   fprintf( tep, "stroke-width=\"%5.1f\" ", beRongNet );
	}
	else {
	   fprintf( tep, "stroke=\"none\" " );
	}
   fprintf( tep, ">\n" );
	fprintf( tep, " %s </text>\n\n", xau );
}



char *mangKyTu[] = {

 "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F",
// 16

 "ก", "ข", "ค", "ฆ", "ง", "จ", "ฉ", "ช", "ซ", "ฌ", "ญ", "ฎ", "ฏ",
 "ฐ", "ฑ", "ฒ", "ณ", "ด", "ต", "ถ", "ท", "ธ", "น", "บ", "ป", "ผ", "ฝ", "พ", "ฟ",
 "ภ", "ม", "ย", "ร", "ฤ", "ล", "ฦ", "ว", "ศ", "ษ", "ส", "ห", "ฬ", "อ", "ฮ", "ฯ",
 "ะ", "แ", "โ", "ใ","ไ","ๆ",
// 16 + 45

 "Ằ", "ằ", "ẳ", "Ẵ", "ẵ", "Ặ", "ặ", "Ẹ", "ẹ", "Ẻ", "ẻ", "Ẽ", "ẽ", "Ế", "ế", "ẽ",
 "Ề", "ề", "Ể", "ể", "Ễ", "ễ", "Ệ", "ệ", "Ỉ", "ỉ", "Ị", "ị", "Ọ", "ọ", "Ỏ", "ỏ",
 "Ố", "ố", "Ồ", "ồ", "Ổ", "ổ", "Ỗ", "ỗ", "Ộ", "ộ", "Ớ", "ớ", "Ờ", "ờ", "Ở", "ở",
 "Ự", "ự",
// 50 + 45 + 16

 "あ", "い", "う", "え", "お", "か", "き", "く", "け", "こ", "さ", "し", "す", "せ", "そ", "た",
 "ち", "つ", "て", "と", "な", "に", "ぬ", "ね", "の", "は", "ひ", "ふ", "へ", "ほ", "ま", "み",
 "む", "め", "も", "や", "ゆ", "よ", "ら", "り", "る", "れ", "ろ", "わ", "を", "ん",
// 44+ 50 + 45 + 16

 "ア", "イ", "ウ", "エ", "オ", "カ", "キ", "ク", "ケ", "コ", "サ", "シ", "ス", "セ", "ソ", "タ",
 "チ", "ツ", "テ", "ト", "ナ", "ニ", "ヌ", "ネ", "ノ", "ハ", "ヒ", "フ", "ヘ", "ホ", "マ", "ミ",
 "ム", "メ", "モ", "ヤ", "ユ", "ヨ", "ラ", "リ", "ル", "レ", "ロ", "ワ", "を", "ン", "ー", "｜",
// 88 + 50 + 45 + 16

 "ㄅ", "ㄆ", "ㄇ", "ㄈ", "ㄉ", "ㄊ", "ㄋ", "ㄌ", "ㄍ", "ㄎ", "ㄏ", "ㄐ", "ㄑ", "ㄒ", "ㄓ", "ㄔ",
 "ㄕ", "ㄖ", "ㄗ", "ㄘ", "ㄙ", "ㄚ", "ㄛ", "ㄜ", "ㄝ", "ㄞ", "ㄟ", "ㄠ", "ㄡ", "ㄢ", "ㄣ", "ㄤ",
 "ㄥ", "ㄦ", "ㄧ", "ㄨ", "ㄩ", "ㄪ", "ㄫ", "ㄬ",
// 42 + 88 + 50 + 45 + 16

  "ក", "ខ", "គ", "ឃ", "ង", "ច", "ឆ", "ជ", "ឈ", "ញ", "ដ", "ឋ", "ឌ", "ឍ", "ណ", "ត",
  "ថ", "ទ", "ធ", "ន", "ប", "ផ", "ព", "ភ", "ម", "យ", "រ", "ល", "វ", "ឝ", "ឞ", "ស",
  "ហ", "ឡ", "អ", "ឣ", "ឥ", "។", "ៗ", "០", "១", "២", "៣", "៤", "៥", "៦", "៧", "៨",
   "៩",
   
     "Б", "Г", "Д", "Ж", "З", "И", "Й", "Л", "П", "У", "Ф", "Ц", "Ч", "Ш", "Щ", "Ъ",
     "Ы", "Ь", "Э", "Ю", "Я",
   
   "\0",
};


#define kKHO_HOA_TIET 2048 // điểm ảnh, khổ vuông
#define kSO_LUONG_BUOC 32


int main( int argc, char **argv ){

   // ---- mở tập tin SVG
   FILE *tapTinSVG = fopen( "Họa Tiết Hiệu Ứng Ma Trận.svg", "w" );

   if( tapTinSVG != NULL ) {
      
      luuDauSVG( tapTinSVG, kKHO_HOA_TIET, kKHO_HOA_TIET );
      
      // ---- vẽ chữ nhật
      chuNhat( tapTinSVG, 0.0f, 0.0f, kKHO_HOA_TIET, kKHO_HOA_TIET, kDUNG, 0x000000, 1.0f,
              kSAI, 0.0f, 0x000000, 0.0f );
      
      // ---- quét đặt chữ cát
      float buoc = (float)(kKHO_HOA_TIET/kSO_LUONG_BUOC);
      unsigned char soBuocHang = 0;
      
      float viTriY = buoc*0.75f;
      
      unsigned short soLuongKyTu = 0;
      while( mangKyTu[soLuongKyTu][0] != 0x00 ) {
         soLuongKyTu++;
      }
      printf( "Số lượng ký tự %d\n", soLuongKyTu );
 
      while( soBuocHang < kSO_LUONG_BUOC ) {
         unsigned char soBuocCot = 0;
         float viTriX = buoc*0.5f;
         
         while( soBuocCot < kSO_LUONG_BUOC ) {
            
            // ----- ngẫu nhiên chọn ký tự
            unsigned short soKyTu = rand() % soLuongKyTu;
            
            // ----
            float coKichPhong = 48.0f;
            vanBan_ngang( tapTinSVG, mangKyTu[soKyTu], viTriX, viTriY, "Arial", coKichPhong, "Normal",
                         kDUNG, 0xffffff, 1.0f, kSAI, 0.0f, 0x000000, 0.0f, "middle" );
            
            soKyTu++;
            viTriX += buoc;
            soBuocCot++;
         }
         
         viTriY += buoc;
         soBuocHang++;
      }

      // ---- đóng tập tin SVG
      fprintf( tapTinSVG, "</svg>\n" );
      fclose( tapTinSVG );

   }

   return 0;
}

