#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço I2C do display LCD. Normalmente é 0x27 ou 0x3F.
#define I2C_ADDR 0x27

// Inicializa o display LCD com o endereço I2C e dimensões 16x2.
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);

// Define o pino do botão
#define BUTTON_PIN 34

void setup() {
  // Inicializa o display.
  lcd.init();
  // Liga a luz de fundo do display.
  lcd.backlight();
  
  // Configura o pino do botão como entrada com resistor de pull-up.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Variável para armazenar o estado do botão.
  int buttonState = HIGH;
  
  // Aguarda o botão ser pressionado.
  while (buttonState == HIGH) {
    buttonState = digitalRead(BUTTON_PIN); // Lê o estado do botão.
    
    // Exibe a mensagem e animação de carregamento.
    lcd.setCursor(0, 0); // Define o cursor na coluna 0, linha 0.
    lcd.print(" DULCE  CECILIA ");
    
    // Animação de carregamento na segunda linha.
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, 1);
      lcd.print(".");
      delay(100); // Aguarda 100 ms.
      
      // Sai do loop se o botão for pressionado.
      if (digitalRead(BUTTON_PIN) == LOW) {
        buttonState = LOW;
        break;
      }
    }
    
    // Limpa a segunda linha após a animação.
    if (buttonState == HIGH) {
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }
  
  // Exibe uma mensagem no display após o botão ser pressionado.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Button Pressed!");
  lcd.setCursor(0, 1);
  lcd.print("Continuing...");
}

void loop() {
  // Você pode adicionar qualquer outro código que desejar aqui.
  // Por enquanto, o display apenas exibe a mensagem definida no setup().
}
