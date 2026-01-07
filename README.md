# -Embedded-Firmware-Developer-JSON-Serialization-for-w-M-Bus-related-Firmware
designing an embedded-friendly software library that serializes structured meter data into a predefined JSON format.
The choosen platform is stm32 because  first of all it is familiar to me and its controllers(stm series controllers are cheap and fast) also c language is used as it is fast and consumes less memory 
# build and run instructions
all file at one place then
 gcc Main.c json.c -o Main 
 ./Main

Example are in the example folder
the big desigion in designing the API is that no loops are used and the whole format is made and directly wrote in the memory so that fastest computation can be possible
