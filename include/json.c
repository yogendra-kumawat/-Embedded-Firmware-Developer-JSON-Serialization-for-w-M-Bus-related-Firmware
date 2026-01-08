#include "json.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

 char* searlizer(input input_data ,int buff_length){
    meta m=input_data.m;
    readings r=input_data.r;
    data d=input_data.d;
    int dc=input_data.device_count;
   
int leng=strlen(m.date)+strlen(m.deviceType)+strlen(m.gatewayId)+20;//as 10 is the max value count for 2^16(int_16 length)
leng=leng+strlen(r.deviceId)+strlen(r.media)+strlen(r.meter)+strlen(r.unit);
leng=leng+strlen(d.meter_datatime)+strlen(d.status)+strlen(d.timestamps)+10;
leng=leng+285;//charactors in blank format for jaison;
if (strlen(m.date)!=10){//format handling
    char* message="wrong data length for date (yyyy-mm-dd,10 characters)";
    return message;
}

if(buff_length<leng){//buffer size handling
    char * message="low buffer length";
    return message;
    
}

char *jaon =(char*)malloc(leng*sizeof(char));//memory assigning
snprintf(jaon,leng,"[{\"gatewayId\": \"%s\",\"date\": \"%s\",\"deviceType\": \"%s\",\"interval_minutes\": %d,\"total_readings\": %d,\"values\": {\"device_count\": %d,\"readings\": [{\"media\": \"%s\", \"meter\": \"%s\",\"deviceId\": \"%s\",\"unit\": \"%s\",\"data\": [{\"timestamp\": \"%s\",\"meter_datetime\": \"%s\",\"total_m3\": %f,\"status\": \"%s\"}]}]}}]",m.gatewayId,m.date,m.deviceType,m.interval_minutes,m.total_readings,dc,r.media,r.meter,r.deviceId,r.unit,d.timestamps,d.meter_datatime,d.total_m3,d.status);

return jaon;
}
