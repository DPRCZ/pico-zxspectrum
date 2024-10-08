
include_directories(${CMAKE_CURRENT_LIST_DIR})

set(zxspectrum_common_src
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumMouse.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumHidMouse.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumSettings.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFlashSettings.cpp # Needed for flash settings (not currently working)
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFileSettings.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumAudio.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumKiosk.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFatSpiKiosk.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumKeyboard.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumHidKeyboard.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumJoystick.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumHidJoystick.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumDualJoystick.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumNespadJoystick.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrum.cpp
  ${CMAKE_CURRENT_LIST_DIR}/QuickSave.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProc.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTone.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcStdHeader.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcStdByte.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcStdByteStream.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcChain.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxBlock.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxTurbo.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTap.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzx.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxHeader.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxGlue.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxIndex.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcPauseMillis.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxPureTone.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcPulseStream.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxPulseSequence.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxPureData.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcBitStream.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxDirectRecording.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcCallStream.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxGenData.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcTzxSelect.cpp 
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcSymdefs.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcRleSym.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcSymbol.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PulseProcSymbolData.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFile.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFileLoop.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumAy.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumMenu.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumFatSpiExists.cpp
  ${CMAKE_CURRENT_LIST_DIR}/PicoOnScreenKeyboard.cpp
)

set(zxspectrum_rgb332_src
  ${CMAKE_CURRENT_LIST_DIR}/ZxRgb332RenderLoop.cpp
)

set(zxspectrum_rgb_src
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumPrepareRgbScanline.cpp
)

set(zxspectrum_scanvideo_src
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumPrepareScanvideoScanline.cpp
  ${CMAKE_CURRENT_LIST_DIR}/ZxScanlineVgaRenderLoop.cpp
)

set(zxspectrum_dvi_src
  ${CMAKE_CURRENT_LIST_DIR}/tmds_encode_zxspectrum.S
  ${CMAKE_CURRENT_LIST_DIR}/tmds_encode_zxspectrum.h
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumPrepareDviScanline.cpp
)

set(zxspectrum_kbd_src
  ${CMAKE_CURRENT_LIST_DIR}/ZxSpectrumKeyMatrix.cpp
)

set(zxspectrum_common_libs
  pico_stdlib
  pico_multicore
  pico_util
  pico_emu_utils
  pico_hid_host
  pico_nespad
  sdcard
  fatfs
  hardware_dma
  hardware_flash # Needed for flash settings (not currently working)
  hardware_sync  # Needed for flash settings (not currently working)
  Zeta
  Z80
)

set(zxspectrum_audio_i2s_pio
  ${CMAKE_CURRENT_LIST_DIR}/audio_i2s.pio
)

set(zxspectrum_ear_in_pio
  ${CMAKE_CURRENT_LIST_DIR}/zx_ear_in.pio
)

set(murmulator_common_src
	${CMAKE_CURRENT_LIST_DIR}/ps2kbd_mrmltr.cpp
	${CMAKE_CURRENT_LIST_DIR}/ps2kbd_mrmltr.h
)

set(murmulator_ps2kbd_pio
  ${CMAKE_CURRENT_LIST_DIR}/ps2kbd_mrmltr.pio
)

add_subdirectory(hdmi)
add_subdirectory(picomputer)
add_subdirectory(vga)
add_subdirectory(picovga)

add_custom_target (ZX-MURMULATOR)
add_dependencies (ZX-MURMULATOR
  ZX-MURMULATOR_HDMI_PWM_AUDIO_640x480x60Hz
  ZX-MURMULATOR_HDMI_PWM_AUDIO_720x576x50Hz
  ZX-MURMULATOR_HDMI_HDMI_AUDIO_640x480x60Hz
  ZX-MURMULATOR_HDMI_HDMI_AUDIO_720x576x50Hz
  ZX-MURMULATOR_HDMI_I2S_AUDIO_640x480x60Hz
  ZX-MURMULATOR_HDMI_I2S_AUDIO_720x576x50Hz
  ZX-MURMULATOR_VGA_PWM_AUDIO_640x480x60Hz
  ZX-MURMULATOR_VGA_PWM_AUDIO_720x576x50Hz
  ZX-MURMULATOR_VGA_I2S_AUDIO_640x480x60Hz
  ZX-MURMULATOR_VGA_I2S_AUDIO_720x576x50Hz
)
