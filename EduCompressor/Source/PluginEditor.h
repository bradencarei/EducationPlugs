/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Knob.h"



//==============================================================================
/**
*/
class EduCompressorAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Timer, public juce::Slider::Listener, public juce::Button::Listener
{
public:
    EduCompressorAudioProcessorEditor (EduCompressorAudioProcessor&);
    ~EduCompressorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override ;
    
    void sliderValueChanged(juce::Slider* slider) override;
    void buttonClicked(juce::Button * button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    EduCompressorAudioProcessor& audioProcessor;
    
    juce::Image mic = juce::ImageCache::getFromMemory(BinaryData::micGraphic_png, BinaryData::micGraphic_pngSize);
    
    juce::Image mb = juce::ImageCache::getFromMemory(BinaryData::meter_back_png, BinaryData::meter_back_pngSize);
    
    juce::Image pb = juce::ImageCache::getFromMemory(BinaryData::plugBack_jpeg, BinaryData::plugBack_jpegSize);
    
    juce::Image tb = juce::ImageCache::getFromMemory(BinaryData::thotBubble_png, BinaryData::thotBubble_pngSize);
    
    juce::Image aFact = juce::ImageCache::getFromMemory(BinaryData::attckFact_png, BinaryData::attckFact_pngSize);
    
    juce::ImageComponent microphone;
    juce::ImageComponent bubble;
    juce::ImageComponent attackFact;
    
    float micSize = 100.f;
    
    Knob Knob;
    
    juce::Slider attack;
    juce::Slider release;
    juce::Slider input;
    juce::Slider thresh;
    juce::Slider makeup;
    juce::Slider mix;
    juce::Slider ratio;
    juce::Slider knee;
    
    juce::TextButton attackButton;
    juce::TextButton releaseButton;
    juce::TextButton inputButton;
    juce::TextButton threshButton;
    juce::TextButton makeupButton;
    juce::TextButton mixButton;
    juce::TextButton ratioButton;
    juce::TextButton kneeButton;
    
    bool buttonBool = false;

    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EduCompressorAudioProcessorEditor)
};
