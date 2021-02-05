#include <ESP32MailHTTPClient.h>
#include <ESP32TimeHelper.h>
#include <ESP32_MailClient.h>
#include <RFC2047.h>
#include <ssl_client32.h>
#include <WiFiClientSecureESP32.h>

#include "ESP32_MailClient.h"
const char* ssid = "Saad";
const char* password = "Pan10101";

#define emailSenderAccount"saadsalim283@gmail.com"
#define emailSenderPassword "saadsalim278"
#define emailRecipient "saadsalim2782@gmail.com"
#define smtpServer "smtp.gmail.com"
#define smtpServerPort 465
#define emailSubject "ESP32 Testing Email"

SMTPData smtpData;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("*");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi connected.");
  Serial.println();
  Serial.println("Preparing to send email");
  Serial.println();
  
  smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount,emailSenderPassword);
 
  smtpData.setSender("ESP32 Sender", emailSenderAccount);
  
  smtpData.setPriority("High");
  
  smtpData.setSubject(emailSubject);
  
  smtpData.setMessage("<div><h1>Hello World!</h1><p>- Sent from ESP32 board</p></div>", true);
  
  smtpData.addRecipient(emailRecipient);

  smtpData.setSendCallback(sendCallback);

  if(!MailClient.sendMail(smtpData)){
    Serial.println("Error in Sending EMail" + MailClient.smtpErrorReason());
        
  }
  smtpData.empty();

}

void loop() {
  // put your main code here, to run repeatedly:
}

void sendCallback(SendStatus message)
{
  Serial.println(message.info());

  if(message.success()){
    Serial.print("+++++");
  }
}
