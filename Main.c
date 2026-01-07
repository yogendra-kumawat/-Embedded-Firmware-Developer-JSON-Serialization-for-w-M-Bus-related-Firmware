#include <stdio.h>
#include "json.h"

int main() {
meta m;//data type for meta data
data d;
readings r;
input inp;//data type that contains other data types
m.date="1423-34-23";
m.deviceType="xyz";
m.gatewayId="it may be";
m.interval_minutes=23;
m.total_readings=34;
r.deviceId="meri";
r.media="dielec";
r.meter="omel";
r.unit="m3";
d.meter_datatime="12-34-34";
d.status="ok";
d.timestamps="45-123-456-345";
d.total_m3=123;
inp.d=d;
inp.m=m;
inp.r=r;
inp.device_count=1;
const char* output_buffer=searlizer(inp,500);//output_buffer=searlizer(input data,size of buffer)
    printf("%s",output_buffer);
}
