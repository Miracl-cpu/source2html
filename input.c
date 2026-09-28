#define MAX_SCK  12
#define MAX_SO   13
#define MAX_CS   14

uint16_t readMAX6675Raw()
{
  uint16_t value = 0;

  digitalWrite(MAX_CS, LOW);
  delayMicroseconds(10);

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(MAX_SCK, HIGH);
    delayMicroseconds(5);

    value <<= 1;

    if (digitalRead(MAX_SO))
      value |= 1;

    digitalWrite(MAX_SCK, LOW);
    delayMicroseconds(5);
  }

  digitalWrite(MAX_CS, HIGH);

  return value;
}

void setup()
{
  Serial.begin(115200);

  pinMode(MAX_SCK, OUTPUT);
  pinMode(MAX_CS, OUTPUT);
  pinMode(MAX_SO, INPUT);

  digitalWrite(MAX_CS, HIGH);
  digitalWrite(MAX_SCK, LOW);

  Serial.println("MAX6675 Diagnostic Test");

  delay(500);
}

void loop()
{
  uint16_t raw = readMAX6675Raw();

  Serial.print("RAW = 0x");
  Serial.print(raw, HEX);
  Serial.print("   Binary = ");
  Serial.println(raw, BIN);

  // D2 = thermocouple open detection
  if (raw & 0x04)
  {
    Serial.println("ERROR: Thermocouple OPEN / not connected");
  }
  else
  {
    float temperature = (raw >> 3) * 0.25;

    Serial.print("Temperature = ");
    Serial.print(temperature, 2);
    Serial.println(" °C");
  }

  Serial.println("---------------------");

  delay(1000);
}