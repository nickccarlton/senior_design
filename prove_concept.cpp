// This is a proof-of-concept for the low-cost modular guitar pedal
// for ASU EE Senior Design, Spring 2025.

// This code implements a simple single pole LPF where
//      the LPF's cutoff frequency is controlled by 
//      an encoder.

// Authors:
//      Team 5- Nick Carlton, 
//              Ju Lee, 
//              Bob Barnett, 
//              Silas Stevens, and
//              Joe Liptock

// With support from:
//      Mentor- Professor Michael Goryll, and
//      TA    - Brookelyn Barnes

// Useful sources:
//  Daisy examples
//      @ https://daisy.audio/tutorials/cpp-dev-env/
//  Daisy Discord
//      @ https://discord.gg/5EvkCrnd
//  Keyth72's GuitarML Seed implementation (last accessed 24 April 2025)
//      @ https://github.com/GuitarML/Seed/blob/main/src/seed.cpp


#include <string.h>
#include "libDaisy/src/daisy_seed.h"
#include "DaisySP/Source/Filters/onepole.h"


using namespace daisy;
using namespace daisysp;


DaisySeed           hw;                 // DaisySeed object (whole chip)
Encoder             knob;               // encoder to control filter
AnalogControl       knob_fake_analog;   // fake analog implementation to trick the Parameter
OnePole             filter;             // filter object
Parameter           cutoff_frequency;   // parameter object for reading knob for filter
uint16_t            *knob_val;          // stored value from encoder
//Switch              bypass_footswitch;  // [left in place for later]
bool                bypass;             // bypass value 


static void Callback(AudioHandle::InputBuffer  in,
                     AudioHandle::OutputBuffer out,
                     size_t                    size)
{
    filter.SetFrequency(cutoff_frequency.Process()); // Assign current value of knob to cutoff

    for (size_t i=0; i<size; i++){
        if (bypass){
            // do nothing
        } else {
            out[0][i] = filter.Process(in[0][i]); // Process inbuffer and assign to outbuffer.
        }
    }
}


int main(void)
{
    // (GLOBAL)
    hw.Init();      // Initialize Daisy Seed
    
    // (CONTROLS)
    knob.Init(daisy::seed::D0,  // One pin of encoder (dunno A/B)
              daisy::seed::D2,  // One pin of encoder (dunno A/B)
              daisy::seed::D4,  // Switch of encoder
              0.0f);            // Update rate (to be deprecated)
    *knob_val = 0xFFFF / 2;     // initialize knob_val at halfway point
    knob_fake_analog.Init(knob_val, // pointer to value above
                          10,       // sample knob_val @ 10 Hz
                          false,    // don't invert
                          false,    // don't invert
                          0.002f);  // default slew rate

    // (FILTER)
    filter.Init();                                          // Initialize filter
    filter.SetFilterMode(OnePole::FILTER_MODE_LOW_PASS);    // Sets filter to LPF
    cutoff_frequency.Init(knob_fake_analog,     // uses knob to control
                          0.0f, 0.497f,         // between these max/min values
                          Parameter::LINEAR);   // with linear adjustment between them
                                                // -- if LPF struggles at high freq.,
                                                // change this to EXPONENTIAL or 
                                                // LOGARITHMIC
    // (PROCESSING)
    hw.SetAudioBlockSize(1024); // Set number of samples processed per block per channel

    // (STARTUP)
    hw.StartAudio(Callback);    // Start processing audio
    
    // Loop permanently
    for(;;){

        knob_val += knob.Increment();     // adjust knob_val based on encoder movement
    
    }
}
