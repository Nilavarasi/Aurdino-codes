import os
import serial
from twilio.rest import Client
ArduinoSerial = serial.Serial('/dev/cu.usbmodem1101',9600)  
try:

    while ArduinoSerial.read():
        
        incoming_data = str (ArduinoSerial.readline())
        print ('data', incoming_data)
        ArduinoSerial.close()
except:
    print("Failed to send!")
        account_sid = 'ACd5e641bbf8ae3c22c3146c0b5717cdbd'
auth_token = '23d9bf64cd76f4e61973d019d4c61d48'
client = Client(account_sid, auth_token)

message = client.messages \
    .create(
         body='Radar ALERT',
         from_='+15614402676',
         to='+393278144144'
     )

print(message.sid)