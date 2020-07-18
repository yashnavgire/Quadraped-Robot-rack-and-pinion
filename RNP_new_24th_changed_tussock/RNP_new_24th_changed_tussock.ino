
/*
  NOTATIONS:
* *************************  HORIZONTAL  ****************************
  PINS:
  L2Hpwm : LEG 2 HORIZONTAL PWM PIN
L2Hdir : LEG 2 HORIZONTAL DIRECTION PIN
  L2Hpot : LEG 2 HORIZONTAL POT PIN
  VARIABLES:
  L2H_val  : POT VALUE OF LEG 2 HORIZONTAL
  L2H_front: LEG 2 HORIZONTAL FRONT
  L2H_back : LEG 2 HORIZONTAL BACK
  bpwmH     : BASE PWM OF HORIZOTAL LEGS
  kph       : HORIZONTAL Kp
  lnh_pwm   : PWM to feed  , where n = 1,2,3,4
  FUNCTIONS:
  L2H_Mov  : LEG 2 HORIZONTAL MOTION

* *************************  VERTICAL  *******************************
  PINS:
  L2Vpwm : LEG 2 VERTICAL PWM PIN
  L2Vdir : LEG 2 VERTICAL DIRECTION PIN
  L2Vpot : LEG 2 VERTICAL POT PIN
  VARIABLES:
  L2V_val  : POT VALUE OF LEG VERTICAL
  L2V_up   : LEG 2 VERTICAL UPWARD
  L2V_down : LEG 2 VERTICAL DOWN
  bpwmV     : BASE PWM OF VERTICAL LEGS
  kpv       : VERTICAL Kp
  lnv_pwm   : PWM to feed , where n = 1,2,3,4
FUNCTIONS:
  L2V_Mov  : LEG 2 VERTICAL MOTION

  /****************************************************************************/
#include"variables_rnp.h"
#include"pins.h"
#include"setPinMode.h"
#include"getYPR.h"
#include"ultra.h"
#include"Mov_functions.h"
#include"Mov_functions2.h"
#include"Mov_LS_functions.h"
#include"slope_functions.h"
#include"hall_functions.h"
#include"ThreeLegs_v1.h"
#include"New_LS_sanddune1.h"
#include"right_turn45_1.h"
#include"Tuning.h"
#include"left_turn_60.h"
#include"right_turn60.h"
#include"Sanddune_Initial.h"
#include"Diagonal_halfRack1.h"
#include"slope_states.h"
#include"mountain.h"
#include"retry_tussock.h"


#include"tussock1.h"

//#include"new_three_legs.h"


/****************************************************************************/
/*  READING FROM ALL 8 POTS   */
void readPots(uint8_t val)
{
  Serial.print("POTS :  ");
  Serial.print(analogRead(L1Hpot));
  Serial.print(" ");
  Serial.print(analogRead(L1Vpot));
  Serial.print("    ");

  Serial.print(analogRead(L2Hpot));
  Serial.print(" ");
  Serial.print(analogRead(L2Vpot));
  Serial.print("    ");

  Serial.print(analogRead(L3Hpot));
  Serial.print(" ");
  Serial.print(analogRead(L3Vpot));
  Serial.print("    ");

  Serial.print(analogRead(L4Hpot));
  Serial.print(" ");
  Serial.print(analogRead(L4Vpot));
  Serial.print(" | ");

  Serial.print("LS: ");
  Serial.print(digitalRead(LS_L1));
//  Serial.print("  ");
  Serial.print(digitalRead(LS_L2));
//  Serial.print("  ");
  Serial.print(digitalRead(LS_L3));
//  Serial.print("  ");
  Serial.print(digitalRead(LS_L4));
  Serial.print(" * ");
  Serial.print(digitalRead(LS_G));
  Serial.print(" | ");

  Serial.print("U:");
//  Serial.print("  ");
  distance1();
  Serial.print(dist);
  distance4();
  Serial.print(" ");
  Serial.print(dist);
  Serial.print(" | ");

  Serial.print("m:");
  Serial.print(digitalRead(mpu1));
  Serial.print(digitalRead(mpu2));
  Serial.print(" | ");

  Serial.print(digitalRead(mode_select));
  Serial.print(digitalRead(start_L1));
  Serial.print(digitalRead(sd_L2));
  Serial.print(digitalRead(tus_dir));
  Serial.print(digitalRead(initial));
  Serial.print(digitalRead(motor_pwm));
  Serial.print("**");
  Serial.println(digitalRead(proxy_mountain));
}


