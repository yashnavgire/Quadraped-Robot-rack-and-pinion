/*
 * Put this part in void setup() just below setPM();
 * 
 * 
if(digitalRead(mode_select)==1)                       //Normal Mode
{
 if(digitalRead(start_L1))                            //For Start Checkpoint
 {
  while(digitalRead(LS_G)==0);                        //wait till gerege is detected
  delay(1000);
  state=31;                                           //Go to normal walking initial
 }
 else if(digitalRead(sd_L2))                          //For Sand Dune Checkpoint
 state=171;                                           //Go to SD initial
 
 else if(digitalRead(tus_dir))                        //For Tussock Checkpoint
 state=0;                                             //Go to tussock initial
  
 else if(digitalRead(mountain))                       //For Mountain Checkpoint
 state=0;                                             //Go to mountain initial
}
 else if(digitalRead(mode_select)==0)                 //Tuninig Mode
 {
  state=5000;
 }

//////////////////////////////////////////////////////New//////////////////////////////////////////////////////////////////////
 
if(digitalRead(mode_select)==1)                       //Normal Mode
{
  if(digitalRead(initial)==1)
  {
    
  }
  else
  {
    if(digitalRead(start_L1))                            //For Start Checkpoint
    {
      while(digitalRead(LS_G)==0);                        //wait till gerege is detected
      delay(1000);
      state=31;                                           //Go to normal walking initial
    }

     if(digitalRead(sd_L2))                          //For Sand Dune Checkpoint
      state=171;                                           //Go to SD initial
 
     if(digitalRead(tus_dir))                        //For Tussock Checkpoint
      state=0;                                             //Go to tussock initial
  
                                              //Go to mountain initial
  }
    else if(digitalRead(mode_select)==0)                 //Tuninig Mode
  {
    if(digitalRead(initial==1))
    {
      state=500;            /////////go to mountain
    }
    else
    {
      state=5000;
    }
  }
*/


void state5000()
{
  int s2 =  digitalRead(start_L1);
  int s3 =  digitalRead(sd_L2);
  int const_pwm = 40;

  if(digitalRead(motor_pwm)==1)
  {
    if(s2==0 && s3==0)
    {
     digitalWrite(L1Vdir,digitalRead(tus_dir));
     analogWrite(L1Vpwm,const_pwm);
     Serial.println(analogRead(L1Vpot));
    }
    else if(s2==0 && s3==1)
    {
      const_pwm=50;
     digitalWrite(L2Vdir,digitalRead(tus_dir));
     analogWrite(L2Vpwm,const_pwm);
     Serial.println(analogRead(L2Vpot));
    }
    else if(s2==1 && s3==0)
    {
     digitalWrite(L3Vdir,digitalRead(tus_dir));
     analogWrite(L3Vpwm,const_pwm);
     Serial.println(analogRead(L3Vpot));
    }
    else if(s2==1 && s3==1)
    {
     digitalWrite(L4Vdir,digitalRead(tus_dir));
     analogWrite(L4Vpwm,const_pwm);
     Serial.println(analogRead(L4Vpot));
    }
  }
  else
  {
    analogWrite(L1Vpwm,0);
    analogWrite(L2Vpwm,0);
    analogWrite(L3Vpwm,0);
    analogWrite(L4Vpwm,0);
  }   
}
