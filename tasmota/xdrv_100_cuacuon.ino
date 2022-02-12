#ifdef ESP32
#ifdef USE_CUACUON

#define XDRV_100           100


#define GPIOO_LEN 1 //relay 1
#define GPIOO_XUONG 2 //reay 2
#define GPIOO_DUNG 3 //relay 3
#define GPIOO_KHOA 4 //reay 4

#define D_CMND_LEN "LEN"
#define D_CMND_XUONG "XUONG"
#define D_CMND_DUNG "DUNG"
#define D_CMND_KHOA "KHOA"



/***************COMMAND RM START*******************/
const char kRMCommands[] PROGMEM = "|"  // No prefix
D_CMND_LEN "|" D_CMND_XUONG "|" D_CMND_DUNG "|" D_CMND_KHOA;
void (* const RMCommand[])(void) PROGMEM = {
  &cmndLen, &cmndXuong, &cmndDung, &cmndKhoa};
void cmndLen(void)
{
  if (XdrvMailbox.payload == 3611)
  {
    ExecuteCommandPower(GPIOO_LEN, POWER_ON, SRC_IGNORE);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
    ExecuteCommandPower(GPIOO_LEN, POWER_OFF, SRC_IGNORE);
    AddLog_P(LOG_LEVEL_INFO, PSTR("DANG LEN"));    
  }
}
void cmndXuong(void)
{

  if (XdrvMailbox.payload == 3611)
  {
    ExecuteCommandPower(GPIOO_XUONG, POWER_ON, SRC_IGNORE);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
    ExecuteCommandPower(GPIOO_XUONG, POWER_OFF, SRC_IGNORE);
    AddLog_P(LOG_LEVEL_INFO, PSTR("DANG XUONG"));
  }
}

void cmndDung(void)
{

  if (XdrvMailbox.payload == 3611)
  {
    ExecuteCommandPower(GPIOO_DUNG, POWER_ON, SRC_IGNORE);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
    ExecuteCommandPower(GPIOO_DUNG, POWER_OFF, SRC_IGNORE);
    AddLog_P(LOG_LEVEL_INFO, PSTR("DANG DUNG"));
  }
}

void cmndKhoa(void)
{

  if (XdrvMailbox.payload == 3611)
  {
    ExecuteCommandPower(GPIOO_KHOA, POWER_ON, SRC_IGNORE);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
    ExecuteCommandPower(GPIOO_KHOA, POWER_OFF, SRC_IGNORE);
    AddLog_P(LOG_LEVEL_INFO, PSTR("DANG KHOA"));
  }
}




/***************COMMAND RM END*******************/

bool Xdrv100(uint8_t function) {
  bool result = false;

  switch (function) {
    case FUNC_COMMAND:
      result = DecodeCommand(kRMCommands, RMCommand);
      break;
    case FUNC_INIT:

      break;
    case FUNC_EVERY_SECOND:

     break;
     case FUNC_EVERY_50_MSECOND:
 
     break;
    case FUNC_LOOP:
      //code here
    break;
  }
  return result;
}
#endif //use demo
#endif //use esp 32