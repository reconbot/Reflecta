/*
  ReflectaFunctions.h - Library for binding functions to a virtual function table
*/

#include <Arduino.h>

#ifndef REFLECTA_FUNCTIONS_H
#define REFLECTA_FUNCTIONS_H

// Types of errors detected by Reflecta Functions
#define FUNCTIONS_ERROR_FRAME_TOO_SMALL     0x05
#define FUNCTIONS_ERROR_FUNCTION_CONFLICT   0x06
#define FUNCTIONS_ERROR_FUNCTION_NOT_FOUND  0x07
#define FUNCTIONS_ERROR_PARAMETER_MISMATCH  0x08
#define FUNCTIONS_ERROR_STACK_OVERFLOW      0x09
#define FUNCTIONS_ERROR_STACK_UNDERFLOW     0x0A

// Frame Ids used by Reflecta Functions.  These are reserved values for the first byte of the frame data.
#define FUNCTIONS_PUSHARRAY                 0x00
#define FUNCTIONS_QUERYINTERFACE            0x01
#define FUNCTIONS_RESPONSE                  0x7D

namespace reflectaFunctions
{
  // Bind a function to an interfaceId so it can be called by Reflecta Functions.  The assigned frame id is returned.
  byte bind(String interfaceId, void (*function)(byte sequence));
  
  void push(byte b);
  
  byte pop();
  
  // Send a response to a function call
  //   callerSequence == the sequence number of the frame used to call the function
  //     used to correlate request/response on the caller side
  //   parameterLength & parameter byte* of the response data
  void sendResponse(byte sequence, byte parameterLength, byte* parameters);
  
  // reflectaFunctions setup() to be called in the Arduino setup() method
  void setup();
  
  void setExtendedParser(reflectaFrames::frameReceivedFunction extendedParser);
};

#endif
