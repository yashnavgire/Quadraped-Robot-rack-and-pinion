    float getDMPAngle(char c)
{
  if(c == 'y' || c == 'p' || c == 'r'){
    Serial2.write(c);
    
    unsigned long requestTime1 = millis();
    while ((!Serial2.available() > 0) && (millis() - requestTime1) < 1);
    float myAngle = Serial2.parseFloat();

//    Serial.print(c);
//    Serial.println(myAngle);

    return myAngle;
  }
}
//
//float getDMPAngle1(char c)
//{
//    
//  if(c == 'y' || c == 'p' || c == 'r' || c=='R')
//    Serial2.write(c);
//    unsigned long requestTime1 = millis();
//    while ((!Serial2.available() > 0) && (millis() - requestTime1) < 1);
//    int myAngle = Serial2.read();
//    myAngle = map(myAngle,0,255,-360,360);
//    return myAngle;
//}

void writeypr(char c)
{
  Serial.write(c);  
}

void getAngle()
{
  Serial2.flush();
//  delay(100);
    if(Serial2.available()>0)
    {
    angle = Serial2.read();
//    angle = map(angle,0,255,-180,180);
//    Serial.println(myAngle);
//    Serial2.flush();
    }
  
}
