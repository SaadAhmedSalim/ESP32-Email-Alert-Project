#include "ESP32_MailClient.h"
 
const char* ssid = "Saad";
const char* password = "Pan10101";
 
#define emailSenderAccount "saadsalim283@gmail.com"
#define emailSenderPassword "saadsalim278"
#define emailRecipient "saadsalim2782@gmail.com"
#define smtpServer "smtp.gmail.com"
#define smtpServerPort 465
#define emailSubject "ESP32 Testing Email"
 
SMTPData smtpData;
int touchValue;
void setup() {
  // put your setup code here, to run once:
WiFi.begin(ssid, password);
while(WiFi.status() != WL_CONNECTED)
{
  Serial.print("*");
  delay(200);
  }
  Serial.println("WiFi is Connected");
  /*
smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
smtpData.setSender("ESP32 Sender", emailSenderAccount);  
smtpData.setPriority("High");
smtpData.setSubject(emailSubject);
//smtpData.setMessage("Hellow World This is ESP Email Testing", false);
//smtpData.setMessage("<div style=\"color:#2fffff;\"><h1>Hello</h1><p>- Sent from ESP32</p></div>", true);
 
smtpData.addRecipient(emailRecipient);
/*
if(!MailClient.sendMail(smtpData))
  Serial.println("Error in Sending the Email" + MailClient.smtpErrorReason());
 
  smtpData.empty();*/
}
 
void loop() {
  // put your main code here, to run repeatedly:
smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
smtpData.setSender("ESP32 Sender", emailSenderAccount);  
smtpData.setPriority("High");
smtpData.setSubject(emailSubject);
touchValue = touchRead(4);
Serial.print("The touch sensor value: ");
Serial.println(touchValue);
if(touchValue >= 100)
{
 smtpData.setMessage("The Touch Sensor value is above 100", true);
 smtpData.addRecipient(emailRecipient);
 
if(!MailClient.sendMail(smtpData))
  Serial.println("Error in Sending the Email" + MailClient.smtpErrorReason());
 
  smtpData.empty();
delay(100000);
  }
}
 
 
void sendCallback(SendStatus message)
{
  Serial.println(message.info());
 
  if(message.success()){Serial.print("++++++++");}
  }
