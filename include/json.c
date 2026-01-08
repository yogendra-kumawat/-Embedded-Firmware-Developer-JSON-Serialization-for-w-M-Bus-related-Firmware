#include "json.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
 char* searlizer(input input_data ,int buff_length){
    meta m=input_data.m;
    readings r=input_data.r;
    data d=input_data.d;
    int dc=input_data.device_count;
   
int leng=strlen(m.date)+strlen(m.deviceType)+strlen(m.gatewayId)+20;//(int)log10(m.interval_minutes)+(int)log10(m.total_readings);
leng=leng+strlen(r.deviceId)+strlen(r.media)+strlen(r.meter)+strlen(r.unit);
leng=leng+strlen(d.meter_datatime)+strlen(d.status)+strlen(d.timestamps)+10;//(int)log10(d.total_m3);
leng=leng+385;//charactors in blank format;
if (strlen(m.date)!=10){
    char* message="wrong data length for date (yyyy-mm-dd,10 characters)";
    return message;
}

if(buff_length<leng){
    char * message="low buffer length";
    return message;
    
}

char *jaon =(char*)malloc(leng*sizeof(char));
snprintf(jaon,leng,"[\n\t{\n\t\t\"gatewayId\": \"%s\",\n\t\t\"date\": \"%s\",\n\t\t\"deviceType\": \"%s\",\n\t\t\"interval_minutes\": %d,\n\t\t\"total_readings\": %d,\n\t\t\"values\": {\n\t\t\t\"device_count\": %d,\n\t\t\t\"readings\": [\n\t\t\t{\"media\": \"%s\"\n\t\t\t\t, \"meter\": \"%s\",\n\t\t\t\t\"deviceId\": \"%s\",\n\t\t\t\t\"unit\": \"%s\",\n\t\t\t\t\"data\": [\n\t\t\t\t{\n\t\t\t\t\t\"timestamp\": \"%s\",\n\t\t\t\t\t\"meter_datetime\": \"%s\",\n\t\t\t\t\t\"total_m3\": %f,\n\t\t\t\t\t\"status\": \"%s\"\n\t\t\t\t\t\t}\n\t\t\t\t\t]\n\t\t\t\t}\n\t\t\t]\n\t\t}\n\t}\n]\n",m.gatewayId,m.date,m.deviceType,m.interval_minutes,m.total_readings,dc,r.media,r.meter,r.deviceId,r.unit,d.timestamps,d.meter_datatime,d.total_m3,d.status);
return jaon;
}
