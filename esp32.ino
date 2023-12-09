#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"


const tflite::Model* model;
tflite::MicroErrorReporter micro_error_reporter;
tflite::MicroInterpreter interpreter(model, micro_error_reporter);
tflite::Tensor* input_tensor = interpreter.input(0);
tflite::Tensor* output_tensor = interpreter.output(0);

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);

  // Initialize TensorFlow Lite
  tflite::InitializeInterpreter(model, &interpreter);

  // Allocate memory for input and output tensors
  interpreter.AllocateTensors();
}


void loop() {
  int adc_MQ = analogRead(15); // Read sensor data
  float voltage = adc_MQ * (3.3 / 1023.0); // Convert to voltage

  // Prepare input tensor with sensor data
  input_tensor->data.f[0] = voltage;
}

if (prediction > 0.5) {
  digitalWrite(2, HIGH);
} else {
  digitalWrite(2, LOW);
}

// Process prediction further...

Serial.print("Prediction:");
Serial.println(prediction);
delay(100);

  



