#pragma once

#include <pico/stdlib.h>
#include "PulseProc.h"
#include "PulseProcTone.h"
#include "PulseProcBitStream.h"
#include "PulseProcPauseMillis.h"

class PulseProcTzxDirectRecording : public PulseProc {
private:

  PulseProcBitStream* _data;
  PulseProcPauseMillis* _pause;
  uint32_t _tsPerMs;

public:

  PulseProcTzxDirectRecording(
    PulseProcBitStream* data,
    PulseProcPauseMillis* pause
  );
  
  void init(
    PulseProc *nxt,
    uint32_t tsPerMs
  );
  
  virtual int32_t advance(
    InputStream *is,
    bool *pstate,
    PulseProc **top
  );
};
