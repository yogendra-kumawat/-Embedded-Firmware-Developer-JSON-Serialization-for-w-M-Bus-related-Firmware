#ifndef JSON_H
#define JSON_H

typedef struct {
     char* gatewayId;
     char* date;
     char* deviceType;
    int interval_minutes;
    int total_readings;
} meta;
typedef struct {
 char* media;
 char* meter;
 char* deviceId;
char* unit;
} readings;
typedef struct{
 char*timestamps;
 char*meter_datatime;
float total_m3;
 char* status;
 }data;
 typedef struct {
meta m;
readings r;
data d;
int device_count;
 }input;
char* searlizer(input input_data ,int buff_length);

#endif
