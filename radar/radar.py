import serial
from twilio.rest import Client

# Your Account Sid and Auth Token from twilio.com/console
# and set the environment variables. See http://twil.io/secure


with serial.Serial('/dev/cu.usbmodem1101', 9600) as ser:
    output = []
    combined_line = ''
    while ser.read():
        incoming_data = ser.read()
        # print('without decode incoming_data', incoming_data)
        incoming_data = incoming_data.decode("utf-8")
        # print('After incoming_data', incoming_data)
        if incoming_data != '.':
            # print('incoming_data, type(incoming_data)',
            # incoming_data, type(incoming_data))
            combined_line = combined_line + incoming_data
        if incoming_data == '.':
            d1 = combined_line.split(',')
            print('d1', d1, len(d1))
            if(len(d1) > 1):
                data = int(d1[1])
                output.append(data)
                combined_line = ''
                if(data < 30):
                    # ArduinoSerial = serial.Serial(
                    #     '/dev/cu.usbmodem1101', 9600)
                    # try:

                    #     while ArduinoSerial.read():
                    #         incoming_data = str(ArduinoSerial.readline())
                    #         print('data', incoming_data)
                    #         ArduinoSerial.close()
                    # except Exception():
                    #     print("Failed to send!")
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
    ser.close()
