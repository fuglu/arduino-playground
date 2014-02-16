BOARD_TAG    = uno
ARDUINO_PORT = /dev/ttyACM0
ARDUINO_DIR = /usr/share/arduino
ARDUINO_LIB_PATH=/home/fuglu/git/arduino/libraries
ARDUINO_LIBS = Debug RGBA RGBC LED Button Buzzer Temp LDR Servo MFRC522 SPI IRemote Sonar LiquidCrystal DHT

include /usr/share/arduino/Arduino.mk