void setup()
{
//  Serial2.begin(2000000);
  Serial.begin(250000);
  setPM();

///////////switches////////////////////////////////
  if(digitalRead(mode_select)==1)                       //Normal Mode
{
  if(digitalRead(start_L1)==0 && digitalRead(sd_L2)==0 && digitalRead(tus_dir)==0 && digitalRead(initial)==0) //////////if gerege not passed,i.e delay included here with while 

// waiting for geregeto be passed
  {
      while(digitalRead(LS_G)==0);                        //wait till gerege is detected
      delay(3000);
      state=37;
      Serial.println("gerege passed");
  }
  else if(digitalRead(initial)==1)                        //for initial modes.
  {
    if(digitalRead(start_L1))                            //For Start Checkpoint
    {
      state=30;                                           //Go to normal walking initial
    }

    if(digitalRead(sd_L2))                          //For Sand Dune Checkpoint
     {
      state=197;                                           //Go to SD initial
     }
 
    if(digitalRead(tus_dir))                        //For Tussock Checkpoint
      {
        left_flag=1;
        right_flag=0;
        tussock_flag1=1;
        state=30; 
      }
  }
  else
  {
    if(digitalRead(start_L1))                            //For Start Checkpoint
    {
      state=37;                                           //normal walking without waiting for gerege
    }

    if(digitalRead(sd_L2))                          //For Sand Dune Checkpoint
     {
      state=31;                                           //Go to SD initial
      L1H_pwm_constrain = 150;      //200 for sanddune when front is to be taken. 130 for after sanddune                        (used in horizontal mov functions,updated in diagonal,turning,sanddune-initial and tussock)
      L1V_up_constrain = 150;       //Up and down 150 for Sand-dune initially on sanddune it is 70. For After tussock 150 & 120 (used in vertical mov functions,)
      L1V_down_constrain = 130;     
      
      L2H_pwm_constrain = 150;
      L2V_up_constrain = 150;
      L2V_down_constrain = 120;
      
      L3H_pwm_constrain = 150;
      L3V_up_constrain = 150;
      L3V_down_constrain =130;
      
      L4H_pwm_constrain = 150;
      L4V_up_constrain = 150;
      L4V_down_constrain = 130;  

      turn_flag=1;
     }
 
    if(digitalRead(tus_dir))                        //For Tussock Checkpoint
      {
        left_flag=1;
        right_flag=0;
        state=31 ;                                  //setting the constrains for tussock retry,i.e countThrash etc.
       tussock_flag1=1;
      counter=0;
      }
  
  }                                            //Go to mountain initial
}  
else if(digitalRead(mode_select)==0)                 //Tuninig Mode
{
  Serial.println("T" );
  if(digitalRead(start_L1)==1 && digitalRead(sd_L2)==1 && digitalRead(initial)==1)
  {
    state=0;  
  }
  
  else if(digitalRead(initial)==1 && digitalRead(start_L1)==0 && digitalRead(sd_L2)==0)
   {
    Serial.println("500");
//    state=0;
      state=499;            /////////go to mountain
//     state=0;
   }
   else
   {
      state=5000;
//     state=0;
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//  while(digitalRead(LS_G)==0);                        //wait till gerege is detected
//  if(retry_flag==0)
//    delay(5000);

  L1H_initial = analogRead(L1Hpot);
  L2H_initial = analogRead(L2Hpot);
  L3H_initial = analogRead(L3Hpot);
  L4H_initial = analogRead(L4Hpot);
  
//  attachInterrupt(digitalPinToInterrupt(L1V_hall), ISR_1V, FALLING);
//  attachInterrupt(digitalPinToInterrupt(L2V_hall), ISR_2V, FALLING);
//  attachInterrupt(digitalPinToInterrupt(L3V_hall), ISR_3V, FALLING);
//  attachInterrupt(digitalPinToInterrupt(L4V_hall), ISR_4V, FALLING);

  ppos1v = L1V_down;
  ppos2v = L2V_down;
  ppos3v = L3V_down;
  ppos4v = L4V_down;

digitalWrite(mpu_mode,0);   /// 0 is for yaw
//  state=1007 ;
}



void loop()
{
  /*   ENTER THE FUNCTION VALUES TO BE PASSED LIKE L1H_front , L1H_back , L1V_up , L1V_down     */
  /*  FOR readPots  enter leg no. and 0 for all readings*/
//Serial.print(hall_count1v);

//Serial.print(" ");
//Serial.print(hall_count2v);
//Serial.print(" ");
//Serial.print(hall_count3v);
//Serial.print(" ");
//Serial.print(hall_count4v);
//Serial.print(" ");
//Seri*al.print(digitalRead(LS_L2f));
//Serial.print(digitalRead(LS_L2b));
//Serial.print(" ");
//Serial.print(digitalRead(LS_L3f));
//Serial.println(digitalRead(LS_L3b));  
//
//Serial.print("LS: ");
//  Serial.print(digitalRead(LS_L1f));
//  Serial.print("  ");
//  Serial.print(digitalRead(LS_L2f));
//  Serial.print("  ");
//  Serial.print(digitalRead(LS_L3f));
//  Serial.print("  ");
//  Serial.print(digitalRead(LS_L4f));
//  Serial.print(" * ");
//  Serial.print(digitalRead(LS_L1b));
//  Serial.print("  ");
//  Serial.print(digitalRead(LS_L2b));
////  Serial.print("  ");
//  Serial.print(digitalRead(LS_L4f));
//  Serial.print("  ");
//  Serial.print(digitalRead(LS_L4b));
//  Serial.print("   ");
//  Serial.println(sanddune_counter1);
//Serial.print(digitalRead(mpu1));
//Serial.println(digitalRead(mpu2));

  switch (state)
  {
    case 0:
      readPots(0);
      break;

    case 5000:            //tuning states.
      state5000();
      break;
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    case 1:
      state1();
      break;

    case 2:
      state2();
      break;

    case 3:
      state3();
      break;

    case 4:
      state4();
      break;

    case 5:
      state5();
      break;

    case 6:
      state6();
      break;

    case 7:
      state7();
      break;

    case 8:
      state8();
      break;

    case 9:
      state9();
      break;

    case 10:
      state10();
      break;

    case 11:
      state11();
      break;

    case 12:
      state12();
      break;            //ThreeLegs_v1 initial
    /////////////////////////////////////////////////////////////////////////////////////
    case 15:
      state15();
      break;

    case 16:
      state16();
      break;

    case 17:
      state17();
      break;

    case 18:
      state18();
      break;

    case 19:
      state19();
      break;

    case 20:
      state20();
      break;

    case 21:
      state21();
      break;

    case 22:
      state22();
      break;

    case 23:
      state23();
      break;

    case 24:
      state24();
      break;

    case 25:
      state25();
      break;

    case 26:
      state26();
      break;

    case 27:
      state27();
      break;        //ThreeLegs_v1_walking
    /////////////////////////////////////////////////////////////////////////////
        case 30:
        state30();
        break;

    case 31:
      state31();
      break;

    case 32:
      state32();
      break;

    case 33:
      state33();
      break;

    case 34:
      state34();
      break;

    case 35:
      state35();
      break;

    case 36:
      state36();
      break;     //Straight walking diagonal

    case 37:
      state37();
      break;

    case 41:
      state41();
      break;

    case 42:
      state42();
      break;

     case 43:
      state43();
      break;
      
    case 44:
      state44();
      break;
      
    case 45:
      state45();
      break;
      
    case 46:
      state46();
      break;
    ////////////////////////////////////////////////////////////////////////////////////
    case 101:
      state101();
      break;

    case 102:
      state102();
      break;

    case 103:
      state103();
      break;

    case 104:
      state104();
      break;

    case 105:
      state105();
      break;

    case 106:
      state106();
      break;          //Left turn initial
    ////////////////////////////////////////////////////////////////////////
    case 110:
      state110();
      break;

    case 111:
      state111();
      break;

    case 112:
      state112();
      break;

    case 113:
      state113();
      break;

    case 114:
      state114();
      break;

    case 115:
      state115();
      break;

    case 116:
      state116();
      break;

    case 117:
      state117();
      break;

    case 118:
      state118();
      break;

    case 119:
      state119();
      break;

    case 120:
      state120();
      break;

    case 121:
      state121();
      break;

    case 122:
      state122();
      break;

    case 123:
      state123();
      break;

    case 124:
      state124();
      break;

    case 125:
      state125();
      break;

    case 126:
    state126();
      break;

    case 127:
      state127();
      break;

    case 128:
      state128();
      break;

    case 129:
      state129();
      break;

    case 130:
      state130();
      break;

    case 131:
      state131();
      break;            //Left turn 45
    ///////////////////////////////////////////////////////////////////////////

    case 132:
      state132();
      break;

    case 133:
      state133();
      break;

    case 134:
      state134();
      break;

    case 135:
      state135();
      break;

    case 136:
      state136();
      break;

    case 137:
      state137();
      break;
    //////////////////////////////////////////////////////
     /////////////////////SHARP LEFT TURN BEFORE TUSSOCK///////////////////////////////////////////////////////////////////
    case 141:
      state141();
      break;           

    case 142:
      state142();
      break;

    case 143:
      state143();
      break;

    case 144:
      state144();
      break;

    case 145:
      state145();
      break;

    case 146:
      state146();
      break;
///////////////////////////////////////////////////////////////////

    case 151:
      state151();
      break;

    case 152:
      state152();
      break;

    case 153:
      state153();
      break;

    case 154:
      state154();
      break;

    case 155:
      state155();
      break;

    case 156:
      state156();
      break;

    case 157:
//      state157();
      break;

    case 158:
//      state158();
      break;

    case 159:
//      state159();
      break;

    case 160:
//      state160();
      break;

    case 161: 
//      state161();
      break;

    case 162:                     //Sanddune initial
//      state162();
      break;

    /////////////////////////////////////////////////////////////////////
    
    ///

    case 170:
    state170();
    break;
    
    case 171:
      state171();
      break;

    case 172:
      state172();
      break;

    case 173:
      state173();
      break;

    case 174:
      state174();
      break;

    case 175:
      state175();
      break;

    case 176:
      state176();
      break;

    case 177:
      state177();
      break;

    case 178:
      state178();
      break;

    case 179:
      state179();
      break;

    case 180:
      state180();
      break;

    case 181:
      state181();
      break;

    case 182:
      state182();
      break;

    case 183:          ///Sanddune Walking
      state183();
      break;

    //Sand-dune Diagonal States
   case 184:
    state184();
    break;
   
   case 185:
      state185();
      break;

    case 186:
      state186();
      break;

    case 187:
      state187();
      break;

    case 188:
      state188();
      break;

    case 189:
      state189();
      break;

    case 190:
      state190();
      break;          //Sand-dune diagonal states end

     case 191:
       state191();
       break;

     case 192:
        state192();
        break;

     case 193:
        state193();
        break;

     case 194:
        state194();
        break;
        
     case 195:
        state195();
        break;

     case 196:
        state196();
        break;

//SD Retry
     case 197:
        state197();
        break;


    ///////////////////////////////////////////////////////////////////////////////
    case 210:
      state210();
      break;

    case 211:
      state211();
      break;

    case 212:
      state212();
      break;

    case 213:
      state213();
      break;

    case 214:
      state214();
      break;

    case 215:
      state215();
      break;

    case 216:
      state216();
      break;

    case 217:
      state217();
      break;

    case 218:
      state218();
      break;

    case 219:
      state219();
      break;

    case 220:
      state220();
      break;

    case 221:
      state221();
      break;

    case 222:
      state222();
      break;

    case 223:
      state223();
      break;

    case 224:
      state224();
      break;

    case 225:
      state225();
      break;

    case 226:
      state226();
      break;

    case 227:
      state227();
      break;

    case 228:
      state228();
      break;

    case 229:
      state229();
      break;

    case 230:
      state230();
      break;

    case 231:
      state231();
      break;            //Right turn0
///////////////////////////////////////////////////////////////////////////////
case 357:
state357();
break;

case 350:
state350();
break;
///////////////TUSSOCK///////////////////////////
  case 351:
    state351();
    break;

  case 352:
    state352();
    break;

  case 353:
    state353();
    break;

  case 354:
    state354();
    break;

  case 355:
    state355();
    break;

  case 356:
    state356();
    break;

  case 358:
     state358();
     break;

//Tussock Ends
////////////////////////////////////////////////////////
    
    case 401:
      state401();
      break;

    case 402:
      state402();
      break;

    case 403:
      state403();
      break;

    case 404:
      state404();
      break;

    case 405:
      state405();
      break;

    case 406:
      state406();
      break;

    case 407:
      state407();
      break;

    case 408:
      state408();
      break;

    case 409:
      state409();
      break;


    case 410:
      state410();
      break;

    case 411:
      state411();
      break;

    case 412:
      state412();
      break;

    case 413:
      state413();
      break;                        //////slope walking three legs

    ///////////////////mountain walking diagonal////////////////////////
    case 499:                       //INITIAL
      state499();
      break;
    
    case 500:
      state500();
      break;

     case 501:
        state501();
        break;

     case 502:
        state502();
        break;

     case 503:
        state503();
        break;

     case 504:
        state504();
        break;

     case 505:
        state505();
        break;

      case 510:
          state510();
          break;
  /////////////////////////////////////////////////////////////
          case 601:
        state601();
        break;

     case 602:
        state602();
        break;

     case 603:
        state603();
        break;

     case 604:
        state604();
        break;

    ////////////////////////////////////////////////////////////////////////////
    case 1000:                    //ALL DOWN
//            L1_V_MovD(L1V_down);
      //      L2_V_MovD(L2V_down);
//            L3_V_MovD(L3V_down);
//            L4_V_MovD(L4V_down);

      // ALL downmid
      L1_V_MovD(L1V_downmid+90);
      L2_V_MovD(L2V_downmid-90);
      L3_V_MovD(L3V_downmid+90);
      L4_V_MovD(L4V_downmid-90);

      break;

    case 1001:                    //ALL UP
//      val2v = L2V_upmid;
  val4v = L4V_upmid;
//  L2_V_MovUP(val2v);
  L4_V_MovUP(val4v);
//  digitalWrite(L3Vdir, 0);
//  analogWrite(L3Vpwm, stall_base3v-5);
//  digitalWrite(L4Vdir, 0);
//  analogWrite(L4Vpwm, stall_base4v);

  Serial.println("31");
  if (flag2vu == 1 && flag4vu == 1)
  {
    L2V_sum = 0;
    L4V_sum = 0;
    flag2vu = 0;
    flag4vu = 0;
    flag2_up=0;
    flag4_up=0;
    analogWrite(L3Vpwm,0);
    analogWrite(L2Vpwm, 0);
    analogWrite(L4Vpwm, 0);
    state = 0;
  }
      break;

    case 1002:      //ALL BACK
  L1_H_Mov(L1H_back);
  L2_H_Mov(L2H_back);
  L3_H_Mov(L3H_back);
  L4_H_Mov(L4H_back);
  if(flag1h == 1 && flag3h == 1 && flag2h == 1 && flag4h == 1)
  {
    flag1h =0;
    flag3h =0;
    flag2h =0;
    flag4h = 0;
      analogWrite(L1Hpwm, 0);
      analogWrite(L2Hpwm, 0);
      analogWrite(L3Hpwm, 0);
      analogWrite(L4Hpwm, 0);
  }

 
      break;

    case 1003:                    //ALL FRONT
      L2_H_Mov(L2H_front);
      L4_H_Mov(L4H_front);

      L1_H_Mov(L1H_front);
      L3_H_Mov(L3H_front);
      break;


    case 1005:
      distance1();
      Serial.println(dist);
      break;

    case 1004:
      //      digitalWrite(52, 0);
      angle = getDMPAngle('y');
      Serial.println(angle);
      break;

    case 1006:
      //      L3_V_MovUP(L3V_up - ;50)
      L3_V_MovD(L3V_down);
      break;

    case 1007:                    //ALL MID
//      L1_V_MovUP(L1V_upmid);
      L2_V_MovUP(L2V_upmid); 
//      L3_V_MovUP(L3V_upmid);
//      L4_V_MovUP(L4V_upmid);
//     Serial.println(analogRead(L1Vpot));
     Serial.println(analogRead(L2Vpot));
//     Serial.println(analogRead(L3Vpot));
//     Serial.println(analogRead(L4Vpot));
//     if (flag1vu == 1)
//     {
//     flag1vu = 0;
//     analogWrite(L1Vpwm,0);
//     delay(500);
//     state=1008;
//     }
     if (flag2vu == 1)
     {
     flag2vu = 0;
     analogWrite(L2Vpwm,0);
     delay(500);
     state=1008;
     }
//     if (flag3vu == 1)
//     {
//     flag3vu = 0;
//     analogWrite(L3Vpwm,0);
//     delay(500);
//     state=1008;
//     }
//     if (flag4vu == 1)
//     {
//     flag4vu = 0;
//     analogWrite(L4Vpwm,0);
//     delay(500);
//     state=1008;
//     }  
      break;

    case 1008:                    //ALL DOWNMID
      L1_V_MovD(L1V_downmid);
//      L2_V_MovD(L2V_downmid);
//      L3_V_MovD(L3V_downmid);
//      L4_V_MovD(L4V_downmid);
      Serial.println(analogRead(L1Vpot));
      Serial.println(analogRead(L2Vpot));
      Serial.println(analogRead(L3Vpot));
      Serial.println(analogRead(L4Vpot));
     if (flag1vd == 1)
     {
     flag1vd = 0;
     analogWrite(L1Vpwm,0);
     delay(500);
     state=1007;
     }  
//     if (flag2vd == 1)
//     {
//     flag2vd = 0;
//     analogWrite(L2Vpwm,0);
//     delay(500);
//     state=1007;
//     }  
//     if (flag3vd == 1)
//     {
//     flag3vd = 0;
//     analogWrite(L3Vpwm,0);
//     delay(500);
//     state=1007;
//     }  
//     if (flag4vd == 1)
//     {
//     flag4vd = 0;
//     analogWrite(L4Vpwm,0);
//     delay(500);
//     state=1007;
//     }  
      break;

    case 1009:                    // Diagonal Initial;
//      L2_H_Mov(L2H_front);
//      L4_H_Mov(L4H_front);
//      L1_H_Mov(L1H_back);
//      L3_H_Mov(L3H_back);
      L1_V_MovD(L1V_downmid);
      L2_V_MovD(L2V_downmid);
      L3_V_MovD(L3V_downmid);
      L4_V_MovD(L4V_downmid);
//      L1_V_MovD(L1V_down-90);
//      L2_V_MovD(L2V_down+90);
//      L3_V_MovD(L3V_down-90);
//      L4_V_MovD(L4V_down+90);
      if(flag1vd==1 && flag2vd==1 && flag3vd==1 && flag4vd==1 )
      {
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
      }
      break;

    case 1010:
      //      if(!flag3vu)
      //      {
      //      L3_V_MovUP_hall(L3V_upmid);
      ////       Serial.println(flag3vu);
      ////      delay(10);
      //      }
      //      if(flag3vu==1)
      //      {
      //        analogWrite(L3Vpwm,0);
      //       }

      if (!flag2vu)
      {
        L2_V_MovUP_hallD();
        Serial.println(flag2vu);
        //      delay(10);
      }
      if (flag2vu == 1)
      {
        analogWrite(L2Vpwm, 0);
      }
      break;

    case 1011:
      //  Serial.println(digitalRead(LS_L4up));
      break;

    case 1012:
      if (flag1vd == 0 || flag2vd == 0 || flag3vd == 0 || flag4vd == 0)
        const_all_down();
      break;

    case 1013:
      //      if(flag4vd==1 || digitalRead(LS_L4f)==0 ||digitalRead(LS_L4b)==0)
      flag4_down = 1;
      flag1_down = 1;
      flag2_down = 1;
      flag3_down = 1;
//              L1_V_MovSD();
//      Serial.println("1013");
             L4_V_MovSD();
             if(flag4vd==1)
             {
             state=1014;
             flag4_down=0;
             flag4vd=0;
              delay(1000);
             }
//             L3_V_MovSD();
//             L4_V_MovSD();
      break;

    case 1014:
      flag4_up = 1;
      flag3_up = 1;
      flag2_up = 1;
      flag1_up = 1;
//      Serial.println("1014");
//      L4_V_MovUP_hall();
      //      L3_V_MovUP_hall();
            L4_V_MovSU();
            if(flag4vu==1)
            {
              state=1013;
              delay(1000);
              flag4vu=0;
              flag4_up=0;
            }
//            L1_V_MovUP_hall();
      break;


    case 1020:
     flag4_down=1;
    L4_V_MovSD();
      Serial.println(hall_count4v);
     break;

      case 1021:
     flag4_up=1;
      L4_V_MovSU();
      Serial.println(hall_count4v);
     break;


    case 1030:
      hall_count1v=1;
      hall_count2v=0;
      hall_count3v=0;
      hall_count4v=0;
      state=1031;
      break;

    case 1031:
    L1_V_MovSD();
    L2_V_MovSD();
    L3_V_MovSD();    
    L4_V_MovSD();
    break;

     case 1032:
     
    L1V_down_constrain = 150; 
    L2V_down_constrain = 150;
    L3V_down_constrain = 150;
    L4V_down_constrain = 150;
  
     L1_V_MovD(L1V_down);
     L2_V_MovD(L2V_down);
     L3_V_MovD(L3V_down);
//     L4_V_MovD(L4V_down);

      if(flag1vd==1 && flag2vd==1 && flag3vd==1 && flag4vd==1)
      {
        delay(1000);
//      state=185;
      analogWrite(L1Vpwm, 0);
      analogWrite(L2Vpwm, 0);
      analogWrite(L3Vpwm, 0);
      analogWrite(L4Vpwm, 0);
      flag1vd=0;
      flag2vd=0;
      flag3vd=0;
      flag4vd=0;
      
     L1H_pwm_constrain = 150;      
     L1V_up_constrain = 200;       
     L1V_down_constrain = 100;     
    
     L2H_pwm_constrain = 150;
     L2V_up_constrain = 200;
     L2V_down_constrain = 80;
    
     L3H_pwm_constrain = 150;
     L3V_up_constrain = 200;
     L3V_down_constrain =80;
    
     L4H_pwm_constrain = 150;
     L4V_up_constrain = 200;
     L4V_down_constrain = 100;
  
      delay(500); 
      }    
     break;

     case 1033:
     Serial.print(digitalRead(mpu1));
     Serial.println(digitalRead(mpu2));
     break;

     case 1034:
     distance4();
//     Serial.print(dist);
//     Serial.print(" ");
//     distance4();
     Serial.print(dist);
     Serial.println(" ");
    break;

     case 1035:
     L2_H_Mov(L2H_front);
     if(flag2h==1)
     {
      flag2h=0;
      state=1036;
      delay(500);
     }
     break;

     case 1036:
     L2_H_Mov(L2H_back);
     if(flag2h==1)
     {
      flag2h=0;
      analogWrite(L2Hpwm,0);
//      state=1035;
      delay(500);
     }
     break;

     case 1037:
     digitalWrite(Udir,1);
     analogWrite(Upwm,100);
     break;
     

      case 1038:
      val1h=L1H_front;
//      val1h=L1H_back;
       L1_H_Mov(val1h);
     if(flag1h==1)
     {
      flag1h=0;
//      state=1036;
      delay(500);
     }
     break;

      
      case 1039:
      val2h=L2H_front;
//      val2h=L2H_back;
       L2_H_Mov(val2h);
     if(flag2h==1)
     {
      flag2h=0;
      delay(500);
     }
      break;
     
      case 1040:
      val3h=L3H_front;
//      val3h=L3H_back;
       L3_H_Mov(val3h);
     if(flag3h==1)
     {
      flag3h=0;
//      state=1036;
      delay(500);
     }
     break;

     
      case 1041:
      val4h=L4H_front;
//      val4h=L4H_back;
       L4_H_Mov(val4h);
     if(flag4h==1)
     {
      flag4h=0;
//      state=1036;
      delay(500);
     }
     break;

    case 1042:
      val1v = L1V_upmid;
//  L2_V_MovUP(val2v);
    L1_V_MovUP(val1v);
    break;

    default:
    Serial.println("Invalid");

}
}
