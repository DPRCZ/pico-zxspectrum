#include "FatFsSpiInputStream.h"
#include <pico/printf.h>

FatFsSpiInputStream::FatFsSpiInputStream(SdCardFatFsSpi* sdCard, const char* name) :
  _sdCard(sdCard),
  _eof(false),
  _open(false)
{
  if (!_sdCard->mounted()) {
    if (!_sdCard->mount()) {
      printf("Failed to mount SD card\n");
      return;
    }
  }
  
  printf("openning file %s\n", name);
  _fr = f_open(&_fil, name, FA_READ|FA_OPEN_EXISTING);
  if (FR_OK != _fr && FR_EXIST != _fr) {
    printf("f_open(%s) error: %s (%d)\n", name, FRESULT_str(_fr), _fr);
  }
  else {
    printf("openned file %s ok!\n", name);
    _open = true;
    _fr = FR_OK;
  }
}

int FatFsSpiInputStream::readByte() {
  if (_eof || !_open) return -1;
  
  // TODO Handle errors with separate codes
  if (FR_OK != _fr) return -1; 

  unsigned char d;
  UINT br = 0;
  _fr = f_read(&_fil, &d, 1, &br);
  _eof = br == 0;
  if (_eof) {
    printf("eof\n");
    return -1;
  }
  if (_fr != FR_OK) {
    printf("f_read(%s) error: (%d)\n", FRESULT_str(_fr), _fr);
    return -2;
  }
  return d;
}

void FatFsSpiInputStream::close() {
  if (_open) {
    f_close(&_fil);
    _open = false;
  }
}
