
void L1_V_MovNLS(int16_t valv)                                                          //front reading > back reading
{
  L1V_val = analogRead(L1Vpot);
  L1V_err = (L1V_val - valv);
  

  if (!digitalRead(LS_L1f) && !digitalRead(LS_L1b)||(abs(L2V_err) < thrs2v))
  {
    flag1vd = 1;
    analogWrite(L1Vpwm, 0);
  } 
  else if(flag1vd==0)
  {
    L1V_val = analogRead(L1Vpot);                                                       //Read pot
    L1V_err = L1V_val - valv;                                                           //Cal.Error
    L1V_sum = L1V_sum + L1V_err;
    digitalWrite(L1Vdir, L1V_err > 0);                                                 //Def. dir
    l1v_pwm = base1v + ki1v * abs(L1V_sum) + kp1v * abs(L1V_err);                      //Cal. pwm
    analogWrite(L1Vpwm, constrain(l1v_pwm,0, 100));                                 //Run leg
  }
}

/*LEG2*/
void L2_V_MovNLS(int16_t valv)                                                          //front reading > back reading
{
  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - valv);

  if (!digitalRead(LS_L2f) && !digitalRead(LS_L2b) || (abs(L2V_err) < thrs2v))
  {
      flag2vd = 1;
      analogWrite(L2Vpwm, 0);
  }
  else if(flag2vd==0)
  {
    L2V_val = analogRead(L2Vpot);                                                       //Read pot
    L2V_err = L2V_val - valv;                                                           //Cal.Error
    L2V_sum = L2V_sum + L2V_err;
    digitalWrite(L2Vdir, L2V_err > 0);                                                 //Def. dir
    l2v_pwm = base2v + ki2v * abs(L2V_sum) + kp2v * abs(L2V_err);                      //Cal. pwm
    analogWrite(L2Vpwm, constrain(l2v_pwm, 0, 100));                                 //Run leg
  }
}

/*LEG3*/
void L3_V_MovNLS(int16_t valv)
{

  L3V_val = analogRead(L3Vpot);
  L3V_err = (L3V_val - valv);

  if (!digitalRead(LS_L3f) && !digitalRead(LS_L3b) || (abs(L3V_err) < thrs3v))
  {
      flag3vd = 1;
      analogWrite(L3Vpwm, 0);
  }
  else if(flag3vd==0) 
  {
    L3V_val = analogRead(L3Vpot);                                                      //Read pot
    L3V_err = (L3V_val - valv);                                                        //Cal.Error
    L3V_sum = L3V_sum + L3V_err;
    digitalWrite(L3Vdir, L3V_err < 0);                                                //Def. dir
    l3v_pwm = base3v + ki3v * abs(L3V_sum) + kp3v * abs(L3V_err);                      //Cal. pwm
    analogWrite(L3Vpwm, constrain(l3v_pwm, 0, 100));                                  //Run leg
  }
}

/*LEG4*/
void L4_V_MovNLS(int16_t valv)
{
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - valv);

  if (!digitalRead(LS_L4f) && !digitalRead(LS_L4b) || (abs(L4V_err) < thrs4v))
  {
      flag4vd = 1;
      analogWrite(L4Vpwm, 0);
  }
  else if(flag4vd==0)
  {
    L4V_val = analogRead(L4Vpot);                                                      //Read pot
    L4V_err = (L4V_val - valv);                                                        //Cal.Error
    L4V_sum = L4V_sum + L4V_err;
    digitalWrite(L4Vdir, L4V_err > 0);                                                //Def. dir : Initially <
    l4v_pwm = base4v + ki4v * abs(L4V_sum) + kp4v * abs(L4V_err);                      //Cal. pwm
    analogWrite(L4Vpwm, constrain(l4v_pwm,0, 100));                                  //Run leg
  }
} 
