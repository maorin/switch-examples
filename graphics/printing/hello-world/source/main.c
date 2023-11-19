
#include <string.h>
#include <stdio.h>


#include <switch.h>


int main(int argc, char **argv)
{
   // Initialize console
   consoleInit(NULL);


   // Configure supported input layout: a single player with standard controller styles
   padConfigureInput(1, HidNpadStyleSet_NpadStandard);


   // Initialize the default gamepad
   PadState pad;
   padInitializeDefault(&pad);


   // Text to print
   char hello[] = "hello world";


   // Main loop
   while(appletMainLoop())
   {
       // Scan the gamepad
       padUpdate(&pad);


       // Check if the Plus button is pressed
       u64 kDown = padGetButtonsDown(&pad);
       if (kDown & HidNpadButton_Plus) break; // Exit if Plus is pressed


       // Print characters one by one
       for (int i = 0; i < strlen(hello); i++) {
           consoleClear(); // Clear the console
           printf("\x1b[16;20H"); // Move cursor
           for(int j = 0; j <= i; j++) {
               printf("%c", hello[j]); // Print each character up to current
           }
           consoleUpdate(NULL);
           svcSleepThread(200000000L); // Sleep for 200ms
       }
   }


   // Exit console
   consoleExit(NULL);
   return 0;

}