# NFC Link Writer

A simple Arduino sketch that writes a LinkedIn profile URL to an NFC tag as an NDEF URI record.

## Requirements

- Arduino board and USB cable
- PN532 NFC shield or module configured for SPI, with chip select on pin 10
- Writable, NDEF-compatible NFC tag
- Arduino IDE with the `NfcAdapter` and PN532 libraries that provide the headers used in the sketch

## Usage

1. Connect the PN532 to your board's SPI pins, using pin 10 for chip select.
2. Open `nfc-speeed.ino` in the Arduino IDE and install the required libraries.
3. Change the URL in `message.addUriRecord(...)` to the link you want to write.
4. Select your board and port, then upload the sketch.
5. Open the Serial Monitor at **115200 baud**.
6. Place a writable NFC tag on the reader. When `Written! Remove the card.` appears, remove it.
7. Scan the tag with an NFC-enabled phone to open the link.

The sketch reports `Write failed.` if writing fails. It waits five seconds after each write attempt, then checks again; a tag left on the reader will be written repeatedly. Writing may replace existing NDEF content.
