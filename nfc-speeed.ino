#include <NfcAdapter.h>
#include <SPI.h>
#include <PN532/PN532_SPI/PN532_SPI.h>
#include <PN532/PN532/PN532.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);

void setup() {
  Serial.begin(115200);
  nfc.begin();
  Serial.println("Place a blank card on the shield...");
}

void loop() {
  if (nfc.tagPresent()) {
    NdefMessage message = NdefMessage();
    message.addUriRecord("https://www.linkedin.com/in/nicolas-campan-766263433");

    if (nfc.write(message)) {
      Serial.println("Written! Remove the card.");
    } else {
      Serial.println("Write failed.");
    }
    delay(5000);
  }
}