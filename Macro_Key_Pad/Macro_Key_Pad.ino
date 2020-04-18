#include <Keyboard.h>

#define KEY_LEFT_CTRL  0x80
#define KEY_LEFT_SHIFT 0x81
#define KEY_LEFT_ALT   0x82
#define KEY_LEFT_GUI   0x83
#define KEY_RIGHT_CTRL 0x84
#define KEY_RIGHT_SHIFT    0x85
#define KEY_RIGHT_ALT  0x86
#define KEY_RIGHT_GUI  0x87

#define KEY_UP_ARROW   0xDA
#define KEY_DOWN_ARROW 0xD9
#define KEY_LEFT_ARROW 0xD8
#define KEY_RIGHT_ARROW    0xD7
#define KEY_BACKSPACE  0xB2
#define KEY_TAB        0xB3
#define KEY_RETURN 0xB0
#define KEY_ESC        0xB1
#define KEY_INSERT 0xD1
#define KEY_DELETE 0xD4
#define KEY_PAGE_UP    0xD3
#define KEY_PAGE_DOWN  0xD6
#define KEY_HOME   0xD2
#define KEY_END        0xD5
#define KEY_CAPS_LOCK  0xC1
#define KEY_F1     0xC2
#define KEY_F2     0xC3
#define KEY_F3     0xC4
#define KEY_F4     0xC5
#define KEY_F5     0xC6
#define KEY_F6     0xC7
#define KEY_F7     0xC8
#define KEY_F8     0xC9
#define KEY_F9     0xCA
#define KEY_F10        0xCB
#define KEY_F11        0xCC
#define KEY_F12        0xCD

#define debounceTime 500
#define tinyTime 50

int function0 = 2;  // Set a button to any pin
int function1 = 4;  // Set a button to any pin
int function2 = 7;  // Set a button to any pin
int function3 = 8;  // Set a button to any pin
int function4 = 10;  // Set a button to any pin
int function5 = 15;  // Set a button to any pin


void setup()
{
  pinMode(function0, INPUT);  // Set the button as an input
  pinMode(function1, INPUT);  // Set the button as an input
  pinMode(function2, INPUT);  // Set the button as an input
  pinMode(function3, INPUT);  // Set the button as an input
  pinMode(function4, INPUT);  // Set the button as an input
  pinMode(function5, INPUT);  // Set the button as an input
  digitalWrite(function0, HIGH);  // Pull the button high
  digitalWrite(function1, HIGH);  // Pull the button high
  digitalWrite(function2, HIGH);  // Pull the button high
  digitalWrite(function3, HIGH);  // Pull the button high
  digitalWrite(function4, HIGH);  // Pull the button high
  digitalWrite(function5, HIGH);  // Pull the button high
}

void enter()
{
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(debounceTime);
}

void openRun()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
}

void openFileExplorer()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('e');
  Keyboard.releaseAll();
  delay(debounceTime);
}

void openCMD()
{
  openRun();
  delay(debounceTime);
  Keyboard.press('c');
  Keyboard.press('m');
  Keyboard.press('d');
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
}

void lockPC() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  Keyboard.releaseAll();
  delay(debounceTime);
}

void sleepPC()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('x');
  Keyboard.releaseAll();chrome.exe
  delay(debounceTime);
  Keyboard.press('u');
  Keyboard.releaseAll();
  delay(debounceTime);
  Keyboard.press('s');
  Keyboard.releaseAll();
  delay(debounceTime);
}
chrome.exe
void openChrome()
{
  openRun();
  Keyboard.print("chrome.exe");
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
}

void openYoutube()
{
  openChrome();
  Keyboard.print("youtube.com");
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
}

void openGlacierCams()
{
  openChrome();
  Keyboard.print("https://www.nps.gov/glac/learn/photosmultimedia/webcams.htm");
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
}

void openSteam()
{
  openCMD();
  Keyboard.print("cd C:\\Users\\JD\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Steam");
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
  Keyboard.print("Steam.lnk");
  Keyboard.releaseAll();
  delay(debounceTime);
  enter();
}

void loop()
{
  if (digitalRead(function0) == 0)  // if the button goes low
  {
    openFileExplorer();
  }
  if (digitalRead(function1) == 0)  // if the button goes low
  {
    openGlacierCams();
  }
  if (digitalRead(function2) == 0)  // if the button goes low
  {
    openCMD();
  }
  if (digitalRead(function3) == 0)  // if the button goes low
  {
    sleepPC();
  }
  if (digitalRead(function4) == 0)  // if the button goes low
  {
    openSteam();
  }
  if (digitalRead(function5) == 0)  // if the button goes low
  {
    openYoutube();
  }
}
