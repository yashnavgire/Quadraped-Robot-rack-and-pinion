long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
void distance1()
{
  dist=0;
  digitalWrite(ultra_trig_pin1, LOW);
  delayMicroseconds(2);
  digitalWrite(ultra_trig_pin1, HIGH);
  delayMicroseconds(12);
  digitalWrite(ultra_trig_pin1, LOW);
  
  duration = pulseIn(ultra_echo_pin1, HIGH);

  dist = microsecondsToCentimeters(duration);
}

void distance4()
{
  dist=0;
  digitalWrite(ultra_trig_pin4, LOW);
  delayMicroseconds(2);
  digitalWrite(ultra_trig_pin4, HIGH);
  delayMicroseconds(12);
  digitalWrite(ultra_trig_pin4, LOW);
  
  duration = pulseIn(ultra_echo_pin4, HIGH);

  dist = microsecondsToCentimeters(duration);
}
