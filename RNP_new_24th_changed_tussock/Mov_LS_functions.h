      /* Limit Switch Function*/
/*
 * 
 * ye Sab FLAGS ka khel hai!!
 * Flag is getting set when I've pressed the LS
 * but it doesn't get reset when LS is released!
 * since flag is set, the bot goes to the next state while also writing the pwm for previous state instead of making the PWM 0
 * 
 */
/*FUNCTIONS*/
/*LEG1*/
void L1_V_MovLS(int16_t valv)                                                          //front reading > back reading
{
  L1V_val = analogRead(L1Vpot);
  L1V_err = (L1V_val - valv);
  

  if ( !digitalRead(LS_L1)||(abs(L1V_err) < thrs1v))
  {
    if(abs(L1V_err) < 120 && abs(L1V_err) > thrs1v)
    {
      L1V_val = analogRead(L1Vpot);                                                       //Read pot
      L1V_err = L1V_val - valv;                                                           //Cal.Error
      L1V_sum = L1V_sum + L1V_err;
      digitalWrite(L1Vdir, L1V_err > 0);                                                 //Def. dir
  
      l1v_pwm = base1v + ki1v * abs(L1V_sum) + kp1v * abs(L1V_err);                      //Cal. pwm
      analogWrite(L1Vpwm, constrain(l1v_pwm, 0,L1V_down_constrain));                                 //Run leg
//      flag1vd=0;
    }
     else 
      {
      flag1vd = 1;
//      Serial.println("s");
//      if(sanddune_counter<2)
      delay(100);
      analogWrite(L1Vpwm, 0);
      }
   }
   else
  {
    L1V_val = analogRead(L1Vpot);                                                       //Read pot
    L1V_err = L1V_val - valv;                                                           //Cal.Error
    L1V_sum = L1V_sum + L1V_err;
    digitalWrite(L1Vdir, L1V_err > 0);                                                 //Def. dir

    l1v_pwm = base1v + ki1v * abs(L1V_sum) + kp1v * abs(L1V_err);                      //Cal. pwm
    analogWrite(L1Vpwm, constrain(l1v_pwm, 0,L1V_down_constrain));                                 //Run leg
//    flag2vd=0;
  }
  //    Serial.println(L1V_err);
}


/*LEG2*/
void L2_V_MovLS(int16_t valv)                                                          //front reading > back reading
{
  L2V_val = analogRead(L2Vpot);
  L2V_err = (L2V_val - valv);

  if (!digitalRead(LS_L2) || (abs(L2V_err) < thrs2v))
  {
    if (abs(L2V_err) < 120 && abs(L2V_err) > thrs2v)
    {
      L2V_val = analogRead(L2Vpot);                                                       //Read pot
      L2V_err = L2V_val - valv;                                                           //Cal.Error
      L2V_sum = L2V_sum + L2V_err;
      digitalWrite(L2Vdir, L2V_err > 0);                                                 //Def. di
      
      l2v_pwm = base2v + ki2v * abs(L2V_sum) + kp2v * abs(L2V_err);                      //Cal. pwm

      analogWrite(L2Vpwm, constrain(l2v_pwm, 0,L2V_down_constrain));                                 //Run leg
//      flag2vd=0;
    }
    else 
    {
      flag2vd = 1;
//      if(sanddune_counter>=2)
      delay(100);
      analogWrite(L2Vpwm, 0);
    }
  }
  else
  {
    L2V_val = analogRead(L2Vpot);                                                       //Read pot
    L2V_err = L2V_val - valv;                                                           //Cal.Error
    L2V_sum = L2V_sum + L2V_err;
    digitalWrite(L2Vdir, L2V_err > 0);                                                 //Def. dir

    l2v_pwm = base2v + ki2v * abs(L2V_sum) + kp2v * abs(L2V_err);                      //Cal. pwm
    analogWrite(L2Vpwm, constrain(l2v_pwm, 0,L2V_down_constrain));                                 //Run leg
//    flag2vd=0;
  }
}

/*LEG3*/
void L3_V_MovLS(int16_t valv)
{

  L3V_val = analogRead(L3Vpot);
  L3V_err = (L3V_val - valv);

  if (!digitalRead(LS_L3) || (abs(L3V_err) < thrs3v))
  {
    if (abs(L3V_err) < 120 && abs(L3V_err) > thrs3v)
    {
      L3V_val = analogRead(L3Vpot);                                                      //Read pot
      L3V_err = (L3V_val - valv);                                                        //Cal.Error
      L3V_sum = L3V_sum + L3V_err;
      digitalWrite(L3Vdir, L3V_err > 0);                                                //Def. dir

      l3v_pwm = base3v + ki3v * abs(L3V_sum) + kp3v * abs(L3V_err);                      //Cal. pwm
      analogWrite(L3Vpwm, constrain(l3v_pwm, 0,L3V_down_constrain));                                  //Run leg
//      flag3vd=0;
//      Serial.println(sanddune_counter);
//      Serial.println("L");
    }
    else 
    {
//      Serial.println("S");
      flag3vd = 1;
//      if(sanddune_counter>=2)
      delay(100);
      analogWrite(L3Vpwm, 0);
    }
  }
  else 
  {
//     Serial.println("E");
    L3V_val = analogRead(L3Vpot);                                                      //Read pot
    L3V_err = (L3V_val - valv);                                                        //Cal.Error
    L3V_sum = L3V_sum + L3V_err;
    digitalWrite(L3Vdir, L3V_err > 0);                                                //Def. dir
    l3v_pwm = base3v + ki3v * abs(L3V_sum) + kp3v * abs(L3V_err);                      //Cal. pwm
    analogWrite(L3Vpwm, constrain(l3v_pwm, 0, L3V_down_constrain));                                  //Run leg
//    flag3vd=0;
  }
}

/*LEG4*/
void L4_V_MovLS(int16_t valv)
{
  L4V_val = analogRead(L4Vpot);
  L4V_err = (L4V_val - valv);

  if ( !digitalRead(LS_L4) || (abs(L4V_err) < thrs4v))
  {
    if (abs(L4V_err) < 120 && abs(L4V_err) > thrs4v ) 
    {
//      Serial.print("    L4V    ");
      L4V_val = analogRead(L4Vpot);                                                      //Read pot
      L4V_err = (L4V_val - valv);                                                        //Cal.Error
      L4V_sum = L4V_sum + L4V_err;
      digitalWrite(L4Vdir, L4V_err > 0);                                                //Def. dir : Initially <
      l4v_pwm = base4v + ki4v * abs(L4V_sum) + kp4v * abs(L4V_err);                      //Cal. pwm

      analogWrite(L4Vpwm, constrain(l4v_pwm, 0, L4V_down_constrain));                                  //Run leg
//      flag4vd=0;
    }
    else 
    {
//      Serial.println("S");
      flag4vd = 1;
//      if(sanddune_counter<2)
      delay(100);
      analogWrite(L4Vpwm, 0);
    }
  }
  else
  {
    L4V_val = analogRead(L4Vpot);                                                      //Read pot
    L4V_err = (L4V_val - valv);                                                        //Cal.Error
    L4V_sum = L4V_sum + L4V_err;
    digitalWrite(L4Vdir, L4V_err > 0);                                                //Def. dir : Initially <
    l4v_pwm = base4v + ki4v * abs(L4V_sum) + kp4v * abs(L4V_err);                      //Cal. pwm

    analogWrite(L4Vpwm, constrain(l4v_pwm,0, L4V_down_constrain));                                  //Run leg
//    flag4vd=0;
  }
} 
