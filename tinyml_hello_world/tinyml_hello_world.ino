#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>

// sine_model.h contains the array you exported from Python with xxd or tinymlgen
#include "sineNN.h"

#define N_INPUTS 1
#define N_OUTPUTS 1

// in future projects you may need to tweak this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 2*1024

constexpr int led_pin = 12;
constexpr float pi = 3.14159265;                  // Some pi
constexpr float freq = 0.5;                       // Frequency (Hz) of sinewave
constexpr float period = (1 / freq) * (1000000);  // Period (microseconds)

Eloquent::TinyML::TensorFlow::TensorFlow<N_INPUTS, N_OUTPUTS, TENSOR_ARENA_SIZE> tf;


void setup() {

    Serial.begin(115200);
    delay(4000);
    tf.begin(sineNN);
    
    // check if model loaded fine
    if (!tf.isOk()) {
        Serial.print("ERROR: ");
        Serial.println(tf.getErrorMessage());
        
        while (true) delay(1000);
    }
}

void loop() {

    unsigned long timestamp = micros();
    timestamp = timestamp % (unsigned long)period;

    // Calculate x value to feed to the model
    float x_val = ((float)timestamp * 2 * pi) / period;

    // Read predicted y value from output buffer (tensor)
    float input[1] = { x_val };
    float y_val = tf.predict(input);
    float y_actual = sin(x_val);

    // Translate to a PWM LED brightness
    int brightness = (int)(255 * y_val);
    analogWrite(led_pin, brightness);

    // Print value
    Serial.print("Variable_1:");
    Serial.print(y_actual);
    Serial.print(",");
    Serial.print("Variable_2:");
    Serial.println(y_val);

    // for (float i = 0; i < 10; i++) {
    //     // pick x from 0 to PI
    //     float x = 3.14 * i / 10;
    //     float y = sin(x);
    //     float input[1] = { x };
    //     float predicted = tf.predict(input);
        
    //     // Serial.print("sin(");
    //     // Serial.print(x);
    //     // Serial.print(") = ");
    //     // Serial.print(y);
    //     // Serial.print("\t predicted: ");
    //     // Serial.println(predicted);

    //   Serial.print("Variable_1:");
    //   Serial.print(x);
    //   Serial.print(",");
    //   Serial.print("Variable_2:");
    //   Serial.println(y);
    // }

    delay(125);
}




// #include "EloquentTinyML.h"
// // sine_model.h contains the array you exported from the previous step
// // with either xxd or tinymlgen
// #include "sineNN.h"

// #define NUMBER_OF_INPUTS 1
// #define NUMBER_OF_OUTPUTS 1
// // in future projects you may need to tweak this value.
// // it's a trial and error process
// #define TENSOR_ARENA_SIZE 2*1024

// Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml(sineNN);

// void setup() {
//     Serial.begin(115200);
// }

// void loop() {
//     // pick up a random x and predict its sine
//     float x = 3.14 * random(100) / 100;
//     float y = sin(x);
//     float input[1] = { x };
//     float predicted = ml.predict(input);

//     Serial.print("sin(");
//     Serial.print(x);
//     Serial.print(") = ");
//     Serial.print(y);
//     Serial.print("\t predicted: ");
//     Serial.println(predicted);
//     delay(1000);
// }
